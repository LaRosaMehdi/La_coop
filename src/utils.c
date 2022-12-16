#include "../include/include.h"

void afflist(t_list *list, char *name)
{
    while (list)
    {
        printf("		--------------------\n\
		| Affichage %s  |\n\
		---------------------\n\
			%s\n", name, list->content);
        list = list->next;
    }
}

t_list *ft_lstadd(t_list **alst, t_list *new)
{
    t_list *tmp;

    tmp = *alst;
    if (tmp)
    {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
    else
        *alst = new;
    return (new);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

char *ft_strchr(const char *s, int c)
{
    while (*s != (char)c)
    {
        if (!*s++)
            return (NULL);
    }
    return ((char *)s);
}

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void ft_putstr(char *str)
{
    int i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
    char *str;
    size_t i;

    i = 0;
    if (!s)
        return (NULL);
    if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
        return (NULL);
    while (i < len)
    {
        str[i] = s[start + i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char **ft_split (char *str)
{
    int i = 0;
    int j = 0;
    //int save = 0;
    //int tmp = 0;
    char **tab = malloc(sizeof(char *) * ft_strlen(str) + 1);

    while (str[i] != '\0')
    {
        if (str[i] == '-')
        {
            //save = i;
            tab[j] = ft_strsub(str, 0, i);
            str = str + i;
            i = 0;
            j++;
        }
        else if (str[i] == '"')
        {
            i = i + 1;
            while(str[i] != '"')
                i++;
            tab[j] = ft_strsub(str, 0, i);
            str = str + i + 1;
            i = 0;
            j++;
        }
        else if (str[i] == '\'')
        {
            i = i + 1;    
            tab[j] = ft_strsub(str, 0, i + 1);
            str = str + i + 1;
            i = 0;
            j++;
        }
        else
        {
            tab[j] = ft_strsub(str, 0, i);
            str = str + i;
            i = 0;
            j++;
        }
        //printf("tab[%d] = %s et la taille = %d\n", j, tab[j], ft_strlen(tab[j]));
        i++;
    }
    tab[j] = ft_strsub(str, 0, i + 1);
    tab[j + 1] = NULL;
    return (tab);
}

void afftab(char **tab)
{
    int i = 0;
    while (tab[i])
    {
        printf("tab[%d] = %s et la taille = %d\n", i, tab[i], ft_strlen(tab[i]));
        i++;
    }
}
