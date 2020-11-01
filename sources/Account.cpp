//
// Created by levs503 on 30.10.2020.
//
#include "Account.h"

#include <iostream>
Account::Account() : broker(), num_account(), amount_of_files(0), lastDate() {}
bool Account::operator==(const Account& oth) const {
  return num_account == oth.num_account && broker == oth.broker;
}
std::ostream& Account::operator<<(std::ostream& out) {
  out << "broker:" << broker << " account:" << num_account
      << " files:" << amount_of_files << " last date:" << lastDate << std::endl;
  return out;
}
Account::Account(const std::string& a, const std::string& b, size_t c,
                 const std::string& d) {
  broker = a;
  num_account = b;
  amount_of_files = c;
  lastDate = d;
}

std::ostream& operator<<(std::ostream& out, const Account& oth) {
  out << "broker:" << oth.broker << " account:" << oth.num_account
      << " files:" << oth.amount_of_files << " last date:" << oth.lastDate
      << std::endl;
  return out;
}