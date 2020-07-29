// Program testira rand funkciju za simuliranje 
// postenog bacanja novcica
// Komentirane linije sluze za interakciju programa s korisnikom

#include <stdio.h>
#include <time.h>

int main(){ 
	int i=1000, x, y=1, d=0, n=0;
	double uspjeh;
	
	srand(time(NULL));
	
	while (--i){				// Ovo je za automatski rad
	//while (y==1||y==2){
		
		x = 1 + (rand()%2);
		
		//printf("\nPismo (1) ili glava (2)? ");
		//scanf("%d", &y);
		y = 1 + (rand()%2);		// Ovo je za automatski rad
		
		printf("\n\t%s! ", x==1 ? "Pismo": "Glava");
		printf("%s!", x==y ? "Bravo": "Neeee");
		x==y ? d++: n++;
	}
	
	printf("\nUkupno %d pogodaka i %d promasaja!", d, n);
	printf("\nUspjesnost iznosi: %4.1f%%", 100.*d/(d+n));
	return 0;
}
