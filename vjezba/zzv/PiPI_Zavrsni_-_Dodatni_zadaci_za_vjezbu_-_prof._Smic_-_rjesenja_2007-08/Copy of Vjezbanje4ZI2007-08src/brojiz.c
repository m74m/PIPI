/********************************************************
  Program broji znakove u formatiranoj datoteci brojiz.c
********************************************************/
 
#include <stdio.h>
#include <stdlib.h> 

int main(){
    int             count = 0;  
    FILE           *in_dat;    
	const char ime_dat[] = "brojiz.c";
	
    int             ch;

    in_dat = fopen(ime_dat, "r");
    if (in_dat == NULL) {
        printf("Problem kod otvaranja %s!\n", ime_dat);
        exit(8);
    }

    while (1) {
        ch = fgetc(in_dat);
        if (ch == EOF)
            break;
        ++count;
    }
    printf("Broj znakova u %s je %d\n", ime_dat, count);

    fclose(in_dat);
    return (0);
}
