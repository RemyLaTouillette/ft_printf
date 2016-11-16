#include <ft_printf.h>

void		*int_type(va_list ap)
{
	int		rtn;
	void	*ptr;

	rtn = va_arg(ap, int);
	printf("[INT_TYPE]|%d|\n",rtn);
	ptr = malloc(sizeof(int));
	*((int*)ptr) = rtn;

	printf("[INT_TYPE]|%d|\n",*((int*)ptr));
//	*((int*)ptr
	return ptr;
}

void		*string_type(va_list ap)
{
	char 	*rtn;

	rtn = va_arg(ap, char*);
	return rtn;
}

t_form		*createArray(int *i)
{
	/*MUST BE FREE*/
	t_form	*tab;

	tab = (t_form *)malloc(sizeof(t_form *) * 5);
	tab[0].flag = 's';
	tab[0].func = string_type;
	tab[1].flag = 'd';
	tab[1].func = int_type;
	tab[2].flag = 'i';
	tab[2].func = int_type;
	*i = 3;
	return	tab;
}
