/*
Napisati program koji ucitava 11 cijelih brojeva te nakon toga ispisuje 
10 unesenih brojeva pomaknutih za broj mjesta koji odreduje 11. broj.
Problem rijesen korištenjem polja i funkcije.
Test primjeri:
	Ulaz:	1 2 3 4 5 6 7 8 9 10 -2
	Izlaz:	3 4 5 6 7 8 9 10 1 2
	Ulaz:	1 2 3 4 5 6 7 8 9 10 2
	Izlaz:	9 10 1 2 3 4 5 6 7 8 
*/
#include <stdio.h> 
#define MAKS 10 

void pomicanje(int * niz, int vel, int pom);

int main() { 
    
    int i, pomak, polje[MAKS]; 
    
    printf("Unesi %d cijelih brojeva:\n", MAKS); 
    for (i = 0; i < MAKS; i++) {
        scanf("%d", &polje[i]); 
    }
    printf("Unesi broj za koliko treba pomaknuti elemente polja:\n");     
    scanf("%d", &pomak);     
    
    pomak = -pomak%MAKS;
    
    if (pomak<0) pomak+=MAKS;
        
    pomicanje (polje, MAKS, pomak);
    
    return 0; 
}

void pomicanje(int * niz, int vel, int pom){
    int i;
    printf("Pomaknuto uneseno polje:\n");     
    for (i=0 ; i < vel; i++, pom++) {
        if (pom == vel) pom = 0;
        printf("%d ", *(niz+pom)); 
        /* ili   printf("%d ", niz[pom]);  */
    }    
}
