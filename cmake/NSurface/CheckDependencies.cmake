
message(STATUS "<NSURFACE::Dependencies> Start checking dependencies")

# setup ncpp cmake modules
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_LIST_DIR}")

if(NOT TARGET ncpp)
    if(NOT EXISTS "${NSURFACE_SUBMODULES_DIR}/ncpp")
        if(WIN32)
            execute_process(COMMAND "${NSURFACE_SCRIPTS_DIR}/check_submodules.bat")
        elseif(UNIX)
            execute_process(COMMAND "${NSURFACE_SCRIPTS_DIR}/check_submodules.sh")
        endif()
    endif()    
endif()

message(STATUS "<NSURFACE::Dependencies> Check dependencies done")