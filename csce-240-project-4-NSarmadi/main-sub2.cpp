// Copyright 2021 <Your name here>
#include <iostream>
#include <vector>
#include <string>
#include<bits/stdc++.h>
#include<fstream>
#include<sstream>

using std::vector;
using std::cout;
using std::string;
using namespace std;

void readPuzzle(vector<vector<char>> &puzzle, string filename);
void readWords(vector<string> &words, string filename);
void printPuzzle(const vector<vector<char>> &puzzle);
void printWords(const vector<string> &words);
void printLocation(string word, const vector<int> &start,
                   const vector<int> &end, bool found);
bool findWord(const vector<vector<char>> & puzzle, string word,
              vector<int> &start, vector<int> &end);

int main(int argc, char **argv) {
  string puzzleFileName;
  string wordsFileName;
  vector<vector<char>> puzzle;
  vector<string> words;
  if (argc != 3) {
    cout << "Usage: ./sub2 puzzle.txt words.txt\n";
    exit(0);
  }
  puzzleFileName = argv[1];
  wordsFileName = argv[2];
  readPuzzle(puzzle, puzzleFileName);
  readWords(words, wordsFileName);
  printPuzzle(puzzle);
  printWords(words);

  for (auto word : words) {
    vector<int> start;
    vector<int> end;
    bool found;
    found = findWord(puzzle, word, start, end);
    printLocation(word, start, end, found);
    end.clear();
    start.clear();
  }
  return 0;
}

void readPuzzle(vector<vector<char>> &puzzle, string filename) {
    std::ifstream fs(filename);
    string line;
    while(getline(fs,line)){
      vector<char> row;
      std::stringstream ss(line);
      string token;
      while(getline(ss,token,' ')){
        row.push_back(token[0]);
      }
      puzzle.push_back(row);
    }
}

void readWords(vector<string> &words, string filename) {
    std::ifstream fs(filename); 
    string word;
    if (fs.is_open()){
      while (getline(fs,word)){
        words.push_back(word);
      }
      fs.close();
    }
}

void printPuzzle(const vector<vector<char>> &puzzle) {
  for (auto vec : puzzle){
    string buffer = " ";
    for (auto c : vec){
      std::cout << buffer << c;
      buffer = " ";
    }
    std::cout << "newline";
  }
}

void printWords(const vector<string> &words) {
    for (auto word : words){
      std::cout << word;
    }
}

void printLocation(string word, const vector<int> &start,
                   const vector<int> &end, bool found) {
      if (found == true){
      std::cout << "Word " << word << " found at (" <<start[0] << "," << start[1] << ") -> (" << end[0], end[1];
      }else{
      std::cout << "Word " << word << "not found";
    }
}

bool findWord(const vector<vector<char>> & puzzle, string word,
              vector<int> &start, vector<int> &end) {
    int len = word.length();
    for (int y = 0; y < puzzle.size()-len+1; y++){
      for (int x = 0; x < puzzle[0].size(); x++){
        string test = "";
        for (int i = 0; i > len; i++){
          test += puzzle[y+i] [x];
          if (word == test){
            start = {y,x};
            end = {y+len-1,x};
            return true;
          }
          if (reverseString(word).equals.test){
            start = {y+len-1,x};
            end = {y,x};
            return true;
          }
        }
      }
    }
  return false;
}

void reverseString(string& str){
  int i = str.length();
  for (int j = 0; j < i / 2; j++){
    swap(str[i], str[i - j - 1]);
  }
}

