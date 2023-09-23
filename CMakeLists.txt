cmake_minimum_required(VERSION 3.12)



project(nsurface)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)



set(NSURFACE_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(NSURFACE_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(NSURFACE_SCRIPTS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/scripts")
set(NSURFACE_SUBMODULES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/submodules")
set(NSURFACE_CMAKE_MODULE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/cmake")



set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(NSurface/Version)

include(NSurface/CheckDependencies)
include(NSurface/ConfigureDependencies)

#Documentations
# option(NSURFACE_ENABLE_DOCUMENTATIONS "If enabled, creating a target being capable of generating documentations" OFF)
# if(NSURFACE_ENABLE_DOCUMENTATIONS)
#     option(NSURFACE_INTERNAL_DOCS "Generate docs for anything" OFF)

#     include(DocsUtils)

#     DocsUtils_CreateTarget(
#         NAME NSURFACE
#         BRIEF "Ncoder's Game Engine Learning Aimed C++ Library."

#         TARGET_NAME nsurface.documentations
#         TARGET_FOLDER nsurface
#         TARGET_LABEL documentations

#         INPUT_DIRS 
#             "${CMAKE_CURRENT_SOURCE_DIR}/nsurface/source"
#             "${CMAKE_CURRENT_SOURCE_DIR}/documentations"
#             "${CMAKE_CURRENT_SOURCE_DIR}/README.md"
#         STYLE_DIRS
#             "${CMAKE_CURRENT_SOURCE_DIR}/documentations/styles"
#         OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/documentations"
#         CWD "${CMAKE_CURRENT_SOURCE_DIR}"
#         INTERNAL_DOCS ${NSURFACE_INTERNAL_DOCS}

#         PREDEFINED
#             NCPP_WINDOWS_PLATFORM
#             NCPP_UNIX_PLATFORM

#         MAIN_PAGE "${CMAKE_CURRENT_SOURCE_DIR}/README.md"
#     )
# endif()



add_subdirectory(nsurface)



include(CPack)