// Copyright 2021 <Your name here>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using std::vector;
using std::cout;
using std::string;

void readData(vector<string> &data, string filename);
void printData(const vector<string> &data);
vector<int> findMinHamming(const vector<string> & data, string test);
void printMinDistance(const vector<string> &data, string word,
                      const vector<int> min);

int main(int argc, char **argv) {
  string filename;
  vector<string> data;
  if (argc != 2) {
    cout << "Usage: ./sub1 data.txt\n";
    exit(0);
  }
  filename = argv[1];
  readData(data, filename);
  printData(data);
  for (auto line : data) {
    vector<int> ret;
    ret = findMinHamming(data, line);
    printMinDistance(data, line, ret);
  }
  return 0;
}

void readData(vector<string> &data, string filename) {
  std::ifstream fs(filename); 
  string word;
  while (getline(fs,word)){
    data.push_back(word);
  }
  fs.close();
}

void printData(const vector<string> &data) {
   for(auto word : data){
     cout << word << "\n";
   }
}

vector<int> findMinHamming(const vector<string> & data, string test) {
  vector<int> ret;
  int min = -1;
  int mindex = -1;
  for (int i = 0; i < data.size() ; i++){
    int over;
    int n_min = 0;
    int l_size=0;
    if (test.size() <= data[i].size()){
      l_size = test.size();
    }else{
      l_size = data[i].size();
    }
    for (int j = 0; j < l_size; j++){
      if (test[j] != data[i][j]){
        n_min++;
      }
      if (n_min + over < min || min == -1 && n_min + over != 0){
        min = n_min + over;
        mindex = 1;
      }
    }
    ret.push_back(mindex);
    ret.push_back(min);
  }
  return ret;
}


void printMinDistance(const vector<string> &data, string word,
                      const vector<int> min) {
  cout << "The minimum hamming distance for " << word << " is " << min[1] << " (matching word: " << data[min[0]] <<")" << "\n";
}
