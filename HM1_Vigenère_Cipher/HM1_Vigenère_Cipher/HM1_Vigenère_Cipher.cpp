#include<iostream>
#include<string>
#include<fstream>
#include<streambuf>
#include <iomanip>
using namespace std;

void Input_String_Length(string input_string, int &input_string_length);
void Alphabet(string letters[]);
void Comparison_Test(int input_string_length, string input_string, int comparison_counter, string letters[]);

int main(void)
{
	ifstream fin("Vigenère.txt");
	string input_string((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
	int input_string_length = 0, letter_count[26] = { 0 }, comparison_counter = 0;
	string letters[26];

	//initialize the alphabet
	Alphabet(letters);

	//calculate the length of the string
	Input_String_Length(input_string, input_string_length);

	//identifies matches in the shifted string vs. base string
	Comparison_Test(input_string_length, input_string, comparison_counter, letters);

	getchar();
}

void Input_String_Length(string input_string, int &input_string_length)
{
	/*determines the length of the input string*/

	input_string_length = input_string.length();
}

void Comparison_Test(int input_string_length, string input_string, int comparison_counter, string letters[])
{
	/*identify the number of 'overlaps' in the 'base' string with 
	the shifted version*/
	
	string base_input_string = "", comparison_input_string = "";
	int counter = 1;
	
	while (counter < input_string_length)
	{
		for (int i = 0; i < input_string_length && ((i + counter) < input_string_length); i++)
		{
			//set 1 char eqaul to each variable for comparision purposes
			base_input_string = input_string[i + counter];
			comparison_input_string = input_string[i];

			if (base_input_string == comparison_input_string)
			{
				for (int i = 0; i < 26; i++)
				{
					if (base_input_string == letters[i])
					{
						comparison_counter++;
					}
				}
			}
		}

		cout << counter << ":" << comparison_counter << endl;

		comparison_counter = 0;
		counter++;
	}
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