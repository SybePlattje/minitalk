NAME = libft.a
HEADER = libft.h

SOURCES_MAND = ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_iswhitespace.c \
			ft_atoll.c \
			handle_errors.c \
			ft_foutput.c \
			ft_fprintf.c \
			ft_output.c \
			ft_printf.c \
			ft_ptr_to_hex.c \
			ft_uint_to_hex_uplow.c \
			ft_uitostr.c \

SOURCES_BONUS = ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \

OBJ_DIR_MAND = ./obj_mand
OBJ_DIR_BONUS = ./obj_bonus
$(shell mkdir -p $(OBJ_DIR_MAND) $(OBJ_DIR_BONUS))

OBJS_MAND = $(addprefix $(OBJ_DIR_MAND)/, $(SOURCES_MAND:.c=.o))
OBJS_BONUS = $(addprefix $(OBJ_DIR_BONUS)/, $(SOURCES_BONUS:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar

all: $(NAME)

$(NAME): $(OBJS_MAND) | $(OBJ_DIR_MAND)
	@cp $(HEADER) $(OBJ_DIR_MAND)
	@$(AR) rcs $(NAME) $(OBJS_MAND)

bonus: $(OBJS_MAND) $(OBJS_BONUS) | $(OBJ_DIR_BONUS) $(OBJ_DIR_MAND)
	@cp $(HEADER) $(OBJ_DIR_MAND)
	@$(AR) rcs $(NAME) $(OBJS_MAND) $(OBJS_BONUS)

$(OBJ_DIR_MAND)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_BONUS)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR_MAND) $(OBJ_DIR_BONUS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re