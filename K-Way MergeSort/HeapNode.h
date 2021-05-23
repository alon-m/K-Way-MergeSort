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

	/*const int* ParentArray() const;*/

	const int IndexInArray() const;

	const int ElementsLeftInArray() const;

	/*void SetNumber(int i_Number);
	void SetRelevant(int i_Relevant);
	void SetIndex(int i_Index);
	void SetNumbersLeft(int i_NumbersLeft);*/

private:

	int m_Value;
	int* m_BelongsToArr;
	int m_IndexInArr;
	int m_ElementsLeftInArr;

};