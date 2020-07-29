/* 
  strlenNoja: 
  funkcija vrati broj znakova
  u s
*/

int strlenMoja(char *s) {
    char *p = s;
    while (*p != '\0')
        p++;
    return p - s;
}