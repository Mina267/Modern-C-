#include <iostream>
#include "UnorderedContainers.h"

#include <unordered_set>
void Unset(void)
{
	/* The std::unordered_set template accepts four template parameters:
	 * First Type of the Element.
	 * Second Type of the Hash Function
     * Third Equality Operator.
	 * Fourth Allocator. 
	 */
	std::unordered_set<std::string> Unset;
	Unset.insert("Mina Magdy");
	Unset.insert("Olivia Rodrigo");
	Unset.insert("Imagine Dragons");
	Unset.insert("Jennifer Lawrence");
	Unset.insert("Pedro Pascal");
	Unset.insert("Emma Stone");
	Unset.insert("Cillian Murphy");
	Unset.insert("Dwayne Johnson");
	Unset.insert("Jason Statham");
	Unset.insert("Rebecca Ferguson");
	Unset.insert("Florence Pugh");
	Unset.insert("Zendaya");
	Unset.insert("Margot Robbie");


	for (const auto& x : Unset)
	{
		/* Show which bucket, a particular element has been inserted. */
		std::cout << "Bucket #" << Unset.bucket(x) << " ,Contains: " << x << std::endl;
	}

	std::cout << "Bucket count: " << Unset.bucket_count() << std::endl;
	std::cout << "Number of elements: " << Unset.size() << std::endl;
	std::cout << "Lead Factor: " << Unset.load_factor() << std::endl;

}



void Multiset(void)
{
	/* Unordered set does not allow duplicates, but unordered multiset does, */
	std::unordered_multiset<std::string> UnMset;
	UnMset.insert("Mina Magdy");
	UnMset.insert("Olivia Rodrigo");
	UnMset.insert("Imagine Dragons");
	UnMset.insert("Jennifer Lawrence");
	UnMset.insert("Pedro Pascal");
	UnMset.insert("Emma Stone");
	UnMset.insert("Rebecca Ferguson");
	UnMset.insert("Rebecca Ferguson");
	UnMset.insert("Rebecca Ferguson");
	UnMset.insert("Rebecca Ferguson");
	UnMset.insert("Rebecca Ferguson");
	UnMset.insert("Rebecca Ferguson");
	UnMset.insert("Rebecca Ferguson");

	for (const auto& x : UnMset)
	{
		/* Show which bucket, a particular element has been inserted. */
		std::cout << "Bucket #" << UnMset.bucket(x) << " ,Contains: " << x << std::endl;
	}

	std::cout << "Bucket count: " << UnMset.bucket_count() << std::endl;
	std::cout << "Number of elements: " << UnMset.size() << std::endl;
	std::cout << "Lead Factor: " << UnMset.load_factor() << std::endl;

}


#include <unordered_map>

void UnMap()
{
	/* In the unordered_map template, the parameters are as follows:
	 * The first  template parameter the type of the key.
	 * The second template parameter the type of the value.
	 * The third  template parameter the type of the hash function.
	 * The fourth template parameter the type of the function object that uses the equality operator to compare keys.
	 * The fifth  template parameter the allocator.
	*/
	std::unordered_map<std::string, std::string> UnMapSet;
	UnMapSet["Batman"] = "Brue wayne";
	UnMapSet["Ironman"] = "Robert Downey Jr.";
	UnMapSet["Spiderman"] = "Tobey Maguire";

	for (const auto& x : UnMapSet)
	{
		std::cout << "Bucket #" << UnMapSet.bucket(x.first) << "  " << x.first << ": " << x.second << std::endl;
	}

	/* For Duplication */
	std::unordered_multimap<std::string, std::string> UnMapDSet;
	/* the subscript operator not overloaded, Mandatory to use insert function */
	UnMapDSet.insert(std::make_pair("Batman", "Brue wayne"));
	UnMapDSet.insert(std::make_pair("Batman", "Robert Pattinson"));
	UnMapDSet.insert(std::make_pair("Ironman", "Robert Downey Jr."));
	UnMapDSet.insert(std::make_pair("Spiderman", "Tobey Maguire"));
	
}