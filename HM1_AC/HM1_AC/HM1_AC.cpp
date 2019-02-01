#include<iostream>
#include<string>
#include<fstream>
#include<streambuf>
using namespace std;

void Input_String_Length(string input_string, int &input_string_length);
void Alphabet(string letters[]);

int main(void)
{
	ifstream fin("HM1_AC.txt");

	int input_string_length = 0;
	string letters[26];
	//read text file into a string
	string input_string((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());

	Alphabet(letters);


	//determines text file string length
	Input_String_Length(input_string, input_string_length);

	cout << input_string << endl;

	getchar();
}

void Input_String_Length(string input_string, int &input_string_length)
{
	/*determines the length of the input string*/
	
	input_string_length = input_string.length();
}

void Alphabet(string letters[])
{
	letters[0] = "a";
	letters[1] = "b";
	letters[2] = "c";
	letters[3] = "d";
	letters[4] = "e";
	letters[5] = "f";
	letters[6] = "g";
	letters[7] = "h";
	letters[8] = "i";
	letters[9] = "j";
	letters[10] = "k";
	letters[11] = "l";
	letters[12] = "m";
	letters[13] = "n";
	letters[14] = "o";
	letters[15] = "p";
	letters[16] = "q";
	letters[17] = "r";
	letters[18] = "s";
	letters[19] = "t";
	letters[20] = "u";
	letters[21] = "v";
	letters[22] = "w";
	letters[23] = "x";
	letters[24] = "y";
	letters[25] = "z";
}
