
#include <iostream>
#include <thread>
#include <future>
static int Operation(int count)
{
	using namespace std::chrono_literals;
	int sum{};
	for (int i = 0; i < count; ++i)
	{
		sum += i;
		std::cout << '.';
		/* Delay */
		std::this_thread::sleep_for(300ms); // std::chrono::secomeds(1);
	}
	std::cout << std::endl;
	return sum;
}
int wait(void)
{
	using namespace std::chrono_literals;
	std::future<int> result = std::async(std::launch::async, Operation, 10);
	std::this_thread::sleep_for(1s);
	std::cout << "main() Thread continues execution" << std::endl;
	/* Check if the future object is valid. */
	if (result.valid())
	{
		auto timepoint = std::chrono::system_clock::now();
		timepoint += 1s;
		auto status = result.wait_until(timepoint);

		auto status2 = result.wait_for(4s);

		switch (status)
		{
		case std::future_status::ready:
			std::cout << "Task is Ready\n";
			break;
		case std::future_status::timeout:
			std::cout << "Task is still Running\n";
			break;
		case std::future_status::deferred:
			std::cout << "Task is Synchronous\n";
			break;
		default:
			break;
		}
		auto sum = result.get();
		std::cout << sum << std::endl;
	}
	return 0;
}




