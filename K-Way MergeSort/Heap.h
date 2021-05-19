#pragma once

class Heap
{
private:
	unsigned int m_Capacity;
	unsigned int m_Size;
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
		return (getLeftChildIndex(i_ParentIndex) < m_Size);
	}

	bool hasRightChild(int i_ParentIndex)
	{
		return (getRightChildIndex(i_ParentIndex) < m_Size);
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
public:

	Heap(unsigned int i_Amount = 1)
	{
		m_Size = 0;
		m_Capacity = i_Amount;
		m_Container = new int[i_Amount];
	}

	int Count()
	{
		return m_Size;
	}

	int Capacity()
	{
		return m_Capacity;
	}
};

