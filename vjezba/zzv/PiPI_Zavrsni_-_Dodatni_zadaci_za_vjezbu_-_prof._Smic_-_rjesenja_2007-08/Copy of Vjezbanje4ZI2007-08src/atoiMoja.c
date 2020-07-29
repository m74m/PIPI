/* 
   vlastito pojednostavljeno rješenje funkcije atoi: 
   pretvorba niza znakova u cijeli broj, uz 
   pretpostavku da nema praznina, predznaka i 
   drugih znakova koji nisu znamenka
*/

int atoiMoja(char s[]) {
    int i = 0, n = 0;
    
    for (; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    
    return n;
}