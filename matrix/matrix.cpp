//
// Created by arcangelo on 10/11/18.
//

#include <iostream>

#include "matrix.h"




Matrix::Matrix(int c,int r){
    rows = r;
    columns = c;
    int i,j;
    element = new tipoelem* [rows];
    for (i=0; i < rows; i++)
        element[i] = new tipoelem[columns];
    for (i=0; i < rows; i++)
        for (j=0; j < columns; j++)
            element[i][j] = 0;
}

// costruttore di copia
Matrix::Matrix(const Matrix &m){
    rows = m.rows;
    columns = m.columns;
    int i,j;
    element = new tipoelem* [rows];
    for (i=0; i < rows; i++)
        element[i] = new tipoelem[columns];
    for (i=0;i<rows;i++)
        for (j=0;j<columns;j++)
            element[i][j]=m.element[i][j];

}

Matrix::~Matrix(){
    for (int j=0; j<columns; j++)
        delete[] element[j];
    delete [] element;
}

Matrix &Matrix::operator=(const Matrix &m){
    // evita gli auto assegnamenti
    if (this == &m) return *this;
    else {
        int i,j;
        if (columns != m.columns || rows != m.rows){
            this->~Matrix();
            columns = m.columns;
            rows = m.rows;
            element = new tipoelem* [rows];
            for (i=0; i < rows; i++)
                element[i] = new tipoelem[columns];
        }
        for (i=0;i<rows;i++)
            for (j=0;j<columns;j++)
                element[i][j] = m.element[i][j];
    }
    return *this;
}

void Matrix::setElemento(int c ,int r ,tipoelem val){
    element[r][c] = val;
}

tipoelem Matrix::printElemento(int c,int r){
    return element[r][c];
}

void Matrix::scalarProd(int val){
    int i,j;
    for (i=0; i < rows; i++)
        for (j=0; j < columns; j++)
            element[i][j] *= val;
}

Matrix Matrix::trasposta(){
    Matrix trasp(columns,rows);
    int i,j;
    for (i=0; i < rows; i++)
        for (j=0; j < columns; j++)
            trasp.setElemento(i,j,element[j][i]);
    return trasp;
}

