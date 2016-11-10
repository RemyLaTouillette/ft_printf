#include <ft_printf.h>

t_pf	*pf_new(void const *sub, size_t content_size)
{
	t_pf	*lst;
	void	*ccpy;

	lst = (t_pf *)malloc(sizeof(t_pf));
	ccpy = (void *)malloc(content_size);
	if (!lst || !ccpy)
		return (NULL);
	if (!sub || !content_size)
	{
		lst->sub = NULL;
		lst->content_size = 0;
	}
	else
	{
		lst->sub = ft_memcpy(ccpy, sub, content_size);
		lst->content_size = content_size;
	}
	lst->nxt = NULL;
	return (lst);
}
