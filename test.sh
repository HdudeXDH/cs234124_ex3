echo Begin testing----------

make -f UnitTests/makefile && ./UnitTester && valgrind --leak-check=full ./UnitTester

g++ --std=c++11 -o ex3_test -Wall -pedantic-errors -Werror -DNDEBUG TestMain.cpp HealthPointsExampleTest.cpp HealthPoints.cpp QueueExampleTests.cpp
valgrind --leak-check=full ./ex3_test

rm submission.zip
zip submission.zip Queue.h HealthPoints.h HealthPoints.cpp dry.pdf
~mtm/public/2122b/ex3/finalCheck submission.zip