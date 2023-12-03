#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <cstring>
#include <vector>
#include <boost/algorithm/string.hpp>

int main()
{
    std::fstream new_file;
    new_file.open("input.txt", std::ios::in); 
    std::vector<std::string> draws;
    std::string tmp_line;
    std::vector<std::string> games;
    if (new_file.is_open()) { 
        while (std::getline(new_file, tmp_line))
        {
            games.push_back(tmp_line);
        }
        new_file.close(); 
    }
    for (auto& str : games)
    {
        std::string draw;
        str.erase(0, str.find_first_of(":")+2);
        boost::split(draws, str, boost::is_any_of(";"));
        
    }
}