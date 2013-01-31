add_executable(cul_thread_test_exc cul_thread_test.cpp)
target_link_libraries(cul_thread_test_exc culio culsys cullog)
add_test(cul_thread_test ${EXECUTABLE_OUTPUT_PATH}/cul_thread_test_exc)

add_executable(cul_singleton_test_exc cul_singleton_test.cpp)
target_link_libraries(cul_singleton_test_exc culio culsys cullog)
add_test(cul_singleton_test ${EXECUTABLE_OUTPUT_PATH}/cul_singleton_test_exc)

add_executable(cul_string_test_exc cul_string_test.cpp)
target_link_libraries(cul_string_test_exc culio culsys cullog)
add_test(cul_string_test ${EXECUTABLE_OUTPUT_PATH}/cul_string_test_exc)

add_executable(cul_refptr_test_exc cul_refptr_test.cpp)
target_link_libraries(cul_refptr_test_exc culio culsys cullog)
add_test(cul_refptr_test ${EXECUTABLE_OUTPUT_PATH}/cul_refptr_test_exc)

add_executable(cul_delegate_test_exc cul_delegate_test.cpp)
target_link_libraries(cul_delegate_test_exc culio culsys cullog)
add_test(cul_delegate_test ${EXECUTABLE_OUTPUT_PATH}/cul_delegate_test_exc)

add_executable(cul_array_test_exc cul_array_test.cpp)
target_link_libraries(cul_array_test_exc culio culsys cullog)
add_test(cul_array_test ${EXECUTABLE_OUTPUT_PATH}/cul_array_test_exc)

add_executable(cul_console_test_exc cul_console_test.cpp)
target_link_libraries(cul_console_test_exc culio culsys cullog)
add_test(cul_console_test ${EXECUTABLE_OUTPUT_PATH}/cul_console_test_exc)

add_executable(cul_stack_test_exc cul_stack_test.cpp)
target_link_libraries(cul_stack_test_exc culio culsys cullog)
add_test(cul_stack_test ${EXECUTABLE_OUTPUT_PATH}/cul_stack_test_exc)

add_executable(cul_signal_test_exc cul_signal_test.cpp)
target_link_libraries(cul_signal_test_exc culio culsys cullog)
add_test(cul_signal_test ${EXECUTABLE_OUTPUT_PATH}/cul_signal_test_exc)

add_executable(cul_textfile_test_exc cul_textfile_test.cpp)
target_link_libraries(cul_textfile_test_exc culio culsys cullog)
add_test(cul_textfile_test ${EXECUTABLE_OUTPUT_PATH}/cul_textfile_test_exc)

add_executable(cul_convert_test_exc cul_convert_test.cpp)
target_link_libraries(cul_convert_test_exc culio culsys cullog)
add_test(cul_convert_test ${EXECUTABLE_OUTPUT_PATH}/cul_convert_test_exc)

add_executable(cul_list_test_exc cul_list_test.cpp)
target_link_libraries(cul_list_test_exc culio culsys cullog)
add_test(cul_list_test ${EXECUTABLE_OUTPUT_PATH}/cul_list_test_exc)

add_executable(cul_log_test_exc cul_log_test.cpp)
target_link_libraries(cul_log_test_exc culio culsys cullog)
add_test(cul_log_test ${EXECUTABLE_OUTPUT_PATH}/cul_log_test_exc)

