#include"CommandLine.h"
const char* algorithmName[] = { "selection-sort", "insertion-sort", "bubble-sort", "shaker-sort", "shell-sort", "heap-sort", "merge-sort", "quick-sort",
"counting-sort", "radix-sort", "flash-sort" };
const char* inputOrder[] = { "-rand", "-nsorted", "-sorted", "-rev" };
const char* outputParameter[] = { "-time", "-comp", "-both" };
const char* mode[] = { "-a", "-c" };
int getComparisionSortAlgorithm(int idxAlgorithmName, int *arr, int n)
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
		ShakerSortTime(arr, n, time);
		break;
	case 5:
		ShellSortTime(arr, n, time);
		break;
	case 6:
		HeapSortTime(arr, n, time);
		break;
	case 7:
		MergeSortTime(arr, n, time);
		break;
	case 8:
		QuickSortTime(arr, n, time);
		break;
	case 9:
		CountingSortTime(arr, n, time);
		break;
	case 10:
		RadixSortTime(arr, n, time);
		break;
	case 11:
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
	default :
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
		idxAlgorithmName2 = idxAlgorithmName1 + 1;
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
		idxAlgorithmName2 = idxAlgorithmName1 + 1;
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
bool isCommandLine1(int argc, char* argv[])
{
	if (argc == 5 && strcmp(argv[1], "-a") == 0)
	{
		return true;
	}
	return false;
}

void printOutputParameter(int idxOutputParameter, chrono::milliseconds time, long long comparison)
{
	switch (idxOutputParameter)
	{
	case 0: 
		cout << "Running Time: " << time.count();
		break;
	case 1: 
		cout << "Comparision: " << comparison;
		break;
	case 2: 
		cout << "Running Time: " << time.count() << endl;
		cout << "Comparision: " << comparison << endl;
		break;
	default: 
		break;
	}
}

void implementCommandLine1(string fileName, int argc, char* argv[])
{
	int idxAlgorithmName = 0, idxInputOrder = 0, idxOutputParameter = 0;
	getIndexAlgorithmMode(argc, argv, idxAlgorithmName, idxInputOrder, idxOutputParameter);
	ifstream in;
	in.open(fileName);
	if (!in) return;
	int inputSize = 0;
	in >> inputSize;
	int* arr = new int[inputSize];
	for (int i = 0; i < inputSize; i++)
	{
		in >> arr[i];
	}
	long long comparison = getComparisionSortAlgorithm(idxAlgorithmName, arr, inputSize);
	chrono::milliseconds time = getTimeSortAlgorithm(idxAlgorithmName, arr, inputSize);
	cout << "Algorithm: " << getNameSortAlgorithm(idxAlgorithmName) << endl;
	cout << "Input file: " << fileName << endl;
	cout << "--------------------------------\n";
	printOutputParameter(idxOutputParameter, time, comparison);
	delete[] arr;
	in.close();
}
void writeFile(string fileName, int* arr, int n)
{
	ofstream out(fileName, ios::out);
	out << n;
	for (int i = 0; i < n; i++)
	{
		out << arr[i];
	}
	out.close();
}
bool isCommandLine2(int argc, char* argv[])
{
	if (argc == 6 && !strcmp(argv[1], "-a"))
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
	long long comparision = getComparisionSortAlgorithm(idxAlgorithmName, arr, inputSize);
	chrono::milliseconds time = getTimeSortAlgorithm(idxAlgorithmName, arr, inputSize);
	cout << "Algorithm: " << getNameSortAlgorithm(idxAlgorithmName) << endl;
	cout << "Input size: " << inputSize << endl;
	cout << "Input order: " << getNameInputOrder(idxInputOrder) << endl;
	cout << "------------------------------------\n";
	printOutputParameter(idxOutputParameter, time, comparision);
	writeFile("output.txt", arr, inputSize);
	delete[] arr;
}
bool isCommandLine3(int argc, char* argv[])
{
	if (argc == 5 && argv[1] == "-a" && isdigit(argv[3][0]))
	{
		return true;
	}
	return false;
}
void implementCommandLine3()
{

}
bool isCommandLine4(int argc, char* argv[])
{
	if (argc == 5 && argv[1] == "-c")
	{
		return true;
	}
	return false;
}
void implementCommandLine4()
{

}
bool isCommandLine5(int argc, char* argv[])
{
	return false;
}
void implementCommandLine5()
{

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

	}
	if (isCommandLine4(argc, argv))
	{

	}
	if (isCommandLine5(argc, argv))
	{

	}
}