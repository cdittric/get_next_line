/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdittric <cdittric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 23:16:23 by cdittric          #+#    #+#             */
/*   Updated: 2017/11/30 15:19:18 by cdittric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static t_f		*openfiles;
	t_f				*f;
	int				i;

	f = openfiles;
	while (!(i = 0) && f && f->d != fd)
		f = f->n;
	if (fd < 0 || (!f && (!(f = malloc(sizeof(*f))) ||
		((f->n = openfiles) && 0) || (f->d *= 0) || (f->d += fd) < 0 ||
		!(openfiles = f) || (f->i *= 0) || (f->j *= 0))) || (f->s *= 0))
		return (-1);
	while (!(f->k *= 0) && (f->i < f->j || (!(f->i *= 0) && (f->j = read(fd,
		f->r, BUFF_SIZE)) > 0)) && (f->s == 0 || f->r[f->i] != 10 || !(++f->i)))
	{
		if (i + BUFF_SIZE >= f->s && (f->k -= 1) && ((f->t = f->b) || 1)
				&& (f->b = (char *)malloc(sizeof(char) * (i + BUFF_SIZE + 1))))
			while (++(f->k) < i && (f->k) < f->s)
				free(((f->b[f->k] = f->t[f->k]) && (f->k + 1 < i) ? 0 : f->t));
		if (i + BUFF_SIZE >= f->s && ((!f->b && ((f->b = f->t) || 1))
					|| !(f->s = i + BUFF_SIZE + 1)))
			return (-1);
		while (f->i < f->j && f->r[f->i] != '\n')
			f->b[i++] = f->r[f->i++];
	}
	return ((i || f->j > 0) && (*line = f->b) && !(f->b[i] *= 0) ? 1 : f->j);
}
