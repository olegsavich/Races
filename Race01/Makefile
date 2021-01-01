CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
SRCS = src/*.c
OBJS = obj/*.o

all: MINILIBMX

MINILIBMX:
	@mkdir obj
	@clang -c $(SRCS)
	@mv *.o obj
	@ar rcs minilibmx.a $(OBJS)
	@clang $(CFLAGS) -o part_of_the_matrix minilibmx.a

clean: 
	@rm -rf minilibmx.a obj

uninstall: clean
	@rm -rf part_of_the_matrix

reinstall: uninstall MINILIBMX
