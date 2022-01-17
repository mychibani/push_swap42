#ifndef FCT_H
# define FCT_H

typedef struct s_stack		t_stack;
typedef struct s_data		t_data;

struct s_stack
{
	int	data;

	t_stack *prev;
	t_stack *next;
};

struct s_data
{
	char		*string;
	t_stack		*head;
	size_t		nbr_elem_a;
	size_t		nbr_elem_b;
	size_t		size;
};

int			_init_(t_data *prog_data);
int			_parse_(int ac, char **av, t_data *prog);
int			ft_atoi(char *str);
int			ft_strlen(char *str);
int			ft_isdigit(char c);
int			ft_putstr_fd(char *str, int fd);
int			ft_check_str(char *str);
void		ft_lstpush_back_data(t_data *lst, int nb);
void		ft_lstpush_front_data(t_data *lst, int nb);
void		ft_print_elem(t_stack *node);
void		_print_data(t_data *a);
void		_clean_(t_data *stack);
void		_swap_(t_data *meta_data);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *str);
t_stack		*ft_lstnew_doubly_linked(int data);

#endif
