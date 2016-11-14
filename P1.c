#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

void main() {

  char note[3];
  int p = mknod("tube_notes", S_IFIFO|0666, 0);
  if (p == -1) {
    printf("Erreur lors de la création du tube. \n"); exit(1);
  }
  p = open("tube_notes", O_WRONLY);
  if (p == -1) {
    printf("Erreur lors de l'ouverture du tube. \n"); exit(1);
  }
  do {
    printf("Entrez une note: ");
    scanf("%s", &note);
    write(p, note, 3);
  }while((atoi(note) >= 0) && (atoi(note) < 100));
}
