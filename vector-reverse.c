/* Inverte un vettore v dato in i n g r e s s o
* VALORE DI RITORNO : il vettore i n v e r t i t o
*/
void reverse ( int v [] , int First , int Last ) {
int tmp ;
    if ( First < Last )
    {
    /* Divide e Impera */
    reverse (v , First + 1 , Last - 1);
    /* Combina */
    tmp = v [ Last ];
    v [ Last ] = v [ First ];
    v [ First ] = tmp ;
    }
}