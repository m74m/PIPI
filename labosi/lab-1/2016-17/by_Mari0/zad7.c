//ovo se mo�da moglo rije�it na neki jednostavniji na�in, ali i ovo �ljaka //

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	int broj, uvjet1, uvjet2;
	printf("Unesite cijeli broj: \n");
	scanf("%d", &broj);
	uvjet1=broj%2;
	uvjet2=broj%3;
	if(!uvjet1){
		if(!uvjet2)
			printf("Broj %d je djeljiv sa 6. \n", broj);
		else 
			printf("Broj %d nije djeljiv sa 6 jer nije djeljiv sa 3. \n", broj);
	}
	else{
		if(!uvjet2)
			printf("Broj nije djeljiv sa 6 jer nije djeljiv sa 2. \n", broj);
		else 
			printf("Broj nije djeljiv sa 6 jer nije djeljiv ni sa 2 ni sa 3. \n", broj);
	}
	return 0;
	
}
