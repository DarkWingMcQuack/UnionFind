set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# needed for multithreading
find_package(Threads REQUIRED)

add_executable(unit_tests
  main.cpp
  tests.cpp
  )

target_link_libraries(unit_tests LINK_PRIVATE
  gtest
  ${CMAKE_THREAD_LIBS_INIT})

target_include_directories(
  unit_tests PUBLIC
  gtest
  ${NAMEDTYPE_INCLUDE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/../include
  )

add_test(
  NAME unit_tests
  COMMAND
  ${CMAKE_BINARY_DIR}/test/unit_tests
  )


add_dependencies(unit_tests gtest-project)
