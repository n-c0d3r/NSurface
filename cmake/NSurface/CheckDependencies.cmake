
message(STATUS "<NSurface::CheckDependencies> Start checking dependencies")



#####################################################################################
#   Main checkings
#####################################################################################
# check for ncpp
if(NOT TARGET ncpp)
    if(NOT EXISTS "${NSURFACE_SUBMODULES_DIR}/ncpp")
        if(WIN32)
            execute_process(COMMAND "${NSURFACE_SCRIPTS_DIR}/check_submodules.bat")
        elseif(UNIX)
            execute_process(COMMAND "${NSURFACE_SCRIPTS_DIR}/check_submodules.sh")
        endif()
    endif()    
endif()



message(STATUS "<NSurface::CheckDependencies> Check dependencies done")