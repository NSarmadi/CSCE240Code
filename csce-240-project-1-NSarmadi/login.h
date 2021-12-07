// Author: Neekon Sarmadi
// Email: nsarmadi@email.sc.edu
// Section #: 003
// Copyright 2021 Neekon Sarmadi
// Modified from template code @coleca24 GitHub
#ifndef LOGIN_H_
#define LOGIN_H_

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using std::string;

const int COLS = 4;
const int ROWS = 5;

// TODO(commit 1): Commit #1 functions
void printUsers(const string data[ROWS][COLS]); 
bool readUsers(string fh, string data[ROWS][COLS]);
char displayOptions();
bool validateOption(char option);
void executeOption(char option, string data[ROWS][COLS], string);
int searchForUser(string name, const string data[ROWS][COLS]);

// TODO(commit 2): Commit #2 functions
int findAllUsers(string title, const string data[ROWS][COLS]);
bool deleteUser(string name, string data[ROWS][COLS], string fh);
string generatePassword();
string generateEmail(string name);
int checkEmpty(const string data[ROWS][COLS]);
void addUser(int index, string name, string title,
             string data[ROWS][COLS], string fh);

void printUsers(const string data[ROWS][COLS]) {
  
}
bool readUsers(string fh, string data[ROWS][COLS]) {
  std::ifstream in(fh);
  std::string line, elem;
     int i = 0;
     if (in.is_open()) 
     {
          while (getline(in, line)) 
          {
               std::stringstream s(line);
               int j = 0;
               while (getline(s, elem, ',')) 
               {
                    data[i][j] = elem;
                    j++;
               }
               i++;
          }
          in.close();
          return true;
     }
     return false;
}
char displayOptions() {
  // std::cout << "E/e Ends the program" << "\n";
  // std::cout << "P/p Calls printUsers()" << "\n";
  // std::cout << "S/s Calls searchForUser()" << "\n";
  // std::cout << "F/f Calls findAllUsers()" << "\n";
  // std::cout << "A/a Calls the addUser() function" << "\n";
  // std::cout << "D/d Calls the deleteUser() function" << "\n";
  // std::cout << "Please choose an option: " << "\n"

  return 'e';
}
bool validateOption(char option) {
  if(option == 'p'|| option == 'P')
  {
    return true;
  }
  if(option == 's'|| option == 'S')
  {
    return true;
  }
  if(option == 'f'|| option == 'F')
  {
    return true;
  }
  if(option == 'a'|| option == 'A')
  {
    return true;
  }
  if(option == 'd'|| option == 'D')
  {
    return true;
  }
  if(option == 'e'|| option == 'E')
  {
    return true;
  }
  return false;
}
void executeOption(char option, string data[ROWS][COLS], string fn) {
  if(option == 'p'|| option == 'P')
  {
    printUsers(data);
  }
  if(option == 's'|| option == 'S')
  {
    
  }
  if(option == 'f' || option == 'F')
  {
    //findAllUsers(data, item);
  }
  if(option == 'a'|| option == 'A')
  {
    return;
  }
  if(option == 'd' || option == 'D')
  {
    return;
  }
  return;
}
int searchForUser(string name, const string data[ROWS][COLS]) {
  for (int i = 0 ; i < ROWS ; i++)
  {
    for (int j = 0 ; j < COLS ; i++)
    {
      if (data[i][j] == name) return i;
    }
  }
  return -1;
}

int findAllUsers(string title, const string data[ROWS][COLS]) {
  int amt = 0;
  for (int i = 0; i < ROWS; i++)
  {
    if (data[i][3] == title) amt++;
  }
  if(amt == 0)
  {
    return amt;
  }
  return -1;
}
bool deleteUser(string name, string data[ROWS][COLS], string fh) 
{
  bool check = false;
  for (int i = 0; i < ROWS; i++)
  {
    int j = 0;
    if (data[i][0] == name) 
    {
      while (j < COLS) {
        data[i][j] = "NULL";
        j++;
      }
      check = true;
    }
  }
  std::ofstream out(fh);
  if(check == true){
    for (int i = 0 ; i < ROWS; i++)
    {
      for (int j = 0; j < COLS; j++)
      {
        if (j != 3){
          out << data[i][j] + ",";
        }else{
          out << data[i][j] << std::endl;
        }
        }
      }
      out.close();
      return true;
    }
    return false;
}
string generatePassword() 
{
  std::string pwd;
  srand(time(NULL));
    int randN = 0;
    for (int i = 0; i < 8; i++)
    {
      randN = rand() % 43 + 48;
      char c = randN;
      pwd.push_back(c);
    }
  return pwd;
}
string generateEmail(string name) {
  string email = name;
  string look = " ";
  email.replace(email.find(look), look.length(), "");
  email += "@email.com";
  return email;
}
int checkEmpty(const string data[ROWS][COLS]) {
  for (int i = 0; i < ROWS; i++){
    for (int j = 0; j < COLS; j++){
      if (data[i][j] == "NULL") return i;
    }
  }
  return -1;
}
void addUser(int index, string name, string title,
             string data[ROWS][COLS], string fh) {
  data[index][0] = name;
  data[index][1] = generateEmail(name);
  data[index][2] = generatePassword();
  data[index][3] = title;
  std::ofstream out(fh);
  for (int i = 0 ; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      if (j != 3){
        out << data[i][j] + ",";
      }else
      {
        out << data[i][j] << std::endl;
      }
      
    }
  }
    out.close();
  return;
}

#endif  // LOGIN_H_
