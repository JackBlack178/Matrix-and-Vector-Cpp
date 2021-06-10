//
// Created by Pascal on 02.05.2021.
//

#include "menuVector.h"
#include "menu.h"


int getVectorType(){
    int number;
    cout << "Create int vector - 1\n"
            "Create float vector - 2" << endl;
    number = getNumberInRange(1,2);
    return number;
}

void getVector(myArraySequence<myVector<int>*> *intVectors, myArraySequence<myVector<float>*> *floatVectors) {
    int number;
    cout << "make a vector automatically or manually?:\n"
            "0: exit\n"
            "1: manually\n"
            "2: automatically (dimension less 10)\n:"
            "Enter number" << endl;
    cin >> number;
    if (number == 0)
        return;

    if (number == 1) {
        number = getVectorType();
        switch (number) {
            case 1:
                getVectorSpecificType<int>(intVectors);
                break;
            case 2:
                getVectorSpecificType<float>(floatVectors);
                break;
            default:
                break;
        }
        return;
    }

    if (number == 2) {
        number = getVectorType();
        switch (number) {
            case 1:
                getRandomVector<int>(intVectors, randomInt);
                break;
            case 2:
                getRandomVector<float>(floatVectors, randomFloat);
                break;
            default:
                break;
        }

    }
}

template<class T>
void getVectorSpecificType(myArraySequence<myVector<T>*> *a){
    int dimension;
    T coordinate;
    int number;
    cout << "Enter dimension:" << endl;
    cin >> dimension;
    cout << "Adding coordinates" << endl;
    myArraySequence<T> coordinates;
    for (int i = 0; i < dimension; i++){
        cout << "Enter the " << i+1 << " coordinate" << endl;
        cin >> coordinate;
        coordinates.append(coordinate);
    }
    cout << "Entered vector has " << dimension << " dimension\n";
    cout << "Its coordinates:\n";
    for (int i = 0; i < dimension; i++)
        cout << coordinates.get(i) << endl;

    cout << "Would you like to save this vector?:\n"
            "Yes - 1\n"
            "No - 2\n";
    number = getNumberInRange(1,2);
    if (number == 1){
        auto *newVec = new myVector<T>;
        *newVec = myVector<T>(coordinates, dimension);
        a->append(newVec);
        return;
    }
    else if (number == 2)
        return;

}

template<class T>
void getRandomVector(myArraySequence<myVector<T>*> *a, T (*func)()){
    int number;
    int dimension = randomInt() % 10;
    myArraySequence<T> coordinates;

    for (int i = 0; i < dimension; i++){
        coordinates.append(func());
    }

    cout << "Recieved vector has " << dimension << "dimension\n";
    cout << "Its coordinates:\n";
    for (int i = 0; i < dimension; i++)
        cout << coordinates.get(i) << endl;

    cout << "Would you like to save this vector?:\n"
            "Yes - 1\n"
            "No - 2\n";
    cin >> number;
    if (number == 1){
        auto *newVec = new myVector<T>;
        *newVec = myVector<T>(coordinates, dimension);
        a->append(newVec);
        return;
    }
    else if (number == 2)
        return;

}

void printVectors(myArraySequence<myVector<int>*>* intVectors,
myArraySequence<myVector<float>*> *floatVectors) {
    int type = getVectorType();
    switch (type) {
    default: break;
    case 1:
    printTypeVector<int>(intVectors);
    break;
    case 2:
    printTypeVector<float>(floatVectors);
    break;
    }
}

template<class T>
void printTypeVector(myArraySequence<myVector<T>*> *vectors) {
    int number;
    if (!vectors->getLength()) {
        cout << "There is no vectors with this type\n";
        return;
    }
    cout << "Enter -1 to see all vectors with this type or enter number index" << endl;
    cin >> number;
    while (true) {
        if (number == -1)
            break;

        if (number < vectors->getLength())
            break;
        cout << "Bad number. Try again\n" << endl;
        cin >> number;
    }

    if (number > -1 && number < vectors->getLength()){
        cout << "Vector with " << number << " index :" << endl;
        myVector<T>*vector = vectors->get(number);
        printVector(vector);
        return;
    }
    if (number == -1){
        for (int i = 0; i < vectors->getLength(); i ++){
            cout << i+1 << " vector" <<endl;
            printVector(vectors->get(i));
        }
    }

}

template<class T>
void printVector(myVector<T>vector){
    cout << "Dimension is :" << vector.getDimension() << endl ;
    cout << "Element getElementSize is :" << vector.getElementSize() << endl ;
    if (vector.getDimension() == 0){
        cout << "Coords is empty" << "\n\n" ;
        return;
    }

    for (int i = 0; i < vector.getDimension(); i++){
        cout << i+1 << " cord is " << vector[i] << endl;
    }
    cout << "\n";
}

template<class T>
void printVector(myVector<T>*vector) {
    cout << "Dimension is :" << vector->getDimension() << endl;
    cout << "Element getElementSize is :" << vector->getElementSize() << endl;
    if (vector->getDimension() == 0) {
        cout << "Coords is empty" << "\n\n";
        return;
    }

    for (int i = 0; i < vector->getDimension(); i++){
        cout << i << " cord is " << (*vector)[i] << endl;

    }
    cout << "\n";
}






template<class T>
void deleteVectorSpecificType(myArraySequence<myVector<T>*> *vectors) {

    if (vectors->getLength() == 0) {
        cout << "There is no vectors of this type for deleting" << endl;
        return;
    }

    int indexOfNumber;
    cout << vectors->getLength() << " vectors/vector available for deleting\n" << "To remove all - enter -1\n" << "To remove by index - enter an index\n"
    << "To cancel - enter -2\n";
    cin >> indexOfNumber;

    if (indexOfNumber == -2){
        return;
    }

    if (indexOfNumber == -1){
        for (int i = vectors->getLength() - 1 ; i >= 0; i--){
            vectors->pop(i);
        }

        cout << "Success" << endl;
    }

    if ( 0 <= indexOfNumber && indexOfNumber < vectors->getLength()){
        vectors->pop(indexOfNumber);
        cout << "Success" << endl;
    }
}




void deleteVectors(myArraySequence<myVector<int>*>* intVectors,
                      myArraySequence<myVector<float>*> *floatVectors) {

    auto manageNumber = getVectorType();

    switch (manageNumber) {
        case 1: deleteVectorSpecificType(intVectors); break;
        case 2: deleteVectorSpecificType(floatVectors); break;
        default: break;
    }
}

template<class T>
void vectorOperation(myArraySequence<myVector<T>*> *vectors){
    int index;
    int number;
    T value;
    for (int i = 0; i < vectors->getLength(); i ++){
        cout << "vector[" << i << "] :" <<endl;
        printVector(vectors->get(i));
    }
    cout << "Choose a vector by index" << endl;
    index = getNumberInRange(0, vectors->getLength() - 1);
    myVector<T> *vector = vectors->get(index);
    cout << "Enter 1 - To get vector getLength" << endl;
    cout << "Enter 2 - To increase on number" << endl;
    cout << "Enter 3 - To exit" << endl;

    number = getNumberInRange(1,3);

    if (number == 1){
        cout << "Vector getLength is " << vector->getNorm() << endl;
    }

    if (number == 2){
        cout << "Enter number for multiplying\n";
        cin >> value;
        if (sizeof(value) == vector->getElementSize()){
            (*vector) / value;
        }
    }

    if (number == 3)
        return;
}

template<class T>
void vectorsOperation(myArraySequence<myVector<T>*> *vectors){
    int index1;
    int index2;
    int number;
    T value;
    T result;
    for (int i = 0; i < vectors->getLength(); i ++){
        cout << "vector[" << i << "] :" <<endl;
        printVector(vectors->get(i));
    }
    cout << "Choose two vectors by index" << endl;
    index1 = getNumberInRange(0, vectors->getLength() - 1);
    index2 = getNumberInRange(0, vectors->getLength() - 1);

    myVector<T> *vector1 = vectors->get(index1);
    myVector<T> *vector2 = vectors->get(index2);

    if (vector1->getDimension() != vector2->getDimension()){
        cout << "Vector dimensions must be the same" << endl;
        return;
    }

    cout << "Enter 1 - To do scalar product" << endl;
    cout << "Enter 2 - To do vector product" << endl;
    cout << "Enter 3 - To sum  vectors" << endl;
    cout << "Enter 4 - To subtract vectors" << endl;
    cout << "Enter 5 - To exit" << endl;

    number = getNumberInRange(1,5);

    if (number == 1){
        cout << "Scalar product is " << *(*vector1 * *vector2) << endl;
        return;
    }

    if (number == 2){
        cout << "Vector product is" << endl;
        printVector( *vector1 & *vector2);
        cout << "Would you like to save this vector?" << endl;
        cout << "Enter 1 - To save" << endl;
        cout << "Enter 0 - To exit" << endl;
        number =  getNumberInRange(0,1);
        if (number == 1){
            auto *newVec = new myVector<T>;
            *newVec = myVector<T>(*vector1 & *vector2);
            vectors->append(&newVec);
        }
        return;

    }

    if (number == 3){
        printVector( *vector1 + *vector2);

        cout << "Would you like to save this vector?" << endl;
        cout << "Enter 1 - To save" << endl;
        cout << "Enter 0 - To exit" << endl;
        number =  getNumberInRange(0,1);
        if (number == 1){
            auto *newVec = new myVector<T>;
            *newVec = myVector<T>(*vector1 + *vector2);
            vectors->append(&newVec);
        }

        return;
    }

    if (number == 4){
        printVector(*vector1 - *vector2);

        cout << "Would you like to save this vector?" << endl;
        cout << "Enter 1 - To save" << endl;
        cout << "Enter 0 - To exit" << endl;
        number =  getNumberInRange(0,1);
        if (number == 1) {
            auto *newVec = new myVector<T>;
            *newVec = myVector<T>(*vector1 - *vector2);
            vectors->append(&newVec);
        }
        return;
    }

    if (number == 5){
        return;
    }



}

void vectorOperationMain(myArraySequence<myVector<int>*>* intVectors,
                         myArraySequence<myVector<float>*> *floatVectors){

    auto manageNumber = getVectorType();

    switch (manageNumber) {
        case 1: vectorOperations(intVectors); break;
        case 2: vectorOperations(floatVectors); break;

        default: break;
    }
}

template<class T>
void vectorOperations(myArraySequence<myVector<T>*> *vectors) {
    if (!vectors->getLength()) {
        cout << "There is no vectors with this type\n";
        return;
    }

    int number;

    cout << "You've made " << vectors->getLength() << "vectors of this type\n"
         << "You can do some operations with one vector or 2 vectors\n"
         << "Enter 1 - If you'd like to do scalar product/ vector product / sum or sub vectors\n"
         << "Enter 2 - If you'd like to get vector getLength / increase vector on number\n"
         << "Enter 3 - To exit" << endl;

    number = getNumberInRange(1, 3);

    if (number == 1) {
        vectorsOperation(vectors);
        return;
    }

    if (number == 2) {
        vectorOperation(vectors);
        return;
    }

    if (number == 3) {
        return;
    }
}

