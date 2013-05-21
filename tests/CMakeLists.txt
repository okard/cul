add_executable(culcore_refptr_test_exc culcore_refptr_test.cpp)
target_link_libraries(culcore_refptr_test_exc culio culsys cullog)
get_target_property(culcore_refptr_test_loc culcore_refptr_test_exc LOCATION)
add_test(NAME culcore_refptr_test WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}" COMMAND "${culcore_refptr_test_loc}")

add_executable(culio_buffer_test_exc culio_buffer_test.cpp)
target_link_libraries(culio_buffer_test_exc culio culsys cullog)
get_target_property(culio_buffer_test_loc culio_buffer_test_exc LOCATION)
add_test(NAME culio_buffer_test WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}" COMMAND "${culio_buffer_test_loc}")

add_executable(culio_console_test_exc culio_console_test.cpp)
target_link_libraries(culio_console_test_exc culio culsys cullog)
get_target_property(culio_console_test_loc culio_console_test_exc LOCATION)
add_test(NAME culio_console_test WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}" COMMAND "${culio_console_test_loc}")

add_executable(cullog_log_test_exc cullog_log_test.cpp)
target_link_libraries(cullog_log_test_exc culio culsys cullog)
get_target_property(cullog_log_test_loc cullog_log_test_exc LOCATION)
add_test(NAME cullog_log_test WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}" COMMAND "${cullog_log_test_loc}")

add_executable(culcore_stack_test_exc culcore_stack_test.cpp)
target_link_libraries(culcore_stack_test_exc culio culsys cullog)
get_target_property(culcore_stack_test_loc culcore_stack_test_exc LOCATION)
add_test(NAME culcore_stack_test WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}" COMMAND "${culcore_stack_test_loc}")

add_executable(culio_convert_test_exc culio_convert_test.cpp)
target_link_libraries(culio_convert_test_exc culio culsys cullog)
get_target_property(culio_convert_test_loc culio_convert_test_exc LOCATION)
add_test(NAME culio_convert_test WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}" COMMAND "${culio_convert_test_loc}")

add_executable(culio_filestream_test_exc culio_filestream_test.cpp)
target_link_libraries(culio_filestream_test_exc culio culsys cullog)
get_target_property(culio_filestream_test_loc culio_filestream_test_exc LOCATION)
add_test(NAME culio_filestream_test WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}" COMMAND "${culio_filestream_test_loc}")

add_executable(culcore_list_test_exc culcore_list_test.cpp)
target_link_libraries(culcore_list_test_exc culio culsys cullog)
get_target_property(culcore_list_test_loc culcore_list_test_exc LOCATION)
add_test(NAME culcore_list_test WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}" COMMAND "${culcore_list_test_loc}")

add_executable(culsys_thread_test_exc culsys_thread_test.cpp)
target_link_libraries(culsys_thread_test_exc culio culsys cullog)
get_target_property(culsys_thread_test_loc culsys_thread_test_exc LOCATION)
add_test(NAME culsys_thread_test WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}" COMMAND "${culsys_thread_test_loc}")

add_executable(culcore_hash_test_exc culcore_hash_test.cpp)
target_link_libraries(culcore_hash_test_exc culio culsys cullog)
get_target_property(culcore_hash_test_loc culcore_hash_test_exc LOCATION)
add_test(NAME culcore_hash_test WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}" COMMAND "${culcore_hash_test_loc}")

add_executable(culio_string_test_exc culio_string_test.cpp)
target_link_libraries(culio_string_test_exc culio culsys cullog)
get_target_property(culio_string_test_loc culio_string_test_exc LOCATION)
add_test(NAME culio_string_test WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}" COMMAND "${culio_string_test_loc}")

add_executable(culio_textfile_test_exc culio_textfile_test.cpp)
target_link_libraries(culio_textfile_test_exc culio culsys cullog)
get_target_property(culio_textfile_test_loc culio_textfile_test_exc LOCATION)
add_test(NAME culio_textfile_test WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}" COMMAND "${culio_textfile_test_loc}")

add_executable(culcore_singleton_test_exc culcore_singleton_test.cpp)
target_link_libraries(culcore_singleton_test_exc culio culsys cullog)
get_target_property(culcore_singleton_test_loc culcore_singleton_test_exc LOCATION)
add_test(NAME culcore_singleton_test WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}" COMMAND "${culcore_singleton_test_loc}")

add_executable(culcore_signal_test_exc culcore_signal_test.cpp)
target_link_libraries(culcore_signal_test_exc culio culsys cullog)
get_target_property(culcore_signal_test_loc culcore_signal_test_exc LOCATION)
add_test(NAME culcore_signal_test WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}" COMMAND "${culcore_signal_test_loc}")

add_executable(culcore_array_test_exc culcore_array_test.cpp)
target_link_libraries(culcore_array_test_exc culio culsys cullog)
get_target_property(culcore_array_test_loc culcore_array_test_exc LOCATION)
add_test(NAME culcore_array_test WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}" COMMAND "${culcore_array_test_loc}")

add_executable(culcore_delegate_test_exc culcore_delegate_test.cpp)
target_link_libraries(culcore_delegate_test_exc culio culsys cullog)
get_target_property(culcore_delegate_test_loc culcore_delegate_test_exc LOCATION)
add_test(NAME culcore_delegate_test WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}" COMMAND "${culcore_delegate_test_loc}")

