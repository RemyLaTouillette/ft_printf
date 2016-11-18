#include <ft_printf.h>

void		*int_type(va_list ap)
{
	int		rtn;
	void	*ptr;

	rtn = va_arg(ap, int);
	ptr = malloc(sizeof(int));
	*((int*)ptr) = rtn;
	return ptr;
}

void		*long_int_type(va_list ap)
{
	long int	rtn;
	void	*ptr;

	rtn = va_arg(ap, long int);
	ptr = malloc(sizeof(long int));
	*((long int*)ptr) = rtn;
	return ptr;
}

void		*void_type(va_list ap)
{
	return (va_arg(ap, void *));
}

void		*string_type(va_list ap)
{
	char 	*rtn;

	rtn = va_arg(ap, char*);
	return rtn;
}

t_form		*createArray(int *i)
{
	// sSpdDiouUxXcC
	// ScC
	/*MUST BE FREE*/
	t_form	*tab;

	tab = (t_form *)malloc(sizeof(t_form *) * 5);
	tab[0].flag = 's';
	tab[0].func = string_type;
	tab[1].flag = 'd';
	tab[1].func = int_type;
	tab[2].flag = 'i';
	tab[2].func = int_type;
	tab[3].flag = 'p';
	tab[3].func = void_type;
	tab[4].flag = 'D';
	tab[4].func = long_int_type;
	tab[5].flag = 'o';
	tab[5].func = int_type;
	tab[6].flag = 'u';
	tab[6].func = int_type;
	tab[7].flag = 'U';
	tab[7].func = int_type;
	tab[8].flag = 'x';
	tab[8].func = int_type;
	tab[9].flag = 'X';
	tab[9].func = int_type;
	tab[10].flag = 'c';
	tab[10].func = int_type;
	tab[11].flag = 'C';
	tab[11].func = int_type;
//	tab[12].flag = 'S';
//	tab[12].func = wide_char_type;
	*i = 11;
	return	tab;
}
