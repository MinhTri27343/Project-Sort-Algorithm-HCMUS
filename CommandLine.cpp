#include"CommandLine.h"
const char *algorithmName[] = { "selection-sort", "insertion-sort", "bubble-sort", "shaker-sort", "shell-sort", "heap-sort", "merge-sort", "quick-sort",
"counting-sort", "radix-sort", "flash-sort" };
const char* inputOrder[] = {"-rand", "-nsorted", "-sorted", "-rev"};
const char* outputParameter[] = { "-time", "-comp", "-both" };
const char* mode[] = { "-a", "-c" };
// Function dùng chung 
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
		name = "Sorted data";
		break;
	case 1: 
		name = "Nearly sorted data";
		break;
	case 2: 
		name = "Reverse sorted data";
		break;
	case 3:
		name = "Randomized data";
		break;
	default: 
		break;
	}
	return name;
}

// Dung de in format cua output parameter
void printOutputParameter(int idxOutputParameter, chrono::milliseconds time, long long comparision)
{
	switch (idxOutputParameter)
	{
	case 0: 
		cout << "Running Time: " << time.count();
		break;
	case 1: 
		cout << "Comparision: " << comparision;
		break;
	case 2: 
		cout << "Running Time: " << time.count() << endl;
		cout << "Comparision: " << comparision << endl;
		break;
	default: 
		break;
	}
}

// Tự build 
bool isCommandLine1(int argc, char* argv[], int& idxAlgorithmName, int &idxInputOrder, int& idxOutputParameter, int &idxMode)
{
	idxMode = -1;
	idxAlgorithmName = -1;
	idxInputOrder = -1;
	idxOutputParameter = -1;
	if (argc == 5 && strcmp(argv[1], "-a") == 0)
	{
		int sizeAlgorithmName = 11;
		int sizeOutputOrder = 3;
		for (int i = 0; i < sizeOutputOrder; i++)
		{
			if (strcmp(inputOrder[i], argv[4]) == 0)
			{
				for (int j = 0; j < sizeAlgorithmName; j++)
				{
					if (strcmp(algorithmName[j], argv[2]) == 0)
					{
						ifstream in(argv[3]);
						if (in)
						{
							idxAlgorithmName = i;
							idxOutputParameter = j;
							idxMode = 0;
							in.close();
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

void implementCommandLine1(int& idxAlgorithmName, int& idxInputOrder, int& idxOutputParameter, int& idxMode, string fileName)
{
	ifstream in;
	in.open(fileName);
	if (!in) return;

	in.close();
}
bool isCommandLine2(int argc, char* argv[])
{
	return false;
}
bool isCommandLine3(int argc, char* argv[])
{
	return false;
}
bool isCommandLine4(int argc, char* argv[])
{
	return false;
}
bool isCommandLine5(int argc, char* argv[])
{
	return false;
}
