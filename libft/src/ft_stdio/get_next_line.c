/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 21:16:04 by bmontoya          #+#    #+#             */
/*   Updated: 2017/06/20 15:00:26 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftstdio.h>
#include <stdlib.h>
#include <ftstring.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <dstruct/ftlist.h>

t_list	*get_files(int fd, t_list ***head)
{
	static t_list	*files = 0;
	t_list			*file;

	file = files;
	while (file && file->content_size != (size_t)fd)
		file = file->next;
	if (!file && fd >= 0)
	{
		file = ft_lstnew(0, 0);
		file->content_size = fd;
		file->content = ft_strnew(0);
		if (files)
			ft_lstadd(&files, file);
		else
			files = file;
	}
	*head = &files;
	return (file);
}

int		read_file(t_list *file, char **line)
{
	char	*tmp;
	int		rd;
	size_t	size;

	tmp = file->content;
	size = ft_strlen(tmp);
	file->content = malloc(ft_strlen(tmp) + BUFF_SIZE + 1);
	ft_strcpy(file->content, tmp);
	free(tmp);
	rd = read(file->content_size, (char *)file->content + size, BUFF_SIZE);
	if (rd > 0)
		((char *)file->content)[size + rd] = '\0';
	else if (size && !rd)
	{
		*line = file->content;
		file->content = ft_strnew(0);
	}
	else
		free(file->content);
	return (rd == -1) ? rd : rd + size;
}

int		get_next_line(int fd, char **line)
{
	t_list	**head;
	t_list	*file;
	char	*text;
	int		ret;

	if (!line || fd < 0)
		return (-1);
	file = get_files(fd, &head);
	*line = 0;
	while (!*line)
	{
		if ((text = ft_strchr(file->content, 0x0a)))
		{
			*text++ = '\0';
			*line = ft_strdup(file->content);
			ft_strcpy(file->content, text);
			break ;
		}
		if ((ret = read_file(file, line)) < 1)
		{
			ft_lstdelnode(head, file);
			return (ret);
		}
	}
	return (1);
}
