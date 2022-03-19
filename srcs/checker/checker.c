#include "includes.h"

void    _gnl_clean_(char *str)
{
    free(str);
}

int    _do_prompt_instructions_(t_data *a, t_data *b)
{
    char *str;

    str = __gnl(0);
    while (str)
    {
        if (!_stdin_parsing_(str))
            return (_ERROR_);
        _gnl_clean_(str);
        str = gnl(0);
    }
    return (_SUCCESS_)
}

int main(int ac, char **av)
{
    t_data      *a;
    t_data      *b;
    t_op        *op;

    op = init_op();
	if (_init_stacks_(&a, &b) == _ERROR_)
		return (0);
	if (_parse_(ac, av, a) == _ERROR_)
		return (_clean_(a, b, op), ft_putstr_fd("Error\n", 2));
	if (_init_(a) == _ERROR_)
		return (_clean_(a, b, op), ft_putstr_fd("Error\n", 2));
    if (_do_prompt_instructions_(a, b) == _ERROR_)
		return (_clean_(a, b, op), ft_putstr_fd("Error\n", 2));
    if (_is_sorted_stack_(a))
		return (_clean_(a, b, op), ft_putstr_fd("OK", 2));
    else
		return (_clean_(a, b, op), ft_putstr_fd("KO", 2));
}