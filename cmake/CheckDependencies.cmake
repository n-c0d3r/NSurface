
message(STATUS "NSurface Check dependencies")

find_package(Doxygen REQUIRED)



if(NSURFACE_GENERATE_DOCS)
    set(NCPP_GENERATE_DOCS ON)
else()
    set(NCPP_GENERATE_DOCS OFF)
endif()

if(NOT TARGET ncpp)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/dependencies/ncpp)
endif()



message(STATUS "NSurface Check dependencies done")