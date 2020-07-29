/**************************************************************
 Program za evidenciju osoba, telefona i jednog broja
**************************************************************/

#include <stdio.h>
#include <conio.h>
#include <string.h>

struct osoba{
	 char ime[20];
	 char telbr[13];
	 int nekibr;
};

void dodajOsobu(){
	  FILE *uidat;
	  struct osoba os1;
	  uidat=fopen("adresar.txt","a");
	  printf("\n\nDodaj osobu i telefon:\n");
	  printf("Unesi ime: ");	  	scanf("%19s", os1.ime);
	  printf("Unesi tel. broj: ");  scanf("%12s", os1.telbr);
	  printf("Unesi neki broj: ");  scanf("%d", &os1.nekibr);
	  fprintf(uidat,"%20s %13s %7d", os1.ime, os1.telbr, os1.nekibr);
	  fclose(uidat);
}

void prikaziSve(){
	  FILE *uidat;
	  struct osoba os1;
	  uidat=fopen("adresar.txt","r");
	  printf("\n\nPrikaz svih osoba u datoteci:\n");
	  printf("\n\n\t\tIme\tTelefon\t\tNeki broj");
	  printf("\n\t\t=====\t==============\t=========\n\n");
	  while(!feof(uidat)){
		  fscanf(uidat,"%20s %13s %7d", os1.ime, os1.telbr, &os1.nekibr);
		  printf("%20s %13s \t%7d\n", os1.ime, os1.telbr, os1.nekibr);
	  }
	  fclose(uidat);
}

void nadjiOsobu(){
	  FILE *uidat;
	  struct osoba os1;
	  char ime[20];
	  int ukupno=0;
	  uidat=fopen("adresar.txt","r");
	  printf("\n\nPrikaz odabranog podatka:\n");
	  printf("\nUnesi ime: ");
	  scanf("%s",&ime);
	  while(!feof(uidat)){
	  	fscanf(uidat,"%20s %13s %7d", os1.ime, os1.telbr, &os1.nekibr);
	    if(strcmp(os1.ime,ime)==0){
		//if(strcmpi(os1.ime,ime)==0){
			printf("\n\nIme   :  %s", os1.ime);
			printf("\nTelefon : %s", os1.telbr);
			printf("\nNeki br.: %d", os1.nekibr);
			ukupno++;
	    }
	  }
	  if(ukupno==0)
	     printf("\n\n\nNema podataka u adresaru!");
	  else
	     printf("\n\n#Pretrazeno ukupno %d osoba.",ukupno);
	  fclose(uidat);
}

int main(){
	char izbor;
	while(1){
		printf("\n\nMALI ADRESAR\n\n");
		printf("1) Dodaj osobu\n");
		printf("2) Nadji osobu\n");
		printf("3) Izlistaj sve osobe\n");
		printf("4) Kraj\n");
		printf("Unesi odabir: ");
		fflush(stdin);
		izbor = getche();
		switch(izbor){
			 case '1' : 
				dodajOsobu();
				break;
			 case '2' : 
				 nadjiOsobu();
				break;
			 case '3' : 
				prikaziSve();
				break;
			 case '4' : return 0;
		}
	}
}
