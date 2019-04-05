TARGET=string
CFLAGS=-Wall
LDFLAGS=-I$(IDIR)

IDIR=./include
SDIR=./src
ODIR=./bin

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
	ifeq ($(shell which gcc-8), /usr/local/bin/gcc-8)
		CC=gcc-8#MacOS GNU gcc, not clang
	else
		CC=clang
	endif
else
	CC=gcc#GNU gcc
endif

_DEPS=string.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))
$(info Header files: $(DEPS))

_SRC=string.c test.c
SRC=$(patsubst %,$(SDIR)/%,$(_SRC))
$(info Source files: $(SRC))

_OBJ=string.o test.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))
$(info Object files: $(OBJ))

all: $(ODIR)/$(TARGET)

$(ODIR)/$(TARGET): $(OBJ)
	$(info Compiling target $@)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(info Compiling $@...)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	$(info Cleaning object directory...)
	rm -f -r $(ODIR)/*.o
