/***************************************************
 * Program filename: assignment5.cpp
 * Author: Junhyeok Jeong
 * Date:3/4/2018
 * Description: Farkle game with multiple players
 * Input: player's number, choose answer of question
 * Output: Scoreboard, winner
****************************************************/

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
/***********************************
 * Function: check_player
 * Description: check player_number for handling errors
 * Parameters:string player_number
 * Pre-Conditions: take 1 argument as string
 * Post-Conditions: player_number should be integer
***********************************/ 
bool check_player(string player_number){
		bool check=true;
	for (int i=0; i<(player_number).length(); i++){
		if((player_number)[i] !=48 && (player_number)[i] != 49 && (player_number)[i] != 50 && (player_number)[i] != 51 && (player_number)[i] != 52 && (player_number)[i] != 53 && (player_number)[i] != 54 && (player_number)[i] != 55 && (player_number)[i] != 56 && (player_number)[i] != 57){
			check = false;}
}
		return check;
}
/***********************************
 * Function: get_player
 * Description: take name and put it in player_list
 * Parameters:string *player_list,string player_number
 * Pre-Conditions: take 2 argument as string and string array
 * Post-Conditions: the input values should fit to parameters
***********************************/ 
void get_player(string *player_list,string player_number){

	for (int i=0; i<atoi((player_number).c_str()); i++){
		cout << "input each player name: " << endl;
		getline(cin, player_list[i]); 
}
	player_list [atoi((player_number).c_str())] = '\0';
	for (int i=0; i<atoi((player_number).c_str()); i++){
	cout << (player_list)[i] << endl;
}
	
	
}
/***********************************
 * Function: rolling
 * Description: rolloing 6 dice in dice array
 * Parameters:int *dice
 * Pre-Conditions: take an argument as int array
 * Post-Conditions: dice array should be size of 6
***********************************/ 
int rolling(int *dice){
	srand(time(NULL));

	for (int i =0; i<6; i++){
		dice[i]=(rand()%6 +1);
		
}
	return *dice;
}
/***********************************
 * Function: set_aside
 * Description: set aside scroing dice which user choose by question
 * Parameters:int *dice,bool *reroll_position
 * Pre-Conditions: take 2 arguments as int and bool arrays
 * Post-Conditions: input arrays should be size of 6
***********************************/ 
int set_aside(int *dice,bool *reroll_position){
	int scoring_dice=0;
	int index;
	char answer;
	for(int i=0; i<6; i++){
		if(reroll_position[i]==true){
			scoring_dice=scoring_dice+1;}
}
	if(scoring_dice>0){
	for(int j=0; j<scoring_dice; j++){
		cout << "what scoring dice set aside? (input dice's number, not value)" << endl;
		cin >> index;
		if(reroll_position[index-1] ==false){
		cout << "please input scoring dice" << endl;
		set_aside(dice,reroll_position);
		break;}
		dice[index-1] = 0;
		cout << "do you want to set aside more?(Y/N)" << endl;
		cin >>answer;
		if(answer == 'n' || answer == 'N'){
			break;}
}
}
	return *dice;
}
/***********************************
 * Function: reroll
 * Description: rerolling dice depend on reroll position
 * Parameters:int *dice,bool *reroll_position
 * Pre-Conditions: take 2 arguments as int and bool arrays
 * Post-Conditions: input arrays should be same size
***********************************/ 
int reroll(int *dice,bool *reroll_position){
	srand(time(NULL));	
	
	for(int i=0; i<6; i++){
	if (dice[i] !=0 || reroll_position[i]==false){
		dice[i] =(rand()%6 +1);}
}
	return *dice;
}
/***********************************
 * Function: printroll
 * Description: print dice's elements
 * Parameters:int *dice
 * Pre-Conditions: take 1 argument as integer array
 * Post-Conditions: dice array should be 6 size
***********************************/ 
void printroll(int *dice){
	for(int i=0; i<6; i++){
		cout<< dice[i] << " " ;
		}
	cout << "" << endl;

}
/***********************************
 * Function: scoring_1
 * Description: take dice and calculate score
 * Parameters:int& score,int *dice, bool *reroll_position
 * Pre-Conditions: take 3 arguments as integer and bool arrays
 * Post-Conditions: all arrays should have same size and score is linked by pointers
***********************************/ 
int scoring_1(int& score,int *dice,bool *reroll_position){
	int counter_1=0;

	for(int i=0; i<6; i++){
	
	if(dice[i]== 1 && reroll_position[i]== false){
	score += 100;
	reroll_position[i] =true;
	counter_1=counter_1+1;}
}
	if (counter_1 == 4){
		score=(score-400)+1000;}
	if(counter_1 == 5){
		score=(score-500)+2000;}
	if(counter_1 ==6){
		score=(score-600)+3000;}

	return score;
}
/***********************************
 * Function: scoring_2
 * Description: take dice and calculate score
 * Parameters:int& score,int *dice, bool *reroll_position
 * Pre-Conditions: take 3 arguments as integer and bool arrays
 * Post-Conditions: all arrays should have same size and score is linked by pointers
***********************************/ 
int scoring_2(int& score,int *dice,bool *reroll_position){
	int counter_2=0;
	int before_score;
	before_score=score;
	for(int i=0; i<6; i++){

	if(dice[i]== 2 && reroll_position==false){
	counter_2=counter_2+1;}	
}
	if (counter_2 == 3){
			score=score+200;}
	if(counter_2 == 4){
			score=score+1000;}
	if(counter_2 ==5){
			score=score+2000;}
	if(counter_2 ==6){
			score=score+3000;}
	if(before_score !=score){
		for(int j=0; j<6; j++){
			if(dice[j] ==2){
				reroll_position[j]=true;}
}
}
	return score;				
}
/***********************************
 * Function: scoring_3
 * Description: take dice and calculate score
 * Parameters:int& score,int *dice, bool *reroll_position
 * Pre-Conditions: take 3 arguments as integer and bool arrays
 * Post-Conditions: all arrays should have same size and score is linked by pointers
***********************************/ 
int scoring_3(int& score,int *dice,bool *reroll_position){
	int counter_3=0;
	int before_score=score;
	for(int i=0; i<6; i++){

	if(dice[i]== 3 && reroll_position[i]==false){
	counter_3=counter_3+1;}	
}
	if (counter_3 == 3){
		score=score+300;}
	if(counter_3 == 4){
		score=score+1000;}
	if(counter_3 ==5){
		score=score+2000;}
	if(counter_3 ==6){
		score=score+3000;}
	if(before_score !=score){
		for(int j=0; j<6; j++){
			if(dice[j] ==3){
				reroll_position[j]=true;}
}
}
	return score;				
}
/***********************************
 * Function: scoring_4
 * Description: take dice and calculate score
 * Parameters:int& score,int *dice, bool *reroll_position
 * Pre-Conditions: take 3 arguments as integer and bool arrays
 * Post-Conditions: all arrays should have same size and score is linked by pointers
***********************************/ 
int scoring_4(int& score,int *dice,bool *reroll_position){
	int counter_4=0;
	int before_score=score;
	for(int i=0; i<6; i++){

	if(dice[i]== 4 && reroll_position[i]==false){
	counter_4=counter_4+1;}	
}
	if (counter_4 == 3){
		score=score+400;}
	if(counter_4 == 4){
		score=score+1000;}
	if(counter_4 ==5){
		score=score+2000;}
	if(counter_4 ==6){
		score=score+3000;}

	if(before_score !=score){
		for(int j=0; j<6; j++){
			if(dice[j] ==4){
				reroll_position[j]=true;}
}}
	return score;				
}
/***********************************
 * Function: scoring_5
 * Description: take dice and calculate score
 * Parameters:int& score,int *dice, bool *reroll_position
 * Pre-Conditions: take 3 arguments as integer and bool arrays
 * Post-Conditions: all arrays should have same size and score is linked by pointers
***********************************/ 
int scoring_5(int& score,int *dice,bool *reroll_position){
	int counter_5=0;

	for(int i=0; i<6; i++){

	if(dice[i]== 5 && reroll_position[i]==false){
	score=score+50;
	reroll_position[i]=true;
	counter_5=counter_5+1;}	
}
	if (counter_5 == 3){
		score=(score-150)+500;}
	if(counter_5 == 4){
		score=(score-200)+1000;}
	if(counter_5 ==5){
		score=(score-250)+2000;}
	if(counter_5 ==6){
		score=(score-300)+3000;}
	
	return score;				
}
/***********************************
 * Function: scoring_6
 * Description: take dice and calculate score
 * Parameters:int& score,int *dice, bool *reroll_position
 * Pre-Conditions: take 3 arguments as integer and bool arrays
 * Post-Conditions: all arrays should have same size and score is linked by pointers
***********************************/ 
int scoring_6(int& score,int *dice,bool *reroll_position){
	int counter_6=0;
	int before_score=score;
	for(int i=0; i<6; i++){

	if(dice[i]== 6){
	counter_6=counter_6+1;
	}	
}
	if (counter_6 == 3){
		score=score+600;}
	if(counter_6 == 4){
		score=score+1000;}
	if(counter_6 ==5){
		score=score+2000;}
	if(counter_6 ==6){
		score=score+3000;}
	if(before_score !=score){
		for(int j=0; j<6; j++){
			if(dice[j] ==6){
				reroll_position[j]=true;}
}}
	return score;				
}
/***********************************
 * Function: straight_score
 * Description: take dice and calculate score followed combination
 * Parameters:int& score,int *dice, int& special_dice
 * Pre-Conditions: take 3 arguments as integer arrays
 * Post-Conditions: all arrays should have same size and score is linked by pointers
***********************************/ 
int straight_score(int score,int *dice,int& special_dice){
	int straight [6] ={1,2,3,4,5,6};	
	if(dice== straight){
		score=score+1500;
		special_dice-=1;}

	return score;
}
/***********************************
 * Function: three_pair
 * Description: take dice and calculate score followed combination
 * Parameters:int& score,int *dice, int& special_dice
 * Pre-Conditions: take 3 arguments as integer arrays
 * Post-Conditions: all arrays should have same size and score is linked by pointers
***********************************/ 
int three_pair(int score,int *dice,int& special_dice){
	int counter [6]={0,0,0,0,0,0};
	int pair_counter=0;

	for (int i=0; i<6; i++){
			for (int j=1; j<7; j++){
				if (dice[i]==j) counter[j-1]=counter[j-1]+1;}
}
	for(int k=0; k<6; k++){
		if(counter[k] == 2){
			pair_counter=pair_counter+1;}
}
	if(pair_counter ==3){
		score=score+1500;
		special_dice-=1;}
	return score;	 
}
/***********************************
 * Function: four_onepair
 * Description: take dice and calculate score followed combination
 * Parameters:int& score,int *dice, int& special_dice
 * Pre-Conditions: take 3 arguments as integer arrays
 * Post-Conditions: all arrays should have same size and score is linked by pointers
***********************************/ 
int four_onepair(int score,int *dice,int& special_dice){
	int counter [6]={0,0,0,0,0,0};
	int four_numbers=0, pair_counter=0;

	for (int i=0; i<6; i++){
			for (int j=1; j<7; j++){
				if (dice[i]==j) counter[j-1]=counter[j-1]+1;}
}
	for(int k=0; k<6; k++){
		if(counter[k] == 4){
			four_numbers=four_numbers+1;}
		if(counter[k] == 2){
			pair_counter=pair_counter+1;}
}		
	if(four_numbers == 1 && pair_counter == 1){
		score=score+1500;
		special_dice-=1;}

	return score;
}
/***********************************
 * Function: two_triplet
 * Description: take dice and calculate score followed combination
 * Parameters:int& score,int *dice, int& special_dice
 * Pre-Conditions: take 3 arguments as integer arrays
 * Post-Conditions: all arrays should have same size and score is linked by pointers
***********************************/ 
int two_triplet(int score,int *dice,int& special_dice){
	int counter [6]={0,0,0,0,0,0};
	int triplet_counter=0;

	for (int i=0; i<6; i++){
			for (int j=1; j<7; j++){
				if (dice[i]==j) counter[j-1]=counter[j-1]+1;}
}
	for(int k=0; k<6; k++){
		if(counter[k] == 3){
			triplet_counter=triplet_counter+1;}
}
	if(triplet_counter==2){
		score=score+2500;
		special_dice-=1;}

	return score;
}
/***********************************
 * Function: scoring
 * Description: use score combination functions and then caculate final score
 * Parameters:int& score,int *dice, bool *reroll_position
 * Pre-Conditions: take 3 arguments as integer and bool arrays
 * Post-Conditions: all arrays should have same size and score is linked by pointers
***********************************/ 
int scoring(int& score,int *dice,bool *reroll_position){
	int special_dice =4;
	straight_score(score,dice,special_dice);
	three_pair(score,dice,special_dice);
	two_triplet(score,dice,special_dice);
	four_onepair(score,dice,special_dice);
	if(special_dice ==4){
		scoring_1(score,dice,reroll_position);
		scoring_2(score,dice,reroll_position);
		scoring_3(score,dice,reroll_position);
		scoring_4(score,dice,reroll_position);
		scoring_5(score,dice,reroll_position);
		scoring_6(score,dice,reroll_position);}
	else{
		for(int i=0; i<6; i++){
			reroll_position[i]=true;}
	}
	cout << "available score from roll: " << score << endl;
	return score;
}
/***********************************
 * Function: scoreboard
 * Description: after scoring function, record final score to score_list
 * Parameters:int *score_list,string *player_list,string player_number
 * Pre-Conditions: take 3 arguments as integer and string arrays
 * Post-Conditions: all arrays should have same size and score is linked by pointers
***********************************/ 
void scoreboard(int *score_list,string *player_list,string player_number){
		cout << "score board" << endl;
		cout << "-----------" << endl;
		for( int j=0; j<atoi((player_number).c_str()); j++){
				cout << player_list[j] << " : "  << score_list[j] << endl;
		}
		cout << "-----------" << endl;
}
/***********************************
 * Function: check_500
 * Description: checking score is higher than 500 points
 * Parameters:int& score
 * Pre-Conditions: take 1 arguments as integer
 * Post-Conditions: score value should be linked by reference
***********************************/ 
bool check_500(int& score){
	bool result=false;
	if(score >=500){
		result=true;}
	
	return result;
}
/***********************************
 * Function: player_turn
 * Description: arrange functions for playing farkle
 * Parameters:string *player_list,string player_number,int *score_list,int *dice, bool *reroll_position
 * Pre-Conditions: take 5 arguments as integer, bool,and string arrays
 * Post-Conditions: all arrays should have same size and score is linked by pointers
***********************************/ 
void player_turn(string *player_list,string player_number,int *score_list,int *dice,bool *reroll_position){
	char Q_answer;
	int score=0;
	for(int i=0; i<atoi((player_number).c_str()); i++){
		do
		{
		cout << "dice are cast" << endl;
		rolling(dice);
		printroll(dice);
		scoring(score,dice,reroll_position);
	if(score >=0){
		cout << "do you want to reroll non scoring dice? (Y/N)" << endl;
		cin >> Q_answer;
		if (Q_answer =='y' || Q_answer == 'Y'){
		int before_score=score;
		set_aside(dice,reroll_position);
		reroll(dice,reroll_position);
		printroll(dice);
		scoring(score,dice,reroll_position);
			if(score==before_score){
			cout << "Farkle !!" << endl;
			cout << "turn is over " << endl;
			scoreboard(score_list,player_list,player_number);
			for(int h=0; h<6; h++){
				reroll_position[h]=false;
				break;}
}
		if(score>=500){
		score_list[i]=score_list[i]+score;
		scoreboard(score_list,player_list,player_number);}
		break;}
		if(Q_answer =='n' || Q_answer =='N'){
		score_list[i]=score_list[i]+score;
		scoreboard(score_list,player_list,player_number);
		for(int a=0; a<6; a++){
			reroll_position[a]=false;}
		}
}
}while(check_500(score) !=true);


		score=0;
	 	for(int j=0; j<6; j++){
			reroll_position[j]=false;}
	
}
}
/***********************************
 * Function: check_10k
 * Description: check scoreboard is higher then 10000points
 * Parameters:string player_number,int *scire_list
 * Pre-Conditions: take 2 arguments as integer and string arrays
 * Post-Conditions: all arrays should have same size and score is linked by pointers
***********************************/ 
bool check_10k(string player_number,int *score_list){
	bool reach_10k=false;
	for(int i=0; i<atoi((player_number).c_str()); i++){
		if(score_list[i]>= 10000){
		cout << "a player reached 10000 points, start last chance" << endl;
		reach_10k=true;}
}
	return reach_10k;
}
/***********************************
 * Function: get_number
 * Description: take the number of players from user and save
 * Parameters: string& player_number
 * Pre-Conditions: take 1 argument as string value
 * Post-Conditions: input value should be an integer
***********************************/ 
string get_number(string& player_number){
	cout << "welcome to farkle game !!" << endl;
	cout << "-------------------------" << endl;
	cout << "How many players are there? " << endl;
	getline(cin,player_number);
	
	if (check_player(player_number) == false){
		cout << "check your input" << endl;
		get_number(player_number);
	
		
}
	return player_number;
}					
int main() {
	bool reroll_position[]={false,false,false,false,false,false};
	int dice[6];
	//int *dice= new int[6];
	string player_number;
	get_number(player_number);
	string *player_list =new string[atoi(player_number.c_str())+1];
	string winner="";
	int temp=0,win=0;
	get_player(player_list,player_number);

	
	int *score_list = new int[atoi((player_number).c_str())];	
	
	while( check_10k(player_number,score_list) !=true){
		player_turn(player_list,player_number,score_list,dice,reroll_position);
		}
	player_turn(player_list,player_number,score_list,dice,reroll_position);
	for (int i=0; i<atoi((player_number).c_str()); i++){
		if(score_list[i]>=temp){
		temp=score_list[i];
		win=i;}
}

	cout<< "Winner is " << player_list[win] << endl; 
	cout << "with score : " << score_list[win] << endl;
	delete []player_list;
	delete []score_list;
}
	
