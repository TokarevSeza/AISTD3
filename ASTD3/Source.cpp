#include"heap.h"

int main()
{
	Heap* h = new Heap(0);
	h->insert(1);
	h->insert(10);
	h->insert(2);
	h->insert(3);
	h->insert(4);
	cout << "Deep-first:" << endl;
	Iterator* deep = h->create_dft_iterator();
	while (deep->has_next())
	{
		cout << deep->next() << " ";
	}
	cout << endl;
	cout << "Wide-first:" << endl;
	Iterator* wide = h->create_bft_iterator();
	while (wide->has_next())
	{
		cout << wide->next() << " ";
	}
}
