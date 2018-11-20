/**********************************************
 * Program Filename: assignment4.cpp
 * Author: Junhyeok Jeong
 * Date: 2/18/2018
 * Description: this program is about 4 calculators: standard, binary conversions, grade calculator. you can use one of them by choosing each number.
 * Input: combination of functions
 * output: each valid calculated output
***********************************************/
#include <stdlib.h> //for using atof, atoi 
#include <iostream>
#include <string>
#include <cmath>
#include <ctype.h> // for using atof, atoi
#include <stdio.h> // for using atof ,atoi

using namespace std;

/***********************************
 * Function: space_check
 * Description: count " " for making valid input string in standard calculator
 * Parameters:string prompt
 * Pre-Conditions: prompt should have even of ' 's
 * Post-Conditions: ' ' 's count >=2 ' ' 's count %2 ==0
***********************************/ 
bool space_check(string prompt){
	int count=0;
	bool result=false;

	for (int i=0; i<prompt.length(); i++){
		if(prompt[i] ==' '){
		count= count+1;}
}
	if (count >=2 && count%2==0){
		result=true;}

	return result;
}
/***********************************
 * Function: prompt_check
 * Description: check elements one by one for making valid input string in standard calculator
 * Parameters:string prompt
 * Pre-Conditions: prompt have at least one element
 * Post-Conditions: prompt should be integers or float point or one of operaters
***********************************/ 
bool prompt_check(string prompt){
	bool result =true;

	for (int i=0; i<prompt.length(); i++){
		if(prompt[i] !=48 && prompt[i] != 49 && prompt[i] != 50 && prompt[i] != 51 && prompt[i] != 52 && prompt[i] != 53 && prompt[i] != 54 && prompt[i] != 55 && prompt[i] != 56 && prompt[i] != 57 && prompt[i] !=46 && prompt[i] != ' ' & prompt[i] != '+' && prompt[i] != '-' && prompt[i] != '*' && prompt[i] != '/' ){
			result = false;}
}

	return result;
}
/***********************************
 * Function: calculate_part1
 * Description: Depend on sign, change to operator
 * Parameters:string prompt
 * Pre-Conditions: take 3 arguments
 * Post-Conditions: sign should be  one of operaters
***********************************/ 			
float calculate_part1(float store1,float store2,char sign){

		switch(sign){
			case '+':
				store1 = store1 + store2;
				break;
			case '-':
				store1= store1 - store2;
				break;
			case '*':
				store1= store1 * store2;
				break;
			case '/':
				store1 = store1/store2;
				break;
			}
			return store1;
}				
/***********************************
 * Function: calculate_part2
 * Description: with the part1, take final value of standard calculator
 * Parameters:string prompt
 * Pre-Conditions: take 1 argument
 * Post-Conditions: the part1 should be valid
***********************************/ 
float calculate_part2(string prompt){
	float store1;
	store1=atof(prompt.c_str());
	for (int i=0; i<prompt.length(); i++){
		if(prompt[i] == ' '){
		prompt.erase(0,i+1);
		char sign = prompt[0];
		prompt.erase(0,2);
		float store2=atof(prompt.c_str());
		store1=calculate_part1(store1,store2,sign);
		i=0;
		}
}
	cout<< store1 << endl;
}
/***********************************
 * Function: standard_calculator
 * Description: combination of sub-functions, take final value about input values
 * Parameters:string prompt
 * Pre-Conditions: take 1 argument
 * Post-Conditions: the sub-functions should be valid
***********************************/ 
float standard_calculator(string prompt){
		cout << "What is your equation? " << endl;
		getline(cin, prompt);
		
		if (prompt_check(prompt) == false || space_check(prompt) == false){
			cout << "check your equation" << endl;
			return 0;}

		calculate_part2(prompt);
}		
/***********************************
 * Function: check_binary
 * Description: check prompt2 for taking valid value, error handling
 * Parameters:string prompt2
 * Pre-Conditions: take 1 argument as string
 * Post-Conditions: the prompt2 should be consist of 0 or 1
***********************************/ 
bool check_binary(string prompt2){
		for(int i=0; i<prompt2.length(); i++){
			if(prompt2[i] != '0' && prompt2[i] != '1') {
				return false;}
		}
		return true;
}
/***********************************
 * Function: conversion
 * Description: convert prompt2 to integer value
 * Parameters:string prompt2
 * Pre-Conditions: take 1 argument as string
 * Post-Conditions: the prompt2 should be consist of 0 or 1 as string
***********************************/ 
int conversion(string prompt2){
		int result =0;
		for(int i=0; i < prompt2.length(); i++){
			if(prompt2[i] == '1'){
				result = result + pow(2, ((prompt2.length())-i-1));
}
}
		cout << result << endl;
}
/***********************************
 * Function: binary_to_decimal
 * Description: combination of sub-function for converting binary to decimal
 * Parameters:string prompt2
 * Pre-Conditions: take 1 argument as string
 * Post-Conditions: the check_binary(prompt2) should be true 
***********************************/ 
int binary_to_decimal(string prompt2){
		cout << "What is your binary? " << endl;
		getline(cin, prompt2);

		if(check_binary(prompt2) == false){
			cout << "check your binary" << endl;
			return 0;}

		conversion(prompt2);
}
/***********************************
 * Function: check_decimal
 * Description: checking prompt3 for taking valid value
 * Parameters:string prompt3
 * Pre-Conditions: take 1 argument as string
 * Post-Conditions: the prompt3 should be numbers
***********************************/ 
bool check_decimal(string prompt3){
		for(int i=0; i<prompt3.length(); i++){
			if (prompt3[i] <48 || prompt3[i] >57){
			return false;}
}
		return true;
}
/***********************************
 * Function: conversion2
 * Description: calculate prompt3 for taking final value, recursive function
 * Parameters:string prompt3
 * Pre-Conditions: take 1 argument as string
 * Post-Conditions: the prompt3 should be valid value
***********************************/ 
void conversion2(int prompt3){
		int result;
		
		if(prompt3 <=1){
			cout << prompt3;
			return;}
		result = prompt3 %2;
		conversion2(prompt3/2);
		cout << result;
}
/***********************************
 * Function: decimal_to_binary
 * Description: combination of sub-function for converting decimal to binary
 * Parameters:string prompt3
 * Pre-Conditions: take 1 argument as string
 * Post-Conditions: the check_decimal(prompt3) should be true 
***********************************/ 
int decimal_to_binary(string prompt3){
		cout << "What is your decimal? " << endl;
		getline(cin, prompt3);
		
		if(check_decimal(prompt3) == false){
			cout << "check your decimal" << endl;
			return 0;}

		conversion2(atoi(prompt3.c_str()));
		cout<<""<<endl;
}
/***********************************
 * Function: check_grade
 * Description: checking prompt4 for taking valid value
 * Parameters:string prompt4
 * Pre-Conditions: take 1 argument as string
 * Post-Conditions: the prompt4 should be numbers or a float point
***********************************/ 
bool check_grade(string prompt4){
		bool check=true;
	for (int i=0; i<prompt4.length(); i++){
		if(prompt4[i] !=48 && prompt4[i] != 49 && prompt4[i] != 50 && prompt4[i] != 51 && prompt4[i] != 52 && prompt4[i] != 53 && prompt4[i] != 54 && prompt4[i] != 55 && prompt4[i] != 56 && prompt4[i] != 57 && prompt4[i] !=46){
			check = false;}
}
		return check;
}
/***********************************
 * Function: normal_average
 * Description: calculate normal average
 * Parameters:string grade_number
 * Pre-Conditions: take 1 argument as string
 * Post-Conditions: the grade_number should be number as string
***********************************/ 
float normal_average(string grade_number){
		float sum=0;
		string prompt4;
		for (int i=0; i< atoi(grade_number.c_str()); i++){
			cout << "input your each grade one by one" << endl;
			getline(cin, prompt4);
			if(check_grade(prompt4) == false){
				cout << "check your input" << endl;
				return 0;}
			sum=sum+atof(prompt4.c_str());}
		
		cout << "normal average: " << sum/atof(grade_number.c_str()) << endl;
}	
/***********************************
 * Function: weighted_average
 * Description: calculate weighted average
 * Parameters:string grade_number
 * Pre-Conditions: take 1 argument as string
 * Post-Conditions: the grade_number should be number as string
***********************************/ 
float weighted_average(string grade_number){
		string weight;
		string prompt4;
		float sum=0;
		float weight_sum=0;
		for (int i=0; i< atoi(grade_number.c_str()); i++){
			cout << "input your each grade one by one" << endl;
			getline(cin, prompt4);
			cout << "what is the grade's weight?" << endl;
			getline(cin, weight);		
			if (check_grade(prompt4) == false || check_grade(weight) == false){
				cout << "check your input" << endl;
				return 0;}
			sum=sum+(atof(prompt4.c_str())*atof(weight.c_str()));
			weight_sum=weight_sum+atof(weight.c_str());}

		cout << "weighted average: " << sum/weight_sum << endl;
}
/***********************************
 * Function: grade_calculator
 * Description: combination of sub-function for calculating grade average or weighted average
 * Parameters:string option
 * Pre-Conditions: take 1 argument as string
 * Post-Conditions: option should be 1 or 2  
***********************************/ 
float grade_calculator(string option){
		string grade_number;
		
		cout << "what do you want to do? (1.calculate normal average 2.calculate weighted average) " << endl;
		getline(cin, option);
		if(option[0] != '1' && option[0] != '2' || option.length() !=1){
			cout << "check your input" << endl;
			return 0;}
		
		cout << "How many grades do you have? " << endl;
		getline(cin, grade_number);
		if(check_grade(grade_number) == false){
				cout << "check your input" << endl;
				return 0;}
		if(option[0] == '1'){
			normal_average(grade_number);}
		if(option[0] == '2'){
			weighted_average(grade_number);}
}
/***********************************
 * Function: choice
 * Description: function for choosing one of the calculators
 * Parameters:Null
 * Pre-Conditions: pick should be 1 or 2 or 3 or 4 or 5
 * Post-Conditions: each calculator should be valid
***********************************/ 
void choice(){
		string pick;
		cout << "what do you want to use? 1.standard calculator 2.binary to decimal 3.decimal to binary 4. grade calculator 5. stop program " << endl;
		getline(cin, pick);
		
		if(pick[0] != '1' && pick[0] != '2' && pick[0] != '3' && pick[0] != '4' && pick[0] != '5' || pick.length() !=1){
			cout << "check your input" << endl;
			choice();}
		if(pick[0] == '1'){ standard_calculator("prompt");
					choice();}
		if(pick[0] == '2'){ binary_to_decimal("prompt2");
					choice();}
		if(pick[0] == '3'){ decimal_to_binary("prompt3");
					choice();}
		if(pick[0] == '4'){ grade_calculator("prompt4");
					choice();}
		
		if(pick[0] == '5') return;
	
}
			
int main() {
	choice();
}
