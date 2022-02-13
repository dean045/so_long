/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:56:01 by brhajji-          #+#    #+#             */
/*   Updated: 2022/02/08 12:23:06 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*ft_nul(char *tmp)
{
	free(tmp);
	return (NULL);
}

int	r_buf(char *buf, int fd, int BUFFER_SIZE)
{
	int	ret;

	ret = read(fd, buf, BUFFER_SIZE);
	if (ret == -1)
		return (-1);
	buf[ret] = '\0';
	return (ret);
}

char	*get_next_line(int fd, int BUFFER_SIZE)
{
	static char	*tmp;
	char		*buf;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!tmp || ft_get_n(tmp) <= 0 || ft_get_n(tmp) == ft_strlen(tmp))
	{
		if (r_buf(buf, fd, BUFFER_SIZE) == -1)
			return (ft_nul(buf));
		tmp = ft_join(tmp, buf);
		if (ft_strlen(buf) < BUFFER_SIZE)
			break ;
	}
	free(buf);
	result = ft_substr(tmp, ft_get_n(tmp));
	if (tmp && ft_strlen(tmp) > ft_get_n(tmp) + 1)
		tmp = ft_strdup(tmp, tmp + ft_get_n(tmp) + 1, 1);
	else if (tmp)
		tmp = ft_nul(tmp);
	return (result);
}
