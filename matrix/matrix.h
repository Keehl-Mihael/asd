//
// Created by arcangelo on 10/11/18.
//

#ifndef C_MATRIX_H
#define C_MATRIX_H

typedef double tipoelem;

class Matrix{
public:
    Matrix(int,int);
    void setElemento(int,int,tipoelem);
    tipoelem printElemento(int,int);
    void scalarProd(int);
    Matrix trasposta();
    ~Matrix();
    void prodotto(Matrix);
    Matrix(const Matrix &m);
    Matrix & operator=(const Matrix &m);
private:
    int rows;
    int columns;
    tipoelem  **element;

};

#endif //C_MATRIX_H
