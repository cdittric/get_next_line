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
