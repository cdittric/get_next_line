# get_next_line
My diarrhea inducing get_next_line.

- Doesn't use libft 🙂
- Questionnably complies to 42born2code's norm (Actually it doesn't but norminette doesn't detect it)
- Reallocates the line buffer by adding BUFSIZE bytes each time, which is bad for very long lines.
- Obscure naming of most identifiers.
- ft_printf.c is 42 lines long.
- Features comments!

#### get_next_line.h
```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdittric <cdittric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 23:16:19 by cdittric          #+#    #+#             */
/*   Updated: 2017/11/30 15:20:31 by cdittric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 32

/*
** t_f: Chained file info list element
** d	File descriptor
** s	Line buffer size
** b	Line buffer
** t	Pointer to temporary buffer used when reallocating line buffer
** r	Read buffer
** i	Index of next character to read in read buffer
** j 	Number of characters in read buffer
** k	Line buffer iterator
** n	Next element in chained list
*/

typedef struct	s_f
{
	int				d;
	int				s;
	char			*b;
	char			*t;
	char			r[BUFF_SIZE];
	int				i;
	int				j;
	int				k;
	struct s_f		*n;
}				t_f;

int				get_next_line(const int fd, char **line);

#endif
```

#### get_next_line.c
```c
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
```

As pushed on vogsphere@vogsphere.42.fr:intra/2017/activities/get_next_line/cdittric
