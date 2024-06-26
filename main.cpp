#include"CommandLine.h"
#include"SortAlgorithm.h"
int main()
{
	char **argv = new char* [50];
	for (int i = 0; i < 50; i++)
	{
		argv[i] = new char[50];
	}
	int argc = 6;
	for (int i = 0; i < argc; i++)
	{
		cin >> argv[i];
	}
	runCommandLine(argc, argv);
	for (int i = 0; i < 50; i++)
	{
		delete[] argv[i];
	}
	delete[] argv;
}