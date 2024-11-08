#include <iostream>
#include <thread>
#include <string>
#include <list>
#include <mutex>

std::list<int> g_Data;
static const int SIZE = 10000;

std::mutex g_mutex;
static void Download()
{
	for (int i = 0; i < SIZE; ++i)
	{
		std::lock_guard<std::mutex> mtx(g_mutex);
		g_Data.push_back(i);
		if (i == 500)
			return;
	}
}
// Function that simulates downloading data and uses std::lock_guard for mutex management
static void Download2()
{
	// Lock the mutex using std::lock_guard. It will be unlocked automatically when the lock_guard object goes out of scope.
	std::lock_guard<std::mutex> guard(g_mutex);

	std::cout << "[Downloader] Start download of file." << std::endl;
	for (int i = 0; i < SIZE; ++i) {
		g_Data.push_back(i);
	}
	std::cout << "[Downloader] Finished download." << std::endl;

	// Mutex is automatically unlocked here when the lock_guard object goes out of scope.
}
int Mutex(void)
{
	// Create a thread that calls the Download function
	std::thread theDownloader(Download);
	std::thread theDownloader2(Download2);
	
	// Wait for the thread to complete its task
	if (theDownloader.joinable()) {
		theDownloader.join();
	}

	// Wait for the thread to complete its task
	if (theDownloader2.joinable()) {
		theDownloader2.join();
	}

	return 0;
}


