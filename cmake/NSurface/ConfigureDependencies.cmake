
message(STATUS "<NSURFACE::Dependencies> Start configuring dependencies")

message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})
if(NOT TARGET ncpp)
    add_subdirectory("${NSURFACE_SUBMODULES_DIR}/ncpp" "${NSURFACE_BINARY_DIR}/submodules/ncpp")
endif()

message(STATUS "<NSURFACE::Dependencies> Configure dependencies done")