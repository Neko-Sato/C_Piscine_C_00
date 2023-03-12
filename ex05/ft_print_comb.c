/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:42:27 by hshimizu          #+#    #+#             */
/*   Updated: 2023/03/11 05:43:05 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	add_one(char temp[], int b)
{
	if (b < 0)
		return (1);
	if (temp[b] < '9')
	{
		temp[b]++;
		return (0);
	}
	else
	{
		temp[b] = '0';
		return (add_one(temp, b - 1));
	}
}

int	next_comb(char temp[])
{
	while (1)
	{
		if (add_one(temp, 2))
			break ;
		if (temp[0] < temp[1] && temp[0] < temp[2] && temp[1] < temp[2])
			return (1);
	}
	return (0);
}

void	ft_print_comb(void)
{
	char	separator[2];
	char	temp[3];

	separator[0] = ',';
	separator[1] = ' ';
	temp[0] = '0';
	temp[1] = '0';
	temp[2] = '0';
	next_comb(temp);
	while (1)
	{
		write(1, temp, 3);
		if (!next_comb(temp))
			break ;
		write(1, separator, 2);
	}
}
