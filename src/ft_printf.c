#include <ft_printf.h>

int				ft_printf(char *str, ...)
{
	va_list		ap;
	int			i;
	t_pf		*start;

	va_start(ap, str);
	start = parse_input(str, ap);
	handle_exce(start);
	createBuffer(start);
	free_lst(start);
	va_end(ap);
	i = 0;
	return (0);
}
