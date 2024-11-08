
#include <iostream>
#include "FuncTemplate.h"


// Function template Print with a non-type template argument Size
template <int Size>
void Print() {
    // Print the value of the template argument Size
    std::cout << "Size: " << Size << std::endl;
}




// Function template Sum with a non-type template argument Size and a type template argument T
template <typename T, int Size>
T Sum(const T(&arr)[Size]) {
    // Initialize a variable sum to hold the sum of array elements
    T sum = 0;

    // Loop through each element of the array
    for (int i = 0; i < Size; ++i) {
        // Add the current element to the sum
        sum += arr[i];
    }

    // Return the sum of array elements
    return sum;
}




// Main function where the program execution begins
int Func_Run() {
    // Invoking the Print function with a template argument of 3
    Print<3>(); // This will print "Size: 3" to the console




    // Initialize an array of integers
    int arr[] = { 1, 2, 3, 4, 5 };

    // Call the Sum function with the array as argument
    // The function template arguments are deduced from the array type and size
    // In this case, T is deduced as int, and Size is deduced as 5
    std::cout << "Sum: " << Sum(arr) << std::endl;


    return 0; // Indicate successful program termination
}

