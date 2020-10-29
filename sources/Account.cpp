//
// Created by levs503 on 30.10.2020.
//

#include "Account.h"
Account::Account():broker(), num_account(), amount_of_files(0), lastDate() {}
bool Account::operator==(const Account& oth) const{
  return num_account == oth.num_account;
}
