/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenamelard <lenamelard@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:54:03 by lmelard           #+#    #+#             */
/*   Updated: 2022/06/30 14:03:04 by lenamelard       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_init_data(t_data *data, int argc, char **argv, char **envp)
{
	data->av = argv;
	data->ac = argc;
	data->env = envp;
	data->pipe_fd[0] = -1;
	data->pipe_fd[1] = -1;
	data->in_file = -1;
	data->out_file = -1;
	data->env_path = ft_get_path_env(envp, data);
	if (!(data->env_path))
		ft_main_error(2, data);
	data->cmd_path = NULL;
	data->arg = NULL;
}

char	**ft_get_path_env(char **envp, t_data *data)
{
	char	*p;
	char	*tmp;
	char	*str;
	char	**tab;

	p = "PATH=";
	while (ft_strnstr(*envp, p, 5) == NULL)
		envp++;
	if (envp)
	{
		str = ft_substr(*envp, 5, ft_strlen(*envp) - 5);
		if (!str)
			ft_get_error(1, data);
		tmp = str;
		tab = ft_split(str, ':');
		free(tmp);
		if (!tab)
			ft_get_error(1, data);
		return (tab);
	}
	ft_get_error(1, data);
	return (0);
}
