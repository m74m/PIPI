/* 
   vlastito  rješenje funkcije atoi: 
   pretvorba niza znakova u cijeli broj, uz 
   ignoriranje bijelih praznina, postivanje 
   preznaka i ignoriranje drugih znakova koji 
   nisu znamenka
*/

#include <ctype.h>

int atoiMoja2(char * s) {
    int i, n, predznak;
    
    for (i = 0; isspace(s[i]); i++); 
        
    predznak = (s[i] == '-') ? -1 : 1;
    
    if (s[i] == '+' || s[i] == '-') 
        i++;
    
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    
    return predznak * n;
}