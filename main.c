#include "minishell.h"

t_main	*ft_initialise(void)
{
	t_main	*proper;

	proper = malloc(sizeof(t_main));
	if (proper == NULL)
	{
		ft_cmd_err("malloc");
		return (NULL);
	}
	proper->fd_input = 0;
	proper->fd_output = 1;
	proper->command = ft_calloc(1, sizeof(char *));
	if (proper->command == NULL)
	{
		ft_cmd_err("malloc");
		return (NULL);
	}
	proper->command[0] = NULL;
	proper->double_input = 0;
	proper->next = NULL;
	return (proper);
}

int main(int argc, char **argv, char **envp)
{
	char	*str;
	t_main	*tmp;
	char 	**env;

	env = ft_get_env(envp);
	g_err_status = 0;
	ft_change_lvl(&env);
	while (1)
	{
		ft_signal();
		str = readline("Minishell> ");
		if (str == NULL)
		{
			ft_putstr_fd("exit\n", 1);
			exit(0);
		}
		str = ft_preparse_empty_str(str);
		if (str == NULL)
			continue;
		add_history(str);
		tmp = ft_parsing(str, env);
		if (tmp == NULL)
		{
			free (str);
			continue;
		}
		ft_execute_input(tmp, &env);
		free (str);
		ft_free_struct(tmp);
	}
}
