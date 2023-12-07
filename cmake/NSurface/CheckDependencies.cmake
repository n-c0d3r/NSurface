
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



#####################################################################################
#   NMath checking
#####################################################################################
if(NOT TARGET nmath)
    if(NOT EXISTS "${NSURFACE_SUBMODULES_DIR}/NMath")
        if(WIN32)
            execute_process(COMMAND "${NSURFACE_SCRIPTS_DIR}/check_submodules.bat")
        elseif(UNIX)
            execute_process(COMMAND "${NSURFACE_SCRIPTS_DIR}/check_submodules.sh")
        endif()
    endif()    
endif()



message(STATUS "<NSurface::CheckDependencies> Check dependencies done")