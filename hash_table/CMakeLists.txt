set(TARGET_NAME hash_table)
set(TARGET_SRC_FILES src/OpenAddressHashmap.cpp)
set(TARGET_INCLUDE_DIR include/)

add_library(${TARGET_NAME} STATIC ${TARGET_SRC_FILES})
target_include_directories(${TARGET_NAME} PUBLIC ${TARGET_INCLUDE_DIR})
target_link_libraries(${TARGET_NAME} PRIVATE hashing)
