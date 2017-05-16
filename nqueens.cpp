#include<iostream>
using namespace std;


// To check if the position can be attacked or not.
bool isAttacked(int x, int y, int **board, int n)
{
	int i = 0;
	int j = 0;
	for(i=0;i<n;i++){
		if(board[x][i] == 1 && i != y){
			return true;
		}
		if(board[i][y] == 1 && i != x){
			return true;
		}
	}
	for(i=0; i<n;i++){
		for (int j = 0; j < n; j++){
			if ( ((i + j) == (x + y)) || ((i - j) == (x - y)) ) {
				if (((i != x) || (j != y)) && (board[i][j] == 1)) {
					return true;
				}
			}
		}
		
	}
	return false;
}

//Function to print the board.
int printBoard(int **board, int n){
	int i;
	int j;
	for(i = 0;i<n ;i++){
		for(j = 0; j<n ;j++){
			cout << " " << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

//This solution is implemented by using the concept of back tracking. Here in this function back_tracking is used.
bool nQueens(int **board, int level, int n){
	int j;
	if(level == n){
		return true;
	}
	for(j=0;j<n;j++){
		
		if(isAttacked(level,j,board,n)){
			continue;
		}
		
		board[level][j] = 1;
		if(nQueens(board,level+1,n)){
			return true;
		}
		board[level][j] = 0;
		
	}
	return false;
	
}

//Main function
int main( ){
	int n;
	cout << "Enter the size of the Board: "<< endl;
	cin >> n;
	int **board;
	int i,j;
	board = new int *[n];
	for(i=0;i<n;i++){
		board[i] = new int [n];
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			board[i][j] = 0;
		}
	}
	
	if(nQueens(board,0,n)){
		cout << "YES" << endl;
		printBoard(board,n);
	}
	else{
		cout << "NO";
	}
	delete board;
	return 0;
}
