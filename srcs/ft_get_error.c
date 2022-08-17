/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:09:17 by lmelard           #+#    #+#             */
/*   Updated: 2022/07/01 16:55:17 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_close_std(void)
{
	close(STDIN_FILENO);
	close(STDERR_FILENO);
	close(STDOUT_FILENO);
}

void	ft_main_error(int code, t_data *data)
{
	if (code == 1)
	{
		write(2, "error: creating process\n", 28);
		ft_free_data(data);
		ft_close_std();
		exit(EXIT_FAILURE);
	}
	if (code == 2)
	{
		write(2, "error: no envp variable\n", 24);
		ft_close_std();
		exit(EXIT_FAILURE);
	}
	if (code == 3)
	{
		write(2, "error: wrong number of arguments\n", 33);
		ft_close_std();
		exit(EXIT_FAILURE);
	}
}

void	ft_get_error(int code, t_data *data)
{
	if (code == 1)
	{
		write(2, "error: Something went wrong\n", 28);
		ft_free_data(data);
		ft_close_std();
		exit(EXIT_FAILURE);
	}
	if (code == 2)
	{
		write(2, "error: command not found", 24);
		ft_custom_putstr_fd(data->arg[0], 2);
		ft_free_data(data);
		ft_close_std();
		exit(127);
	}
	if (code == 3)
	{
		write(2, "error: permission denied:\n", 26);
		ft_free_data(data);
		ft_close_std();
		exit(126);
	}
}

void	ft_error_process(int code, t_data *data)
{
	if (code == 2)
	{
		ft_write_error(data->cmd_path, 2);
		ft_free_data(data);
		ft_close_std();
		exit(126);
	}
	if (code == 3)
	{
		ft_write_error(data->av[1], 2);
		close(data->pipe_fd[1]);
		ft_free_tab(data->env_path);
		ft_close_std();
		exit(EXIT_FAILURE);
	}
	if (code == 4)
	{
		ft_write_error(data->av[4], 2);
		close(data->pipe_fd[0]);
		ft_free_tab(data->env_path);
		ft_close_std();
		exit(EXIT_FAILURE);
	}
}
