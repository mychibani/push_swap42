#ifndef FONCTIONS_H
# define FONCTIONS_H

typedef struct s_stack		t_stack;
typedef struct s_data		t_data;
typedef struct s_list		t_list;

struct s_stack
{
	int	data;

	t_stack *prev;
	t_stack *next;
};

struct s_data
{
	t_stack		*head;
	size_t		size;
	char		*string;
	int			*index_tab;
};

struct s_list
{
	void	*content;
	t_list	*next;
};

enum	e_op
{
	PA,
	PB,
	SA,
	SB,
	SS,
	RA,
	RB,
	RRA,
	RRB,
	RRR,
};

//init
t_data		*_init_stacks_(t_data **a, t_data **b);
int			_sorting_prep_(t_data *a)
int			_init_(t_data *a);
int			_is_duplicate_elem_(t_data *a);
int			_is_sorted_stack_(t_data *a);
int			*_init_index_tab(int size);
int			_index_sort(t_data *a);

//parsing
int			_parse_(int ac, char **av, t_data *prog);
int			ft_atoi(char *str);
int			ft_strlen(char *str);
int			ft_isdigit(char c);
int			ft_putstr_fd(char *str, int fd);
int			ft_check_str(char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *str);

//lst_utils
void		ft_lstadd_back_data(t_data *a, int data);
void		ft_lstpush_back_data(t_data *data, t_stack *node);
void		ft_lstpush_front_data(t_data *data, t_stack *node);
t_stack		*ft_lstnew_doubly_linked(int data);

//tests_utils
void		ft_print_elem(t_stack *node);
void		_print_data_(t_data *data);
void		_clean_(t_data *a, t_data *b);
void		_swap_(t_data *data, t_data *b);

//operations
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

//algorithms

#endif
