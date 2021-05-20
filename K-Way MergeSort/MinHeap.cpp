#include "MinHeap.h"

/*
 * Public Methods
 */

MinHeap::MinHeap(int i_Amount)
{
	m_ElementCount = 0;
	m_ContainerCapacity = i_Amount;
	m_Container = new int[i_Amount];
}

MinHeap::~MinHeap()
{
	delete[] m_Container;
}

int MinHeap::Count() const
{
	return m_ElementCount;
}

int MinHeap::Capacity() const
{
	return m_ContainerCapacity;
}

int MinHeap::Min() const
{
	if (IsEmpty())
	{
		throw std::length_error("Heap is empty");
	}

	return m_Container[0];
}

int MinHeap::DeleteMin()
{
	if (IsEmpty())
	{
		throw std::length_error("Heap is empty");
	}

	int itemToReturn = m_Container[0];
	m_Container[0] = m_Container[m_ElementCount - 1];
	m_ElementCount--;
	fixHeapDown();

	return itemToReturn;
}

void MinHeap::Insert(int i_ItemToAdd)
{
	resize();
	m_Container[Count()] = i_ItemToAdd;
	fixHeapUp();
}

bool MinHeap::IsEmpty() const
{
	return Count() == 0;
}

void MinHeap::BuildHeap(int* i_Arr, int i_Size)
{
	if (i_Arr)
	{
		for (int i = 0; i < i_Size; i++)
		{
			Insert(i_Arr[i]);
		}
	}
	else
	{
		throw std::exception("input array pointer is null");
	}
}

/*
 * Private Methods
 */

int MinHeap::getLeftChildIndex(int i_ParentIndex) const
{
	return 2 * i_ParentIndex + 1;
}

int MinHeap::getRightChildIndex(int i_ParentIndex) const
{
	return 2 * i_ParentIndex + 2;
}

int MinHeap::getParentIndex(int i_ChildIndex) const
{
	return (i_ChildIndex - 1) / 2;
}

bool MinHeap::hasLeftChild(int i_ParentIndex) const
{
	return (getLeftChildIndex(i_ParentIndex) < Count());
}

bool MinHeap::hasRightChild(int i_ParentIndex) const
{
	return (getRightChildIndex(i_ParentIndex) < Count());
}

bool MinHeap::hasParent(int i_ChildIndex) const
{
	return (getParentIndex(i_ChildIndex) >= 0);
}

int MinHeap::getLeftChild(int i_ParentIndex) const
{
	return m_Container[getLeftChildIndex(i_ParentIndex)];
}

int MinHeap::getRightChild(int i_ParentIndex) const
{
	return m_Container[getRightChildIndex(i_ParentIndex)];
}

int MinHeap::getParent(int i_ChildIndex) const
{
	return m_Container[getParentIndex(i_ChildIndex)];
}

void MinHeap::swap(int i_Index1, int i_Index2)
{
	int temp = m_Container[i_Index1];
	m_Container[i_Index1] = m_Container[i_Index2];
	m_Container[i_Index2] = temp;
}

void MinHeap::resize()
{
	if (Count() == Capacity())
	{
		m_Container = copyContainerAndDoubleCapacity();
	}
}

int* MinHeap::copyContainerAndDoubleCapacity()
{
	int* result = new int[m_ContainerCapacity * 2];

	for (int i = 0; i < m_ContainerCapacity; i++)
	{
		result[i] = m_Container[i];
	}

	m_ContainerCapacity *= 2;

	return result;
}

void MinHeap::fixHeapDown()
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

		swap(index, smallerChildIndex);

		index = smallerChildIndex;
	}
}

void MinHeap::fixHeapUp()
{
	int index = Count() - 1;

	while (hasParent(index) && getParent(index) > m_Container[index])
	{
		swap(getParentIndex(index), index);
		index = getParentIndex(index);
	}
}
