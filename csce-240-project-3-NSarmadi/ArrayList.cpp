#include "./ArrayList.h"

template <class U>
ostream& operator<<(ostream & os, ArrayList<U> a) {
    os << "[";
    for (int i = 0; i < a.getSize(); i++) {
        os << a.getData(i) << " ";
    }
    os << "]";
    return os;
}

template <class T>
ArrayList<T>::ArrayList() {
    size = 0;
    data = new T[size];
}

template <class T>
ArrayList<T>::ArrayList(int size, T val) {
    this->size = size;
    data = new T[size];
    for (int i = 0; i <size; i++) {
        data[i] = val;
    }
}

template <class T>
ArrayList<T>::ArrayList(const ArrayList<T> & copy) {
    setSize(copy.getSize());
    data = new T[size];
    for (int i = 0; i < size; i++) {
        data[i] = copy[i];
    }
}

template <class T>
ArrayList<T>::~ArrayList() {
    delete [] data;
}

template <class T>
void ArrayList<T>::setSize(int size) {
    if (size >= 0) {
        this->size = size;
    } else {
        std::cout << "Incorrect size\n";
        exit(1);
    }
}

template <class T>
int ArrayList<T>::getSize() const {
    return size;
}

template <class T>
T ArrayList<T>::getData(int index) const {
    if (index >= 0 && index < size) {
        return data[index];
    } else {
        std::cout << "Invalid Index\n";
        exit(0);
    }
}

template <class T>
T ArrayList<T>::operator[](int index) const {
    if (index >= 0 && index < size) {
        return data[index];
    } else {
        std::cout << "Invalid Index\n";
        exit(0);
    }
}

template <class T>
T& ArrayList<T>::operator[](int index) {
    return data[index];
}

template <class T>
const ArrayList<T> & ArrayList<T>::operator=(const ArrayList<T> rhs) {
    size = rhs.getSize();
    delete [] data;
    data = new T[size];
    for (int i = 0; i < size; i++) {
        data[i] = rhs[i];
    }
    return *this;
}

template <class T>
void ArrayList<T>::print() const {
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}

// Start of new functions

template <class T>
bool ArrayList<T>::operator!=(const ArrayList<T> & rhs) const {
    if (this->size != rhs.size){
        return true;
    }
    for (int i = 0; i < size; i++){
        if (data[i] != rhs[i]){
            return true;
        }
    }
    return false;
}

template <class T>
ArrayList<T> ArrayList<T>::operator+(T val) const {
    ArrayList<T> temp(*this);
    for (int i = 0; i < size; i++){
      temp[i] = temp[i] + val;
    }
    return temp;
    
}

template <class T>
ArrayList<T> ArrayList<T>::operator+(const ArrayList<T> & rhs) const {
    if (size != rhs.size){
        return ArrayList();
    }
    ArrayList<T> temp(*this);
    for (int i = 0; i < size; i++){
        temp[i] = rhs[i] + temp[i];
    }
    return temp;
}

template <class T>
ArrayList<T> & ArrayList<T>::operator--() {
    if (this->size == 0){
        return *this;
    }
    int *temp = new T[size-1];
    for (int i = 0; i < size-1; i++){
        temp[i] = data[i];
    }
    delete [] data;
    data = temp;
    size = size - 1;
    return *this;
}

template <class T>
ArrayList<T> ArrayList<T>::operator--(int) {
    if (this->size == 0){
        return *this;
    }
   ArrayList<T> ret(*this);
   int *temp = new T[size - 1];
   for (int i = 0; i < size - 1; i++){
       temp[i] = data[i];
   }
   delete [] data;
   data = temp;
   size = size - 1;
   return ret; 
}

template <class T>
void ArrayList<T>::operator+=(T val) {
    int *temp = new T[size+1];
    for (int i = 0; i < size; i++){
        temp[i] = data[i];
    }
    temp[size] = val;
    delete [] data;
    data = temp;
    size = size+1;
    return;
}

template <class T>
void ArrayList<T>::operator+=(const ArrayList<T> & rhs) {
    int *temp = new T[size + rhs.size];
    for (int i = 0; i < size; i++){
        temp[i] = data[i];
    }
    for (int i = 0; i < rhs.size; i++){
        temp[i+size] = rhs[i];
    }
    delete [] data;
    data = temp;
    size = size + rhs.size;
}

template <class T>
ArrayList<T> ArrayList<T>::operator*(int val) const {
    int newsize = size*val;
    ArrayList<T> temp(newsize);
    int count = 0;
    for (int i = 0; i < val; i++){
        for (int j = 0; j < size; j++){
            temp[count++] = data[j];
        }
    }
    return temp;

}

template <class T>
ArrayList<T> ArrayList<T>::operator/(int val) const {
    int num = size/val;
    ArrayList<T> temp(num);
    for (int i = 0; i < num; i++){
        temp[i] = data[i];
    }
    return temp;
}
