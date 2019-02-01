#include<iostream>
#include<string>
#include<fstream>
#include<streambuf>
using namespace std;

int main(void)
{
	ifstream fin("HM1_AC.txt");

	int size;

	//read text file into a string
	string input_string((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());

	cout << input_string << endl;

	getchar();
}