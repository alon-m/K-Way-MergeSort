#pragma once
class Member
 {
public:
	Member();
	Member(int i_Number,int i_Relevant,int i_Index,int i_NumbersLeft);
	Member(const Member& other);
	~Member() {};
	int GetNumber();
	int GetRelevant();
	int GetIndex();
	int GetNumbersLeft();
	void SetNumber(int i_Number);
	void SetRelevant(int i_Relevant);
	void SetIndex(int i_Index);
	void SetNumbersLeft(int i_NumbersLeft);

private:
	int m_Number;
	int m_Relevant;
	int m_Index;
	int m_NumbersLeft;

};