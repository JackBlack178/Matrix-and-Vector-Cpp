//
// Created by Pascal on 09.05.2021.
//

#include "menuMatrix.h"



int getMatrixType(){
    int number;
    cout << "Create int matrix - 1\n"
            "Create float matrix - 2\n";

    number = getNumberInRange(1,2);
    return number;
}


void getMatrix(myArraySequence<myMatrix<int>*> *intMatrices, myArraySequence<myMatrix<float>*> *floatMatrices){
    int number;

    cout << "Make a matrix automatically or manually?:\n"
            "0: exit\n"
            "1: manually\n"
            "2: automatically (dimension less 10)\n:"
            "Enter number" << endl;
    cin >> number;
    if (number == 0)
        return;

    if (number == 1) {
        number = getMatrixType();
        switch (number) {
            case 1:
                getMatrixSpecificType<int>(intMatrices);
                break;
            case 2:
                getMatrixSpecificType<float>(floatMatrices);
                break;

            default:
                break;
        }
    }

    if (number == 2) {
        number = getMatrixType();
        switch (number) {
            case 1:
                getRandomMatrix<int>(intMatrices, randomInt);
                break;
            case 2:
                getRandomMatrix<float>(floatMatrices, randomFloat);
                break;

            default:
                break;
        }

    }
}

template<class T>
void getMatrixSpecificType(myArraySequence<myMatrix<T>*> *a){
    int size;
    T value;
    int number;
    cout << "Enter matrix getElementSize:" << endl;
    cin >> size;
    cout << "Adding values" << endl;
    myArraySequence<T> values;
    for (int i = 0; i < size*size; i++){
        cout << "Enter the " << i+1 << " value of matrix" << endl;
        cin >> value;
        values.append(value);
    }
    cout << "Entered matrix has getElementSize" << size << " X " << size << endl;
    cout << "Its values:\n";
    for (int i = 0; i < size*size ; i++) {
        if (i % size == 0){
            cout <<"\n";
        }
        cout << values.get(i) << "\t";
    }
    cout <<"\n";
    cout << "Would you like to save this matrix?:\n"
    "Yes - 1\n"
    "No - 2\n";
    number = getNumberInRange(1,2);
    if (number == 1){
        auto *newMatrix = new myMatrix<T>;
        *newMatrix = myMatrix<T>(values, size);
        a->append(newMatrix);
        return;
    }
    else if (number == 2)
        return;

}


template<class T>
void getRandomMatrix(myArraySequence<myMatrix<T>*> *a, T (*func)()){
    int number;
    int size = randomInt() % 10;
    myArraySequence<T> values;

    for (int i = 0; i < size * size; i++){
        values.append(func());
    }

    cout << "Recieved matrix has getElementSize " << size << "X" << size << endl;
    cout << "Its coordinates:\n";
    for (int i = 0; i < size*size ; i++) {
        if (i % size == 0){
            cout <<"\n";
        }
        cout << values.get(i) << "\t";
    }
    cout <<"\n";
    cout << "Would you like to save this matrix?:\n"
            "Yes - 1\n"
            "No - 2\n";

    cin >> number;
    if (number == 1){
        auto *newMatrix = new myMatrix<T>;
        *newMatrix = myMatrix<T>(values, size);
        a->append(newMatrix);
        return;
    }
    else if (number == 2)
        return;
}

void printMatrices(myArraySequence<myMatrix<int>*>* intMatrices,
                  myArraySequence<myMatrix<float>*> *floatMatrices) {
    int type = getMatrixType();
    switch (type) {
        default: break;
        case 1:
            printTypeMatrix<int>(intMatrices);
            break;
        case 2:
            printTypeMatrix<float>(floatMatrices);
            break;

    }
}

template<class T>
void printTypeMatrix(myArraySequence<myMatrix<T>*> *matrices) {
    int number;
    if (!matrices->getLength()) {
        cout << "There is no Matrixs with this type\n";
        return;
    }
    cout << "Enter -1 to see all Matrixs with this type or enter number index" << endl;
    cin >> number;
    while (true) {
        if (number == -1)
            break;

        if (number < matrices->getLength())
            break;
        cout << "Bad number. Try again\n" << endl;
        cin >> number;
    }

    if (number > -1 && number < matrices->getLength()){
        cout << "Matrix with " << number << " index :" << endl;
        myMatrix<T>*matrix = matrices->get(number);
        printMatrix(*matrix);
        return;
    }
    if (number == -1){
        for (int i = 0; i < matrices->getLength(); i ++){
            cout << i+1 << " matrix" <<endl;
            printMatrix(*matrices->get(i));
            cout << endl;
        }
    }
}

template<class T>
void printMatrix(myMatrix<T>m1){
    cout << "Matrix getElementSize " << m1.getMatrixSize() << " X " << m1.getMatrixSize() << endl;
    cout <<"Element getElementSize :" << m1.getElementSize() << endl;
    for (int i = 0; i < m1.getMatrixSize()*m1.getMatrixSize() ; i++) {
        if (i % m1.getMatrixSize() == 0){
            cout <<"\n";
        }
        cout << m1[i] << "\t";
    }
    cout <<"\n";
}


template<class T>
void deleteMatrixSpecificType(myArraySequence<myMatrix<T>*> *matrices) {

    if (matrices->getLength() == 0) {
        cout << "There is no matrices of this type for deleting" << endl;
        return;
    }

    int indexOfNumber;
    cout << matrices->getLength() << " Matrices available for deleting\n" << "To remove all - enter -1\n" << "To remove by index - enter an index\n"
         << "To cancel - enter -2\n";
    cin >> indexOfNumber;

    if (indexOfNumber == -2){
        return;
    }

    if (indexOfNumber == -1){
        for (int i = matrices->getLength() - 1 ; i >= 0; i--){
            matrices->pop(i);

        }

        cout << "Success" << endl;
    }

    if ( 0 <= indexOfNumber && indexOfNumber < matrices->getLength()){
        matrices->pop(indexOfNumber);
        cout << "Success" << endl;
    }
}




void deleteMatrices(myArraySequence<myMatrix<int>*>* intMatices,
                   myArraySequence<myMatrix<float>*> *floatMatrices) {

    auto manageNumber = getMatrixType();

    switch (manageNumber) {
        case 1: deleteMatrixSpecificType(intMatices); break;
        case 2: deleteMatrixSpecificType(floatMatrices); break;
        default: break;
    }
}


void matrixOperationMain(myArraySequence<myMatrix<int>*>* intMatrices,
                         myArraySequence<myMatrix<float>*> *floatMatrices){

    auto manageNumber = getMatrixType();

    switch (manageNumber) {
        case 1: matrixOperation(intMatrices); break;
        case 2: matrixOperation(floatMatrices); break;
        default: break;
    }
}

template<class T>
void matrixOperation(myArraySequence<myMatrix<T>*> *matrices){
    int index;
    int number;
    T value;
    int lineOrColumn1;
    int lineOrColumn2;
    for (int i = 0; i < matrices->getLength(); i ++){
        cout << "myMatrix[" << i << "] :" <<endl;
        printMatrix(*matrices->get(i));

    }
    cout << "Choose a myMatrix by index" << endl;
    index = getNumberInRange(0, matrices->getLength() - 1);
    myMatrix<T> *matrix = matrices->get(index);
    cout << "Enter 1 - To get determinant" << endl;
    cout << "Enter 2 - To mult line or column" << endl;
    cout << "Enter 3 - To sum or sub lines or columns" << endl;
    cout << "Enter 4 - To exit" << endl;

    number = getNumberInRange(1,3);

    if (number == 1){
        cout << "Determinant is " << matrix->getNorm() << endl;
    }

    if (number == 2){
        cout << "Enter 1 - To use line\n"
        << "Enter 2 - To use column\n";
        number = getNumberInRange(1,2);

        cout << "Matrix getElementSize " << matrix->getMatrixSize() << " X " << matrix->getMatrixSize() << endl;

        if (number == 1) {
            cout << "Select line\n";
            number = getNumberInRange(1, sqrt(matrix->getMatrixSize()));
            cout << "Enter value for multiplying\n";
            cin >> value;
            matrix->multLine(number, value);
        }
        else {
                cout << "Select column\n";
                cin >> number;
                cout << "Enter value for multiplying\n";
                cin  >> value;
                matrix->multColumn(number,value);
        }
        return;
    }

    if (number == 3){
        cout << "Enter 1 - To use line\n"
             << "Enter 2 - To use column\n";
        number = getNumberInRange(1,2);

        cout << "Matrix getElementSize " << matrix->getMatrixSize() << " X " << matrix->getMatrixSize() << endl;

        if (number == 1) {
            cout << "Select line 1\n";
            lineOrColumn1 = getNumberInRange(1, matrix->getMatrixSize());

            cout << "Select line 2\n";
            lineOrColumn2 = getNumberInRange(1, matrix->getMatrixSize());

           matrix->sumLine(lineOrColumn1 - 1, lineOrColumn2 - 1);

        }
        else {
            cout << "Select column 1\n";
            lineOrColumn1 = getNumberInRange(1, matrix->getMatrixSize() );
            cout << "Select column 2\n";
            lineOrColumn2 = getNumberInRange(1, matrix->getMatrixSize());

            matrix->sumColumn(lineOrColumn1 - 1, lineOrColumn2 - 1);
        }
        return;
    }

    if (number == 4)
        return;
}


