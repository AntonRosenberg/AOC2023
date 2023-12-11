#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <cstring>
#include <vector>
#include <boost/algorithm/string.hpp>

bool possible_game(std::string& draw, std::map<std::string, int>& colors)
{
    for (int i = 0; i < colors.size(); i++)
    {
        auto ind = draw.find("color");
        if (draw.find("color") != draw.npos)
        {
            
        }

    }


}

int main()
{
    std::map<std::string, int> colors{{"blue", 14}, {"red", 12}, {"green", 13}};
    std::fstream new_file;
    new_file.open("input.txt", std::ios::in);
    std::vector<std::string> draws;
    std::string tmp_line;
    std::vector<std::string> games;
    if (new_file.is_open()) 
    { 
        while (std::getline(new_file, tmp_line))
        {
            games.push_back(tmp_line);
        }
        new_file.close(); 
    }
    for (auto& str : games)
    {
        str.erase(0, str.find_first_of(":")+2);
        boost::split(draws, str, boost::is_any_of(";"));
        std::cout<<draws[0]<<std::endl;
        for (auto& draw : draws)
        {
            
        } 
    }
    return 0;
}