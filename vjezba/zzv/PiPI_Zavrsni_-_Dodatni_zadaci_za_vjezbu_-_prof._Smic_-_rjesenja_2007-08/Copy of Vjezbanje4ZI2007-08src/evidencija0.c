/*************************************************
 Datoteka za direktni pristup korištenjem zapisa
 Kreiranje:
*************************************************/
#include <stdio.h>

int main(){ 
   struct osoba { 
      int broj;          
      char prezime[15];  
      char ime[10];
      int prisutnost;	/* od 0 do 6 	*/ 
      float prosjek;   /* od 0. do 100. */    
   }; 
   struct osoba st1 = { 0, "", "", 0, 0.0 }; 
   int i; 
   FILE *uidat; 
   
   if ((uidat = fopen("evidencija.dat", "wb")) == NULL) 
      printf("Datoteka se ne moze otvoriti.\n"); 
   else { 
      for (i = 1; i <= 100; i++) {
         	fwrite(&st1, sizeof(struct osoba), 1, uidat);
      }
   } 
   
   fclose(uidat); 
   return 0; 
}