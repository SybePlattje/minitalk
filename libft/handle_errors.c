/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_errors.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: splattje <splattje@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/06 10:17:53 by splattje      #+#    #+#                 */
/*   Updated: 2024/01/15 10:04:42 by splattje      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_errors(char *error_msg)
{
	ft_fprintf(2, "Error %s\n", error_msg);
	exit(EXIT_FAILURE);
}
