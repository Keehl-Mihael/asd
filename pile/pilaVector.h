#ifndef PILAVECTOR_H
#define PILAVECTOR_H

template <class t>
class pilavector;

template <class T>
class cella {
public:
    friend class pilavector<T>;
    cella<T> operator<(const cella<T>& c ) const { return this->value < c.value; };
    cella<T> operator<=(const cella<T>& c) const { return this->value <= c.value; };
    cella<T> operator>(const cella<T>& c) const { return this->value > c.value; };
private:
    T value;
    cella<T> * succ;
};

template <class T>
class pilavector : public pila <T>{
public:
    ~pila();
    void creapila();
    bool pilavuota();
    value_type leggipila();
    void fuoripila();
    void inpila();
private:
    int testa;
    value_type elements[10];

};

#endif //PILAVECTOR_H