#pragma once
#include <stdexcept>
#include "HeapNode.h"

class MinHeap
{
public:

	explicit MinHeap(int i_Amount = 1);

	~MinHeap();

	int Count() const;

	int Capacity() const;

	int Min() const;

	int DeleteMin();

	void Insert(int i_Number, int* i_Relevant, int i_Index, int i_NumbersLeft);

	bool IsEmpty() const;

	void Print();

private:

	int m_ContainerCapacity;
	int m_ElementCount;
	HeapNode* m_Container;

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

	void copyContainerAndDoubleCapacity();

	void fixHeapDown();

	void fixHeapUp();

};
