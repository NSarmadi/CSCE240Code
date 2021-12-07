// Copyright 2021 Coleca24
#include <gtest/gtest.h>
#include <iostream>
#include "./login.h"

// DO NOT MODIFY THIS FILE

TEST(Commit1, readUsersOpensCorrectFile) {
     std::string data[ROWS][COLS];
     EXPECT_EQ(readUsers("test/user_info.csv", data), true);
}

TEST(Commit1, readUsersFailsWithIncorrect) {
     std::string data[ROWS][COLS];
     EXPECT_EQ(readUsers("test/user_info1.csv", data), false);
}

TEST(Commit1, readUsersCorrectContent) {
     std::string data_real[ROWS][COLS] = {
          {"Earl Jones", "EarlJones@email.com", "7Rfkqyuq", "Manager"},
          {"Kandy McGill", "KandyMcGill@email.com", "bYeP82i6", "Engineer"},
          {"Hank Stark", "HankStark@email.com", "t277Bqyi", "Manager"},
          {"Bob Baker", "BobBaker@email.com", "yidHvr81", "Engineer"},
          {"Tariq Thompson", "TariqThompson@email.com", "hB23uiyu", "CEO"}};
     std::string data[ROWS][COLS];
     readUsers("test/user_info.csv", data);
     for (int i = 0; i < ROWS; i++) {
          for (int j = 0; j < COLS; j++) {
          EXPECT_EQ(data[i][j], data_real[i][j]) << "Arrays differ at index "
               << i << ", " << j << "\n";
          }
     }
}

TEST(Commit1, validateOptionCorrect) {
     EXPECT_EQ(validateOption('A'), true) << "Option A did not return true\n";
     EXPECT_EQ(validateOption('a'), true) << "Option a did not return true\n";
     EXPECT_EQ(validateOption('P'), true) << "Option P did not return true\n";
     EXPECT_EQ(validateOption('p'), true) << "Option p did not return true\n";
     EXPECT_EQ(validateOption('S'), true) << "Option S did not return true\n";
     EXPECT_EQ(validateOption('s'), true) << "Option s did not return true\n";
     EXPECT_EQ(validateOption('F'), true) << "Option F did not return true\n";
     EXPECT_EQ(validateOption('f'), true) << "Option f did not return true\n";
     EXPECT_EQ(validateOption('D'), true) << "Option D did not return true\n";
     EXPECT_EQ(validateOption('d'), true) << "Option d did not return true\n";
     EXPECT_EQ(validateOption('E'), true) << "Option E did not return true\n";
     EXPECT_EQ(validateOption('e'), true) << "Option e did not return true\n";
     EXPECT_EQ(validateOption('Q'), false) << "Invalid option did not return "
                                          << "false\n";
}

TEST(Commit1, searchForUserFoundCorrectIndex) {
     std::string data_real[ROWS][COLS] = {
          {"Earl Jones", "EarlJones@email.com", "7Rfkqyuq", "Manager"},
          {"Kandy McGill", "KandyMcGill@email.com", "bYeP82i6", "Engineer"},
          {"Hank Stark", "HankStark@email.com", "t277Bqyi", "Manager"},
          {"Bob Baker", "BobBaker@email.com", "yidHvr81", "Engineer"},
          {"Tariq Thompson", "TariqThompson@email.com", "hB23uiyu", "CEO"}};
     EXPECT_EQ(searchForUser("Earl Jones", data_real), 0) << "Earl Jones "
                                             << "should be at index 0\n";
     EXPECT_EQ(searchForUser("Kandy McGill", data_real), 1) << "Kandy McGill "
                                             << "should be at index 1\n";
     EXPECT_EQ(searchForUser("Hank Stark", data_real), 2) << "Hank Stark "
                                             << "should be at index 2\n";
     EXPECT_EQ(searchForUser("Bob Baker", data_real), 3) << "Bob Baker "
                                             << "should be at index 3\n";
     EXPECT_EQ(searchForUser("Tariq Thompson", data_real), 4) << "Tariq "
                                        << "Thompson should be at index 4\n";
}

TEST(Commit1, searchForUserNotFoundCorrect) {
     std::string data_real[ROWS][COLS] = {
          {"Earl Jones", "EarlJones@email.com", "7Rfkqyuq", "Manager"},
          {"Kandy McGill", "KandyMcGill@email.com", "bYeP82i6", "Engineer"},
          {"Hank Stark", "HankStark@email.com", "t277Bqyi", "Manager"},
          {"Bob Baker", "BobBaker@email.com", "yidHvr81", "Engineer"},
          {"Tariq Thompson", "TariqThompson@email.com", "hB23uiyu", "CEO"}};
     EXPECT_EQ(searchForUser("Casey Cole", data_real), -1) << "Invalid name "
                                                  << "should return -1\n";
}

TEST(Commit2, findAllUsersCorrectExists) {
     std::string data_real[ROWS][COLS] = {
          {"Earl Jones", "EarlJones@email.com", "7Rfkqyuq", "Manager"},
          {"Kandy McGill", "KandyMcGill@email.com", "bYeP82i6", "Engineer"},
          {"Hank Stark", "HankStark@email.com", "t277Bqyi", "Manager"},
          {"Bob Baker", "BobBaker@email.com", "yidHvr81", "Engineer"},
          {"Tariq Thompson", "TariqThompson@email.com", "hB23uiyu", "CEO"}};
     EXPECT_EQ(findAllUsers("CEO", data_real), 1) << "CEO should return 1\n";
     EXPECT_EQ(findAllUsers("Manager", data_real), 2) << "Manager should "
                                                      << "return 2\n";
     EXPECT_EQ(findAllUsers("Engineer", data_real), 2) << "Engineer should "
                                                       << "return 2\n";
}

TEST(Commit2, findAllUsersCorrectNotExist) {
     std::string data_real[ROWS][COLS] = {
          {"Earl Jones", "EarlJones@email.com", "7Rfkqyuq", "Manager"},
          {"Kandy McGill", "KandyMcGill@email.com", "bYeP82i6", "Engineer"},
          {"Hank Stark", "HankStark@email.com", "t277Bqyi", "Manager"},
          {"Bob Baker", "BobBaker@email.com", "yidHvr81", "Engineer"},
          {"Tariq Thompson", "TariqThompson@email.com", "hB23uiyu", "CEO"}};
     EXPECT_EQ(findAllUsers("Frog", data_real), 0) << "Frog should return 0\n";
}

TEST(Commit2, deleteUserReturnCorrectReturn) {
     std::string data_real[ROWS][COLS] = {
          {"Earl Jones", "EarlJones@email.com", "7Rfkqyuq", "Manager"},
          {"Kandy McGill", "KandyMcGill@email.com", "bYeP82i6", "Engineer"},
          {"Hank Stark", "HankStark@email.com", "t277Bqyi", "Manager"},
          {"Bob Baker", "BobBaker@email.com", "yidHvr81", "Engineer"},
          {"Tariq Thompson", "TariqThompson@email.com", "hB23uiyu", "CEO"}};
     std::string file = "test/user_info_delete1.csv";
     EXPECT_EQ(deleteUser("Earl Jones", data_real, file), true)
          << "deleteUsers should return true when user found and deleted.\n";
     EXPECT_EQ(deleteUser("Bob Jones", data_real, file), false)
          << "deleteUsers should return true when user found and deleted.\n";
}

TEST(Commit2, deleteUserArrayCorrect) {
     std::string data[ROWS][COLS] = {
          {"Earl Jones", "EarlJones@email.com", "7Rfkqyuq", "Manager"},
          {"Kandy McGill", "KandyMcGill@email.com", "bYeP82i6", "Engineer"},
          {"Hank Stark", "HankStark@email.com", "t277Bqyi", "Manager"},
          {"Bob Baker", "BobBaker@email.com", "yidHvr81", "Engineer"},
          {"Tariq Thompson", "TariqThompson@email.com", "hB23uiyu", "CEO"}};
     std::string data_real[ROWS][COLS] = {
          {"Earl Jones", "EarlJones@email.com", "7Rfkqyuq", "Manager"},
          {"Kandy McGill", "KandyMcGill@email.com", "bYeP82i6", "Engineer"},
          {"NULL", "NULL", "NULL", "NULL"},
          {"Bob Baker", "BobBaker@email.com", "yidHvr81", "Engineer"},
          {"Tariq Thompson", "TariqThompson@email.com", "hB23uiyu", "CEO"}};
     deleteUser("Hank Stark", data, "test/user_info_delete2.csv");
     for (int i = 0; i < ROWS; i++) {
          for (int j = 0; j < COLS; j++) {
          EXPECT_EQ(data[i][j], data_real[i][j]) << "Arrays differ at index "
               << i << ", " << j << " after deleting Hank Stark (row 2)\n";
          }
     }
}

TEST(Commit2, deleteUserFileCorrect) {
     std::string data[ROWS][COLS] = {
          {"Earl Jones", "EarlJones@email.com", "7Rfkqyuq", "Manager"},
          {"Kandy McGill", "KandyMcGill@email.com", "bYeP82i6", "Engineer"},
          {"Hank Stark", "HankStark@email.com", "t277Bqyi", "Manager"},
          {"Bob Baker", "BobBaker@email.com", "yidHvr81", "Engineer"},
          {"Tariq Thompson", "TariqThompson@email.com", "hB23uiyu", "CEO"}};
     deleteUser("Hank Stark", data, "test/user_info_delete3.csv");
     std::string data_real[ROWS][COLS];
     std::ifstream in("test/user_info_delete3.csv");
     std::string line, elem;
     int i = 0;
     if (in.is_open()) {
          while (getline(in, line)) {
               std::stringstream s(line);
               int j = 0;
               while (getline(s, elem, ',')) {
                    data_real[i][j] = elem;
                    j++;
               }
               i++;
          }
          in.close();
     }
     for (int i = 0; i < ROWS; i++) {
          for (int j = 0; j < COLS; j++) {
          EXPECT_EQ(data[i][j], data_real[i][j]) << "File differ at index "
               << i << ", " << j << " after deleting Hank Stark (row 2)\n";
          }
     }
}

bool hasNum(string test) {
     for (int i = 0; i < test.length(); i++) {
          if (test[i] >=48 && test[i] <=57) return true;
     }
     return false;
}

bool hasUpper(string test) {
     for (int i = 0; i < test.length(); i++) {
          if (test[i] >=65 && test[i] <=90) return true;
     }
     return false;
}

TEST(Commit2, generatePasswordCorrect) {
     std::string password = generatePassword();
     EXPECT_EQ(password.length(), 8) << "Password not 8 chars\n";
     EXPECT_EQ(hasNum(password), true)
                         << "Password does not have a number";
     EXPECT_EQ(hasUpper(password), true)
                         << "Password does not have an upper case char";
}

TEST(Commit2, generateEmailCorrect) {
     EXPECT_EQ(generateEmail("George Hank"), "GeorgeHank@email.com")
               << "Email for George Hank should be GeorgeHank@email.com\n";
}

TEST(Commit2, checkEmptyCorrectIndexFound) {
     std::string data[ROWS][COLS] = {
          {"NULL", "NULL", "NULL", "NULL"},
          {"Kandy McGill", "KandyMcGill@email.com", "bYeP82i6", "Engineer"},
          {"Hank Stark", "HankStark@email.com", "t277Bqyi", "Manager"},
          {"Bob Baker", "BobBaker@email.com", "yidHvr81", "Engineer"},
          {"Tariq Thompson", "TariqThompson@email.com", "hB23uiyu", "CEO"}};
     EXPECT_EQ(checkEmpty(data), 0)
     << "Empty spot was at index 0 - see test checkEmptyCorrectIndexFound\n";
}

TEST(Commit2, checkEmptyCorrectIndexNotFound) {
     std::string data[ROWS][COLS] = {
          {"Earl Jones", "EarlJones@email.com", "7Rfkqyuq", "Manager"},
          {"Kandy McGill", "KandyMcGill@email.com", "bYeP82i6", "Engineer"},
          {"Hank Stark", "HankStark@email.com", "t277Bqyi", "Manager"},
          {"Bob Baker", "BobBaker@email.com", "yidHvr81", "Engineer"},
          {"Tariq Thompson", "TariqThompson@email.com", "hB23uiyu", "CEO"}};
     EXPECT_EQ(checkEmpty(data), -1)
               << "No empty space, checkEmpty() should return -1\n";
}

TEST(Commit2, addUserReturnArrayCorrect) {
     std::string data[ROWS][COLS] = {
          {"Earl Jones", "EarlJones@email.com", "7Rfkqyuq", "Manager"},
          {"NULL", "NULL", "NULL", "NULL"},
          {"Hank Stark", "HankStark@email.com", "t277Bqyi", "Manager"},
          {"Bob Baker", "BobBaker@email.com", "yidHvr81", "Engineer"},
          {"Tariq Thompson", "TariqThompson@email.com", "hB23uiyu", "CEO"}};
     std::string data_real[ROWS][COLS] = {
          {"Earl Jones", "EarlJones@email.com", "7Rfkqyuq", "Manager"},
          {"Casey Cole", "CaseyCole@email.com", "test", "Manager"},
          {"Hank Stark", "HankStark@email.com", "t277Bqyi", "Manager"},
          {"Bob Baker", "BobBaker@email.com", "yidHvr81", "Engineer"},
          {"Tariq Thompson", "TariqThompson@email.com", "hB23uiyu", "CEO"}};
     std::string file = "test/user_info_add1.csv";
     addUser(1, "Casey Cole", "Manager", data, file);
     for (int i = 0; i < ROWS; i++) {
          for (int j = 0; j < COLS; j++) {
               if (j != 2) {
                    EXPECT_EQ(data[i][j], data_real[i][j]) <<
                    "Arrays differ at index " << i << ", " << j
                    << " after inserting Casey Cole "
                    << "(row 1)\n";
               } else {
                    EXPECT_NE(data[i][j], "NULL");
               }
          }
     }
}


TEST(Commit2, addUserFileCorrect) {
     std::string data[ROWS][COLS] = {
          {"Earl Jones", "EarlJones@email.com", "7Rfkqyuq", "Manager"},
          {"NULL", "NULL", "NULL", "NULL"},
          {"Hank Stark", "HankStark@email.com", "t277Bqyi", "Manager"},
          {"Bob Baker", "BobBaker@email.com", "yidHvr81", "Engineer"},
          {"Tariq Thompson", "TariqThompson@email.com", "hB23uiyu", "CEO"}};
     addUser(1, "Casey Cole", "Manager", data, "test/user_info_add2.csv");
     std::string data_real[ROWS][COLS];
     std::ifstream in("test/user_info_add2.csv");
     std::string line, elem;
     int i = 0;
     if (in.is_open()) {
          while (getline(in, line)) {
               std::stringstream s(line);
               int j = 0;
               while (getline(s, elem, ',')) {
                    data_real[i][j] = elem;
                    j++;
               }
               i++;
          }
          in.close();
     }
     for (int i = 0; i < ROWS; i++) {
          for (int j = 0; j < COLS; j++) {
          EXPECT_EQ(data[i][j], data_real[i][j]) << "File differ at index "
               << i << ", " << j << " after deleting Hank Stark (row 2)\n";
          }
     }
}

void init(string[ROWS][COLS]);

int main(int argc, char** argv) {
     std::string data[ROWS][COLS];
     init(data);
     std::string fn = "./data/user_info.csv";
     bool success = readUsers(fn, data);
     printUsers(data);
     if (success) {
          char option;
          do {
               option = displayOptions();
               executeOption(option, data, fn);
          } while (option != 'e' && option != 'E');
     } else {
          std::cout << "Could not open file\n";
     }
     ::testing::InitGoogleTest(&argc, argv);
     return RUN_ALL_TESTS();
}

void init(string data[ROWS][COLS]) {
     for (int i = 0; i < ROWS; i++) {
          for (int j = 0; j < COLS; j++) {
               data[i][j] = "NULL";
          }
     }
}

// DO NOT MODIFY END
