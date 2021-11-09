/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/24 11:02:23 by katherine     #+#    #+#                 */
/*   Updated: 2021/11/03 15:11:25 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	free_heredocs(t_heredoc *head)
{
	t_heredoc	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->delimiter);
		free(tmp);
	}
}

void	free_commands(t_command *head)
{
	t_command	*tmp;

	while (head)
	{
		tmp = head;
		head = head->pipe;
		ft_free_split(tmp->tokens->items);
		free(tmp->tokens);
		free(tmp);
	}
}

void	free_command_and_tokens(void)
{
	free_heredocs(g_shell->heredocs);
	g_shell->heredocs = NULL;
	free_commands(g_shell->cmd);
	g_shell->cmd = NULL;
	free(g_shell->info->buffer);
	free(g_shell->info);
}
