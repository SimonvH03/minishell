/*
MINISHELL:

	Part list:
	- History management
	- Cmd management
	- File/ dir management
	- Sig management
*/

#include "../minish_param.h"

void	TEST_printline(char *line);

short	sig = 0;

// Initializes struct of all structs: t_dad.
void	init_dad(t_dad *d, char **envp)
{
	d->sig_arg_head = NULL;
	d->prev_line = NULL;
	d->line = NULL;
	d->env_head = create_env_list(envp);
}

// Adds current line to history if:
// line_len > 0 && line != previous line.
// Lastly: strdups line to prev_line.
void	line_history_management(t_dad *d)
{
	const size_t	line_len = ft_strlen(d->line);

	if (line_len && \
	(!d->prev_line || ft_strncmp(d->line, d->prev_line, line_len + 1)))
	{
		add_history(d->line);
		free(d->prev_line);
		d->prev_line = ft_strdup(d->line);
		if (!d->prev_line)
			exit_clean(d, errno, NULL);
	}
}

// Contains the readline() loop.
// FOR TESTING: to print the input of readline() input:
// "print [this will be printed]"
int	main(int argc, char **argv, char **envp)
{
	t_dad	d;

	init_dad(&d, envp);
	while (true)
	{
		rl_on_new_line();
		d.line = readline(C_YELLOW "mini" C_RED " > " C_RESET);
		if (!d.line)
			break ;
		if (syntax_check(d.line))
		{
			TEST_printline(d.line);// TEST
			line_history_management(&d);
			parsing_distributor(&d);
		}
		else
			printf("syntax error\n");
		free(d.line);
	}
	free(d.prev_line);
	rl_clear_history();
	return (0);
}

// TEST FUNCTIONS:
void	TEST_printline(char *line)
{
	if (ft_strlen(line) >= 7 && !ft_strncmp(line, "print ", 6))
		printf("*\n%s\n*\n", line + 6);
}
