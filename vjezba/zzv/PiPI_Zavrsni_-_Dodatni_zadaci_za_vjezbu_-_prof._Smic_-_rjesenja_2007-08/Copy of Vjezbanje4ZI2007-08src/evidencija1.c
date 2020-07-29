/*************************************************
 Datoteka za direktni pristup korištenjem zapisa
 Upis i pregled upisanoga:
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
   int i, is, iz=0; 
   FILE *uidat; 

   if ((uidat = fopen("evidencija.dat", "r+b")) == NULL) 
      printf("Datoteka se ne moze otvoriti.\n"); 
   else { 
      printf("Unesi broj: ");
      scanf("%d", &is);
      while (is!=0) { 
	     fseek(uidat, (is-1)*sizeof(struct osoba), SEEK_SET);
	     fread(&st1, sizeof(struct osoba), 1, uidat);
	     if (st1.broj==is){
		     printf("\nZa broj %d uneseni su podaci:\n", st1.broj);
		     printf("%s %s %d %4.1f", st1.prezime, st1.ime, st1.prisutnost, st1.prosjek);
	         printf("\nUpisi '1' za izmjenu podataka: ");
    	     scanf("%iz", &iz);
	     }
		 if (!(st1.broj==is) || iz==1) {
			 iz=0;
			 st1.broj = is;
	         printf("\nUpisi za promjenu/unos: prezime ime ");
			 printf("prisutnost (0-6) i prosjek (0.-100.)\n");        
	         fscanf(stdin, "%s %s %d %f", 
	         		st1.prezime, st1.ime, &st1.prisutnost, &st1.prosjek);
	         fseek(uidat, (st1.broj-1)*sizeof(struct osoba), SEEK_SET);
	         fwrite(&st1, sizeof(struct osoba), 1, uidat);
	         printf("\nBodovi za broj %d iznose %3.2f.\n", 
	         		st1.broj, (st1.prisutnost+1)*st1.prosjek*5/700);
         }
         printf("\nUnesi novi broj: ");
         scanf("%d", &is);
      } 
      fclose(uidat); 
   } 

   return 0; 
}