
message(STATUS "Generate docs")



set(OUTPUT_DOCUMENTATIONS_DIR "${CMAKE_CURRENT_BINARY_DIR}/documentations")
set(OUTPUT_EXTERNAL_DOCUMENTATIONS_DIR "${OUTPUT_DOCUMENTATIONS_DIR}/external")
set(OUTPUT_INTERNAL_DOCUMENTATIONS_DIR "${OUTPUT_DOCUMENTATIONS_DIR}/internal")

if(NOT EXISTS ${OUTPUT_EXTERNAL_DOCUMENTATIONS_DIR})
    file(MAKE_DIRECTORY ${OUTPUT_EXTERNAL_DOCUMENTATIONS_DIR})
endif()

if(NOT EXISTS ${OUTPUT_INTERNAL_DOCUMENTATIONS_DIR})
    file(MAKE_DIRECTORY ${OUTPUT_INTERNAL_DOCUMENTATIONS_DIR})
endif()



set(DOCUMENTATIONS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/documentations")
set(EXTERNAL_DOCUMENTATIONS_DIR "${DOCUMENTATIONS_DIR}/external")
set(INTERNAL_DOCUMENTATIONS_DIR "${DOCUMENTATIONS_DIR}/internal")

set(MARKDOWN_DOCUMENTATIONS_DIR "${DOCUMENTATIONS_DIR}/doxygen_markdown")



file(
    COPY 
    "${DOCUMENTATIONS_DIR}/doxygen_themes"
    DESTINATION "${OUTPUT_DOCUMENTATIONS_DIR}"
)



function(NRENDERINGGenerateDocs docs_dir output_dir)
    set(DOXYFILE_TEMPLATE "${docs_dir}/Doxyfile.template")
    set(OUTPUT_DOXYFILE "${output_dir}/Doxyfile")
    file(READ ${DOXYFILE_TEMPLATE} DOXYFILE_TEMPLATE_CONTENT)
    string(
        REPLACE
        "OUTPUT_DIRECTORY       ="
        "OUTPUT_DIRECTORY       = ${output_dir}/NRENDERING"
        DOXYFILE_TEMPLATE_CONTENT
        ${DOXYFILE_TEMPLATE_CONTENT}
    )
    string(
        REPLACE
        "INPUT                  ="
        "INPUT                  = ${MARKDOWN_DOCUMENTATIONS_DIR}
        INPUT += ${SOURCE_DIR}
        FILE_PATTERNS += *.md *.markdown
        MARKDOWN_SUPPORT = YES
        TAB_SIZE = 2
        USE_MDFILE_AS_MAINPAGE = ${MARKDOWN_DOCUMENTATIONS_DIR}/Overview.md
        "
        DOXYFILE_TEMPLATE_CONTENT
        ${DOXYFILE_TEMPLATE_CONTENT}
    )
    file(WRITE ${OUTPUT_DOXYFILE} ${DOXYFILE_TEMPLATE_CONTENT})    
    
    execute_process(
        COMMAND ${DOXYGEN_EXECUTABLE}
        WORKING_DIRECTORY ${output_dir}
    )

endfunction()



message(STATUS "Generate external docs")
NRENDERINGGenerateDocs(
    ${EXTERNAL_DOCUMENTATIONS_DIR}
    ${OUTPUT_EXTERNAL_DOCUMENTATIONS_DIR}
)
message(STATUS "Generate external docs done")

message(STATUS "Generate internal docs")
NRENDERINGGenerateDocs(
    ${INTERNAL_DOCUMENTATIONS_DIR}
    ${OUTPUT_INTERNAL_DOCUMENTATIONS_DIR}
)
message(STATUS "Generate internal docs done")



message(STATUS "Generate docs done")