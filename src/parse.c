#include <ft_printf.h>

//ft_printf("zz %s a %d#-LLd %hey");

int			find_percent(char *s, int index)
{
	if (s && (s[index] != '\0')) {
		while (s[index] != '\0')
		{
			if (s[index] == '%')
				return index;
			index++;
		}
	}
	return (ft_strlen(s));
}

void display(t_pf *l) {
	while(l->nxt != NULL)
	{
		ft_putendl(l->sub);
		l = l->nxt;
	}
	ft_putendl(l->sub);
}

t_pf					*parse_input(char *str)
{
	t_pf				*hd;
	t_pf				*curr;
	t_pf				*next;
	unsigned long		index;
	int					nxt_pct;
	char 				*tmp;

	index = 0;
	tmp = ft_strsub(str,0,(index = find_percent(str,0)));
	hd = pf_new(tmp, sizeof(tmp));
	curr = hd;
	while (index < ft_strlen(str))
	{
		index = find_percent(str,index);
		nxt_pct = find_percent(str,index + 1);
		tmp = ft_strsub(str,index,nxt_pct - index);
		next = pf_new(tmp, sizeof(tmp));
		curr->nxt = next;
		curr = curr->nxt;
		index = (nxt_pct + 1);
	}
	display(hd);
	return (hd);
}

/*
   int			count_occ(char *s)
   {
   int 	rtn;
   char	**tmp;
   char	*

   rtn = 0;
   tmp = ft_strsplit(s, "%%");

   return rtn;
   }
   */

