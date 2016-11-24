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

void	concatRez(char *s)
{
	s[0] = 'T';
}

char	*createBuffer(t_pf *start)
{
	char	*rtn;
	int	totalSize;

	totalSize = getSize(start);
	rtn = (char *)malloc(sizeof(char *) * (totalSize + 1));
	concatRez(rtn);
	printf("\n[totalSize]=>|%d|\n", totalSize);
	printf("[RTN      ]=>|%s|\n", rtn);
	start = start->nxt;
	return (rtn);
}
