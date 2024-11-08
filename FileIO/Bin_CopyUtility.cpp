#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std::filesystem;
#include "Bin_CopyUtility.h"

void Bin_CopyUtility(const path& src, const path& des)
{
	if (!exists(src))
	{
		std::cerr << "Source file does not exist.\n";
		return;
	}


	/* Check if source is a regular file
	 * a regular file is a type of file that contains data, 
	 * typically in the form of text, binary, or other formats
	 */
	if (!is_regular_file(src)) {
		std::cerr << "Source is not a regular file.\n";
		return;
	}

	if (exists(des))
	{
		std::cerr << "Destination file already exists. Overwriting is not allowed.\n";
		return;
	}


	std::ifstream inputFile{ src, std::ios::binary | std::ios::in };
	std::ofstream outputFile{ des, std::ios::binary | std::ios::out };

	/* Get the size of the source file by point to end of the file 
	 * he seekg function is used to set the position of the get pointer in the input stream (sourceFile). 
	 * By seeking to the end of the file, the current position of the get pointer will be set to the end of the file.
	 */
	inputFile.seekg(0, std::ios::end);

	/*  tellg() returns the current position of the get pointer as an offset from the beginning of the file. 
	 *  "std::streamsize" :  represents the size of a stream buffer or a file in bytes. I
	 */
	std::streamsize SrcSize = inputFile.tellg();

	/* This line seeks the get position indicator back to the beginning of the file (std::ios::beg). 
	 * After obtaining the file size, it's common to reset the get pointer to 
	 * the beginning of the file so that subsequent read operations start from the beginning.
	 */
	inputFile.seekg(0, std::ios::beg);

	/* The value 4096 is a commonly used buffer size in file I/O operations. 
	 * Using a buffer helps in efficient reading and writing of data from/to 
	 * a file by reducing the number of system calls required. */
	const std::streamsize BufferSize = 4096;
	/* The buffer is used to store data read from or written to a file */
	char Buffer[BufferSize];

	while (SrcSize > 0)
	{
		std::streamsize CopySize = (SrcSize >= BufferSize) ? BufferSize : SrcSize;
		inputFile.read(Buffer, CopySize);
		if (!inputFile) {
			std::cerr << "Error reading from source file.\n";
			return ;
		}

		outputFile.write(Buffer, CopySize);
		if (!outputFile) {
			std::cerr << "Error writing to destination file.\n";
			return ;
		}
		

		SrcSize -= CopySize;

	}


	std::cout << "File copied successfully.\n";

}