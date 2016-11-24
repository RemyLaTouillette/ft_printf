#include <ft_printf.h>

void		handle_flags(t_pf *lst)
{
	while (lst)
	{
		lst = lst->nxt;	
	}
}

void		handle_exce(t_pf *lst)
{
	handle_flags(lst);
}
