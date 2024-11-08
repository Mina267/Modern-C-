#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std::filesystem;
#include "TXT_CopyUtility.h"
void TXT_CopyUtility(const path &src, const path &des)
{
	std::ifstream input{ src };
	if (!input)
	{
		std::cout << "Source file not found!";
		return;
	}
	/* if you create an std::ofstream object with a file path that doesn't exist, 
	 * it will create a new file with that name. If the file already exists, 
	 * it will be overwritten by default, unless you specify 
	 * the std::ios::app flag to append to the existing file. */
	std::ofstream output{ des };
	/*  the object's internal state is set to indicate whether the file was opened successfully.
	 * If the file opening operation fails, typically due to reasons like the file not existing, 
	 * lack of permissions, or other system-related issues
	*/
	if (!output)
	{
		std::cout << "Failure to open Destination file!";
		return;
	}

	std::string line;
	/* std::getline() successfully reads a line from the input stream. 
	* The loop automatically stops when the end-of-file is reached or if an error occurs during reading. */
	while (std::getline(input, line))
	{
		output << line << std::endl;
	}

	input.close();
	output.close();
}