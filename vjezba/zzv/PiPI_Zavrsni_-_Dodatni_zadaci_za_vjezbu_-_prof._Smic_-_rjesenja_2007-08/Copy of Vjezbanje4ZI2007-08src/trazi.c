/********************************************************
  Trazi broj u znakovnoj datoteci brojevi.txt s brojevima 
  u nizu diskontinuirano uzlazno
  Maksimalni broj je postavljen na MAX_N
 ********************************************************/
#include <stdio.h>
#define MAX_N 1000	

int main(){
    FILE *in_file;
    int brojevi[MAX_N], max_n=0;	
    int	sredina, pocetak, kraj, trazen;
	char DAT_FILE[] = "brojevi.txt", red[80];
	
    in_file = fopen(DAT_FILE, "r");
    if (in_file == NULL) {
		fprintf(stderr,"Error: Prolem otvaranja %s\n", DAT_FILE);
		exit (8);
    }
    while (1) {
		if (fscanf(in_file, "%d",  &brojevi[max_n]) != 1)
	    	break;
		++max_n;
    }
    
    while (1) {
		printf("Unesi trazeni broj ili -1 za kraj:" );
		scanf("%d", &trazen);
		if (trazen == -1) break;
		pocetak = 0;
		kraj = max_n;
		while (1) {
		    if (pocetak >= kraj) {
				printf("Broj %d nije nadjen!\n", trazen);
				break;
		    }
		    sredina = (pocetak + kraj) / 2;
		    if (brojevi[sredina] == trazen) {
				printf("Broj %d je na %d. mjestu!\n", trazen, sredina+1);
				break;
		    }
		    if (brojevi[sredina] < trazen)
				pocetak = sredina + 1;
		    else
				kraj = sredina;
		}
   }
   return (0);
}