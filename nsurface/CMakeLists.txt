
#####################################################################################
#   Includes
#####################################################################################
include(NCPP/ConfigureCompiler)



#####################################################################################
#   Generated files
#####################################################################################
# nsurface target configure file
configure_file(source/nsurface/.config "${NSURFACE_GENERATED_FILES_DIR}/config.hpp")



#####################################################################################
#   nsurface target's files
#####################################################################################
set(NSURFACE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/source" PARENT_SCOPE)

# nsurface target source files
file(GLOB_RECURSE source_files
    "source/*.cpp"
    "source/*.hpp"

    "source/*.mm"
    "source/*.h"
)

# Exclude the windows platform files from the list if not using windows
if(NOT WIN32)
    list(FILTER source_files EXCLUDE REGEX "source/nsurface/windows/*.*")
endif()

# Exclude the apple platform files from the list if not using apple platforms
if(NOT APPLE)
    list(FILTER source_files EXCLUDE REGEX "source/nsurface/macos/*.*")
endif()

# Exclude the posix platform files from the list if not using posix
if(NOT UNIX)
    list(FILTER source_files EXCLUDE REGEX "source/nsurface/posix/*.*")
endif()

# create source group
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/source PREFIX source FILES ${source_files})

file(GLOB_RECURSE generated_files
    "${CMAKE_CURRENT_BINARY_DIR}/generated_files/*.cpp"
    "${CMAKE_CURRENT_BINARY_DIR}/generated_files/*.hpp"
)
source_group(TREE "${CMAKE_CURRENT_BINARY_DIR}/generated_files" PREFIX generated_files FILES ${generated_files})



#####################################################################################
#   Create nsurface target
#####################################################################################
add_library(nsurface STATIC
    ${source_files}
    ${generated_files}
)



#####################################################################################
#   nsurface target settings
#####################################################################################
set_target_properties(nsurface
    PROPERTIES 
        FOLDER "nsurface"
)

target_include_directories(nsurface
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/source
        ${CMAKE_CURRENT_BINARY_DIR}/generated_files
)

target_precompile_headers(nsurface
    PRIVATE
        source/nsurface/prerequisites.hpp
)

target_link_libraries(nsurface
    PUBLIC
        ncpp
)

# MSVC compile options
if(MSVC)
  target_compile_options(nsurface PUBLIC /GT)
endif()

# MacOS libs
if(APPLE)
    # Find the Cocoa lib
    find_library(COCOA_LIBRARY Cocoa)
    if (NOT COCOA_LIBRARY)
        message(FATAL_ERROR "Cocoa not found")
    endif()
 
    target_link_libraries(nsurface
        PRIVATE
            ${COCOA_LIBRARY}
    )
endif()



#####################################################################################
#   Dependencies
#####################################################################################
add_dependencies(nsurface ncpp)



#####################################################################################
#   Add dependencies
#####################################################################################
add_subdirectory(samples)



