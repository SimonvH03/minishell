#include "../minishell.h"

t_list	*create_cmd_node(char *content)
{
	t_list	*new_cmd_node;

	new_cmd_node = (t_list *)malloc(sizeof(t_list));
	if (!new_cmd_node)
		return (NULL);
	new_cmd_node->content = content;
	new_cmd_node->next = NULL;
	return (new_cmd_node);
}

// RETURN: head = success, NULL = failure (whole list is freed)
t_list	**new_node_back_cmdlist(t_list **head, char *content)
{
	t_list	*new_cmd_node;
	t_list	*tmp;

	if (!head)
		return (NULL);
	new_cmd_node = create_cmd_node(content);
	if (!new_cmd_node)
		return (free_cmdlist(head), NULL);
	if (!(*head))
		return (*head = new_cmd_node, head);
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp->next = new_cmd_node, head);
}

t_list	*cmdlist_last_node(t_list **head)
{
	t_list	*tmp;

	if (!head || !(*head))
		return (NULL);
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	free_cmdlist(t_list **head)
{
	t_list	*tmp;
	t_list	*tmp_tmp;

	if (!head || !(*head))
		return ;
	tmp = *head;
	while (tmp != NULL)
	{
		free_if(tmp->content);
		tmp_tmp = tmp->next;
		free(tmp);
		tmp = tmp_tmp;
	}
}
