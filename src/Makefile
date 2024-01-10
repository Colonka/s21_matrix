ifeq ($(shell uname -s),Linux)
    CHECK_FLAGS = -lcheck -lrt -lsubunit -lm -lpthread
endif
ifeq ($(shell uname -s),Darwin)
    CHECK_FLAGS = $(shell pkg-config --libs check --cflags)
endif

CC = gcc
FLAGS= -Wall -Wextra -Werror -std=c11 -g
GCOV_FLAGS = -fprofile-arcs -ftest-coverage

PREF_BIN = ./binary/
PREF_SRC = ./source/

SRC = $(wildcard $(PREF_SRC)*.c)
OBJS = $(patsubst $(PREF_SRC)%.c, $(PREF_BIN)%.o, $(SRC))

all: s21_matrix.a

style:
	clang-format -i -style=google *.c
	clang-format -style=google -n *.c

s21_matrix.a: $(OBJS)
	ar rc libs21_matrix.a $(OBJS)
	ranlib libs21_matrix.a

$(PREF_BIN)%.o: $(PREF_SRC)%.c $(PREF_SRC)s21_matrix.h
	mkdir -p binary
	$(CC) $(FLAGS) $(GCOV_FLAGS) -c $< -o $@

test: clean s21_matrix.a test/test.c 
	cd binary && $(CC) $(FLAGS) $(GCOV_FLAGS) -c ../test/test.c
	$(CC) -L. -ls21_matrix binary/test.o $(GCOV_FLAGS) $(CHECK_FLAGS) -o run_tests
	./run_tests

gcovr_report: test
	mkdir -p report
	./run_tests
	gcov -f *.gcno
	gcovr -r. --html --html-details -o report/report.html
	open report/report.html

dvi: clean
	mkdir -p docs
	doxygen Doxyfile
	mv html latex docs
	open docs/html/index.html

git: clean_for_git
	git add -A
	git commit -m "$m"
	git push origin "$b"

clean:
	rm -rf *.o *.gcov *.gcda *.gcno binary run_tests

clean_for_git:
	rm -rf run_tests binary