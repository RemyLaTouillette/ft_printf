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
		printf("TYPE	|%s|\n\n", l->format);
		display(l->nxt);
	}
	else
		printf("\n////////////////////////////////////\n\n");
}

void		*string_type(va_list ap)
{
	ap = NULL;
	return NULL;
}

t_form		*createArray()
{
	/*MUST BE FREE*/
	t_form	*tab;

	tab = (t_form *)malloc(sizeof(t_form *) * 5);
	//tab = {{"sS", string_type}};
	//tab[0] = ("sS",string_type);
	tab[0].flag = "sS";
	tab[0].val = string_type;
	return	tab;
}
