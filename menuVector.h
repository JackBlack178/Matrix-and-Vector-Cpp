

#ifndef LAB2_MENUVECTOR_H
#define LAB2_MENUVECTOR_H
#include "iostream"
#include "myVector.h"
#include "menuVector.h"

using std::cout;
using std::cin;
using std::endl;


int getVectorType();

template<class T>
void getVectorSpecificType(myArraySequence<myVector<T>*> *a);

void getVector(myArraySequence<myVector<int>*> *intVectors, myArraySequence<myVector<float>*> *floatVectors);

template<class T>
void getRandomVector(myArraySequence<myVector<T>*> *a, T (*func)());

void printVectors(myArraySequence<myVector<int>*>* intVectors,
                  myArraySequence<myVector<float>*> *floatVectors);

template<class T>
void printTypeVector(myArraySequence<myVector<T>*> *vectors);

int randomInt();

float randomFloat();



template<class T>
void printVector(myVector<T>vector);

template<class T>
void printVector(myVector<T>*vector);

template<class T>
void deleteVectorSpecificType(myArraySequence<myVector<T>*> *vectors);

void deleteVectors(myArraySequence<myVector<int>*>* intVectors,
                      myArraySequence<myVector<float>*> *floatVectors);

template<class T>
void vectorOperation(myArraySequence<myVector<T>*> *vectors);

template<class T>
void vectorsOperation(myArraySequence<myVector<T>*> *vectors);

template<class T>
void vectorOperations(myArraySequence<myVector<T>*> *vectors);

void vectorOperationMain(myArraySequence<myVector<int>*>* intVectors,
                         myArraySequence<myVector<float>*> *floatVectors);


#endif //LAB2_MENUVECTOR_H
