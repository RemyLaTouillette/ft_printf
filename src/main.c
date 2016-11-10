/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:58:32 by sduprey           #+#    #+#             */
/*   Updated: 2016/11/10 16:35:27 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#include <stdio.h>

//  sSpdDioOuUxXcC

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	//ft_printf("Hello world! %s et test %");

	ft_printf("zz %s a %d#-LLd %% hey", "test");
	printf("%%\n");
	/*
	ft_putendl("\n----------------------");
	ft_putendl("\n----------------------");
	printf("zz % d", 12);
	*/
	//printf("|%5d|\n", 123);
	//printf("|% 10|\n", 123);
	return (0);
}
