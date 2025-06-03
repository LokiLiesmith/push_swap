/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 21:58:15 by mrazem            #+#    #+#             */
/*   Updated: 2025/06/03 23:34:00 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;

	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' && *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
		result = result * 10 + (*s++ - '0');
	return (sign * result);
}

void	ft_free_split(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

//CHECK IF ONLY 0-9 CHARS AND +-
int	is_valid_int_string(char *s)
{
	int	i;

	i = 0;
	if (!s || !*s)
		return (0);
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

//CHECK IF IN INT MAX-MIN RANGE
int	is_in_int_range(char *s)
{
	long	n;

	n = ft_atol(s);
	return (n >= -2147483648 && n <= 2147483647);
}

int	is_valid_int(char *s)
{
	return (is_valid_int_string(s) && is_in_int_range(s));
}
