//
// Created by levs503 on 02.11.2020.
//
#include "header.hpp"

#include <sstream>

#include "Account.h"
namespace fs = boost::filesystem;

bool isNumber(std::string& str) {
  for (auto& ch : str) {
    if (!std::isdigit(ch)) return false;
  }
  return true;
}

void file_analysis(
    const fs::path& file_name,
    std::unordered_map<std::string, std::unordered_set<std::string>>&
        array_number_of_account,
    std::map<std::string, Account>& array_of_account,
    const std::string& directory_name) {
  if (file_name.extension().string() == ".txt") {
    std::istringstream file(file_name.string());
    std::string balance;
    std::string number_of_account;
    std::string date;
    std::string txt;
    getline(file, balance, '_');
    getline(file, number_of_account, '_');
    getline(file, date, '.');
    file >> txt;
    if (txt == "txt" && balance == "balance" && isNumber(number_of_account) &&
        isNumber(date) && number_of_account.size() == 8 && date.size() == 8) {
      array_number_of_account[directory_name].insert(number_of_account);
      array_of_account[number_of_account].num_account = number_of_account;
      array_of_account[number_of_account].amount_of_files++;
      array_of_account[number_of_account].broker = directory_name;
      if (date > array_of_account[number_of_account].lastDate)
        array_of_account[number_of_account].lastDate = date;
    }
  }
}

void read_directory(
    const fs::path& path,
    std::unordered_map<std::string, std::unordered_set<std::string>>&
        array_number_of_account,
    std::map<std::string, Account>& array_of_account,
    const std::string& directory_name) {
  std::vector<fs::path> directories;
  for (fs::directory_entry& file : fs::directory_iterator(path)) {
    if (fs::is_regular_file(file.path())) {
      file_analysis(file.path().filename(), array_number_of_account,
                    array_of_account, directory_name);
    } else if (fs::is_directory(file.path()))
      directories.push_back(file.path());
    else if (fs::is_symlink(file.path()))
      directories.push_back(fs::read_symlink(file.path()));
  }
  for (const auto& x : directories) {
    read_directory(x, array_number_of_account, array_of_account,
                   x.stem().string());
  }
}