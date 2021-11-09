/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/29 16:42:28 by kfu           #+#    #+#                 */
/*   Updated: 2021/11/03 16:00:15 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	shell_exit(int error)
{
	if (error == err_args)
		printf("Please execute without arguments\n");
	if (error == err_malloc)
		printf("Malloc failed\n");
	if (error == err_pipe)
		printf("Pipe failed\n");
	if (error == err_fork)
		printf("Fork failed\n");
	if (error == err_exit)
		printf("exit\n");
	if (error == err_open)
		printf("Open failed\n");
	if (error == err_pwd)
		printf("Unknown error occured\n");
	exit(0);
}
