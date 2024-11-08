

#include <iostream>
#include <string>

#include <set>
#include <functional>

void Set(void)
{
	/* The list can be Initialize throuh the uniform initialization syntax. 
	 * but the set will internally store the elements in the sorted order. 
	 * Create an instance of set; the set accepts three template parameters.
	 * The first is the type that you want to store.
     * The second is a comparator that the set will use for sorting the elements. 
	 * By default, It uses the comparator less, which is a function object, and the less than operator for comparison.
	 * The third parameter, as usual, is the allocator. 
	 */
	std::set<int, std::greater<int>> s{ 8,2,5,9,4 };
	/* Multi set allow Duplication */
	std::multiset<int, std::greater<int>> ms{ 8,2,2,2,6,6,5,5,5,9,4 };

	s.insert(1);
	/* If we set duplicate elements in a set, they will not appear. A set does not allow duplicats, but a multi-set does. */
	s.insert(3);
	s.insert(3);


	/* To add more elements to the set, there is no push_back or push_front. Instead, 
	 * there is a function called insert, and to access the elements, we can use the iterators. 
	 *  All the iterators are constant. That means you cannot modify the elements through the iterator directly.
	 */
	auto itr = s.begin();
	while (itr != s.end())
	{
		std::cout << *itr++ << " ";
	}
	std::cout << std::endl;

	/* Erase Elements */
	s.erase(0); 
	s.erase(s.begin());

	/* To search for an element, associated containers provide a function called find(), 
	 * which accepts the key. If find() is able to locate the element, then it'll return the iterator to that element.
	 * If the iterator points to the end, that means that element is not found. */
	itr = s.find(9);
	if (itr != s.end())
	{
		std::cout << "Element found!" << std::endl;
	}
	else
	{
		std::cout << "Not found!" << std::endl;

	}
	/* Search in multi list for all of the occurrence over the number. */
	auto found = ms.equal_range(3);
	while (found.first != found.second)
	{
		std::cout << *found.first++ << " ";
	}
	std::cout << std::endl;


}

#include <map>
#include "AssociativeContainer.h"

void Map(void)
{
	/* Map accepts multiple template parameters; the first parameter is the type of the key.
	 * The second parameter is the type of the value; Will use a string as the value; 
	 * the third is the comparator object; 
	 * and finally, the allocator.  
	 */
	std::map<int, std::string> m{
		{1, "Mina Magdy"},
		{2, "Olivia Rodrigo"},
		{3, "Imagine Dragons"},
	};
	/* To insert a pair object into a map using the insert() function, you need to create a temporary object of type std::pair.  */
	m.insert(std::pair<int, std::string>(5, "Jennifer Lawrence"));

	/* a map does not allow duplicate keys. So, if we try to insert a pair that contains a key 
	* which already exists in the map, then the new pair will be discarded. */
	m.insert(std::make_pair(9, "Pedro Pascal"));
	m.insert(std::make_pair(9, "Pedro Pascal"));


	/* Intsert elemnt by using overloaded subscript operator */
	m[0] = "Emma Stone";

	/* You cannot directly modify a key but you can modify its value, so we can modify the value using the subscript operator,*/
	m[0] = "Cillian Murphy";


	/* To remove an element from a set, you can utilize the `erase()` function. This function is versatile,
	  offering differen*t overloads to accommodate various removal scenarios. It can either accept a position or the key. */
	m.erase(0);

	/* Iterator points to a pair object So, you need to access the key and value separately. */
	auto itr = m.begin();
	
	/* The arrow (->) operator is overloaded for the iterator in a way similar to smart pointers. 
	 * It allows convenient access to the members of the underlying type without explicitly dereferencing the iterator. 
	 */
	std::cout << itr->first << " : " << itr->second << std::endl;

	for (const auto& i : m)
	{
		std::cout << i.first << " : " << i.second << std::endl;
	}

	/* To perform a search operation, you can use the function called find, and you can find based on the key. 
     * This will return the iterator to the object that has been found.
     * If the pair object with the specified key is not found, then the find function will return an iterator to the end. 
	 */
	itr = m.find(1);
	if (itr != m.end())
	{
		std::cout << "Found: " << itr->second << std::endl;
	}
	else
	{
		std::cout << "Not found!" << std::endl;

	}

	/* To access the values of specified keys, you can use the subscript operator. However, 
	 * this approach presents a potential issue: if a key does not exist, 
	 * using the subscript operator will insert it into the map with a default value. 
	 * Therefore, when using the subscript operator, be cautious about inadvertently inserting new key-value pairs into the map. 
	 */
	std::cout << m[2] << std::endl;
	/* Key did not extist will add new key into map */
	std::cout << "10: " << m[10] << std::endl;

}





void MultiMap(void)
{
	/* If you need to store duplicates, you can utilize a multimap.Unlike regular maps, 
	 * multimap's subscript operator is not overloaded, allowing duplicate keys with different values. 
	 * Multimap also supports the function `equal_range()`, which facilitates searching for all equivalent keys. 
	 * Upon specifying a key, the function returns a pair object with iterators pointing to the first and last elements found. 
	 * Remember to use the arrow operator to access the pair object and retrieve the desired values. */
	std::map<int, std::string> m{
		{1, "Mina Magdy"},
		{2, "Olivia Rodrigo"},
		{2, "Olivia Rodrigo"},
		{2, "Olivia Rodrigo"},
		{3, "Imagine Dragons"},
	};

	auto found = m.equal_range(2);
	while (found.first != found.second)
	{
		std::cout << found.first->first << " : " << found.first->second << std::endl;
	}
}