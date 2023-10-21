
# nsurface.samples.hello_nsurface target source files
file(GLOB source_files
    "source/*.cpp"
    "source/*.hpp"
)
source_group("source" FILES ${source_files})



# Create nsurface.samples.hello_nsurface target
add_executable(nsurface.samples.hello_nsurface
    ${source_files}
)



# nsurface.samples.hello_nsurface target settings
set_target_properties(nsurface.samples.hello_nsurface
    PROPERTIES 
        FOLDER "nsurface/samples"
        PROJECT_LABEL "hello_nsurface"
)
target_link_libraries(nsurface.samples.hello_nsurface
    PUBLIC 
        nsurface
)
target_include_directories(nsurface.samples.hello_nsurface
    PUBLIC 
        nsurface
        ${CMAKE_CURRENT_SOURCE_DIR}/source
)



# nsurface.samples.hello_nsurface target dependencies
add_dependencies(nsurface.samples.hello_nsurface 
    nsurface
)