#include "../headers/stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

struct stack* init_stack(void)
{
	return NULL;
}
	
struct stack* free_stack(struct stack* p_stack)
{
	while(p_stack != NULL)
	{
		p_stack = pop_stack(p_stack);
	}

	return p_stack;
}

struct stack* push_stack(struct stack* p_stack, void* data)
{
	struct stack* node = init_stack();

	errno = 0;
	node = malloc(sizeof(*node));
	
	if(node == NULL)
	{
		fprintf(stderr, "%s:%d in function \"%s\" : %s", __FILE__ , __LINE__, __func__, strerror(errno));
		return init_stack();
	}

	node->data = data;
	node->node = p_stack;

	return node;
}

struct stack* pop_stack(struct stack* p_stack)
{
	if(p_stack != NULL)
	{
		struct stack* node_next_save = p_stack->node;
		free(p_stack);
		return node_next_save;
	}

	return init_stack();
}

