#pragma once

class Animal
{
public:
	void Eat()
	{
		std::cout << "Animal eating" << std::endl;
	}
	void Run()
	{
		std::cout << "Animal running" << std::endl;
	}
	void Speak()
	{
		std::cout << "Animal speaking" << std::endl;
	}
	Animal()
	{
	}

	~Animal()
	{
	}

private:

};

/* That class will automatically inherit the behaviors of an animal class */
class Dog : public Animal
{
public:
	
	/* There is some behaviors that may differ from animal behaviors 
	 * We can rewrite it again.
	 * We will change the eat and run behaviors from the Parent class.
	 * inheritance allows us to reuse the behaviors of a base class 
	 * but at the same time we can also provide our own implementation for some of the behaviors.
	 */
	void Eat()
	{
		std::cout << "Dog eating meat" << std::endl;
	}
	void Speak()
	{
		std::cout << "Dog barking" << std::endl;
	}

	
	Dog()
	{
	}

	~Dog()
	{
	}

private:

};
