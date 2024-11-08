#pragma once

int Func_Run();
template <typename T, int Size>
T Sum(const T(&arr)[Size]);

template <int Size>
void Print();