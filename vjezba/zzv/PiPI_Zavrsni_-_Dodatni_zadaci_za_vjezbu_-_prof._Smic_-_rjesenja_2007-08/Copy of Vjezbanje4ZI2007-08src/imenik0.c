#include <stdio.h>
#define MAXL 100

void einfo(char * poruka, char * dat){
	printf("Problem kod %s datoteke - %s\n", poruka, dat);
	exit (1);
}

int main() {
  FILE  *u_dat, *i_dat;
  char  ime[MAXL], udat[]="imena.txt", idat[]="imenao.txt";
  int   ibr;
  float ocjena;

  u_dat = fopen(udat, "r");
  
  if (u_dat == NULL) einfo("ulazne", udat);
  
  i_dat = fopen(idat, "w");
  
  if (i_dat == NULL) einfo("izlazne", idat);
    
  ibr = 0;
  while ( fscanf(u_dat, "%s", ime ) == 1 ){
    ibr++;
    printf("Unesi ocjenu za %s: ", ime);
    scanf("%f", &ocjena);
    if ( fprintf(i_dat, "%s %.2f\n", ime, ocjena) <= 0 )
      einfo("izlazne", idat);
  }
  
  printf("\nBroj imena: %d\n", ibr);
  
  fclose(u_dat);
  fclose(i_dat);
  
  return 0;
}
