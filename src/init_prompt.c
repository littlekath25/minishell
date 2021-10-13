/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_prompt.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 15:51:53 by kfu           #+#    #+#                 */
/*   Updated: 2021/10/13 18:00:22 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	init_prompt(void)
{
	char	*line;

	while (1)
	{
		activate_signals();
		line = read_line("minishell> ");
		if (!line)
			shell_exit(err_exit);
		if (*line)
		{
			add_history(line);
			if (create_commands_list(line) == 1 && set_redirects() != -1)
			{
				if (g_shell->cmd->tokens->items[0] != NULL)
				{
					handle_heredoc(g_shell->cmd);
					deactivate_signals();
					init_executor();
				}
			}
			free_command_and_tokens();
		}
		free(line);
	}
}
