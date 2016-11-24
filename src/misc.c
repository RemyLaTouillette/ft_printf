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
		printf("TYPE	|%c|\n", l->format);
		printf("PERPER	|%d|\n", l->is_perper);
		if (l->format == 's')
			printf("VAL S	|%s|\n",(char *)l->val);
		if (l->format == 'd')
			printf("VAL D	|%d|\n",*((int*)l->val));
		printf("\n");
		display(l->nxt);
	}
	else
		printf("\n////////////////////////////////////\n\n");
}
