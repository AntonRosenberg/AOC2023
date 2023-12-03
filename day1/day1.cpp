#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <cstring>
#include <vector>

std::size_t find_number_sum(std::string& string)
{
    std::string sum = "";
    std::string firstNum;
    std::string lastNum;
    std::vector<std::string> textNums = {"one","two","three","four","five","six","seven","eight","nine"};
    auto minDist = (std::size_t)std::distance(string.begin(), string.end()); 
    for (int i = 0; i<textNums.size(); i++)
    {
        auto elem = textNums[i];
        auto indFirstLetNum = string.find(elem);
        if (indFirstLetNum != string.npos && indFirstLetNum < minDist)
        {
            minDist = indFirstLetNum;
            firstNum = std::to_string(i+1);
        }    
    }
    std::size_t indFirstNumber = string.find_first_of("0123456789");
    if (indFirstNumber < minDist)
    {
        firstNum = string[indFirstNumber];
    }
    minDist = (std::size_t)std::distance(string.begin(), string.end()); 
    sum.append(firstNum);

    std::reverse(string.begin(), string.end());
    for (int i = 0; i<textNums.size(); i++)
    {
        auto elem = textNums[i];
        std::reverse(elem.begin(), elem.end());
        auto indFirstLetNum = string.find(elem);
        if (indFirstLetNum != string.npos && indFirstLetNum < minDist)
        {
            minDist = indFirstLetNum;
            lastNum = std::to_string(i+1);
        }    
    }
    std::size_t indLastNum = string.find_first_of("0123456789");
    if (indLastNum < minDist)
    {
        lastNum = string[indLastNum];
    }
    sum.append(lastNum);
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