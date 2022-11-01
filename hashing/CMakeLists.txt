set(HASHING_SRC_FILES "")
set(HASHING_INCLUDE_DIR include/)

add_library(hashing INTERFACE)
target_include_directories(hashing INTERFACE ${HASHING_INCLUDE_DIR})
