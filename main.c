/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:45:12 by pnamnil           #+#    #+#             */
/*   Updated: 2023/09/09 16:46:49 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int    test(int test_nb, int (*fn)(const char *, ...))
{
	switch (test_nb)
	{
		case 1:
			return fn("Test worked\n");
		case 2:
			return fn("Test worked%%\n");
		default:
			break;
	}
    return (-1);
}

int main(void)
{
	for (int i = 1; i <= 2; i++)
	{
		int lib = test(i, printf);
		int	lft = test(i, ft_printf);
		if (lib != lft)
		{
			printf ("Wrong! in case: %d, lib: %d, lft: %d\n", i, lib, lft);
			return (-1);
		}
	}
	return (0);
}