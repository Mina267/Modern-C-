#include <iostream>
#include <string>
#include <sstream>
template <typename T, int size>
void array_Print(T(&arr)[size])
{
	for (auto x : arr)
	{
		std::cout << x << " ";
	}
	std::cout << std::endl;
}

//using Comparator = bool(*)(int, int);

/* "typename Comparator" will provide privileges to make the comparsion invocation
 *  whatwver Callbacks-Function Objects, Callbacks-Function or Lambda Expressions. */
template <typename T, int size, typename Comparator>
void Sort(T(&arr)[size], Comparator Comp)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			/* To enhance the comparison mechanism to be generic, instead of using "(arr[j] > arr[j + 1]),"
			 * make a pointer to the function for comparison and make the user define
			 * this comparison function according to its dire data.
			 */
			if (Comp(arr[j], arr[j + 1]))
			{
				/* use move semantic to avoid copy */
				T tmp = std::move(arr[j]);
				arr[j] = std::move(arr[j + 1]);
				arr[j + 1] = std::move(tmp);
			}
		}
	}
}

template <typename T, int size, typename Callback>
void ForEach(T(&arr)[size], Callback operation)
{
	for (int i = 0; i < size - 1; ++i)
	{
		operation(arr[i]);
	}
}
//template <typename T>
//struct __Unnamed
//{
//	/* Copy for variable that we captured by lambda in Capture List */
//	int offset;
//	/* initialize it in the constructor. */
//	__Unnamed(int off) : offset(off) {
//
//	}
//	/* compiler constructs the function with the "const" key,
//	 * and we use the keyword "mutable" to remove it. */
//	void operator()(T& x) /*const*/ {
//		x += offest;
//		offest++;
//	}
//};


void Lambda3_Run(void)
{
	int arr[]{ 1,5,9,7,8,4,7,9 };
	int offest = 5;
	ForEach(arr, [](auto x)
		{
			std::cout << x << " ";
		});
	std::cout << std::endl;
	ForEach(arr, [offest](auto& x) mutable {
		x += offest;
		offest++;
		});
	ForEach(arr, [](auto x)
		{
			std::cout << x << " ";
		});
	std::cout << std::endl;
}

void Lambda2_Run(void)
{
	int arr[]{ 1,5,9,7,8,4,7,9 };
	int offest = 5;
	int sum{};
	ForEach(arr, [](auto x)
		{
			std::cout << x << " ";
		});
	std::cout << std::endl;
	ForEach(arr, [&sum, &offest](auto& x) mutable {
		sum += x;
		offest++;
		});
	ForEach(arr, [](auto x)
		{
			std::cout << x << " ";
		});
	std::cout << std::endl;
}






void Lambda1_Run(void)
{
	int arr[]{ 1,5,9,7,8,4,7,9 };
	array_Print(arr);
	auto comp = [](auto x, auto y) {
		return x > y;
		};
	Sort(arr, comp);
	array_Print(arr);
}


/* Callbacks - Function Objects */
struct comparison
{
	bool operator()(int x, int y)
	{
		return x > y;
	}
};
int Function_Objects_Run(void)
{
	int arr[]{ 1,5,9,7,8,4,7,9 };
	/* Create the intance of Function Objects */
	comparison Comp;
	array_Print(arr);
	Sort(arr, Comp);
	array_Print(arr);
	return 0;
}




/*  Callbacks-Function */
bool Comp1(int x, int y)
{
	return x > y;
}
/*  Callbacks-Function */
bool Comp2(int x, int y)
{
	return x < y;
}





void Callbacks_Function_Run(void)
{
	int arr[]{ 1,5,9,7,8,4,7,9 };


	array_Print(arr);
	Sort(arr, Comp1);
	array_Print(arr);
	Sort(arr, Comp2);
	array_Print(arr);

}


class Product
{
	std::string m_name;
	float m_Price;
public:
	Product(const std::string &n, float p): m_name(n), m_Price(p) {	}

	void AssignFinalPrice()
	{
		float taxes[]{ 1, 5, 5 };
		float basePrice{ m_Price };
		/* Capture this in lambda */
		ForEach(taxes, [basePrice, this](float tax)
			{
				float TaxedPrice = basePrice * tax / 100;
				m_Price += TaxedPrice;
			});
	}
	auto GetDescription()
	{
		return [*this](const std::string& header)
			{
				std::ostringstream ost;
				ost << header << std::endl;
				ost << "Name: " << m_name << std::endl;
				ost << "Price: " << m_Price << std::endl;
				return ost.str();
			};
		
	}
	float GetPrice() const
	{
		return m_Price;
	}

};


int main()
{
	Product *p = new Product { "Watch", 500 };
	auto desc = p->GetDescription() ;
	delete p ;
	std::cout << desc("##############") << std::endl;




	auto f = [](int x, int y) {
		return x + y;
		};
	constexpr auto sum = f(3, 5);
	auto sum = f(3, 5);
	printf("%d", sum);




}