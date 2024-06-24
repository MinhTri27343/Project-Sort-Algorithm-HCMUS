#include<iostream>
#include<string>
#include<chrono>
#include<fstream>
#include<time.h>
using namespace std;
void BubbleSortComparison(int* arr, int N, long long& count_assign, long long& count_compare);
void BubbleSortTime(int* arr, int N, chrono::milliseconds& time);
void MergeSortComparison(int* arr, int N, long long& count_assign, long long& count_compare);
void MergeSortTime(int* arr, int N, chrono::milliseconds& time);
void RadixSortComparison(int* arr, int N, long long& count_assign, long long& count_compare);
void RadixSortTime(int* arr, int N, chrono::milliseconds& time);
void RadixSort(int* arr, int n);