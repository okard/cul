
###############################################################################
# C++ Utility Library
# Test Project
###############################################################################
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(cul-tests)

#refptr test
add_executable(refptr_test_exc refptr_test.cpp)
add_test(refptr_test ${EXECUTABLE_OUTPUT_PATH}/refptr_test_exc)

#singleton test
add_executable(singleton_test_exc singleton_test.cpp)
add_test(singleton_test ${EXECUTABLE_OUTPUT_PATH}/singleton_test_exc)

#string test
add_executable(string_test_exc string_test.cpp)
target_link_libraries(string_test_exc culio)
add_test(string_test ${EXECUTABLE_OUTPUT_PATH}/string_test_exc)

#textfile test
add_executable(textfile_test_exc textfile_test.cpp)
target_link_libraries(textfile_test_exc culio)
add_test(textfile_test ${EXECUTABLE_OUTPUT_PATH}/textfile_test_exc ${CMAKE_CURRENT_SOURCE_DIR}/utf8_file_bom.txt)

#console test
add_executable(console_test_exc console_test.cpp)
target_link_libraries(console_test_exc culio)
add_test(console_test ${EXECUTABLE_OUTPUT_PATH}/console_test_exc)

#log test
add_executable(logging_test_exc logging_test.cpp)
target_link_libraries(logging_test_exc cullog)
add_test(logging_test ${EXECUTABLE_OUTPUT_PATH}/logging_test_exc)

#thread test
add_executable(thread_test_exc thread_test.cpp)
target_link_libraries(thread_test_exc culsys)
add_test(thread_test ${EXECUTABLE_OUTPUT_PATH}/thread_test_exc)

#list test
#add_executable(list_test_exc list_test.cpp)
#add_test(list_test ${EXECUTABLE_OUTPUT_PATH}/list_test_exc)

#cul stack test
#add_executable(cul_stack_test_exc cul_stack_test.cpp)
#add_test(cul_stack_test ${EXECUTABLE_OUTPUT_PATH}/cul_stack_test_exc)

#cul delegate test
add_executable(cul_delegate_test_exc cul_delegate_test.cpp)
add_test(cul_delegate_test ${EXECUTABLE_OUTPUT_PATH}/cul_delegate_test_exc)

#cul signal test
add_executable(cul_signal_test_exc cul_signal_test.cpp)
add_test(cul_signal_test ${EXECUTABLE_OUTPUT_PATH}/cul_signal_test_exc)

#cul convert test
add_executable(cul_convert_test_exc cul_convert_test.cpp)
target_link_libraries(cul_convert_test_exc culio)
add_test(cul_convert_test ${EXECUTABLE_OUTPUT_PATH}/cul_convert_test_exc)

