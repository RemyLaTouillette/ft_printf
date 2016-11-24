#include <ft_printf.h>

int				ft_printf(char *str, ...)
{
	va_list		ap;
	int			i;
	char		*rez;
	t_pf		*start;

	va_start(ap, str);
	start = parse_input(str, ap);
	handle_exce(start);
	display(start);
	rez = createBuffer(start);

	ft_putstr("\n[REZ]=>|");
	ft_putstr(rez);
	ft_putstr("|\n");

	free_lst(start);
	va_end(ap);
	i = 0;
	return (i);
}
