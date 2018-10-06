// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 3 - Problem 2
// Program: CS213-2018-A1-T3-P2
// Purpose: Print English words that end with the letters "dous"
// Author1: Mostafa Omar Mahmoud - 20170292
// Date:    4 September 2018
// Version: 1.0

#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	string s;
	string dous = "dous";
	while(in >> s)
	{
		bool ok = (s.size() >= 4);
		for (int i = (int)s.size() - 1, j = 3; j >= 0 && i >= 0; --i, --j)
		{
			if (s[i] != dous[j])
			{
				ok = false;
				break;
			}
		}
		if (ok)
		{
			out << s << '\n';
		}
	}

}
