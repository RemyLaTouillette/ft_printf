#include <ft_printf.h>

int			ft_printf(char *str, ...)
{
	va_list		ap;
	int		i;
	t_pf		*start;

	start = parse_input(str);
	handle_exce(start);
	free_lst(start);
	va_start(ap, str);
	i = 0;
	return (0);
}
