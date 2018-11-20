/***************************************************
 * Program filename: assignment6.cpp
 * Author: Junhyeok Jeong
 * Date:3/17/2018
 * Description: checker game with 2 players
 * Input: token's path, choose answer of question
 * Output: game board, tokenboard, winner
****************************************************/
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <stdio.h>

using namespace std;

/***********************************
 * Function:myatoi
 * Description: convert C-string's value to integer for handling errors
 * Parameters:char* answer
 * Pre-Conditions: take 1 argument as C-string
 * Post-Conditions: conversion of input
***********************************/ 
int myatoi(char* answer){

	int result=0;
	if(strlen(answer)==2){
		result=answer[1] - '0';}
	if(strlen(answer)==3){
		result=10+ (answer[2] - '0');}

	return result;
}
/***********************************
 * Function: check_type
 * Description: error handling for command line argument
 * Parameters:string& board_size
 * Pre-Conditions: take 1 argument as string
 * Post-Conditions: fixing rows and colums 
***********************************/ 
bool check_type(string& board_size){
	bool result=true;

	if(board_size != "1" && board_size != "2" && board_size != "3") {
		result =false;}
	return result;
}
/***********************************
 * Function: type_board
 * Description: check command line argument and then setting board's type
 * Parameters:int& rows, int& cols, string& board_size
 * Pre-Conditions: take 3 arguments as references
 * Post-Conditions: fixing rows and colums
***********************************/ 
int type_board(int& rows, int& cols,string& board_size){
	cout << "------------------------------" << endl;
	cout << "| Welcome to Checker game !! | " << endl;
	cout << "------------------------------ " << endl;
	cout << endl;
	cout << " Setting tokens on the board " << endl;
	cout << endl;
	if(atoi(board_size.c_str()) ==1){
		rows =8;
		cols =8;}
	if(atoi(board_size.c_str()) ==2){
		rows=10;
		cols=10;}
	if(atoi(board_size.c_str()) ==3){
		rows=12;
		cols=12;}

	return cols,rows;
}	
/***********************************
 * Function: init_board
 * Description: initializing board as a dynamic 2D array
 * Parameters:int& rows, int& cols
 * Pre-Conditions: take 2 argument as references
 * Post-Conditions: created a dynamic 2D array
***********************************/ 
char** init_board(int& rows, int& cols) {
		char** board= new char*[rows+1];

		for(int i=0; i<rows; i++) {
			board[i] = new char[cols+1];
			for(int j=0; j<cols; j++){
				board[i][j]= '\0';
}
}
	return board;
}
/***********************************
 * Function: set_board
 * Description: setting board's element
 * Parameters:char** board, int& rows, int& cols
 * Pre-Conditions: take 3 argument as references and pointer
 * Post-Conditions: checker token is set
***********************************/ 
void set_board(char** board, int& rows, int& cols){
		for(int i=0; i<rows; i++) {
			for(int j=0; j<cols; j++){
				board[i][j] = ' ';

}
}
		for(int a=0; a<(rows/2-1); a++) {
			for(int b=0; b<cols; b++){
				if(a%2==0){
					if(b%2==1){
						board[a][b] = 'o';}
}
				else{
					if(b%2==0){
						board[a][b] = 'o';}	
}		 
}
}
		for(int c=(rows/2+1); c<rows; c++){
			for(int d=0; d<cols; d++){
				if(c%2==0){
					if(d%2==1){
						board[c][d] = 'x';}
}
				else{
					if(d%2==0){
						board[c][d] = 'x';}
}
}
}
}
/***********************************
 * Function: print_board
 * Description: print game board for displaying
 * Parameters:char** board, int& rows, int& cols
 * Pre-Conditions: take 3 argument as references and pointer
 * Post-Conditions: print board
***********************************/ 
void print_board(char** board, int& rows, int& cols) {
	cout << endl;
for(int h=0; h<rows; h++){
	cout << "  " << char(65+h) << " ";
}
	cout << endl;
	
for(int i=0; i<rows; i++){
	for(int j=0; j<cols; j++) {
		if (i%2 ==0 && j%2 ==0)
			cout<< "|\033[30;47m " << board[i][j] << " ";
		else if (i%2 == 1 && j%2 ==1)
			cout<< "|\033[30;47m " << board[i][j] << " ";
		else
			cout << "|\033[0m " << board[i][j] << " ";
		cout << "\033[0m";
	
	}
	cout<< i+1 << endl;
}
}
/***********************************
 * Function: delete_board
 * Description: deleting a dynamic 2D array
 * Parameters:char** board, int& rows
 * Pre-Conditions: take 2 argument as references and pointer
 * Post-Conditions: heap-memory is clear
***********************************/ 
void delete_board(char** board, int& rows) {

	for(int i=0; i<rows; i++){
		delete [] board[i];}

	delete [] board;
	board= NULL;
}
/***********************************
 * Function: init_logic_board
 * Description: initializing logic board as a dynamic 2D array
 * Parameters:int& rows, int& cols
 * Pre-Conditions: take 2 argument as references
 * Post-Conditions: created a dynamic 2D array
***********************************/ 
int** init_logic_board(int& rows, int& cols) {
		int** logic_board= new int*[rows];
		
		for(int i=0; i<rows; i++) {
			logic_board[i] = new int[cols];
}
	return logic_board;
}
/***********************************
 * Function: set_logic_board
 * Description: setting logic board's element
 * Parameters:char** logic_board, int& rows, int& cols
 * Pre-Conditions: take 3 argument as references and pointer
 * Post-Conditions: array's elements are set for logic check
***********************************/ 
void set_logic_board(int** logic_board, int& rows, int& cols){
	int num=1;
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++) {
			logic_board[i][j]=num;
			num++;}

}
}
/***********************************
 * Function: delete_logic_board
 * Description: deleting a dynamic 2D array
 * Parameters:char** logic_board, int& rows
 * Pre-Conditions: take 2 argument as references and pointer
 * Post-Conditions: heap-memory is clear
***********************************/ 
void delete_logic_board(int** logic_board, int& rows){
		for(int i=0; i<rows; i++) {
			delete [] logic_board[i];
}
		delete [] logic_board;
		logic_board=NULL;
}
/***********************************
 * Function: token_board
 * Description: displaying token board for players
 * Parameters:char** board, int& rows, int& cols, int& o_token, int& x_token
 * Pre-Conditions: take 4 argument as references and pointer
 * Post-Conditions: print token board
***********************************/ 
void token_board(char** board, int& rows, int& cols,int& o_token, int& x_token){
	
	o_token=0,x_token=0;
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			if(board[i][j] =='8' || board[i][j] =='o'){
				o_token=o_token+1;}
			if(board[i][j] =='X' || board[i][j] =='x'){
				x_token=x_token+1;}
}
}
	cout << endl;
	cout<< "-----------------------------------" << endl;
	cout<< "|    each player's token left     |" << endl;
	cout<< "|---------------------------------|" << endl;
	cout<< "|    player o    |   player x     |" << endl;
	cout<< "|       "<< o_token << "       |       " <<  x_token << "       |" << endl;
	cout<< "-----------------------------------" << endl;
}
/***********************************
 * Function: token_ea
 * Description: counting tokens 
 * Parameters:char** board, int& rows, int& cols, int& o_token, int& x_token
 * Pre-Conditions: take 5 argument as references and pointer
 * Post-Conditions: o_token, x_token
***********************************/ 
void token_ea(char** board, int& rows, int& cols, int& o_token, int& x_token){

	o_token=0,x_token=0;
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			if(board[i][j] == '8' || board[i][j] == 'o'){
				o_token=o_token+1;}
			if(board[i][j] == 'X' || board[i][j] == 'x'){
				x_token=x_token+1;}
}
}	
}
/***********************************
 * Function: answer_error_check
 * Description: error handling function for the question's answer 
 * Parameters:char* answer, int& rows
 * Pre-Conditions: take 2 argument as references and pointer
 * Post-Conditions: output is true or false
***********************************/ 
bool answer_error_check(char* answer, int& rows){
	bool result =false;

	for(int i=0; i<rows; i++){
		if(answer[0] == char(65)+i){result= true;}
}
	if(rows==8){
		if(strlen(answer) !=2){result= false;} 
		if(answer[1] != '1' && answer[1] != '2' && answer[1] != '3' && answer[1] != '4' && answer[1] != '5' && answer[1] != '6' && answer[1] != '7' && answer[1] != '8' || answer[2] != '\0') {result = false;}
}

	if(rows==10){
		if(strlen(answer) !=2 && strlen(answer) !=3){result= false;}
		if(strlen(answer) ==2){
			if( answer[1] != '1' && answer[1] != '2' && answer[1] != '3' && answer[1] != '4' && answer[1] != '5' && answer[1] != '6' && answer[1] != '7' && answer[1] != '8' && answer[1] != '9' || answer[2] != '\0'){result = false;}
}
		if(strlen(answer) ==3) {
			if( answer[1] != '1' || answer[2] != '0') {result = false;}
}
}

	if(rows==12){
		if(strlen(answer) !=2 && strlen(answer) !=3){result= false;}
		if(strlen(answer) ==2){
			if( answer[1] != '1' && answer[1] != '2' && answer[1] != '3' && answer[1] != '4' && answer[1] != '5' && answer[1] != '6' && answer[1] != '7' && answer[1] != '8' && answer[1] != '9' || answer[2] != '\0'){result = false;}
}
		if(strlen(answer) ==3){
			if( answer[1] != '1' || answer[2] !='0' && answer[2] != '1' && answer[2] != '2'){result = false;}
}
}
	return result;
}
/***********************************
 * Function: token_check
 * Description: error handling function for player's token 
 * Parameters:char** board, int& rows, char* answer, int& cols, bool& player
 * Pre-Conditions: take 5 argument as references and pointer
 * Post-Conditions: output is true or false
***********************************/ 
bool token_check(char** board, int& rows, int& cols, bool& player, char* answer){
	bool result = true;
	if(player ==true){
		if(board[myatoi(answer)-1][int(answer[0])-65] != 'o' && board[myatoi(answer)-1][int(answer[0])-65] != '8'){
			result = false;}
}
	if(player ==false){
		if(board[myatoi(answer)-1][int(answer[0])-65] != 'x' && board[myatoi(answer)-1][int(answer[0])-65] != 'X'){
			result = false;}
}
	return result;
}
/***********************************
 * Function: diagonal_check
 * Description: error handling function for the diagonal moving 
 * Parameters:char** board, int** logic_board, char* answer_1, char* answer_2
 * Pre-Conditions: take 4 argument as references and pointer
 * Post-Conditions: output is true or false
***********************************/ 	
bool diagonal_check(char** board, int** logic_board, char* answer_1, char* answer_2){
	bool result =false;

	if(board[myatoi(answer_1)-1][int(answer_1[0])-65] == 'o' && board[myatoi(answer_2)-1][int(answer_2[0])-65] == ' '){
		if(logic_board[myatoi(answer_2)-1][int(answer_2[0])-65] == logic_board[myatoi(answer_1)][int(answer_1[0])-64]){result =true;}

 		if(logic_board[myatoi(answer_2)-1][int(answer_2[0])-65] == logic_board[myatoi(answer_1)][int(answer_1[0])-66]){result =true;}
}

	if(board[myatoi(answer_1)-1][int(answer_1[0])-65] == '8' && board[myatoi(answer_2)-1][int(answer_2[0])-65] == ' '){
		if(logic_board[myatoi(answer_2)-1][int(answer_2[0])-65] == logic_board[myatoi(answer_1)][int(answer_1[0])-64]){result =true;}
	
		if(logic_board[myatoi(answer_2)-1][int(answer_2[0])-65] == logic_board[myatoi(answer_1)][int(answer_1[0])-66]){result =true;}

 		if(logic_board[myatoi(answer_2)-1][int(answer_2[0])-65] == logic_board[myatoi(answer_1)-2][int(answer_1[0])-66]){result =true;}

		if(logic_board[myatoi(answer_2)-1][int(answer_2[0])-65] == logic_board[myatoi(answer_1)-2][int(answer_1[0])-64]){result = true;}
}

	if(board[myatoi(answer_1)-1][int(answer_1[0])-65] == 'x' && board[myatoi(answer_2)-1][int(answer_2[0])-65] == ' '){
		if(logic_board[myatoi(answer_2)-1][int(answer_2[0])-65] == logic_board[myatoi(answer_1)-2][int(answer_1[0])-66]){result =true;}

		if(logic_board[myatoi(answer_2)-1][int(answer_2[0])-65] == logic_board[myatoi(answer_1)-2][int(answer_1[0])-64]){result = true;}
}

	if(board[myatoi(answer_1)-1][int(answer_1[0])-65] == 'X' && board[myatoi(answer_2)-1][int(answer_2[0])-65] == ' '){
		if(logic_board[myatoi(answer_2)-1][int(answer_2[0])-65] == logic_board[myatoi(answer_1)][int(answer_1[0])-64]){result = true;}

		if(logic_board[myatoi(answer_2)-1][int(answer_2[0])-65] == logic_board[myatoi(answer_1)][int(answer_1[0])-66]){result = true;} 
		
		if(logic_board[myatoi(answer_2)-1][int(answer_2[0])-65] == logic_board[myatoi(answer_1)-2][int(answer_1[0])-66]){result = true;}

		if(logic_board[myatoi(answer_2)-1][int(answer_2[0])-65] == logic_board[myatoi(answer_1)-2][int(answer_1[0])-64]){result = true;}
}

	return result;
}
/***********************************
 * Function: o_capture_check
 * Description: error handling function for o_player's capture 
 * Parameters:char** board, int** logic_board, char* answer_1, char* answer_2
 * Pre-Conditions: take 4 argument as references and pointer
 * Post-Conditions: output is true or false
***********************************/ 
bool o_capture_check(char** board, int** logic_board, char* answer_1, char* answer_2){
	

if(board[myatoi(answer_1)-1][int(answer_1[0])-65] == 'o'){
	if(board[myatoi(answer_1)][int(answer_1[0])-64] == 'x' || board[myatoi(answer_1)][int(answer_1[0])-64] == 'X'){
		if(logic_board[myatoi(answer_2)-1][int(answer_2[0])-65] == logic_board[myatoi(answer_1)+1][int(answer_1[0])-63]){
			if(board[myatoi(answer_2)-1][int(answer_2[0])-65] == ' '){board[myatoi(answer_1)][int(answer_1[0])-64] =' ';
											return true;}
}
} // capture jump 1
	if(board[myatoi(answer_1)][int(answer_1[0])-66] == 'x' || board[myatoi(answer_1)][int(answer_1[0])-66] == 'X'){
		if(logic_board[myatoi(answer_2)-1][int(answer_2[0])-65] == logic_board[myatoi(answer_1)+1][int(answer_1[0])-67]){
			if(board[myatoi(answer_2)-1][int(answer_2[0])-65] == ' '){board[myatoi(answer_1)][int(answer_1[0])-66] = ' ';
											return true;}
} // capture jump 2
}
}

if(board[myatoi(answer_1)-1][int(answer_1[0])-65] == '8'){
	if(board[myatoi(answer_1)][int(answer_1[0])-64] == 'x' || board[myatoi(answer_1)][int(answer_1[0])-64] == 'X'){
		if(logic_board[myatoi(answer_2)-1][int(answer_2[0])-65] == logic_board[myatoi(answer_1)+1][int(answer_1[0])-63]){
			if(board[myatoi(answer_2)-1][int(answer_2[0])-65] == ' '){board[myatoi(answer_1)][int(answer_1[0])-64] = ' ';
											return true;}
}
} // capture jump 1
	if(board[myatoi(answer_1)][int(answer_1[0])-66] == 'x' || board[myatoi(answer_1)][int(answer_1[0])-66] == 'X'){
		if(logic_board[myatoi(answer_2)-1][int(answer_2[0])-65] == logic_board[myatoi(answer_1)+1][int(answer_1[0])-67]){
			if(board[myatoi(answer_2)-1][int(answer_2[0])-65] == ' '){board[myatoi(answer_1)][int(answer_1[0])-66] = ' ';
											return true;}

} // capture jump 2
}
	if(board[myatoi(answer_1)-2][int(answer_1[0])-66] == 'x' || board[myatoi(answer_1)-2][int(answer_1[0])-66] == 'X'){
		if(logic_board[myatoi(answer_2)-1][int(answer_2[0])-65] == logic_board[myatoi(answer_1)-3][int(answer_1[0])-67]){
			if(board[myatoi(answer_2)-1][int(answer_2[0])-65] == ' '){board[myatoi(answer_1)-2][int(answer_1[0])-66] = ' ';
											return true;}

}
} // capture jump 3
	if(board[myatoi(answer_1)-2][int(answer_1[0])-64] == 'x' || board[myatoi(answer_1)-2][int(answer_1[0])-64] == 'X'){
		if(logic_board[myatoi(answer_2)-1][int(answer_2[0])-65] == logic_board[myatoi(answer_1)-3][int(answer_1[0])-63]){
			if(board[myatoi(answer_2)-1][int(answer_2[0])-65] == ' '){board[myatoi(answer_1)-2][int(answer_1[0])-64] = ' ';
											return true;}

} // capture jump 4
}
}
	return false;
}
/***********************************
 * Function: x_capture_check
 * Description: error handling function for x_player's capture 
 * Parameters:char** board, int** logic_board, char* answer_1, char* answer_2
 * Pre-Conditions: take 4 argument as references and pointer
 * Post-Conditions: output is true or false
***********************************/ 
bool x_capture_check(char** board, int** logic_board, char* answer_1, char* answer_2){

if(board[myatoi(answer_1)-1][int(answer_1[0])-65] == 'x'){
	if(board[myatoi(answer_1)-2][int(answer_1[0])-66] == 'o' || board[myatoi(answer_1)-2][int(answer_1[0])-66] == '8'){
		if(logic_board[myatoi(answer_2)-1][int(answer_2[0])-65] == logic_board[myatoi(answer_1)-3][int(answer_1[0])-67]){
			if(board[myatoi(answer_2)-1][int(answer_2[0])-65] == ' '){board[myatoi(answer_1)-2][int(answer_1[0])-66] =' ';
											return true;}
}
} // capture jump 1
	if(board[myatoi(answer_1)-2][int(answer_1[0])-64] == 'o' || board[myatoi(answer_1)-2][int(answer_1[0])-64] == '8'){
		if(logic_board[myatoi(answer_2)-1][int(answer_2[0])-65] == logic_board[myatoi(answer_1)-3][int(answer_1[0])-63]){
			if(board[myatoi(answer_2)-1][int(answer_2[0])-65] == ' '){board[myatoi(answer_1)-2][int(answer_1[0])-64] = ' ';
											return true;}
} // capture jump 2
}
}
if(board[myatoi(answer_1)-1][int(answer_1[0])-65] == 'X'){
	if(board[myatoi(answer_1)][int(answer_1[0])-64] == 'o' || board[myatoi(answer_1)][int(answer_1[0])-64] == '8'){
		if(logic_board[myatoi(answer_2)-1][int(answer_2[0])-65] == logic_board[myatoi(answer_1)+1][int(answer_1[0])-63]){
			if(board[myatoi(answer_2)-1][int(answer_2[0])-65] == ' '){board[myatoi(answer_1)][int(answer_1[0])-64] = ' ';
											return true;}
}
} // capture jump 1
	if(board[myatoi(answer_1)][int(answer_1[0])-66] == 'o' || board[myatoi(answer_1)][int(answer_1[0])-66] == '8'){
		if(logic_board[myatoi(answer_2)-1][int(answer_2[0])-65] == logic_board[myatoi(answer_1)+1][int(answer_1[0])-67]){
			if(board[myatoi(answer_2)-1][int(answer_2[0])-65] == ' '){board[myatoi(answer_1)][int(answer_1[0])-66] = ' ';
											return true;}

} // capture jump 2
}
	if(board[myatoi(answer_1)-2][int(answer_1[0])-66] == 'o' || board[myatoi(answer_1)-2][int(answer_1[0])-66] == '8'){
		if(logic_board[myatoi(answer_2)-1][int(answer_2[0])-65] == logic_board[myatoi(answer_1)-3][int(answer_1[0])-67]){
			if(board[myatoi(answer_2)-1][int(answer_2[0])-65] == ' '){board[myatoi(answer_1)-2][int(answer_1[0])-66] = ' ';
											return true;}

}
} // capture jump 3
	if(board[myatoi(answer_1)-2][int(answer_1[0])-64] == 'o' || board[myatoi(answer_1)-2][int(answer_1[0])-64] == '8'){
		if(logic_board[myatoi(answer_2)-1][int(answer_2[0])-65] == logic_board[myatoi(answer_1)-3][int(answer_1[0])-63]){
			if(board[myatoi(answer_2)-1][int(answer_2[0])-65] == ' '){board[myatoi(answer_1)-2][int(answer_1[0])-64] = ' ';
											return true;}

} // capture jump 4
}
}
	return false;
}
/***********************************
 * Function: o_double_jump
 * Description: checking and error handling function for o_player's double jump 
 * Parameters:char** board, int** logic_board, char* answer_1, char* answer_2
 * Pre-Conditions: take 4 argument as references and pointer
 * Post-Conditions: output is true or false
***********************************/ 
bool o_double_jump(char** board, int** logic_board, char* answer_1, char* answer_2){
	bool result = false;

if(board[myatoi(answer_2)-1][int(answer_2[0])-65] == 'o'){
	if(board[myatoi(answer_2)][int(answer_2[0])-64] == 'x' || board[myatoi(answer_2)][int(answer_2[0])-64] == 'X'){
			if(board[myatoi(answer_2)+1][int(answer_2[0])-63] == ' '){result = true;}
}
 // capture jump 1
	if(board[myatoi(answer_2)][int(answer_2[0])-66] == 'x' || board[myatoi(answer_2)][int(answer_2[0])-66] == 'X'){
			if(board[myatoi(answer_2)+1][int(answer_2[0])-67] == ' '){result = true;}
} // capture jump 2
}


if(board[myatoi(answer_2)-1][int(answer_2[0])-65] == '8'){
	if(board[myatoi(answer_2)][int(answer_2[0])-64] == 'x' || board[myatoi(answer_2)][int(answer_2[0])-64] == 'X'){
			if(board[myatoi(answer_2)+1][int(answer_2[0])-63] == ' '){result = true;}
} // capture jump 1
	if(board[myatoi(answer_2)][int(answer_2[0])-66] == 'x' || board[myatoi(answer_2)][int(answer_2[0])-66] == 'X'){
			if(board[myatoi(answer_2)+1][int(answer_2[0])-67] == ' '){result = true;}

} // capture jump 2

	if(board[myatoi(answer_2)-2][int(answer_2[0])-66] == 'x' || board[myatoi(answer_2)-2][int(answer_2[0])-66] == 'X'){
			if(board[myatoi(answer_2)-3][int(answer_2[0])-67] == ' '){result = true;}

}
 // capture jump 3
	if(board[myatoi(answer_2)-2][int(answer_2[0])-64] == 'x' || board[myatoi(answer_2)-2][int(answer_2[0])-64] == 'X'){
			if(board[myatoi(answer_2)-3][int(answer_2[0])-63] == ' '){result = true;}

} // capture jump 4
}
	return result;
}
/***********************************
 * Function: x_double_jump
 * Description: checking and error handling function for x_player's double jump 
 * Parameters:char** board, int** logic_board, char* answer_1, char* answer_2
 * Pre-Conditions: take 4 argument as references and pointer
 * Post-Conditions: output is true or false
***********************************/ 
bool x_double_jump(char** board, int** logic_board, char* answer_1, char* answer_2){
	bool result = false;

if(board[myatoi(answer_2)-1][int(answer_2[0])-65] == 'x'){
	if(board[myatoi(answer_2)-2][int(answer_2[0])-66] == 'o' || board[myatoi(answer_2)-2][int(answer_2[0])-66] == '8'){
			if(board[myatoi(answer_2)-3][int(answer_2[0])-67] == ' '){result = true;}
}
 // capture jump 1
	if(board[myatoi(answer_2)-2][int(answer_2[0])-64] == 'o' || board[myatoi(answer_2)-2][int(answer_2[0])-64] == '8'){
			if(board[myatoi(answer_2)-3][int(answer_2[0])-63] == ' '){result = true;}
} // capture jump 2
}


if(board[myatoi(answer_2)-1][int(answer_2[0])-65] == 'X'){
	if(board[myatoi(answer_2)][int(answer_2[0])-64] == 'o' || board[myatoi(answer_2)][int(answer_2[0])-64] == '8'){
			if(board[myatoi(answer_2)+1][int(answer_2[0])-63] == ' '){result = true;}
} // capture jump 1
	if(board[myatoi(answer_2)][int(answer_2[0])-66] == 'o' || board[myatoi(answer_2)][int(answer_2[0])-66] == '8'){
			if(board[myatoi(answer_2)+1][int(answer_2[0])-67] == ' '){result = true;}

} // capture jump 2

	if(board[myatoi(answer_2)-2][int(answer_2[0])-66] == 'o' || board[myatoi(answer_2)-2][int(answer_2[0])-66] == '8'){
			if(board[myatoi(answer_2)-3][int(answer_2[0])-67] == ' '){result = true;}

}
 // capture jump 3
	if(board[myatoi(answer_2)-2][int(answer_2[0])-64] == 'o' || board[myatoi(answer_2)-2][int(answer_2[0])-64] == '8'){
			if(board[myatoi(answer_2)-3][int(answer_2[0])-63] == ' '){result = true;}

} // capture jump 4
}
	return result;
}

/***********************************
 * Function: token_remove
 * Description: remove token for displaying game board
 * Parameters:char** board, char* answer_1, char* answer_2, int& rows, int& cols
 * Pre-Conditions: take 5 argument as references and pointer
 * Post-Conditions: printing board after player's turn
***********************************/ 
void token_remove(char** board, char* answer_1, char* answer_2, int& rows, int& cols){

	char temp=board[myatoi(answer_1)-1][int(answer_1[0])-65];
	board[myatoi(answer_1)-1][int(answer_1[0])-65] = ' ';
	board[myatoi(answer_2)-1][int(answer_2[0])-65] = temp;
	print_board(board,rows,cols);
}
/***********************************
 * Function: o_double_jump_check
 * Description: checking and error handling function for o_player's double jump 
 * Parameters:char** board, int** logic_board, char* answer_1, char* answer_2, int& rows, int& cols
 * Pre-Conditions: take 6 argument as references and pointer
 * Post-Conditions: output is true or false
***********************************/ 
bool o_double_jump_check(char** board, int** logic_board, char* answer_1, char* answer_2, int& rows, int& cols){
	char double_jump[255] = "";
	char* answer_3= new char[4];
	if(o_double_jump(board,logic_board,answer_1,answer_2) == true){ 
		cout << "Do you want to jump more? (Y/N)" << endl;
		cin >> double_jump;
		double_jump[254] = '\0';
		if(strlen(double_jump) != 1){
			cout << " Warning !! check your input !" << endl;
			o_double_jump_check(board,logic_board,answer_1,answer_2,rows,cols);
			return 0;}
		if(double_jump[0] != 'Y' && double_jump[0] != 'N'){
			cout << " Warning !! check your input !" << endl;
			o_double_jump_check(board,logic_board,answer_1,answer_2,rows,cols);
			return 0;}
		if(double_jump[0] == 'Y'){
			strcpy(answer_3,answer_2);
			cout << "To where?" << endl;
			cin >> answer_2;
			if(answer_error_check(answer_2,rows) == false || o_capture_check(board,logic_board,answer_3,answer_2) == false){
				cout << "Warning !! check your input !" << endl;
				o_double_jump_check(board,logic_board,answer_1,answer_3,rows,cols);
				return 0;}
			cout << "Captured !! again" << endl;
			token_remove(board,answer_3,answer_2,rows,cols);}
}
	delete [] answer_3;
}
/***********************************
 * Function: x_double_jump_check
 * Description: checking and error handling function for x_player's double jump 
 * Parameters:char** board, int** logic_board, char* answer_1, char* answer_2, int& rows, int& cols
 * Pre-Conditions: take 6 argument as references and pointer
 * Post-Conditions: output is true or false
***********************************/ 		
bool x_double_jump_check(char** board, int** logic_board, char* answer_1, char* answer_2, int& rows, int& cols){
	char double_jump[255] = "";
	char* answer_3= new char[4];
	if(x_double_jump(board,logic_board,answer_1,answer_2) == true){ // add x_double_jump check  later
		cout << "Do you want to jump more? (Y/N)" << endl;
		cin >> double_jump;
		double_jump[254] = '\0';
		if(strlen(double_jump) != 1){
			cout << " Warning !! check your input !" << endl;
			x_double_jump_check(board,logic_board,answer_1,answer_2,rows,cols);
			return 0;}
		if(double_jump[0] != 'Y' && double_jump[0] != 'N'){
			cout << " Warning !! check your input !" << endl;
			x_double_jump_check(board,logic_board,answer_1,answer_2,rows,cols);
			return 0;}
		if(double_jump[0] == 'Y'){
			strcpy(answer_3,answer_2);
			cout << "To where?" << endl;
			cin >> answer_2;
			if(answer_error_check(answer_2,rows) == false || x_capture_check(board,logic_board,answer_3,answer_2) == false){
				cout << "Warning !! check your input !" << endl;
				x_double_jump_check(board,logic_board,answer_1,answer_3,rows,cols);
				return 0;}
			cout << "Captured !! again" << endl;
			token_remove(board,answer_3,answer_2,rows,cols);}
}
	delete [] answer_3;
}
/***********************************
 * Function: king_row
 * Description: checking token location and then making a king 
 * Parameters:char** board, int& rows, int& cols
 * Pre-Conditions: take 3 argument as references and pointer
 * Post-Conditions: change normal token to king token 
***********************************/ 
void king_row(char** board,int& rows, int& cols){
	
	for(int i=0; i<cols; i++){
		if(board[rows-1][i] =='o'){
			board[rows-1][i] = '8';
	cout<< endl;
	cout<< "-------------------------------" << endl;
	cout<< "|o token reached king's row !!|" << endl;
	cout<< "-------------------------------" << endl;
	print_board(board,rows,cols);}
}

	for(int j=0; j<cols; j++){
		if(board[0][j] == 'x'){
			board[0][j] = 'X';
	cout<< endl;
	cout<< "-------------------------------" << endl;
	cout<< "|x token reached king's row !!|" << endl;
	cout<< "-------------------------------" << endl;
	print_board(board,rows,cols);}	
}

}
/***********************************
 * Function: move_player_o
 * Description: ask questions for moving and then print changed board
 * Parameters:char** board, int** logic_board, int& rows, int& cols, bool& player, int& o_token, int& x_token
 * Pre-Conditions: take 7 argument as references and pointer
 * Post-Conditions: follow player's answer and then print changed board
***********************************/ 
char move_player_o(char** board, int** logic_board, int& rows, int& cols, bool& player, int& o_token, int& x_token){
	int temp_token=x_token;
	cout << "--------------Player_o's turn------------" << endl;
	char* answer_1=new char[4];
	cout << "Which token do you want to move?" << endl;
	cin >> answer_1;
	if(answer_error_check(answer_1,rows) ==false || token_check(board,rows,cols,player,answer_1) == false){
		cout << "Warning !! check your input !" << endl;
		move_player_o(board,logic_board,rows,cols,player,o_token,x_token);
		return 0;}
	answer_1 [3] = '\0';
	
	char* answer_2=new char[4];
	cout << "To where?" << endl;
	cin >> answer_2;
	if(answer_error_check(answer_2,rows) == false){
		cout <<"Warning !! check your input !" << endl;
		move_player_o(board,logic_board,rows,cols,player,o_token,x_token);
		return 0;}
	if(diagonal_check(board,logic_board,answer_1,answer_2) != true && o_capture_check(board,logic_board,answer_1,answer_2) != true){
		cout << "Warning !! check your input !" << endl;
		move_player_o(board,logic_board,rows,cols,player,o_token,x_token);
		return 0;}   	

	answer_2 [3] = '\0';
	token_remove(board,answer_1,answer_2,rows,cols);
	token_ea(board,rows,cols,o_token,x_token);
	if(temp_token != x_token){
		cout << "Captured !!" << endl;
		o_double_jump_check(board,logic_board,answer_1,answer_2,rows,cols); 	
	}
	king_row(board,rows,cols);
	cout << "Player_o's turn is over !!" << endl;
	delete [] answer_1;
	delete [] answer_2;
}
/***********************************
 * Function: move_player_x
 * Description: ask questions for moving and then print changed board
 * Parameters:char** board, int** logic_board, int& rows, int& cols, bool& player, int& o_token, int& x_token
 * Pre-Conditions: take 7 argument as references and pointer
 * Post-Conditions: follow player's answer and then print changed board
***********************************/ 
char move_player_x(char** board, int** logic_board, int& rows, int& cols, bool& player,int& o_token, int& x_token){
	int temp_token=o_token;
	cout << "------------Player_x's turn------------" << endl;
	char* answer_1=new char[4];
	cout << "Which token do you want to move?" << endl;
	cin >> answer_1;
	if(answer_error_check(answer_1,rows) ==false || token_check(board,rows,cols,player,answer_1) == false){
		cout << "Warning !! check your input !" << endl;
		move_player_x(board,logic_board,rows,cols,player,o_token,x_token);
		return 0;}
	answer_1 [3] = '\0';
	
	char* answer_2=new char[4];
	cout << "To where?" << endl;
	cin >> answer_2;
	if(answer_error_check(answer_2,rows) == false){
		cout <<"Warning !! check your input !" << endl;
		move_player_x(board,logic_board,rows,cols,player,o_token,x_token);
		return 0;}
	if(diagonal_check(board,logic_board,answer_1,answer_2) != true && x_capture_check(board,logic_board,answer_1,answer_2) != true){
		cout << "Warning !! check your input !" << endl;
		move_player_x(board,logic_board,rows,cols,player,o_token,x_token);
		return 0;}   	

	answer_2 [3] = '\0';
	token_remove(board,answer_1,answer_2,rows,cols);
	token_ea(board,rows,cols,o_token,x_token);
	if(temp_token != o_token){
		cout << "Captured !!" << endl;
		x_double_jump_check(board,logic_board,answer_1,answer_2,rows,cols); 	
	}
	king_row(board,rows,cols);
	cout << "Player_x's turn is over !!" << endl;
	delete [] answer_1;
	delete [] answer_2;
}
/***********************************
 * Function: game_play
 * Description: function for whole checker game process
 * Parameters:char** board, int** logic_board, int& rows, int& cols, bool& player_o, bool& player_x, int& o_token, int& x_token
 * Pre-Conditions: take 8 argument as references and pointer
 * Post-Conditions: output is winner
***********************************/ 
void game_play(char** board, int** logic_board, int& rows, int& cols, bool& player_o, bool& player_x, int& o_token, int& x_token){

	print_board(board,rows,cols);
	token_board(board,rows,cols,o_token,x_token);

	while(o_token !=0 && x_token !=0){

	move_player_o(board,logic_board,rows,cols,player_o,o_token,x_token);
	token_board(board,rows,cols,o_token,x_token);
	if(x_token ==0){
	cout << "Congratulation !! Player_o win !!" << endl;
	break;}
	move_player_x(board,logic_board,rows,cols,player_x,o_token,x_token);
	token_board(board,rows,cols,o_token,x_token);
	if(o_token ==0){
	cout << "Congratulation !! Player_x win !!" << endl;
	break;}
}

}

int main(int argc, char** argv){
	if (argc <2){
		cout << "Warning! check your argument (1 - 8X8 2 - 10X10 3 - 12X12) " << endl;
		return 0;}
	string board_size=argv[1];
	if (argc !=2 || check_type(board_size) !=true){
		cout << "Warning! Check your argument (1 - 8X8 2 - 10X10 3 - 12X12) " << endl;
		return 0;}

	int rows, cols; 
	int o_token=0, x_token=0;
	bool player_o=true;
	bool player_x=false;
	
	type_board(rows,cols,board_size);
	char** board = init_board(rows,cols);
	set_board(board,rows,cols);
	int** logic_board = init_logic_board(rows,cols);
	set_logic_board(logic_board,rows,cols);
	
	game_play(board,logic_board,rows,cols,player_o,player_x,o_token,x_token);
	delete_board(board,rows);
	delete_logic_board(logic_board,rows);	

}
