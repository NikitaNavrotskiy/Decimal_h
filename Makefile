CC=gcc
FLAGS=-Wall -Werror -Wextra --std=c11

SRC=my*.c
NAME=my_decimal

all : $(NAME).a

my_decimal.a :
	$(CC) $(FLAGS) -c $(SRC)
	ar rcs $(NAME).a *.o
	ranlib $(NAME).a
	rm -f *.o

test : clean
	$(CC) $(FLAGS) $(SRC) test/*.c -o decimal_test -lcheck -lm
	./decimal_test


clang : 
	clang-format -i *.c *.h test/*.c test/*.h

gcov_report : clean
	$(CC) $(FLAGS) --coverage $(SRC) test/*.c -o decimal_test -lcheck -lm
	./decimal_test
	lcov -t "decimal_test" -o decimal_gcov.info -c -d .
	genhtml -o report decimal_gcov.info
	open report/index.html
	google-chrome report/index.html


clean : 
	rm -f $(NAME).a
	rm -f *.o
	rm -f decimal_test
	rm -f *.gc*
	rm -f decimal_test* decimal_gcov.info
	rm -rf report
