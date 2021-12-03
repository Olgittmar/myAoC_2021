#include <iostream>
#include <fstream>
#include <filesystem>

#include "MyAoC_2021/solutions/Solution_1_1.h"
#include "MyAoC_2021/solutions/Solution_1_2.h"
#include "MyAoC_2021/solutions/Solution_2_1.h"

// ---------------------------------------------------------------------------
// Main utils
// ---------------------------------------------------------------------------
#define dataFolder "data"
#define projectRootFolder "myAoC_2021"

std::filesystem::path
GenerateDataPath(const int& day, const int& problem) {
    auto cwd = std::filesystem::current_path();
    std::filesystem::path rootPath = cwd;

    while( rootPath != cwd.root_path()
        && rootPath.has_parent_path()
        && rootPath.stem() != "myAoC_2021" )
    {
        rootPath = rootPath.parent_path();
    }

    const auto dataPath = rootPath /
        (std::string(dataFolder) + "/"
        + std::to_string(day) + "_"
        + std::to_string(problem));

    return dataPath;
}

std::string GetInputData(const int& day, const int& problem){
    auto dataPath = GenerateDataPath(day, problem);
    auto filename = (dataPath/"input.txt").string();

    std::cout << "Reading file: " << filename << std::endl;
    std::ifstream ifStrm(filename);
    if(!ifStrm.is_open()){
        std::cerr << "Failed to open " << filename << std::endl;
        return std::string();
    }
    return std::string(
        (std::istreambuf_iterator<char>(ifStrm)),
        (std::istreambuf_iterator<char>()) );
}
// ---------------------------------------------------------------------------

int main(int argc, char** argv){

    std::cout << "\nDay 1, problem 1: " << std::endl;
    std::cout << solutions::CountNumIncreasing( GetInputData(1, 1) ) << std::endl;

    std::cout << "\nDay 1, problem 2:" << std::endl;
    std::cout << solutions::CountIncreasingSlidingWindow( GetInputData(1, 2) ) << std::endl;
    
    std::cout << "\nDay 2, problem 1:" << std::endl;
    std::cout << solutions::SubmarineNavigationProduct( GetInputData(2, 1) ) << std::endl;

    return 0;
}