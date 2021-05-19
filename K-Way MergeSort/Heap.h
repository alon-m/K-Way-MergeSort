#pragma once
#include <stdexcept>
using namespace std;

class Heap
{
public:

	Heap(unsigned int i_Amount = 1)
	{
		m_ElementCount = 0;
		m_ContainerCapacity = i_Amount;
		m_Container = new int[i_Amount];
	}

	int Count()
	{
		return m_ElementCount;
	}

	int Capacity()
	{
		return m_ContainerCapacity;
	}

	int peek()
	{
		if (IsEmpty())
		{
			throw new length_error("Heap is empty");
		}

		return m_Container[0];
	}

	int Pull()
	{
		if (IsEmpty())
		{
			throw new length_error("Heap is empty");
		}

		int itemToReturn = m_Container[0];
		m_Container[0] = m_Container[m_ElementCount - 1];
		m_ElementCount--;
		heapifyDown();

		return itemToReturn;
	}

	void add(int i_ItemToAdd)
	{
		resize();
		m_Container[Count()] = i_ItemToAdd;
		heapifyUp();
	}

	bool IsEmpty()
	{
		return Count() == 0;
	}

private:

	unsigned int m_ContainerCapacity;
	unsigned int m_ElementCount;
	int* m_Container;

	int getLeftChildIndex(int i_ParentIndex)
	{
		return 2 * i_ParentIndex + 1;
	}

	int getRightChildIndex(int i_ParentIndex)
	{
		return 2 * i_ParentIndex + 2;
	}

	int getParentIndex(int i_ChildIndex)
	{
		return (i_ChildIndex - 1) / 2;
	}

	bool hasLeftChild(int i_ParentIndex)
	{
		return (getLeftChildIndex(i_ParentIndex) < Count());
	}

	bool hasRightChild(int i_ParentIndex)
	{
		return (getRightChildIndex(i_ParentIndex) < Count());
	}

	bool hasParent(int i_ChildIndex)
	{
		return (getParentIndex(i_ChildIndex) >= 0);
	}

	int getLeftChild(int i_ParentIndex)
	{
		return m_Container[getLeftChildIndex(i_ParentIndex)];
	}

	int getRightChild(int i_ParentIndex)
	{
		return m_Container[getRightChildIndex(i_ParentIndex)];
	}

	int getParent(int i_ChildIndex)
	{
		return m_Container[getParentIndex(i_ChildIndex)];
	}

	void swap(int i_Index1, int i_Index2)
	{
		int temp = m_Container[i_Index1];
		m_Container[i_Index1] = m_Container[i_Index2];
		m_Container[i_Index2] = temp;
	}
	
	void resize()
	{
		if (Count() == Capacity())
		{
			m_Container = copyContainerAndDoubleCapacity();
		}
	}

	int* copyContainerAndDoubleCapacity()
	{
		int* result = new int[m_ContainerCapacity * 2];

		for (int i = 0; i < m_ContainerCapacity; i++)
		{
			result[i] = m_Container[i];
		}

		m_ContainerCapacity *= 2;
		
		return result;
	}

	void heapifyDown()
	{
		int index = 0;

		while (hasLeftChild(index))
		{
			int smallerChildIndex = getLeftChildIndex(index);

			if (hasRightChild(index) && getRightChild(index) < getLeftChild(index))
			{
				smallerChildIndex = getRightChildIndex(index);
			}

			if (m_Container[index] < m_Container[smallerChildIndex])
			{
				break;
			}
			else
			{
				swap(index, smallerChildIndex);
			}

			index = smallerChildIndex;
		}
	}

	void heapifyUp()
	{
		int index = Count() - 1;

		while (hasParent(index) && getParent(index) > m_Container[index])
		{
			swap(getParentIndex(index), index);
			index = getParentIndex(index);
		}
	}

};

