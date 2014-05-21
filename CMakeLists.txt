cmake_minimum_required (VERSION 2.6)
project (renshi)

# Get a list of source files.  Touch this file if you add more files and have already ran CMake.
file(GLOB_RECURSE source_files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/source/*.h)
add_executable(renshi ${source_files})

# Apple needs frameworks instead of standar libs
if(APPLE)
	include_directories ( /System/Library/Frameworks )
	find_library(COCOA_LIBRARY Cocoa)
	find_library(GLUT_LIBRARY GLUT )
	find_library(OpenGL_LIBRARY OpenGL )
	mark_as_advanced (COCOA_LIBRARY GLUT_LIBRARY OpenGL_LIBRARY)
	set(EXTRA_LIBS ${COCOA_LIBRARY} ${GLUT_LIBRARY} ${OpenGL_LIBRARY})
	target_link_libraries(renshi ${EXTRA_LIBS})
else()
	target_link_libraries(renshi GL)
	target_link_libraries(renshi glut)
endif(APPLE)

install(TARGETS renshi DESTINATION ${PROJECT_SOURCE_DIR}/bin)
