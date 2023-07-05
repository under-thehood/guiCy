
# Makefile for library project

TEST=example/test1.c 

SRC_DIR = src
WIDGET_SRC_DIR=$(SRC_DIR)/widget
OBJ_DIR = obj
LIB_DIR = lib

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
WIDGET_SRC_FILES= $(wildcard $(WIDGET_SRC_DIR)/*.c)
# Object files
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
WIDGET_OBJ_FILES = $(patsubst $(WIDGET_SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(WIDGET_SRC_FILES))


# Library
LIB_DIR=lib
LIB =$(LIB_DIR)/libguicy.so

# Compiler and linker flags
CC = clang
CFLAGS = -Wall -Wextra -O3 -std=c2x -fPIC
LDFLAGS = -shared -lraylib -lm

all: $(LIB)

$(LIB):$(OBJ_FILES) $(WIDGET_OBJ_FILES)
	@mkdir -p $(LIB_DIR)
	$(CC) $(LDFLAGS) -o $@ $(OBJ_FILES) $(WIDGET_OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o: $(WIDGET_SRC_DIR)/%.c 
	@echo "Building widget file"
	$(CC) $(CFLAGS) -c -o $@ $<

test:$(LIBRARY) $(TEST) all
	$(CC) $(CFLAGS) $(TEST)  -o test -Llib/ -lguicy -lraylib 
	export LD_LIBRARY_PATH="lib/"  
	./test


clean:
	rm -rf lib
	rm -rf obj
	rm test

debug:
	@echo "SRC: $(SRC_FILES)"
	@echo "WIDGET_SRC: $(WIDGET_SRC_FILES)"
	@echo "OBJ_SRC: $(OBJ_FILES)"
	@echo "Widget object: $(WIDGET_OBJ_FILES):"

.PHONY: all clean