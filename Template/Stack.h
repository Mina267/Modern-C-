#pragma once

/* Use class template so you can create stack with your dire type */
template < typename T, int size>
class Stack
{
	T m_Stack[size];
	int m_StackPointer{ -1 };
public:

	Stack() = default;
	/* Copy constructor To stack object to another */
	Stack(Stack &Stackobj)
	{
		m_StackPointer = Stackobj.m_StackPointer;
		for (int i = 0; i <= m_StackPointer; i++)
		{
			m_Stack[i] = Stackobj.m_Stack[i];
		}
	}
	/* Push data to the stack */
	void Push(const T &Data)
	{
		/* Check if stack is Full or not */
		if (m_StackPointer != size)
		{
			m_Stack[++m_StackPointer];
		}
	}
	void Pop(void);
	/* Check wherever stack is empty or not */
	bool IsEmpty(void)
	{
		return (m_StackPointer == -1);
	}

	/* Read the top of the stack */
	const T& Top() const
	{
		/* Check if stack is empty or not */
		if (m_StackPointer != -1)
		{
			return m_Stack[m_StackPointer];
		}
	}
	/* Create new stack */
	static Stack Create();

private:

};


void Stack_Run(void);