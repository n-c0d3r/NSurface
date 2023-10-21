
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
)

# Remove the posix platform files from the list if using windows
if(WIN32)
list(FILTER source_files EXCLUDE REGEX "source/nsurface/posix/*.*")
endif(WIN32)

# Remove the windows platform files from the list if using unix
if(UNIX)
list(FILTER source_files EXCLUDE REGEX "source/nsurface/windows/*.*")
endif(UNIX)

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
target_link_libraries(nsurface
    PUBLIC 
        ncpp
)
target_include_directories(nsurface
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/source
        ${CMAKE_CURRENT_BINARY_DIR}/generated_files
)

# MSVC compile options
if(MSVC)
  target_compile_options(nsurface PUBLIC /GT)
endif()



#####################################################################################
#   Dependencies
#####################################################################################
add_dependencies(nsurface ncpp)



#####################################################################################
#   Add dependencies
#####################################################################################
add_subdirectory(samples)



