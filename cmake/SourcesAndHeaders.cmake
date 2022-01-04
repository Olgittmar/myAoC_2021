set(sources
    src/utils/StringSplit.cpp
    src/utils/Coordinates.cpp
    src/utils/myMath.cpp
    src/solutions/Solution_1_1.cpp
    src/solutions/Solution_1_2.cpp
    src/solutions/Solution_2_1.cpp
    src/solutions/Solution_2_2.cpp
    src/solutions/Solution_3_1.cpp
    src/solutions/Solution_3_2.cpp
    src/solutions/Solution_4_1.cpp
    src/solutions/Solution_4_2.cpp
    src/solutions/Solution_5_1.cpp
    src/solutions/Solution_5_2.cpp
    src/solutions/Solution_6_1.cpp
    src/solutions/Solution_6_2.cpp
    src/solutions/Solution_7_1.cpp
    src/solutions/Solution_7_2.cpp
    src/solutions/Solution_8_1.cpp
    src/solutions/Solution_8_2.cpp
    src/solutions/Solution_9_1.cpp
    src/solutions/Solution_9_2.cpp
    src/solutions/Solution_10_1.cpp
)

set(exe_sources
	src/main.cpp
	${sources}
)

set(headers
    include/MyAoC_2021/utils/StringSplit.h
    include/MyAoC_2021/utils/Coordinates.h
    include/MyAoC_2021/utils/Constants.h
    include/MyAoC_2021/utils/myMath.h
    include/MyAoC_2021/solutions/Solution_1_1.h
    include/MyAoC_2021/solutions/Solution_1_2.h
    include/MyAoC_2021/solutions/Solution_2_1.h
    include/MyAoC_2021/solutions/Solution_2_2.h
    include/MyAoC_2021/solutions/Solution_3_1.h
    include/MyAoC_2021/solutions/Solution_3_2.h
    include/MyAoC_2021/solutions/Solution_4_1.h
    include/MyAoC_2021/solutions/Solution_4_2.h
    include/MyAoC_2021/solutions/Solution_5_1.h
    include/MyAoC_2021/solutions/Solution_5_2.h
    include/MyAoC_2021/solutions/Solution_6_1.h
    include/MyAoC_2021/solutions/Solution_6_2.h
    include/MyAoC_2021/solutions/Solution_7_1.h
    include/MyAoC_2021/solutions/Solution_7_2.h
    include/MyAoC_2021/solutions/Solution_8_1.h
    include/MyAoC_2021/solutions/Solution_8_2.h
    include/MyAoC_2021/solutions/Solution_9_1.h
    include/MyAoC_2021/solutions/Solution_9_2.h
    include/MyAoC_2021/solutions/Solution_10_1.h
)

set(test_utils_sources
  src/utils/StringSplit_test.cpp
  src/utils/Coordinates_test.cpp
  src/utils/myMath_test.cpp
)


set(test_solutions_sources
  src/solutions/Solution_1_1_test.cpp
  src/solutions/Solution_1_2_test.cpp
  src/solutions/Solution_2_1_test.cpp
  src/solutions/Solution_2_2_test.cpp
  src/solutions/Solution_3_1_test.cpp
  src/solutions/Solution_3_2_test.cpp
  src/solutions/Solution_4_1_test.cpp
  src/solutions/Solution_4_2_test.cpp
  src/solutions/Solution_5_1_test.cpp
  src/solutions/Solution_5_2_test.cpp
  src/solutions/Solution_6_1_test.cpp
  src/solutions/Solution_6_2_test.cpp
  src/solutions/Solution_7_1_test.cpp
  src/solutions/Solution_7_2_test.cpp
  src/solutions/Solution_8_1_test.cpp
  src/solutions/Solution_8_2_test.cpp
  src/solutions/Solution_9_1_test.cpp
  src/solutions/Solution_9_2_test.cpp
  src/solutions/Solution_10_1_test.cpp
)
