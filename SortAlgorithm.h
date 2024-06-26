#include<iostream>
#include<string>
#include<chrono>
#include<fstream>
#include<time.h>
#include<vector>
using namespace std;
void BubbleSortComparison(int* arr, int N, long long& count_assign, long long& count_compare);
void BubbleSortTime(int* arr, int N, chrono::microseconds& time);
void MergeSortComparison(int* arr, int N, long long& count_assign, long long& count_compare);
void MergeSortTime(int* arr, int N, chrono::microseconds& time);
void RadixSortComparison(int* arr, int N, long long& count_assign, long long& count_compare);
void RadixSortTime(int* arr, int N, chrono::microseconds& time);
void CountingSortComparison(int* arr, int N, long long& count_assign, long long& count_compare);
void CountingSortTime(int* arr, int N, chrono::microseconds& time);
void HeapSortComparison(int* arr, int N, long long& count_assign, long long& count_compare);
void HeapSortTime(int* arr, int N, chrono::microseconds& time);
void ShakerSortComparison(int* arr, int N, long long& count_assign, long long& count_compare);
void ShakerSortTime(int* arr, int N, chrono::microseconds& time);
void FlashSortComparison(int* arr, int N, long long& count_assign, long long& count_compare);
void FlashSortTime(int* arr, int N, chrono::microseconds& time);
void ShellSortComparison(int* arr, int N, long long& count_assign, long long& count_compare);
void ShellSortTime(int* arr, int N, chrono::microseconds& time);
void InsertionSortComparison(int* arr, int N, long long& count_assign, long long& count_compare);
void InsertionSortTime(int* arr, int N, chrono::microseconds& time);
void SelectionSortComparison(int* arr, int N, long long& count_assign, long long& count_compare);
void SelectionSortTime(int* arr, int N, chrono::microseconds& time);
void QuickSortComparison(int* arr, int N, long long& count_assign, long long& count_compare);
void QuickSortTime(int* arr, int N, chrono::microseconds& time);