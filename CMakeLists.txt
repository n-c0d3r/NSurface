cmake_minimum_required(VERSION 3.12)



#####################################################################################
#   Project NSurface
#####################################################################################
project(nsurface)



#####################################################################################
#   CMake module
#####################################################################################
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/cmake")



#####################################################################################
#   Local variables
#####################################################################################
set(NSURFACE_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(NSURFACE_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(NSURFACE_SCRIPTS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/scripts")
set(NSURFACE_SUBMODULES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/submodules")
set(NSURFACE_CMAKE_MODULE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/cmake")



#####################################################################################
#   Dependencies
#####################################################################################
include(NSurface/CheckDependencies)
include(NSurface/ConfigureDependencies)



#####################################################################################
#   NCPP cmake module path
#####################################################################################
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${NCPP_CMAKE_MODULE_DIR}")



#####################################################################################
#   Version
#####################################################################################
include(NSurface/Version)



#####################################################################################
#   Global variables
#####################################################################################
include(NCPP/ApplyGlobal)
NCPP_ApplyGlobal(
    NSURFACE_ROOT_DIR
    NSURFACE_BINARY_DIR
    NSURFACE_SCRIPTS_DIR
    NSURFACE_SUBMODULES_DIR
    NSURFACE_CMAKE_MODULE_DIR 
)



#####################################################################################
#   Documentations
#####################################################################################
option(NSURFACE_ENABLE_DOCUMENTATIONS "If enabled, creating a target being capable of generating documentations" OFF)
if(NSURFACE_ENABLE_DOCUMENTATIONS)
    option(NSURFACE_INTERNAL_DOCS "Generate docs for anything" OFF)

    include(NCPP/DocsUtils)

    NCPP_DocsUtils_CreateTarget(
        NAME NSurface
        BRIEF "Ncoder's Learning Aimed C++ Surface Library."

        TARGET_NAME nsurface.documentations
        TARGET_FOLDER nsurface
        TARGET_LABEL documentations

        INPUT_DIRS 
            "${CMAKE_CURRENT_SOURCE_DIR}/nsurface/source"
            "${CMAKE_CURRENT_SOURCE_DIR}/documentations"
            "${CMAKE_CURRENT_SOURCE_DIR}/README.md"
        STYLE_DIRS
            "${CMAKE_CURRENT_SOURCE_DIR}/documentations/styles"
        OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/documentations"
        CWD "${CMAKE_CURRENT_SOURCE_DIR}"
        INTERNAL_DOCS ${NSURFACE_INTERNAL_DOCS}

        PREDEFINED 
            ${NCPP_DOCUMENTATIONS_PREDEFINED}

        MAIN_PAGE "${CMAKE_CURRENT_SOURCE_DIR}/README.md"
    )
endif()



#####################################################################################
#   Add main directory
#####################################################################################
add_subdirectory(nsurface)



include(CPack)