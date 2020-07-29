/*
  Okretatanje matrice do n puta u smjeru kazaljke na satu
  Rjesenje koristi funkcije i za test uzima inicijalizirane vrijednosti
  Da bi rjesenje bilo jednostavnije dvije su matrice koristene
  tako da je svako naredno rotiranje u odnosu na prethodni rezultat
  i naizmjenicnim koristenjem pocetne matrice.  
*/

#include <stdio.h>

#define MAX 10

void unos2D(int *mat, int maxdim, int dim, int nacin);
void ispis2D(int *mat, int maxdim, int dim);
void rot2D(int *mp, int *mr, int maxdim, int dim);

int main(void) {
  	int i, j, k, n, rot, kako;
  	int r[MAX][MAX], m[MAX][MAX];
  	
	do { 
		printf("\nUnesi velicinu kvadratne matrice: ");	   	
		scanf("%d", &n);
	} while (n<0 || n>10);
    
	printf("Odredi nacin unosa vrijednosti u matricu, 0 za auto: ");	   	
	scanf("%d", &kako);
    
    unos2D(m, MAX, n, kako);
    
	do { 
        printf("\nUnesi broj okretanja: \n");	   	
        scanf("%d", &rot);
	} while (rot<0);
	
	// ispis ucitane matrice:
	printf("\nUcitana je matrica %dx%d (ukupno %d elemenata): \n", n,n,n*n);
	ispis2D(m, MAX, n);
	
	// rotiranje i ispis matrice potreban broj puta
    for (i=1; i<=rot; i++){
        if (i%2)
            rot2D(m, r, MAX, n);
        else
            rot2D(r, m, MAX, n);
    }

    return 0;
}

void rot2D(int *mp, int *mr, int maxdim, int dim){
    int i, j;
	for (i=0; i<dim; i++) {
		for (j=0; j<dim; j++) {
			*(mr+j*maxdim+dim-i-1) = *(mp+i*maxdim+j);
		}
	}    
    printf("\nRotirana x%d matrica: \n", 1);
    ispis2D(mr, maxdim, dim);    
}    

void unos2D(int *mat, int maxdim, int dim, int nacin){
    int i, j;
    if (nacin){
	  // Ovdje se unose vrijednosti u matricu preko tastature
	  printf("Unesi vrijednosti za matricu %dx%d", dim,dim);	   	
	  printf(" (ukupno %d cijelih brojeva): \n", dim*dim);
        for (i=0; i<dim; i++) {
		  for (j=0; j<dim; j++) {
              scanf("%d", (mat+i*maxdim + j));
          }
      }
    }
    else {
      // Unos vrijednosti u matricu automatski determinirano */
	  for (i=0; i<dim; i++) {
		  for (j=0; j<dim; j++) {
              *(mat+i*maxdim + j) = i*dim + j;
          }
	  }
    }    
}    

void ispis2D(int *mat, int maxdim, int dim){
    int i, j;
	for (i=0; i<dim; i++) {
		for (j=0; j<dim; j++) {
            printf("%5d ", *(mat+i*maxdim + j));
        }
		printf("\n");
	}
}    