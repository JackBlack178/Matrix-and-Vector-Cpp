//
// Created by Pascal on 02.05.2021.
//


#include "menu.h"


int randomInt() {
    return rand()%10000; // Не более 10000
}

float randomFloat() {
    return (float)randomInt() + (float)randomInt()/(float)randomInt();
}


int getNumberInRange(int down, int up){
    int number;
    while(true){
        cout << "Enter number" << endl;
        cin >> number;
        if (down <= number && number <= up)
            return number;
    }
}


void menu1() {
    myArraySequence<myVector<int> *> intVectors;
    myArraySequence<myVector<float> *> floatVectors;
    int number;

    while (true) {
        cout << "1: Make a vector\n"
             << "2: Print vectors\n"
             << "3: remove vectors\n"
             << "4: Execute an operation on the vector\n"
             << "5: To quit \n"
             << "Enter a number:" << endl;
        number = getNumberInRange(1,5);


        switch (number) {
            case 1:
                getVector(&intVectors, &floatVectors);
                break;
            case 2: printVectors(&intVectors, &floatVectors); break;
            case 3: deleteVectors(&intVectors, &floatVectors); break;
            case 4: vectorOperationMain(&intVectors, &floatVectors); break;
            case 5: cout << "Stopping program ..." << endl; return;
            default: break;
        }
    }
}

void menu2(){
    myArraySequence<myMatrix<int> *> intMatrices;
    myArraySequence<myMatrix<float> *> floatMatrices;
    int number;

    while (true) {
        cout << "1: Make a matrix\n"
             << "2: Print matrices\n"
             << "3: remove matrices\n"
             << "4: Execute an operation on the matrix\n"
             << "5: To quit - "
             << "Enter a number:" << endl;
        cin >> number;
        if (number == 5)
            break;
        if (number < 1 || number > 5) {
            cout << "Wrong number. Try again!\n";
            continue;
        }

        switch (number) {
            case 1:

                getMatrix(&intMatrices, &floatMatrices);
                break;
            case 2:
                printMatrices(&intMatrices, &floatMatrices);
                break;
            case 3:
                deleteMatrices(&intMatrices, &floatMatrices);
                break;
            case 4:
                matrixOperationMain(&intMatrices, &floatMatrices);
                break;
            case 5:
                cout << "Stopping program ..." << endl;
                return;
            default:
                break;
        }
    }
}


