cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

#
# Project details
#

project(
  "MyAoC_2021"
  VERSION 0.2.0
  LANGUAGES CXX
)


if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "Debug")
endif()

if (UNIX)
	add_compile_options("$<$<CONFIG:DEBUG>:-D_DEBUG>")    #this will allow to use same _DEBUG macro available in both Linux as well as Windows - MSCV environment. Easy to put Debug specific code.
endif (UNIX)
message(STATUS "Started CMake for ${PROJECT_NAME} v${PROJECT_VERSION} Build type: ${CMAKE_BUILD_TYPE}\n")

#
# Set project options
#

include(cmake/StandardSettings.cmake)
include(cmake/Utils.cmake)


#
# Setup alternative names
#

if(${PROJECT_NAME}_USE_ALT_NAMES)
  string(TOLOWER ${PROJECT_NAME} PROJECT_NAME_LOWERCASE)
  string(TOUPPER ${PROJECT_NAME} PROJECT_NAME_UPPERCASE)
else()
  set(PROJECT_NAME_LOWERCASE ${PROJECT_NAME})
  set(PROJECT_NAME_UPPERCASE ${PROJECT_NAME})
endif()

#
# Prevent building in the source directory
#

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there.\n")
endif()

#
# Enable package managers
#

include(cmake/Conan.cmake)
include(cmake/Vcpkg.cmake)

#
# Create library, setup header and source files
#

# Find all headers and implementation files
include(cmake/SourcesAndHeaders.cmake)
include(cmake/CompilerWarnings.cmake)

# Set up common precompiled headers
set(STD_PCH
  <iostream>
  <string>
  <string_view>
  <vector>
  <map>
  <set>
  <algorithm>
  <numeric>
)

# Create utils library
add_library(
  ${PROJECT_NAME}_UTILS_LIB
  STATIC
    ${utils_headers}
    ${utils_sources}
)

target_include_directories(
  ${PROJECT_NAME}_UTILS_LIB
  PRIVATE
	$<INSTALL_INTERFACE:include/utils>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/utils>
)

target_link_libraries(
	${PROJECT_NAME}_UTILS_LIB
	PUBLIC
	  ${llvm_libs}
)

target_compile_features(${PROJECT_NAME}_UTILS_LIB PUBLIC cxx_std_20)

set(UTILS_PCH "")
foreach(rel_path ${utils_headers})
	list(APPEND UTILS_PCH
		$<INSTALL_INTERFACE:${rel_path}>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${rel_path}>
	)
endforeach()


target_precompile_headers(
  ${PROJECT_NAME}_UTILS_LIB
  PUBLIC
	${STD_PCH}
  PRIVATE
	${UTILS_PCH}
)

target_include_directories(
  ${PROJECT_NAME}_UTILS_LIB
  PUBLIC
	$<INSTALL_INTERFACE:include/utils>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}/utils>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils
)

if(${PROJECT_NAME}_VERBOSE_OUTPUT)
  verbose_message("Found the following sources:")
  foreach(source IN LISTS utils_sources)
    verbose_message("* ${source}")
  endforeach()
  verbose_message("Found the following headers:")
  foreach(header IN LISTS utils_headers)
    verbose_message("* ${header}")
  endforeach()
endif()

set_target_properties(
  ${PROJECT_NAME}_UTILS_LIB
  PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}"
)

set_project_warnings(${PROJECT_NAME}_UTILS_LIB)

install(
  TARGETS
    ${PROJECT_NAME}_UTILS_LIB
  EXPORT
    ${PROJECT_NAME}Targets
  LIBRARY DESTINATION
    ${CMAKE_INSTALL_PREFIX}/lib
  ARCHIVE DESTINATION
	${CMAKE_INSTALL_PREFIX}/lib
  PUBLIC_HEADER DESTINATION
	${CMAKE_INSTALL_PREFIX}/include/utils
  INCLUDES DESTINATION
	${CMAKE_INSTALL_PREFIX}/include/utils
  PUBLIC_HEADER DESTINATION
	${CMAKE_INSTALL_PREFIX}/include/utils
)

add_library(${PROJECT_NAME}::utils ALIAS ${PROJECT_NAME}_UTILS_LIB)

# Create solution libraries
# TODO: Each solution should be an independent library
set(SOLUTIONS_LIBS "")
foreach(DAY RANGE 1 25)
  add_library(
    ${PROJECT_NAME}_SOLUTION_${DAY}_LIB
    STATIC
	  include/${PROJECT_NAME}/solutions/${DAY}/day_${DAY}_part_1.h
	  include/${PROJECT_NAME}/solutions/${DAY}/day_${DAY}_part_2.h
  	  src/solutions/${DAY}/day_${DAY}_part_1.cpp
  	  src/solutions/${DAY}/day_${DAY}_part_2.cpp
  )

  # Add dependency to utils lib so we don't start compiling solutions before utils are done
  add_dependencies(${PROJECT_NAME}_SOLUTION_${DAY}_LIB ${PROJECT_NAME}_UTILS_LIB)

  # Reuse precompiled headers from utils lib
  target_precompile_headers(
	${PROJECT_NAME}_SOLUTION_${DAY}_LIB
	PUBLIC
	  ${STD_PCH}
	PRIVATE
	  include/${PROJECT_NAME}/solutions/${DAY}/day_${DAY}_part_1.h
	  include/${PROJECT_NAME}/solutions/${DAY}/day_${DAY}_part_2.h
  )

  target_include_directories(
    ${PROJECT_NAME}_SOLUTION_${DAY}_LIB
	PUBLIC
	  $<INSTALL_INTERFACE:include>
	  $<INSTALL_INTERFACE:lib>
	  $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME}>
	PRIVATE
	  ${CMAKE_SOURCE_DIR}/src
  )

  set_target_properties(
	  ${PROJECT_NAME}_SOLUTION_${DAY}_LIB
    PROPERTIES
      ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}"
      LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}"
  )

  target_link_libraries(
	  ${PROJECT_NAME}_SOLUTION_${DAY}_LIB
    PRIVATE
      ${PROJECT_NAME}_UTILS_LIB
	  ${llvm_libs}
  )

  target_compile_features(${PROJECT_NAME}_SOLUTION_${DAY}_LIB PUBLIC cxx_std_20)
  set_project_warnings(${PROJECT_NAME}_SOLUTION_${DAY}_LIB)
  list(APPEND SOLUTIONS_LIBS ${PROJECT_NAME}_SOLUTION_${DAY}_LIB)

  install(
	TARGETS
	  ${PROJECT_NAME}_SOLUTION_${DAY}_LIB
	EXPORT
	  ${PROJECT_NAME}Targets
	LIBRARY DESTINATION
	  ${CMAKE_INSTALL_PREFIX}/lib
	ARCHIVE DESTINATION
	  ${CMAKE_INSTALL_PREFIX}/lib
	PUBLIC_HEADER DESTINATION
	  ${CMAKE_INSTALL_PREFIX}/include/solutions
	INCLUDES DESTINATION
	  ${CMAKE_INSTALL_PREFIX}/include/solutions
	PUBLIC_HEADER DESTINATION
	  ${CMAKE_INSTALL_PREFIX}/include/solutions
  )

  add_library(${PROJECT_NAME}::solution_${DAY} ALIAS ${PROJECT_NAME}_SOLUTION_${DAY}_LIB)
  message("${PROJECT_NAME}_SOLUTION_${DAY}_LIB aliased as ${PROJECT_NAME}::solution_${DAY}")
endforeach()

if(${PROJECT_NAME}_VERBOSE_OUTPUT)
  verbose_message("Created solution libraries:")
  foreach(lib IN LISTS SOLUTIONS_LIBS)
	verbose_message("* ${lib}")
  endforeach()
endif()

#
# Unit testing setup
#

if(${PROJECT_NAME}_ENABLE_UNIT_TESTING)
  enable_testing()
  message(STATUS "Build unit tests for the project. Tests should always be found in the test folder\n")
  add_subdirectory(test)
endif()

# Enable static analyzers for main target only
# I think this should stop clang-tidy and cppcheck from running for all files for each target generated
include(cmake/StaticAnalyzers.cmake)

# Create main executable or exportable interface (Not sure how the latter will work)
add_executable(${PROJECT_NAME} ${exe_sources})
add_dependencies(${PROJECT_NAME} ${SOLUTIONS_LIBS})

list(APPEND STATIC_ANALYSIS_SOURCES ${exe_sources})

if(${PROJECT_NAME}_VERBOSE_OUTPUT)
  verbose_message("Found the following sources:")
  foreach(source IN LISTS exe_sources)
	verbose_message("* ${source}")
  endforeach()
endif()

target_link_libraries(
	${PROJECT_NAME}
  PRIVATE
    ${SOLUTIONS_LIBS}
	${llvm_libs}
)

set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}"
	LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}"
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}"
)

message(STATUS "Added all header and implementation files.\n")

#
# Set the project standard and warnings
#
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
set_project_warnings(${PROJECT_NAME})

verbose_message("Applied compiler warnings. Using standard ${CMAKE_CXX_STANDARD}.\n")

#
# Enable Doxygen
#

include(cmake/Doxygen.cmake)

#
# Provide alias to library for
#
add_executable(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

verbose_message("Project is now aliased as ${PROJECT_NAME}::${PROJECT_NAME}.\n")

#
# Format the project using the `clang-format` target (i.e: cmake --build build --target clang-format)
#

add_clang_format_target()

#
# Install library for easy downstream inclusion
#

install(
  TARGETS
  ${PROJECT_NAME}
  EXPORT
  ${PROJECT_NAME}Targets
  LIBRARY DESTINATION
	${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION
	${CMAKE_INSTALL_BINDIR}
  ARCHIVE DESTINATION
	${CMAKE_INSTALL_LIBDIR}
  INCLUDES DESTINATION
	include
  PUBLIC_HEADER DESTINATION
	include
)

# I have probably broken this with the restructuring...
install(
  EXPORT
  ${PROJECT_NAME}Targets
  FILE
	${PROJECT_NAME}Targets.cmake
  NAMESPACE
	${PROJECT_NAME}::
  DESTINATION
	${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

#
# Add version header
#

configure_file(
  ${CMAKE_CURRENT_LIST_DIR}/cmake/version.hpp.in
  include/${PROJECT_NAME_LOWERCASE}/version.hpp
  @ONLY
)

install(
  FILES
  ${CMAKE_CURRENT_BINARY_DIR}/include/${PROJECT_NAME_LOWERCASE}/version.hpp
  DESTINATION
	include/${PROJECT_NAME_LOWERCASE}
)

#
# Install the `include` directory
#
## solutions and utils are built as semi-independent libs
## and install rules are generated for them individually

# install(
#   DIRECTORY
#   include/${PROJECT_NAME_LOWERCASE}
#   DESTINATION
#   include
# )

# verbose_message("Install targets succesfully build. Install with `cmake --build <build_directory> --target install --config <build_config>`.")

#
# Quick `ConfigVersion.cmake` creation
#

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  ${PROJECT_NAME}ConfigVersion.cmake
  VERSION
	${PROJECT_VERSION}
  COMPATIBILITY
	SameMajorVersion
)

configure_package_config_file(
  ${CMAKE_CURRENT_LIST_DIR}/cmake/${PROJECT_NAME}Config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
  INSTALL_DESTINATION
  ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

install(
  FILES
	${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
	${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
  DESTINATION
	${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

#
# Generate export header if specified
#
## Should not be used, may look into how this works in the future
# if(${PROJECT_NAME}_GENERATE_EXPORT_HEADER)
#   include(GenerateExportHeader)
#   generate_export_header(${PROJECT_NAME})
#   install(
#     FILES
#     ${PROJECT_BINARY_DIR}/${PROJECT_NAME_LOWERCASE}_export.h
#     DESTINATION
#     include
#   )

#   message(STATUS "Generated the export header `${PROJECT_NAME_LOWERCASE}_export.h` and installed it.")
# endif()

message(STATUS "Finished building requirements for installing the package.\n")
