// Copyright 2021 Coleca24
#include <gtest/gtest.h>
#include <iostream>
#include "./ArrayList.cpp"

// DO NOT MODIFY THIS FILE

// Testing bool operator!=(const ArrayList<T> &) const;
TEST(Project3, test_operator_notEqual) {
     ArrayList<int> a(2,1), b(3,1);
     bool test = (a != a); 
     EXPECT_EQ(test, false) << "Objects are the same! \n" 
     << "Object 1: " << a << " Object 2: " << a 
     << "Should return false\n";
     
     test = (a != b); 
     EXPECT_EQ(test, true) << "Objects are not the same! \n" 
     << "Object 1: " << a << " Object 2: " << b 
     << "Should return true\n";
}

// Testing ArrayList<T> operator+(T) const;
TEST(Project3, test_operator_addT) {
	 ArrayList<int> c(2,1), c_ret; 
	 c_ret = c + 1;
	 std::cout << "Test: c_ret = c + 1 where c_ret = [] and c = [1,1]\n";
     EXPECT_EQ(c_ret.getSize(), 2) << "c_ret incorrect length"; 
     EXPECT_EQ(c.getSize(), 2) << "c incorrect length"; 
     for (int i = 0; i < 2; i++) {
          EXPECT_EQ(c_ret[i], 2) << "Element in c_ret at " << i
               << " differs (should be 2)";
     }
}

// Testing ArrayList<T> operator+(const ArrayList<T> &) const;
TEST(Project3, test_operator_addArrayList) {
	 ArrayList<int> c(2,1), c2(2,2), c_ret; 
	 c_ret = c + c2;
	 std::cout << "Test: c_ret = c + c2 where c_ret = [] and c = [1,1] and c2 = [2,2]\n";
     EXPECT_EQ(c_ret.getSize(), 2) << "c_ret incorrect length"; 
     EXPECT_EQ(c.getSize(), 2) << "c incorrect length"; 
     EXPECT_EQ(c2.getSize(), 2) << "c2 incorrect length"; 
     for (int i = 0; i < 2; i++) {
          EXPECT_EQ(c_ret[i], 3) << "Element in c_ret at " << i
               << " differs (should be 3)";
     }
}
  
// Testing ArrayList<T> & operator--(); 
TEST(Project3, test_operator_pre) {
	 ArrayList<int> c(2,1), c_ret; 
	 c_ret = --c;
	 std::cout << "Test: c_ret = --c where c_ret = [] and c = [1,1]\n";
     EXPECT_EQ(c_ret.getSize(), 1) << "c_ret incorrect length"; 
     EXPECT_EQ(c.getSize(), 1) << "c incorrect length"; 
     for (int i = 0; i < 1; i++) {
          EXPECT_EQ(c_ret[i], 1) << "Element in c_ret at " << i
               << " differs (should be 1)";
          EXPECT_EQ(c[i], 1) << "Element in c at " << i
               << " differs (should be 1)";
     }
}

// Testing ArrayList<T> operator--(int);
TEST(Project3, test_operator_post) {
	 ArrayList<int> c(2,1), c_ret; 
	 c_ret = c--;
	 std::cout << "Test: c_ret = c-- where c_ret = [] and c = [1,1]\n";
     EXPECT_EQ(c_ret.getSize(), 2) << "c_ret incorrect length"; 
     EXPECT_EQ(c.getSize(), 1) << "c incorrect length"; 
     for (int i = 0; i < 2; i++) {
          EXPECT_EQ(c_ret[i], 1) << "Element in c_ret at " << i
               << " differs (should be 1)";
     }
     for (int i = 0; i < 1; i++) {
          EXPECT_EQ(c[i], 1) << "Element in c at " << i
               << " differs (should be 1)";
     }
}
  
// Testing void operator+=(T);
TEST(Project3, test_operator_plusEqualT) {
ArrayList<int> c(2,1); 
c += 1;
std::cout << "Test: c = [1,1] += 1\n";
     EXPECT_EQ(c.getSize(), 3) << "c incorrect length"; 
     for (int i = 0; i < 3; i++) {
          EXPECT_EQ(c[i], 1) << "Element in c at " << i
               << " differs (should be 1)";
     }
}

// Testing void operator+=(const ArrayList<T> &);
TEST(Project3, test_operator_plusEqualArrayList) {
ArrayList<int> c(2,1), c2(2,2); 
c += c2;
std::cout << "Test: c += c2 where c = [1,1] and c2 = [2,2]\n";
     EXPECT_EQ(c.getSize(), 4) << "c incorrect length"; 
     EXPECT_EQ(c2.getSize(), 2) << "c2 incorrect length"; 
     for (int i = 0; i < 4; i++) {
 if ( i <= 1 ) {
          EXPECT_EQ(c[i], 1) << "Element in c at " << i
               << " differs (should be 1)";
 } else {
 EXPECT_EQ(c[i], 2) << "Element in c at " << i
               << " differs (should be 2)";
 }
     }
     for (int i = 0; i < 2; i++) {
          EXPECT_EQ(c2[i], 2) << "Element in c2 at " << i
               << " differs (should be 2)";
     }
}

  
// Testing ArrayList<T> operator*(int) const; 
TEST(Project3, test_operator_times) {
	 ArrayList<int> c(2,1), c_ret; 
	 c_ret = c*2;
	 std::cout << "Test: c_ret = c * 2 where c_ret = [] and c = [1,1]\n";
     EXPECT_EQ(c_ret.getSize(), 4) << "c_ret incorrect length"; 
     EXPECT_EQ(c.getSize(), 2) << "c incorrect length"; 
     
     for (int i = 0; i < 4; i++) {
          EXPECT_EQ(c_ret[i], 1) << "Element in c_ret at " << i
               << " differs (should be 1)";
     }
     for (int i = 0; i < 2; i++) {
          EXPECT_EQ(c[i], 1) << "Element in c at " << i
               << " differs (should be 1)";
     }
}

// Testing ArrayList<T> operator/(int) const;
TEST(Project3, test_operator_divide) {
	 ArrayList<int> c(5,1), c_ret; 
	 c_ret = c/2;
	 std::cout << "Test: c_ret = c * 2 where c_ret = [] and c = [1,1,1,1,1]\n";
     EXPECT_EQ(c_ret.getSize(), 2) << "c_ret incorrect length"; 
     EXPECT_EQ(c.getSize(), 5) << "c incorrect length"; 
     
     for (int i = 0; i < 2; i++) {
          EXPECT_EQ(c_ret[i], 1) << "Element in c_ret at " << i
               << " differs (should be 1)";
     }
     for (int i = 0; i < 5; i++) {
          EXPECT_EQ(c[i], 1) << "Element in c at " << i
               << " differs (should be 1)";
     }
}

int main(int argc, char** argv) {
     ::testing::InitGoogleTest(&argc, argv);
     return RUN_ALL_TESTS();
}

// DO NOT MODIFY END
