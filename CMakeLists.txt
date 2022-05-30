cmake_minimum_required(VERSION 3.21)
project(ex3)

set(CMAKE_CXX_STANDARD 14)

#add_executable(ex3 TestMain.cpp HealthPointsExampleTest.cpp HealthPoints.cpp QueueExampleTests.cpp)
add_executable(ex3 HealthPoints.cpp UnitTests/UnitTestsMain.cpp UnitTests/QueueUnitTests.cpp UnitTests/HealthPointsUnitTests.cpp HealthPoints.h Queue.h UnitTests/catch.hpp UnitTests/relativeIncludes.h)
#add_executable(ex3 hpTest.cpp HealthPoints.cpp)
