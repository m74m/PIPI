/* 
   proberi: 
   funkcija koja iz niza znakova "s" 
   izbaci sve znakove == c
*/

int proberi(char s[], int c) {
    int i, j;
    
    for (i=j=0; s[i] != '\0'; i++) {
        if (s[i] != c) 
            s[j++] = s[i];
    }
    
    s[j] = '\0';
        
    return j-i-1;
}