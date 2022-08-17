/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:58:36 by lmelard           #+#    #+#             */
/*   Updated: 2022/07/01 16:30:13 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include "../libft/libft.h"

typedef struct s_data {
	char	**av;
	int		ac;
	char	**env;
	int		pipe_fd[2];
	int		in_file;
	int		out_file;
	char	**env_path;
	char	*cmd_path;
	char	**arg;
}			t_data;

void	ft_init_data(t_data *data, int argc, char **argv, char **envp);
char	**ft_get_path_env(char **envp, t_data *data);
void	ft_main_error(int code, t_data *data);
void	ft_get_error(int code, t_data *data);
void	ft_error_process(int code, t_data *data);
void	ft_free_tab(char **tab);
void	ft_free_data(t_data *data);
void	ft_add_backslash(t_data *data);
void	ft_get_cmd_path(t_data *data, char *cmd);
void	ft_find_command(t_data *data);
int		ft_child_process1(t_data *data);
int		ft_child_process2(t_data *data);
void	ft_main_process(int *pipe_fd, int *pid, int status);
void	ft_children_process(int *pid, t_data *data);
void	ft_exit_error(t_data *data);
void	ft_custom_putstr_fd(char *s, int fd);
void	ft_write_error(char *s, int fd);
int		ft_check_cmd(t_data *data, char *cmd);
void	ft_close_std(void);

#endif
