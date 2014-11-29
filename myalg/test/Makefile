#----------------options----------------#
#environment
CC = g++
FLAGS_DEBUG = -g
FLAGS_COMPILE = -c -Wall -Wextra -Werror

#directory
SHELL = /bin/sh
DIR = $(PWD)
DIR_OBJ = $(DIR)/obj/
DIR_SRC = $(DIR)/test/
DIR_BIN = $(DIR)/bin/
DIR_LIB = $(DIR)/lib/
DIR_INC = $(DIR)/inc/

#target
TARGET = test

#vpath
#vpath %.cpp $(DIR_SRC)
#vpath %.o $(DIR_OBJ)

#src
SRC=$(wildcard ${DIR_SRC}*.cpp)

#include
INC=-I$(DIR_INC)

#lib
#LIBS depends on your needs
#for instance: LIBS=-lsky which means there is a libsky.a file in DIR_LIB direction
LIBS=
LIB=-L$(DIR_LIB)$(LIBS)

#obj
OBJ=$(patsubst %.cpp,${DIR_OBJ}%.o,$(notdir ${SRC}))

#----------------macro---------------#
.PHONY:dir clean make r
#debug
debug:$(OBJ)
	@echo "linking..."
	@cd $(DIR_OBJ);$(CC) *.o -o $(DIR_BIN)$(TARGET)
	@echo "linking end..."
	@echo "execute the $(TARGET) in $(DIR_BIN)$(TARGET)"

$(DIR_OBJ)%.o:$(DIR_SRC)%.cpp
	@echo "compiling..."
	@echo "SRC:$<"
	$(CC) $(FLAGS_DEBUG) $(FLAGS_COMPILE) $< -o $@ $(INC)
	@echo "compiling end..."

#clean
clean:
	@rm -rf $(DIR_OBJ)
	@rm -rf $(DIR_BIN)

#objects & executable direction
dir:
	@mkdir -p $(DIR_OBJ)
	@mkdir -p $(DIR_BIN)

#help
help:
	@echo "......------------Makefile------------......"
	@echo "Include four commands: #1.de; #2.clean; #3.dir; #4.help"
	@echo "#1.de:"
	@echo "    debug the source file into a executable file that is included in the $(DIR_BIN)!"
	@echo "#2.clean:"
	@echo "    delete the debug files and directions"
	@echo "#3.dir:"
	@echo "    mkdir a new directions for objects and executable file:"
	@echo "    $(DIR_BIN) for executable file"
	@echo "    $(DIR_OBJ) for object file"
	@echo "#4.help:"
	@echo "    help for using this makefile to debug a project which includes source files include files"
	@echo "......------------End------------......"

#make all the commands and get the executable file
make:
	@echo "start debugging..."
	@$(MAKE) -s dir
	@$(MAKE) -s debug
	@echo "finish..."
	@echo "******************************"
	@echo "*    ____  ____  _   ________*"
	@echo "*   / __ \/ __ \/ | / / ____/*"
	@echo "*  / / / / / / /  |/ / __/   *"
	@echo "* / /_/ / /_/ / /|  / /___   *"
	@echo "*/_____/\____/_/ |_/_____/   *"
	@echo "******************************"
	@echo "You want the executable file run itself?"
	@echo "'Y' for yes,'N' for no"
	@read -s -n1 key;\
		Y="Y";\
		y="y";\
		if [ $$key == $$Y ] || [ $$key == $$y ]; then\
		cd $(DIR_BIN);\
		$(DIR_BIN)$(TARGET);\
		exit 0;\
		else\
		echo "Not Execute the File!";\
		fi
	@echo "done"

#r: re-make the project
r:
	$(MAKE) -s clean
	$(MAKE) -s make
