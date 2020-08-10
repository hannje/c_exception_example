// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <windows.h>

#include <string>
#include <excpt.h>


#define DIM1 1000
#define DIM2 1000
#include <chrono> 
using namespace std::chrono;

using namespace std;




class RuntimeException {
private:
	string errorMsg;
public:
	RuntimeException(const string& err) { errorMsg = err; }
	string getMessage() const { return errorMsg; }
};

class StackEmpty : public RuntimeException {
public:
	StackEmpty(const string& err) : RuntimeException(err) {}
};

int filter(unsigned int code, struct _EXCEPTION_POINTERS *ep)
{
	puts("in filter.");

	printf(" code = %X  \n", code);

	if (code == EXCEPTION_ACCESS_VIOLATION)
	{
		puts("caught AV as expected.");
		return EXCEPTION_EXECUTE_HANDLER;
	}
	else
	{
		puts("didn't catch AV, unexpected.");
		return EXCEPTION_CONTINUE_SEARCH;
	};
}


int main()
{


	DWORD   pri = THREAD_PRIORITY_HIGHEST;

//	if (!SetPriorityClass(GetCurrentProcess(), pri))
//	{
//		DWORD dwError = GetLastError();
//		if (ERROR_PROCESS_MODE_ALREADY_BACKGROUND == dwError)
//		{
//
//		}
//		else
//		{
//
//		}
//	}

	auto start = high_resolution_clock::now();

	__try
	{

	int core = 12;
//	SetThreadAffinityMask(GetCurrentThread(), (1 << core) - 1);

	int iSecret, iGuess;

	/* initialize random seed: */
	srand(time(NULL));

	/* generate secret number between 1 and 10: */
	iSecret = rand() % 10 + 1;



		int t = 0;
		int g = 100;
//		int f = g / t;

		int randi[DIM1][DIM2];

		for (int y = 0; y < 2000; y++)
		{
			//		std::cout << y << std::endl;
			for (int i = 0; i < DIM1; i++)
			{
				for (int j = 0; j < DIM2; j++)
				{
					randi[i][j] = rand() % 100 + 1;
				}
//				Sleep(1);

			}
			if ((y % 100) == 0)
			{
				char buf[10];
				itoa(y, buf, 10);
				std::cout << " " << y;
			}
		}

	}
//	__except (const std::runtime_error& e)
//	{
//		std::cout << "Exception caught\n";
//		std::cout << e.what();
//	}
//	__except (const std::overflow_error& e)
//	{
//		std::cout << "Exception caught\n";
//		std::cout << e.what();
//	}

	__except (filter(GetExceptionCode(), GetExceptionInformation()))
	{
		std::cout << "Exception!\n";

	}
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);

	// To get the value of duration use the count() 
	// member function on the duration object 
	std::cout << duration.count() << std::endl;

    std::cout << "priority:" << pri; 





}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
