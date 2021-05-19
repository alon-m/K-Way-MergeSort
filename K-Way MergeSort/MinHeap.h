#pragma once
#include <stdexcept>

class MinHeap
{
public:

	explicit MinHeap(int i_Amount = 1);

	~MinHeap()
	{
		delete[] m_Container;
	}

	int Count() const;

	int Capacity() const;

	int Min() const;

	int DeleteMin();

	void Insert(int i_ItemToAdd);

	bool IsEmpty() const;

	void BuildHeap(int* i_Arr, int i_Size);
	

private:

	int m_ContainerCapacity;
	int m_ElementCount;
	int* m_Container;

	int getLeftChildIndex(int i_ParentIndex) const;

	int getRightChildIndex(int i_ParentIndex) const;

	int getParentIndex(int i_ChildIndex) const;

	bool hasLeftChild(int i_ParentIndex) const;

	bool hasRightChild(int i_ParentIndex) const;

	bool hasParent(int i_ChildIndex) const;
	
	int getLeftChild(int i_ParentIndex) const;

	int getRightChild(int i_ParentIndex) const;

	int getParent(int i_ChildIndex) const;

	void swap(int i_Index1, int i_Index2);

	void resize();

	int* copyContainerAndDoubleCapacity();

	void fixHeapDown();

	void fixHeapUp();
	
};
