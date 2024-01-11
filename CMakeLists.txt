cmake_minimum_required(VERSION 3.0)
project(untitled)

set(CMAKE_CXX_STANDARD 14)
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:/SFML-2.6.1/lib/cmake/SFML")

find_package(SFML 2.6 COMPONENTS graphics audio REQUIRED)

add_executable(untitled main.cpp matrix/Matrix.cpp network/NeuralNetwork.cpp network/NeuralNetwork.h network/Layer.cpp network/Layer.h network/ActivationFunctionSchema.h)
target_link_libraries(untitled sfml-graphics sfml-window sfml-system)