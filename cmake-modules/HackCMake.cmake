
macro(__qc_compile_object input)
    set(compile_output ${target}.dir/${input}.o)
    if((${input} MATCHES ".*\.S$") OR (${input} MATCHES ".*\.asm$"))
        add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${compile_output}
                DEPENDS ${input}  ${qc_compiler}
                COMMAND $<TARGET_FILE:${qc_compiler}> --target ${SNESDEV_TARGET_NAME} $<TARGET_PROPERTY:${target},COMPILE_OPTIONS>
                 -c -o ${CMAKE_CURRENT_BINARY_DIR}/${compile_output} ${CMAKE_CURRENT_SOURCE_DIR}/${input} -I$<JOIN:$<TARGET_PROPERTY:${target},INCLUDE_DIRECTORIES>, -I>
                -D$<JOIN:$<TARGET_PROPERTY:${target},COMPILE_DEFINITIONS>, -D>
                )
        list(APPEND objs ${compile_output})
    elseif((${input} MATCHES ".*\.c$"))
        add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${compile_output}
                DEPENDS ${input} ${CMAKE_CURRENT_BINARY_DIR}/${qc_compiler}
                COMMAND $<TARGET_FILE:${qc_compiler}> --target ${SNESDEV_TARGET_NAME} $<TARGET_PROPERTY:${target},COMPILE_OPTIONS>
                -c -o ${compile_output} ${CMAKE_CURRENT_SOURCE_DIR}/${input} -I$<JOIN:$<TARGET_PROPERTY:${target},INCLUDE_DIRECTORIES>, -I>
                -D$<JOIN:$<TARGET_PROPERTY:${target},COMPILE_DEFINITIONS>, -D>
                -std=c$<TARGET_PROPERTY:${target},C_STANDARD>
                )
        list(APPEND objs ${compile_output})
    else()
        list(APPEND headers ${input})
    endif()
endmacro()

function(add_qc_library target)
    if(NOT DEFINED SNESDEV_BOOTSTRAP)
        add_library(${target} STATIC ${ARGN})
        install(TARGETS ${target} DESTINATION ${QC_INSTALL_ROOTDIR}/lib)
    else()
        set(output ${CMAKE_CURRENT_BINARY_DIR}/lib${target}.a)
        add_library(${target} STATIC IMPORTED GLOBAL)
        set(objs)
        set(headers)
        foreach(source ${ARGN})
            __qc_compile_object(${source})
        endforeach()
        set_target_properties(${target} PROPERTIES
                C_STANDARD ${CMAKE_C_STANDARD}
                IMPORTED_LOCATION ${output})
        set_property(TARGET ${target} PROPERTY PUBLIC_HEADERS ${headers})
        add_custom_command(OUTPUT ${output}
                DEPENDS ${objs}
                COMMAND ${CMAKE_AR} rsc ${output} ${objs}
                WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
        add_custom_target(${target}_archive DEPENDS ${output})
        add_dependencies(${target} ${target}_archvie ${src_targets})
        install(FILES ${output} DESTINATION ${QC_INSTALL_ROOTDIR}/lib)
    endif()
endfunction()