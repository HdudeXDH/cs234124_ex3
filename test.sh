echo Begin testing

g++ --std=c++11 -o ex3_test -Wall -pedantic-errors -Werror -DNDEBUG *.cpp
valgrind --leak-check=full ./ex3_test

rm submission.zip
zip submission.zip Queue.h HealthPoints.h dry.pdf
~mtm/public/2122b/ex3/finalCheck submission.zip
