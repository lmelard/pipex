/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenamelard <lenamelard@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:03:10 by lmelard           #+#    #+#             */
/*   Updated: 2022/06/29 15:58:26 by lenamelard       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

void	ft_free_data(t_data *data)
{
	if (data->env_path)
		ft_free_tab(data->env_path);
	if (data->arg)
		ft_free_tab(data->arg);
	if (data->cmd_path)
	{
		free(data->cmd_path);
		data->cmd_path = NULL;
	}
}
