/*
   Od unesenih brojeva s tastature program odredjuje 
   najveci i najmanji koristenjem funkcijskih poziva
*/

#include <stdio.h>

#define MAX_BR 4

float velikibr(float, float);
float malibr(float, float);

int main() {
	float brojevi[MAX_BR]= {0};
	float najveci=0, najmanji=1;
	int i;
	
	printf("Unesi %d broja:\n", MAX_BR);
	for (i=0; i<MAX_BR; i++)
		scanf("%f", &brojevi[i]);
	
	for (i = 0; i < MAX_BR; i++) {
	   najveci  = velikibr(brojevi[i], najveci);
	   najmanji = malibr(brojevi[i], najmanji);
	   }
	printf("\nNajveci broje je: %f\n",  najveci);
	printf("\nNajmanji broj je: %f\n", najmanji);
	return 0;
}
	
float velikibr( float num1, float num2){
	if ( num1 > num2)
	   return num1;
	else
	   return num2;
}
	
float malibr( float num1, float num2){
	if ( num1 < num2)
	   return num1;
	else
	   return num2;
}
