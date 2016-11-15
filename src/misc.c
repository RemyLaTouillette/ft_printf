#include <ft_printf.h>

void		display(t_pf *l)
{
	if (l)
	{
		printf("SUB	|%s|\n", l->sub);
		printf("CSIZE	|%d|\n", (int)l->content_size);
		printf("FLAG	|%s|\n", l->flag);
		printf("PAD	|%d|\n", l->padvalue);
		printf("ISPRECI	|%d|\n", l->ispreci);
		printf("PRECI	|%d|\n", l->preci);
		printf("MODIF	|%s|\n", l->modif);
		printf("TYPE	|%c|\n\n", l->format);
		display(l->nxt);
	}
	else
		printf("\n////////////////////////////////////\n\n");
}

void		*string_type(va_list ap)
{
	char 	*rtn;

	rtn = NULL;
	ft_putstr("[STRING_TYPE]\n");
	rtn = va_arg(ap, char*);		//SEGFAULT
	ft_putstr("\n|");
	ft_putstr(rtn);
	ft_putstr("|\n");
	ap = NULL;
	return rtn;
}

t_form		*createArray(int *i)
{
	/*MUST BE FREE*/
	t_form	*tab;

	tab = (t_form *)malloc(sizeof(t_form *) * 5);
	tab[0].flag = 's';
	tab[0].func = string_type;
	*i = 1;
	return	tab;
}
