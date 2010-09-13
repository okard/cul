
#refptr test
add_executable(refptr_test_exc refptr_test.cpp)
add_test(refptr_test ${EXECUTABLE_OUTPUT_PATH}/refptr_test_exc)

#singleton test
add_executable(singleton_test_exc singleton_test.cpp)
add_test(singleton_test ${EXECUTABLE_OUTPUT_PATH}/singleton_test_exc)

#string test
add_executable(string_test_exc string_test.cpp)
target_link_libraries(string_test_exc cul)
add_test(string_test ${EXECUTABLE_OUTPUT_PATH}/string_test_exc)

#textfile test
add_executable(textfile_test_exc textfile_test.cpp)
target_link_libraries(textfile_test_exc cul)
add_test(textfile_test ${EXECUTABLE_OUTPUT_PATH}/textfile_test_exc ${CMAKE_CURRENT_SOURCE_DIR}/utf8_file_bom.txt)
