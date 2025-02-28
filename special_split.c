/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:04:20 by jomanuel          #+#    #+#             */
/*   Updated: 2025/02/28 12:34:02 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	count_tokens(const char *s, int count, int i)
{
	char	quote;

	while (s[i])
	{
		while (s[i] && s[i] == ' ')
			i++;
		if (!s[i])
			break ;
		if (s[i] == '\'' || s[i] == '"')
		{
			count++;
			quote = s[i++];
			while (s[i] && s[i] != quote)
				i++;
			if (s[i])
				i++;
		}
		else
		{
			while (s[i] && s[i] != ' ' && s[i] != '\'' && s[i] != '"')
				i++;
			count++;
		}
	}
	return (count);
}

void	quote_token(const char *s, char **token, int *j)
{
	int		start;
	int		len;
	char	quote;
	int		i;

	len = 0;
	i = *j;
	quote = s[i];
	i++;
	start = i;
	while (s[i] && s[i] != quote)
		i++;
	len = i - start;
	*token = (char *) ft_calloc(len + 1, sizeof(char));
	if (!(*token))
		return ;
	ft_strlcpy(*token, s + start, len + 1);
	if (s[i] == quote)
		i++;
	else
	{
		free(*token);
		*token = NULL;
	}
	*j = i;
}

void	space_token(const char *s, char **token, int *j)
{
	int	start;
	int	len;
	int	i;

	i = *j;
	len = 0;
	start = i;
	while (s[i] && s[i] != ' ' && s[i] != '\'' && s[i] != '"')
		i++;
	len = i - start;
	*token = (char *) ft_calloc(len + 1, sizeof(char));
	if (!(*token))
		return ;
	ft_strlcpy(*token, s + start, len + 1);
	*j = i;
}

void	get_token(const char *s, int *index, char **token)
{
	int		i;

	i = *index;
	*token = NULL;
	while (s[i] && s[i] == ' ')
		i++;
	if (!s[i])
	{
		*index = i;
		return ;
	}
	if (s[i] == '\'' || s[i] == '"')
	{
		quote_token(s, token, &i);
		if (!(*token))
			return ;
	}
	else
	{
		space_token(s, token, &i);
		if (!(*token))
			return ;
	}
	*index = i;
}

char	**special_split(const char *s)
{
	int		i;
	int		token_count;
	int		token_index;
	char	**tokens;
	char	*token;

	token_count = count_tokens(s, 0, 0);
	i = 0;
	token_index = 0;
	token = NULL;
	tokens = (char **) ft_calloc((token_count + 1), sizeof(char *));
	if (!tokens)
		return (NULL);
	while (s[i])
	{
		get_token(s, &i, &token);
		if (!token)
		{
			ft_freeall(tokens);
			return (NULL);
		}
		tokens[token_index++] = token;
	}
	tokens[token_index] = NULL;
	return (tokens);
}
