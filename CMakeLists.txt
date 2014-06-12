cmake_minimum_required (VERSION 2.6)
project (renshi)

# Here are a bunch of compiler flags.  Most are from the make files in /opt/vc/src/ folder.  I don't know what all of them do.
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DSTANDALONE -D__STDC_CONSTANT_MACROS -D__STDC_LIMIT_MACROS -DTARGET_POSIX -D_LINUX -fPIC -DPIC -D_REENTRANT  -U_FORTIFY_SOURCE -Wall -g -DHAVE_LIBOPENMAX=2 -DOMX -DOMX_SKIP64BIT -ftree-vectorize -pipe -DUSE_EXTERNAL_OMX -DHAVE_LIBBCM_HOST -DUSE_EXTERNAL_LIBBCM_HOST -DUSE_VCHIQ_ARM -Wno-psabi")

# Get a list of source files.  Touch this file if you add more files and have already ran CMake.
file(GLOB_RECURSE SRC_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h )

# Here are places to like for header files.
include_directories(/opt/vc/include/ /opt/vc/include/interface/vcos/pthreads /opt/vc/include/interface/vmcs_host/linux ${PROJECT_SOURCE_DIR}/include/glm)

add_executable(${PROJECT_NAME} ${SRC_FILES})

# Link RPi specific libraries
target_link_libraries(${PROJECT_NAME} "/opt/vc/lib/libEGL.so")
target_link_libraries(${PROJECT_NAME} "/opt/vc/lib/libGLESv2.so")
target_link_libraries(${PROJECT_NAME} "/opt/vc/lib/libbcm_host.so")

install(TARGETS renshi DESTINATION ${PROJECT_SOURCE_DIR}/bin)
