cmake_minimum_required(VERSION 3.15)

#
# Project details
#

project(
  "MyAoC_2021"
  VERSION 0.2.0
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)

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
include(cmake/StaticAnalyzers.cmake)
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
include(GNUInstallDirs)

# Create utils library
add_library(
  ${PROJECT_NAME}_UTILS_LIB
  STATIC
    ${utils_headers}
    ${utils_sources}
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

target_compile_features(${PROJECT_NAME}_UTILS_LIB PUBLIC cxx_std_20)
set_project_warnings(${PROJECT_NAME}_UTILS_LIB)

install(
  TARGETS
    ${PROJECT_NAME}_UTILS_LIB
  EXPORT
    ${PROJECT_NAME}Targets
  LIBRARY DESTINATION
    ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION
    ${CMAKE_INSTALL_BINDIR}
  ARCHIVE DESTINATION
    ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION
	include/utils
  INCLUDES DESTINATION
    include/utils
  PUBLIC_HEADER DESTINATION
    include/utils
)

add_library(utils ALIAS ${PROJECT_NAME}_UTILS_LIB)

# Create solution libraries
# TODO: Each solution should be an independent library
set(SOLUTIONS_LIBS "")
foreach(NUM RANGE 1 25)
  add_library(
    ${PROJECT_NAME}_SOLUTION_${NUM}_LIB
    STATIC
	  include/${PROJECT_NAME}/solutions/${NUM}/part_1.h
	  include/${PROJECT_NAME}/solutions/${NUM}/part_2.h
  	  src/solutions/${NUM}/part_1.cpp
  	  src/solutions/${NUM}/part_2.cpp
  )

  target_include_directories(
    ${PROJECT_NAME}_SOLUTION_${NUM}_LIB
	PUBLIC
	  $<INSTALL_INTERFACE:include/solutions>
	  $<INSTALL_INTERFACE:include/utils>
	  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}/solutions>
	  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}/utils>
	PRIVATE
	  ${CMAKE_CURRENT_SOURCE_DIR}/src/solutions
  )

  set_target_properties(
	  ${PROJECT_NAME}_SOLUTION_${NUM}_LIB
    PROPERTIES
      ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}"
      LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}"
  )

  target_link_libraries(
	  ${PROJECT_NAME}_SOLUTION_${NUM}_LIB
    PRIVATE
      ${PROJECT_NAME}_UTILS_LIB
  )

  target_compile_features(${PROJECT_NAME}_SOLUTION_${NUM}_LIB PUBLIC cxx_std_20)
  set_project_warnings(${PROJECT_NAME}_SOLUTION_${NUM}_LIB)
  list(APPEND SOLUTIONS_LIBS ${PROJECT_NAME}_SOLUTION_${NUM}_LIB)
  
install(
	TARGETS
	  ${PROJECT_NAME}_SOLUTION_${NUM}_LIB
	EXPORT
	  ${PROJECT_NAME}Targets
	LIBRARY DESTINATION
	  ${CMAKE_INSTALL_LIBDIR}
	RUNTIME DESTINATION
	  ${CMAKE_INSTALL_BINDIR}
	ARCHIVE DESTINATION
	  ${CMAKE_INSTALL_LIBDIR}
	INCLUDES DESTINATION
	  include/solutions
	PUBLIC_HEADER DESTINATION
	  include/solutions
  )

  add_library(solution_${num} ALIAS ${PROJECT_NAME}_SOLUTION_${NUM}_LIB)
endforeach()

if(${PROJECT_NAME}_VERBOSE_OUTPUT)
  verbose_message("Created solution libraries:")
  foreach(lib IN LISTS SOLUTIONS_LIBS)
	verbose_message("* ${lib}")
  endforeach()
endif()

# Create main executable or exportable interface (Not sure how the latter will work)
add_executable(${PROJECT_NAME} ${exe_sources})

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

# if(${PROJECT_NAME}_ENABLE_UNIT_TESTING)
#   target_compile_features(${PROJECT_NAME}_LIB PUBLIC cxx_std_20)
# endif()

verbose_message("Applied compiler warnings. Using standard ${CMAKE_CXX_STANDARD}.\n")

#
# Enable Doxygen
#

include(cmake/Doxygen.cmake)

#
# Model project dependencies
#

# Identify and link with the specific "packages" the project uses
#find_package(package_name package_version REQUIRED package_type [other_options])
#target_link_libraries(
#  ${PROJECT_NAME}
#  PUBLIC
#    dependency1 ...
#  PRIVATE
#    dependency2 ...
#    ${PROJECT_NAME}_PROJECT_OPTIONS
#    ${PROJECT_NAME}_PROJECT_WARNINGS
#)

# For Windows, it is necessary to link with the MultiThreaded library.
# Depending on how the rest of the project's dependencies are linked, it might be necessary
# to change the line to statically link with the library.
#
# This is done as follows:
#
# set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
#
# On Linux and Mac this variable is ignored. If any issues rise from it, try commenting it out
# and letting CMake decide how to link with it.
# set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")

verbose_message("Successfully added all dependencies and linked against them.")

#
# Set the build/user include directories
#

# Allow usage of header files in the `src` directory, but only for utilities
# target_include_directories(
#   ${PROJECT_NAME}
#   PUBLIC
#   $<INSTALL_INTERFACE:include>
#   $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#   PRIVATE
#   ${CMAKE_CURRENT_SOURCE_DIR}/src
# )

# if(${PROJECT_NAME}_ENABLE_UNIT_TESTING)
#   target_include_directories(
# 	${PROJECT_NAME}_LIB
# 	PUBLIC
# 	$<INSTALL_INTERFACE:include>
# 	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
# 	PRIVATE
# 	${CMAKE_CURRENT_SOURCE_DIR}/src
#   )
# endif()

message(STATUS "Finished setting up include directories.")

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

install(
  DIRECTORY
  include/${PROJECT_NAME_LOWERCASE}
  DESTINATION
  include
)

verbose_message("Install targets succesfully build. Install with `cmake --build <build_directory> --target install --config <build_config>`.")

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

if(${PROJECT_NAME}_GENERATE_EXPORT_HEADER)
  include(GenerateExportHeader)
  generate_export_header(${PROJECT_NAME})
  install(
    FILES
    ${PROJECT_BINARY_DIR}/${PROJECT_NAME_LOWERCASE}_export.h
    DESTINATION
    include
  )

  message(STATUS "Generated the export header `${PROJECT_NAME_LOWERCASE}_export.h` and installed it.")
endif()

message(STATUS "Finished building requirements for installing the package.\n")

#
# Unit testing setup
#

if(${PROJECT_NAME}_ENABLE_UNIT_TESTING)
  enable_testing()
  message(STATUS "Build unit tests for the project. Tests should always be found in the test folder\n")
  add_subdirectory(test)
  file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/Testing)
  file(TOUCH ${CMAKE_BINARY_DIR}/Testing/testlog.log)
endif()
