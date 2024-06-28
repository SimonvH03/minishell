#include "../minishell.h"

// Frees *ptr if != NULL, then sets it to NULL
// geen protection op *ptr? ptr kan NULL zijn-> write error
// void	free_setnull(void **ptr)
// {
// 	if (ptr && *ptr)
// 		free(*ptr);
// 	*ptr = NULL;
// }

// Frees *ptr if != NULL
// boeie, gewoon doen ook als het wel NULL is, gebeurt toch weinig
// void	free_if(void *ptr)
// {
// 	if (ptr)
// 		free(ptr);
// }

// Frees variable amount of pointers (if != NULL)
// leip, houden
void	free_va(int amount, ...)
{
	va_list	ptrs_to_free;
	short	i;

	va_start(ptrs_to_free, amount);
	i = 0;
	while (i < amount)
	{
		free_if(va_arg(ptrs_to_free, void *));
		++i;
	}
	va_end(ptrs_to_free);
}

// zet deze in je eigen libft, erg handig [-----------> libft/ft_free_array.c <-----------]
// void	ft_free_array(char **arr)
// {
// 	int	i;

// 	if (!arr)
// 		return ;
// 	i = 0;
// 	while (arr[i] != NULL)
// 	{
// 		free(arr[i]);
// 		arr[i] = NULL; // dit mag niet btw
// 		++i;
// 	}
// 	free(arr);
// 	arr = NULL;
// }
