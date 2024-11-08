
#include <iostream>
#include <thread>
#include <future>
static int Operation(std::promise<int>& data)
{
	using namespace std::chrono_literals;
	/* you create a corresponding std::future that can be used to asynchronously retrieve
	 * the result of the operation that the promise represents. */
	auto f = data.get_future();
	try
	{
		std::cout << "[Task] waiting for count\n";
		/* Blocks the current thread until the value becomes available. */
		auto count = f.get();
		std::cout << "[Task] Count aquired\n";
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
	catch (std::exception&ex)
	{
		std::cout << "[Task] Exception: " << ex.what() << std::endl;
	}
	
}
int main(void)
{
	using namespace std::chrono_literals;
	std::promise<int> data;
	/* Pass the promise to future of function by reference */
	std::future<int> result = std::async(std::launch::async, Operation, std::ref(data));
	std::this_thread::sleep_for(1s);
	std::cout << "[main] setting the data in Promise" << std::endl;

	try
	{
		throw std::runtime_error{ "Data not available" };
		data.set_value(10);
		/* Check if the future object is valid. */
		if (result.valid())
		{
			auto sum = result.get();
			std::cout << sum << std::endl;
		}
	}
	catch (std::exception&ex)
	{
		data.set_exception(std::make_exception_ptr(ex));
	}
	
	return 0;
}
