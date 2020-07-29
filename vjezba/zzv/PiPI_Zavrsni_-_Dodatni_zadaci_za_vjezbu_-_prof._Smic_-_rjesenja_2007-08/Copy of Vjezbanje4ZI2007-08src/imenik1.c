#include <stdio.h>
#define MAXL 100

int main(){
  FILE  *i_dat;
  char  ime[MAXL];
  float	ocjena;

  i_dat = fopen("imenao.txt", "r");

  if (i_dat == NULL) {
    printf("Problem kod otvaranja datoteke.\n");
    return 1;
  }

  while ( fscanf(i_dat, "%s %f", ime, &ocjena) == 2 ) {
    printf("%s\t %2.1f\n", ime, ocjena);
  }
  
  printf("\n");
  
  fclose(i_dat);
  
  return 0;
}
