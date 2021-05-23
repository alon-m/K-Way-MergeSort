#include "HeapNode.h"


HeapNode::HeapNode() : m_Value(0), m_BelongsToArr(nullptr), m_IndexInArr(0), m_ElementsLeftInArr(0)
{
}

HeapNode::HeapNode(int i_NodeValue = 0, int* i_BelongsToArr = nullptr, int i_IndexInArr = 0, int i_ElementsLeftInArr = 0)
{
	m_Value = i_NodeValue;
	m_BelongsToArr = i_BelongsToArr;
	m_IndexInArr = i_IndexInArr;
	m_ElementsLeftInArr = i_ElementsLeftInArr;
}

HeapNode::HeapNode(const HeapNode& other)
{
	m_IndexInArr = other.m_IndexInArr;
	m_Value = other.m_Value;
	m_ElementsLeftInArr = other.m_ElementsLeftInArr;
	m_BelongsToArr = other.m_BelongsToArr;
}






const int HeapNode::Value() const
{
	return m_BelongsToArr[IndexInArray()];
}

//const int* HeapNode::ParentArray() const
//{
//	return m_BelongsToArr;
//}

const int HeapNode::IndexInArray() const
{
	return m_IndexInArr;
}

const int HeapNode::GetArrayInIndex(int i_Index) const
{
	return m_BelongsToArr[i_Index];
}

const int HeapNode::ElementsLeftInArray() const
{
	return m_ElementsLeftInArr;
}

void HeapNode::SetValue(int i_Number)
{
	m_Value = i_Number;
}
void HeapNode::SetIndex(int i_Index)
{
	m_IndexInArr = i_Index;
}

void HeapNode::SetNumbersLeft(int i_NumbersLeft)
{
	m_ElementsLeftInArr = i_NumbersLeft;
}