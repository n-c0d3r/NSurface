cmake_minimum_required(VERSION 3.12)



set(NPROJECT_NAME_UPPERCASE NSURFACE)
set(NPROJECT_NAME_LOWERCASE nsurface)



project(${NPROJECT_NAME_LOWERCASE})

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)



set(${NPROJECT_NAME_UPPERCASE}_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")



include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/CheckDependencies.cmake)



option(${NPROJECT_NAME_UPPERCASE}_GENERATE_DOCS "Generate External And Internal Docs" ON)
if(${${NPROJECT_NAME_UPPERCASE}_GENERATE_DOCS})
    include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/GenerateDocs.cmake)
endif()



include(CPack)