#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/errno.h>
#include <signal.h>
#include <dirent.h>
#include <termios.h>
#include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include "libft/libft.h"
# include <sys/fcntl.h>
# include <errno.h>
# include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

#include <fcntl.h>

static int g_err_status;

typedef struct s_param
{
	int	in_quotes;
	int in_dquotes;
	int i;
	int j;
}				t_param;

typedef struct s_main
{
	char			**command;
	int				fd_input;
	int 			fd_output;
	int 			double_input;
	struct s_main	*next;
}					t_main;

typedef struct s_info
{
	int		count_cmds;
	int		count_pipes;
	int		**fd;
	pid_t	*pids;
}				t_info;

void	ft_close_pipes_fd_in_middle_fork(t_main cmd, int position, t_info info);
void	ft_close_pipes_fd_in_last_fork(t_main cmd, t_info info);
void	ft_close_pipes_fd_in_first_fork(t_main cmd, t_info info);
void	ft_choose_cmd_position(int position, t_main *cmds, char ***envp, t_info info);
void	ft_close(int fd, char *cmd_name);
void	ft_dup2(int oldfd, int newfd, char *cmd_name);
void	ft_dup2_and_close_fd(int oldfd, int newfd, char *cmd_name);
void	ft_cd(char **cmd, char ***envp);
char	*ft_add_home(char *cmd, char *dfl_dir);
void	ft_set_param(char *old_pwd, char ***envp, char *cmd_name);
void	ft_echo(char **cmd);
void	ft_env(char **envp);
void	ft_export_err(char *cmd, char *err, char *arg);
void	ft_cmd_err(char *cmd);
void	ft_custom_err(char *cmd, char *err);
void	ft_cd_err(char *cmd, char *dir_name);
void	ft_exit_err(char *cmd, char *err, char *arg);
int		ft_arr_len(char **arr);
char	*ft_get_var_name(char *line);
int		ft_count_commands(t_main *cmds);
void	ft_free_arr(char **arr);
void	ft_free_line(char **arr, int count);
void	ft_free_int_arr(int **arr);
void	ft_free_int_line(int **arr, int count);
void	ft_execve(char **cmd, char **envp);
int		ft_split_path(char *path_line, char **cmd, char **envp);
void	ft_exit(char **cmd);
void	ft_arrjoin(char ***envp, char *arg, char *cmd);
void	ft_export(char **cmd, char ***envp);
int		ft_check_arg(char *cmd, char *arg);
int		ft_check_double(char **envp, char *arg);
void	ft_export_without_arg(char **envp);
char	*ft_getenv_line(char **envp, char *var);
int		ft_getenv_num_of_line(char **envp, char *var);
void	ft_exec_cmd(char **cmd, char ***envp);
void	ft_change_lvl(char ***envp);
void	ft_signal_in_fork(void);
void	ft_signal_here_doc(void);
void	ft_signal(void);
void	ft_execute_input(t_main *cmds, char ***envp);
void	ft_pipe(t_main *cmds, char ***envp, t_info *info);
void	ft_create_forks(t_main *cmds, char ***envp, t_info *info);
void	ft_pwd(void);
void	ft_unset(char **cmd, char ***envp);
void	ft_error(char *str);
int		ft_strcmp(char *str1, char *str2);
void	ft_exec_some_cmd(char **cmd, char **envp);
int		ft_check_cmd_arg(char *arg);
t_main 	*ft_parsing(char *str, char **env);
void	ft_critical_error(char *str);
int		ft_preparsing(char *str);
char	*ft_mystrjoin(char *s1, char *s2, size_t size);
t_main	*ft_initialise(void);
char 	**ft_get_env(char **envp);
int		ft_dollar_parse(char **str, char **env, char **res, t_param *param);
void	ft_free_struct(t_main *res);
char 	**ft_expand_array(char **array, int j, char *str);
int 	ft_quotes_flags(int *in_quotes, int *in_dquotes, char **str);
void 	ft_parse_spaces(char **str, t_param *param);
int 	ft_parse_pipes(char **str, t_param *param, t_main **proper);
void	ft_critical_error(char *str);
int		ft_redirects_syntax_error(char **str);
int		ft_form_filename(char **buf, t_param *p, char **env, char **str);
void	ft_str_assignment(char **buf, char **str, t_param *p);
int		ft_parse_redirect_output(char **str, char **env, t_main *proper);
void	ft_initializate_parameters(t_param *param);
int		ft_parse_redirect_input(char **str, char **env, t_main *proper);
int		ft_conditions_of_replacement(t_param *param, char symbol);
char	*ft_replace_with_env(char *replace);
void	ft_str_assignment(char **buf, char **str, t_param *p);
int		ft_parse_double_input(char **str, char **env, t_main *proper);
int		ft_end_of_double_parse(int fd, t_main *proper, char *stop_word);
void 	ft_free_some(char *arr1, char *arr2, char *arr3);
void 	ft_fill_the_line(char **res, char **buf);
char	*ft_preparse_empty_str(char *str);
char	*ft_dollar_in_redirect(char *line, char **env, char **res, t_param
		*par);
int	ft_dollar_parse_special(char **str, char **env, char ***res, t_param *param);

#endif
