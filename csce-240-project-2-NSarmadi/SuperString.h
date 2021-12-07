#ifndef SUPERSTRING_H_
#define SUPERSTRING_H_
// Author: Neekon Sarmadi
// Email: nsarmadi@email.sc.edu
// Section #: 003
// Copyright 2021 Neekon Sarmadi
// Modified from template code @coleca24 GitHub
#include <iostream>
#include <string>

class SuperString {
 public:
    // Constructors
    SuperString();
    explicit SuperString(std::string);
    SuperString(int, char);
    SuperString(const SuperString&);

    // Destructor
    ~SuperString();

    // Member Functions
    void print();
    char get(int);
    int length();
    int find(char, int start = 0);
    int find(std::string, int start = 0);
   
    SuperString substr(int, int);

    SuperString reverse();
    SuperString replace(int, int, std::string);
    void push_back(char);
    void append(std::string);
    void append(const SuperString&);
    void replace(char, char);

   // Extra Credit
    void removeAll(char);
    void replace(std::string, std::string);
    bool isUpper();
    bool isLower();
    bool isTitleCase();

 private:
    // Member Variables
    char *data;
    int size;
};



#endif  // SUPERSTRING_H_
