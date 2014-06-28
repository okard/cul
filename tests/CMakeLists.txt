
# tests
file(GLOB_RECURSE LIBCUL_TESTS *.cpp)
add_executable(libcul_tests EXCLUDE_FROM_ALL ${LIBCUL_TESTS})
target_link_libraries(libcul_tests culio cullog culsys)
add_custom_target(libcul_runtests COMMAND libcul_tests DEPENDS libcul_tests)




