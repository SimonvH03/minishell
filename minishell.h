#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# include "mini_def.h"
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <termios.h>

// Function parameters

// parsing.c

void		parsing_distributor(t_shell *d);

// envp_parse.c

size_t		parse_env_variable(t_shell *d, size_t i);

// envp_init.c

char		**create_envp(char **envp);

// utils_syntax.c

bool		syntax_check(const char *line);

// utils_string.c

char		*strdup_index(char *str, size_t	start, size_t end);

// utils_sig_arg_list.c

t_sig_arg	**new_node_back_arglist(
				t_list **cmd_head,
				char **cmd_arr,
				short token,
				t_sig_arg **head);

t_sig_arg	*arglist_last_node(t_sig_arg **head);
void		free_arglist(t_sig_arg **head);

// utils_cmd_list.c

t_list		**new_node_back_cmdlist(t_list **head, char *content);
t_list		*cmdlist_last_node(t_list **head);
void		free_cmdlist(t_list **head);

// utils_exit.c

void		exit_clean(t_shell *d, int num, char *message);
// void	exit_va_free(t_shell *d, int num, char *message, int amount, ...);

// utils_freeing.c

void		free_setnull(void **ptr);
void		free_if(void *ptr);
void		free_va(int amount, ...);

#endif
