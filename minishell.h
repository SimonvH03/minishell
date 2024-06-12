typedef struct s_cmd_node
{
	char	*content;
	void	*next;
}	t_cmd_node;

typedef struct s_sig_argument
{
	t_cmd_node	**cmd_head; // can be used as single pointer, head stored in sig_argument node only
	char		**cmd_array;
	int			token;
	void		*next;
}	t_sig_argument;
