#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std::filesystem;
#include "Bin_CopyUtility.h"
#include "Copy_Files_Dir.h"


static void Copy_dir(path& srcDir, path& disDir)
{
	// Create destination directory if it does not exist
	if (!exists(disDir))
	{
		create_directories(disDir);
	}

	// Iterate through all entries (files and directories) in the source directory
	for (const auto& entry : recursive_directory_iterator(srcDir))
	{
		if (entry.is_regular_file())
		{
			// Get the relative path of the file with respect to the source directory
			path relativePath = relative(entry.path(), srcDir);

			// Construct the destination file path
			path destinationFile = disDir / relativePath;

			// Show progress: Display the source and destination paths being copied
			std::cout << "Copying: " << entry.path() << " -> " << destinationFile << std::endl;
			
			// Copy the file
			Bin_CopyUtility(entry, destinationFile);
		}


	}

}

int Copy_Files_Dir(path& src, path& dis)
{

	if (!exists(src))
	{
		std::cerr << "Error: Source file or directory does not exist: " << src << std::endl;
		return 1;
	}

	if (is_regular_file(src))
	{
		Bin_CopyUtility(src, dis);
	}
	else if (is_directory(src))
	{
		Copy_dir(src, dis);
	}
	else 
	{
		std::cerr << "Error: Unsupported source type." << std::endl;
		return 2; // Return error code 1 indicating unsupported source type
	}


	// Display completion message
	std::cout << "Copy completed successfully." << std::endl;
	return 0; // Return success code 0 indicating successful completion
}

