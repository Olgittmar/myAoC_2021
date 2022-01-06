set(utils_sources
    src/utils/StringSplit.cpp
    src/utils/Coordinates.cpp
    src/utils/myMath.cpp
)

set(exe_sources
	src/main.cpp
)

set(utils_headers
	include/${PROJECT_NAME}/utils/Constants.h
    include/${PROJECT_NAME}/utils/StringSplit.h
    include/${PROJECT_NAME}/utils/Coordinates.h
    include/${PROJECT_NAME}/utils/myMath.h
)

set(test_utils_sources
  src/utils/StringSplit_test.cpp
  src/utils/Coordinates_test.cpp
  src/utils/myMath_test.cpp
)

set(test_solutions_sources
  src/solutions/1/Problem_1_part_1_test.cpp
  src/solutions/1/Problem_1_part_2_test.cpp
  src/solutions/2/Problem_2_part_1_test.cpp
  src/solutions/2/Problem_2_part_2_test.cpp
  src/solutions/3/Problem_3_part_1_test.cpp
  src/solutions/3/Problem_3_part_2_test.cpp
  src/solutions/4/Problem_4_part_1_test.cpp
  src/solutions/4/Problem_4_part_2_test.cpp
  src/solutions/5/Problem_5_part_1_test.cpp
  src/solutions/5/Problem_5_part_2_test.cpp
  src/solutions/6/Problem_6_part_1_test.cpp
  src/solutions/6/Problem_6_part_2_test.cpp
  src/solutions/7/Problem_7_part_1_test.cpp
  src/solutions/7/Problem_7_part_2_test.cpp
  src/solutions/8/Problem_8_part_1_test.cpp
  src/solutions/8/Problem_8_part_2_test.cpp
  src/solutions/9/Problem_9_part_1_test.cpp
  src/solutions/9/Problem_9_part_2_test.cpp
  src/solutions/10/Problem_10_part_1_test.cpp
  src/solutions/10/Problem_10_part_2_test.cpp
  src/solutions/11/Problem_11_part_1_test.cpp
  src/solutions/11/Problem_11_part_2_test.cpp
  src/solutions/12/Problem_12_part_1_test.cpp
  src/solutions/12/Problem_12_part_2_test.cpp
  src/solutions/13/Problem_13_part_1_test.cpp
  src/solutions/13/Problem_13_part_2_test.cpp
  src/solutions/14/Problem_14_part_1_test.cpp
  src/solutions/14/Problem_14_part_2_test.cpp
  src/solutions/15/Problem_15_part_1_test.cpp
  src/solutions/15/Problem_15_part_2_test.cpp
  src/solutions/16/Problem_16_part_1_test.cpp
  src/solutions/16/Problem_16_part_2_test.cpp
  src/solutions/17/Problem_17_part_1_test.cpp
  src/solutions/17/Problem_17_part_2_test.cpp
  src/solutions/18/Problem_18_part_1_test.cpp
  src/solutions/18/Problem_18_part_2_test.cpp
  src/solutions/19/Problem_19_part_1_test.cpp
  src/solutions/19/Problem_19_part_2_test.cpp
  src/solutions/20/Problem_20_part_1_test.cpp
  src/solutions/20/Problem_20_part_2_test.cpp
  src/solutions/21/Problem_21_part_1_test.cpp
  src/solutions/21/Problem_21_part_2_test.cpp
  src/solutions/22/Problem_22_part_1_test.cpp
  src/solutions/22/Problem_22_part_2_test.cpp
  src/solutions/23/Problem_23_part_1_test.cpp
  src/solutions/23/Problem_23_part_2_test.cpp
  src/solutions/24/Problem_24_part_1_test.cpp
  src/solutions/24/Problem_24_part_2_test.cpp
  src/solutions/25/Problem_25_part_1_test.cpp
  src/solutions/25/Problem_25_part_2_test.cpp
)
