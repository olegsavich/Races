SRCS = src/*.c
INC = inc/*.h

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -lncurses

all: install clean

install:
	@clang $(CFLAGS) -o matrix_rain $(SRCS) -I inc

clean:
	@rm -rf inc/*.gch

uninstall: clean
	@rm -rf matrix_rain

reinstall: uninstall all
