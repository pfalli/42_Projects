/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:24:06 by pfalli            #+#    #+#             */
/*   Updated: 2023/11/23 14:45:35 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int a)
{
	if ((a > 47 && a < 58) || (a > 64 && a < 91) || (a > 96 && a < 123))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
