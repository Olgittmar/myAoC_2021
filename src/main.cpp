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
#include <solutions/14/day_14_part_1.h>
// #include <solutions/14/day_14_part_2.h>
#include <solutions/15/day_15_part_1.h>
#include <solutions/15/day_15_part_2.h>
#include <solutions/16/day_16_part_1.h>
#include <solutions/16/day_16_part_2.h>
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

#define DEBUG_INPUT_PARSER false
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

	if(DEBUG_INPUT_PARSER) {
    	std::cout << "Reading file: " << filename << '\n';
	}
    std::ifstream ifStrm(filename);
    if(!ifStrm.is_open()){
        std::cerr << "Failed to open " << filename << '\n';
        return std::string{};
    }
	std::string _ret{(std::istreambuf_iterator<char>(ifStrm)),
        (std::istreambuf_iterator<char>())};
	if(DEBUG_INPUT_PARSER) {
		std::cout << "Successfully grabbed input data." << std::endl;
	}
    return _ret;
}
// ---------------------------------------------------------------------------

auto main(/*int argc, char** argv*/) -> int{

    std::cout << "\nDay 1, problem 1: " << std::endl;
    std::cout << "Answer:\n " << solutions::CountNumIncreasing( GetInputData(1, 1) ) << std::endl; // NOLINT

    std::cout << "\nDay 1, problem 2:" << std::endl;
    std::cout << "Answer:\n " << solutions::CountIncreasingSlidingWindow( GetInputData(1, 1) ) << std::endl; // NOLINT

    std::cout << "\nDay 2, problem 1:" << std::endl;
    std::cout << "Answer:\n " << solutions::SubmarineNavigationProduct( GetInputData(2, 1) ) << std::endl; // NOLINT

    std::cout << "\nDay 2, problem 2:" << std::endl;
    std::cout << "Answer:\n " << solutions::SubmarineAdvancedNavigationProduct( GetInputData(2, 1) ) << std::endl; // NOLINT

    std::cout << "\nDay 3, problem 1:" << std::endl;
    std::cout << "Answer:\n " << solutions::SubmarinePowerConsumption( GetInputData(3, 1) ) << std::endl; // NOLINT

    std::cout << "\nDay 3, problem 2:" << std::endl;
    std::cout << "Answer:\n " << solutions::SubmarineLifeSupportRating( GetInputData(3, 1) ) << std::endl; // NOLINT

    std::cout << "\nDay 4, problem 1:" << std::endl;
    std::cout << "Answer:\n " << solutions::WinBingo( GetInputData(4, 1) ) << std::endl; // NOLINT

    std::cout << "\nDay 4, problem 2:" << std::endl;
    std::cout << "Answer:\n " << solutions::LoseBingo( GetInputData(4, 1) ) << std::endl; // NOLINT

    std::cout << "\nDay 5, problem 1:" << std::endl;
    std::cout << "Answer:\n " << solutions::NumberOfOverlappingVentlinePoints( GetInputData(5, 1) ) << std::endl; // NOLINT

    std::cout << "\nDay 5, problem 2:" << std::endl;
    std::cout << "Answer:\n " << solutions::NumberOfOverlappingVentlinePointsIncludingDiagonals( GetInputData(5, 1) ) << std::endl; // NOLINT

    std::cout << "\nDay 6, problem 1:" << std::endl;
    std::cout << "Answer:\n " << solutions::CalculateNumberOfLanternFishAfterNDays( GetInputData(6, 1), 80 ) << std::endl; // NOLINT

    std::cout << "\nDay 6, problem 2:" << std::endl;
    std::cout << "Answer:\n " << solutions::CalculateMassiveNumberOfLanternFishAfterNDays( GetInputData(6, 1), 256 ) << std::endl; // NOLINT

    std::cout << "\nDay 7, problem 1:" << std::endl;
    std::cout << "Answer:\n " << solutions::CalculateAlignmentOptimalFuelConsumption( GetInputData(7, 1) ) << std::endl; // NOLINT

    std::cout << "\nDay 7, problem 2:" << std::endl;
    std::cout << "Answer:\n " << solutions::CalculateExpensiveAlignmentOptimalFuelConsumption( GetInputData(7, 1) ) << std::endl; // NOLINT

    std::cout << "\nDay 8, problem 1:" << std::endl;
    std::cout << "Answer:\n " << solutions::GetNumberOfCodesOfUniqueLengthInOutput( GetInputData(8, 1) ) << std::endl; // NOLINT

    std::cout << "\nDay 8, problem 2:" << std::endl;
    std::cout << "Answer:\n " << solutions::SumOfJumbledCodes( GetInputData(8, 1) ) << std::endl; // NOLINT

	std::cout << "\nDay 9, problem 1:" << std::endl;
    std::cout << "Answer:\n " << solutions::SumRiskLevelOfLowPoints( GetInputData(9, 1) ) << std::endl; // NOLINT

	std::cout << "\nDay 9, problem 2:" << std::endl;
    std::cout << "Answer:\n " << solutions::ProductOfLargestBasinSizes( GetInputData(9, 1), 3 ) << std::endl; // NOLINT
	
	std::cout << "\nDay 10, problem 1:" << std::endl;
    std::cout << "Answer:\n " << solutions::SyntaxErrorScoreCorrupted( GetInputData(10, 1) ) << std::endl; // NOLINT
	
	std::cout << "\nDay 10, problem 2:" << std::endl;
    std::cout << "Answer:\n " << solutions::MiddleCompletedScore( GetInputData(10, 1) ) << std::endl; // NOLINT
	
	std::cout << "\nDay 11, problem 1:" << std::endl;
    std::cout << "Answer:\n " << solutions::CountDumboFlashes( GetInputData(11, 1), 100 ) << std::endl; // NOLINT

	std::cout << "\nDay 11, problem 2:" << std::endl;
    std::cout << "Answer:\n " << solutions::PredictSynchronizedFlash( GetInputData(11, 1), 1000 ) << std::endl; // NOLINT

	std::cout << "\nDay 12, problem 1:" << std::endl;
    std::cout << "Answer:\n " << solutions::FindNumCavePaths( GetInputData(12, 1) ) << std::endl; // NOLINT
	
	std::cout << "\nDay 12, problem 2:" << std::endl;
    std::cout << "Answer:\n " << solutions::FindNumCavePathsWithExtraVisit( GetInputData(12, 1) ) << std::endl; // NOLINT

	std::cout << "\nDay 13, problem 1:" << std::endl;
    std::cout << "Answer:\n " << solutions::DotsVisibleAfterNFolds( GetInputData(13, 1), 1 ) << std::endl; // NOLINT

	std::cout << "\nDay 13, problem 2:" << std::endl;
    std::cout << "Answer:\n " << solutions::PrintCodeFromDottedPaper( GetInputData(13, 1), 0 ) << std::endl; // NOLINT

	std::cout << "\nDay 14, problem 1:" << std::endl;
    std::cout << "Answer:\n " << solutions::CommonUncommonPolymerDiff( GetInputData(14, 1), 10 ) << std::endl; // NOLINT

	std::cout << "\nDay 14, problem 2:" << std::endl;
    std::cout << "Answer:\n " << solutions::CommonUncommonPolymerDiff( GetInputData(14, 1), 40 ) << std::endl; // NOLINT

	std::cout << "\nDay 15, problem 1:" << std::endl;
    std::cout << "Answer:\n " << solutions::RiskValueOfLeastRiskyPath( GetInputData(15, 1) ) << std::endl; // NOLINT

	std::cout << "\nDay 15, problem 2:" << std::endl;
    std::cout << "Answer:\n " << solutions::RiskValueOfLeastRiskyPathThroughLargeMap( GetInputData(15, 1) ) << std::endl; // NOLINT

	std::cout << "\nDay 16, problem 1:" << std::endl;
    std::cout << "Answer:\n " << solutions::SumOfPackageVersions( GetInputData(16, 1) ) << std::endl; // NOLINT

	std::cout << "\nDay 16, problem 2:" << std::endl;
    std::cout << "Answer:\n " << solutions::EvaluatePackageValues( GetInputData(16, 1) ) << std::endl; // NOLINT

    return 0;
}