project(darling-corecrypto)

cmake_minimum_required(VERSION 2.4.0)
enable_language(C ASM)

if(COMMAND cmake_policy)
	cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -msse -msse2 -msse3 -w -nostdinc")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D__DARWIN_UNIX03 -fPIC -w")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -nostdlib -Wl,--version-script=${DARLING_TOP_DIRECTORY}/darwin.map")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS}")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/cc/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ccn/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ccdigest/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ccmd2/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ccmd4/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ccmd5/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ccsha1/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ccsha2/include)

include_directories(${DARLING_TOP_DIRECTORY}/platform-include)

add_definitions(-D_FILE_OFFSET_BITS=64)

set(cc_sources
	cc/src/cc_zero.c
	cc/src/cc_clear.c
	cc/src/cc_copy.c
	cc/src/cc_xor.c
	cc/src/cc_cmp_safe.c
	cc/src/cc_muxp.c
	ccdigest/src/ccdigest.c
	ccmd2/src/ccmd2.c
	ccmd4/src/ccmd4.c
	ccmd5/src/ccmd5.c
)

SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}/darling")
SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE) 
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

add_library(corecrypto SHARED ${cc_sources})
install(TARGETS corecrypto DESTINATION ${CMAKE_INSTALL_LIBDIR}/darling)

