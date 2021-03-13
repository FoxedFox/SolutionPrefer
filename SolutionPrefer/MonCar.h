#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<ctime>
class MonCar
{
private:
	int NMC;
public:
	void  MonteCarloCalculate(int *landscape, int N)
	{
		srand(time(NULL));
		int max = 0;
		int MaxCell = 0;
		for (int i = 0; i < N; i++)
		{
			std::cout <<"\n" << i + 1 << "-step. At now max is ["<<MaxCell<<"] = " << max <<"\n";
			int RandomChoose = rand() % 20;
			std::cout << "Picked cell is[" << RandomChoose << "] ";
			std::cout << landscape[RandomChoose]<<"\n" ;
			if (max < landscape[RandomChoose]) {
				max = landscape[RandomChoose];
				MaxCell = RandomChoose;
				std::cout << "Chossed s[" << RandomChoose << "].";
				std::cout << "  Changing max = " << max<<"\n";
				NMC = i + 1;
			}
			
		}
		std::cout << "The best solution is: [" << MaxCell <<"] = "<< max <<" on step "<<NMC <<"\n";
	}
};