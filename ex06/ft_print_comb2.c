/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:08:27 by hshimizu          #+#    #+#             */
/*   Updated: 2023/03/11 03:07:49 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char temp[])
{
	char	separator;

	separator = ' ';
	write(1, temp, 2);
	write(1, &separator, 1);
	write(1, temp + 2, 2);
}

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
		if (add_one(temp, 3))
			break ;
		if (temp[0] < temp[2] || (temp[0] == temp[2] && temp[1] < temp[3]))
			return (1);
	}
	return (0);
}

void	ft_print_comb2(void)
{
	char	separator[2];
	char	temp[4];

	separator[0] = ',';
	separator[1] = ' ';
	temp[0] = '0';
	temp[1] = '0';
	temp[2] = '0';
	temp[3] = '0';
	next_comb(temp);
	while (1)
	{
		print(temp);
		if (!next_comb(temp))
			break ;
		write(1, separator, 2);
	}
}
