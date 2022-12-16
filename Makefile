# Compiler settings.
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS =

# Makefile settings.
APPNAME = push_swap
EXT = .c
LIBEXT = .a
SRCDIR = src
OBJDIR = obj
LIBDIR = lib/libft
SRC = $(wildcard $(SRCDIR)/*$(EXT))
OBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)

RM = rm
DELOBJ = $(OBJ)

all: lib $(APPNAME)

# Builds the app
$(APPNAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) -L ${LIBDIR} -lft

# Building rule for .o files and its .c
$(OBJDIR)/%.o: $(SRCDIR)/%$(EXT)
	@$(CC) $(CFLAGS) -o $@ -c $<

# Rules
.PHONY: clean
clean:
	@make clean -C lib/libft
	@$(RM) $(DELOBJ)

.PHONY: fclean
fclean: clean
	@make fclean -C lib/libft
	@$(RM) $(APPNAME)

.PHONY: lib
lib:
	@make -C lib/libft
.PHONY: re
re:	fclean all
