set(TARGET_NAME counter)
set(TARGET_SRC_FILES src/Counter.cpp)
set(TARGET_INCLUDE_DIR include/)

add_library(${TARGET_NAME} STATIC ${TARGET_SRC_FILES})
target_include_directories(${TARGET_NAME} PUBLIC ${TARGET_INCLUDE_DIR})
target_link_libraries(${TARGET_NAME} PRIVATE hashing)
