/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:25:54 by hgeorges          #+#    #+#             */
/*   Updated: 2025/12/03 10:39:11 by epetrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "push_swap.h"

// list_basic.c
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *n);
void	ft_lstadd_front(t_list **lst, t_list *n);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));

// list_utils.c
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_lstsize(t_list *lst);
t_list	*ft_lstprevious(t_list *lst);

#endif