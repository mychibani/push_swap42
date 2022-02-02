#ifndef FONCTIONS_H
# define FONCTIONS_H

typedef struct s_stack		t_stack;
typedef struct s_data		t_data;
typedef struct s_res		t_res;

struct s_stack
{
	int	data;

	t_stack *prev;
	t_stack *next;
};

struct s_data
{
	size_t		size;
	t_stack		*head;
	char		*string;
};

struct s_res
{
	char *op;
	t_res *next;
};


t_data		*_init_stack_(void);
int			_init_(t_data *prog_data);
int			_is_duplicate_elem_(t_data *a);
int			_is_sorted_stack_(t_data *a);
int			_parse_(int ac, char **av, t_data *prog);

int			ft_atoi(char *str);
int			ft_strlen(char *str);
int			ft_isdigit(char c);
int			ft_putstr_fd(char *str, int fd);
int			ft_check_str(char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *str);

void		ft_lstadd_back_data(t_data *a, int data);
void		ft_lstpush_back_data(t_data *data, t_stack *node);
void		ft_lstpush_front_data(t_data *data, t_stack *node);
t_stack		*ft_lstnew_doubly_linked(int data);

void		ft_print_elem(t_stack *node);
void		_print_data_(t_data *data);
void		_clean_(t_data *a, t_data *b);
void		_clean(t_data *a, t_data *b);
void		_swap_(t_data *data, t_data *b);


int			pb(t_data *a, t_data *b);
int			pa(t_data *a, t_data *b);
int			sa(t_data *a);
int			sb(t_data *b);
int			ss(t_data *a, t_data *b);
int			ra(t_data *a);
int			rb(t_data *b);
int			rr(t_data *a, t_data *b);
int			rra(t_data *a);
int			rrb(t_data *a);
int			rrr(t_data *a, t_data *b);

#endif
