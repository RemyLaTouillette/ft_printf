#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct	s_pf
{
	size_t		content_size;
	char		*sub;
	char		*flag; // '0', -, +, #, ' '
	int			length;

	int			preci;
	int			ispreci;

	int			lpad;
	int			rpad;
	char		pad;

	char		modif; // h H(hh) l L(ll) j z

	char		format; // sSpdDiouUxXcC
	struct s_pf	*nxt;
}				t_pf;
void 	display(t_pf *l) {
	printf("[DISPLAY]\n");
	while(l->nxt != NULL)
	{
		printf("	[while] |%s|\n", l->sub);
		l = l->nxt;
	}
	printf("	[noloop] |%s|\n", l->sub);
}
char			*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char		*str;

	if (s != NULL)
	{
		str = (char *)malloc(sizeof(char) * len + 1);
		if (str == NULL)
			return (NULL);
		i = 0;
		while (start < strlen(s) && i < len)
		{
			str[i] = s[start];
			i++;
			start++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
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
		lst->sub = memcpy(ccpy, sub, content_size);
		lst->content_size = content_size;
	}
	lst->nxt = NULL;
	return (lst);
}


t_pf 		*next_occ(char *s, int *i)
{
	t_pf	*rtn;
	char	*tmpstr;
	int	start;
	int	end;

	printf("[NEXT_OCC]\n");
	start = *i;
	rtn = NULL;
	if (s && s[start] != '\0')
	{
		end = start + 1;
		if (s[end] != '\0' && s[end] == '%')
		{
			while (s[end] != '\0' && s[end] == '%')
			{
				end++;
				printf("YOLO\n");
			}
		}
		while (s[end] != '\0' && s[end] != '%')
			++end;
		printf("%d | %d\n",start, (end - start));
		tmpstr = ft_strsub(s,start,(end - start));
		printf("	[tmpstr] |%s|\n",tmpstr);
		rtn = pf_new(tmpstr,strlen(tmpstr));
		free(tmpstr);
		*i = end;
	}
	else
		*i = -1;
	return (rtn);
}

t_pf		*parse_input(char *str)
{
	t_pf	*hd;
	t_pf	*tmp;
	int	i;
	int	len;

	printf("[PARSE_INPUT]\n");
	i = 0;
	hd = NULL;
	len = strlen(str);
	if (len > 0)
	{
		hd = next_occ(str,&i);
		tmp = hd;
		while(i != -1)
		{
			tmp->nxt = next_occ(str,&i);
			tmp = tmp->nxt;
		}
	}
	return (hd);
}

int 		main(int argc, char **argv) {
	t_pf	*lst;

	if (argc >= 2)
	{
		lst = parse_input(argv[1]);
		display(lst);
	}
//	printf("bonjour %d", 12);
}
