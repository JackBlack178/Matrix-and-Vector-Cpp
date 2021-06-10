//
// Created by Pascal on 09.05.2021.
//

#ifndef LAB2_MENUMATRIX_H
#define LAB2_MENUMATRIX_H
#include "myMatrix.h"
#include "menu.h"
#include "iostream"



void getMatrix(myArraySequence<myMatrix<int>*> *intMatrices, myArraySequence<myMatrix<float>*> *floatMatrices);


int getMatrixType();

template<class T>
void getMatrixSpecificType(myArraySequence<myMatrix<T>*> *a);

template<class T>
void getRandomMatrix(myArraySequence<myMatrix<T>*> *a, T (*func)());

void printMatrices(myArraySequence<myMatrix<int>*>* intMatrices,
                   myArraySequence<myMatrix<float>*> *floatMatrices);

template<class T>
void printTypeMatrix(myArraySequence<myMatrix<T>*> *matrices);

template<class T>
void printMatrix(myMatrix<T>m);

template<class T>
void deleteMatrixSpecificType(myArraySequence<myMatrix<T>*> *matrices);

void deleteMatrices(myArraySequence<myMatrix<int>*>* intMatices,
                    myArraySequence<myMatrix<float>*> *floatMatrices);

template<class T>
void matrixOperation(myArraySequence<myMatrix<T>*> *matrices);

void matrixOperationMain(myArraySequence<myMatrix<int>*>* intMatrices,
                         myArraySequence<myMatrix<float>*> *floatMatrices);


#endif //LAB2_MENUMATRIX_H
