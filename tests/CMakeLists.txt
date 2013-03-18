add_executable(cul_thread_test_exc cul_thread_test.cpp)
target_link_libraries(cul_thread_test_exc culio culsys cullog)
get_target_property(cul_thread_test_loc cul_thread_test_exc LOCATION)
add_test(NAME cul_thread_test WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}" COMMAND "${cul_thread_test_loc}")

add_executable(cul_singleton_test_exc cul_singleton_test.cpp)
target_link_libraries(cul_singleton_test_exc culio culsys cullog)
get_target_property(cul_singleton_test_loc cul_singleton_test_exc LOCATION)
add_test(NAME cul_singleton_test WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}" COMMAND "${cul_singleton_test_loc}")

add_executable(cul_string_test_exc cul_string_test.cpp)
target_link_libraries(cul_string_test_exc culio culsys cullog)
get_target_property(cul_string_test_loc cul_string_test_exc LOCATION)
add_test(NAME cul_string_test WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}" COMMAND "${cul_string_test_loc}")

add_executable(cul_refptr_test_exc cul_refptr_test.cpp)
target_link_libraries(cul_refptr_test_exc culio culsys cullog)
get_target_property(cul_refptr_test_loc cul_refptr_test_exc LOCATION)
add_test(NAME cul_refptr_test WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}" COMMAND "${cul_refptr_test_loc}")

add_executable(cul_delegate_test_exc cul_delegate_test.cpp)
target_link_libraries(cul_delegate_test_exc culio culsys cullog)
get_target_property(cul_delegate_test_loc cul_delegate_test_exc LOCATION)
add_test(NAME cul_delegate_test WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}" COMMAND "${cul_delegate_test_loc}")

add_executable(cul_array_test_exc cul_array_test.cpp)
target_link_libraries(cul_array_test_exc culio culsys cullog)
get_target_property(cul_array_test_loc cul_array_test_exc LOCATION)
add_test(NAME cul_array_test WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}" COMMAND "${cul_array_test_loc}")

add_executable(cul_console_test_exc cul_console_test.cpp)
target_link_libraries(cul_console_test_exc culio culsys cullog)
get_target_property(cul_console_test_loc cul_console_test_exc LOCATION)
add_test(NAME cul_console_test WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}" COMMAND "${cul_console_test_loc}")

add_executable(cul_stack_test_exc cul_stack_test.cpp)
target_link_libraries(cul_stack_test_exc culio culsys cullog)
get_target_property(cul_stack_test_loc cul_stack_test_exc LOCATION)
add_test(NAME cul_stack_test WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}" COMMAND "${cul_stack_test_loc}")

add_executable(cul_signal_test_exc cul_signal_test.cpp)
target_link_libraries(cul_signal_test_exc culio culsys cullog)
get_target_property(cul_signal_test_loc cul_signal_test_exc LOCATION)
add_test(NAME cul_signal_test WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}" COMMAND "${cul_signal_test_loc}")

add_executable(cul_textfile_test_exc cul_textfile_test.cpp)
target_link_libraries(cul_textfile_test_exc culio culsys cullog)
get_target_property(cul_textfile_test_loc cul_textfile_test_exc LOCATION)
add_test(NAME cul_textfile_test WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}" COMMAND "${cul_textfile_test_loc}")

add_executable(cul_convert_test_exc cul_convert_test.cpp)
target_link_libraries(cul_convert_test_exc culio culsys cullog)
get_target_property(cul_convert_test_loc cul_convert_test_exc LOCATION)
add_test(NAME cul_convert_test WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}" COMMAND "${cul_convert_test_loc}")

add_executable(cul_list_test_exc cul_list_test.cpp)
target_link_libraries(cul_list_test_exc culio culsys cullog)
get_target_property(cul_list_test_loc cul_list_test_exc LOCATION)
add_test(NAME cul_list_test WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}" COMMAND "${cul_list_test_loc}")

add_executable(cul_log_test_exc cul_log_test.cpp)
target_link_libraries(cul_log_test_exc culio culsys cullog)
get_target_property(cul_log_test_loc cul_log_test_exc LOCATION)
add_test(NAME cul_log_test WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}" COMMAND "${cul_log_test_loc}")

