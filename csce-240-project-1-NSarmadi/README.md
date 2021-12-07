# Project 1 CSCE 240 Fall 2021 (20 points)
In this project, you will be writing a basic login system. You will create a basic command line interface (CLI) as well as implement the ability for the user to add, delete, search and more. The data for the system will be stored in a flat file (in this case a CSV file). 

You will need to implement 12 functions. The prototypes for these will be in the login.h file. **You will only need to modify the login.h file, DO NOT MODIFY THE `main.cpp` file or any of the files in the ./test folder**

To simplify the prototypes for the functions, I have elected to keep both dimensions of the array as constant global variables. 
```
const int COLS = 4;
const int ROWS = 5;
```
This means that your login system only has the capacity for 5 users at most. We are going to enforce that limit. 

The starting users for the system are in the data/ folder in a file called  `user_info.csv`.  

## Some comments about `user_info.csv`
### Format
You will find that in the file there are 4 attributes for each user: Name, Email, Password and Job Title.

This is how your file should start.
```
Earl Jones,EarlJones@email.com,7Rfkqyuq,Manager
Kandy McGill,KandyMcGill@email.com,bYeP82i6,Engineer
Hank Stark,HankStark@email.com,t277Bqyi,Manager
Bob Baker,BobBaker@email.com,yidHvr81,Engineer
Tariq Thompson,TariqThompson@email.com,hB23uiyu,CEO
```
- Col 0 = Name
- Col 1 = Email
- Col 2 = Password
- Col 3 = Job Title

Also notice, that there are **no spaces** before or after a comma. You will want to keep it consistant like this if you want to pass all the tests! 

### Getting back to the original
As you are testing, you will probably edit the file (for instance when you are testing the delete and the add functions described below). If you ever want to get back to the original to test, issue the following command inside the repo's folder: 
```
cp ./data/user_info_back.csv ./data/user_info.csv
```
If you really mess it up, then let me know and I can push you a new file to start with. 

## Commit #1 (Due 9/13/21 at Midnight) Functions to Complete:
These are in order of how I would suggest to complete them. These 6 will be the ones tested for commit #1 (5 points total).

- `bool readUsers(string fh, string data[ROWS][COLS]);`
  -   Reads in the user from the flat csv file and stores it in the data array.
  -   `fh` is the name of the file to be read. This will be sent in by the main. 
  -   `data` is a 5x4 array that you will populate with the data from the `user_info.csv` file. 
- `void printUsers(const string data[ROWS][COLS]);`
  - Prints out the contents of the 2d array to standard out
  - This function will be useful as a debugging step. 
  - `data` is a 5x4 array that has the user information 
- `bool validateOption(char option);`
  - This function will validate whether a valid input was given to your CLI. 
  - The valid inputs are: E, e, P, p, S, s, F, f, A, a, D, d
  - `option` is the character that should be checked for being a valid input
  - returns bool - true if `option` is a valid input, false otherwise.
- `char displayOptions();`
  -  This function will display the command line options that the user can input into your system. 
  -  It should include a call to `cin` to get the choice from the user and return this choice if it is a valid option (Hint: you will use the `validateOption(char)` to check).
- `void executeOption(char option, const string data[ROWS][COLS], string fn);`
  - Based on the `option` that is sent in, the correct function should be called. Note that for this first commit, you will not have all of the functions implemented, so it is fine for you to just put a cout statement for that option as a placeholder for now. 
  - Options: 
    - E/e Ends the program - you will actually not have to do anything for this option in this function (note the flow in the main function in main.cpp)
    - P/p Calls printUsers()
    - S/s Calls searchForUser() - You will need to first read in a name from the user to pass to this function. You should also use the index that this function returns to print out the user infomation that was found (if one was found - see output example). 
    - F/f Calls findAllUsers() - You will need to read in a job title from the user to pass to this function. You should also print out the number of users that were found here (see output example). 
    - A/a Calls the addUser() function - You will need to read in a name and a job title from the user to send to this function. Before calling the function, you should first check to see if there is an empty spot (a row populated by "NULL"s). If there is not, then you should tell the user that the database is full (see example output). You should also not allow the user to add a duplicate entry. 
    - D/d Calls the deleteUser() function - You will need to read in a name from the user to send to this function. If the user is deleted, then the user should be told they were successfully deleted. If they were not found then the user should be told that there was no user found. 
  - `option` is the action that the user chose in the `displayOptions()` function (note in the main.cpp how this flows). 
  - `data` is a 5x4 array that has the user information 
  -  `fh` is the name of the file. Some of the functions that you will call in this function will need the file name. 
- `int searchForUser(string name, const string data[ROWS][COLS]);`
  -  Allows the user to search the data array by name. If there is a match then the index of the match (the row number) is returned. If there is no match then -1 is returned. 
  -  `name` is the name to search for in the `data` array. 
  -  `data` is a 5x4 array that has the user information

### Example outputs
https://github.com/coleca24/csce240_f21_p1/blob/main/OutputExamples.md

## Commit #2 (Due 9/20/21 by Midnight) Functions to complete:
These are in order of how I would suggest to complete them. These 6 will be the ones tested for commit #2 (15 points total).
- `int findAllUsers(string title, const string data[ROWS][COLS]);` 
  - This function should allow the user to find the number of users that have a certain job title in the data. 
  -  `title` is the job title to search for in the `data` array (this is always in column 3). 
  -  `data` is a 5x4 array that has the user information
  -  returns an int - count of matches for a given string `title`
- `bool deleteUser(string name, string data[ROWS][COLS], string);`
  - Allows the user to delete a user from the system given a `name`. If the `name` does not exist then this function should return false. If the `name` does exist then it should replace all values of the row in which `name` was found with "NULL". It should also write the changes back to the `user_info.csv` file in the exact format as it was when you started. 
  - `name` is the name to search for in the `data` array and then delete if it exisits. 
  -  `data` is a 5x4 array that has the user information
  -  returns an bool - false if name was not found, true if it was found and deleted.
Ex. of deleteUser(). Imagine the file starts like this:
```
Earl Jones,EarlJones@email.com,7Rfkqyuq,Manager
Kandy McGill,KandyMcGill@email.com,bYeP82i6,Engineer
Hank Stark,HankStark@email.com,t277Bqyi,Manager
Bob Baker,BobBaker@email.com,yidHvr81,Engineer
Tariq Thompson,TariqThompson@email.com,hB23uiyu,CEO
```
And then the user performs a `deleteUser("Bob Baker", data, fh)`, then the new array and file should look like this:
```
Earl Jones,EarlJones@email.com,7Rfkqyuq,Manager
Kandy McGill,KandyMcGill@email.com,bYeP82i6,Engineer
Hank Stark,HankStark@email.com,t277Bqyi,Manager
NULL,NULL,NULL,NULL
Tariq Thompson,TariqThompson@email.com,hB23uiyu,CEO
```
Note that you can leave the empty row in the same spot as were it was when it was populated and do not need to worry about rearranging the entries (we will do this in a future assignment :) ). 
 
- `string generatePassword();`
  - Function that should generate a password for a user. This function will be called within the `addUser()` function. 
  - Returns a string that has the following attributes:
    - Exactly 8 characters
    - Exactly 1 number (0-9) 
    - Exactly 1 uppercase letter
    - Exactly 6 lowercase letters
  - General hints: 
    - Remember that a char can be converted to an int that is it's ASCII dec value (https://en.cppreference.com/w/cpp/language/ascii). You can go the other way too. You can generate an int and change it to a char...
    - Random numbers can be generated by either using the `rand()` function (https://www.cplusplus.com/reference/cstdlib/rand/) or the `<random>` library (https://www.cplusplus.com/reference/random/). Note that you can **ignore** the cpplint error that is returned for the `rand()` function. 
- `string generateEmail(string name);`
  - Function that will generate an email from a `name` that is passed in. This function will be called within the `addUser()` function. 
  - Returns a string that contains the email. General Form: 
    - Name = "Bob Watts"
    - Email = "BobWatts@email.com"
  - General hints:
    - Take a look at the `string` functions `find()` (https://www.cplusplus.com/reference/string/string/find/) and `replace()` (https://www.cplusplus.com/reference/string/string/replace/). You may end up using both, or just 1 or the other. 
- `int checkEmpty(const string data[ROWS][COLS]);`
  - Function that will return the first row of the `data` array that is empty (a row of all "NULL" values). This function will be called **before** the `addUser()` function in the `executeOption()` function. The first parameter of the `addUser()` function will take in the `int` returned from this function.  
  - If there are no empty rows, it returns -1
- `void addUser(int index, string name, string title, string data[ROWS][COLS], string fh);`
  - This function will allow the user to add a user to the database at a given `index`. This function will call the `generatePassword()` and `generateEmail()` functions to fill in those values. Note that this function should also write the changes back to the `user_info.csv` file. 
  - `index` is the row in which to add the user. 
  - `name` is the name of the new user to add. 
  - `title` is the job title of the new user to add.
  - `data` is a 5x4 array that has the user information
  - `fh` is the name of the file to open and write to. 

### Example outputs
https://github.com/coleca24/csce240_f21_p1/blob/main/OutputExamples.md

## Some comments about the `main()`
### Flow
The `main()` function looks like this, I have added comments below to describe each action it takes. 
```
int main(int argc, char** argv) {
     // Setting up and initializing the values of data to all "NULL"
     std::string data[ROWS][COLS];
     init(data);
     // Setting the file name 
     std::string fn = "./data/user_info.csv";
     // Call to your readUsers() function 
     bool success = readUsers(fn, data);
     // Call to your printUsers() function - gives you a chance to debug your readUsers() function. 
     // This should have the data from user_info.csv, if there are any "NULL" then you did something wrong. 
     printUsers(data);
     // If the file was read in, start the main loop of asking the user for input. 
     if (success) {
          char option;
          do {
               // Call to your displayOptions() function 
               option = displayOptions();
               // Feed the input to the executeOption() function
               executeOption(option, data, fn);
            //Stop if they enter 'e' or 'E'
          } while (option != 'e' && option != 'E');
     } else {
          std::cout << "Could not open file\n";
     }
     // Run all tests when the loop finishs! 
     ::testing::InitGoogleTest(&argc, argv);
     return RUN_ALL_TESTS();
}
```
**At the bare minimum, you will need to have all functions defined to get the main to run. They do not need to do anything (ie. they can have a dummy cout or dummy return statement) but they do need to be defined.**

## Running your code

To compile your code: 
```
Windows WSL and Linux: 
g++ main.cpp -lgtest -lpthread -o login

Mac:
g++ -std=c++2a main.cpp -lgtest -lpthread -o login
```

To run your code: 
```
All platforms: 
./login 
```

## Grading
### Commit #1 Due 9/13/21 at Midnight (5 pts)
For commit #1 you need to be passing all of the tests in the commit1 test module (6 in total)

1. Commit1.readUsersOpensCorrectFile - 0.5 pt
2. Commit1.readUsersFailsWithIncorrect - 0.5 pt
3. Commit1.readUsersCorrectContent - 2 pt 
4. Commit1.validateOptionCorrect - 0.5 pt
5. Commit1.searchForUserFoundCorrectIndex - 1 pt 
6. Commit1.searchForUserNotFoundCorrect - 0.5 pt

For more info about these test cases, please see https://github.com/coleca24/csce240_f21_p1/blob/main/Tests.md. 

### Commit #2 Due 9/20/21 at Midnight (15 pts)
For commit #2 you need to be passing all of the tests in the commit1 test module (11 in total)

1. Commit2.findAllUsersCorrectExists - 1 pt
2. Commit2.findAllUsersCorrectNotExist - 1 pt 
3. Commit2.deleteUserReturnCorrectReturn - 0.5 pt 
4. Commit2.deleteUserArrayCorrect - 1.5 pts
5. Commit2.deleteUserFileCorrect - 2 pts
6. Commit2.generatePasswordCorrect - 1 pt
7. Commit2.generateEmailCorrect - 1 pt
8. Commit2.checkEmptyCorrectIndexFound - 0.5 pt
9. Commit2.checkEmptyCorrectIndexNotFound - 0.5 pt
10. Commit2.addUserReturnArrayCorrect - 2 pts
11. Commit2.addUserFileCorrect - 2 pts

**1 pt for passing the style checker**

For more info about these test cases, please see https://github.com/coleca24/csce240_f21_p1/blob/main/Tests.md. 
