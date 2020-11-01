// Copyright [2020] <Lev Semkov>
// Created by levs503 on 29.10.2020.
//
#include <boost/filesystem.hpp>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <unordered_set>

#include "Account.h"
#include "header.hpp"

namespace fs = boost::filesystem;

int main(int argc, char* argv[]) {
  std::unordered_map<std::string, std::unordered_set<std::string>>
      array_number_of_account;                      // broker->set<number>
  std::map<std::string, Account> array_of_account;  // number->Account
  const fs::path first_path = argc >= 2 ? argv[1] : fs::current_path();

  if (fs::exists(first_path)) {
    if (fs::is_directory(first_path))
      read_directory(first_path, array_number_of_account, array_of_account,
                     "unknown");
  } else {
    throw std::invalid_argument("wrong path");
  }
  for (auto& g : array_number_of_account) {
    for (const auto& h : g.second) {
      std::cout << array_of_account[h];
    }
  }
  return 1;
}
