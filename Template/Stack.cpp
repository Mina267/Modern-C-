#include <iostream>
#include "Stack.h"


/* If you want to define a function outside of the class body, it should be processed with the declaration of the templates.
 * also for the name of the class, it not just the name. we cannot use short hand notion outside the class we must've specify full name.
 */
template <typename T, int size>
void Stack<T, size>::Pop(void)
{
	--m_StackPointer;
}

template<typename T, int size>
Stack<T, size> Stack<T, size>::Create()
{
	return Stack<T, size>();
}





void Stack_Run(void)
{
	Stack<int, 10> s;

}