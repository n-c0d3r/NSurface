
message(STATUS "<NSurface::ConfigureNCPP> Start configuring NCPP")



#####################################################################################
#   Add NCPP subdirectory
#####################################################################################
if(NOT TARGET ncpp)
    add_subdirectory("${NSURFACE_SUBMODULES_DIR}/NCPP" "${NSURFACE_BINARY_DIR}/submodules/NCPP")
endif()



#####################################################################################
#   NCPP cmake module path
#####################################################################################
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${NCPP_CMAKE_MODULE_DIR}")



message(STATUS "<NSurface::ConfigureNCPP> Configure NCPP done")