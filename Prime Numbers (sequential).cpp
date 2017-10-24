// Prime Numbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<omp.h>
#include<iostream>
#include<time.h>
#define Peak 500000
double Prime_Counter = 0;
bool IsPrime = true;

using namespace std;
int main()
{
	double t1 = omp_get_wtime();
	cout << "working" << endl;
	for (int Number = 2; Number < Peak ; Number++)
	{
		IsPrime = true;
		//cout << Number << "first loop" << endl;
		for (int denominator = (Number-1); denominator >= 2; denominator--)
		{
			//cout << denominator << "second loop" << endl;
			if ((Number%denominator) == 0)
			{
				IsPrime = false;
				break;
			}
			if (IsPrime == false) break;
		}
		if (IsPrime) {
			cout << Number << endl; Prime_Counter++;
		}
		
	}
	double t2 = omp_get_wtime();
	cout << Prime_Counter << " prime numbers" << endl;
	cout << t2 - t1 << "seconds"<<endl;
    return 0;
}

