#pragma once
#include <list>
class HeapNode
{
public:
	HeapNode();
	HeapNode(int i_NodeValue, int* i_BelongsToArr, int i_IndexInArr, int i_ElementsLeftInArr);
	HeapNode(const HeapNode& other);
	~HeapNode() {};

	const int Value() const;

	const int IndexInArray() const;
	const int GetArrayInIndex(int i_Index ) const;
	const int ElementsLeftInArray() const;

	void SetValue(int i_Number);
	void SetIndex(int i_Index);
	void DecrementElements();

private:

	int m_Value;
	int* m_BelongsToArr;
	int m_IndexInArr;
	int m_ElementsLeftInArr;

};