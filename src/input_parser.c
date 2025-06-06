/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 22:48:16 by mrazem            #+#    #+#             */
/*   Updated: 2025/06/04 22:52:21 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//MASSIVE STRING
char	*join_input(int argc, char **argv)
{
	char	*joined;
	char	*tmp;
	int		i;

	i = 1;
	joined = ft_strdup("");
	while (i < argc)
	{
		tmp = ft_strjoin(joined, argv[i]);
		free(joined);
		joined = ft_strjoin(tmp, " ");
		free(tmp);
		i++;
	}
	return (joined);
}

//CONVERT MASSIVE STRING TO INT ARR
int	*convert_to_int_arr(char **input, int len)
{
	int	*arr;
	int	i;

	i = 0;
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);
	while (i < len)
	{
		arr[i] = ft_atoi(input[i]);
		i++;
	}
	return (arr);
}

//CHECK INT ARRAY FOR DUPLICATES
int	check_duplicates(int *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 1 + i;
		while (j < len)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//COUNT STRJOIN TOKENS
int	count_tokens(char **input)
{
	int	i;

	i = 0;
	while (input[i])
		i++;
	return (i);
}

int	*check_input(int argc, char **argv, int *arr_len)
{
	char	**input;
	char	*joined;
	int		*array;
	int		i;

	i = 0;
	joined = join_input(argc, argv);
	input = ft_split(joined, ' ');
	free(joined);
	if (!input)
		return (NULL);
	while (input[i])
	{
		if (!is_valid_int(input[i]))
			return (ft_free_split(input), NULL);
		i++;
	}
	*arr_len = count_tokens(input);
	array = convert_to_int_arr(input, *arr_len);
	ft_free_split(input);
	if (!array || !check_duplicates(array, *arr_len))
		return (free(array), NULL);
	return (array);
}
