#include "pch.h"
#include "CppUnitTest.h"
#include "../ASTD3/Heap.h"
#include "../ASTD3/Stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		Heap* data;
		int elem;

		TEST_METHOD_INITIALIZE(setup) 
		{
			elem = 1;
			data = new Heap(elem);
		}

		TEST_METHOD_CLEANUP(cleanup) 
		{
			delete data;
		}

		TEST_METHOD(containts) 
		{
			data->insert(1);
			data->insert(2);
			Assert::AreEqual(data->contains(1), true);
			Assert::AreEqual(data->contains(2), true);
		}

		TEST_METHOD(insert)
		{
			data->insert(1);
			data->insert(2);
			Assert::AreEqual((int)data->get_size(), 3);
		}

		TEST_METHOD(remove)
		{
			data->insert(1);
			data->insert(2);
			data->remove(2);
			Assert::AreEqual((int)data->get_size(), 2);
		}

	};
}
