#include <stdio.h>
#include <time.h>

void main() {
  int codeSecret = randomCodeSecret(); 
  int codeUtilisateur = 0;
  while(codeSecret != codeUtilisateur) {
    printf("Veuillez rentrer un code a 4 chiffres : ");
    scanf("%d", &codeUtilisateur);
    printf("Debug: %d %d \n", codeSecret, codeUtilisateur);
    printf("Il y a %d chiffres communs, et %d chiffres identiques. \n", chiffresCommuns(codeSecret, codeUtilisateur), chiffresIdentiques(codeSecret, codeUtilisateur)); 
  }
  printf("Bravo vous avez gagné.\n");

}

int chiffresCommuns(int codeSecret, int codeUtilisateur) {
  char secretCode[4];
  char userCode[4];
 
  sprintf(secretCode, "%ld", codeSecret);
  sprintf(userCode, "%ld", codeUtilisateur);
  
  int sommeChiffresCommuns = 0;

  int i; int j;
  for(i = 0; i < 4; i++) {
    for(j = 0; j < 4; j++) {
      if(secretCode[j]==userCode[i]){
        sommeChiffresCommuns+=1;
        break;
      }
    }
  }

  return sommeChiffresCommuns;
}

int chiffresIdentiques(int codeSecret, int codeUtilisateur) {
  char secretCode[4];
  char userCode[4];

  sprintf(secretCode, "%ld", codeSecret);
  sprintf(userCode, "%ld", codeUtilisateur);
  
  int sommeChiffresIdentiques = 0;

  int i;
  for (i = 0; i<4; i++) {
    if(secretCode[i]==userCode[i]){
      sommeChiffresIdentiques += 1;
    }
  }
  return sommeChiffresIdentiques;
}

int randomCodeSecret() {
  srand(time(NULL)); //init rand 
  return (rand()%(9999-1000)+1000);
}
