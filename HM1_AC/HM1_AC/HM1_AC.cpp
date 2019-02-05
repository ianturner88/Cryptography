#include<iostream>
#include<string>
#include<fstream>
#include<streambuf>
#include <iomanip>
using namespace std;

void Input_String_Length(string input_string, int &input_string_length);
void Alphabet(string letters[]);
void Letter_Counter(string input_string, string letters[], int &input_string_length, float letter_count[]);
void Display_Instances_of_Letter(float letter_count[], int input_string_length, string letters[]);
void Identify_Char_to_Decode(string input_string, string &replacement, int index_counter);
void Identify_Replacement_Alphabet_Numerical_Value(string replacement, int &letter_numerical_value, string letters[]);
void Affine_Cipher_Equation(int &letter_numerical_value, string letters[], int &affine_cipher);
void Output_Answer(int affine_cipher, string letters[]);

int main(void)
{
	ifstream fin("HM1_AC.txt");

	int input_string_length = 0, index_counter = 0, letter_numerical_value = 0, affine_cipher = 0;
	float letter_count[26] = { 0 };
	string letters[26], switch_letters[26], replacement = "";
	//read text file into a string
	string input_string((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());

	Alphabet(letters);

	//determines text file string length
	Input_String_Length(input_string, input_string_length);
	//indentify the number of times a given letter appears in the text
	Letter_Counter(input_string, letters, input_string_length, letter_count);
	//calculate the number of times a letter occurrs
	Display_Instances_of_Letter(letter_count, input_string_length, letters);

	while (index_counter < input_string.length())
	{
		Identify_Char_to_Decode(input_string, replacement, index_counter);
		Identify_Replacement_Alphabet_Numerical_Value(replacement, letter_numerical_value, letters);
		Affine_Cipher_Equation(letter_numerical_value, letters, affine_cipher);
		Output_Answer(affine_cipher, letters);

		index_counter++;
	}

	getchar();
}

void Output_Answer(int affine_cipher, string letters[])
{
	cout << letters[affine_cipher];
}

void Affine_Cipher_Equation(int &letter_numerical_value, string letters[], int &affine_cipher)
{
	affine_cipher = 23 * letter_numerical_value + 23;

	while (affine_cipher > 25)
	{
		affine_cipher -= 26;
	}

	while (affine_cipher < 0)
	{
		affine_cipher += 26;
	}
}

void Identify_Replacement_Alphabet_Numerical_Value(string replacement, int &letter_numerical_value, string letters[])
{
	letter_numerical_value = 0;

	while (replacement != letters[letter_numerical_value])
	{
		letter_numerical_value++;
	}
}

void Identify_Char_to_Decode(string input_string, string &replacement, int index_counter)
{
	replacement = input_string[index_counter];
}

void Display_Instances_of_Letter(float letter_count[], int input_string_length, string letters[])
{
	float float_input_string_length = input_string_length;
	float percentage_occurrence;
	
	for (int i = 0; i < 26; i++)
	{
		//determines how often a letter appears in the text file
		percentage_occurrence = letter_count[i] / input_string_length * 100;

		//outputs each letter's percentage occurence in the text
		cout << fixed; 
		cout << setprecision(2); 
		cout << letters[i] << " " << letter_count[i] << " " << percentage_occurrence << endl;
		}
}

void Letter_Counter(string input_string, string letters[], int &input_string_length, float letter_count[])
{
	string letter_test_case = "";
	bool lettermatch;
	
	for (int i = 0; i < input_string_length; i++)
	{
		/*parse the string to count the individual occurences of every letter*/
		
		letter_test_case = input_string[i];

		lettermatch = false;

		for (int a = 0; a < 26 && lettermatch == false; a++)
		{
			/*find a letter match in the alphabet*/

			if (letter_test_case == letters[a])
			{
				/*indicates a letter match found*/
				
				//bool condition broken
				lettermatch = true;

				//increment instance of letter occurrence
				letter_count[a] += 1;
			}
		}
	}
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