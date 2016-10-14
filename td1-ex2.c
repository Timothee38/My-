#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
  int pid;
  int code = 0;

  int status; 

  pid = fork();

  if(pid == 0) {
    
    do { 
      printf("Enter un code [0,255] : ");
      scanf("%d", &code);
    } while((code < 0) && (code > 256));
    exit(code);
  }
  else if(pid == -1) {
    printf("Erreur dans la creation du fils.\n");
  }
  else {
    wait(&status);
    if(WIFEXITED(status)) {
      printf("Code reçu : %d\n", WEXITSTATUS(status));
    }
  }
  return 0;
 }

