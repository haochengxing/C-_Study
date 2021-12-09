#include "pch.h"
#include "A.h"
#include <stdio.h>
#include <random>

extern "C" __declspec(dllexport) int Add(int x, int y)
{
	return x + y;
}

extern "C" __declspec(dllexport) int Sub(int x, int y)
{
	return x - y;
}

extern "C" __declspec(dllexport) int Multiply(int x, int y)
{
	return x * y;
}

extern "C" __declspec(dllexport) int Divide(int x, int y)
{
	return x / y;
}


typedef struct Student
{
	char name[20];
	int age;
	double scores[32];
}Student;

typedef struct Class
{
	int number;
	Student students[126];
}Class;


extern "C" __declspec(dllexport) int GetClass(Class pClass[50])
{
	std::random_device sd;

	for (int i = 0; i < 50; i++)
	{
		pClass[i].number = i;
		for (int j = 0; j < 126; j++)
		{
			memset(pClass[i].students[j].name,0,20);
			sprintf_s(pClass[i].students[j].name,"name_%d_%d",i,j);
			pClass[i].students[j].age = j % 2 == 0 ? 15 : 20;
			for (size_t k = 0; k < 32; k++)
			{
				pClass[i].students[j].scores[k] = sd();
			}
		}
	}

	return 0;
}