
message(STATUS "<NSurface::CheckDependencies> Start checking dependencies")



#####################################################################################
#   Main checkings
#####################################################################################
# check for ncpp
if(NOT TARGET ncpp)
    if(NOT EXISTS "${NSURFACE_SUBMODULES_DIR}/NCPP")
        if(WIN32)
            execute_process(COMMAND "${NSURFACE_SCRIPTS_DIR}/check_submodules.bat")
        elseif(UNIX)
            execute_process(COMMAND "${NSURFACE_SCRIPTS_DIR}/check_submodules.sh")
        endif()
    endif()    
endif()
# check for ntask_system
if(NOT TARGET ntask_system)
    if(NOT EXISTS "${NSURFACE_SUBMODULES_DIR}/NTaskSystem")
        if(WIN32)
            execute_process(COMMAND "${NSURFACE_SCRIPTS_DIR}/check_submodules.bat")
        elseif(UNIX)
            execute_process(COMMAND "${NSURFACE_SCRIPTS_DIR}/check_submodules.sh")
        endif()
    endif()    
endif()
# check for nevent
if(NOT TARGET nevent)
    if(NOT EXISTS "${NSURFACE_SUBMODULES_DIR}/NEvent")
        if(WIN32)
            execute_process(COMMAND "${NSURFACE_SCRIPTS_DIR}/check_submodules.bat")
        elseif(UNIX)
            execute_process(COMMAND "${NSURFACE_SCRIPTS_DIR}/check_submodules.sh")
        endif()
    endif()    
endif()



message(STATUS "<NSurface::CheckDependencies> Check dependencies done")