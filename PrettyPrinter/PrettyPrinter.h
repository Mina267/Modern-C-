#pragma once

template < typename T>
class PrettyPrinter
{
	T* m_pData;
public:
	PrettyPrinter(T* pdata) : m_pData{ pdata }
	{

	}
	void Print()
	{
		std::cout << "{" << *m_pData << "}" << std::endl;
	}
	T* GetData(void)
	{
		return m_pData;
	}
};


template <>
void PrettyPrinter<std::vector<int>>::Print()
{
	std::cout << "{";
	for (const auto& x : *m_pData)
	{
		std::cout << x << " ";
	}

	std::cout << "}" << std::endl;
}

template <>
class PrettyPrinter<char*>
{
	char* m_pData;
public:
	PrettyPrinter(char* pdata) : m_pData{ pdata }
	{

	}
	void Print()
	{
		std::cout << "{" << m_pData << "}" << std::endl;
	}
	char* GetData(void)
	{
		return m_pData;
	}
};


//template <>
//class PrettyPrinter<std::vector<int>>
//{
//	std::vector<int>* m_pData;
//public:
//	PrettyPrinter(std::vector<int>* pdata) : m_pData{ pdata }
//	{
//
//	}
//	void Print()
//	{
//		std::cout << "{";
//
//		for (const auto& x : *m_pData)
//		{
//			std::cout << x << " ";
//		}
//
//		std::cout << "}" << std::endl;
//	}
//	std::vector<int>* GetData(void)
//	{
//		return m_pData;
//	}
//};

void PrettyPrinter_Run(void);



