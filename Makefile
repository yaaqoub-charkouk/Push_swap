CC = cc
CFLAGS = -Wall -Wextra -Werror
TARGET = push_swap
B_TARGET = checker

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
	get_next_line/get_next_line_utils.c \
	libft/ft_strcmp.c

U_OBJS = $(UTILS:.c=.o)
S_OBJS = $(SRC:.c=.o)
B_OBJS = $(BNS:.c=.o)

HEADERS = libft/libft.h ft_printf/ft_printf.h
MANDATORY_HEADER = push_swap.h
BONUS_HEADER = bonus/push_swap_bonus.h


all: $(TARGET)

$(TARGET): $(S_OBJS) $(U_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

bonus : $(B_TARGET)

$(B_TARGET): $(U_OBJS) $(B_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(U_OBJS): %.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(S_OBJS): %.o: %.c $(HEADERS) $(MANDATORY_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(B_OBJS): %.o: %.c $(HEADERS) $(BONUS_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(U_OBJS) $(S_OBJS) $(B_OBJS)

fclean: clean
	rm -f $(TARGET) $(B_TARGET)

re: fclean all

.PHONY: all clean fclean re bonus