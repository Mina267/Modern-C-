#include <iostream>

/* Base Function */
void Print()
{
	std::cout << std::endl;
}

/* Template parameter pack */
template<typename T, typename...Params>
/* function parameter pack */
void Print(T&& a, Params&&...args)
{
	std::cout << a;
	if (sizeof...(args) != 0)
	{
		std::cout << ",";
	}
	Print(std::forward<Params>(args)...);
}





