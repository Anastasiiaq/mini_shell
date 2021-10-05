NAME = minishell

CC = gcc

CFLAGS = -Wall -Werror -Wextra

%.o: %.c
	$(CC) $(CFLAGS) -I./includes/ -Ift -Ireadline -I/usr/local/opt/readline/include -c $< -o $@

SRCS =	./src/builtins/cd/cd.c \
	./src/builtins/cd/cd_set_param.c \
	./src/builtins/echo/echo.c \
	./src/builtins/env/env.c \
	./src/builtins/env/get_env.c \
	./src/builtins/env/get_env_info.c \
	./src/builtins/exit/exit.c \
	./src/builtins/export/export.c \
	./src/builtins/export/export_unset_check.c \
	./src/builtins/export/export_with_arg.c \
	./src/builtins/pwd/pwd.c \
	./src/builtins/unset/unset.c \
	./src/errors/errors.c \
	./src/errors/parse_errors.c \
	./src/execve/exec_split_path.c \
	./src/execve/exec_utils.c \
	./src/execve/execve.c \
	./src/free/free_arr.c \
	./src/free/free_struct.c \
	./src/minishell/main.c \
	./src/minishell/minishell.c \
	./src/parsing/ft_mystrjoin.c \
	./src/parsing/parse_dollar.c \
	./src/parsing/parse_dollar2.c \
	./src/parsing/parse_main.c \
	./src/parsing/parse_quotes_pipes_spaces.c \
	./src/parsing/parse_redir_heredoc.c \
	./src/parsing/parse_redir_heredoc2.c \
	./src/parsing/parse_redirects_in.c \
	./src/parsing/parse_redirects_out.c \
	./src/parsing/parse_utils.c \
	./src/parsing/preparsing.c \
	./src/pipe/pipe.c \
	./src/pipe/pipe_close_fd.c \
	./src/pipe/pipe_create.c \
	./src/pipe/pipe_dup2.c \
	./src/pipe/pipe_exec_cmd.c \
	./src/pipe/pipe_fork.c \
	./src/signals/signals.c \
	./src/signals/signals_dfl.c \
	
LIB_SRCS = libft/*.c

HEADER = ./includes/minishell.h

OBJS = $(SRCS:.c=.o)

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJS) $(LIB_SRCS)
	$(MAKE) -C ./libft
	$(CC) $(OBJS) -I./includes/ -lreadline -Llibft -lft -L/usr/local/opt/readline/lib/ -o $(NAME)

$(OBJS):	$(HEADER)

clean:
		rm -f $(OBJS)
		${MAKE} -C ./libft clean

fclean:	clean
		rm -f $(NAME)
		${MAKE} -C ./libft fclean

re: fclean all