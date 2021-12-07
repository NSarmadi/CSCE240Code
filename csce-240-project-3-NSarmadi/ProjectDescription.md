# Project 3 CSCE 240 Fall 2021 (50 points)
Due 10/28/21 at Midnight

In this assignment, you will be extending the ArrayList object that we have been creating in class with some more operators overloads. You will start from the templated ArrayList that we created together in class. Remember that the T is the data type. 
  
## ArrayList member variables
- `T *data`: a dynamic pointer array that holds each element of type T in the ArrayList
- `int size`: the size of the `data` array (how many elements it holds)

## ArrayList Methods
Notice that you will not need to implement the constructors or some of the other functions (they are already implemented).

The following are the methods that you will need to implement: 
- `bool operator!=(const ArrayList<T> &) const`
  - Checks to see if the calling object and the passed object are different
  - Returns true if they are different (either different sizes or if content differs
  - Returns false if sizes are the same and all content are the same. 
  - **Should not modify the calling object**
- `ArrayList<T> operator+(T) const`                     
  - Creates and returns an object that has a `data` array that is the calling object's data + the value of the passed arugement.
  - **Should not modify the calling object**
  - For example: 
```
ArrayList<int> a(2,1); // [1, 1] 
ArrayList<int> c; 
c = a + 1; // c == [2, 2] 
```
- `ArrayList<T> operator+(const ArrayList<T> &) const`
  - Pairwise addition (should only work if the sizes are the same)
  - Creates and returns an object that has a `data` array that is the calling object's data + the value of the passed arugement's data array.
  - **Should not modify the calling object**
  - For example: 
```
ArrayList<int> a(2,1); // [1, 1] 
ArrayList<int> b(2,2); // [2, 2]
ArrayList<int> c; 
c = a + b; // c == [3, 3] 
```
- `ArrayList<T> & operator--()`                      
  - Pre 
  - We are going to be inventive here! The `operator--` in this case will mean removal of the last element of the `data` array. 
  - If the `data` array is empty then it should just return an empty object and make no changes to itself
  - **Should modify the calling object**
  - For example: 
```
ArrayList<int> a(2,1), b;  // a == [1,1]
a[1] = 2;             // a == [1,2]
b = --a;        
b.print();            // b == [1]
a.print();            // a == [1]
```
- `ArrayList<T> operator--(int)`                        
  - Post
  - Same as the `operator--` description as above, this time just as the post instead of the pre. 
  - If the `data` array is empty then it should just return an empty object and make no changes to itself
  - **Should modify the calling object**
  - For example: 
```
ArrayList<int> a(2,1), b;  // a == [1,1]
a[1] = 2;             // a == [1,2]
b = a--;        
b.print();            // b == [1,2]
a.print();            // a == [1]
```
- `void operator+=(T)`                                  
  - Appends an element on to the end of the `data` array. 
  - **Should modify the calling object**
  - For example: 
```
ArrayList<int> a(2,1);  // a == [1,1]
a += 2;                 // a == [1,1,2]
```
- `void operator+=(const ArrayList<T> &)`                     
  - Appends the values of the ArrayList passed to the end of the calling object object's data. 
  - **Should modify the calling object**
  - For example: 
```
ArrayList<int> a(2,1), b(2,2);  // a == [1,1] b == [2,2]
a += b;                         // a == [1,1,2,2]
```
- `ArrayList<T> operator*(int) const`                     
  - We are going to get inventive here too! The `*` operator should take in an `int` and return an object that has the calling object's `data` array duplicated that many times
  - **Should not modify the calling object**
  - For example: 
```
ArrayList<int> a(2,1), c;     // a == [1,1]
c = a*2;                      // c == [1,1,1,1]
```
- `ArrayList<T> operator/(int) const`                
  - This one will be a little different as well. It will also take in an `int` and return an object that has the corresponding fraction (dictated by the `int` passed in) of the calling object's `data` array. 
  - If the size is not divisible by the `int` passed in, then you should truncate the new size (5/2 == 2). 
  - **Should not modify the calling object**
  - For example: 
```
ArrayList<int> a(5,1), c;     // a == [1,1,1,1,1]
c = a/2;                      // c == [1,1] (the first 2 elements of a)
```

## Compiling and Running your Code
With Google Test
```
Windows WSL and Linux: 
g++ main-gtest.cpp ArrayList.cpp -lgtest -lpthread -o proj3
./proj3

Mac: 
g++ -std=c++2a main-gtest.cpp ArrayList.cpp -lgtest -lpthread -o proj3
./proj3
```

Without Google Test
```
Windows WSL and Linux: 
g++ main.cpp ArrayList.cpp -o proj3
./proj3

Mac: 
g++ -std=c++2a main.cpp ArrayList.cpp -o proj3 
./proj3
```

## Submitting your Code to GitHub
Feel free to modify the `main.cpp`, `ArrayList.h`, `ArrayList.cpp`. Any changes that you make to these, you should push up to GitHub: 
```
git pull 
git add <files> // For example, git add ArrayList.h ArrayList.cpp
git commit -m "Changes..."
git push 
```

## Grading Rubric

- `bool operator!=(const ArrayList<T> &) const`         - 5 points
- `ArrayList<T> operator+(T) const`                     - 5 points
- `ArrayList<T> operator+(const ArrayList<T> &) const`  - 5 points
- `ArrayList<T> & operator--()`                         - 5 points
- `ArrayList<T> operator--(int)`                        - 5 points
- `void operator+=(T)`                                  - 5 points
- `void operator+=(ArrayList<T> &)`                     - 5 points
- `ArrayList<T> operator*(T) const`                     - 5 points
- `ArrayList<T> operator/(T) const`                     - 5 points

5 points for no memory leaks and proper style (passes cpplint)
