cmake_minimum_required(VERSION 3.15)

#
# Project details
#

project(
  ${CMAKE_PROJECT_NAME}Tests
  LANGUAGES CXX
)

verbose_message("Adding tests under ${CMAKE_PROJECT_NAME}Tests...")

#
# Load the desired unit testing framework
#
# Currently supported: GoogleTest (and GoogleMock), Catch2.
find_package(GTest REQUIRED)

if(${CMAKE_PROJECT_NAME}_USE_GOOGLE_MOCK)
	set(GOOGLE_MOCK_LIBRARIES GTest::gmock GTest::gmock_main)
endif()

# utils lib first
foreach(file ${test_utils_sources})
  string(REGEX REPLACE "(.*/)([a-zA-Z0-9_ ]+)(\.cpp)" "\\2" test_name ${file})
  add_executable(${test_name}_Tests ${file})
  add_dependencies(${test_name}_Tests MyAoC_2021::utils)
  
  target_include_directories(
	${test_name}_Tests
	PRIVATE
	  $<INSTALL_INTERFACE:include/utils>
	  $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/utils>
  )

  #
  # Set the compiler standard
  #
  target_compile_features(${test_name}_Tests PUBLIC cxx_std_20)

  target_link_libraries(
    ${test_name}_Tests
    PUBLIC
      GTest::gtest
      GTest::gtest_main
      ${GOOGLE_MOCK_LIBRARIES}
      MyAoC_2021::utils
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
  string(REGEX REPLACE "(.*/)(day_)([0-9]+)([a-zA-Z0-9_ ]+)(\.cpp)" "\\2\\3" test_name ${file})
  set(dayNumber ${CMAKE_MATCH_3})
  add_executable(${test_name}_Tests ${file})

  #
  # Set the compiler standard
  #
  target_compile_features(${test_name}_Tests PUBLIC cxx_std_20)

  target_link_libraries(
    ${test_name}_Tests
    PUBLIC
      GTest::gtest
      GTest::gtest_main
      ${GOOGLE_MOCK_LIBRARIES}
      MyAoC_2021::solution_${dayNumber}
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
