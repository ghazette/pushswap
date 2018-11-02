/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gzanarel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 14:15:29 by gzanarel     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/11 15:37:19 by gzanarel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!(ptr = (char *)malloc(size)))
		return (NULL);
	while (i < size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
