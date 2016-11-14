#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void main() {

  char note[3];

  int p = open("tube_notes", O_RDONLY);
  if(p == -1) { printf("Erreur ouverture du tube\n"); exit(1); }
  do{
    read(p, &note, 3);
    printf("%s\n", note);
  }while((atoi(note) > 0) && (atoi(note)<100));
}
