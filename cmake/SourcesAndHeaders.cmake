set(sources
    src/utils/StringSplit.cpp
    src/utils/Coordinates.cpp
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
)

set(exe_sources
	src/main.cpp
	${sources}
)

set(headers
    include/MyAoC_2021/utils/StringSplit.h
    include/MyAoC_2021/utils/Coordinates.h
    include/MyAoC_2021/utils/Constants.h
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
)

set(test_utils_sources
  src/utils/StringSplit_test.cpp
  src/utils/Coordinates_test.cpp
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
)
