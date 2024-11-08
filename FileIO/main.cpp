#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>


#include "TXT_CopyUtility.h"
#include "Bin_CopyUtility.h"
#include "Copy_Files_Dir.h"

void Write(void)
{
	/*  creates an std::ofstream object named out and attempts to open a file named "text.txt" for writing. */
	std::ofstream out("text.txt");
	/* if statement checks if the file stream object out is in a failed state. */
	if (!out)
	{
		std::cout << "Could not open file for writing" << std::endl;
		return;
	}
	/* meassage that will be placed in the file. */
	std::string message{ "Mina Magdy Aziz" };
	for (char ch : message)
	{
		out.put(ch);
	}
}

void Read(void)
{
	std::ifstream input{ "text.txt" };
	if (!input)
	{
		std::cout << "Source file not found" << std::endl;
		return;
	}



	char ch{};
	while (input.get(ch))
	{
		std::cout << ch;
	}
}




void Bin(void)
{
	/* Create an object textstream of type std::ofstream. This object represents an output file stream. */
	std::ofstream textstream{ "data" };
	/* Write the integer value 123456789 to the file using the output operator <<. 
	 * The integer will be converted to its string representation and written to the file. 
	 */
	textstream << 123456789;

	/* Create an object binstream of type std::ofstream. This object represents an output file stream.
	 * Open a file named "binary" for writing in binary mode. The std::ios::binary flag specifies binary mode, 
	 * ensuring that data is written in binary format without any special character conversions. 
	 * The std::ios::out flag specifies that the file is opened for output.
	 */
	std::ofstream binstream{ "binary", std::ios::binary | std::ios::out };
	/* Declare an integer variable num and initialize it with the value 12345678. */
	int num{ 12345678 };
	/* Write the binary representation of the integer num to the file using the write() function. 
	 * The address of num is cast to a pointer to const char*, 
	 * and sizeof(num) bytes are written to the file.
	 */
	binstream.write((const char*)&num, sizeof(num));

	/* Close the file so that it can be open for reading */
	binstream.close();
	/* Create an object input of type std::ifstream. This object represents an input file stream.
	 * Open a file named "binary" for reading in binary mode. The std::ios::binary flag specifies binary mode, 
	 * ensuring that data is read in binary format without any special character conversions. 
	 * The std::ios::in flag specifies that the file is opened for input.
	 */
	std::ifstream input{ "binary", std::ios::binary | std::ios::in };
	/* Declare an integer variable num and initialize it with the value 0. */
	num = 0;
	/* Read binary data from the file into the integer variable num using the read() function. 
	 * The address of num is cast to a pointer to char*, and sizeof(num) bytes are read from the file. 
	 */
	input.read((char*)&num, sizeof(num));

	std::cout << num << std::endl;
}

struct Record
{
	int id;
	char name[10];
};

void WriteRecord(Record* p)
{
	std::ofstream binStream{ "record", std::ios::binary | std::ios::out };
	binStream.write((const char*)p, sizeof(Record));
}

Record ReadRecord(void)
{
	std::ifstream binStream{ "record", std::ios::binary | std::ios::in };
	Record r;
	binStream.read((char*)&r, sizeof(Record));
	return r;
}
 
void Record_Run(void)
{
	Record r;
	Record r2;
	r.id = 1234;
	strcpy_s(r.name, 10, "Mina");
	WriteRecord(&r);
	r2 = ReadRecord();
	std::cout << "Record Name: " << r2.name << "\nRecord id: " << r2.id << std::endl;
}


int main(void)
{/*
	Write();
	Read();
	std::cout << std::endl;
	Bin();
	std::cout << std::endl;
	Record_Run();

	using namespace std::filesystem;
	path src(current_path());
	src /= "main.cpp";
	path des(current_path());
	des /= "copy.cpp";
	TXT_CopyUtility(src, des);

	*/

	/*
	std::string path1 = "E:/file1/binary.bin";
	path src(path1);
	std::string path2 = "E:/file1/copy.bin";
	path des(path2);
	Bin_CopyUtility(src, des);
	*/


	std::string path1 = "E:/file1";
	path src(path1);
	std::string path2 = "E:/file2";
	path dis(path2);
	Copy_Files_Dir(src, dis);



	return 0;
}