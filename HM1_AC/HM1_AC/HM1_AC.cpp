#include<iostream>
#include<string>
#include<fstream>
#include<streambuf>
using namespace std;

void Input_String_Length(string input_string, int &input_string_length);

int main(void)
{
	ifstream fin("HM1_AC.txt");

	int input_string_length = 0;

	//read text file into a string
	string input_string((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());

	cout << input_string << endl;

	getchar();
}

void Input_String_Length(string input_string, int &input_string_length)
{
	/*determines the length of the input string*/
	
	input_string_length = input_string.length();
}