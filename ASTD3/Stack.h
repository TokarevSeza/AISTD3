#pragma once
class Stack
{
private:
	void reset_stack();
	void S_add_first(int elem);

	class Node
	{
	public:
		Node(int data, Node* prev = nullptr) {
			this->data = data;
			this->prev = prev;
		};
		~Node() {};

		int data;
		Node* prev;
	};

	Node* tail;
	size_t stack_size;

public:
	Stack()
	{
		reset_stack();
	}
	~Stack()
	{
		if (tail)
		{
			while (tail->prev)
				pop_back();
			reset_stack();
		}
	}

	void push_back(int Elem);
	void pop_back();
	bool IsEmpty();
	int return_last();
};