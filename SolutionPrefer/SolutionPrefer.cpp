#include <iostream>
#include<ctime>
#include<string>
#include<algorithm>
#include<cmath>
#include <windows.h>
#include <cstring>
#include "MonCar.h"
#include <string>
#include "DFS.h"
using namespace std;
string InputChoise, BinaryCodeDBFS[32768];
int i,k, N=0;
int InputVariant, SwitchAlgorithm= 0;
int landscape[32768];
string DoBinaryCodeDBFS(int i) {
	string str;
	int BinaryParts = 0;
	while (i > 0) {
		BinaryParts = i % 2;
		str += to_string(BinaryParts);
		i = i / 2;
		BinaryParts++;
	}
	reverse(str.begin(), str.end());
	while (str.size() != 15) {
		str = "0" + str;
	}
	return str;

}
int main()
{
	DFS DFS;
	MonCar MonCar;

	srand(time(NULL));
	std::cout << "Hello, this is a program that implements evolutionary genetic algorithms\n";
	while (i==0)
	{
		std::cout << "And and what will we optimize now?\n";
		std::cout << "1. Random(32768 elements max & <100000)\n2.Input on keyboard\n3.Input from file\n";
		std::cin >>InputChoise;
		if (InputChoise == "1" ||  InputChoise == "2"|| InputChoise == "3")
		{
			std::cout << "Your choise is: ";
			if (InputChoise == "1") {
				std::cout << "Random\n";
				i = 1;
			}
			else if (InputChoise == "2") {
				std::cout << "Input on keyboard\n";
				i = 1;
			}
			else if (InputChoise == "3") {
				std::cout << "input from file\n";
				i = 1;
			}
		}
		else
		{
			std::cout << "Not available answer\n";
			i = 0;
		}
	}	
	InputVariant = atoi(InputChoise.c_str());
	if (InputVariant == 1)
	{
		for (int j = 0; j < 20;j++)
		{
			int randomvalue = rand() % 32768;
			landscape[j] = randomvalue;
			std::cout << "Cell [" << j << "] = " << landscape[j] << endl;
		}
	}
	std::cout << "1) Monte-Carlo algorythm\n2)DFS algorythm\n3)BFS algorythm\n";
    std::cout << "Choose algorithm: ";
	std::cin >> SwitchAlgorithm;
	std::cout << "How many steps? ";
	std::cin >> N;
	switch (SwitchAlgorithm)
	{
	case 1:
		MonCar.MonteCarloCalculate(landscape, N);
		break;
	case 2:		
		for (int j = 0; j < 20;j++)
		{
          BinaryCodeDBFS[j] = DoBinaryCodeDBFS(j);
		}
		DFS.DFSCalculating(landscape, BinaryCodeDBFS, N);
		break;
	default:
		std::cout << "wait what?";
		break;
		
	}
	
	

	
}