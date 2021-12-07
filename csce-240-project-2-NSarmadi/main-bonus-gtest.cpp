// Copyright 2021 Coleca24
#include <gtest/gtest.h>
#include <iostream>
#include "./SuperString.h"

// DO NOT MODIFY THIS FILE

// void removeAll(char);
TEST(Bonus, removeAll) {
     SuperString s("test");
     s.removeAll('t');
     EXPECT_EQ(s.length(), 2) << "Length incorrect for removeAll('t')\n"
          << "Should be 2!";
     std::string comp = "es";
     for (int i = 0; i < 2; i++) {
          EXPECT_EQ(s.get(i), comp[i]) << "Element at " << i
               << "differs";
     }
}

// void replace(std::string, std::string);
TEST(Bonus, replaceStrings) {
     SuperString s("that cat is a cool cat");
     s.replace("cat", "dog");
     EXPECT_EQ(s.length(), 22) << "Length incorrect for replace(string"
          << ", string)\nShould be 22!";
     std::string comp = "that dog is a cool dog";
     for (int i = 0; i < 22; i++) {
          EXPECT_EQ(s.get(i), comp[i]) << "Element at " << i
               << "differs";
     }
}

// bool isUpper();
TEST(Bonus, isUpper) {
     SuperString s("test");
     SuperString s2("TEST");
     EXPECT_EQ(s.isUpper(), false);
     EXPECT_EQ(s2.isUpper(), true);
}

// bool isLower();
TEST(Bonus, isLower) {
     SuperString s("test");
     SuperString s2("TEST");
     EXPECT_EQ(s.isLower(), true);
     EXPECT_EQ(s2.isLower(), false);
}

// bool isTitleCase();
TEST(Bonus, isTitleCase) {
     SuperString s("This Is Title Case");
     SuperString s2("This Is not Title Case");
     EXPECT_EQ(s.isTitleCase(), true);
     EXPECT_EQ(s2.isTitleCase(), false);
}

int main(int argc, char** argv) {
     ::testing::InitGoogleTest(&argc, argv);
     return RUN_ALL_TESTS();
}

// DO NOT MODIFY END
