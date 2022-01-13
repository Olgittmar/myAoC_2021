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
    include/${PROJECT_NAME}/utils/myConcepts.h
	include/${PROJECT_NAME}/utils/utils.h
)

set(test_utils_sources
  src/utils/StringSplit_test.cpp
  src/utils/Coordinates_test.cpp
  src/utils/myMath_test.cpp
)

set(test_solutions_sources "")
foreach(DAY RANGE 1 25)
	list(APPEND test_solutions_sources src/solutions/day_${DAY}_test.cpp)
endforeach()