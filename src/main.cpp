#include <filesystem>
#include <fstream>
#include <iostream>

#include <solutions/1/day_1_part_1.h>
#include <solutions/1/day_1_part_2.h>
#include <solutions/10/day_10_part_1.h>
#include <solutions/10/day_10_part_2.h>
#include <solutions/11/day_11_part_1.h>
#include <solutions/11/day_11_part_2.h>
#include <solutions/12/day_12_part_1.h>
#include <solutions/12/day_12_part_2.h>
#include <solutions/13/day_13_part_1.h>
#include <solutions/13/day_13_part_2.h>
#include <solutions/2/day_2_part_1.h>
#include <solutions/2/day_2_part_2.h>
#include <solutions/3/day_3_part_1.h>
#include <solutions/3/day_3_part_2.h>
#include <solutions/4/day_4_part_1.h>
#include <solutions/4/day_4_part_2.h>
#include <solutions/5/day_5_part_1.h>
#include <solutions/5/day_5_part_2.h>
#include <solutions/6/day_6_part_1.h>
#include <solutions/6/day_6_part_2.h>
#include <solutions/7/day_7_part_1.h>
#include <solutions/7/day_7_part_2.h>
#include <solutions/8/day_8_part_1.h>
#include <solutions/8/day_8_part_2.h>
#include <solutions/9/day_9_part_1.h>
#include <solutions/9/day_9_part_2.h>

// ---------------------------------------------------------------------------
// Main utils
// ---------------------------------------------------------------------------
constexpr const char* dataFolder = "data";
constexpr const char* projectRootFolder = "myAoC_2021";

auto
GenerateDataPath(const int& day, const int& problem) -> std::filesystem::path {
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

auto GetInputData(const int& day, const int& problem) -> std::string{
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

auto main(/*int argc, char** argv*/) -> int{

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
	
	std::cout << "\nDay 11, problem 1:" << std::endl;
    std::cout << solutions::CountDumboFlashes( GetInputData(11, 1), 100 ) << std::endl; // NOLINT

	std::cout << "\nDay 11, problem 2:" << std::endl;
    std::cout << solutions::PredictSynchronizedFlash( GetInputData(11, 1), 1000 ) << std::endl; // NOLINT

	std::cout << "\nDay 12, problem 1:" << std::endl;
    std::cout << solutions::FindNumCavePaths( GetInputData(12, 1) ) << std::endl; // NOLINT
	
	std::cout << "\nDay 12, problem 2:" << std::endl;
    std::cout << solutions::FindNumCavePathsWithExtraVisit( GetInputData(12, 1) ) << std::endl; // NOLINT

	std::cout << "\nDay 13, problem 1:" << std::endl;
    std::cout << solutions::DotsVisibleAfterNFolds( GetInputData(13, 1), 1 ) << std::endl; // NOLINT

	std::cout << "\nDay 13, problem 2:" << std::endl;
    std::cout << solutions::PrintCodeFromDottedPaper( GetInputData(13, 1), 0 ) << std::endl; // NOLINT

    return 0;
}