NAME = minishell

CC = gcc

CFLAGS = -Wall -Werror -Wextra

%.o: %.c
	$(CC) $(CFLAGS) -Ift -Ireadline -I/Users/$(USER)/.brew/Cellar/readline/8.1/include -c $< -o $@

SRCS =	main.c \
		parse_main.c \
		preparsing.c \
		parse_dollar.c \
		parse_dollar2.c \
		ft_mystrjoin.c \
		get_env.c \
		errors.c \
		free_struct.c \
		parse_utils.c \
		parse_quotes_pipes_spaces.c \
		parse_errors.c \
		parse_redirects_out.c \
		parse_redirects_in.c \
		parse_redir_heredoc.c \
		parse_redir_heredoc2.c \
		cd.c \
		cd_set_param.c \
		echo.c \
		env.c \
		exec_split_path.c \
		exec_utils.c \
		execve.c \
		exit.c \
		export.c \
		export_unset_check.c \
		export_with_arg.c \
		free_arr.c \
		get_env_info.c \
		pipe.c \
		pipe_close_fd.c \
		pipe_create.c \
		pipe_dup2.c \
		pipe_exec_cmd.c \
		pipe_fork.c \
		pwd.c \
		signals.c \
		signals_dfl.c \
		unset.c \
		minishell.c

LIB_SRCS = libft/*.c

HEADER = minishell.h

OBJS = $(SRCS:.c=.o)

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJS) $(LIB_SRCS) $(HEADER)
	$(MAKE) -C ./libft
	$(CC) $(OBJS) -lreadline -Llibft -lft -L/Users/$(USER)/.brew/Cellar/readline/8.1/lib/ -o $(NAME)

clean:
		rm -f $(OBJS) $(BONUS_OBJS)
		${MAKE} -C ./libft clean

fclean:	clean
		rm -f $(NAME)
		${MAKE} -C ./libft fclean

re: fclean all