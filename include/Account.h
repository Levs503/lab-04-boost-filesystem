//
// Created by levs503 on 30.10.2020.
//

#ifndef LAB_04_BOOST_FILESYSTEM_ACCOUNT_H
#define LAB_04_BOOST_FILESYSTEM_ACCOUNT_H
#pragma once
#include <string>
class Account {
 public:
  Account(const std::string& a, const std::string& b, size_t c,
          const std::string& d);
  std::string broker;
  std::string num_account;
  size_t amount_of_files;
  std::string lastDate;
  Account();
  bool operator==(const Account& oth) const;
  std::ostream& operator<<(std::ostream& out);
};

std::ostream& operator<<(std::ostream& out, const Account& acc);

#endif  // LAB_04_BOOST_FILESYSTEM_ACCOUNT_H
