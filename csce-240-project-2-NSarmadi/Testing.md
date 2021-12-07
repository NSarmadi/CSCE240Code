# Testing your Code for Project 2
This time around you will have 2 ways that you can test your code locally on your machine. You can test them with a main that has Google Tests enabled or one that does not. Note that even if you decide to just use the non-gtest enabled mains, you should run your code with the GTest mains at some point to figure out your grade!

## Testing with the GTest Mains
The following will outline the different test cases in the Google Test mains.

### Commit #1 Functions
**Commit1.defaultConstructor**
- Tests SuperString()
- Checks that the size of the object created using your default constructor is of size 0 

**Commit1.altConstructor1**
- Tests SuperString(std::string)
- Checks that:
  - The size of the object created in this constructor is the same size as the string passed in. 
  - The content of the object created in this constructor is the same as the string passed in. 

**Commit1.altConstructor2**
- Tests SuperString(int, char)
- Checks that:
  - The size of the object created in this constructor is the int passed in. 
  - The content of the object created in this constructor is all the character passed in. 

**Commit1.copyConstructor**
- Tests SuperString(SuperString&)
- Checks that:
  - The size of the object created in this constructor is the same size as the object passed in.
  - The content of the object created in this constructor is the same as the contents of the object passed in. 

**Commit1.findChar**
- Tests find(char, int) 
- Checks that: 
  - If a valid character and index are passed, then it will return the correct index of the character in the data array. It looks at multiple starting points (different values for the passed int)
  - If just a valid character is passed, it checks that the function uses the default value of the second parameter and returns the correct index. 
  - If a character is passed that does not exist, the function should return -1

**Commit1.findStr**
- Tests find(std::string, int)
- Checks that: 
  - If a valid string and index are passed, then it will return the correct index of the string in the data array. It looks at multiple starting points (different values for the passed int)
  - If just a valid string is passed, it checks that the function uses the default value of the second parameter and returns the correct index. 
  - If a string is passed that does not exist, the function should return -1

**Commit1.substrValid**
- Tests substr(int, int)
- Checks that: 
  - If a valid index and number of characters are passed then the object that is returned from the function has the correct content

**Commit1.substrInvalid**
- Tests substr(int, int)
- Checks that: 
  - If an invalid index and number of characters are passed then the object that is returned from the function has size 0

### Commit #2 Functions
**Commit2.reverse**

**Commit2.replaceValid**

**Commit2.replaceInvalid**

**Commit2.pushBack**

**Commit2.appendString**

**Commit2.appendSuperString**

**Commit2.replace**

### Bonus Functions

## Testing with the non-GTest Mains

### Commit #1 Functions

### Commit #2 Functions

### Bonus Functions
