/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenamelard <lenamelard@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:08:07 by lenamelard        #+#    #+#             */
/*   Updated: 2022/06/30 14:08:35 by lenamelard       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_custom_putstr_fd(char *s, int fd)
{
	if (s && fd)
	{
		write(fd, ": ", 2);
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
	}
}

void	ft_write_error(char *s, int fd)
{
	write(2, "error: ", 7);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	ft_custom_putstr_fd(s, fd);
}
