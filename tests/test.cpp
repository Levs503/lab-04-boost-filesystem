// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include "Account.h"
#include <boost/filesystem.hpp>
#include <unordered_set>
#include "header.hpp"
#include <sstream>
namespace fs = boost::filesystem;


TEST(Example, EmptyTest) {
  std::unordered_map<std::string, std::unordered_set<std::string>> array_number_of_account;//broker->set<number>
  std::map<std::string, Account> array_of_account; // number->Account
  const fs::path path1 = "balance_12001234_20292231.txt";
  file_analysis(path1, array_number_of_account, array_of_account, "base");
  EXPECT_EQ(*(array_number_of_account["base"].begin()), "12001234");
  std::ostringstream out;
  std::string a = "broker:base account:12001234 files:1 last date:20292231\n";
  out<<array_of_account[*(array_number_of_account["base"].begin())];
  EXPECT_EQ(out.str(), a);
  std::ostringstream out2;
  file_analysis(path1, array_number_of_account, array_of_account, "base");
  std::string b = "broker:base account:12001234 files:2 last date:20292231\n";
  out2<<array_of_account[*(array_number_of_account["base"].begin())];
  EXPECT_EQ(out2.str(), b);
}

TEST(Account, ostream) {
  std::ostringstream a;
  Account b("broker", "12345678",2, "12345678");
  std::string c = "broker:broker account:12345678 files:2 last date:12345678\n";
  a<<b;
  EXPECT_EQ(a.str(), c);
}