#include <iostream>
#include <string>

const int boardSize = 9;
const int empty = 0;

//create board
int board[boardSize][boardSize] = {{0, 0, 0,  7, 0, 0,  0, 0, 1},
				   {0, 0, 1,  0, 0, 0,  0, 2, 0}, 
				   {8, 0, 0,  0, 0, 2,  0, 0, 0},
				   {0, 0, 0,  4, 0, 0,  0, 1, 0},
				   {6, 0, 2,  0, 0, 0,  0, 0, 5},
				   {0, 0, 0,  0, 1, 0,  0, 3, 0},
				   {0, 6, 0,  5, 0, 0,  0, 0, 0},
				   {9, 0, 0,  0, 7, 0,  3, 0, 0},
				   {0, 5, 0,  9, 0, 0,  0, 0, 2},
				  }; 
int originalBoard[boardSize][boardSize];

/*
 * copies from boarda to the original board
 */
void copy() {
	for(int r = 0; r < boardSize; ++r) {
		for(int c= 0; c < boardSize; ++c) {
			originalBoard[r][c] = board[r][c];
		}
	}
}

/*
 * This function prints the board.
 * Each cell is a zero (for empty) or the value 1 to 9
 * Each cell is separated by a space
 * No Space At end of row.
 */
void printBoard() {
	for(int r = 0; r < boardSize; ++r) {
		if(r % 3 == 0) {
			std::cout << "------+-------+------" << std::endl;
		}
		for(int c = 0; c < boardSize; ++c) {
			if((c % 9) != 0 && (c % 9) % 3 == 0) {
				std::cout << " |";
			}
			if(c > 0) {
				std::cout << " ";
			}
			std::cout << board[r][c];
		}
		std::cout << std::endl;
	}
	std::cout << "------+-------+------" << std::endl << std::endl;

}

/*
 * This function sets any value different then 0 as a true value
 * if (any value == 0) 
 * 	then: it can be changed
 * 	if not: it already contains a number and cannot by changed
 */
bool fixedValues(int row, int column) {
	if(board[(row - 1)][(column - 1)] == empty) {
		return false;
	}
	else {
		return true;
	}
}

/*
 * This function cheks if any value is repeated in row
 * When new value is set in a coordinate
 * then: the function will look if a similar already exists
 * if (new value == existing row value) -> error
 * if not: new value can be written
 */
bool checkRow(int row, int number) {
	int n;
	for(int c = 0; c < boardSize; ++c) {
		n = board[(row - 1)][c];
		if(n == number) {
			return true;
		}
	}
	return false;
}

/*
 * This function cheks if any value is repeated in column
 * When new value is set in a coordinate
 * then: the function will look if a similar already exists
 * if (new value == existing column value) -> error
 * if not: new value can be written
 */
bool checkColumn(int column, int number) {
	int n;
	for(int r = 0; r < boardSize; ++r) {
		n = board[r][(column - 1)];
		if(number == n) {
			return true;
		}
	}
	return false;
}

/*
 * This function checks  if any value is repeated in the 3x3 box
 * the function transform the coordinates of row and column into a box by dividing it by 3
 * once divided dhe column it will set the grid in 3 areas as so |0|1|3|
 * one divided the row it will set the grid in 3 areas horizontally 0
 * 								   ---
 * 								    1
 * 								   ---
 * 								    3
 * the for loop will search for equal values inside the box
 * if(new value == to any int box)
 * 	then: show error
 */ 								    
bool checkBox(int row, int column, int number) {
	int boxRow,boxColumn;
	if((row -1)/3 == 0) {
		boxRow = 0;
	}
	else if((row - 1)/3 == 1) {
		boxRow = 3;
	}
	else {
		boxRow = 6;
	}
	if((column - 1)/3 == 0){
		boxColumn = 0;
	}
	else if((column - 1)/3 == 1){
		boxColumn = 3;
	}
	else {
		boxColumn= 6;
	}
	for(int r = boxRow; r<(boxRow + 3); ++r) {
		for(int c = boxColumn; c < (boxColumn + 3); ++c) {
			if(board[r][c] == number) {
				std::cout << "Error: Same number is 3x3 box." << std::endl;
				return true;
			}
		}
	}
	return false;
}

/*
 * This function uses a copy of the original board, and uses it to check for0 values
 * if the original board contains a value different from 0 in the desired coordinate to change
 * then: is a true value and it cannot be changed
 * any value represented with a 0 in the original board, can be erased(changing the agin to 0
 */
bool erase(int row, int column) {
	if(originalBoard[(row - 1)][(column - 1)] == empty ) {
		return false;
	}
	else {
		return true;
	}
}

/*
 * main program 
 */
int main() {
	int count = 0; //if count = 60 -> (81-21) the : Win!
	int row, column, number;

	copy();

	std::cout << "Welcome to the Game of  Sudoku" << std::endl;

	std::string userChoice = "";
	do {
		std::cout << "What would you like to do (print -> p, write -> w, erase -> e, quit -> q): ";
		std::cin >>userChoice;

		if(userChoice == "p") {
			printBoard();
			continue;
		}
		if(userChoice == "w") {
			std::cout << "Input Row: " << std::endl;
			std::cin >>row;
			std::cout << "Input Column: " << std::endl;
			std::cin >>column;
			std::cout << "Input Number: " << std::endl;
			std::cin >>number;
			std::cout << std::endl;
			while((number > 9) || (number < 1)){
				std::cout << "Please enter a number from 1 to 9 " << std::endl;
				std::cin >>number;
			}

			if(fixedValues(row, column) == false && checkRow(row, number) == false && checkColumn(column, number) == false && checkBox(row, column, number) == false) {
				if(board[(row - 1)][(column - 1)] == empty) {
					count++;
				}

				board[(row - 1)][(column - 1)] = number;
				printBoard();
			}
			if(count == 60 ) {
				std::cout << "Win!!!!!!" << std::endl;
				userChoice = "q";
			}
			continue;
		}
		if(userChoice == "e") {
			std::cout << "Input Row: " << std::endl;
			std::cin >>row;
			std::cout << "Input Column: " << std::endl;
			std::cin >>column;

			if(erase(row, column) == false) {
				board[(row - 1)][(column - 1)] = empty;
				count--;
				printBoard();
			}
			else {
				std::cout << "Error: trying to erase a fixed number. " << std::endl;
			}
			continue;
			
		}
	}while(userChoice != "q");
	
	std::cout << "\nThanks for playing our game, have a great day!" << std::endl;
	
	return 0;

}
