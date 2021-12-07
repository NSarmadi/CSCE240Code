// Copyright 2021 Coleca24
#include <iostream>
#include "./SuperString.h"

using std::string;


int main(int argc, char** argv) {
     SuperString s;
     string test = "test";
     SuperString s1(test);
     SuperString s2(5, 'x');
     SuperString s3(s2);
     SuperString s4("Hello");
     SuperString s5("that cat is a cool cat");

     // ------------Testing Constructors-----------------
     std::cout << "----\nTesting Default Constructor: \n";
     std::cout << "Your output: \n";
     s.print();
     std::cout << "Correct output: \n<EMPTY>\n";

     std::cout << "----\nTesting Alt Constructor 1: \n";
     std::cout << "Your output: \n";
     s1.print();
     std::cout << "Correct output: \ntest\n";

     std::cout << "----\nTesting Alt Constructor 2: \n";
     std::cout << "Your output: \n";
     s2.print();
     std::cout << "Correct output: \nxxxxx\n";

     std::cout << "----\nTesting Copy Constructor: \n";
     std::cout << "Your output: \n";
     s3.print();
     std::cout << "Correct output: \nxxxxx\n";

     // ------------Testing find(char, int)-----------------
     std::cout << "----\nTesting find(char, int) - "
               << "looking for 'l' in \"Hello\" starting at 0: \n";
     std::cout << "Your output: \n"
               << s4.find('l', 0) << "\n";
     std::cout << "Correct output: \n2\n";

     std::cout << "----\nTesting find(char, int) - "
               << "looking for 'l' in \"Hello\" starting at 3: \n";
     std::cout << "Your output: \n"
               << s4.find('l', 3) << "\n";
     std::cout << "Correct output: \n3\n";

     std::cout << "----\nTesting find(char, int) - "
               << "looking for 'l' in \"Hello\" starting at 4: \n";
     std::cout << "Your output: \n"
               << s4.find('l', 4) << "\n";
     std::cout << "Correct output: \n-1\n";

     std::cout << "----\nTesting find(char, int) - "
               << "looking for 'l' in \"Hello\" starting at default: \n";
     std::cout << "Your output: \n"
               << s4.find('l') << "\n";
     std::cout << "Correct output: \n2\n";

     // ------------Testing find(string, int)-----------------
     std::cout << "----\nTesting find(string, int) - "
               << "looking for \"cat\" in \"that cat is a cool cat\""
               << "starting at 0: \n";
     std::cout << "Your output: \n"
               << s5.find("cat", 0) << "\n";
     std::cout << "Correct output: \n5\n";

     std::cout << "----\nTesting find(string, int) - "
               << "looking for \"cat\" in \"that cat is a cool cat\""
               << "starting at 6: \n";
     std::cout << "Your output: \n"
               << s5.find("cat", 6) << "\n";
     std::cout << "Correct output: \n19\n";

     std::cout << "----\nTesting find(string, int) - "
               << "looking for \"cat\" in \"that cat is a cool cat\""
               << "starting at default (0): \n";
     std::cout << "Your output: \n"
               << s5.find("cat") << "\n";
     std::cout << "Correct output: \n5\n";

     // ------------Testing length()-----------------
     std::cout << "----\nTesting length() with empty object\n";
     std::cout << "Your output: \n"
               << s.length() << "\n";
     std::cout << "Correct output: \n0\n";

     std::cout << "----\nTesting length() with non-empty object\n";
     std::cout << "Your output: \n"
               << s1.length() << "\n";
     std::cout << "Correct output: \n4\n";

     // ------------Testing substr(int, int)-----------------
     std::cout << "----\nTesting substr(int, int) with invalid start\n";
     SuperString ret = s1.substr(-1, 5);
     std::cout << "Your output: \n";
     ret.print();
     std::cout << "Correct output: \n<EMPTY>\n";

     std::cout << "----\nTesting substr(int, int) with invalid numChars\n";
     SuperString ret2 = s1.substr(0, 10);
     std::cout << "Your output: \n";
     ret2.print();
     std::cout << "Correct output: \n<EMPTY>\n";

     std::cout << "----\nTesting substr(int, int) with valid start "
               << "and numChars\n";
     SuperString ret3 = s1.substr(0, 2);
     std::cout << "Your output: \n";
     ret3.print();
     std::cout << "Correct output: \nte\n";

     // ------------Testing reverse()-----------------
     std::cout << "----\nTesting reverse()\n";
     SuperString rev = s1.reverse();
     std::cout << "Your output: \n";
     rev.print();
     std::cout << "Correct output: \ntset\n";

     // ------------Testing replace(int, int, string)-----------------
     std::cout << "----\nTesting replace(int, int, string) with "
               << "invalid start\n";
     SuperString rep1 = s1.replace(-1, 5, "hi");
     std::cout << "Your output: \n";
     rep1.print();
     std::cout << "Correct output: \n<EMPTY>\n";

     std::cout << "----\nTesting replace(int, int, string) with "
               << "invalid numChars\n";
     SuperString rep2 = s1.replace(0, 10, "hi");
     std::cout << "Your output: \n";
     rep2.print();
     std::cout << "Correct output: \n<EMPTY>\n";

     std::cout << "----\nTesting replace(int, int, string) with "
               << "valid start and numChars\n";
     SuperString rep3 = s1.replace(0, 3, "hi");
     std::cout << "Your output: \n";
     rep3.print();
     std::cout << "Correct output: \nhit\n";

     // ------------Testing push_back(char)-----------------
     std::cout << "----\nTesting push_back(char)\n";
     s1.push_back('!');
     std::cout << "Your output: \n";
     s1.print();
     std::cout << "Correct output: \ntest!\n";

     // ------------Testing append(string)-----------------
     std::cout << "----\nTesting append(string)\n";
     s.append("hello world");
     std::cout << "Your output: \n";
     s.print();
     std::cout << "Correct output: \nhello world\n";

     // ------------Testing append(SuperString)-----------------
     std::cout << "----\nTesting append(SuperString)\n";
     s2.append(s2);
     std::cout << "Your output: \n";
     s2.print();
     std::cout << "Correct output: \nxxxxxxxxxx\n";

     // ------------Testing replace(char, char)-----------------
     std::cout << "----\nTesting replace(char, char) - replacing "
              << "all 'c' characters in \"this cat is a cool cat\""
              <<"with 't'\n";
     s5.replace('c', 't');
     std::cout << "Your output: \n";
     s5.print();
     std::cout << "Correct output: \nthis tat is a tool tat\n";

     
     return 0;
}
