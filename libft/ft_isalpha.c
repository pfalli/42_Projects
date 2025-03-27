/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:43:34 by pfalli            #+#    #+#             */
/*   Updated: 2023/12/07 10:37:52 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int a)
{
	if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

//	int	main(void)
//	{
//		char	x;
//
//		x = 5;
//		ft_isalpha(x);
//		printf("it's alphabet or not %d", x);
//		return (0);
//	}
//