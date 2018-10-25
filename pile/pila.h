#ifndef PILA_H
#define PILA_H

template <class T>
class pila{
public:
    typedef T value_type;
    virtual ~pila() = 0 ;
    virtual void creapila() = 0;
    virtual bool pilavuota() = 0;
    virtual value_type leggipila() = 0;
    virtual void fuoripila() = 0;
    virtual void inpila(value_type t) = 0;
};

#endif //PILA_H