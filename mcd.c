/*
Calcolo del MCD : calcola il MCD tra due numeri interi
VALORE DI RITORNO : il valore c a l c o l a t o
*/
int mcd ( int m , int n ) {
int r;
if (m < n)
    return mcd (n , m );
r = m % n;

    if ( r == 0)
        return ( n );
    else
    return ( mcd (n , r ));
}