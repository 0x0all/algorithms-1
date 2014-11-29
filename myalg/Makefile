.PHONY: all clean
CC=gcc
CPP=g++
AR=ar
CFLAGS= -Wall -Wextra -Werror
C11FLAGS= -g -Wall -Wno-unused-function -std=c++11
DIR_SRC = ./test
DIR_INC = ./inc/
DIR_LIB = ./lib/
INCLUDEDIR = -I./inc

INC_CPP = $(wildcard ${DIR_INC}*.cpp)
LIBS = $(patsubst %.cpp,${DIR_LIB}%.o,$(notdir ${INC_CPP}))
$(DIR_LIB)%.o:$(DIR_INC)%.cpp
	g++ -c -o $@ $<


PROGRAMS = test_linklist \

all: $(PROGRAMS)
test_linklist: $(DIR_SRC)/test_linklist.cpp
	$(CPP) $(CFLAGS) -o $@ $^ -L$(DIR_LIB) $(INCLUDEDIR)

lib:$(DIR_INC)%.cpp
	$(CPP) -c $(CFLAGS) $< -o $@
	@ar crv test.a $(DIR_LIB)*.o
clean:
	rm -rf $(PROGRAMS) *.dSYM

