// Copyright 2021 <Enter Name Here>
#include "./SuperString.h"

// DO NOT MODIFY START
void SuperString::print() {
    if (size != 0) {
        for (int i = 0; i < size; i++) {
            std::cout << data[i];
        }
        std::cout << "\n";
    } else {
        std::cout << "<EMPTY>\n";
    }
}

char SuperString::get(int index) {
    if (index >= 0 && index < size) {
        return data[index];
    }
    return '\0';
}

int SuperString::length() {
    return size;
}
// DO NOT MODIFY END

// PUT YOUR CODE BELOW!

SuperString::SuperString() {
    size = 0;
    data = new char[size];
}

SuperString::SuperString(std::string str) {
    size = str.length();
    data = new char[size];
    for(int i=0; i<size; i++){
        data[i] = str[i];
    }
}

SuperString::SuperString(int size, char val) {
    this -> size = size;
    data = new char[size];
    for(int i=0; i<size; i++){
        data[i] = val;
    }
}

SuperString::SuperString(const SuperString& copy) {
    size = copy.size;
    data = new char[size];
    for (int i=0; i<size; i++){
        data[i] = copy.data[i];
    }
}

int SuperString::find(char c, int start) {
    for (int i=start; i<size; i++){
        if(data[i]==c){
            return i;
        }
    }
    return -1;
}

int SuperString::find(std::string str, int start) {
    int L = str.length();
    int END = size - L + 1;
    for (int i=start; i<END; i++){
        for(int j=0; j<L; j++){
            if (data[i+j]!=str[j]){
                break;
            }
            if (j==L-1)
            {
                return i;
            }
        }
    }
    return -1;
}

SuperString SuperString::substr(int start, int numChar) {
    std::string allah = "";
    if(start>size){
       return SuperString(allah);
    }
    if(start+numChar>size){
        return SuperString(allah);
    }
    int end = start+numChar;
    for (int i=start; i<end; i++){
        allah+=data[i];
    }
    return SuperString(allah);
}

SuperString SuperString::reverse() {
    std::string s = "";
    for (int i=size; i>0 ; i--){
        s+=data[i-1];
    }
    return SuperString(s);
}

SuperString SuperString::replace(int start, int numChar, std::string sub) {
   if (start + numChar > size){
       return SuperString();
   }
   std::string s = "";
   for (int i = 0; i<start; i++){
       s+=data[i];
   }
   s+=sub;
   int sum = start+numChar;
   for (int i = sum; i<size; i++){
       s+=data[i];
   }
   return SuperString(s);
}

void SuperString::push_back(char c) {
    char*temp = new char[size+1];
    for (int i = 0; i<size; i++){
        temp[i] = data[i];
    }
    temp[size] = c;
    delete [] data;
    data = temp;
    size = size+1;
}

void SuperString::append(std::string str) {
    int l = str.length();
    int newSize = size+l;
    char*temp = new char[newSize];
    for (int i=0; i<size; i++){
        temp[i] = data[i];
    }
    for (int i=0; i<l; i++){
        temp[size+i] = str[i];
    }
    delete [] data;
    data = temp;
    size = newSize;
}

void SuperString::append(const SuperString& obj) {
    int l = obj.size;
    int newSize = size+l;
    char*temp = new char[newSize];
    for (int i = 0; i<size; i++){
        temp[i] = data[i];
    }
    for (int i = size; i<newSize; i++){
        temp[i] = obj.data[i-size];
    }
    delete [] data;
    data = temp;
    size = newSize;
}

void SuperString::replace(char find, char rep) {
   int temp = this -> find(find,0);
    while (temp != -1){
        data[temp] = rep;
        temp = this -> find(find,temp + 1);
    }
}

void SuperString::removeAll(char c) {
    return; 
}

// Bonus Methods
void SuperString::replace(std::string find, std::string rep) {
    return;
}

bool SuperString::isUpper() {
    return true;
}

bool SuperString::isLower() {
    return true;
}

bool SuperString::isTitleCase() {
    return true;
}

SuperString::~SuperString() {
    delete [] data;
}
