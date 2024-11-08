#include <iostream>
#include <thread>
#include <Windows.h>
static void Process()
{
	/* Return the ID of function running thread */
	std::cout << "ProcessThreadID: " << std::this_thread::get_id() << std::endl;
	for (int i = 0; i < 100; ++i)
	{
		/* Delay */
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << i << ' ';
	}
	std::cout << std::endl;
}
int Func(void)
{
	/* Creates a new thread t1 and associates it with the function Process.
	 * When the thread is started, it will execute the Process function.
	 */
	std::thread t1(Process);

	/* Retrieves the unique identifier (ID) of the thread t1 using the get_id() method.
	 * The ID is stored in the variable id.
	 */
	auto id = t1.get_id();
	std::cout << id << std::endl;

	/* Return the ID of function running thread */
	std::cout << "MainThreadID: " << std::this_thread::get_id() << std::endl;

	/* The native handle represents the underlying operating system thread handle.
	 * It is a platform-specific type that allows interaction with the operating system's thread management functions.
	 */
	HANDLE handle = t1.native_handle();

	/* On Linux, use pthread_setname_np system call */
	SetThreadDescription(handle, L"MyThread");

	/* Number of Cores in machine */
	int cores = std::thread::hardware_concurrency();
	std::cout << "Cores: " << cores << std::endl;

	t1.join();
	return 0;
}




