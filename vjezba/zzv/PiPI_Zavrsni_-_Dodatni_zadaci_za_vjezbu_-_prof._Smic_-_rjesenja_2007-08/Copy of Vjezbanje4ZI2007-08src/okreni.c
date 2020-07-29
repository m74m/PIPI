/* 
  okreni: 
  funkcija koja okrene sadrzaj niza znakova
*/

#include <string.h>

void okreni(char s[]){
    int i, j;
    char c;
    
    j = strlen(s)-1;
    
    for (i = 0; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}