cmake_minimum_required(VERSION 3.16)
project(AlDenteAmore)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

add_subdirectory(googletest)
add_subdirectory(src)

include_directories(${CMAKE_SOURCE_DIR}/lib)
link_directories(${LIBRARY_OUTPUT_PATH})

add_executable(AdminTests
    tests/AdminTests.cpp
    src/User.cpp
    src/IngredientStock.cpp
    src/Date.cpp
    src/Ingredient.cpp
    src/AdminLogistics.cpp
    src/AdminStatus.cpp
    src/Facts.cpp
    src/Path.cpp
)

add_executable(CustomerTests
    tests/CustomerTests.cpp
    src/User.cpp
    src/Ingredient.cpp
    src/IngredientStock.cpp
    src/Goods.cpp
    src/Customer.cpp
    src/Date.cpp
    src/Facts.cpp
    src/Path.cpp
)

add_executable(IngredientStockTests
    tests/IngredientStockTests.cpp
    src/Ingredient.cpp
    src/IngredientStock.cpp
    src/Date.cpp
    src/Facts.cpp
    src/Path.cpp
)

add_executable(IngredientTests
    tests/IngredientTests.cpp
    src/Ingredient.cpp
    src/Date.cpp
    src/Facts.cpp
    src/Path.cpp
)

add_executable(DateTests
    tests/DateTests.cpp
    src/Date.cpp
    src/Path.cpp
)

target_link_libraries(AdminTests gtest gtest_main)
target_link_libraries(CustomerTests gtest gtest_main)
target_link_libraries(IngredientTests gtest gtest_main)
target_link_libraries(IngredientStockTests gtest gtest_main)
target_link_libraries(DateTests gtest gtest_main)