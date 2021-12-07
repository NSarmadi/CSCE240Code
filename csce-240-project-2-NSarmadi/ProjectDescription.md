# Project 2 CSCE 240 Fall 2021 (40 points)
In this project, you will be creating your own string class (called SuperString). At this point we have used the `std::string` object (https://www.cplusplus.com/reference/string/string/) in C++ quite a bit. You should now have an idea of how to use some of the functions it contains (like the find and replace). In this project, you will create an object that mimicks some of this functionality and also builds on it! 

Your SuperString object is already defined for you in the `SuperString.h` file in your GitHub repo. Below I will describe more details about all of the variables and functions. **Make sure that you read this all the way through before starting! There is important information at the end about how to run the code!** (https://github.com/coleca24/csce240_f21_p2/blob/main/ProjectDescription.md#compiling-and-running-your-code)

## SuperString member variables: 
- `char *data`: a dynamic pointer array that holds each character of the string within that SuperString object
- `int size`: the size of the `data` array (how many characters it holds)

## SuperString Constructors: 
- `SuperString()`: The default constructor. Should: 
  - set `size` to 0 
  - allocate the `data` array to a new char array of size `size`
- `explicit SuperString(std::string)`: Alt. Constructor #1. Should:
  - set `size` to the length of the string passed in
  - allocate the `data` array to a new char array of size `size`
  - fill the contents of the `data` array with the contents of the string passed in
- `SuperString(int, char)`: Alt. Constructor #2. Should:
  - set `size` to the value of the int passed in 
  - allocate the `data` array to a new char array of size `size`
  - fill all contents of the `data` array with the character passed in
- `SuperString(const SuperString&)`: Copy Constructor. Should: 
  - set `size` to the size of the object passed in 
  - allocate the `data` array to a new char array of size `size`
  - fill all contents of the `data` array with the same contents as the passed object's data

## SuperString Destructor: 
- `~SuperString()`: Should deallocate the data array

## SuperString Member Functions
- `void print()`: prints the contents of your array - Already implemented **DO NOT MODIFY**
- `char get(int)`: Extracts an element from your `data` array. - Already implemented **DO NOT MODIFY**
- `int length()`: returns the `size`. - Already implemented **DO NOT MODIFY**
- `int find(char, int start = 0)`
  - returns the index of the *first* instance of the character passed in the `data` array starting at index `start` 
  - returns -1 if the character does not exist. 
  - Ex. obj.data = "Hello" then obj.find('l', 0) == 2 
  - Ex. obj.data = "Hello" then obj.find('l', 3) == 3
- `int find(std::string, int start = 0)`
  - returns the index of the *first* instance of the string passed in the `data` array starting at index `start` 
  - returns -1 if the character does not exist. 
  - Ex. obj.data = "that cat is a cool cat" then obj.find("cat", 0) == 5
  - Ex. obj.data = "that cat is a cool cat" then obj.find("cat", 6) == 19
- `SuperString substr(int start, int numChar)`
  - returns a `SuperString` object that contains the substring of the calling object's data starting at index `start` and spanning the number of characters held in `numChar`
  - Contents of the returned object should be size 0 if no substring is able to be extracted. This would happen if a user gave an index that was out of bounds. 
  - Ex. obj.data = "Hello" then obj.substr(0,2) == ret.data =="He"
  - Ex. obj.data = "Hello" then obj.substr(4,2) == ret.data == empty // Note that this will attempt to get a substring that walks out of bounds (the last index would be 4 + 2 = 6 which is out of bounds)
- `SuperString reverse()`
  - Returns a `SuperString` object thats data array contains the calling calling object's data in reverse order.
  - Ex. obj.data = "Hello" then obj.reverse() == ret.data == "olleH"
- `SuperString replace(int index, int numChar, std::string sub)`
  - Returns a `SuperString` object thats data array has the contents of the data after the replacement is performed. 
  - Returns a `SuperString` object with size = 0 if invalid index is passed. 
  - How the replacement is performed: 
    - Starting at `index`, the elements of the `data` array are removed up until `index` + `numChar` and replaced with the contents of the passed string `sub`
  - Ex. obj.data = "Hello" then obj.replace(0, 2, "Jal") == ret.data == "Jalllo"
- `void push_back(char)`
  - Adds a new character (the one passed in) to the `data` array of the calling object.
  - Ex. obj.data = "hello" then obj.push_back('w') -> obj.data == "hellow"
- `void append(std::string)`
  - Appends the content of the passed string to the end of the `data` array of the calling object
  - Ex. obj.data = "hello" then obj.append(" world") -> obj.data == "hello world"
- `void append(const SuperString&)`
  - Appends the content of the passed `SuperString` to the end of the `data` array of the calling object
  - Ex. obj.data = "hello" and obj2.data = " world" then obj.append(obj2) -> obj.data == "hello world"
- `void replace(char find, char rep)`
  - Replaces all instances of the character `find` in the calling object's `data` array with the `rep` character.
  - Ex. obj.data = "catcat" then obj.replace('c', 't') -> obj.data = "tattat" 


Extra Credit Functions:
- `void removeAll(char)`
  - Removes all of the instances of the character that is passed in is in the `data` array
  - Ex. obj.data = "hello" then obj.removeAll('l') -> obj.data == "heo" 
- `void replace(std::string find, std::string sub)`
  - Replaces all instance of a string `find` with the string `sub`
  - Ex. obj.data = "this cat is a cool cat" then obj.replace("cat", "dog") -> obj.data = "this dog is a cool dog"
- `bool isUpper()`
  - Returns true if the `data` array contains all uppercase characters
  - Returns false if the `data` array contains anything other than uppercase characters
- `bool isLower()`
  - Returns true if the `data` array contains all lowercase characters
  - Returns false if the `data` array contains anything other than lowercase characters
- `bool isTitleCase()`
  - Returns true if the `data` array contains a sentence that is in proper "Title" case. 
  - Returns false if the `data` array contains contains a sentence that is not in proper "Title" case. 
  - For this function we are going to simplify the definition of "Title" case to be *every new word in a sentence is capitalized*. 
  - For example: "This Is Our Modified Title Case" and "This Does Not Count as Title Case" (because of the "as") 

## Timing of Commits
### Commit #1 Due 9/30 by Midnight
Functions to complete: 
1. `SuperString();`
2. `explicit SuperString(std::string);`
3. `SuperString(int, char);`
4. `SuperString(const SuperString&);`
5. `~SuperString();`
6. `int find(char, int start = 0);`
7. `int find(std::string, int start = 0);`
8. `SuperString substr(int, int);`

### Commit #2 Due 10/6 by Midnight
Functions to complete:
1. `SuperString reverse(const SuperString&);`
2. `SuperString replace(int, int, std::string);`
3. `void push_back(char);`
4. `void append(std::string);`
5. `void append(const SuperString&);`
6. `SuperString replace(char, char);`

### Extra Credit Due 10/6 by Midnight
1. `void removeAll(char);`
2. `SuperString replace(std::string, std::string);`
3. `bool isUpper();`
4. `bool isLower();`
5. `bool isTitleCase();`

## Compiling and Running your Code
To compile and run your code **with** Google Tests: 
```
Windows WSL and Linux: 
g++ main-gtest.cpp SuperString.cpp -lgtest -lpthread -o proj2
./proj2

Mac:
g++ -std=c++2a main-gtest.cpp SuperString.cpp -lgtest -lpthread -o proj2
./proj2
```

To compile and run your code **without** Google Tests: 
```
Windows WSL and Linux: 
g++ main.cpp SuperString.cpp -o proj2
./proj2

Mac:
g++ -std=c++2a main.cpp SuperString.cpp -o proj2
./proj2
```

To compile and run your *Extra Credit* code **with** Google Tests: 
```
Windows WSL and Linux: 
g++ main-bonus-gtest.cpp SuperString.cpp -lgtest -lpthread -o proj2
./proj2

Mac:
g++ -std=c++2a main-bonus-gtest.cpp SuperString.cpp -lgtest -lpthread -o proj2
./proj2
```

To compile and run your *Extra Credit* code **without** Google Tests: 
```
Windows WSL and Linux: 
g++ main-bonus.cpp SuperString.cpp -o proj2
./proj2

Mac:
g++ -std=c++2a main-bonus.cpp SuperString.cpp -o proj2
./proj2
```

For more information about the Google test cases and the non-gtest mains, see: https://github.com/coleca24/csce240_f21_p2/blob/main/Testing.md

## Submitting your Code to GitHub
This time, you may modify the header (.h) or the SuperString.cpp or even one of the non-gtest related mains! That means that you may have multiple files to push. Make sure you push them all up if needed.

Example for pushing the .h and the SuperString.cpp together
```
git pull 
git add SuperString.h SuperString.cpp
git commit -m "Added changes to .h and SuperString.cpp"
git push
```

Remember, you can use the command `git status` to see what files you have modified since your last pull! 

## Grading Rubric
See the Testing.md file (https://github.com/coleca24/csce240_f21_p2/blob/main/Testing.md) for breakdown per Google Test. 
### Commit #1 Due 9/30 by Midnight - 15 points
1. `SuperString();`                               - 1 point
2. `explicit SuperString(std::string);`           - 1 point
3. `SuperString(int, char);`                      - 1 point
4. `SuperString(const SuperString&);`             - 2 points
5. `~SuperString();`                              - 2 points
6. `int find(char, int start = 0);`               - 2 point
7. `int find(std::string, int start = 0);`        - 3 points
8. `SuperString substr(int, int);`                - 3 points

### Commit #2 Due 10/6 by Midnight - 25 points
1. `SuperString reverse(const SuperString&);`     - 3 points
2. `SuperString replace(int, int, std::string);`  - 5 points
3. `void push_back(char);`                        - 4 points
4. `void append(std::string);`                    - 5 points
5. `void append(const SuperString&);`             - 5 points
6. `SuperString replace(char, char);`             - 2 points

1 point for cpplint

### Extra Credit Due 10/6 by Midnight - 8 points total
1. `void removeAll(char);`                            + 2 point
2. `SuperString replace(std::string, std::string);`   + 2 points
3. `bool isUpper();`                                  + 1 point
4. `bool isLower();`                                  + 1 point
5. `bool isTitleCase();`                              + 2 point
