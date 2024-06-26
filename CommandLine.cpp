#include"CommandLine.h"
#include<iomanip>
const char* algorithmName[] = { "selection-sort", "insertion-sort", "bubble-sort", "shaker-sort", "shell-sort", "heap-sort", "merge-sort", "quick-sort",
"counting-sort", "radix-sort", "flash-sort" };
const char* inputOrder[] = { "-rand", "-nsorted", "-sorted", "-rev" };
const char* outputParameter[] = { "-time", "-comp", "-both" };
const char* mode[] = { "-a", "-c" };
long long getComparisonSortAlgorithm(int idxAlgorithmName, int* arr, int n)
{
	long long count_compare = 0;
	long long count_assign = 0;
	switch (idxAlgorithmName)
	{
	case 0:
		SelectionSortComparison(arr, n, count_assign, count_compare);
		break;
	case 1:
		InsertionSortComparison(arr, n, count_assign, count_compare);
		break;
	case 2:
		BubbleSortComparison(arr, n, count_assign, count_compare);
		break;
	case 3:
		ShakerSortComparison(arr, n, count_assign, count_compare);
		break;
	case 4:
		ShellSortComparison(arr, n, count_assign, count_compare);
		break;
	case 5:
		HeapSortComparison(arr, n, count_assign, count_compare);
		break;
	case 6:
		MergeSortComparison(arr, n, count_assign, count_compare);
		break;
	case 7:
		QuickSortComparison(arr, n, count_assign, count_compare);
		break;
	case 8:
		CountingSortComparison(arr, n, count_assign, count_compare);
		break;
	case 9:
		RadixSortComparison(arr, n, count_assign, count_compare);
		break;
	case 10:
		FlashSortComparison(arr, n, count_assign, count_compare);
		break;

	default:
		break;
	}
	return count_compare;
}
chrono::milliseconds getTimeSortAlgorithm(int idxAlgorithmName, int* arr, int n)
{
	chrono::milliseconds time;
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
void getIndexAlgorithmMode(int argc, char* argv[], int& idxAlgorithmName, int& idxInputOrder, int& idxOutputParameter)
{
	if (isCommandLine1(argc, argv) || isCommandLine3(argc, argv))
	{
		//Algorithm Name
		for (int i = 0; i < 11; i++)
		{
			if (!strcmp(argv[2], algorithmName[i]))
			{
				idxAlgorithmName = i;
				break;
			}
		}
		//Output Parameter
		for (int i = 0; i < 3; i++)
		{
			if (!strcmp(argv[4], outputParameter[i]))
			{
				idxOutputParameter = i;
				break;
			}
		}
	}
	if (isCommandLine2(argc, argv))
	{
		//Algorithm Name
		for (int i = 0; i < 11; i++)
		{
			if (!strcmp(argv[2], algorithmName[i]))
			{
				idxAlgorithmName = i;
				break;
			}
		}
		//Order
		for (int i = 0; i < 4; i++)
		{
			if (!strcmp(argv[4], inputOrder[i]))
			{
				idxInputOrder = i;
				break;
			}
		}
		//Output parameter
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
void getIndexComparisonMode(int argc, char* argv[], int& idxAlgorithmName1, int& idxAlgorithmName2, int& idxInputOrder)
{
	if (isCommandLine4(argc, argv))
	{
		//Algorithm Name 1
		for (int i = 0; i < 11; i++)
		{
			if (!strcmp(argv[2], algorithmName[i]))
			{
				idxAlgorithmName1 = i;
				break;
			}
		}
		//Algorithm Name 2
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
		//Algorithm Name 1
		for (int i = 0; i < 11; i++)
		{
			if (!strcmp(argv[2], algorithmName[i]))
			{
				idxAlgorithmName1 = i;
				break;
			}
		}
		//Algorithm Name 2
		for (int i = 0; i < 11; i++)
		{
			if (!strcmp(argv[3], algorithmName[i]))
			{
				idxAlgorithmName2 = i;
				break;
			}
		}
		//Parameter Order
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
void printOutputParameter(int idxOutputParameter, chrono::milliseconds& time, long long& comparision)
{
	switch (idxOutputParameter)
	{
	case 0:
		cout << "Running Time: " << time.count();
		break;
	case 1:
		cout << "Comparisions: " << comparision;
		break;
	case 2:
		cout << "Running Time: " << time.count() << endl;
		cout << "Comparisions: " << comparision << endl;
		break;
	default:
		break;
	}
}
void CopyValue(int*& b, int*& a, int size)
{
	b = new int[size];
	for (int i = 0; i < size; i++)
	{
		b[i] = a[i];
	}
}
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
bool isCommandLine1(int argc, char* argv[])
{
	if (argc == 5 && strcmp(argv[1], "-a") == 0)
	{
		return true;
	}
	return false;
}
void implementCommandLine1(string fileName, int argc, char* argv[])
{
	int idxAlgorithmName = -1, idxInputOrder = -1, idxOutputParameter = -1;
	getIndexAlgorithmMode(argc, argv, idxAlgorithmName, idxInputOrder, idxOutputParameter);

	int* arr = NULL;
	int inputSize = 0;
	readFile(fileName, arr, inputSize);
	long long comparison = getComparisonSortAlgorithm(idxAlgorithmName, arr, inputSize);
	chrono::milliseconds time = getTimeSortAlgorithm(idxAlgorithmName, arr, inputSize);


	cout << "Algorithm: " << getNameSortAlgorithm(idxAlgorithmName) << endl;
	cout << "Input file: " << fileName << endl;
	cout << "Input size: " << inputSize << endl;
	cout << "--------------------------------\n";
	printOutputParameter(idxOutputParameter, time, comparison);
	writeFile("output.txt", arr, inputSize);
	delete[] arr;
}
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
	int idxAlgorithmName = -1;
	int idxInputOrder = -1;
	int idxOutputParameter = -1;
	getIndexAlgorithmMode(argc, argv, idxAlgorithmName, idxInputOrder, idxOutputParameter);

	int sizeAlgorithmName = 11;
	int sizeOutputParameter = 3;
	int inputSize = stoi(argv[3]);

	int* arr = new int[inputSize];
	GenerateData(arr, inputSize, idxInputOrder);
	writeFile("input.txt", arr, inputSize);
	long long comparison = getComparisonSortAlgorithm(idxAlgorithmName, arr, inputSize);
	chrono::milliseconds time = getTimeSortAlgorithm(idxAlgorithmName, arr, inputSize);

	cout << "Algorithm: " << getNameSortAlgorithm(idxAlgorithmName) << endl;
	cout << "Input size: " << inputSize << endl;
	cout << "Input order: " << getNameInputOrder(idxInputOrder) << endl;
	cout << "--------------------------------------\n";
	printOutputParameter(idxOutputParameter, time, comparison);
	writeFile("output.txt", arr, inputSize);
	delete[] arr;
}
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
	int idxAlgorithmName, idxInputOrder, idxOutputParameter;
	getIndexAlgorithmMode(argc, argv, idxAlgorithmName, idxInputOrder, idxOutputParameter);
	string nameAlgorithm = getNameSortAlgorithm(idxAlgorithmName);
	int inputSize = stoi(argv[3]);

	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm: " << nameAlgorithm << endl;
	cout << "Input size: " << inputSize << endl << endl;

	for (int i = 0; i < 4; i++)
	{
		cout << "Input order: " << getNameInputOrder(i) << endl;
		cout << "--------------------------------------" << endl;

		int* arr = new int[inputSize];
		GenerateData(arr, inputSize, i);
		string fileName = "input_" + to_string(i + 1) + ".txt";
		writeFile(fileName, arr, inputSize);

		chrono::milliseconds time;
		long long count_compare = getComparisonSortAlgorithm(idxAlgorithmName, arr, inputSize);
		printOutputParameter(idxOutputParameter, time, count_compare);
		cout << endl << endl;
		delete[] arr;
	}
}
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
	int idxAlgorithmName1, idxAlgorithmName2, idxInputOrder;
	getIndexComparisonMode(argc, argv, idxAlgorithmName1, idxAlgorithmName2, idxInputOrder);
	string nameAlgorithm1 = getNameSortAlgorithm(idxAlgorithmName1);
	string nameAlgorithm2 = getNameSortAlgorithm(idxAlgorithmName2);
	string fileName = argv[4];

	int size;
	int* arr1_time;
	int* arr2_time;
	readFile(fileName, arr1_time, size);
	CopyValue(arr2_time, arr1_time, size);

	int* arr1_comp;
	int* arr2_comp;
	CopyValue(arr1_comp, arr1_time, size);
	CopyValue(arr2_comp, arr1_time, size);

	cout << "COMPARE MODE" << endl;
	cout << "Algorithm: " << nameAlgorithm1 << " | " << nameAlgorithm2 << endl;
	cout << "Input file: " << fileName << endl;
	cout << "Input size: " << size << endl;
	cout << "--------------------------------------" << endl;

	chrono::milliseconds time1 = getTimeSortAlgorithm(idxAlgorithmName1, arr1_time, size);
	chrono::milliseconds time2 = getTimeSortAlgorithm(idxAlgorithmName2, arr2_time, size);

	long long count_compare1 = getComparisonSortAlgorithm(idxAlgorithmName1, arr1_comp, size);
	long long count_compare2 = getComparisonSortAlgorithm(idxAlgorithmName2, arr2_comp, size);

	cout << "Running time: " << time1.count() << " | " << time2.count() << endl;
	cout << "Comparisons: " << count_compare1 << " | " << count_compare2 << endl << endl;
	delete[] arr1_comp;
	delete[] arr2_comp;
	delete[] arr1_time;
	delete[] arr2_time;
}
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
	int idxAlgorithmName1, idxAlgorithmName2, idxInputOrder;
	getIndexComparisonMode(argc, argv, idxAlgorithmName1, idxAlgorithmName2, idxInputOrder);
	string nameAlgorithm1 = getNameSortAlgorithm(idxAlgorithmName1);
	string nameAlgorithm2 = getNameSortAlgorithm(idxAlgorithmName2);
	int size = stoi(argv[4]);
	string inputOrder = getNameInputOrder(idxInputOrder);

	cout << "COMPARE MODE" << endl;
	cout << "Algorithm: " << nameAlgorithm1 << " | " << nameAlgorithm2 << endl;
	cout << "Input size: " << size << endl;
	cout << "Input order: " << inputOrder << endl;
	cout << "--------------------------------------" << endl;
	
	int* arr1_time = new int[size];
	GenerateData(arr1_time, size, idxInputOrder);
	writeFile("input.txt", arr1_time, size);
	int* arr2_time, * arr1_compare, * arr2_compare;
	CopyValue(arr2_time, arr1_time, size);
	CopyValue(arr1_compare, arr1_time, size);
	CopyValue(arr2_compare, arr1_time, size);

	chrono::milliseconds time1 = getTimeSortAlgorithm(idxAlgorithmName1, arr1_time, size);
	chrono::milliseconds time2 = getTimeSortAlgorithm(idxAlgorithmName2, arr2_time, size);

	long long count_compare1 = getComparisonSortAlgorithm(idxAlgorithmName1, arr1_compare, size);
	long long count_compare2 = getComparisonSortAlgorithm(idxAlgorithmName2, arr2_compare, size);

	cout << "Running time: " << time1.count() << " | " << time2.count() << endl;
	cout << "Comparisons: " << count_compare1 << " | " << count_compare2 << endl;
	delete[] arr1_time;
	delete[] arr2_time;
	delete[] arr1_compare;
	delete[] arr2_compare;
}
void runCommandLine(int argc, char* argv[])
{
	if (isCommandLine1(argc, argv))
	{
		implementCommandLine1(argv[3], argc, argv);
	}
	if (isCommandLine2(argc, argv))
	{
		implementCommandLine2(argc, argv);
	}
	if (isCommandLine3(argc, argv))
	{
		implementCommandLine3(argc, argv);
	}
	if (isCommandLine4(argc, argv))
	{
		implementCommandLine4(argc, argv);
	}
	if (isCommandLine5(argc, argv))
	{
		implementCommandLine5(argc, argv);
	}
}
