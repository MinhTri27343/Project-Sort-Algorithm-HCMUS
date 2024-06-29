#include"SortAlgorithm.h"
// Algorithm Bubble Sort
int stack[500000];
void BubbleSort(int* arr, int N)
{
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - 1 - i; j++)
		{
			if (arr[j + 1] < arr[j])
			{
				swap(arr[j + 1], arr[j]);
			}
		}
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
		for (int j = 0; ++count_compare && j < N - 1 - i; j++)
		{
			count_assign++;
			if (++count_compare && arr[j + 1] < arr[j])
			{
				int temp = arr[j]; count_assign++;
				arr[j] = arr[j + 1]; count_assign++;
				arr[j + 1] = temp; count_assign++;
			}
		}
		if (++count_compare) return;
	}
}

// Calculate execution time of bubble sort algorithms
void BubbleSortTime(int* arr, int N, chrono::microseconds& time)
{
	// get start time
	auto start = chrono::steady_clock::now();

	// Call BubbleSort function
	BubbleSort(arr, N);

	// get end time
	auto end = chrono::steady_clock::now();

	// calculate duration
	time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
}


// Merge two arrays in asscending order
void MergeComparison(int arr[], int l, int m, int r, long long& count_assign, long long& count_compare)
{
	int n1 = m - l + 1; count_assign++; // get size of arr1
	int n2 = r - m; count_assign++; // get size of arr2
	int* arr1 = new int[n1];
	int* arr2 = new int[n2];
	for (int i = l; ++count_compare && i <= m; i++)
	{
		count_assign++;
		arr1[i - l] = arr[i]; count_assign++; // Assign arr1 array
	}
	for (int i = m + 1; ++count_compare && i <= r; i++)
	{
		count_assign++;
		arr2[i - m - 1] = arr[i]; count_assign++; // Assign arr2 array
	}
	int idx1 = 0; count_assign++;
	int idx2 = 0; count_assign++;

	// Merge two arrays in asscending order
	while (++count_compare && idx1 < n1 && ++count_compare && idx2 < n2)
	{
		if (++count_compare && arr1[idx1] <= arr2[idx2])
		{
			arr[l] = arr1[idx1]; count_assign++;
			idx1++; count_assign++;
			l++; count_assign++;
		}
		else
		{
			arr[l] = arr2[idx2]; count_assign++;
			idx2++; count_assign++;
			l++; count_assign++;
		}
	}
	while (++count_compare && idx1 < n1)
	{
		arr[l] = arr1[idx1]; count_assign++;
		l++; count_assign++;
		idx1++; count_assign++;
	}
	while (++count_compare && idx2 < n2)
	{
		arr[l] = arr2[idx2]; count_assign++;
		l++; count_assign++;
		idx2++; count_assign++;
	}
	delete[] arr1;
	delete[] arr2;
}

//  Merge two arrays in asscending order
void Merge(int arr[], int l, int m, int r)
{
	int n1 = m - l + 1;// get size of arr1
	int n2 = r - m;// get size of arr2
	int* arr1 = new int[n1];
	int* arr2 = new int[n2];
	for (int i = l; i <= m; i++)
	{
		arr1[i - l] = arr[i]; // Assign arr1 array
	}
	for (int i = m + 1; i <= r; i++)
	{
		arr2[i - m - 1] = arr[i]; // Assign arr2 array
	}
	int idx1 = 0;
	int idx2 = 0;
	// Merge two arrays in asscending order
	while (idx1 < n1 && idx2 < n2)
	{
		if (arr1[idx1] <= arr2[idx2])
		{
			arr[l] = arr1[idx1];
			idx1++;
			l++;
		}
		else
		{
			arr[l] = arr2[idx2];
			idx2++;
			l++;
		}
	}
	while (idx1 < n1)
	{
		arr[l] = arr1[idx1];
		l++;
		idx1++;
	}
	while (idx2 < n2)
	{
		arr[l] = arr2[idx2];
		l++;
		idx2++;
	}
	delete[] arr1;
	delete[] arr2;
}

// Merge sort algorithm
void MergeSort(int* arr, int l, int r)
{
	if (l >= r) return;
	int m = (l + r) / 2;
	MergeSort(arr, l, m);
	MergeSort(arr, m + 1, r);
	Merge(arr, l, m, r);
}
// Merge sort algorithm and count number of comparision
void Merge_Sort_Comparison(int* arr, int l, int r, long long& count_assign, long long& count_compare)
{
	if (++count_compare && l >= r) return;
	int m = (l + r) / 2; count_assign++;
	Merge_Sort_Comparison(arr, l, m, count_assign, count_compare);
	Merge_Sort_Comparison(arr, m + 1, r, count_assign, count_compare);
	MergeComparison(arr, l, m, r, count_assign, count_compare);
}
// Merge sort algorithm and count number of comparision
void MergeSortComparison(int* arr, int N, long long& count_assign, long long& count_compare)
{
	count_assign = 0;
	count_compare = 0;
	int l = 0; count_assign++;
	int r = N - 1; count_assign++;
	Merge_Sort_Comparison(arr, l, r, count_assign, count_compare);
}
// Merge sort algorithm and determine execution time 
void MergeSortTime(int* arr, int N, chrono::microseconds& time)
{
	// get start time
	auto start = chrono::steady_clock::now();

	// Call MergeSort function
	MergeSort(arr, 0, N - 1);

	// get end time
	auto end = chrono::steady_clock::now();

	// calculate duration
	time = chrono::duration_cast<std::chrono::microseconds>(end - start);
}

// get number of digits of integer
int getNumberOfDigits(int n, long long& count_assign, long long& count_compare)
{
	int result = 0; count_assign++;
	while (++count_compare && n > 0)
	{
		result++; count_assign++;
		n = n / 10; count_assign++;
	}
	return result;
}
// get number of digits of integer
int get_Number_Of_Digits(int n)
{
	int result = 0;
	while (n > 0)
	{
		result++;
		n = n / 10;
	}
	return result;
}

// Get digit of n at position k (k in range [1, n] )
int getDigitAtPositionK(int n, int k, long long& count_assign, long long& count_compare)
{
	int numberDigit = getNumberOfDigits(n, count_assign, count_compare); count_assign++;
	string number = to_string(n); count_compare += numberDigit + 2; count_assign += 2 * numberDigit + 2;
	if ((++count_compare && k <= 0) || (++count_compare && k > n)) return 0;
	else
	{
		return number[k - 1] - '0';
	}
}

// Get digit of n at position k (k in range [1, n] )
int get_Digit_At_Position_K(int n, int k)
{
	int numberDigit = get_Number_Of_Digits(n);
	string number = to_string(n);
	if (k <= 0 || k > n) return 0;
	else
	{
		return number[k - 1] - '0';
	}
}

// save array from vetor
void saveArrayFromVector(int* arr, vector<int>* v, int N, long long& count_assign, long long& count_compare)
{
	int idx = 0; count_assign++;
	for (int i = 0; ++count_compare && i <= 9; i++)
	{
		count_assign++;
		if (++count_compare && !v[i].empty())
		{
			int n = v[i].size(); count_assign++;
			while (++count_compare && count_assign++ && n--)
			{
				arr[idx] = v[i][v[i].size() - n - 1]; count_assign++;
				idx++; count_assign++;
			}
		}
		v[i] = vector<int>(); count_assign++;
	}
}
// save array from vetor
void save_Array_From_Vector(int* arr, vector<int>* v, int N)
{
	int idx = 0;
	for (int i = 0; i <= 9; i++)
	{
		if (!v[i].empty())
		{
			int n = v[i].size();
			while (n--)
			{
				arr[idx] = v[i][v[i].size() - n - 1];
				idx++;
			}
		}
		v[i] = vector<int>();
	}
}
// Radix Sort Algorithms
void RadixSortComparison(int* arr, int N, long long& count_assign, long long& count_compare)
{
	count_assign = 0;
	count_compare = 0;
	vector<int>* save = new vector<int>[10]; count_assign++;
	int numberDigitMax = getNumberOfDigits(arr[0], count_assign, count_compare);  count_assign++;
	for (int i = 1; ++count_compare && i < N; i++)
	{
		count_assign++;
		int numberDigitCurr = getNumberOfDigits(arr[i], count_assign, count_compare);  count_assign++;
		if (++count_compare && numberDigitMax < numberDigitCurr)
		{
			numberDigitMax = numberDigitCurr;  count_assign++;
		}
	}
	for (int j = 0; ++count_compare && j < numberDigitMax; j++)
	{
		count_assign++;
		for (int i = 0; ++count_compare && i < N; i++)
		{
			count_assign++;
			int numberDigit = getNumberOfDigits(arr[i], count_assign, count_compare); count_assign++;
			int digitPos = getDigitAtPositionK(arr[i], numberDigit - j, count_assign, count_compare);  count_assign++;
			save[digitPos].push_back(arr[i]);
		}
		saveArrayFromVector(arr, save, N, count_assign, count_compare);
	}
	delete[] save;
}

// Radix Sort Algorithms
void RadixSort(int* arr, int N)
{
	vector<int>* save = new vector<int>[10];
	int numberDigitMax = get_Number_Of_Digits(arr[0]);
	for (int i = 1; i < N; i++)
	{
		int numberDigitCurr = get_Number_Of_Digits(arr[i]);
		if (numberDigitMax < numberDigitCurr)
		{
			numberDigitMax = numberDigitCurr;
		}
	}
	for (int j = 0; j < numberDigitMax; j++)
	{
		for (int i = 0; i < N; i++)
		{
			int numberDigit = get_Number_Of_Digits(arr[i]);
			int digitPos = get_Digit_At_Position_K(arr[i], numberDigit - j);
			save[digitPos].push_back(arr[i]);
		}
		save_Array_From_Vector(arr, save, N);
	}
	delete[] save;
}

// Radix sort algorithm and determine execution time 
void RadixSortTime(int* arr, int N, chrono::microseconds& time)
{
	// get start time
	auto start = chrono::steady_clock::now();

	// Call MergeSort function
	RadixSort(arr, N);

	// get end time
	auto end = chrono::steady_clock::now();

	// calculate duration
	time = chrono::duration_cast<std::chrono::microseconds>(end - start);
}

void CountingSortComparison(int* arr, int N, long long& count_assign, long long& count_compare)
{
	count_assign = 0; count_compare = 0;

	// Create a temporary array for sorting
	int* output = new int[N]; ++count_assign;

	// Find the largest and smallest element of the array 
	// to find the range of the count array
	int max = 0; ++count_assign;
	int min = INT_MAX; ++count_assign;
	++count_assign;
	for (int i = 0; ++count_compare && i < N; i++, ++count_assign)
	{
		if (++count_compare && arr[i] > max)
		{
			max = arr[i]; ++count_assign;
		}
		else if (++count_compare && arr[i] < min)
		{
			min = arr[i]; ++count_assign;
		}
	}

	// Initialize the counting array with 0
	int range = max - min + 1;
	int* count = new int[range] {0}; count_assign += range;

	// Store count of occurrences in count[]
	++count_assign;
	for (int i = 0; ++count_compare && i < N; i++, ++count_assign)
	{
		count[arr[i] - min]++; ++count_assign;
	}

	// Store the cummulative count
	++count_assign;
	for (int i = 1; ++count_compare && i < range; i++, ++count_assign)
	{
		count[i] += count[i - 1]; ++count_assign;
	}

	// Place the elements in sorted order
	++count_assign;
	for (int i = N - 1; ++count_compare && i >= 0; i--, ++count_assign)
	{
		output[count[arr[i] - min] - 1] = arr[i]; ++count_assign;
		count[arr[i] - min]--; ++count_assign;
	}

	// Copy from temporary array to original array
	++count_assign;
	for (int i = 0; ++count_compare && i < N; i++, ++count_assign)
	{
		arr[i] = output[i]; ++count_assign;
	}

	// Deallocate
	delete[] output;
	delete[] count;
}

void CountingSortTime(int* arr, int N, chrono::microseconds& time)
{
	auto start = chrono::steady_clock::now();

	int* output = new int[N];

	int max = 0;
	int min = INT_MAX;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		else if (arr[i] < min)
			min = arr[i];
	}

	int range = max - min + 1;
	int* count = new int[range] {0};

	for (int i = 0; i < N; i++)
		count[arr[i] - min]++;

	for (int i = 1; i < range; i++)
		count[i] += count[i - 1];

	for (int i = N - 1; i >= 0; i--)
	{
		output[count[arr[i] - min] - 1] = arr[i];
		count[arr[i] - min]--;
	}

	for (int i = 0; i < N; i++)
		arr[i] = output[i];

	delete[] output;
	delete[] count;

	auto finish = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::microseconds>(finish - start);
}
void InsertionSortComparison(int* arr, int N, long long& count_assign, long long& count_compare)
{
	count_assign = 0; count_compare = 0;

	for (int i = 1 && ++count_assign; ++count_compare && i < N; i++ && ++count_assign)
	{
		int key = arr[i]; ++count_assign;
		int j = i - 1; ++count_assign;

		while ((++count_compare && j >= 0) && (++count_compare && arr[j] > key))
		{
			arr[j + 1] = arr[j]; ++count_assign;
			--j; ++count_assign;
		}

		arr[j + 1] = key; ++count_assign;
	}
}

void InsertionSortTime(int* arr, int N, chrono::microseconds& time)
{
	auto start = chrono::steady_clock::now();

	for (int i = 1; i < N; i++)
	{

		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			--j;
		}

		arr[j + 1] = key;
	}

	auto finish = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::microseconds>(finish - start);
}
void ShellSortComparison(int* arr, int N, long long& count_assign, long long& count_compare)
{
	count_assign = 0; count_compare = 0;

	// Initialize the value of gap size,
	// Divide the current list into smaller sub-lists having equal size with the given gap
	++count_assign;
	for (int gap = N / 2; ++count_compare && gap > 0; gap /= 2, ++count_assign)
	{
		// Sort the sub-lists using Insertion Sort
		++count_assign;
		for (int i = gap; ++count_compare && i < N; i += 1, ++count_assign)
		{
			int key = arr[i]; ++count_assign;
			int j;

			++count_assign;
			for (j = i; ++count_compare && ++count_compare && j >= gap && arr[j - gap] > key; j -= gap, ++count_assign) {
				arr[j] = arr[j - gap]; ++count_assign;
			}

			arr[j] = key; ++count_assign;
		}
	}
}
void ShellSortTime(int* arr, int N, chrono::microseconds& time)
{
	auto start = chrono::steady_clock::now();

	for (int gap = N / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < N; i += 1)
		{
			int key = arr[i];
			int j;

			for (j = i; j >= gap && arr[j - gap] > key; j -= gap)
				arr[j] = arr[j - gap];

			arr[j] = key;
		}
	}

	auto finish = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::microseconds>(finish - start);
}
// Heap Sort
void heapifyComparison(int* arr, int N, int i, long long& count_assign, long long& count_compare)
{
	// Initialize largest as root
	++count_assign;
	int largest = i;

	// left = 2*i + 1
	++count_assign;
	int l = 2 * i + 1;

	// right = 2*i + 2
	++count_assign;
	int r = 2 * i + 2;

	// If left child is larger than root
	if ((++count_compare && l < N) && (++count_compare && arr[l] > arr[largest]))
	{
		++count_assign;
		largest = l;
	}
	// If right child is larger than largest
	// so far
	if ((++count_compare && r < N) && (++count_compare && arr[r] > arr[largest]))
	{
		++count_assign;
		largest = r;
	}
	// If largest is not root
	if (++count_compare && largest != i) {
		count_assign += 3;
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		// Recursively heapify the affected
		heapifyComparison(arr, N, largest, count_assign, count_compare);
	}
}
// Heap Sort main function
void HeapSortComparison(int* arr, int N, long long& count_assign, long long& count_compare)
{
	// Build heap
	for (int i = N / 2 - 1; ++count_compare && i >= 0; i--)
	{
		heapifyComparison(arr, N, i, count_assign, count_compare);
	}

	++count_assign;
	for (int i = N - 1; ++count_compare && i > 0; ++count_assign && i--) {

		// Move the largest to the end of the array
		count_assign += 3;
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;

		// call max heapify on the reduced heap
		heapifyComparison(arr, i, 0, count_assign, count_compare);
	}
}
void heapifyTime(int* arr, int N, int i)
{
	// Initialize largest as root
	int largest = i;

	// left = 2*i + 1
	int l = 2 * i + 1;

	// right = 2*i + 2
	int r = 2 * i + 2;

	// If left child is larger than root
	if (l < N && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest
	// so far
	if (r < N && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);
		// Recursively heapify the affected
		heapifyTime(arr, N, largest);
	}
}
// Heap Sort main function
void HeapSortTime(int* arr, int N, chrono::microseconds& time)
{
	auto start = chrono::steady_clock::now();
	// Build heap
	for (int i = N / 2 - 1; i >= 0; i--)
		heapifyTime(arr, N, i);

	for (int i = N - 1; i > 0; i--) {

		// Move the largest to the end of the array
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;

		// call max heapify on the reduced heap
		heapifyTime(arr, i, 0);
	}
	auto finish = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::microseconds>(finish - start);
}

int partitionComparison(int* arr, int start, int end, long long& count_assign, long long& count_compare)
{
	++count_assign;
	int pivot = arr[start];

	++count_assign;
	int count = 0;
	++count_assign;
	for (int i = start + 1; i <= end && ++count_compare; i++ && ++count_assign) {
		if (++count_compare && arr[i] <= pivot)
		{
			++count_assign;
			count++;
		}
	}

	// Giving pivot element its correct position
	++count_assign;
	int pivotIndex = start + count;
	count_assign += 3;
	int temp = arr[pivotIndex];
	arr[pivotIndex] = arr[start];
	arr[start] = temp;

	// Sorting left and right parts of the pivot element
	count_assign += 2;
	int i = start, j = end;

	while ((++count_compare && i < pivotIndex) && (++count_compare && j > pivotIndex)) {

		while (++count_compare && arr[i] <= pivot) {
			++count_assign;
			i++;
		}

		while (++count_compare && arr[j] > pivot) {
			++count_assign;
			j--;
		}

		if ((++count_compare && i < pivotIndex) && (++count_compare && j > pivotIndex)) {
			count_assign += 5;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			++i;
			--j;
		}
	}

	return pivotIndex;
}
void _QuickSort(int* arr, int start, int end, long long& count_assign, long long& count_compare)
{
	// Create a stack 

	// initialize top of stack 
	++count_assign;
	int top = -1;

	// push initial values of start and end to stack 
	count_assign += 4;
	stack[++top] = start;
	stack[++top] = end;

	// Keep popping from stack while it is not empty 
	while (++count_compare && top >= 0) {
		// Pop start and end
		count_assign += 4;
		end = stack[top--];
		start = stack[top--];

		// Set pivot element at its correct position 
		// in sorted array 
		++count_assign;
		int p = partitionComparison(arr, start, end, count_assign, count_compare);

		// If there are elements on left side of pivot, 
		// then push left side to stack 
		if (++count_compare && p - 1 > start) {
			count_assign += 4;
			stack[++top] = start;
			stack[++top] = p - 1;
		}

		// If there are elements on right side of pivot, 
		// then push right side to stack 
		if (++count_compare && p + 1 < end) {
			count_assign += 4;
			stack[++top] = p + 1;
			stack[++top] = end;
		}
	}
}
void QuickSortComparison(int* arr, int N, long long& count_assign, long long& count_compare)
{
	_QuickSort(arr, 0, N - 1, count_assign, count_compare);
}

int partitionTime(int* arr, int start, int end)
{

	int pivot = arr[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot)
			count++;
	}

	// Giving pivot element its correct position
	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);

	// Sorting left and right parts of the pivot element
	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i] <= pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}
void QuickSort(int* arr, int start, int end)
{

	// initialize top of stack 
	int top = -1;

	// push initial values of start and end to stack 
	stack[++top] = start;
	stack[++top] = end;

	// Keep popping from stack while it is not empty 
	while (top >= 0) {
		// Pop start and end
		end = stack[top--];
		start = stack[top--];

		// Set pivot element at its correct position 
		// in sorted array 
		int p = partitionTime(arr, start, end);

		// If there are elements on left side of pivot, 
		// then push left side to stack 
		if (p - 1 > start) {
			stack[++top] = start;
			stack[++top] = p - 1;
		}

		// If there are elements on right side of pivot, 
		// then push right side to stack 
		if (p + 1 < end) {
			stack[++top] = p + 1;
			stack[++top] = end;
		}
	}
	delete[] stack;
}
void QuickSortTime(int* arr, int N, chrono::microseconds& time)
{
	auto start = chrono::steady_clock::now();
	QuickSort(arr, 0, N - 1);
	auto finish = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::microseconds>(finish - start);
}
// Comparison
void SelectionSortComparison(int* arr, int N, long long& count_assign, long long& count_compare)
{
	int minpos;
	++count_assign;
	for (int i = 0; ++count_compare && i < N - 1; i++ && ++count_assign)
	{
		++count_assign;
		minpos = i;
		++count_assign;
		for (int j = i + 1; ++count_compare && j < N; j++ && ++count_assign)
		{
			if (++count_compare && arr[j] < arr[minpos])
			{
				count_assign += 3;
				int temp = arr[minpos];
				arr[minpos] = arr[i];
				arr[i] = temp;
			}
		}
	}
	return;
}
// Time
void SelectionSortTime(int* arr, int N, chrono::microseconds& time)
{
	auto start = chrono::steady_clock::now();
	int minpos;
	for (int i = 0; i < N - 1; i++)
	{
		minpos = i;
		for (int j = i + 1; j < N; j++)
			if (arr[j] < arr[minpos])
				minpos = j;
		swap(arr[minpos], arr[i]);
	}
	auto finish = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::microseconds>(finish - start);
	return;
}
void ShakerSortComparison(int* arr, int N, long long& count_assign, long long& count_compare)
{
	count_assign = 0; // count assign
	count_compare = 0; // count compare;
	int left = 0; count_assign++; // the first of arr;
	int right = N - 1; count_assign++; // the end of arr;
	int mark_step = 0; count_assign++; // mark the step when swapping;
	while (++count_compare && left < right)
	{
		// Give the maximum of the array to the end of array
		count_assign++;
		for (int i = left; ++count_compare, i < right; i++, count_assign++) // traverse from left to right
		{
			if (++count_compare && arr[i] > arr[i + 1])
			{
				mark_step = i; count_assign++;
				swap(arr[i], arr[i + 1]); count_assign += 3;
			}
		}
		right = mark_step; count_assign++; // start from the mark_step
		// Give the minimum of the array to the first of array
		count_assign = count_assign + 1;
		for (int i = right; ++count_compare, i > left; i--, count_assign++) // traverse from right to left
		{
			if (++count_compare, arr[i] < arr[i - 1])
			{
				mark_step = i; count_assign++;
				swap(arr[i], arr[i - 1]); count_assign += 3;
			}
		}
		left = mark_step; count_assign++; // start from the mark_step
	}
}
void ShakerSortTime(int* arr, int N, chrono::microseconds& time)
{
	auto start = chrono::steady_clock::now();
	int left = 0; // the first of arr;
	int right = N - 1; // the end of arr;
	int mark_step = 0; // mark the step when swapping;
	while (left < right)
	{
		// Give the maximum of the array to the end of array
		for (int i = left; i < right; i++) // traverse from left to right
		{
			if (arr[i] > arr[i + 1])
			{
				mark_step = i;
				swap(arr[i], arr[i + 1]);
			}
		}
		right = mark_step; // start from the mark_step
		// Give the minimum of the array to the first of array
		for (int i = right; i > left; i--) // traverse from right to left
		{
			if (arr[i] < arr[i - 1])
			{
				mark_step = i;
				swap(arr[i], arr[i - 1]);
			}
		}
		left = mark_step; // start from the mark_step
	}
	auto finish = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::microseconds>(finish - start);
}
int bucket[500000];
void FlashSortComparison(int* arr, int N, long long& count_assign, long long& count_compare)
{
	count_assign = 0;
	count_compare = 0;
	if (++count_compare && N <= 1) return;
	if (++count_compare && N == 2)
	{
		if (++count_compare && arr[0] > arr[1])
		{
			count_assign += 3;
			swap(arr[0], arr[1]);
		}
		return;
	}
	int max = INT_MIN, min = INT_MAX; count_assign += 2;
	count_assign++;
	for (int i = 0; ++count_compare, i < N; i++, count_assign++)
	{
		if (++count_compare && arr[i] > max)
		{
			count_assign++;
			max = arr[i];
		}
		if (++count_compare && arr[i] < min)
		{
			count_assign++;
			min = arr[i];
		}
	}
	if (++count_compare && max == min) return;
	//Step 1: Classify
	int num_bucket = 0.45 * N; count_assign++; // 0.45 is the constant
	//Initialize buckets.
	count_assign += num_bucket;
	for (int i = 0; i < num_bucket; i++)
	{
		bucket[i] = 0;
	}
	count_assign++;
	for (int i = 0; count_compare++, i < N; i++, ++count_assign)
	{
		int k = 1ll * (num_bucket - 1) * (arr[i] - min) / (max - min); count_assign++;
		bucket[k] += 1; count_assign++; // if element in bucket, the number of element in bucket plus 1
	}
	count_assign++;
	for (int i = 1; count_compare++, i < num_bucket; i++, ++count_assign)
	{
		bucket[i] = bucket[i - 1] + bucket[i]; ++count_assign; // find the index of the end of each bucket.
	}

	//Step 2: Permutation
	int count = 0; count_assign++; // count the number of step
	int i = 0; count_assign++;
	// Permutate all the element into the correct bucket.
	while (++count_compare && count < N)
	{
		int k = 1ll * (num_bucket - 1) * (arr[i] - min) / (max - min); count_assign++;
		while (++count_compare && i >= bucket[k]) // If the bucket is full. Shift the index + 1.
		{
			i++; count_assign++;
			k = 1ll * (num_bucket - 1) * (arr[i] - min) / (max - min); count_assign++;
		}
		int value = arr[i]; count_assign++; // save the value.
		while (++count_compare && i != bucket[k])
		{
			k = 1ll * (num_bucket - 1) * (value - min) / (max - min); count_assign++;
			swap(arr[bucket[k] - 1], value); count_assign += 3; // change arr[bucket[k] - 1] = value, and value = arr[bucket[k] - 1];
			bucket[k]--; count_assign++; // decrease the nums of bucket by 1. Because adding the value in the bucket.
			count++; count_assign++;
		}
	}

	//Step 3: Insertion sort
	for (int i = 1 && ++count_assign; ++count_compare && i < N; i++ && ++count_assign)
	{
		int key = arr[i]; ++count_assign;
		int j = i - 1; ++count_assign;

		while ((++count_compare && j >= 0) && (++count_compare && arr[j] > key))
		{
			arr[j + 1] = arr[j]; ++count_assign;
			--j; ++count_assign;
		}
		arr[j + 1] = key; ++count_assign;
	}
}
//Similar to FlashSortComparison.
void FlashSortTime(int* arr, int N, chrono::microseconds& time)
{
	auto start = chrono::steady_clock::now();
	if (N <= 1)
	{
		auto finish = chrono::steady_clock::now();
		time = chrono::duration_cast<chrono::microseconds>(finish - start);
		return;
	}
	if (N == 2)
	{
		if (arr[0] > arr[1])
		{
			swap(arr[0], arr[1]);
		}
		auto finish = chrono::steady_clock::now();
		time = chrono::duration_cast<chrono::microseconds>(finish - start);
		return;
	}
	int max = INT_MIN, min = INT_MAX;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	if (max == min)
	{
		auto finish = chrono::steady_clock::now();
		time = chrono::duration_cast<chrono::microseconds>(finish - start);
		return;
	}
	//Step 1: Classify
	int num_bucket = 0.45 * N;// 0.45 is the constant
	for (int i = 0; i < num_bucket; i++)
	{
		bucket[i] = 0;
	}
	// divide element into (m) bucket
	for (int i = 0; i < N; i++)
	{
		// find index of bucket
		int k = 1ll * (num_bucket - 1) * (arr[i] - min) / (max - min);
		bucket[k] += 1; // if element in bucket, the number of element in bucket plus 1
	}
	for (int i = 1; i < num_bucket; i++)
	{
		bucket[i] = bucket[i - 1] + bucket[i]; // find the index of the end of each bucket.
	}

	//Step 2:
	int count = 0; // count the number of step
	int i = 0;
	// Permutate all the element into the correct bucket.
	while (count < N)
	{
		int k = 1ll * (num_bucket - 1) * (arr[i] - min) / (max - min);
		/*int k = (int)((num_bucket - 1) * ((float)(arr[i] - min) / (max - min)));*/ // find index of bucket
		while (i >= bucket[k]) // If the bucket is full. Shift the index + 1.
		{
			i++;
			k = 1ll * (num_bucket - 1) * (arr[i] - min) / (max - min);
		}
		int value = arr[i];// save the value.
		while (i != bucket[k])
		{
			k = 1ll * (num_bucket - 1) * (value - min) / (max - min);
			swap(arr[bucket[k] - 1], value); // change arr[bucket[k] - 1] = value, and value = arr[bucket[k] - 1];
			bucket[k]--; // decrease the nums of bucket by 1. Because adding the value in the bucket.
			count++;
		}
	}

	//Step 3:
	for (int i = 1; i < N; i++)
	{
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
	auto finish = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::microseconds>(finish - start);
}
