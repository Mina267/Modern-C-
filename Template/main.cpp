#include <iostream>
#include <utility> // for std::pair
#include "Assignment.h"


int main() {
    // Example usage
    int intArray[] = { 1, 2, 3, 4, 5 };
    double doubleArray[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    const int arraySize = 5;

    // Add_Nums
    int sumInt = Add_Nums(5, 10);
    double sumDouble = Add_Nums(3.14, 2.71);
    std::cout << "Sum of integers: " << sumInt << std::endl;
    std::cout << "Sum of doubles: " << sumDouble << std::endl;

    // ArraySum
    int sumIntArray = ArraySum<int, arraySize>(intArray);
    double sumDoubleArray = ArraySum<double, arraySize>(doubleArray);
    std::cout << "Sum of integer array: " << sumIntArray << std::endl;
    std::cout << "Sum of double array: " << sumDoubleArray << std::endl;

    // MaxInArray
    int maxInt = MaxInArray<int, arraySize>(intArray);
    double maxDouble = MaxInArray<double, arraySize>(doubleArray);
    std::cout << "Max in integer array: " << maxInt << std::endl;
    std::cout << "Max in double array: " << maxDouble << std::endl;

    // MinMax
    auto minMaxInt = MinMax<int, arraySize>(intArray);
    auto minMaxDouble = MinMax<double, arraySize>(doubleArray);
    std::cout << "Min and Max in integer array: " << minMaxInt.first << ", " << minMaxInt.second << std::endl;
    std::cout << "Min and Max in double array: " << minMaxDouble.first << ", " << minMaxDouble.second << std::endl;

    const char* arr[] = { "apple", "banana", "orange" };
    auto result = MinMax(arr);

    std::cout << "Minimum string: " << result.first << std::endl;
    std::cout << "Maximum string: " << result.second << std::endl;

    std::string arr2[] = { "apple", "banana", "orange" };
    auto result2 = MinMax(arr2);

    std::cout << "Minimum string: " << result2.first << std::endl;
    std::cout << "Maximum string: " << result2.second << std::endl;

    return 0;
}
