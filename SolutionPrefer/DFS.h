#pragma once
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#include <string>
using namespace std;
class DFS
{
	int NDFS = 0;
public:
	int hemming(string s1, string s2)
	{
		if (s1.length() != s2.length()) {
			return -1;
		}
		int counthemm = 0;
		int size = s1.length();
		for (int i = 0; i < size; i++) {
			if (s1[i] != s2[i])
				counthemm += 1;
		}
		return counthemm;
	}
	string Binarycoding(int i)
	{
		string str;
		int k = 0;
		while (i > 0) {
			int k = i % 2;
			str += to_string(k);
			i = i / 2;
			k++;
		}
		reverse(str.begin(), str.end());
		while (str.size() != 15) {
			str = "0" + str;
		}
		return str;
	}
	int strToInt(string s) {
		int a;
		a = atoi(s.c_str());
		return a;
	}
	int TransBinToDeca(int q) {
		int num = 0;
		int i = 0;
		int a = 0;
		while (q > 0) {
			a = q % 10;
			num += a * pow(2, i);
			i += 1;
			q /= 10;
		}
		return num;
	}
	void DFSCalculating(int* landscape, string* BinaryCodeDBFS, int N)
	{
		srand(time(NULL));
		int CountNumberNeighbour = 0;
		int FirstCell = 0;
		int max = 0;
		int CurrentCell = 0;
		int Cell = 0;
		string maxCell;
		int suitability[20] = { 0 };
		int l = 0;
		int* p;
		string* c;
		c = new string[32768];
		p = new int[32768];
		for (int j = 0; j < 20;j++)
		{
			suitability[j] = landscape[j];
			std::cout << "cell [" << j << "]= " << suitability[j] << "\n";

		}
		FirstCell = rand() % 20;
		std::cout << "The first random element is [" << FirstCell << "]= " << landscape[FirstCell] << endl;
		maxCell = BinaryCodeDBFS[FirstCell];
		max = suitability[FirstCell];
		Cell = TransBinToDeca(strToInt(maxCell));
		for (int i = 0; i < N;i++)
		{
			l = 0;
			for (int j = 0; j < 20; j++)
			{
				if (hemming(maxCell, BinaryCodeDBFS[j]) == 1) {
					p[l] = suitability[j];
					c[l] = BinaryCodeDBFS[j];
					l++;
				}		
			}
			std::cout << "the current best result is: [" << Cell <<"] "<<max<<" bincode: "<<maxCell<<"\n";
		}
	}
};

