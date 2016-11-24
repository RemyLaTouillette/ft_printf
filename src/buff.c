#include <ft_printf.h>

int		getSize(t_pf *start)
{
	int	rtn;

	rtn = 0;
	while (start)
	{
		rtn += start->content_size;
		start = start->nxt;
	}
	return (rtn);
}

/*
void	whatever_to_str(t_pf *l)
{
	while (l)		
	{
		
	}
}
*/

void	concatRez(char *s, t_pf *l)
{
	while (l)
	{
		ft_strcat(s, l->sub);
		l = l->nxt;
	}
}

char	*createBuffer(t_pf *start)
{
	char	*rtn;
	int	totalSize;

	totalSize = getSize(start);
	rtn = (char *)malloc(sizeof(char *) * (totalSize + 2));
//	whatever_to_str(start);
	concatRez(rtn, start);
	printf("\n[totalSize]=>|%d|\n", totalSize);
	printf("[RTN      ]=>|%s|\n", rtn);
	start = start->nxt;
	return (rtn);
}
