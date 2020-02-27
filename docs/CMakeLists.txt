#
# This file is part of VERILOG_TEMPLATE.
#

###########################
# Build stddoc executable #
###########################
list(APPEND STDDOC_SOURCES stddoc.c)

add_executable(stddoc ${STDDOC_SOURCES})

########################################
# Use stddoc to generate documentation #
########################################
foreach(MODULE ${VERILOG_AUTODOC})
    string(REPLACE ".v" "" MODULE_NAME ${MODULE})
    add_custom_command(OUTPUT "${MODULE_NAME}.html"
        COMMAND stddoc < "rtl/${MODULE}" > "docs/${MODULE_NAME}.html"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        DEPENDS stddoc
        COMMENT "Creating docs/${MODULE_NAME}.html"
    )
    add_custom_target(doc_${MODULE_NAME} ALL
        DEPENDS "${MODULE_NAME}.html"
        VERBATIM
    )
endforeach()
