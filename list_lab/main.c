/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-hoo <svan-hoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:43:12 by svan-hoo          #+#    #+#             */
/*   Updated: 2024/06/27 19:42:15 by svan-hoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_types.h"

int	main(void)
{
	t_list		**cmd_head;
	t_sig_arg_node	**sig_head;

	// set up two command lists, and add them to the significant argument list
	lstadd_back((void **)cmd_head, getnext_string, new_node_string("export")); // command export
	lstadd_back((void **)cmd_head, getnext_string, new_node_string("HELLO=Hello world!"));	// parameter HELLO=Hello world!
	lstadd_back((void **)sig_head, getnext_sig_arg, new_node_sig_arg(cmd_head, NULL, T_COMMAND)); // significant argument "export HELLO=Hello world!"
	lstadd_back((void **)cmd_head, getnext_string, new_node_string("echo")); // command echo
	lstadd_back((void **)cmd_head, getnext_string, new_node_string("$HELLO")); // parameter $HELLO
	lstadd_back((void **)sig_head, getnext_sig_arg, new_node_sig_arg(cmd_head, NULL, T_COMMAND)); // significant argument "echo $HELLO"
}