/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:23:04 by lmelard           #+#    #+#             */
/*   Updated: 2022/07/01 16:06:37 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_child_process1(t_data *data)
{
	close(data->pipe_fd[0]);
	data->in_file = open(data->av[1], O_RDONLY);
	if (data->in_file < 0)
		ft_error_process(3, data);
	dup2(data->in_file, STDIN_FILENO);
	dup2(data->pipe_fd[1], STDOUT_FILENO);
	close(data->in_file);
	close(data->pipe_fd[1]);
	data->arg = ft_split(data->av[2], ' ');
	if (!(data->arg))
		ft_get_error(1, data);
	ft_find_command(data);
	if (!(data->cmd_path))
		ft_get_error(1, data);
	if (execve(data->cmd_path, data->arg, data->env) == -1)
		ft_error_process(2, data);
	exit(errno);
}

int	ft_child_process2(t_data *data)
{
	close(data->pipe_fd[1]);
	data->out_file = open(data->av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (data->out_file < 0)
		ft_error_process(4, data);
	dup2(data->out_file, STDOUT_FILENO);
	dup2(data->pipe_fd[0], STDIN_FILENO);
	close(data->out_file);
	close(data->pipe_fd[0]);
	data->arg = ft_split(data->av[3], ' ');
	if (!(data->arg))
		ft_get_error(1, data);
	ft_find_command(data);
	if (!(data->cmd_path))
		ft_get_error(1, data);
	if (execve(data->cmd_path, data->arg, data->env) == -1)
		ft_error_process(2, data);
	exit(errno);
}
