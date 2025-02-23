CC = cc
CFLAGS = -Wall -Wextra -Werror
TARGET = push_swap
B_TARGET = checker
HEADERS = header.h libft/libft.h get_next_line/get_next_line.h ft_printf/ft_printf.h bonus/header_bonus.h
UTILS = libft/ft_atoi.c \
	libft/ft_bzero.c \
	libft/ft_calloc.c \
	libft/ft_isdigit.c \
	libft/ft_lst_before_last.c \
	libft/ft_lstadd_back_bonus.c \
	libft/ft_lstadd_front_bonus.c \
	libft/ft_lstlast_bonus.c \
	libft/ft_lstnew_bonus.c \
	libft/ft_lstsize_bonus.c \
	libft/ft_error.c \
	libft/ft_split.c \
	libft/ft_stack_clear.c \
	libft/ft_strlen.c \
	ft_printf/ft_printf.c \
	ft_printf/ft_printf_utils.c

SRC = src/push_swap.c \
	src/utils.c \
	src/parsing_1.c \
	src/stack_operations.c \
	src/sorting.c \
	src/sorting_2.c \
	moves/push.c \
	moves/rotate.c \
	moves/reverse_rotate.c \
	moves/swap.c 

BNS = bonus/apply_move.c \
	bonus/checker_bonus.c \
	bonus/stack_operations_bonus.c \
	bonus/moves_bonus.c \
	bonus/utils_bonus.c \
	bonus/parsing_bonus.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c


U_OBJS = $(UTILS:.c=.o)
S_OBJS = $(SRC:.c=.o)
B_OBJS = $(BNS:.c=.o)
OBJS = $(U_OBJS) $(S_OBJS)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

bonus: $(B_TARGET) 

$(B_TARGET): $(B_OBJS) $(U_OBJS)
	$(CC) $(CFLAGS) $(B_OBJS) -o $(B_TARGET)




clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(TARGET) $(B_TARGET)

re: fclean all