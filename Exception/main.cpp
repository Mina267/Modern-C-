#include <iostream>
#include <memory>
#include <vector>
#include <random>
class Test {
public:
	Test() { std::cout << "Test():Acquire resources" << std::endl; }
	~Test() { std::cout << "~Test():Release resources" << std::endl; }
};

void ProcessRecords(int count) {
	std::unique_ptr<Test> t(new Test);
	if (count < 10)
		throw std::out_of_range("Count should be greater than 10");

	std::vector<int> p;
	p.reserve(count);
	std::vector<int> records;
	records.reserve(count);
	//Process the records
	for (int i = 0; i < count; ++i) {
		records.push_back(i);
	}
	std::default_random_engine eng;
	std::bernoulli_distribution dist;
	int errors{};
	for (int i = 0; i < count; ++i) {
		try {
			std::cout << "Processing record # : " << i << " ";
			if (!dist(eng)) {
				++errors;
				throw std::runtime_error("Could not process the record");
			}
			std::cout << std::endl;
		}
		catch (std::runtime_error& ex) {
			std::cout << "[ERROR " << ex.what() << "]" << std::endl;
			if (errors > 4) {
				std::runtime_error err("Too many errors. Abandoning operation");
				ex = err;
				throw;
			}
		}
	}
}
/*
Old code using raw pointers
*/
void ProcessRecordsOld(int count) {
	/*
	Compare this code with the code that uses RAII.
	*/
	Test* t = new Test;
	if (count < 10)
		throw std::out_of_range("Count should be greater than 10");

	int* p = new int[count];
	int* pArray = (int*)malloc(count * sizeof(int));
	if (pArray == nullptr) {
		throw std::runtime_error("Failed to allocate memory");
	}
	//Process the records
	for (int i = 0; i < count; ++i) {
		pArray[i] = i;
	}
	//Unreachable code in case of an exception
	free(pArray);
	delete[] p;
	delete t;

}
int main() {
	try {
		//ProcessRecords(std::numeric_limits<int>::max());
		ProcessRecords(10);
	}
	catch (std::runtime_error& ex) {
		std::cout << ex.what() << std::endl;
	}
	catch (std::out_of_range& ex) {
		std::cout << ex.what() << std::endl;
	}
	catch (std::bad_alloc& ex) {
		std::cout << ex.what() << std::endl;

	}

	/*
	std::exception is the base class for all standard
	exception classes. It can be used as a handler if
	the exception handling code is same for all child
	class exception objects
	*/
	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	/*
	All-catch handler. Avoid as it does not give any
	information about the exception, so it is difficult
	to take any preventative action
	*/
	catch (...) {
		std::cout << "Exception" << std::endl;
	}
	return 0;
}



#include <iostream>
#include <memory>
#include <vector>
class A {
public:
	A() {
		std::cout << "A()" << std::endl;
	}
	~A() {
		std::cout << "~A()" << std::endl;
	}
};
class B {
public:
	B() {
		std::cout << "B()" << std::endl;
	}
	~B() {
		std::cout << "~B()" << std::endl;
	}
};
class test {
	A* pA{};
	B b{};
	int* pArr;
	char* pStr;
	int* pInt;
public:
	test() {
		std::cout << "test():Acquire resources" << std::endl;

		pA = new A;
		pInt = new int;
		/* If there is an exception thrown by a class while the constructor is executed, 
		 * all the concrete objects created by this class will be destroyed.
		 * Whereas the destructor of the object will not be invoked, consequently, 
		 * the memory that is allocated by New will not be deleted, leading to a memory leak.  
		 */
		throw std::runtime_error("Failed to initialize");
		pStr = new char[1000];
		pArr = new int[50000];
	}
	~test() {
		std::cout << "~test():Release resources" << std::endl;
		delete pA;
		delete pInt;
		delete[]pStr;
		delete[] pArr;
	}
};

void Run_Constructor_Destructor(void)
{
	try {
		test t;
		throw std::runtime_error{ "Exception" };
	}
	catch (std::runtime_error& ex) {
		std::cout << ex.what() << std::endl;
	}
}




#include <iostream>
#include <memory>
#include <vector>
class A {
public:
	A() {
		std::cout << "A()" << std::endl;
	}
	~A() {
		std::cout << "~A()" << std::endl;
	}
};
class B {
public:
	B() {
		std::cout << "B()" << std::endl;
	}
	~B() {
		std::cout << "~B()" << std::endl;
	}
};
class Test {
	/* Using smart pointers, vectors, and strings will manage freeing the memory that has been allocated, 
	 * probably preventing the problem of memory leaks. */
	std::unique_ptr<A> pA{};
	B b{};
	std::unique_ptr<int> pInt{};
	std::string pStr{};
	std::vector<int> pArr{};
public:
	Test() {
		std::cout << "Test():Acquire resources" << std::endl;
		pA.reset(new A);

	}
	~Test() {
		std::cout << "~Test():Release resources" << std::endl;
		//throw std::runtime_error("Failed to initialize");
	}
};

int main() {
	try {
		Test t;
		throw std::runtime_error{ "Exception" };
	}
	catch (std::runtime_error& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}











#include <iostream>

int main() {
	std::string html = R"(
        <html>
            <head>
                <title>Raw String Literals</title>
            </head>
            <body>
                <h1>Hello, World!</h1>
            </body>
        </html>
    )";

	std::cout << html << std::endl;

	return 0;
}






#include <iostream>
#include <vector>
#include <stdexcept>
#include <memory>

// Example class to demonstrate resource management
class Test {
public:
    Test() {
        std::cout << "Resource acquired" << std::endl;
    }
    ~Test() {
        std::cout << "Resource released" << std::endl;
    }
};

void processRecord(int record) {
    // Example processing that might throw an exception
    if (record % 2 == 0) { // Simulating an error for even records
        throw std::runtime_error("Processing error on record " + std::to_string(record));
    }
    std::cout << "Processed record " << record << std::endl;
}

void processRecords(const std::vector<int>& records) {
    int errors = 0;
    const int errorThreshold = 4;

    for (const auto& record : records) {
        try {
            std::unique_ptr<Test> testPtr = std::make_unique<Test>(); // Resource management
            processRecord(record);
        } catch (std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            errors++;

            if (errors > errorThreshold) {
                std::runtime_error modifiedException("Error threshold exceeded. Abandoning operation.");
                std::cerr << "Abandoning operation due to multiple errors." << std::endl;
                throw modifiedException;
            }
        }
    }

    std::cout << "Processed " << records.size() - errors << " records successfully, with " << errors << " errors." << std::endl;
}

int main() {
    std::vector<int> records = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    try {
        processRecords(records);
    } catch (const std::exception& e) {
        std::cerr << "Caught exception in main: " << e.what() << std::endl;
    }

    return 0;
}






