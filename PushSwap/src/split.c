/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 09:13:30 by pfalli            #+#    #+#             */
/*   Updated: 2024/04/09 16:02:13 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	count_words(char *s, char c)
{
	int	count;
	int	inside_word;

	count = 0;
	inside_word = 0;
	while (*s)
	{
		if (*s != c && inside_word == 0)
		{
			count++;
			inside_word = 1;
		}
		else if (*s == c)
			inside_word = 0;
		s++;
	}
	return (count);
}

static char	*substring(char *s, char c)
{
	char		*substring;
	size_t		length;
	static int	i = 0;
	int			x;

	length = 0;
	x = 0;
	while (s[i] == c)
		i++;
	if (s[i] == '\0')
		return (NULL);
	while (s[i + length] != c && s[i + length] != '\0')
		length++;
	substring = malloc((length + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	while ((s[i] != c) && s[i])
	{
		substring[x] = s[i];
		x++;
		i++;
	}
	substring[x] = '\0';
	return (substring);
}

char	**split(char *s, char c)
{
	int		words;
	char	**total_array;
	int		i;

	i = 0;
	words = count_words(s, c);
	if (!words)
		exit(1);
	total_array = malloc((words + 2) * sizeof(char *));
	if (!total_array)
		return (NULL);
	while (words-- >= 0)
	{
		if (i == 0)
		{
			total_array[i] = malloc(sizeof(char));
			if (!total_array[i])
				return (NULL);
			total_array[i++][0] = '\0';
		}
		total_array[i++] = substring(s, c);
	}
	total_array[i] = NULL;
	return (total_array);
}

//  int main(void)
//  {
//     char **total_array = split("15 33 44", ' ');
//     while (*total_array != NULL)
//     {
//          printf("%s\n", *total_array);
//          total_array++;
//     }
//     return (0);
//  }