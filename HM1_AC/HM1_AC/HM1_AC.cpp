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
void Switch_Letters(string input_string, string letters[], string switch_letters[]);
void Output_new_string(string input_string, string switch_letters[], string letters[]);

int main(void)
{
	ifstream fin("HM1_AC.txt");

	int input_string_length = 0; 
	float letter_count[26] = { 0 };
	string letters[26], switch_letters[26];
	//read text file into a string
	string input_string((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());

	Alphabet(letters);

	//determines text file string length
	Input_String_Length(input_string, input_string_length);
	//indentify the number of times a given letter appears in the text
	Letter_Counter(input_string, letters, input_string_length, letter_count);
	//calculate the number of times a letter occurrs
	Display_Instances_of_Letter(letter_count, input_string_length, letters);

	Switch_Letters(input_string, letters, switch_letters);

	Output_new_string(input_string, switch_letters, letters);

	getchar();
}


void Output_new_string(string input_string, string switch_letters[], string letters[])
{
	string answer, replacement;
	bool match;
	
	for (int i = 0; i < input_string.length(); i++)
	{
		replacement = input_string[i];

		match = false;

		for (int j = 0; j < 26 && match == false; j++)
		{
			if (replacement == switch_letters[j])
			{
				match = true;
				replacement = letters[j];
			}
		}

		answer += replacement;
	}

	cout << "answer: " << answer << endl;
}


void Switch_Letters(string input_string, string letters[], string switch_letters[])
{
	int affine_cipher;
	
	for (int i = 0; i < 26; i++)
	{
		affine_cipher = 3 * i + 13;

		while (affine_cipher > 25)
		{
			affine_cipher -= 26;
		}

		while (affine_cipher < 0)
		{
			affine_cipher += 26;
		}

		switch_letters[i] = letters[affine_cipher];
	}

	for (int i = 0; i < 26; i++)
	{
		cout << i << " " << letters[i] << " " << switch_letters[i] << endl;
	}
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