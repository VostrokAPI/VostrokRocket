AUTHOR = https://github.com/Unam3dd
NAME = libvsrocket
CC = gcc
AR = ar rcs
VS_VER	= 0.0.1
VERSION = $(shell $(CC) --version | head -n1)
CFLAGS = -Wall -Wextra -Werror -Iinc -fPIC

OBJDIR = obj
DIST = dist
UNIT_DIR = $(shell pwd)/unit

vpath %.c src
vpath %.h inc

##################################
#
#		COLOR
#
##################################

GREEN 	= \033[38;5;82m
RED   	= \033[38;5;196m
YELLOW 	= \033[38;5;226m
ORANGE	= \033[38;5;202m
PURPLE	= \033[38;5;207m
LBLUE	= \033[38;5;45m
BLUE	= \033[38;5;26m
DGREY	= \033[90m
RESET 	= \033[00m

NUM_CF		= $(shell ls -lR src/ | grep -F .c | wc -l)
cnt			= 2
PERC		= 0

##############################################
#
#
#			C Source Files
#
#
##############################################

SRCS 				=	$(shell find src -iname "*.c" -type f -print)
OBJS				=	$(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

##############################################
#
#
#				OUTPUT
#
#
##############################################

STATIC_LIB			= $(DIST)/$(NAME).a
DYNAMIC_LIB			= $(DIST)/$(NAME).so

##############################################
#
#
#				TESTS
#
#
##############################################

TEST_DIR 	= tests
TESTS 		= $(shell find tests -iname "*.c" -print)
TESTS_MAIN 	= $(TESTS:.c=.out)

ifdef DEBUG
	CFLAGS	+= -g
endif

ifdef OSIZE
	CFLAGS += -Os
endif

ifdef OFAST
	CFLAGS += -Ofast
endif

ifdef O3
	CFLAGS += -O3
endif

ifdef 32
	CFLAGS += -m32
else
	CFLAGS += -m64
endif

all: $(STATIC_LIB) $(DYNAMIC_LIB)

obj/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o  $@

$(STATIC_LIB): $(OBJDIR) $(OBJS)
	@mkdir -p dist
	$(AR) $(STATIC_LIB) $(OBJS)

$(DYNAMIC_LIB): $(OBJDIR) $(OBJS)
	@mkdir -p dist
	$(CC) $(CFLAGS) -shared $(OBJS) -o $(DYNAMIC_LIB)

$(OBJDIR):
	@mkdir -p $(sort $(addprefix $(OBJDIR)/, $(dir $(SRCS))))

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(STATIC_LIB) $(DYNAMIC_LIB) $(OBJDIR)
	rm -rf $(DIST)
	rm -rf $(UNIT_DIR)

re: fclean $(STATIC_LIB) $(DYNAMIC_LIB)

$(UNIT_DIR):
	@mkdir -p $(UNIT_DIR)

%.out: %.c
	$(CC) $(CFLAGS) -Iinc -L. $< -o $@ $(STATIC_LIB)
	$@ -v | ./greatest/contrib/greenest
	mv $@ $(UNIT_DIR)

$(TESTS_MAIN): $(TESTS) $(STATIC_LIB) $(UNIT_DIR)

test: $(TESTS_MAIN)

.PHONY: all clean fclean re tests
