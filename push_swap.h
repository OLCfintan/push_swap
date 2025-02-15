/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mouk <oel-mouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 06:31:51 by oel-mouk          #+#    #+#             */
/*   Updated: 2024/06/24 00:24:44 by oel-mouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	int				index;
	int				arr_index;
	int				data;
	int				above_median;
	int				push_cost;
	int				rotate_cost;
	struct s_stack	*next;
	struct s_stack	*target;
}					t_stack;

// operations1
void				swap_data(int *a, int *b);
void				swap(t_stack **B, char *op);
void				push(t_stack **A, t_stack **B, char *op);
void				rotate(t_stack **stack, char *op);
void				r_rotate(t_stack **stack, char *op);

// push_swap_utils
void				last_rotat(t_stack **stack, t_stack *top, char c);
void				update_position(t_stack *stack);

// push_swap commands
void				push_swap(t_stack **A, int chunksize);
void				sort_2(t_stack **stack);
void				sort_3(t_stack **stack);
void				sort_5(t_stack **stack_a);

// string operations
int					ft_atoi(const char *str, char **numbers, t_stack **stack);
int					ft_strncmp(char *s1, char *s2, size_t n);
int					ft_intcmp(int a, int b);
int					ft_isdigit(int c);
void				ft_perror(int e, char *err);

// lst search
int					ft_lstget_max(t_stack *stack);
int					ft_lstgmin(t_stack *stack);
t_stack				*ft_lstbfr_last(t_stack *stack);
t_stack				*ft_lstlast(t_stack *lst);

// lst_management
t_stack				*lst_new(int data);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
int					ft_lstsize(t_stack *lst);
void				ft_lstclear(t_stack **lst);
int					ft_islst_sorted(t_stack **stack);

// ft_put_in_fd
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putstr_fd(char *s, int fd);

// ft_split
char				**ft_split(char const *s, char c);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_calloc(size_t num_elements, size_t element_size);
void				free_strs(char **strs);

// check_errors
int					check_dups(t_stack *stack);
int					check_input(char **strs);
void				init_stack(char **numbers, t_stack **stack);

// sorting_utils
int					*list_to_arr(t_stack *stack);

size_t				ft_strlen(const char *s);
void				*ft_memcpy(void *dst, const void *src, size_t n);
char				*ft_strdup(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
t_stack				*check_args(int ac, char **av);
void				push_to_b(t_stack **a, t_stack **b, int sort_window);
void				push_to_a(t_stack **a, t_stack **b);
t_stack				*find_b(t_stack *stack, int index);

#endif
