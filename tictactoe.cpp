/*
Name: Jayden Huang
Date: 10/22/2021
Description: Text-based two-player Tic Tac Toe game 
 */
//Header files
#include <iostream>
#include <cstring>
using namespace std;
struct boardstate {
  //The struct could use some more variables but these are the only necessary ones
  int tictactoeboard[3][3];
  bool win;
};
void printBoard(struct boardstate newboard);
bool checkWin(struct boardstate newboard);
int main() {
  //Variables!
  struct boardstate newboard;
  int movex = 0;
  int movey = 0;
  int tiecheck = 0;
  char endgameinput[2];
  int testcounter = 0;
  bool running = true;
  bool win;
  bool tie;
  newboard.win = false;
  int Xwins = 0;
  int Owins = 0;
  bool Oturn = false;
  bool validmove = false;
  int movechoicecounter;
  char movechoice[3];
  //Setting the board
  for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            newboard.tictactoeboard[i][j] = 0;
        }
    }
  printBoard(newboard);
  while(running == true) {
    //Could just define tiecheck in the while loop but this method is more appealing
    tiecheck = 0;
    //User interaction cout
    if(Oturn == true) {
      cout << "\nIt is the O player's turn, please make your move\n";
    }
    if(Oturn == false) {
      cout << "It is the X player's turn, please make your move\n";
    }
    cout << "Enter the space that you want to make your move on: ";
    cin >> movechoice;
    movechoicecounter = strlen(movechoice);
    if(movechoicecounter == 2) { 
      validmove = true;
    }
    else {
      cout << "Error" << endl;
      continue;
    }
    //Converting the string input into something readable by the array
    if(movechoice[0] == 'a' || movechoice[0] == 'b' || movechoice[0] == 'c') {  
      validmove = true;
    }
    else {
      cout << "Error" << endl;
      continue;
    }
    if(movechoice[1] == '1' || movechoice[1] == '2' || movechoice[1] == '3') {
      validmove = true;
    }
    else {
      cout << "Error" << endl;
      continue;
    }
    if(movechoice[0] == 'a') {
      movex = 0;
    }
    if(movechoice[0] == 'b') {
      movex = 1;
    }
    if(movechoice[0] == 'c') {
      movex = 2;
    }
    movey = (int)movechoice[1] - 49;
    //Placing the move, the x and y are reversed due to oversight when writing the code
    if(Oturn == true && newboard.tictactoeboard[movey][movex] == 0) {
      newboard.tictactoeboard[movey][movex] = 1;
      Oturn = false;
    }
    else if(Oturn == false && newboard.tictactoeboard[movey][movex] == 0) {
      newboard.tictactoeboard[movey][movex] = 2;
      Oturn = true;
    }
    else {
      cout << "Error" << endl;
    }
    printBoard(newboard);
    win = checkWin(newboard);
    //Due to the way the code was originally written, O wins when Oturn is equal to false because the turn changes immediatley after the move
    if(win == true && Oturn == false) {
      cout << "O wins!" << endl;
      Owins++;
      cout << "O has won ";
      cout << Owins;
      cout << " times" << endl;
      cout << "Do you want to play again? Enter y for yes and n for no" << endl;
      cin >> endgameinput;
      if(endgameinput[0] == 'y') {
	Oturn = false;
	for(int i = 0; i < 3; i++) {
	  for(int j = 0; j < 3; j++) {
	    newboard.tictactoeboard[i][j] = 0;
	  }
        }
	printBoard(newboard);
      }
      else{
	cout << "Thank you for playing!";
	running = false;
      }
      
      
    }
    //X win, it checks if Oturn is equal to true because the turn switches as the array is updated
    if(win == true && Oturn == true) {
      cout << "X wins!" << endl;
      Xwins++;
      cout << "X has won ";
      cout << Xwins;
      cout << " times" << endl;
      cout << "Do you want to play again? Enter y for yes, and any other input for no" << endl;
      cin >> endgameinput;
      if(endgameinput[0] == 'y') {
        Oturn = false;
	for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                newboard.tictactoeboard[i][j] = 0;
            }
        }
	printBoard(newboard);
      }
      else {
	cout << "Thanks for playing!";
	running = false;
      }
    }
    //Checking for tie
    for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
	      if(newboard.tictactoeboard[i][j] != 0) {
		tiecheck++;
	      }
            }
        }
    //Tie case
    if(tiecheck == 9) {
      cout << "The game ended in a tie!" << endl;
      cout << "Do you want to play again? Enter y for yes,and any other input for no" << endl;
      cin >> endgameinput;
      if(endgameinput[0] == 'y') {
        Oturn = false;
	for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                newboard.tictactoeboard[i][j] = 0;
            }
        }
	printBoard(newboard);
      }
      else {
	cout << "Thanks for playing!";
	running = false;
      }
    }
  }
  
  
}
void printBoard(struct boardstate newboard) {
    cout << "  a b c\n";
    cout << "1 ";
    
    for(int m = 0 ; m < 3 ; m++) {
       if(newboard.tictactoeboard[0][m] == 0) {
	 cout << "t ";
	}
       if(newboard.tictactoeboard[0][m] == 1) {
	 cout << "o ";
       }
       if(newboard.tictactoeboard[0][m] == 2) {
	 cout << "x ";
       }
      }
    cout << "\n2 ";
    for(int f = 0 ; f < 3 ; f++) {
       if(newboard.tictactoeboard[1][f] == 0) {
	 cout << "t ";
	}
       if(newboard.tictactoeboard[1][f] == 1) {
	 cout << "o ";
       }
       if(newboard.tictactoeboard[1][f] == 2) {
	 cout << "x ";
       }
      }
    cout << "\n3 ";
    for(int d = 0 ; d < 3 ; d++) {
       if(newboard.tictactoeboard[2][d] == 0) {
	 cout << "t ";
	}
       if(newboard.tictactoeboard[2][d] == 1) {
	 cout << "o ";
       }
       if(newboard.tictactoeboard[2][d] == 2) {
	 cout << "x ";
       }
      }
    cout << endl;
  }
bool checkWin(struct boardstate newboard) {
  for(int i = 1; i <3 ; i++) {
    //Diagonals
    if(newboard.tictactoeboard[0][0] == i && newboard.tictactoeboard[1][1] == i && newboard.tictactoeboard[2][2] == i){
       return true;
    }
    if(newboard.tictactoeboard[2][0] == i && newboard.tictactoeboard[1][1] == i && newboard.tictactoeboard[0][2] == i){
       return true;
    }
    //Left column
    if(newboard.tictactoeboard[0][0] == i && newboard.tictactoeboard[1][0] == i && newboard.tictactoeboard[2][0] == i){
       return true;
    }
    //Middle column
    if(newboard.tictactoeboard[0][1] == i && newboard.tictactoeboard[1][1] == i && newboard.tictactoeboard[2][1] == i){
       return true;
    }
    //Right column
    if(newboard.tictactoeboard[0][2] == i && newboard.tictactoeboard[1][2] == i && newboard.tictactoeboard[2][2] == i){
       return true;
    }
    //Top row
    if(newboard.tictactoeboard[0][0] == i && newboard.tictactoeboard[0][1] == i && newboard.tictactoeboard[0][2] == i){
       return true;
    }
    //Middle row
    if(newboard.tictactoeboard[1][0] == i && newboard.tictactoeboard[1][1] == i && newboard.tictactoeboard[1][2] == i){
       return true;
    }
    //Bottom row
    if(newboard.tictactoeboard[2][0] == i && newboard.tictactoeboard[2][1] == i && newboard.tictactoeboard[2][2] == i){
       return true;
    }
    
    
  }
  return false;
  
  
  
}


