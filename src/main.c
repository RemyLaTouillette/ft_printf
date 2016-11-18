#include <ft_printf.h>

#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	//	ft_printf("Hello world! %s et test %");
	//	ft_printf("zz %s a %d#-LLd %% hey", "test");



	//	ft_printf("zz %s a %.2d#-LLd %hey");
	//	ft_printf("%x %X %p %20.15d\n");

	//	ft_printf("\n\n|%l|\n\n",130);


//	ft_printf("%-10d% d%+d%010d%hhd\n");

//	ft_printf("%-10d % d%   dqd dqw d%010d%hhd\n");




	ft_printf("   %0-hhs    %d %C","HELLO THERE", 42, 42);

	printf("|%u|\n", 42);
	printf("|%u|\n", 8);


//	printf("%ss","TEST");



	//ft_printf("%-10d% d %+d%010d %hhd\n");


	//	ft_printf("%jd %zd %u %o %#08x\n");
	//	ft_printf("%x %#X %S %s%s\n");




	return (0);
}
