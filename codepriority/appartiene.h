//
// Created by arcangelo on 06/01/19.
//

#ifndef TEST_BUILD_APPARTIENE_H
#define TEST_BUILD_APPARTIENE_H

#include <queue>

template <class T>
class appartiene{
    typedef typename CodaPriorita<T>::tipoElem tipoElem;
    bool appart(CodaPriorita<int> &c,int lookFor){
        std::queue<int> conserva;
        tipoElem start;
        start =  c.min();
        if(start < lookFor){
            return false;
        }else{
            if(start == lookFor){
                return true;
            }
            conserva.push(start);
            c.cancellaMin();
            while (start != NULL){
                start = c.min();
                if(start == lookFor){
                    return true;
                }
                conserva.push(start);
                c.cancellaMin();
            }
        }
        return false;
    }
};

#endif //TEST_BUILD_APPARTIENE_H
