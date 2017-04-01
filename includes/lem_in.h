/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <jye@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 19:51:05 by jye               #+#    #+#             */
/*   Updated: 2017/02/18 17:52:52 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define CHECKED 21
# define OCCUPIED 42

typedef struct s_lst	t_lst;
typedef struct s_link	t_link;
typedef struct s_node	t_node;
typedef struct s_pathf	t_pathf;
typedef struct s_route	t_route;
typedef struct s_ant	t_ant;

struct					s_lst
{
	struct s_lst	*prev;
	struct s_lst	*next;
	void			*data;
};

struct					s_pathf
{
	struct s_pathf	*prev;
	t_node			*node;
};

struct					s_link
{
	char	*name1;
	char	*name2;
};

struct					s_ant
{
	t_lst			*route;
	unsigned int	id_ant;
};

struct					s_node
{
	char			*name;
	struct s_node	**next;
	unsigned int	nb_link;
	unsigned short	flag;
	unsigned short	io;
};

/*
** LST function
*/
t_lst					*init_lst__(void *data);
void					pop_lst__(t_lst **node, void (*del)());
void					append_lst__(t_lst *node, void *data);
void					push_lst__(t_lst **node, void *data);
/*
** LINK function
*/
t_lst					*init_link(t_lst *lst_data, t_lst *lst_room);
/*
** ROOM function
*/
t_lst					*init_node(t_lst *lst_data);
/*
** CREATE LINK function
*/
void					link_it(t_lst *lst_node, t_lst *lst_link);
/*
** CLR function
*/
void					clr_link(t_link *link);
void					clr_node(t_node *node);
/*
** BFS solver
*/
t_lst					*solve_it(t_node *start);
/*
** Moving ants function
*/
void					move_all(unsigned int nb_ants, t_lst *route);
void					move_ants(unsigned int nb_ants, t_lst *route);
/*
** ETC function
*/
t_lst					*read_args(void);
int						sub_rargs(t_lst **node);
int						get_line(const int fd, char **line);
unsigned int			f_atoi(char *str);
void					f_perror(unsigned int str_err);
char					*get_name(const char *str, char *pattern);
void					swap(void *a, void *b);
void					print_data(t_lst *lst);
#endif
