
message(STATUS "<NSURFACE::Dependencies> Start configuring dependencies")



#####################################################################################
#   Main configurating
#####################################################################################
find_package(Doxygen)

if(NOT TARGET ncpp)
    add_subdirectory("${NSURFACE_SUBMODULES_DIR}/ncpp" "${NSURFACE_BINARY_DIR}/submodules/ncpp")
endif()



message(STATUS "<NSURFACE::Dependencies> Configure dependencies done")