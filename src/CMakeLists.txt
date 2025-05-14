cmake_minimum_required(VERSION 3.16)
project(AlDenteAmore)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

include_directories(${CMAKE_SOURCE_DIR}/lib)
link_directories(${LIBRARY_OUTPUT_PATH})

add_executable(AlDenteAmore
    main.cpp
    User.cpp
    Date.cpp
    Goods.cpp
    Customer.cpp
    Ingredient.cpp
    AdminStatus.cpp
    AdminLogistics.cpp
    IngredientStock.cpp
    Facts.cpp
    Path.cpp
)
