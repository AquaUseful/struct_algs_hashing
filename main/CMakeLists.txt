set(MAIN_SRC_FILES src/main.cpp)
#set(MAIN_INCLUDE_DIR include/)

add_executable(main ${MAIN_SRC_FILES})
#include_directories(main ${MAIN_INCLUDE_DIR})

target_link_libraries(main PRIVATE form)
target_link_libraries(main PRIVATE hash_table)
