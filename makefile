C=clang
C_FLAGS=-ansi -pedantic
SEP=
SUFFIX_BIN=
SUFFIX_OBJ=

ifeq ($(OS),Windows_NT)
	SEP+=\
	SUFFIX_BIN+=.exe
	SUFFIX_OBJ+=.obj
else
	SEP+=/
	SUFFIX_OBJ+=.o
endif

all:
	$(error There is nothing to do)

test: test-mach$(SUFFIX_BIN)

.PHONY: all test

test-mach$(SUFFIX_BIN): test/mach.c mach/rec$(SUFFIX_OBJ) mach/stat$(SUFFIX_OBJ)
	$(C) $(C_FLAGS) $^ -o $@
	.$(SEP)$@

mach/rec$(SUFFIX_OBJ): mach/rec.c
	$(C) $(C_FLAGS) -c $< -o $@

mach/stat$(SUFFIX_OBJ): mach/stat.c
	$(C) $(C_FLAGS) -c $< -o $@
