#include <iostream>
#include <fstream>
#include <filesystem>

#include "MyAoC_2021/Solution_1_1.h"

#define dataFolder "data"
#define dayNumber 1
#define problemNumber 1

std::filesystem::path
GenerateDataPath() {
    auto cwd = std::filesystem::current_path();
    std::filesystem::path rootPath = cwd;
    while( rootPath != cwd.root_path()
        && rootPath.has_parent_path()
        && rootPath.stem() != "myAoC_2021" )
    {
        std::cout << rootPath.string() << std::endl;
        rootPath = rootPath.parent_path();
    }
    std::cout << rootPath.string() << std::endl;
    const auto dataPath = rootPath /
        (std::string(dataFolder) + "/"
        + std::to_string(dayNumber) + "_"
        + std::to_string(problemNumber));
    return dataPath;
}

int main(int argc, char** argv){
    auto dataPath = GenerateDataPath();
    auto filename = (dataPath/"input.txt").string();

    std::ifstream ifStrm(filename);
    if(!ifStrm.is_open()){
        std::cerr << "Failed to open " << filename << std::endl;
        return 1;
    }
    std::string input(
        (std::istreambuf_iterator<char>(ifStrm)),
        (std::istreambuf_iterator<char>()) );

    std::cout << CountNumIncreasing( input );

    return 0;
}