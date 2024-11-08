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


template<>
void PrettyPrinter<std::vector<int>>::Print();




////Primary or base template
//template<typename T, int columns>
//class PrettyPrinter {
//	T* m_pData;
//public:
//	PrettyPrinter(T* data) :m_pData(data) {
//
//	}
//	void Print() {
//		std::cout << "Columns:" << columns << std::endl;
//		std::cout << "{" << *m_pData << "}" << std::endl;
//	}
//
//	T* GetData() {
//		return m_pData;
//	}
//};
////Partial specialization for value 80
//template<typename T>
//class PrettyPrinter<T, 80> {
//	T* m_pData;
//public:
//	PrettyPrinter(T* data) :m_pData(data) {
//
//	}
//	void Print() {
//		std::cout << "Using 80 Columns" << std::endl;
//		std::cout << "{" << *m_pData << "}" << std::endl;
//	}
//
//	T* GetData() {
//		return m_pData;
//	}
//};