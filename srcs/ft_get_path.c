/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:56:06 by lmelard           #+#    #+#             */
/*   Updated: 2022/07/01 15:12:00 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_find_command(t_data *data)
{
	ft_add_backslash(data);
	ft_get_cmd_path(data, data->arg[0]);
}

void	ft_add_backslash(t_data *data)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!(data->env_path))
		ft_get_error(1, data);
	while (data->env_path[i])
	{
		tmp = data->env_path[i];
		data->env_path[i] = ft_strjoin(data->env_path[i], "/");
		if (!(data->env_path[i]))
			ft_get_error(1, data);
		free(tmp);
		tmp = NULL;
		i++;
	}
}

int	ft_check_cmd(t_data *data, char *cmd)
{
	int		i;
	char	*tmp;

	i = 0;
	while (data->env_path[i])
	{
		tmp = data->env_path[i];
		if (access(cmd, F_OK) == 0
			&& ft_strncmp(cmd, tmp, ft_strlen(tmp)) == 0)
		{
			data->cmd_path = ft_strdup(cmd);
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_get_cmd_path(t_data *data, char *cmd)
{
	char	*cmd_path;
	int		i;

	if (!(data->env_path) || !cmd)
		ft_get_error(3, data);
	if (ft_check_cmd(data, cmd) == 0)
		return ;
	i = 0;
	while (data->env_path[i])
	{
		cmd_path = ft_strjoin(data->env_path[i], cmd);
		if (!cmd_path)
			ft_get_error(1, data);
		if (access(cmd_path, F_OK | X_OK) == 0)
		{
			data->cmd_path = ft_strdup(cmd_path);
			ft_free_tab(data->env_path);
			free(cmd_path);
			return ;
		}
		free(cmd_path);
		i++;
	}
	ft_get_error(2, data);
}
