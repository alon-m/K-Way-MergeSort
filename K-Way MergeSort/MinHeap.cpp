#include "MinHeap.h"
#include <iostream>
class HeapNode;
using namespace std;


/*
 * Public Methods
 */

MinHeap::MinHeap(int i_Amount)
{
	m_ElementCount = 0;
	m_ContainerCapacity = i_Amount;
	m_Container = new HeapNode[i_Amount];
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

	return m_Container[0].Value();
}

int MinHeap::DeleteMin()
{
	if (IsEmpty())
	{
		throw std::length_error("Heap is empty");
	}

	int itemToReturn = m_Container[0].Value();

	if (m_Container[0].ElementsLeftInArray() == 0)
	{
		m_Container[0] = m_Container[Count() - 1];
		m_ElementCount--;
	}
	else
	{
		
		int nextIndex = m_Container[0].IndexInArray()+1;
		int nextValue = m_Container[0].GetArrayInIndex(nextIndex);
		m_Container[0].SetValue(nextValue);
		m_Container[0].SetIndex(nextIndex);
		m_Container[0].DecrementElements();
	}

	fixHeapDown();

	return itemToReturn;
	
}

void MinHeap::Insert(int i_NodeValue, int* i_NodeParentArray, int i_ValueIndexInArray, int i_NumbersLeft)
{
	HeapNode toAdd(i_NodeValue, i_NodeParentArray, i_ValueIndexInArray, i_NumbersLeft);
	resize();
	m_Container[Count()] = toAdd;
	m_ElementCount++;

	fixHeapUp();
}

bool MinHeap::IsEmpty() const
{
	return Count() == 0;
}

void MinHeap::Print()
{
	for (int i = 0; i < m_ElementCount; i++)
		cout << m_Container[i].Value() << " ";
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
	return m_Container[getLeftChildIndex(i_ParentIndex)].Value();
}

int MinHeap::getRightChild(int i_ParentIndex) const
{
	return m_Container[getRightChildIndex(i_ParentIndex)].Value();
}

int MinHeap::getParent(int i_ChildIndex) const
{
	return m_Container[getParentIndex(i_ChildIndex)].Value();
}

void MinHeap::swap(int i_Index1, int i_Index2)
{
	HeapNode temp = m_Container[i_Index1];
	m_Container[i_Index1] = m_Container[i_Index2];
	m_Container[i_Index2] = temp;
}

void MinHeap::resize()
{
	if (Count() == Capacity())
	{
		copyContainerAndDoubleCapacity();
	}
}

void MinHeap::copyContainerAndDoubleCapacity()
{
	HeapNode* result = new HeapNode[m_ContainerCapacity * 2];

	for (int i = 0; i < m_ContainerCapacity; i++)
	{
		result[i] = m_Container[i];
	}

	m_ContainerCapacity *= 2;

	delete[] m_Container;

	m_Container = result;
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

		if (m_Container[index].Value() < m_Container[smallerChildIndex].Value())
		{
			break;
		}

		swap(index, smallerChildIndex);

		index = smallerChildIndex;
	}
}

void MinHeap::fixHeapUp()
{
	int index = Count()-1;
	int Fatherval = getParent(index);
	int myval = m_Container[index].Value();
	while (hasParent(index) && getParent(index) > m_Container[index].Value())
	{
		swap(getParentIndex(index), index);
		index = getParentIndex(index);
	}
}
