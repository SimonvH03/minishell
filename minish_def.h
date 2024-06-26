#ifndef MINISH_DEF_H
# define MINISH_DEF_H

// Colors

# define C_RESET "\033[0m"
# define C_TEAL "\033[0;36m"
# define C_YELLOW "\033[0;33m"
# define C_RED "\033[31;1m"

// Typedefs

typedef unsigned int	t_uint;
typedef unsigned char	t_uchar;

// Enums

// please use 0 for SUCCES, 1 for FAILURE, and -1 (setting errno) for everything else
enum	e_function_return
{
	SUCCESS = 1,
	NEUTRAL = 0,
	ERROR = -1,
	MEM_ERR = -2,
	SYNTAX_ERR = -3
};
// enum	e_better_function_return
// {
// 	SUCCESS = 0,
// 	FAILURE = 1,
// 	ERROR = -1
// };

// Token enum:

// ? env_var niet als token gebruiken, maar als cmd node achter cmd head "export" of "unset"
enum	e_tokens
{
	T_NO_ACTION = 0,
	T_COMMAND = 1,
	T_FILE = 2,
	T_BUILTIN = 3,
	T_PIPE = 4,
	T_REDIRECT = 5,
	T_ENV_VAR = 6
};

// STRUCTS

// Cmd and arg structs

typedef struct s_cmd_node
{
	char	*content;
	void	*next;
}	t_cmd_node;

// graag envp nabootsen in een pointer array ipv list;
//	een line toevoegen kan namelijk altijd aan het einde van het array en verwijderen gaat ook met relatief weinig duplication (alleen pointers)
typedef struct s_envariable_list
{
	char	*key;
	char	*value;
	void	*next;
}	t_env_node;

typedef struct s_significant_argument
{
	t_cmd_node	**cmd_head; // can be used as single pointer, head stored in sig_argument node only
	char		**cmd_array;
	short		token;
	void		*next;
}	t_sig_arg;

typedef struct s_father_of_all_structs
{
	t_sig_arg	**sig_arg_head;
	t_env_node	**env_head;
	char		*prev_line;
	char		*line;
}	t_dad;

#endif
