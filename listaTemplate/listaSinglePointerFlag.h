#ifndef ASD_LISTASINGLEPOINTERFLAG_H
#define ASD_LISTASINGLEPOINTERFLAG_H
#inlcude "listaSinglePOinter.h"
class listasinglepointerflag : public listsinglepointer<T>{
  public :
    void insLista(const value_type a, postion  p){
      if(!finelista(p)){
          listsinglepointer::inslista(a,p);
      }else{
        position prev;
        position t = new cella<T>;
        t->value = a;
        t->succ = head; 
        prev = predLista(p)
        prev->succ = t;
        lenght ++;
      }
    }
    void canclista(potion p){
      if(!finelista(p)){
          listsinglepointer::canclista(p);
      }else{
            postion prev;
            if(!listaVuota())
                prev = predLista(p);
                prev->succ = head;
                delete[] p;
                lenght --;
      }
    }
  
};
#endif // ASD_LISTASINGLEPOINTERFLAG_H
