
message(STATUS "NRendering Check dependencies")

find_package(Doxygen REQUIRED)



if(NOT DEFINED NCPP_SOURCE_DIRECTORY)
set(NCPP_SOURCE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/ncpp)
endif()

if(NSURFACE_GENERATE_DOCS)
    set(NCPP_GENERATE_DOCS ON)
else()
    set(NCPP_GENERATE_DOCS OFF)
endif()

if(NOT DEFINED NCPP_ADDED)
set(NCPP_ADDED TRUE)
add_subdirectory(${NCPP_SOURCE_DIRECTORY})
endif()



message(STATUS "NRendering Check dependencies done")