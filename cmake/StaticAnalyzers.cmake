if(${PROJECT_NAME}_ENABLE_CLANG_TIDY)
  find_program(CLANGTIDY clang-tidy)
  if(CLANGTIDY)
    set(CMAKE_CXX_CLANG_TIDY ${CLANGTIDY} -extra-arg=-Wno-unknown-warning-option)
    message("Clang-Tidy finished setting up.")
  else()
    message(SEND_ERROR "Clang-Tidy requested but executable not found.")
  endif()
endif()

if(${PROJECT_NAME}_ENABLE_CPPCHECK)
  find_program(CPPCHECK cppcheck)
  if(CPPCHECK)
	set(CPP_CHECK_CACHE_DIR ${CMAKE_BINARY_DIR}/cppcheck)
  	file(MAKE_DIRECTORY ${CPP_CHECK_CACHE_DIR})
    set(CMAKE_CXX_CPPCHECK ${CPPCHECK}
		--cppcheck-build-dir=${CPP_CHECK_CACHE_DIR}
		--suppressions-list=${CMAKE_SOURCE_DIR}/cppcheck_suppressions.txt
		-I${CMAKE_SOURCE_DIR}/include/MyAoC_2021/*
		--enable=warning
        --inline-suppr
		--inconclusive)
    message("Cppcheck finished setting up.")
  else()
    message(SEND_ERROR "Cppcheck requested but executable not found.")
  endif()
endif()
