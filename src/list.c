#include <ft_printf.h>

void	init_blank(t_pf *lst)
{
	lst->sub = NULL;
	lst->content_size = 0;
	lst->flag = NULL;
	lst->length = 0;
	lst->preci = 0;
	lst->ispreci = 0;
	lst->lpad = 0;
	lst->rpad = 0;
	lst->padvalue = 0;
	lst->pad = 0;
	lst->modif = NULL;
	lst->format = ' ';
	lst->nxt = NULL;
	lst->is_perper = 0;
}

t_pf	*pf_new(void const *sub, size_t content_size)
{
	t_pf	*lst;
	void	*ccpy;

	lst = (t_pf *)malloc(sizeof(t_pf));
	ccpy = (void *)malloc(content_size);
	if (!lst || !ccpy)
		return (NULL);
	init_blank(lst);
	lst->sub = ft_memcpy(ccpy, sub, content_size);
	lst->content_size = content_size;
	return (lst);
}

void	free_lst(t_pf *lst)
{
	t_pf	*tmp;

	if (lst)
	{
		tmp = lst;
		free_lst(lst->nxt);
		free(tmp);
	}
}
