#ifndef FCT_H
# define FCT_H

typedef struct s_list		t_list;
typedef struct s_stack		t_stack;

struct s_list
{
	int	data;

	t_list *prev;
	t_list *next;
};

struct s_stack
{
	t_list *head;
	size_t size;		

};

char    *ft_strdup(char *str);
int		nbr_check(char *str, int size);
int     ft_strlen(char *str);
int     ft_isdigit(char c);
int		ft_putstr_fd(char *str, int fd);
char    *ft_strjoin(char *s1, char *s2);
int     ft_check_str(char *str);
int     _parse_(int ac, char **av);
t_list  *ft_lstnew_doubly_linked(int data);
void    ft_lstpush_back_stack(t_stack *lst, t_list *node);
void    ft_lstpush_front_stack(t_stack *lst, t_list *node);
void    ft_print_elem(t_list *node);
void    _print_stack(t_stack *a);
void    _clean_(t_stack *list);
void    _swap_(t_stack *meta_data);

#endif
