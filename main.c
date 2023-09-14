/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:45:12 by pnamnil           #+#    #+#             */
/*   Updated: 2023/09/14 15:50:47 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int    test(int test_nb, int (*fn)(const char *, ...))
{
	char	c = 'A';
	char	*s = "42 Bangkok School";
	char	*null = NULL;
	int		i_max = INT_MAX;
	int		i_min = INT_MIN;
	int		i_zro = 0;
	int		nb = 42;

	switch (test_nb)
	{
		case 1:
			return fn("\x01\x02\a\v\b\f\r\n");
		case 2:
			return fn("Test worked%%");
		case 3:
			return fn("%c", c);
		case 4:
			return fn("%c, %s, %s", c, s, null);
		case 5:
			return fn("%c, %s, %s, %p, %p", c, s, null, s, null);
		case 6:
			return fn("%c, %s, %s, %p, %p, %d, %d, %d",
				c, s, null, s, null, i_max, i_min, i_zro);
		case 7:
			return fn("%c, %s, %s, %p, %p, %d, %d, %d, %i, %i, %i",
				c, s, null, s, null, i_max, i_min, i_zro, i_max, i_min, i_zro);
		case 8:
			return fn("%u, %u, %u, %u, %u",
				i_max, i_min, i_zro, 42, -42);
		case 9:
			return fn("%x, %x, %x, %x, %x, %d, %d, %d, %d, %d",
				i_max, i_min, i_zro, 42, -42, i_max, i_min, i_zro, 42, -42);
		case 10:
			return fn("%x, %x, %x, %x, %x, %d, %d, %d, %d, %d, %X, %X, %X, %X, %X",
				i_max, i_min, i_zro, 42, -42, i_max,
				i_min, i_zro, 42, -42, i_max, i_min, i_zro, 42, -42);
		case 11:
			return fn("1: %p\t2: %p\t3: %p\t4: %p\t5: %X\t6: %p\t7: %p\t8: %p",
				(void *)8781479304639507952,
				1183744175,
				2094719205,
				590551644,
				371464711,
				(void *)6335348253505465920,
				-1051412835,
				(void *)-4374214113005521705);
		
		// bonus part
		case 12:
			{
				int cnt = 0;
				for (int i = 15; i < 20; i++)
				cnt += fn("%-*s\n", i, s);
				return (cnt);
			}
		case 13:
			{
				int cnt = 0;
				for (int i = 15; i < 20; i++)
				cnt += fn("%*s\n", i, s);
				return (cnt);
			}
		case 14:
			return fn("%s, %-5s, %5s, %5.2s, %-5.2s, %10.2s, %-10.2s", s, s, s, s, s, null, null);
		case 15:
			return fn("%-6d\t%6d\t%06d\t%.06d\t%06.3d\t%.-6d\t%.0-6d",
			nb, nb, nb, nb, nb, nb, nb);
		default:
			break;
	}
    return (-1);
}

int main(void)
{
	for (int i = 14; i <= 14; i++)
	{
		// int lib = test(i, printf);
		// int	lft = test(i, ft_printf);
		int lib;
		int lft;
		printf (" => lib test %d: return: %d\n", i, lib = test(i, printf));
		printf (" => lft test %d: return: %d\n", i, lft = test(i, ft_printf));
		if (lib != lft)
		{
			printf ("Wrong! in case: %d, lib: %d, lft: %d\n", i, lib, lft);
			return (-1);
		}
	}
	return (0);
}