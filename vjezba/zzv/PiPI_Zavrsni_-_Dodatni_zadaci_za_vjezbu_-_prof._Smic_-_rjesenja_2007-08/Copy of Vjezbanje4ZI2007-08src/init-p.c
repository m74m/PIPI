/********************************************************
  Inicijaliziranje polja
 ********************************************************/

#define MAX 10
	
void init_polja_a();
void init_polja_b();
    
int main(){
    int  polje[MAX];
    
    init_polja_a(polje, MAX, 0);		/* jedan nacin poziva*/

    init_polja_a(&polje[0], MAX, 1);	/* drugi nacin poziva*/

    init_polja_a(&polje, MAX, 0);		
    /* treci nacin radi, ali uz compiler warning */

    init_polja_b(polje, MAX, 1);		/* druga funkcija */

    return (0);
}

void init_polja_a(int data[], int n_max, int p){
    int  i;
    for (i = 0; i < n_max; ++i){
        data[i] = p;
        printf("%d", data[i]);
    }
}

void init_polja_b(int *i_ptr, int n_max, int p){
    int i;
    for (i = 0; i < n_max; ++i){
        *(i_ptr + i) = p;
        printf("%d", *(i_ptr + i));
    }
}
