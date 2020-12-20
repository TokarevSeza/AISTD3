#pragma once
#include "Stack.h"
#include "Iterator.h"
#include <iostream>
using namespace std;


class Heap
{
public:
	Heap(int NewData)
	{
		this->data = new int[max_size];
		data[0] = NewData;
		this->heap_size = 1;
	};
	~Heap()
	{
		delete this->data;
		heap_size = 0;
	}

	size_t get_size();
	void Up(int elem);
	void Down(int elem);
	bool contains(int elem);
	void insert(int NewElem);
	void swap_data(int one, int two);
	void remove(int elem);
	int min_data(int a, int b);
	void print();

	Iterator* create_dft_iterator();
	Iterator* create_bft_iterator();

	class dft : public Iterator
	{
	public:
		dft(size_t size, int* data) {
			deep_data->data = data;
			deep_data->heap_size = size;
			S = new Stack();
			S->push_back(0);
			colored = new bool[deep_data->heap_size];
			for (int i = 0; i < deep_data->heap_size; i++)
				colored[i] = false;
		};
		int next() override;
		bool has_next() override;

	private:
		Stack* S;
		bool* colored;
		Heap* deep_data;
	};

	class bft : public Iterator
	{
	public:
		bft(size_t size, int* data) {
			wide_data->data = data;
			wide_data->heap_size = size;
			current = 0;
		};
		int next() override;
		bool has_next() override;
	private:
		int current;
		Heap* wide_data;
	};

private:
	void add_first(int newElem);
	void reset();

	int* data;
	size_t heap_size;
	size_t max_size = 100;
};
