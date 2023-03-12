/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 03:02:29 by hshimizu          #+#    #+#             */
/*   Updated: 2023/03/13 08:50:27 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int nb, int n)
{
	char	temp;

	temp = '0';
	if (n < 1)
		return ;
	print(nb / 10, n - 1);
	temp += nb % 10;
	write(1, &temp, 1);
}

int	init_comb(int s, int n)
{
	if (n <= 1)
		return (s);
	return (init_comb(s * 10 + s % 10 + 1, n - 1));
}

void	next_comb(int *n)
{
	if (*n % 10 == 9)
	{
		*n /= 10;
		next_comb(n);
		*n = (*n * 10) + (*n % 10);
		next_comb(n);
	}
	else
		(*n)++;
}

void	ft_print_combn(int n)
{
	int	i;
	int	end;

	i = init_comb(0, n);
	end = init_comb(10 - n, n);
	print(i, n);
	while (i < end)
	{
		next_comb(&i);
		write(1, ", ", 2);
		print(i, n);
	}
}
