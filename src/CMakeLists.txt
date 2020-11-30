add_executable(${PROJECT_NAME} "")
target_sources(${PROJECT_NAME} PRIVATE main.cpp matrix.cpp matrix_iterator.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/src")
