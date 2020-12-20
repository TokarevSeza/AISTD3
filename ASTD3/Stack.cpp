#include"Stack.h"

void Stack::reset_stack()
{
	tail = nullptr;
	stack_size = 0;
}

void Stack::S_add_first(int elem)
{
	tail = new Node(elem);
}

void Stack::push_back(int elem)
{
	if (stack_size == 0)
		S_add_first(elem);
	else
	{
		Node* temp = new Node(elem);
		temp->prev = tail;
		tail = temp;
	}
	stack_size++;
}

void Stack::pop_back()
{
	if (stack_size == 1)
	{
		delete tail;
		reset_stack();
	}
	else
	{
		Node* temp = tail->prev;;
		delete tail;
		tail = temp;
		stack_size--;
	}
}

bool Stack::IsEmpty()
{
	if (stack_size == 0)
		return true;
	else
		return false;
}

int Stack::return_last()
{
	return tail->data;
}