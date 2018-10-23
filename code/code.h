//
// Created by arcangelo on 10/23/18.
//

#ifndef TEST_BUILD_CODE_H
#define TEST_BUILD_CODE_H
template <class T>
class code{
public:
    typedef T value_type;

    virtual void creacoda() = 0;
    virtual bool codavuota() = 0;
    virtual value_type leggicoda() = 0;
    virtual void fuoricoda() = 0;
    virtual void incoda(value_type v ) = 0;
};


#endif //TEST_BUILD_CODE_H
