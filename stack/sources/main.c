#include "../headers/stack.h"
#include <stdio.h>
#include <stdbool.h>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define NC "\033[0m"
static bool UNITTEST_init_stack(void);
static bool UNITTEST_free_stack(void);
static bool UNITTEST_push_stack(void);
static bool UNITTEST_pop_stack(void);
static void UNITTEST_run();


int main(void)
{
	UNITTEST_run();	

	return 0;
}	

bool UNITTEST_init_stack(void)
{
	printf("TEST %s", __func__);

	struct stack* stack = init_stack();

	if(stack == NULL)
		return true;
	return false;
}

bool UNITTEST_free_stack(void)
{
	printf("TEST %s", __func__);

	struct stack* stack = init_stack();
	int data0 = 0;

	stack = push_stack(stack, &data0);
	stack = push_stack(stack, &data0);
	stack = push_stack(stack, &data0);


	stack = free_stack(stack);

	if(stack == NULL)
	{
		return true;
	}
	return false;

}

bool UNITTEST_push_stack(void)
{
	printf("TEST %s", __func__);

	struct stack* stack = init_stack();

	if(stack == NULL)
	{
		int data0 = 1;
		int data1 = 2;
		int data2 = 3;

		stack = push_stack(stack, &data0);
		stack = push_stack(stack, &data1);
		stack = push_stack(stack, &data2);


		if(*(int*)stack->data == data2 && *(int*)stack->node->data == data1 && *(int*)stack->node->node->data == data0 && (int*)stack->node->node->node == NULL)
		{
			return true;
		}
	}
	return false;

}

bool UNITTEST_pop_stack(void)
{
	printf("TEST %s", __func__);

	struct stack* stack = init_stack();

	if(stack == NULL)
	{
		int data0 = 1;
		int data1 = 2;
		int data2 = 3;


		stack = push_stack(stack, &data0);
		stack = push_stack(stack, &data1);
		
		stack = pop_stack(stack);

		if(*(int*)stack->data == data0)
		{
			stack = push_stack(stack, &data1);
			stack = push_stack(stack, &data2);

			stack = pop_stack(stack);
			if(*(int*)stack->data == data1)
			{
				stack = push_stack(stack, &data2);
				stack = pop_stack(stack);
				stack = pop_stack(stack);
				stack = pop_stack(stack);

				if(stack == NULL)
				{
					return true;
				}
				else 
				{
					return false;
				}
			}
			else 
			{
				return false;
			}
		}
		else
		{
			return false;
		}

	}

	return false;
}	

void UNITTEST_run()
{
	if(UNITTEST_init_stack())
	{
		printf("\t%sOK%s\n\n", GREEN, NC);
	}
	else 
	{
		printf("\t%sKO%s\n\n", RED, NC);
	}


	if(UNITTEST_push_stack())
	{
		printf("\t%sOK%s\n\n", GREEN, NC);
	}
	else 
	{
		printf("\t%sKO%s\n\n", RED, NC);
	}

	if(UNITTEST_pop_stack())
	{
		printf("\t%sOK%s\n\n", GREEN, NC);
	}
	else 
	{
		printf("\t%sKO%s\n\n", RED, NC);
	}

	
	if(UNITTEST_free_stack())
	{
		printf("\t%sOK%s\n\n", GREEN, NC);
	}
	else
	{
		printf("\t%sKO%s\n\n", RED, NC);
	}

}




















