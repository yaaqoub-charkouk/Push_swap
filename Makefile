CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
TARGET = push_swap
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
	moves/push.c \
	moves/rotate.c \
	moves/reverse_rotate.c \
	moves/swap.c
	
U_OBJS = $(UTILS:.c=.o)
S_OBJS = $(SRC:.c=.o)
OBJS = $(U_OBJS) $(S_OBJS)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all