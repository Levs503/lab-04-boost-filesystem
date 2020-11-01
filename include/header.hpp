// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_
#pragma once
#include <Account.h>
#include <unordered_map>
#include <boost/filesystem.hpp>
#include <unordered_set>
#include <map>
#include "Account.h"
#include "header.hpp"
#include <string>

namespace fs = boost::filesystem;

void file_analysis(
    const fs::path& file_name,
    std::unordered_map<std::string, std::unordered_set<std::string>>&
        array_number_of_account,
    std::map<std::string, Account>& array_of_account,
    const std::string& directory_name);

void read_directory(
    const fs::path& path,
    std::unordered_map<std::string, std::unordered_set<std::string>>&
        array_number_of_account,
    std::map<std::string, Account>& array_of_account,
    const std::string& directory_name);
#endif  // INCLUDE_HEADER_HPP_
