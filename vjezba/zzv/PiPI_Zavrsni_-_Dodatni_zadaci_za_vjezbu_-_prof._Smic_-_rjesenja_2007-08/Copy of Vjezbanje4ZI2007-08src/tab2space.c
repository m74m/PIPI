/*************************************************************
 Izmjena tab znaka za prazninu uz koristenje pomocne datoteke 
**************************************************************/
#include <stdio.h>

int main(){
   FILE *ul_dat, *tmpul_dat; 
   int c; 
   char ime_dat[30+1];

   printf("Program mijenja tabove u praznine.\n"
      	  "Unesi ime datoteke za procesiranje (maks. 30 znakova): ");
   scanf("%30s", ime_dat);

   if ((ul_dat = fopen(ime_dat, "r+")) != NULL) {
      if ((tmpul_dat = fopen("privremena", "w+b")) != NULL) {
	  /* ili if ((tmpul_dat = tmpfile()) != NULL) {*/
	  
         printf("\nDatoteka prije modificiranja:\n");
         while ((c = getc(ul_dat)) != EOF) {
            putchar(c);
            putc(c == '\t' ? ' ': c, tmpul_dat);
         }
         fseek(tmpul_dat, 0L, SEEK_SET);	/* ili rewind(tmpul_dat);*/
         fseek(ul_dat, 0L, SEEK_SET);  		/* ili rewind(ul_dat);*/
         
         printf("\n\nDatoteka poslije modificiranja:\n");
         while ((c = getc(tmpul_dat)) != EOF) {
            putchar(c);
            putc(c, ul_dat);
         }
      } 
      else 
         printf("Problem kod otvaranja privremene datoteke!\n");
   } 
   else  
      printf("Problem kod otvaranja datoteke %s\n", ime_dat);
   return 0; 
} 
