set(sources
    src/solutions/Solution_1_1.cpp
    src/solutions/Solution_1_2.cpp
    src/solutions/Solution_2_1.cpp
    src/solutions/Solution_2_2.cpp
    src/utils/StringSplit.cpp
)

set(exe_sources
		src/main.cpp
		${sources}
)

set(headers
    include/MyAoC_2021/utils/StringSplit.h
    include/MyAoC_2021/solutions/Solution_1_1.h
    include/MyAoC_2021/solutions/Solution_1_2.h
    include/MyAoC_2021/solutions/Solution_2_1.h
    include/MyAoC_2021/solutions/Solution_2_2.h
)

set(test_sources
  src/utils/StringSplit_test.cpp
  src/solutions/Solution_1_1_test.cpp
  src/solutions/Solution_1_2_test.cpp
  src/solutions/Solution_2_1_test.cpp
  src/solutions/Solution_2_2_test.cpp
)
