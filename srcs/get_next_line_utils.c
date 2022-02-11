/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:15:26 by brhajji-          #+#    #+#             */
/*   Updated: 2022/02/08 12:24:06 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s || !*s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_get_n(char *tmp)
{
	int	i;

	i = 0;
	if (!tmp || !*tmp)
		return (-1);
	while (tmp[i])
	{
		if (tmp[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

char	*ft_strdup(char *tmp, char *str, int fr)
{
	int		i;
	char	*new;

	if (!str || !*str)
		return (ft_nul(tmp));
	i = -1;
	new = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!new)
		return (NULL);
	while (str[++i])
		new[i] = str[i];
	new[i] = '\0';
	if (fr == 1)
		tmp = ft_nul(tmp);
	return (new);
}

char	*ft_join(char *tmp, char *buf)
{
	int		len1;
	int		len2;
	char	*new;
	int		i;

	if (!tmp && !buf)
		return (NULL);
	len1 = ft_strlen(tmp);
	len2 = ft_strlen(buf);
	new = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!new)
		return (NULL);
	i = -1;
	new[len1 + len2] = '\0';
	while (++i < len1 || i < len2)
	{
		if (i < len1 && tmp[len1 - i - 1])
			new[len1 - i - 1] = tmp[len1 - i - 1];
		if (i < len2 && buf[len2 - i - 1])
			new[len1 + len2 - i - 1] = buf[len2 - i - 1];
	}
	tmp = ft_nul(tmp);
	return (new);
}

char	*ft_substr(char *tmp, int end)
{
	char	*new;
	int		i;

	if (!tmp || !*tmp)
		return (NULL);
	if (end > ft_strlen(tmp))
		return (NULL);
	new = malloc(sizeof(char) * (end + 2));
	if (!new)
		return (NULL);
	i = -1;
	while (++i <= end)
		new[i] = tmp[i];
	new[i] = '\0';
	return (new);
}
