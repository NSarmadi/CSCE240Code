// Copyright 2021 Coleca24
#include <iostream>
#include "./SuperString.h"

using std::string;


int main(int argc, char** argv) {
    SuperString s1("that cat is a cool cat");
    SuperString s2("that cat is a cool cat");
    SuperString s3("TEST");
    SuperString s4("test");
    SuperString s5("This Is Title Case");
    SuperString s6("This Is not Title Case");

    // ------------Testing removeAll(char)-----------------
    std::cout << "----\nTesting removeAll(char) - removing"
              << "all 'c' characters in \"this cat is a cool cat\'\n";
    s1.removeAll('c');
    std::cout << "Your output: \n";
    s1.print();
    std::cout << "Correct output: \nthis at is a ool at\n";

    // ------------Testing replace(string, string)-----------------
    std::cout << "----\nTesting replace(string,string) - replacing"
              << "all \"cat\" in \"this cat is a cool cat\" "
              << "with \"dog\"\n";
    s2.replace("cat", "dog");
    std::cout << "Your output: \n";
    s2.print();
    std::cout << "Correct output: \nthis dog is a cool dog\n";

    // ------------Testing isUpper(string, string)-----------------
    std::cout << "----\nTesting isUpper()\n";
    std::cout << "Your output: "<< s3.isUpper() << "\n";
    std::cout << "Correct output: \ntrue\n";
    std::cout << "Your output: "<< s4.isUpper() << "\n";
    std::cout << "Correct output: \nfalse\n";

    // ------------Testing isLower(string, string)-----------------
    std::cout << "----\nTesting isLower()\n";
    std::cout << "Your output: "<< s3.isLower() << "\n";
    std::cout << "Correct output: \nfalse\n";
    std::cout << "Your output: "<< s4.isLower() << "\n";
    std::cout << "Correct output: \ntrue\n";

    // ------------Testing isTitleCase(string, string)-----------------
    std::cout << "----\nTesting isTitleCase()\n";
    std::cout << "Your output: "<< s5.isTitleCase() << "\n";
    std::cout << "Correct output: \ntrue\n";
    std::cout << "Your output: "<< s6.isTitleCase() << "\n";
    std::cout << "Correct output: \nfalse\n";

    return 0;
}
