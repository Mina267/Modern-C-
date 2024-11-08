#include <iostream>
#include <thread>
#include <string>
#include <list>


static std::list<int> g_Data;
static const int SIZE = 500000;
class String
{
public:
	String() {
		std::cout << "String()" << std::endl;
	}
	String(const String&) {
		std::cout << "String(const String &)" << std::endl;
	}
	String& operator=(const String&) {
		std::cout << "operator=(const String&)" << std::endl;
		return *this;
	}
	~String() {
		std::cout << "~String()" << std::endl;
	}

};
static void Download(const String& File_name)
{
	std::cout << "[Downloader]Start download of file: " << std::endl;
	for (int i = 0; i < SIZE; ++i)
	{
		g_Data.push_back(i);
	}
	std::cout << "[Downloader]Finished download" << std::endl;
}
int Thread1(void)
{
	String file;
	std::cout << "[main]User started an operation" << std::endl;
	std::thread theDownloader(Download, std::cref(file));
	std::cout << "[main]User started another operation" << std::endl;
	if (theDownloader.joinable())
	{
		theDownloader.join();
	}
	return 0;
}




