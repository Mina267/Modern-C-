#pragma once

template<typename T>
class SmartPointer {
	T* m_ptr;
public:
	SmartPointer(T* ptr) :m_ptr(ptr) {

	}
	T* operator ->() {
		return m_ptr;
	}
	T& operator *() {
		return *m_ptr;
	}
	~SmartPointer() {
		delete m_ptr;
	}
};
//Partial specialization for array types
template<typename T>
class SmartPointer<T[]> {
	T* m_ptr;
public:
	SmartPointer(T* ptr) :m_ptr(ptr) {

	}
	T& operator[](int index) {
		return m_ptr[index];
	}
	~SmartPointer() {
		delete[] m_ptr;
	}
};






int SM_run();