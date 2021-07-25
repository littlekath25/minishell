/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unset.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/01 18:06:07 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/25 17:30:28 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "shell.h"

/*
	Each variable or function specified in argv shall be unset.
	Ignores an argument if the variable was not set.
*/
void	_unset_(char **argv)
{
	int	i;

	argv++;
	while (*argv)
	{
		i = vector_indexof(g_shell->env, *argv, ft_strlen(*argv));
		if (i != -1)
		{
			free(vector_getvalue(g_shell->env, i));
			vector_removeat(g_shell->env, i);
		}
		argv++;
	}
	free(__environ);
	__environ = vector_tostrarray(g_shell->env);
	if (!__environ)
		exit(0);
}