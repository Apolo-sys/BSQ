
COMPILER	:= cc

NAME		:= bsq

FLAGS		:= -Wall -Wextra -Werror -I./heads -O3

SRCDIR		:= src
HEADERS		:= heads

all:
	$(COMPILER) $(SRCDIR)/*.c $(FLAGS) -o $(NAME)
clean:
	rm bsq && *.x
.PHONY:
	clean all
