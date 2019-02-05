#include<iostream>
#include<string>
#include<fstream>
#include<streambuf>
#include<iomanip>
#include<vector>
#include <array>
using namespace std;

void Input_String_Length(string input_string, int &input_string_length);
void Alphabet(string letters[]);
void Comparison_Test(int input_string_length, string input_string, int comparison_counter, string letters[]);
void Letter_Frequency(float english_letter_frequencies[]);
void User_Inputs_Key_Length(int &key_length);
void Letter_Count_at_Interval_X(int letter_count[], string input_string, int key_length, string letters[],
	int &counter_letter_frequency_at_key_length);
void Percentage_of_Letter_at_Interval(int letter_count[], vector<float> &text_letter_frequencies, string input_string, int key_length,
	float english_letter_frequencies[]);
void Find_Shift(vector<float> text_letter_frequencies, float english_letter_frequency[]);

int main(void)
{
	ifstream fin("Vigenère.txt");
	string input_string((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
	int input_string_length = 0, letter_count[26] = { 0 }, comparison_counter = 0,
		key_length = 0, number_of_letters = 0, counter_letter_frequency_at_key_length = 0;
	string letters[26], letter_summation = "";
	float english_letter_frequencies[26];
	vector<float> text_letter_frequencies;

	//initialize the hard-coded arrays
	Alphabet(letters);
	Letter_Frequency(english_letter_frequencies);

	//calculate the length of the string
	Input_String_Length(input_string, input_string_length);

	//identifies matches in the shifted string vs. base string
	Comparison_Test(input_string_length, input_string, comparison_counter, letters);

	User_Inputs_Key_Length(key_length);

	for (counter_letter_frequency_at_key_length; counter_letter_frequency_at_key_length < key_length; 
		counter_letter_frequency_at_key_length++)
	{
		/*determine the letter frequency at internvals of the key length*/

		Letter_Count_at_Interval_X(letter_count, input_string, key_length, letters, counter_letter_frequency_at_key_length);
		Percentage_of_Letter_at_Interval(letter_count, text_letter_frequencies, input_string, key_length, english_letter_frequencies);
		Find_Shift(text_letter_frequencies, english_letter_frequencies);
	}

	getchar();
	getchar();
}

void Find_Shift(vector<float> text_letter_frequencies, float english_letter_frequency[])
{
	int total_number_of_shifts = 0, shifts_needed = 0, greatest_sum = 0, answer_number_of_shifts = 0, array_index_counter = 0;
	float sum = 0;
	
	while ((array_index_counter < 26) && (total_number_of_shifts < 26))
	{
		for (int i = 0; i < 26; i++)
		{
			sum += text_letter_frequencies[i] * english_letter_frequency[array_index_counter];

			array_index_counter = i + total_number_of_shifts;
		}

		total_number_of_shifts++;

		if (sum > greatest_sum)
		{
			answer_number_of_shifts = total_number_of_shifts;
			greatest_sum = sum;
		}
	}

	if (array_index_counter > 26)
	{
		int remaining_number_of_shifts = 26 - total_number_of_shifts;
			
		while (remaining_number_of_shifts > 0)
		{
			for (int i = 0; i < 26; i++)
			{
				sum += text_letter_frequencies[i] * english_letter_frequency[array_index_counter];
			}
			
			remaining_number_of_shifts--;

			if (sum > greatest_sum)
			{
				answer_number_of_shifts = total_number_of_shifts;
				greatest_sum = sum;
			}
		}
	}
	
}

void Percentage_of_Letter_at_Interval(int letter_count[], vector<float> &text_letter_frequencies, string input_string, int key_length,
	float english_letter_frequencies[])
{
	int input_string_length = input_string.length();

	for (int i = 0; i < 26; i++)
	{	
		float percentage_letter_occurs = (float)letter_count[i] / (float)input_string_length;
		text_letter_frequencies.push_back(percentage_letter_occurs);
	}

}

void Letter_Count_at_Interval_X(int letter_count[], string input_string, int key_length, string letters[], 
	int &counter_letter_frequency_at_key_length)
{
	string individual_letter;
	bool match = false;
	
	int j = key_length;

	while (j < input_string.length())
	{
		individual_letter = input_string[j];
			
		for (int k = 0; (k < 26) && (match == false); k++)
		{
			if (individual_letter == letters[k])
			{
				letter_count[k] += 1;
				match = true;
			}
		}
			
		match = false;
		j += key_length;
	}
}

void User_Inputs_Key_Length(int &key_length)
{
	cout << "Please enter the key length: ";
	cin >> key_length;
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

void Letter_Frequency(float english_letter_frequencies[])
{
	english_letter_frequencies[0] = 8.167;
	english_letter_frequencies[1] = 1.492;
	english_letter_frequencies[2] = 2.782;
	english_letter_frequencies[3] = 4.253;
	english_letter_frequencies[4] = 12.702;
	english_letter_frequencies[5] = 2.228;
	english_letter_frequencies[6] = 2.015;
	english_letter_frequencies[7] = 6.094;
	english_letter_frequencies[8] = 6.966;
	english_letter_frequencies[9] = 0.153;
	english_letter_frequencies[10] = 0.772;
	english_letter_frequencies[11] = 4.025;
	english_letter_frequencies[12] = 2.406;
	english_letter_frequencies[13] = 6.749;
	english_letter_frequencies[14] = 7.507;
	english_letter_frequencies[15] = 1.929;
	english_letter_frequencies[16] = 0.095;
	english_letter_frequencies[17] = 5.987;
	english_letter_frequencies[18] = 6.327;
	english_letter_frequencies[19] = 9.056;
	english_letter_frequencies[20] = 2.758;
	english_letter_frequencies[21] = 0.978;
	english_letter_frequencies[22] = 2.360;
	english_letter_frequencies[23] = 0.150;
	english_letter_frequencies[24] = 1.974;
	english_letter_frequencies[25] = 0.074;
}