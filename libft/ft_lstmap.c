/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:26:25 by jomanuel          #+#    #+#             */
/*   Updated: 2024/11/15 17:23:59 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*node;
	void	*content;

	newlst = NULL;
	while (lst)
	{
		content = f(lst->content);
		if (!content)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		node = ft_lstnew(content);
		if (!node)
		{
			del(content);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, node);
		lst = lst->next;
	}
	return (newlst);
}

/*#include <stdio.h>
#include <stdlib.h>

void *increment(void *content)
{
    int *value = (int *)content;
    int *new_value = (int *)malloc(sizeof(int));
    if (new_value)
        *new_value = *value + 1;
    return new_value;
}

void del(void *content)
{
    free(content);
}

void print_list(t_list *lst)
{
    while (lst)
    {
        printf("%d -> ", *((int *)lst->content));
        lst = lst->next;
    }
    printf("NULL\n");
}

int main()
{
    // Create a simple linked list with integer data
    int *a = malloc(sizeof(int)); 
	*a = 1;
    int *b = malloc(sizeof(int)); 
	*b = 2;
    int *c = malloc(sizeof(int)); 
	*c = 3;

    t_list *lst = ft_lstnew(a);
    lst->next = ft_lstnew(b);
    lst->next->next = ft_lstnew(c);

    printf("Original list:\n");
    print_list(lst);

    t_list *mapped_lst = ft_lstmap(lst, increment, del);

    printf("Mapped list (incremented):\n");
    print_list(mapped_lst);

    ft_lstclear(&lst, del);
    ft_lstclear(&mapped_lst, del);

    return 0;
}*/
