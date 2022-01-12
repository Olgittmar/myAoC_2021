if(${PROJECT_NAME}_ENABLE_CLANG_TIDY)
  find_program(CLANGTIDY clang-tidy)
  if(CLANGTIDY)
	set(CLANG_TIDY_ARGS
		--fix
		--fix-notes
		-p=${CMAKE_BINARY_DIR}
		-extra-arg=-Wno-unknown-warning-option
	)
    set(CMAKE_CXX_CLANG_TIDY ${CLANGTIDY} ${CLANG_TIDY_ARGS})
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
	set(CPP_CHECK_ARGS 
		--cppcheck-build-dir=${CPP_CHECK_CACHE_DIR}
		--suppressions-list=${CMAKE_SOURCE_DIR}/cppcheck_suppressions.txt
		-I${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME}/*
		--enable=warning
		--inline-suppr
		--inconclusive
	)
	if(${CMAKE_EXPORT_COMPILE_COMMANDS})
		list(APPEND CPP_CHECK_ARGS --project=${CMAKE_BINARY_DIR}/compile_commands.json)
	endif()

	#TODO: Seems a lot faster, would like to get this to work...
	# if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
	# 	list(APPEND CPP_CHECK_ARGS --clang)
	# endif()

    set(CMAKE_CXX_CPPCHECK ${CPPCHECK} ${CPP_CHECK_ARGS})
    message("Cppcheck finished setting up.")
  else()
    message(SEND_ERROR "Cppcheck requested but executable not found.")
  endif()
endif()
