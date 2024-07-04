#include"CommandLine.h"
#include<iomanip>
#include <cstring>

const char* algorithmName[] = { "selection-sort", "insertion-sort", "bubble-sort", "shaker-sort", "shell-sort", "heap-sort", "merge-sort", "quick-sort",
"counting-sort", "radix-sort", "flash-sort" };
const char* inputOrder[] = { "-rand", "-nsorted", "-sorted", "-rev" };
const char* outputParameter[] = { "-time", "-comp", "-both" };
const char* mode[] = { "-a", "-c" };

//Get the number of compare of given index of algorithm name
long long getComparisonSortAlgorithm(int idxAlgorithmName, int* arr, int n)
{
	long long count_compare = 0;
	long long count_assign = 0;
	switch (idxAlgorithmName)
	{
	case 0:
		//Selection Sort
		SelectionSortComparison(arr, n, count_assign, count_compare);
		break;
	case 1:
		//Insertion Sort
		InsertionSortComparison(arr, n, count_assign, count_compare);
		break;
	case 2:
		//Bubble Sort
		BubbleSortComparison(arr, n, count_assign, count_compare);
		break;
	case 3:
		//Shaker Sort
		ShakerSortComparison(arr, n, count_assign, count_compare);
		break;
	case 4:
		//Shell Sort
		ShellSortComparison(arr, n, count_assign, count_compare);
		break;
	case 5:
		//Heap Sort
		HeapSortComparison(arr, n, count_assign, count_compare);
		break;
	case 6:
		//Merge Sort
		MergeSortComparison(arr, n, count_assign, count_compare);
		break;
	case 7:
		//Quick Sort
		QuickSortComparison(arr, n, count_assign, count_compare);
		break;
	case 8:
		//Counting Sort
		CountingSortComparison(arr, n, count_assign, count_compare);
		break;
	case 9:
		//Radix Sort
		RadixSortComparison(arr, n, count_assign, count_compare);
		break;
	case 10:
		//Flash Sort
		FlashSortComparison(arr, n, count_assign, count_compare);
		break;
	default:
		break;
	}
	return count_compare;
}
//Get the amount of time of given index of algorithm name
chrono::microseconds getTimeSortAlgorithm(int idxAlgorithmName, int* arr, int n)
{
	chrono::microseconds time;
	switch (idxAlgorithmName)
	{
	case 0:
		SelectionSortTime(arr, n, time);
		break;
	case 1:
		InsertionSortTime(arr, n, time);
		break;
	case 2:
		BubbleSortTime(arr, n, time);
		break;
	case 3:
		ShakerSortTime(arr, n, time);
		break;
	case 4:
		ShellSortTime(arr, n, time);
		break;
	case 5:
		HeapSortTime(arr, n, time);
		break;
	case 6:
		MergeSortTime(arr, n, time);
		break;
	case 7:
		QuickSortTime(arr, n, time);
		break;
	case 8:
		CountingSortTime(arr, n, time);
		break;
	case 9:
		RadixSortTime(arr, n, time);
		break;
	case 10:
		FlashSortTime(arr, n, time);
		break;
	default:
		break;
	}
	return time;
}
//Get name of algorithm with the give index.
string getNameSortAlgorithm(int idxAlgorithmName)
{
	string name = "";
	switch (idxAlgorithmName)
	{
	case 0:
		name = "Selection Sort";
		break;
	case 1:
		name = "Insertion Sort";
		break;
	case 2:
		name = "Bubble Sort";
		break;
	case 3:
		name = "Shaker Sort";
		break;
	case 4:
		name = "Shell Sort";
		break;
	case 5:
		name = "Heap Sort";
		break;
	case 6:
		name = "Merge Sort";
		break;
	case 7:
		name = "Quick Sort";
		break;
	case 8:
		name = "Counting Sort";
		break;
	case 9:
		name = "Radix Sort";
		break;
	case 10:
		name = "Flash Sort";
		break;
	default:
		break;
	}
	return name;
}
//Get the name of input order with the given index.
string getNameInputOrder(int idxInputOrder)
{
	string name = "";
	switch (idxInputOrder)
	{
	case 0:
		name = "Randomized data";
		break;
	case 1:
		name = "Nearly sorted data";
		break;
	case 2:
		name = "Sorted data";
		break;
	case 3:
		name = "Reverse sorted data";
		break;

	default:
		break;
	}
	return name;
}
//Get all index of algorithm in command line 1, 2, 3
void getIndexAlgorithmMode(int argc, char* argv[], int& idxAlgorithmName, int& idxInputOrder, int& idxOutputParameter)
{
	//If it is command line 1 or command line 3
	if (isCommandLine1(argc, argv) || isCommandLine3(argc, argv))
	{
		//Get the index of name.
		for (int i = 0; i < 11; i++)
		{
			if (!strcmp(argv[2], algorithmName[i]))
			{
				idxAlgorithmName = i;
				break;
			}
		}
		//Get the index of output parameter.
		for (int i = 0; i < 3; i++)
		{
			if (!strcmp(argv[4], outputParameter[i]))
			{
				idxOutputParameter = i;
				break;
			}
		}
	}
	//If it is command line 1 or command line 3
	if (isCommandLine2(argc, argv))
	{
		//Get the index of name.
		for (int i = 0; i < 11; i++)
		{
			if (!strcmp(argv[2], algorithmName[i]))
			{
				idxAlgorithmName = i;
				break;
			}
		}
		//Get the index of order.
		for (int i = 0; i < 4; i++)
		{
			if (!strcmp(argv[4], inputOrder[i]))
			{
				idxInputOrder = i;
				break;
			}
		}
		//Get the index of output parameter
		for (int i = 0; i < 3; i++)
		{
			if (!strcmp(argv[5], outputParameter[i]))
			{
				idxOutputParameter = i;
				break;
			}
		}
	}
}
//Get all index of algorithm in command line 4, 5
void getIndexComparisonMode(int argc, char* argv[], int& idxAlgorithmName1, int& idxAlgorithmName2, int& idxInputOrder)
{
	//If it is command line 4
	if (isCommandLine4(argc, argv))
	{
		//Get the index of first name.
		for (int i = 0; i < 11; i++)
		{
			if (!strcmp(argv[2], algorithmName[i]))
			{
				idxAlgorithmName1 = i;
				break;
			}
		}
		//Get the index of second name.
		for (int i = 0; i < 11; i++)
		{
			if (!strcmp(argv[3], algorithmName[i]))
			{
				idxAlgorithmName2 = i;
				break;
			}
		}
	}
	if (isCommandLine5(argc, argv))
	{
		//Get the index of first name.
		for (int i = 0; i < 11; i++)
		{
			if (!strcmp(argv[2], algorithmName[i]))
			{
				idxAlgorithmName1 = i;
				break;
			}
		}
		//Get the index of second name.
		for (int i = 0; i < 11; i++)
		{
			if (!strcmp(argv[3], algorithmName[i]))
			{
				idxAlgorithmName2 = i;
				break;
			}
		}
		//Get the index of parameter order
		for (int i = 0; i < 4; i++)
		{
			if (!strcmp(argv[5], inputOrder[i]))
			{
				idxInputOrder = i;
				break;
			}
		}
	}
}
//Print the output of parameter.
void printOutputParameter(int idxOutputParameter, chrono::microseconds& time, long long& comparison)
{
	switch (idxOutputParameter)
	{
	//If printing only time
	case 0:
		cout << "Running Time: " << (double)time.count() / 1000;
		break;
	//If printing only comparison
	case 1:
		cout << "Comparisons: " << comparison;
		break;
	//If printing both
	case 2:
		cout << "Running Time: " << (double)time.count() / 1000 << endl;
		cout << "Comparisons: " << comparison << endl;
		break;
	default:
		break;
	}
}
//Copy from the value of array1 to array2
void CopyValue(int*& b, int*& a, int size)
{
	b = new int[size];
	for (int i = 0; i < size; i++)
	{
		b[i] = a[i];
	}
}
//Write data into file
void writeFile(string fileName, int* arr, int n)
{
	ofstream out(fileName, ios::out);
	out << n << endl;
	for (int i = 0; i < n; i++)
	{
		out << arr[i] << " ";
	}
	out.close();
}
//Read data from file
void readFile(string fileName, int*& arr, int& N)
{
	ifstream fin(fileName.c_str());
	if (!fin.is_open())
	{
		return;
	}
	fin >> N;
	arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		fin >> arr[i];
	}
	fin.close();
}
//Check whether it is command line 1 or not
bool isCommandLine1(int argc, char* argv[])
{
	if (argc == 5 && strcmp(argv[1], "-a") == 0)
	{
		return true;
	}
	return false;
}
//Implement command line 1 if it is command line 1
void implementCommandLine1(string fileName, int argc, char* argv[])
{
	//Initialize index variable
	int idxAlgorithmName = -1, idxInputOrder = -1, idxOutputParameter = -1;
	//Get all the index.
	getIndexAlgorithmMode(argc, argv, idxAlgorithmName, idxInputOrder, idxOutputParameter);

	int* arr = NULL;
	int inputSize = 0;
	//Read file
	readFile(fileName, arr, inputSize);
	int* arr1_time = NULL;
	int* arr1_compare = NULL;
	//Copy the value from 1 array to other array
	CopyValue(arr1_time, arr, inputSize);
	CopyValue(arr1_compare, arr, inputSize);
	//Get comparison
	long long comparison = getComparisonSortAlgorithm(idxAlgorithmName, arr1_compare, inputSize);
	//Get time
	chrono::microseconds time = getTimeSortAlgorithm(idxAlgorithmName, arr1_time, inputSize);
	
	//Print data on the console
	cout << "Algorithm: " << getNameSortAlgorithm(idxAlgorithmName) << endl;
	cout << "Input file: " << fileName << endl;
	cout << "Input size: " << inputSize << endl;
	cout << "--------------------------------\n";
	printOutputParameter(idxOutputParameter, time, comparison);
	//Write data into file named "output.txt"
	writeFile("output.txt", arr1_compare, inputSize);
	delete[] arr;
}
//Check whether it is command line 2 or not
bool isCommandLine2(int argc, char* argv[])
{
	if (argc == 6 && strcmp(argv[1], "-a") == 0)
	{
		return true;
	}
	return false;
}
void implementCommandLine2(int argc, char* argv[])
{
	//Initialize 
	int idxAlgorithmName = -1;
	int idxInputOrder = -1;
	int idxOutputParameter = -1;
	//Get all the index.
	getIndexAlgorithmMode(argc, argv, idxAlgorithmName, idxInputOrder, idxOutputParameter);

	//Get the size of the array from cmd
	int inputSize = stoi(argv[3]);

	//Generate data
	int* arr = new int[inputSize];
	GenerateData(arr, inputSize, idxInputOrder);
	//Write data into input.txt
	writeFile("input.txt", arr, inputSize);
	int* arr1_time = NULL;
	int* arr1_compare = NULL;
	//Copy value from 1 array to other array
	CopyValue(arr1_time, arr, inputSize);
	CopyValue(arr1_compare, arr, inputSize);
	//Get comparison
	long long comparison = getComparisonSortAlgorithm(idxAlgorithmName, arr1_compare, inputSize);
	//Get time
	chrono::microseconds time = getTimeSortAlgorithm(idxAlgorithmName, arr1_time, inputSize);

	//Print data on console
	cout << "Algorithm: " << getNameSortAlgorithm(idxAlgorithmName) << endl;
	cout << "Input size: " << inputSize << endl;
	cout << "Input order: " << getNameInputOrder(idxInputOrder) << endl;
	cout << "--------------------------------------\n";
	printOutputParameter(idxOutputParameter, time, comparison);
	//Write file into output.txt
	writeFile("output.txt", arr1_compare, inputSize);
	delete[] arr;
}
//Check whether it is command line 3 or not
bool isCommandLine3(int argc, char* argv[])
{
	if (argc == 5 && strcmp(argv[1], "-a") == 0 && isdigit(argv[3][0]))
	{
		return true;
	}
	return false;
}
void implementCommandLine3(int argc, char* argv[])
{
	//Definition 
	int idxAlgorithmName, idxInputOrder, idxOutputParameter;
	//Get all the index.
	getIndexAlgorithmMode(argc, argv, idxAlgorithmName, idxInputOrder, idxOutputParameter);
	//Get name
	string nameAlgorithm = getNameSortAlgorithm(idxAlgorithmName);
	//Get the size of the array from cmd
	int inputSize = stoi(argv[3]);

	//Print data on the console
	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm: " << nameAlgorithm << endl;
	cout << "Input size: " << inputSize << endl << endl;

	for (int i = 0; i < 4; i++)
	{
		//Print data on the console
		cout << "Input order: " << getNameInputOrder(i) << endl;
		cout << "--------------------------------------" << endl;

		//Generate data
		int* arr = new int[inputSize];
		GenerateData(arr, inputSize, i);
		//Create the file contained the generated data
		string fileName = "input_" + to_string(i + 1) + ".txt";
		writeFile(fileName, arr, inputSize);

		//Copy value from 1 array to other array
		int* arr1_compare;
		CopyValue(arr1_compare, arr, inputSize);
		//Get time
		chrono::microseconds time = getTimeSortAlgorithm(idxAlgorithmName, arr, inputSize);
		//Get comparison
		long long count_compare = getComparisonSortAlgorithm(idxAlgorithmName, arr1_compare, inputSize);
		//Print data on the console
		printOutputParameter(idxOutputParameter, time, count_compare);
		cout << endl << endl;
		delete[] arr;
	}
}
//Check whether it is command line 4 or not
bool isCommandLine4(int argc, char* argv[])
{
	if (argc == 5 && strcmp(argv[1], "-c") == 0)
	{
		return true;
	}
	return false;
}
void implementCommandLine4(int argc, char* argv[])
{
	//Definition
	int idxAlgorithmName1, idxAlgorithmName2, idxInputOrder;
	//Get all the index.
	getIndexComparisonMode(argc, argv, idxAlgorithmName1, idxAlgorithmName2, idxInputOrder);
	//Get name
	string nameAlgorithm1 = getNameSortAlgorithm(idxAlgorithmName1);
	string nameAlgorithm2 = getNameSortAlgorithm(idxAlgorithmName2);
	string fileName = argv[4];
	//Definition
	int size;
	int* arr1_time;
	int* arr2_time;
	//Read file
	readFile(fileName, arr1_time, size);
	//Copy from 1 array to other array
	CopyValue(arr2_time, arr1_time, size);

	//Copy from one array to other array
	int* arr1_comp;
	int* arr2_comp;
	CopyValue(arr1_comp, arr1_time, size);
	CopyValue(arr2_comp, arr1_time, size);

	//Print data on the console
	cout << "COMPARE MODE" << endl;
	cout << "Algorithm: " << nameAlgorithm1 << " | " << nameAlgorithm2 << endl;
	cout << "Input file: " << fileName << endl;
	cout << "Input size: " << size << endl;
	cout << "--------------------------------------" << endl;

	//Get time
	chrono::microseconds time1 = getTimeSortAlgorithm(idxAlgorithmName1, arr1_time, size);
	chrono::microseconds time2 = getTimeSortAlgorithm(idxAlgorithmName2, arr2_time, size);

	//Get comparison
	long long count_compare1 = getComparisonSortAlgorithm(idxAlgorithmName1, arr1_comp, size);
	long long count_compare2 = getComparisonSortAlgorithm(idxAlgorithmName2, arr2_comp, size);

	//Print data on the console
	cout << "Running time: " << (double)time1.count() / 1000 << " | " << (double)time2.count() / 1000 << endl;
	cout << "Comparisons: " << count_compare1 << " | " << count_compare2 << endl << endl;
	delete[] arr1_comp;
	delete[] arr2_comp;
	delete[] arr1_time;
	delete[] arr2_time;
}
//Check whether it is command line 5 or not
bool isCommandLine5(int argc, char* argv[])
{
	if (argc == 6 && strcmp(argv[1], "-c") == 0 && isdigit(argv[4][0]))
	{
		return true;
	}
	return false;
}
void implementCommandLine5(int argc, char* argv[])
{
	//Definition
	int idxAlgorithmName1, idxAlgorithmName2, idxInputOrder;
	//Get all index
	getIndexComparisonMode(argc, argv, idxAlgorithmName1, idxAlgorithmName2, idxInputOrder);
	//Get name
	string nameAlgorithm1 = getNameSortAlgorithm(idxAlgorithmName1);
	string nameAlgorithm2 = getNameSortAlgorithm(idxAlgorithmName2);
	//Get the size of array.
	int size = stoi(argv[4]);
	//Get the order of output.
	string inputOrder = getNameInputOrder(idxInputOrder);

	//Print the data on the console
	cout << "COMPARE MODE" << endl;
	cout << "Algorithm: " << nameAlgorithm1 << " | " << nameAlgorithm2 << endl;
	cout << "Input size: " << size << endl;
	cout << "Input order: " << inputOrder << endl;
	cout << "--------------------------------------" << endl;

	//Generate the data.
	int* arr1_time = new int[size];
	GenerateData(arr1_time, size, idxInputOrder);
	//Write data into input.txt
	writeFile("input.txt", arr1_time, size);
	int* arr2_time, * arr1_compare, * arr2_compare;
	//Copy from one array to other array
	CopyValue(arr2_time, arr1_time, size);
	CopyValue(arr1_compare, arr1_time, size);
	CopyValue(arr2_compare, arr1_time, size);

	//Get time
	chrono::microseconds time1 = getTimeSortAlgorithm(idxAlgorithmName1, arr1_time, size);
	chrono::microseconds time2 = getTimeSortAlgorithm(idxAlgorithmName2, arr2_time, size);

	//Get comparison
	long long count_compare1 = getComparisonSortAlgorithm(idxAlgorithmName1, arr1_compare, size);
	long long count_compare2 = getComparisonSortAlgorithm(idxAlgorithmName2, arr2_compare, size);
	
	//Print data on the console.
	cout << "Running time: " << (double)time1.count() / 1000 << " | " << (double)time2.count() / 1000 << endl;
	cout << "Comparisons: " << count_compare1 << " | " << count_compare2 << endl;
	delete[] arr1_time;
	delete[] arr2_time;
	delete[] arr1_compare;
	delete[] arr2_compare;
}
//Implement command line that is selected.
void runCommandLine(int argc, char* argv[])
{
	if (isCommandLine3(argc, argv))
	{
		implementCommandLine3(argc, argv);
	}
	else if (isCommandLine1(argc, argv))
	{
		implementCommandLine1(argv[3], argc, argv);
	}
	else if (isCommandLine2(argc, argv))
	{
		implementCommandLine2(argc, argv);
	}
	else if (isCommandLine4(argc, argv))
	{
		implementCommandLine4(argc, argv);
	}
	else if (isCommandLine5(argc, argv))
	{
		implementCommandLine5(argc, argv);
	}
}
