/* 
   vlastita funkcija za kopiranje 
   niza znakova "iz" u niz znakova "u",
   ne kontrolira se je li niz znakov "u" 
   dovoljno velik i funkcija vraca broj
   kopiranih znakova
*/

int strcpyMoja(char * u, char * iz){
    int i;
    i = 0;
    while ((u[i] = iz[i]) != '\0')
        ++i;
    return i;
}
