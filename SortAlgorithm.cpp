#include"SortAlgorithm.h"
// Algorithm Bubble Sort
void BubbleSort(int* arr, int N)
{
	for (int i = 0; i < N - 1; i++)
	{
		bool flag = 0;
		for (int j = 0; j < N - 1 - i; j++)
		{
			if (arr[j + 1] < arr[j])
			{
				flag = 1;
				swap(arr[j + 1], arr[j]);
			}
		}
		if (!flag) return;
	}
}

// Count number of comparisio of bubble sort algorithms
void BubbleSortComparison(int* arr, int N, long long& count_assign, long long& count_compare)
{
	count_assign = 0;
	count_compare = 0;
	for (int i = 0; ++count_compare && i < N - 1; i++)
	{
		count_assign++;
		bool flag = 0; count_assign++;
		for (int j = 0; ++count_compare && j < N - 1 - i; j++)
		{
			count_assign++;
			if (++count_compare && arr[j + 1] < arr[j])
			{
				int temp = arr[j]; count_assign++;
				arr[j] = arr[j + 1]; count_assign++;
				arr[j + 1] = temp; count_assign++;
				flag = 1; count_assign++;
			}
		}
		if (++count_compare && flag == 0) return;
	}
}

// Calculate execution time of bubble sort algorithms
void BubbleSortTime(int* arr, int N, chrono::milliseconds& time)
{
	// get start time
	auto start = chrono::steady_clock::now();

	// Call BubbleSort function
	BubbleSort(arr, N);

	// get end time
	auto end = chrono::steady_clock::now();

	// calculate duration
	time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
}