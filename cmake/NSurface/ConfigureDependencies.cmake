
message(STATUS "<NSurface::ConfigureDependencies> Start configuring dependencies")



#####################################################################################
#   Main configurating
#####################################################################################
find_package(Doxygen)

if(NOT TARGET ncpp)
    add_subdirectory("${NSURFACE_SUBMODULES_DIR}/NCPP" "${NSURFACE_BINARY_DIR}/submodules/NCPP")
endif()

if(NOT TARGET ntask_system)
    add_subdirectory("${NSURFACE_SUBMODULES_DIR}/NTaskSystem" "${NSURFACE_BINARY_DIR}/submodules/NTaskSystem")
endif()

if(NOT TARGET nevent)
    add_subdirectory("${NSURFACE_SUBMODULES_DIR}/NEvent" "${NSURFACE_BINARY_DIR}/submodules/NEvent")
endif()



message(STATUS "<NSurface::ConfigureDependencies> Configure dependencies done")