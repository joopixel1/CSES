#include <iostream>
using namespace std;

const int SIZE = 9;
const int PATH_LEN = 48;  // length of all possible paths
bool rarr[SIZE][SIZE];
string barr;


int tryPath(int row, int col, int count) {

    if (row==7 && col==1){
        if (count==PATH_LEN) return 1;
        else return 0;
    }
    else if (count==PATH_LEN)
        return 0;
    else if (rarr[row][col])
        return 0;


    //1st optimization Case 010
    else if (rarr[row - 1][col] && rarr[row + 1][col] && !rarr[row][col - 1] && !rarr[row][col + 1])
        return 0;
    else if (rarr[row][col - 1] && rarr[row][col + 1] && !rarr[row - 1][col] && !rarr[row + 1][col])
        return 0;


    //2nd optimization Case 10
    //######################01
    else if (rarr[row - 1][col + 1] && !rarr[row - 1][col] && !rarr[row][col + 1]) 
    	return 0;
	else if (rarr[row + 1][col + 1] && !rarr[row + 1][col] && !rarr[row][col + 1]) 
       	return 0;
    else if (rarr[row - 1][col - 1] && !rarr[row - 1][col] && !rarr[row][col - 1]) 
    	return 0;
    else if (rarr[row + 1][col - 1] && !rarr[row + 1][col] && !rarr[row][col - 1]) 
    	return 0;
    

    
    else{
        
        int sol = 0;
        rarr[row][col] = true;

        if (barr[count] == '?'){
        	sol+= tryPath(row+1, col, count+1); //DOWN
            sol+= tryPath(row-1, col, count+1); //UP
            sol+= tryPath(row, col+1, count+1); //RIGHT
            sol+= tryPath(row, col-1, count+1); //LEFT
        }

        else if (barr[count] == 'D') sol= tryPath(row+1, col, count+1); //DOWN
        else if (barr[count] == 'U') sol= tryPath(row-1, col, count+1); //UP
        else if (barr[count] == 'R') sol= tryPath(row, col+1, count+1); //RIGHT
        else if (barr[count] == 'L') sol= tryPath(row, col-1, count+1); //LEFT

        rarr[row][col] = false;   
        return sol;
    }
}


int main() {

    getline(cin, barr);
    
    

    // set borders of grid
	for (int i = 0; i < SIZE; i++) {
		rarr[0][i] = true;
		rarr[8][i] = true;
		rarr[i][0] = true;
		rarr[i][8] = true;
	}
	// initialize the inside of the grid to be completely empty
    for (int row = 1; row <= 7; row++) {
        for (int col = 1; col <= 7; col++) {
            rarr[row][col] = false;
        }
    }


    cout << tryPath(1, 1, 0) << endl;


    return 0;
}