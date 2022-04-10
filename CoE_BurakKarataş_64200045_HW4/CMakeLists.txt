cmake_minimum_required(VERSION 3.20)
project(hospital)

set(CMAKE_CXX_STANDARD 11)

add_executable(hospital Hospital.cpp Person.h Person.cpp Patient.h Patient.cpp Doctor.h Doctor.cpp)
