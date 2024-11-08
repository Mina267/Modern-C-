#include <iostream>


#include <array>

void Array(void)
{
	/* The array can Initialize throuh the uniform initialization syntax. */
	std::array<int, 5> arr{ 3, 5, 6, 7, 1 };
	/* using standard array it knows about its size, because it contains a function called as size(). */
	for (int i = 0; i < arr.size(); ++i)
	{
		/* Can access array using the subscript operator [ ] */
		arr[i] = i;
	}

	/* Create Iterators for array */
	auto itr = arr.begin();
	for (auto& x : arr)
	{
		std::cout << x << " ";
	}
	std::cout << std::endl;

	/* The data() function returns a pointer to the internal array
	 * can pass that pointer to C functions.
	 * standard array is backward compatible with C.
	 * You can then use this pointer to access or manipulate the elements of the array directly.
	 */
	 // Access the pointer to the underlying array
	int* ptr = arr.data();
}


#include <vector>

void Vector(void)
{
	/* The vector can be initialized through the uniform initialization syntax. 
     * It accepts two template parameters.
	 * One is the type, and the second is the allocator.
     * Allocators are classes that containers internally use to manage their memory. 
	 * The default allocator is good for most cases.
	 */
	std::vector<int> vec{ 3, 5, 6, 7, 1 };
	for (int i = 0; i < 5; ++i)
	{
		/* The push_back() function in C++ is used to add elements to the end of a std::vector.  */
		vec.push_back(i * 10);
		/* The size of the vector will increase as we add elements to it. */
		std::cout << vec.size() << std::endl;
	}

	/* Can access or edit vector using the subscript operator [ ] */
	/* Edit */
	vec[0] = 100;
	/* Access */
	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;


	/* The standard way of accessing the elements of the container is through iterators. */
	auto itr = vec.begin();
	while (itr != vec.end())
	{
		std::cout << *itr++ << " ";
	}
	std::cout << std::endl;

	/* To insert an element at a specific position in a vector,
	 * you use the insert() function along with an iterator pointing to the desired position.
	 * crucial to consider the performance implications of this operation.
	 * Inserting an element may require shifting existing elements,
	 * which involves copying elements and can be computationally expensive,
	 * especially for large vectors or when dealing with user-defined objects. */
	vec.insert(vec.begin(), 700);

	vec.erase(vec.end() - 5);
	vec.pop_back();

}




#include <deque>

void Deque(void)
{
	std::deque<int> deq{ 3, 5, 6, 7, 1 };
	for (int i = 0; i < 5; ++i)
	{
		/* The push_back() function in C++ is used to add elements to the end of a std::deque.  */
		deq.push_back(i * 10);
	}

	for (int i = 0; i < 5; ++i)
	{
		/* The push_front() function in C++ is used to add elements to the front of a std::deque.  */
		deq.push_front(i * 10);

	}

	/* Can access or edit deque using the subscript operator [ ] */
	/* Edit */
	deq[0] = 100;
	/* Access */
	for (int i = 0; i < deq.size(); ++i)
	{
		std::cout << deq[i] << " ";
	}
	std::cout << std::endl;


	/* The standard way of accessing the elements of the container is through iterators. */
	auto itr = deq.begin();
	while (itr != deq.end())
	{
		std::cout << *itr++ << " ";
	}
	std::cout << std::endl;

	/* To insert an element at a specific position in a deque,
	 * you use the insert() function along with an iterator pointing to the desired position.
	 */
	deq.insert(deq.begin(), 700);

	deq.erase(deq.end() - 5);
	deq.pop_back();
	deq.pop_front();

}

#include <list>

void List(void)
{
	/* The list can also be initialized using the initializer_list just like a vector and a deque  */
	std::list<int> li;

	for (int i = 0; i < 5; ++i)
	{
		/* The push_back() function in C++ is used to add elements to the end of a std::list.  */
		li.push_back(i * 10);
	}


	/* Can not access or edit list using the subscript operator [ ]
	* only use iterators */
	auto itr = li.begin();
	while (itr != li.end())
	{
		std::cout << *itr++ << " ";
	}
	std::cout << std::endl;

	/* Lists excel at insertions and deletions, offering constant-time complexity for
	 * these operations regardless of the position within the list. */
	itr = li.begin();
	li.insert(itr, 700);

}

#include <forward_list>
#include "SequenceContainer.h"

void ForwardList(void)
{
	std::forward_list<int> F_li{ 1,2,3,4,5 };
	for (int i = 0; i < 5; ++i)
	{
		/* Forward List only have The push_front() function used to add elements to the front of a std::forward_list.
		 * not have push_back() function.
		 */
		F_li.push_front(i * 10);
	}

	for (auto x : F_li)
	{
		std::cout << x << " ";
	}
	std::cout << std::endl;

	F_li.insert_after(F_li.begin(), 10);
	F_li.erase_after(F_li.begin());


}