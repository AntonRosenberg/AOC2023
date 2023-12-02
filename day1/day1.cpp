#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

std::size_t find_number_sum(std::string& string)
{
    std::vector<std::string> textNums = {"one","two","three","four","five","six","seven","eight","nine"};
    std::string sum;
    const char firstNum = string[string.find_first_of("0123456789")];
    sum.push_back(firstNum);
    std::reverse(string.begin(), string.end());
    const char lastNum = string[string.find_first_of("0123456789")];
    sum.push_back(lastNum);

    return std::stoi(sum);
}

int main(int argc, char *argv[])
{
    std::fstream new_file;
    new_file.open("input-1.txt", std::ios::in); 

    std::string tmp_line;
    std::vector<std::string> lines;
    if (new_file.is_open()) { 
        while (std::getline(new_file, tmp_line))
        {
            lines.push_back(tmp_line);
        }
        new_file.close(); 
    }
    size_t calibration = 0;
    for (auto& line : lines)
    {
        calibration += find_number_sum(line);
    }
    std::cout<<"Calibration is: "<<calibration<<std::endl;
    
    return 0;
}