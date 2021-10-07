add_executable(u_test primitive_test.cpp)

target_include_directories(u_test PRIVATE ..)

target_link_libraries(u_test matrix_lib GTest::GTest GTest::Main)