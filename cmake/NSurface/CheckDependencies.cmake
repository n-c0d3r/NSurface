
message(STATUS "<NSurface::CheckDependencies> Start checking dependencies")



#####################################################################################
#   Includes
#####################################################################################
include(NCPP/GitUtils)



#####################################################################################
#   Setup directory for dependencies to be downloaded into
#####################################################################################
if(NOT EXISTS ${NSURFACE_DEPENDENCIES_DIR})
    file(MAKE_DIRECTORY ${NSURFACE_DEPENDENCIES_DIR})
endif()



message(STATUS "<NSurface::CheckDependencies> Check dependencies done")