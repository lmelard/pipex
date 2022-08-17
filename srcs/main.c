/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:12:35 by lmelard           #+#    #+#             */
/*   Updated: 2022/07/01 16:55:24 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_children_process(int *pid, t_data *data)
{
	pid[0] = fork();
	if (pid[0] < 0)
		ft_main_error(1, data);
	if (pid[0] == 0)
		ft_child_process1(data);
	pid[1] = fork();
	if (pid[1] < 0)
		ft_main_error(1, data);
	if (pid[1] == 0)
		ft_child_process2(data);
}

int	main(int argc, char **argv, char **envp)
{
	int		pid[2];
	t_data	data;
	int		status;

	status = 1;
	if (argc == 5)
	{
		if (!envp)
			ft_main_error(2, &data);
		ft_init_data(&data, argc, argv, envp);
		if (pipe(data.pipe_fd) < 0)
			return (1);
		ft_children_process(pid, &data);
		close(data.pipe_fd[0]);
		close(data.pipe_fd[1]);
		waitpid(pid[0], &status, 0);
		waitpid(pid[1], &status, 0);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		ft_free_tab(data.env_path);
		ft_close_std();
	}
	else
		ft_main_error(3, &data);
	return (status);
}
