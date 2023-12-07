
message(STATUS "<NSurface::ConfigureDependencies> Start configuring dependencies")



#####################################################################################
#   Doxygen
#####################################################################################
find_package(Doxygen)



#####################################################################################
#   Add NMath subdirectory
#####################################################################################
if(NOT TARGET nmath)
    add_subdirectory("${NSURFACE_SUBMODULES_DIR}/NMath" "${NSURFACE_BINARY_DIR}/submodules/NMath")
endif()



message(STATUS "<NSurface::ConfigureDependencies> Configure dependencies done")