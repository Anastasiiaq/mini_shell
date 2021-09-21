#include "minishell.h"

int	ft_strcmp(char *str1, char *str2)
{
	int				i;
	unsigned char	*u_str1;
	unsigned char	*u_str2;

	i = 0;
	u_str1 = (unsigned char *)str1;
	u_str2 = (unsigned char *)str2;
	while (u_str1[i] != '\0' || u_str2[i] != '\0')
	{
		if (u_str1[i] == u_str2[i])
			i++;
		else
		{
			if (u_str1[i] > u_str2[i])
				return (1);
			else if (u_str1[i] < u_str2[i])
				return (-1);
		}
	}
	return (0);
}

void	ft_exec_cmd(char **cmd, char ***envp)
{
	if (ft_strcmp(*cmd, "echo") == 0)
		ft_echo(cmd);
	else if (ft_strcmp(*cmd, "cd") == 0)
		ft_cd(cmd, envp);
	else if (ft_strcmp(*cmd, "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(*cmd, "export") == 0)
		ft_export(cmd, envp);
	else if (ft_strcmp(*cmd, "unset") == 0)
		ft_unset(cmd, envp);
	else if (ft_strcmp(*cmd, "env") == 0)
		ft_env(*envp);
	else if (ft_strcmp(*cmd, "exit") == 0)
		ft_exit(cmd);
	else
		ft_execve(cmd, *envp);
}

static char	*ft_set_lvl(char *lvl)
{
	int		cur_lvl;
	char	*str;

	cur_lvl = ft_atoi(lvl);
	lvl = ft_itoa(cur_lvl + 1);
	if (!lvl)
		return (NULL);
	str = ft_strjoin("SHLVL=", lvl);
	free(lvl);
	return (str);
}

void	ft_change_lvl(char ***envp)
{
	char	*str;
	int		num_line;
	char	*lvl;

	num_line = ft_getenv_num_of_line(*envp, "SHLVL");
	if (num_line == -2)
		return (ft_custom_err ("SHLVL", "failed to allocate memory"));
	lvl = ft_getenv_line(*envp, "SHLVL");
	if (!lvl || ft_check_cmd_arg(lvl) == 1)
		str = ft_strjoin("SHLVL=", "1");
	else
		str = ft_set_lvl(lvl);
	if (!str)
		return (ft_custom_err ("SHLVL", "failed to allocate memory"));
	if (num_line == -1)
	{
		ft_arrjoin(envp, str, "SHLVL");
		free(str);
		return ;
	}
	free((*envp)[num_line]);
	(*envp)[num_line] = str;
}
