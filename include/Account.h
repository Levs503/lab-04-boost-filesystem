//
// Created by levs503 on 30.10.2020.
//

#ifndef LAB_04_BOOST_FILESYSTEM_ACCOUNT_H
#define LAB_04_BOOST_FILESYSTEM_ACCOUNT_H

#include <string>
class Account {
 public:
  std::string broker;
  std::string num_account;
  size_t amount_of_files;
  std::string lastDate;
  Account();
  bool operator==(const Account& oth) const;

};

#endif  // LAB_04_BOOST_FILESYSTEM_ACCOUNT_H
