execute_process(
    #generate_sources_from_json  #name
    COMMAND "python3" "script.py"   #run command
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} #in what dir do i want to run it.
)


set (CAN_INCLUDE_DIR
            ${CMAKE_CURRENT_SOURCE_DIR}/output/include PARENT_SCOPE)
set (CAN_SOURCES
            ${CMAKE_CURRENT_SOURCE_DIR}/output/src/CAN_min_signals.cpp PARENT_SCOPE)

#add_custom_target


