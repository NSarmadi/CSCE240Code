// Copyright 2021 Coleca24
#include <gtest/gtest.h>
#include <iostream>
#include "./SuperString.h"

// DO NOT MODIFY THIS FILE

TEST(Commit1, defaultConstructor) {
     SuperString s;
     EXPECT_EQ(s.length(), 0) << "Length incorrect for default\n"
          << "Should be 0!";
}

TEST(Commit1, altConstructor1) {
     std::string hello = "hello";
     SuperString s(hello);
     EXPECT_EQ(s.length(), 5) << "Length incorrect for alt 1\n"
          << "Should be 5!";
     for (int i = 0; i < 5; i++) {
          EXPECT_EQ(s.get(i), hello[i]) << "Element at " << i
               << " differs";
     }
}

TEST(Commit1, altConstructor2) {
     SuperString s(5, 'x');
     EXPECT_EQ(s.length(), 5) << "Length incorrect for alt 2\n"
          << "Should be 5!";
     for (int i = 0; i < 5; i++) {
          EXPECT_EQ(s.get(i), 'x') << "Element at " << i
               << "differs";
     }
}

TEST(Commit1, copyConstructor) {
     SuperString ts(5, 'x');
     SuperString s(ts);
     EXPECT_EQ(s.length(), 5) << "Length incorrect for copy\n"
          << "Should be 5!";
     for (int i = 0; i < 5; i++) {
          EXPECT_EQ(s.get(i), 'x') << "Element at " << i
               << "differs";
     }
}

// int find(char, int start = 0);
TEST(Commit1, findChar) {
     SuperString s("test");
     EXPECT_EQ(s.find('t', 0), 0) << "Return for find(char,int)\n"
          << "incorrect for test s.find('t', 0) when s.data == \"test\"";
     EXPECT_EQ(s.find('t', 1), 3) << "Return for find(char,int)\n"
          << "incorrect for test s.find('t', 1) when s.data == \"test\"";
     EXPECT_EQ(s.find('t'), 0) << "Return for find(char,int)\n"
          << "incorrect for test s.find('t') when s.data == \"test\"";
     EXPECT_EQ(s.find('z', 0), -1) << "Return for find(char,int)\n"
          << "incorrect for test s.find('z', 0) when s.data == \"test\"";
}

// int find(std::string, int start = 0);
TEST(Commit1, findStr) {
     SuperString s("that cat is a cool cat");
     EXPECT_EQ(s.find("cat", 0), 5) << "Return for find(str,int)\n"
          << "incorrect for test s.find(\"cat\", 0) when s.data "
          << "== \"that cat is a cool cat\"";
     EXPECT_EQ(s.find("cat", 6), 19) << "Return for find(str,int)\n"
          << "incorrect for test s.find(\"cat\", 6) when s.data "
          << "== \"that cat is a cool cat\"";
     EXPECT_EQ(s.find("cat"), 5) << "Return for find(str,int)\n"
          << "incorrect for test s.find(\"cat\") when s.data "
          << "== \"that cat is a cool cat\"";
     EXPECT_EQ(s.find("dog", 0), -1) << "Return for find(str,int)\n"
          << "incorrect for test s.find(\"dog\") when s.data "
          << "== \"that cat is a cool cat\"";
}

// SuperString substr(int, int);
TEST(Commit1, substrValid) {
     SuperString s("that cat is a cool cat");
     SuperString ret = s.substr(0, 4);
     EXPECT_EQ(ret.length(), 4) << "Length incorrect for substr(int,int)\n"
          << "Should be 4!";
     std::string comp = "that";
     for (int i = 0; i < 4; i++) {
          EXPECT_EQ(ret.get(i), comp[i]) << "Element at " << i
               << "differs";
     }
}

TEST(Commit1, substrInvalid) {
     SuperString s("that cat is a cool cat");
     SuperString ret = s.substr(23, 4);
     EXPECT_EQ(ret.length(), 0) << "Length incorrect for substr(int,int)\n"
          << "Should be 0!";
}

// SuperString reverse();
TEST(Commit2, reverse) {
     SuperString s("test");
     SuperString ret = s.reverse();
     EXPECT_EQ(ret.length(), 4) << "Length incorrect for reverse()\n"
          << "Should be 4!";
     std::string comp = "tset";
     for (int i = 0; i < 4; i++) {
          EXPECT_EQ(ret.get(i), comp[i]) << "Element at " << i
               << "differs";
     }
}

// SuperString replace(int, int, std::string);
TEST(Commit2, replaceValid) {
     SuperString s("test");
     SuperString ret = s.replace(0, 2, "bu");
     EXPECT_EQ(ret.length(), 4) << "Length incorrect for replace()\n"
          << "Should be 4!";
     std::string comp = "bust";
     for (int i = 0; i < 4; i++) {
          EXPECT_EQ(ret.get(i), comp[i]) << "Element at " << i
               << "differs";
     }
}

TEST(Commit2, replaceInvalid) {
     SuperString s("test");
     SuperString ret = s.replace(4, 2, "bu");
     EXPECT_EQ(ret.length(), 0) << "Length incorrect for replace()\n"
          << "Should be 0!";
}

// void push_back(char);
TEST(Commit2, pushBack) {
     SuperString s("test");
     s.push_back('!');
     EXPECT_EQ(s.length(), 5) << "Length incorrect for push_back(char)\n"
          << "Should be 5!";
     std::string comp = "test!";
     for (int i = 0; i < 4; i++) {
          EXPECT_EQ(s.get(i), comp[i]) << "Element at " << i
               << "differs";
     }
}

// void append(std::string);
TEST(Commit2, appendString) {
     SuperString s("test");
     s.append("ing!");
     EXPECT_EQ(s.length(), 8) << "Length incorrect for append(string)\n"
          << "Should be 8!";
     std::string comp = "testing!";
     for (int i = 0; i < 8; i++) {
          EXPECT_EQ(s.get(i), comp[i]) << "Element at " << i
               << "differs";
     }
}

// void append(std::string);
TEST(Commit2, appendSuperString) {
     SuperString s("test");
     s.append(s);
     EXPECT_EQ(s.length(), 8) << "Length incorrect for append(SuperString)\n"
          << "Should be 8!";
     std::string comp = "testtest";
     for (int i = 0; i < 8; i++) {
          EXPECT_EQ(s.get(i), comp[i]) << "Element at " << i
               << "differs";
     }
}

// void replace(char, char);
TEST(Commit2, replace) {
     SuperString s("test");
     s.replace('t', 'r');
     EXPECT_EQ(s.length(), 4) << "Length incorrect for replace(char,char)\n"
          << "Should be 4!";
     std::string comp = "resr";
     for (int i = 0; i < 4; i++) {
          EXPECT_EQ(s.get(i), comp[i]) << "Element at " << i
               << "differs";
     }
}

int main(int argc, char** argv) {
     ::testing::InitGoogleTest(&argc, argv);
     return RUN_ALL_TESTS();
}

// DO NOT MODIFY END
