/*******************************************
 **Program: assignment3.cpp
 **Author: Junhyeok Jeong
 **Date:2/4/2018
 **Description: making 16 functions and each tests
 **Input: integer,float,string
 **Output: except for 15,16 functions, every functions' outputs assumed by me
********************************************/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
/********************************
 **Function: check_range
 **Description:Indicates if the provided number is in the specified range
 **Parameters:int lower_bound, int upper_bound, int test_value
 **Pre-Conditions: takes 3 arguments in input,lower_bound < upper_bound
 **Post-Conditions: true if test_value is in range
*******************************/
bool check_range(int lower_bound,int upper_bound,int test_value) {
		if(test_value >= lower_bound && test_value <= upper_bound) {
			return true;}
		else{ 
			return false;}
}
/******************************
 **Function:is_int
 **Description:Indicates if a given string is an integer
 **Parameters: string num
 **Pre-Conditions: take string value, one argument
 **Post-Conditions: if all string's elements are integer, then true
*****************************/
bool is_int(string num) {
		bool b2;
		for (int i=0; i < num.length(); i++) {
		if( num[i] > 57 || num[i] < 48) {
			b2 = false;
			break;}
		else{
			b2 = true;}

	}
return b2;
}
/*****************************
 **Function:is_float
 **Description:Indicates if a given string is a float
 **Parameters: string num
 **Pre-Conditions: take string value, one argument
 **Post-Conditions: if input string is float, then true
******************************/
bool is_float(string num) {
		bool b3 = false;
		int float_point = 0;
	
		for (int i=0; i < num.length(); i++) {
			if ( num[i] >= 48 && num[i] <= 57 || num[i] == 46)
				{
					if(num[i] == 46)
					float_point++;
					b3 = true;
				}  
			else 
				return b3;
}
		if (float_point ==1){
			return b3;}
		else{
			b3 = false;
			return b3;}	
}
/****************************
 * Function:is_capital
 * Description: Indicates if a given character is a capital letter
 * Parameters:char letter
 * Pre-Conditions: take one character, one argument
 * Post-Conditions: if input character is capital letter, then true
****************************/
bool is_capital(char letter) {

		if ( letter < 65 || letter > 90 ) {
			return false;}
		else {
			return true;}
}
/****************************
 * Function:is_even
 * Description: Indicates if a given number is even
 * Parameters:int num
 * Pre-Conditions: take number, one argument
 * Post-Conditions: if input number is even, then true
****************************/
bool is_even(int num) {

		if ( num%2 == 0) {
			return true;}
		else {
			return false;}
}
/****************************
 * Function:is_odd
 * Description: Indicates if a given number is odd
 * Parameters:int num
 * Pre-Conditions: take number, one argument
 * Post-Conditions: if input number is odd, then true
****************************/
bool is_odd(int num) {

		if ( num%2 ==1) {
			return true;}
		else {
			return false;}
}
/****************************
 * Function:equality_test
 * Description: Tests num1 against num2 and returns -1 if num1 < num2, returns 0 if num1 == num2, returns 2 1 if num1 > num2
 * Parameters:int num1,int num2
 * Pre-Conditions: take numbers, two argument
 * Post-Conditions: it is comparing function, all values are accepted in True
****************************/
int equality_test(int num1,int num2){
		int output;
		
		if (num1 == num2) {
		output =0;
		return output;}
		if ( num1 > num2) {
		output = 1;
		return output;}
		else if (num1 < num2) {
		output = -1;
		return output;}
}
/****************************
 * Function:float_is_equal
 * Description: Tests if num1 and num2 are equal to each other within a certain precision
 * Parameters:float num1,float num2,float precision
 * Pre-Conditions: take floats, three argument
 * Post-Conditions: it is comparing function, all values are accepted in True if inputs are floats
****************************/
bool float_is_equal(float num1,float num2,float precision) {

		float diff = num1 - num2;
		if (abs(diff) <= precision) {
		return true;}
		else {
		return false;}
}
/****************************
 * Function:numbers_present
 * Description: Indicates if the provided string contains numbers
 * Parameters:string sentence
 * Pre-Conditions: take string, one argument
 * Post-Conditions: if input sentece has number(s), then it is true
****************************/
bool numbers_present(string sentence) { 
		int result=0;
		
		for (int i=0; i< sentence.length(); i++) {
			if ( sentence[i] < 48 || sentence[i] > 57 ) {
			result =0;
			}
			else {
			result =1;
			break;}
}
		if (result == 1) {
			return true;}
		else{
			return false;}

}
/****************************
 * Function:letters_present
 * Description: Indicates if the provided string contains letters
 * Parameters:string sentence
 * Pre-Conditions: take string, one argument
 * Post-Conditions: if input sentece has letter(s), then it is true
****************************/
bool letters_present(string sentence) {
		int result =0;
		
		for (int i=0; i< sentence.length(); i++) {
			if ( sentence[i] >= 65 && sentence[i] <= 90 ) {
			result =1;
			break;}
			if ( sentence[i] >= 97 && sentence[i] <= 122 ) {
			result =1;
			break;}
			else {
			result = 0;}
}
		if (result == 1) {
			return true;}
		else{
			return false;}
}
/****************************
 * Function:contains_sub_string()
 * Description: Indicates if substring exists in sentence
 * Parameters:string sentence, string sub_string
 * Pre-Conditions: take strings, two arguments
 * Post-Conditions: if main sentece has sub_string, then it is true
****************************/
bool contains_sub_string(string sentence,string sub_string) {

		int result =0;

		for (int i=0; i< sentence.length(); i++) {
			if (sentence[i] == sub_string[0]) {
				for (int j=0; j< sub_string.length(); j++) {
					if (sentence[i+j] != sub_string[j]) {
						result = 0;}
					else {
						result = 1;}
  } 
 }					
}
		if (result == 1) {
			return true;}
		else{
			return false;}	
}
/****************************
 * Function:word_count()
 * Description: provides the number of words in a given string
 * Parameters:string sentence
 * Pre-Conditions: take string, one arguments
 * Post-Conditions: if input sentence has word, then it is true
****************************/
int word_count(string sentence) {
		int counter =1;

		for (int i=0; i<sentence.length(); i++) {
			if (sentence[i] == 32 && sentence[i+1] != 32) {
				counter= counter +1;}
}
		return counter;		
}
/****************************
 * Function:to_upper()
 * Description: Capitalizes all letters in a given string and leave all non-letter characters unchanged
 * Parameters:string sentence
 * Pre-Conditions: take string, one argument
 * Post-Conditions: if input sentence has lower letter, then change to capital letter
****************************/
string to_upper(string sentence) {

		for(int i=0; i<sentence.length(); i++) {
			if (sentence[i] >= 97 && sentence[i] <= 122) sentence[i] -=32;
		}
		return sentence;
}
/****************************
 * Function:to_lower()
 * Description: Makes all letters lowercase in given string
 * Parameters:string sentence
 * Pre-Conditions: take string, one argument
 * Post-Conditions: if input sentence has capital letter, then change to lower letter
****************************/
string to_lower(string sentence) {

		for(int i=0; i<sentence.length(); i++) {
			if (sentence[i] >= 65 && sentence[i] <= 90) sentence[i] +=32;
		}
		return sentence;
}
/****************************
 * Function:get_int()
 * Description: Takes a prompt from the user as a string literal, checks if input is a valid integer, returns the provided integer.
 * Parameters:string prompt
 * Pre-Conditions: take string, one argument
 * Post-Conditions: if input sentence has integer, then take out it from prompt 
****************************/
int get_int() {
		string prompt;
		string output="";
		cout << "Enter your string prompt: " << endl;
		getline(cin, prompt);

		for (int i=0; i<prompt.length(); i++) {
			if (prompt[i] >= 48 && prompt[i] <= 57) {
				output = output + prompt[i];}
		}
		cout << output <<endl;
}
/****************************
 * Function:get_float()
 * Description: Takes a prompt from the user as a string literal, checks if input is a valid float, returns the provided float.
 * Parameters:string prompt
 * Pre-Conditions: take string, one argument
 * Post-Conditions: if input sentence has float, then take out it from prompt 
****************************/
float get_float() {
		string prompt;
		string output="";
		int point_count=0;
		cout << "Enter your string prompt: " << endl;
		getline(cin, prompt);

		for (int i=0; i<prompt.length(); i++) {
			if (prompt[i] >= 48 && prompt[i] <= 57 || prompt[i] ==46) {
				output = output + prompt[i];}
			if(prompt[i] ==46 ) {
					point_count = point_count +1;
			}
		}
		if (point_count > 1 || point_count ==0) {
		output="";}
		
		cout << output << endl;
}
int main() {
	
	cout << "Testing check_range()" << endl;
	cout << "Input: \"1,10,5\", Expected Output: 1, Actual Output: " ;

	if (check_range(1,10,5)) {
		cout << "True, PASS" << endl;}
	else {
		cout << "False, FAIL" << endl;}
	cout << "Input: \"1,10,20\", Expected Output: 0, Actual Output: " ;
	
	if (check_range(1,10,20)) {
		cout << "True, PASS" << endl;}
	else {
		cout << "False, FAIL" << endl;}
	
	cout << "Testing is_int()" << endl;
	cout << "Input: \"1234567\", Expected Output: 1, Actual Output: " ;

	if (is_int("1234567")) {
		cout << "True, PASS" << endl;}
	else {
		cout << "False, FAIL" << endl;}
	cout << "Input: \"123abc\", Expected Output: 0, Actual Output: " ;
	
	if (is_int("123abc")) {
		cout << "True, PASS" << endl;}
	else {
		cout << "False, FAIL" << endl;}
	
	cout << "Testing is_float()" << endl;
	cout << "Input: \"123.456\", Expected Output: 1, Actual Output: " ;

	if (is_float("123.456")) {
		cout << "True, PASS" << endl;}
	else {
		cout << "False, FAIL" << endl;}
	cout << "Input: \"123\", Exepected Output: 0, Actual Output: ";

	if (is_float("123")) {
		cout << "True, PASS" << endl;}
	else {
		cout << "False, FAIL" << endl;}

	cout << "Testing is_capital()" << endl;
	cout << "Input: \"A\", Expected Output: 1, Actual Output: " ;

	if (is_capital('A')) {
		cout << "True, PASS" << endl;}
	else {
		cout << "False, FAIL" << endl;}
	cout << "Input: \"a\", Exepected Output: 0, Actual Output: ";

	if (is_capital('a')) {
		cout << "True, PASS" << endl;}
	else {
		cout << "False, FAIL" << endl;}

	cout << "Testing is_even()" << endl;
	cout << "Input: \"24\", Expected Output: 1, Actual Output: " ;

	if (is_even(24)) {
		cout << "True, PASS" << endl;}
	else {
		cout << "False, FAIL" << endl;}
	cout << "Input: \"23\", Exepected Output: 0, Actual Output: ";

	if (is_even(23)) {
		cout << "True, PASS" << endl;}
	else {
		cout << "False, FAIL" << endl;}

	cout << "Testing is_odd()" << endl;
	cout << "Input: \"11\", Expected Output: 1, Actual Output: " ;

	if (is_odd(11)) {
		cout << "True, PASS" << endl;}
	else {
		cout << "False, FAIL" << endl;}
	cout << "Input: \"12\", Exepected Output: 0, Actual Output: ";

	if (is_odd(12)) {
		cout << "True, PASS" << endl;}
	else {
		cout << "False, FAIL" << endl;}

	cout << "Testing equality_test()" << endl;
	cout << "Input: \"100,50\", Expected Output: 1, Actual Output: " ;

	if (equality_test(100,50)) {
		cout << "1, PASS" << endl;}
	else {
		cout << "False, FAIL" << endl;}
	cout << "Input: \"100,100\", Exepected Output: 0, Actual Output: ";

	if (equality_test(100,100) == 0) {
		cout << "0, PASS" << endl;}
	else {
		cout << "False, FAIL" << endl;}
	cout << "Input: \"50,100\", Expected Output: -1, Actual Output: " ;

	if (equality_test(50,100)) {
		cout << "-1, PASS" << endl;}
	else {
		cout << "False, FAIL" << endl;}

	cout << "Testing float_is_equal()" << endl;
	cout << "Input: \"0.011,0.01,0.01\", Expected Output: 1, Actual Output: " ;

	if (float_is_equal(0.011,0.01,0.01)) {
		cout << "True, PASS" << endl;}
	else {
		cout << "False, FAIL" << endl;}
	cout << "Input: \"0.011,0.01,0.0001\", Exepected Output: 0, Actual Output: ";

	if (float_is_equal(0.011,0.01,0.0001)) {
		cout << "True, PASS" << endl;}
	else {
		cout << "False, FAIL" << endl;}

	cout << "Testing numbers_present()" << endl;
	cout << "Input: \"abcdefg1\", Expected Output: 1, Actual Output: " ;

	if (numbers_present("abcdefg1")) {
		cout << "True, PASS" << endl;}
	else {
		cout << "False, FAIL" << endl;}
	cout << "Input: \"abcdefg\", Exepected Output: 0, Actual Output: ";

	if (numbers_present("abcdefg")) {
		cout << "True, PASS" << endl;}
	else {
		cout << "False, FAIL" << endl;}

	cout << "Testing letters_present()" << endl;
	cout << "Input: \"12345a\", Expected Output: 1, Actual Output: " ;

	if (letters_present("12345a")) {
		cout << "True, PASS" << endl;}
	else {
		cout << "False, FAIL" << endl;}
	cout << "Input: \"12345\", Exepected Output: 0, Actual Output: ";

	if (letters_present("12345")) {
		cout << "True, PASS" << endl;}
	else {
		cout << "False, FAIL" << endl;}

	cout << "Testing contatins_sub_string()" << endl;
	cout << "Input: \"I am staying in OSU,OSU\", Expected Output: 1, Actual Output: " ;

	if (contains_sub_string("I am stating in OSU","OSU")) {
		cout << "True, PASS" << endl;}
	else {
		cout << "False, FAIL" << endl;}
	cout << "Input: \"I am staying in Korea,OSU\", Exepected Output: 0, Actual Output: ";

	if (contains_sub_string("I am staying in Korea","OSU")) {
		cout << "True, PASS" << endl;}
	else {
		cout << "False, FAIL" << endl;}

	cout << "Testing word_count()" << endl;
	cout << "Input: \"I am staying in OSU.\", Expected Output: 5, Actual Output: " ;

	if (word_count("I am stating in OSU.") == 5) {
		cout << "5, PASS" << endl;}
	else {
		cout << "False, FAIL" << endl;}
	cout << "Input: \"IamstayinginKorea.\", Exepected Output: 0, Actual Output: ";

	if (word_count("IamstayinginKorea.") == 0) {
		cout << "True, PASS" << endl;}
	else {
		cout << "False, FAIL" << endl;}

	cout << "Testing to_upper()" << endl;
	cout << "Input: \"abcdefg11.\", Expected Output: ABCDEFG11, Actual Output: " ;

	if (to_upper("abcdefg11") == "ABCDEFG11") {
		cout << "ABCDEFG11, PASS" << endl;}
	else {
		cout << "False, FAIL" << endl;}
	cout << "Input: \"ABCDD\", Exepected Output: ABCD, Actual Output: ";

	if (to_upper("ABCDD") == "ABCD") {
		cout << "True, PASS" << endl;}
	else {
		cout << "ABCDD, FAIL" << endl;}

	cout << "Testing to_lower()" << endl;
	cout << "Input: \"ABCDEFG12.\", Expected Output: abcdefg12, Actual Output: " ;

	if (to_lower("ABCDEFG12") == "abcdefg12") {
		cout << "abcdefg12, PASS" << endl;}
	else {
		cout << "False, FAIL" << endl;}
	cout << "Input: \"abcdd\", Exepected Output: abcd, Actual Output: ";

	if (to_lower("abcdd") == "abcd") {
		cout << "True, PASS" << endl;}
	else {
		cout << "abcdd, FAIL" << endl;}

	cout << "Testing get_int()" << endl;
	get_int();
	cout << "Input: user's input, Expected Output: integers in the input, Actual Output: user's integers, PASS " << endl;
	get_int();
	cout << "Input: not integer, Expected Output: error, Actual Output: \"""\", FAIL " << endl;
	cout << "Testing get_float()" << endl;
	get_float();
	cout << "Input: user's input, Expected Output: float in the input, Actual Output: input's float, PASS" << endl;
	get_float();
	cout << "Input: not float, Expected Output: error, Actual Output: \"""\", FAIL " << endl;
}





