#include <iostream>

using namespace std;

template<class T>
class List {
private:
    T *list;
    int size;
    int currentsize;
public:

//    constructor with default size of 10
    List(int size = 0) {
//        defensive programming
        if(size < 1){
            this->size = 10;
        }
        else
        {
            this->size = size;
        }




        currentsize = 0;
        list = new T[size];
    }

    ~List() {
        delete[] list;
    }

//    insert an item at the end of the list
    void insert(T item) {

//    check if the list is full
        if (currentsize < size) {
            list[currentsize] = item;
            currentsize++;
        }
        else{
            cout<< "List is full" << endl;
        }
    }

//    insert an item at a specific index
    void insertAt(T item, int index) {
//    check if the list is full
        if (currentsize < size) {
//      shift all the items to the right of the index to the right


            for (int i = currentsize; i > index; i--) {
//          move the item at index i to index i + 1
                list[i] = list[i - 1];
            }

            list[index] = item;
            currentsize++;
        }
        else{
            cout<< "List is full" << endl;
        }
    }

//    retrieve an item at a specific index
    T retrieveAt(int index) {
        return list[index];
    }


    void removeAt(int index) {
//    check if the list is empty
        if (currentsize > 0) {

//      shift all the items to the right of the index to the left
            for (int i = index; i < currentsize - 1; i++) {
                list[i] = list[i + 1];
            }
            currentsize--;
        }
        else{
            cout<< "List is empty" << endl;
        }
    }

    void replaceAt(T item, int index) {
        list[index] = item;
    }

    bool isItemAtEqual(T item, int index) {
        return list[index] == item;
    }

    bool isEmpty() {
        return currentsize == 0;
    }

    bool isFull() {
        return currentsize == size;
    }

    void clear() {
        delete[] list;
        currentsize = 0;
        list = new T[size];
    }

    void print() {
        for (int i = 0; i < currentsize; i++) {
            cout << list[i] << " ";
        }
        cout << endl;
    }

    int listSize() {
        return currentsize;
    }

    int maxListSize() {
        return size;
    }

};

