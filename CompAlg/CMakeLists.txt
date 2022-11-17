cmake_minimum_required(VERSION 3.21)
project(CompAlg)

set(CMAKE_CXX_STANDARD 23)

add_executable(CompAlg main.cpp Z.cpp Z.h gcd.cpp gcd.h Polynomial.cpp Polynomial.h FactorRing.cpp FactorRing.h)
