if(${PROJECT_NAME}_ENABLE_CONAN)
  #
  # Setup Conan requires and options here:
  #

  set(${PROJECT_NAME}_CONAN_REQUIRES "gtest/cci.20210126")
  set(${PROJECT_NAME}_CONAN_OPTIONS "gtest:build_gmock=False")
  set(${PROJECT_NAME}_CONAN_GENERATORS "cmake_find_package")

  #
  # If `conan.cmake` (from https://github.com/conan-io/cmake-conan) does not exist, download it.
  #
  if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(
      STATUS
      "Downloading conan.cmake from https://github.com/conan-io/cmake-conan..."
    )
    file(
      DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/0.17.0/conan.cmake"
      "${CMAKE_BINARY_DIR}/conan.cmake"
    )
    message(STATUS "Cmake-Conan downloaded succesfully.")
  endif()

  include(${CMAKE_BINARY_DIR}/conan.cmake)

  # conan_add_remote(
  #   NAME bincrafters
  #   URL
  #   https://api.bintray.com/conan/bincrafters/public-conan
  # )

  conan_cmake_run(
    REQUIRES
    ${${PROJECT_NAME}_CONAN_REQUIRES}
    OPTIONS
    ${${PROJECT_NAME}_CONAN_OPTIONS}
    GENERATORS
    ${${PROJECT_NAME}_CONAN_GENERATORS}
    BASIC_SETUP
    CMAKE_TARGETS # Individual targets to link to
    BUILD
    missing
  )

  conan_basic_setup()

  verbose_message("Conan is setup and all requires have been installed.")
endif()
