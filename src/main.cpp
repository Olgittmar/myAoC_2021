#include <iostream>
#include <fstream>
#include <filesystem>

#include "MyAoC_2021/solutions/1/part_1.h"
#include "MyAoC_2021/solutions/1/part_2.h"
#include "MyAoC_2021/solutions/2/part_1.h"
#include "MyAoC_2021/solutions/2/part_2.h"
#include "MyAoC_2021/solutions/3/part_1.h"
#include "MyAoC_2021/solutions/3/part_2.h"
#include "MyAoC_2021/solutions/4/part_1.h"
#include "MyAoC_2021/solutions/4/part_2.h"
#include "MyAoC_2021/solutions/5/part_1.h"
#include "MyAoC_2021/solutions/5/part_2.h"
#include "MyAoC_2021/solutions/6/part_1.h"
#include "MyAoC_2021/solutions/6/part_2.h"
#include "MyAoC_2021/solutions/7/part_1.h"
#include "MyAoC_2021/solutions/7/part_2.h"
#include "MyAoC_2021/solutions/8/part_1.h"
#include "MyAoC_2021/solutions/8/part_2.h"
#include "MyAoC_2021/solutions/9/part_1.h"
#include "MyAoC_2021/solutions/9/part_2.h"
#include "MyAoC_2021/solutions/10/part_1.h"
#include "MyAoC_2021/solutions/10/part_2.h"

// ---------------------------------------------------------------------------
// Main utils
// ---------------------------------------------------------------------------
constexpr const char* dataFolder = "data";
constexpr const char* projectRootFolder = "myAoC_2021";

std::filesystem::path
GenerateDataPath(const int& day, const int& problem) {
    auto cwd = std::filesystem::current_path();
    std::filesystem::path rootPath = cwd;

    while( rootPath != cwd.root_path()
        && rootPath.has_parent_path()
        && rootPath.stem() != projectRootFolder )
    {
        rootPath = rootPath.parent_path();
    }

    auto dataPath = rootPath /
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
        return std::string{};
    }
    return std::string{
        (std::istreambuf_iterator<char>(ifStrm)),
        (std::istreambuf_iterator<char>()) };
}
// ---------------------------------------------------------------------------

int main(/*int argc, char** argv*/){

    std::cout << "\nDay 1, problem 1: " << std::endl;
    std::cout << solutions::CountNumIncreasing( GetInputData(1, 1) ) << std::endl; // NOLINT

    std::cout << "\nDay 1, problem 2:" << std::endl;
    std::cout << solutions::CountIncreasingSlidingWindow( GetInputData(1, 1) ) << std::endl; // NOLINT

    std::cout << "\nDay 2, problem 1:" << std::endl;
    std::cout << solutions::SubmarineNavigationProduct( GetInputData(2, 1) ) << std::endl; // NOLINT

    std::cout << "\nDay 2, problem 2:" << std::endl;
    std::cout << solutions::SubmarineAdvancedNavigationProduct( GetInputData(2, 1) ) << std::endl; // NOLINT

    std::cout << "\nDay 3, problem 1:" << std::endl;
    std::cout << solutions::SubmarinePowerConsumption( GetInputData(3, 1) ) << std::endl; // NOLINT

    std::cout << "\nDay 3, problem 2:" << std::endl;
    std::cout << solutions::SubmarineLifeSupportRating( GetInputData(3, 1) ) << std::endl; // NOLINT

    std::cout << "\nDay 4, problem 1:" << std::endl;
    std::cout << solutions::WinBingo( GetInputData(4, 1) ) << std::endl; // NOLINT

    std::cout << "\nDay 4, problem 2:" << std::endl;
    std::cout << solutions::LoseBingo( GetInputData(4, 1) ) << std::endl; // NOLINT

    std::cout << "\nDay 5, problem 1:" << std::endl;
    std::cout << solutions::NumberOfOverlappingVentlinePoints( GetInputData(5, 1) ) << std::endl; // NOLINT

    std::cout << "\nDay 5, problem 2:" << std::endl;
    std::cout << solutions::NumberOfOverlappingVentlinePointsIncludingDiagonals( GetInputData(5, 1) ) << std::endl; // NOLINT

    std::cout << "\nDay 6, problem 1:" << std::endl;
    std::cout << solutions::CalculateNumberOfLanternFishAfterNDays( GetInputData(6, 1), 80 ) << std::endl; // NOLINT

    std::cout << "\nDay 6, problem 2:" << std::endl;
    std::cout << solutions::CalculateMassiveNumberOfLanternFishAfterNDays( GetInputData(6, 1), 256 ) << std::endl; // NOLINT

    std::cout << "\nDay 7, problem 1:" << std::endl;
    std::cout << solutions::CalculateAlignmentOptimalFuelConsumption( GetInputData(7, 1) ) << std::endl; // NOLINT

    std::cout << "\nDay 7, problem 2:" << std::endl;
    std::cout << solutions::CalculateExpensiveAlignmentOptimalFuelConsumption( GetInputData(7, 1) ) << std::endl; // NOLINT

    std::cout << "\nDay 8, problem 1:" << std::endl;
    std::cout << solutions::GetNumberOfCodesOfUniqueLengthInOutput( GetInputData(8, 1) ) << std::endl; // NOLINT

    std::cout << "\nDay 8, problem 2:" << std::endl;
    std::cout << solutions::SumOfJumbledCodes( GetInputData(8, 1) ) << std::endl; // NOLINT

	std::cout << "\nDay 9, problem 1:" << std::endl;
    std::cout << solutions::SumRiskLevelOfLowPoints( GetInputData(9, 1) ) << std::endl; // NOLINT

	std::cout << "\nDay 9, problem 2:" << std::endl;
    std::cout << solutions::ProductOfLargestBasinSizes( GetInputData(9, 1), 3 ) << std::endl; // NOLINT
	
	std::cout << "\nDay 10, problem 1:" << std::endl;
    std::cout << solutions::SyntaxErrorScoreCorrupted( GetInputData(10, 1) ) << std::endl; // NOLINT
	
	std::cout << "\nDay 10, problem 2:" << std::endl;
    std::cout << solutions::MiddleCompletedScore( GetInputData(10, 1) ) << std::endl; // NOLINT

    return 0;
}