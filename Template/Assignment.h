#pragma once



template <typename T>
T Add_Nums(T n1, T n2)
{
	return (n1 + n2);
}

template <typename T, const int size>
T ArraySum(const T(&arr)[size])
{
	T sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
}

template <typename T, const int size>
T MaxInArray(const T(&arr)[size])
{
	T Max = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (Max < arr[i])
		{
			Max = arr[i];
		}
	}
	return Max;
}

template <typename T, const int size>
std::pair<T, T> MinMax(const T (&arr)[size])
{
	T Max = arr[0];
	T Min = arr[0];

	for (int i = 1; i < size; i++)
	{
		if (Max < arr[i])
		{
			Max = arr[i];
		}
		if (Min > arr[i])
		{
			Min = arr[i];
		}
	}
	// Create and return a pair containing the minimum and maximum values
	return std::make_pair(Min, Max);;

}



template <const int size>
std::pair<const char*, const char*> MinMax(const char* (&arr)[size])
{
	const char* Max = arr[0];
	const char* Min = arr[0];

	for (int i = 1; i < size; i++)
	{
		if (std::strcmp(arr[i], Min) < 0)
		{
			Min = arr[i];
		}
		if (std::strcmp(arr[i], Max) > 0)
		{
			Max = arr[i];
		}
		
	}
	// Create and return a pair containing the minimum and maximum values
	return std::make_pair(Min, Max);;

}



template <const int size>
std::pair<std::string, std::string> MinMax(std::string (&arr)[size])
{
	std::string Max = arr[0];
	std::string Min = arr[0];

	for (int i = 1; i < size; i++)
	{
		if (arr[i] < Min)
		{
			Min = arr[i];
		}
		if (arr[i] > Max)
		{
			Max = arr[i];
		}

	}
	// Create and return a pair containing the minimum and maximum values
	return std::make_pair(Min, Max);;

}