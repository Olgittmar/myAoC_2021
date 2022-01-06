cmake_minimum_required(VERSION 3.15)

#
# Project details
#

project(
  ${CMAKE_PROJECT_NAME}Tests
  LANGUAGES CXX
)

verbose_message("Adding tests under ${CMAKE_PROJECT_NAME}Tests...")

find_package(GTest REQUIRED)

# utils lib first
foreach(file ${test_utils_sources})
  string(REGEX REPLACE "(.*/)([a-zA-Z0-9_ ]+)(\.cpp)" "\\2" test_name ${file})
  add_executable(${test_name}_Tests ${file})

  target_link_libraries(
	  ${test_name}_Tests
	PRIVATE
  )
  
  target_include_directories(
	${test_name}_Tests
	PUBLIC
	  $<INSTALL_INTERFACE:include/utils>
	  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}/utils>
	PRIVATE
	  ${CMAKE_CURRENT_SOURCE_DIR}/src/utils
  )

  #
  # Set the compiler standard
  #
  target_compile_features(${test_name}_Tests PUBLIC cxx_std_20)

  #
  # Setup code coverage if enabled
  #
  if (${CMAKE_PROJECT_NAME}_ENABLE_CODE_COVERAGE)
    target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC -O0 -g -fprofile-arcs -ftest-coverage)
    target_link_options(${CMAKE_PROJECT_NAME} PUBLIC -fprofile-arcs -ftest-coverage)
    verbose_message("Code coverage is enabled and provided with GCC.")
  endif()

  #
  # Load the desired unit testing framework
  #
  # Currently supported: GoogleTest (and GoogleMock), Catch2.

  if(${CMAKE_PROJECT_NAME}_USE_GOOGLE_MOCK)
    set(GOOGLE_MOCK_LIBRARIES GTest::gmock GTest::gmock_main)
  endif()

  target_link_libraries(
    ${test_name}_Tests
    PUBLIC
      GTest::gtest
      GTest::gtest_main
      ${GOOGLE_MOCK_LIBRARIES}
      utils
  )

  #
  # Add the unit tests
  #

  add_test(
    NAME
      ${test_name}
    COMMAND
      ${test_name}_Tests
  )
endforeach()

foreach(file ${test_solutions_sources})
  string(REGEX REPLACE "(.*/)([a-zA-Z0-9_ ]+)(\.cpp)" "\\2" test_name ${file})
  add_executable(${test_name}_Tests ${file})
  
  target_include_directories(
	${test_name}_Tests
	PUBLIC
	  $<INSTALL_INTERFACE:include/solutions>
	  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}/solutions>
	PRIVATE
	  ${CMAKE_CURRENT_SOURCE_DIR}/src/solutions
  )

  #
  # Set the compiler standard
  #
  target_compile_features(${test_name}_Tests PUBLIC cxx_std_20)

  #
  # Setup code coverage if enabled
  #
  if (${CMAKE_PROJECT_NAME}_ENABLE_CODE_COVERAGE)
    target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC -O0 -g -fprofile-arcs -ftest-coverage)
    target_link_options(${CMAKE_PROJECT_NAME} PUBLIC -fprofile-arcs -ftest-coverage)
    verbose_message("Code coverage is enabled and provided with GCC.")
  endif()

  #
  # Load the desired unit testing framework
  #
  # Currently supported: GoogleTest (and GoogleMock), Catch2.

  if(${CMAKE_PROJECT_NAME}_USE_GOOGLE_MOCK)
    set(GOOGLE_MOCK_LIBRARIES GTest::gmock GTest::gmock_main)
  endif()

  target_link_libraries(
    ${test_name}_Tests
    PUBLIC
      GTest::gtest
      GTest::gtest_main
      ${GOOGLE_MOCK_LIBRARIES}
      ${SOLUTIONS_LIBS}
  )

  #
  # Add the unit tests
  #

  add_test(
    NAME
      ${test_name}
    COMMAND
      ${test_name}_Tests
  )
endforeach()

verbose_message("Finished adding unit tests for ${CMAKE_PROJECT_NAME}.")
