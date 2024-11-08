#include <iostream>


void run(void);

int main()
{
	

	run();

	return 0;
}



class Stream
{
	std::string m_FileName;
public:
	Stream(const std::string& filename) : m_FileName(filename)
	{
		std::cout << "Stream(const std::string &)" << std::endl;
	}

	const std::string& GetFileName()const
	{
		return m_FileName;
	}

	~Stream()
	{
		std::cout << "~Stream()" << std::endl;

	}

private:

};


class OutputStream : virtual public Stream
{
	std::ostream& out;
public:
	OutputStream(std::ostream& o, const std::string& filename) : out(o), Stream(filename)
	{
		std::cout << "OutputStream" << std::endl;
	}

	std::ostream& operator <<(const std::string& data)
	{
		/* When this operator is invoked, the data is formatted and sent to the output stream referenced by out.
		 * For example, if out refers to std::cout, the data will be displayed on the console.
		 * out << data; is used to send the contents of data to the output stream referenced by out,
		 * allowing the OutputStream class to output data to different output destinations such as the console or files.
		 */
		out << data;
		return out;
	}
	~OutputStream()
	{
		std::cout << "~OutputStream" << std::endl;

	}

private:

};


class InputStream : virtual public Stream
{
	std::istream& in;
public:
	InputStream(std::istream& o, const std::string& filename) : in(o), Stream(filename)
	{
		std::cout << "InputStream" << std::endl;
	}

	std::istream& operator >>(std::string& data)
	{
		/* When this operator is invoked, it reads data from the input stream referenced by in and stores it into the data variable.
		 *  in >> data; is used to read input data from the input stream referenced by in and store it into
		 *  the data variable, allowing the InputStream class to read data from different input sources such as the console or files.
		 */
		in >> data;
		return in;
	}
	~InputStream()
	{
		std::cout << "~InputStream" << std::endl;

	}

private:

};

class IOStream : public OutputStream, public InputStream
{
public:
	IOStream(const std::string filename) : OutputStream(std::cout, filename),
		InputStream(std::cin, filename), Stream(filename)
	{
		std::cout << "~IOStream" << std::endl;

	}

	~IOStream()
	{
		std::cout << "~IOStream" << std::endl;

	}

private:

};


void run(void)
{
	IOStream stream("doc.txt");
	std::string data;
	stream >> data;
	stream << data;
	stream << stream.GetFileName() << std::endl;

}




class Base {
public:
	virtual void func() = 0; // Pure virtual function
};

class Derived1 : public Base {
public:
	void func() override {
		std::cout << "Derived1 implementation of func()" << std::endl;
	}
};

class Derived2 : public Base {
public:
	void func() override {
		std::cout << "Derived2 implementation of func()" << std::endl;
	}
};

class Derived3 : public Derived1, public Derived2 {
public:
	void func() override {
		Derived1::func(); // Calling func() from Derived1
		Derived2::func(); // Calling func() from Derived2
	}
};

