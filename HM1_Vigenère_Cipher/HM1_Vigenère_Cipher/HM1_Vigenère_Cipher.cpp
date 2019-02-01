#include<iostream>
#include<string>
#include<fstream>
#include<streambuf>
#include <iomanip>
using namespace std;

int main(void)
{
	ifstream fin("Vigenère.txt");

	string input_string((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());

	cout << input_string << endl;

	getchar();
}