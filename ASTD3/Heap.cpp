#include "Heap.h"

void Heap::add_first(int newElem)
{
	Heap* data = new Heap(newElem);
}

void Heap::reset()
{
	heap_size = 0;
}

size_t Heap::get_size()
{
	return this->heap_size;
}

int Heap::min_data(int a, int b)
{
	return (data[a] < data[b] ? a : b);
}

void Heap::swap_data(int one, int two) 
{
	int swap = data[one];
	data[one] = data[two];
	data[two] = swap;
}

bool Heap::contains(int elem)
{
	for (int i = 0; i < heap_size; i++)
		if (data[i] == elem)
			return true;
	return false;
}

void Heap::Up(int elem)
{
	int parent = (elem - 1) / 2;
	while ((data[elem] < data[parent]) && (elem < heap_size)) 
	{
		if (elem % 2) {
			parent = (elem - 1) / 2;
		}
		else {
			parent = (elem - 2) / 2;
		}
		swap_data(elem, parent);
		elem++;
		parent = -1;
	}
}

void Heap::Down(int elem = 0)
{
	int right = elem * 2 + 2, left = elem * 2 + 1;
	int min;
	while ((left < heap_size) && (elem < heap_size))
	{
		if (right < heap_size)
		{
			if (data[elem] > data[left])
			{
				min = min_data(left, right);
				swap_data(min, elem);
			}
			if (data[elem] > data[right])
				swap_data(elem, right);
		}
		if (data[elem] > data[left])
			swap_data(elem, left);
		elem++;
		left = 2 * elem + 1;
		right = 2 * elem + 2;
	}
}

void Heap::insert(int NewElem)
{
	data[heap_size] = NewElem; // adding to the end
	heap_size++; // changing size
	Up((int)heap_size - 1);
}

void Heap::remove(int elem)
{
	for (int i = 0; i < heap_size; i++)
	{
		if (data[i] == data[elem])
		{
			swap_data(i, (int)heap_size - 1);
			heap_size--;
			Down(i);
			break;
		}
	}
}

Iterator* Heap::create_dft_iterator()
{
	return new dft(heap_size, data);
}

Iterator* Heap::create_bft_iterator()
{
	return new bft(heap_size, data);
}

int Heap::dft::next()
{
	int current = S->return_last();
	int res;
	int left = current * 2 + 1, right = current * 2 + 2;
	while (true)
	{
		if ((left < deep_data->heap_size) && (!colored[left])) { // non-colored left child
			current = current * 2 + 1;
			left = current * 2 + 1; right = current * 2 + 2;
			S->push_back(current);
		}
		else if ((right < deep_data->heap_size) && (!colored[right])) { // non-colored right child
			current = current * 2 + 2;
			left = current * 2 + 1; right = current * 2 + 2;
			S->push_back(current);
		}
		else break; // if no children
	}
	res = current;
	colored[res] = true;
	S->pop_back();
	if (res % 2) current = (current - 1) / 2;
	else current = (current - 2) / 2;
	return deep_data->data[res];
}

bool Heap::dft::has_next()
{
	return !(S->IsEmpty());
}

int Heap::bft::next()
{
	current++;
	return wide_data->data[current - 1];
}

bool Heap::bft::has_next()
{
	return (current < wide_data->heap_size);
}

void Heap::print() {
	for (int i = 0; i < heap_size; i++) {
		std::cout << data[i] << " ";
	}
}