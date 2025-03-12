COMPILER := cc

NAME     := bsq

FLAGS    := -Wall -Werror -Wextra -I$(HEADERS) -O3

SRCDIR   := src
HEADERS  := heads
OBJDIR   := obj

SRCS     := $(wildcard $(SRCDIR)/*.c)
OBJS     := $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(COMPILER) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(COMPILER) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJDIR) $(NAME)

.PHONY: all clean
