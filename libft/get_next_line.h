/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behamon <behamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 15:09:22 by behamon           #+#    #+#             */
/*   Updated: 2016/12/15 14:59:39 by behamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define EOL '\n'
# define TRUE 1
# define FALSE 0
# define ERROR -1
# define BUFF_SIZE 256
# include "./libft.h"
# include <unistd.h>
# include <stdlib.h>

int		get_next_line(const int fd, char **line);

#endif
