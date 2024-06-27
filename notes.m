Arguments are to be handled as such:
because we do not know the number of flags and significant arguments, we start with a linked list.
this list will contain a node for every significant argument.
each argument will have its own sublist, where any number of flags can be added (the list may start with the command, then flags).
	this sublist will later be made into a pointer array.
		this array will simply be 'sizeof(char *) * list_size(command_0)',
		where the 'char *' in the array will simply be the 'char *' content from the list. no need to reallocate!
	after the creation of pointer arrays, sublists can be freed (and heads set to NULL).
each argument will have its own pointer array as described above.
each argument will have its own Token, decided by the Tokenizer.
	tokens are used to prioritize certain actions.

typedef struct s_cmd_node
{
	char	*content;
	void	*next;
}	t_list;

typedef struct s_sig_argument
{
	t_list	**cmd_head; // can be used as single pointer, head stored in sig_argument node only
	char		**cmd_array;
	int			token;
	void		*next;
}	t_sig_argument;
