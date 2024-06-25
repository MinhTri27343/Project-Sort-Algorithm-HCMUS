#include"SortAlgorithm.h"
bool isCommandLine1(int argc, char* argv[]);
bool isCommandLine2(int argc, char* argv[]);
bool isCommandLine3(int argc, char* argv[]);
bool isCommandLine4(int argc, char* argv[]);
bool isCommandLine5(int argc, char* argv[]);
void getIndexAlgorithmMode(int argc, char* argv[], int& idxAlgorithmName, int& idxInputOrder, int& idxOutputParameter);
void getIndexComparisonMode(int argc, char* argv[], int& idxAlgorithmName1, int& idxAlgorithmName2, int& idxInputOrder);
void GenerateData(int a[], int n, int dataType);
void runCommandLine(int argc, char* argv[]);
