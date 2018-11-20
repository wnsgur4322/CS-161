/****************************************
** Program: assignment2.cpp
** Author: Junhyeok Jeong
** Date: 21 January 2018
** Description: This program is about 'Jumanji' text adventure.
                I use if statements and ramdom number library for player.
                There are 3 life points if you lose all then game over.
**Input: 0 or 1 for enter next level
**Output: next level text for mission complete
*****************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
	int life = 3;
        int path ; 
	cout << "Welcome to Jumanji" << endl;
	cout << "You are Dwayne Johnson. This guy is very strong !!" << endl;
	cout << "Mission: meet Kevin Hart. He knows how to escape this jungle!!" << endl;
        cout << "you are in Jungle now. What should you do next? " << endl;
	cout << "0. Go straight without thinking." << endl;
        cout << "1. Wait for people." << endl;
        srand(time(NULL));
        path = rand()%2;       
        if (path == 0) { 
	cout << "You chose path 0" << endl;
	cout << "you find the village of cannibals. Village people don't think you are a good person." << endl;
	cout << " 0. Fight with people." << endl;
        cout << " 1. Run away." << endl; }
        else { cout << "you decided to wait for people but anybody didn't come to you. Finally, you died by wildanimals." << endl;
	       cout << "Game over"  << endl;
               life = life -1;
               cout << "\033[30;41m life :" << life;
	       cout << "\033[0m";
               cout << endl;
               cout << "you revive. Finally, you find a the village of cannabals. Village people don't think you are a good person." << endl;
               cout << "0. Fight with people." << endl;
               cout << "1. Run away." << endl; }
        path = rand()%2; 
        if (path == 0) { 
	cout << "You chose path 0" << endl;
	cout << "You are strong guy, so you won all of them. After all, they want to obey you as a king." << endl;
        cout << "0. Be a king" << endl;
        cout << "1. Just be a friend and then get information about Kevin Hart." << endl; } 
        else { cout << "you decided to run away from village, but you lost way again and you died by starving." << endl;
               cout << "Game over" << endl;
               life = life -1;
	       cout << "\033[30;41m life :" << life;
               cout << "\033[0m";
               cout << endl;
               cout << "you revive. you decided to fight with them." << endl;
               cout << "You are strong guy, so you won all of them. After all, they want to obey you as a king." << endl;
	       cout << "0. Be a king" << endl;
               cout << "1. Just be a friend and then get information about Kevin Hart." << endl;  }
        path = rand()%2;
        if (path == 1) { 
	cout << "You chose path 1" << endl;
	cout << "They welcome to be friend. They give a map and then teach the place where is Kenvin Hart." << endl;
        cout << "0. Go to the place." << endl;
        cout << "1. Don't trust them, just go to my way." << endl;}
        else { cout << " Be a king of the cannibals!!  However,you were assassinated when you were sleeping." << endl;
               cout << "Game over" << endl;
               life = life-1;
	       cout << "\033[30;41m life :" << life;
	       cout << "\033[0m";
               cout << endl; 
             if (life == 0) { return 0; }
	       cout << "you revive. you decided to throw away the crown and then be a friend. They welcome to be friend. They give a map and ten teach the place where is Kevin Hart." << endl;
	       cout << "0. Go the place." << endl;
	       cout << "1. Don't trust them, just go to my way." << endl; }
        path = rand()%2 ;
        if (path == 0) {
	cout << "You chose path 0" << endl; 
	cout << "you find a big diamond on way to the place. What should I do next? " << endl;
        cout << "0. Get it!" << endl;
        cout << "1. ignore and keep going." << endl;}
        else { cout << "just go to my way but you are trapped and then died by bleeding." << endl;
               cout << "Game over" << endl;
               life = life-1;
	       cout << "\033[30;41m life :" << life;
               cout << "\033[0m"; 
               cout << endl;
             if (life == 0) { return 0; }
	       cout << "you revive. you decided to trust them. you find a big diamond on way to the place. What should I don next? " << endl;
	       cout << "0. Get it!" << endl;
	       cout << "1. ignore and keep going." << endl; }
        path = rand()%2;
        if (path == 1) { 
	cout << "You chose path 1" << endl;
	cout << "Walking about 1 hour, meet Kevin Hart finally." << endl;
        cout << "Mission Complete !!" << endl; } 
        else { cout << "It was a bomb has shape of diamond. The bomb blew out the area and you died." << endl;
               cout << "the bomb is really strong, so real Game over" << endl;
             if (life == 0) { return 0;} }
 return 0; }                      
