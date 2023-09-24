
message(STATUS "<NSurface::ConfigureDependencies> Start configuring dependencies")



#####################################################################################
#   Main configurating
#####################################################################################
find_package(Doxygen)

if(NOT TARGET ncpp)
    add_subdirectory("${NSURFACE_SUBMODULES_DIR}/ncpp" "${NSURFACE_BINARY_DIR}/submodules/ncpp")
endif()



message(STATUS "<NSurface::ConfigureDependencies> Configure dependencies done")