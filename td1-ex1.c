#include <stdio.h>
#include <unistd.h>

int main() {

  int pidFils1;
  int pid1;
  pid1 = fork(); // On crée le fils 1
 

  switch(pid1) {

    case -1: 
      printf("Erreur lors de la création du fils 1.\n");
      break;
    case 0: // Fils 1
      
      pidFils1 = fork(); // On crée le fils 1.1


      switch (pidFils1) {

        case -1: printf("Erreur lors de la création de fils 1.1\n"); break; 
        case 0: 
          printf("Le pid du fils 1.1 est: %d\n", getpid());
          break;
        default: 
          printf("Le pid du fils 1 est: %d\n", getpid());
          int pidFils12 = fork(); // Création du fils 1.2
          switch (pidFils12) {
            case -1: printf("Erreur dans la cration du fils 1.2\n"); break;
            case 0: 
              printf("Le pid du fils 1.2 est: %d\n", getpid()); break; 
          }
      }


      break;
    default: // Père 
      printf("Le pid du père est: %d\n", getpid());  
      int pidFils2 = fork(); // On crée le fils 2
      switch(pidFils2) {
        case -1: printf("Erreur dans la création du fils 2\n"); break;
        case 0: // Fils 2
          printf("Le pid du fils 2 est: %d\n", getpid());
          break;
      } 
  }
}
