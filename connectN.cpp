#include <iostream>
#include<string>

using namespace std;
string stringconverter(int dig) { 
	// converting an integer to  string like a orignally an intger but string 

	string strNumber = to_string(dig); 
	return strNumber;
}
bool Retake(string ar[5][5], int index) {
	// Ensure proper bounds checking and logic for validating the index
	if (index >= 1 && index <= 16) {
		int row = (index - 1) / 4;
		int col = (index - 1) % 4;

		return ar[row][col] != " "; // Return true if position is taken
	}
	return true; // Invalid index, considered as taken
}






// functionality to put players Sign like cross or zero
void Put(string ar[5][5], int index , int turn) {
	if (index>=1 && index<5  ) {
		if (turn == 1) {
			ar[0][index-1] = "X";

		}
		else {
			ar[0][index-1] = "O";

		}
	}
	else if (index >= 5 && index < 9) {
		if (index % 4 == 0) {

			if (turn == 1) {
				ar[1][3] = "X";

			}
			else {
				ar[1][3] = "O";

			}

		}
		else {
			int cont = (index % 4)-1;
			if (turn == 1) {
				ar[1][cont] = "X";

			}
			else {
				ar[1][cont] = "O";

			}

		}
	}
	else if (index >= 9 && index < 13) {
		
		if (index % 4 == 0) {

			if (turn == 1) {
				ar[2][3] = "X";

			}
			else {
				ar[2][3] = "O";

			}
		}
		else {
			int cont1 = (index % 4)-1;
			if (turn == 1) {
				ar[2][cont1] = "X";

			}
			else {
				ar[2][cont1] = "O";

			}

		}
	}
	else if (index >= 13 && index < 17) {
		
		if (index % 4 == 0) {

			if (turn == 1) {
				ar[3][3] = "X";

			}
			else {
				ar[3][3] = "O";

			}
		}
		else {
			int cont1 = (index % 4)-1;
			if (turn == 1) {
				ar[3][cont1] = "X";

			}
			else {
				ar[3][cont1] = "O";

			}

		}
	}

}

void Checker(string ar[5][5], int digit, int turn) {
	// this function takes the user input the digit index,
	// and at the top string converter compares at the checking array index is it the
	// like 9 stringconverter make it "9" now it is checked in new array that
	// check in backend whether this one or othr
	// given digit and turn checks which players turn is it

	for (int j = 0; j <= 3; j++)
	{
		for (int k = 0; k <= 3; k++)
		{
			if (ar[j][k] == stringconverter(digit)) {
				if (turn == 1) {
					ar[j][k] = "X";
				}
				else {
					ar[j][k] = "O";
				}
			}


		}

	}
}

bool WinORElse(string ar[5][5], string turn) {
	int yes = 0;

	// Check rows and columns for a win
	for (int i = 0; i < 3; i++) {
		if ((ar[i][0] == ar[i][1]) && (ar[i][1] == ar[i][2]) && (ar[i][2] == ar[i][3]) && ar[i][0] != "") {
			cout << "--------------------------------------" << turn << " Wins by row "<<i+1 << "-----------------------------------------------------------" << endl;

			return true;
		}
		if ((ar[0][i] == ar[1][i]) && (ar[1][i] == ar[2][i])&&(ar[2][i] == ar[3][i]) && ar[0][i] != "") {
			cout << "--------------------------------------" << turn << " Wins by Column "<<i+1 << "-----------------------------------------------------------" << endl;

			return true;
		}
	}

	// Check diagonals for a win
	if ((ar[0][0] == ar[1][1]) && (ar[1][1] == ar[2][2] &&(ar[2][2] == ar[3][3]) && ar[0][0] != "")) {
		cout << "--------------------------------------" << turn << " Wins by diagonal" << "-----------------------------------------------------------" << endl;

		return true;
	}
	if ((ar[3][0] == ar[2][1]) && (ar[2][1] == ar[1][2]) &&( ar[1][2] == ar[0][3]) && ar[3][0] != "") {
		cout << "--------------------------------------" << turn << " Wins by diagonal" << "-----------------------------------------------------------" << endl;

		return true;
	}
	
	return false;
}

void PrintARRAY(string space[5][5]) {
	// printing paatern of array:
	cout << endl;
	cout << "		|		|		|		\n";
	cout << "		|		|		|		\n";
	cout << "	" << space[0][0] << "	|	" << space[0][1] << "	|	" << space[0][2] << "	|	" << space[0][3] <<"  \n";
	cout << "		|		|		|		\n";
	cout << "________________|_______________|_______________|_______________\n";
	cout << "		|		|		|		\n";
	cout << "		|		|		|		\n";
	cout << "	" << space[1][0] << "	|	" << space[1][1] << "	|	" << space[1][2] << "	|	" << space[1][3] << "  \n";
	cout << "		|		|		|		\n";
	cout << "		|		|		|		\n";
	cout << "________________|_______________|_______________|_______________\n";
	cout << "		|		|		|		\n";
	cout << "		|		|		|		\n";
	cout << "	" << space[2][0] << "	|	" << space[2][1] << "	|	" << space[2][2] << "	|	" << space[2][3] << "  \n";
	cout << "		|		|		|		\n";
	cout << "		|		|		|		\n";
	cout << "________________|_______________|_______________|_______________\n";

	cout << "		|		|		|		\n";
	cout << "	" << space[3][0] << "	|	" << space[3][1] << "	|	" << space[3][2] << "	|	" << space[3][3] << "  \n";

	cout << endl;
}

int main() {

	// arrays for structure like 4 by 4 matrix
			// with index  like row with column number
				// for 4x4 0-3 rows and 0-3 cols
	//int space[3][3] = { { 00,01,02},{10,11,12},{20,21,22} };
	string space[5][5] ;

	string ONGOING[5][5] = { {"1","2","3","4"} ,{"5","6","7","8"},{"9","10","11","12"},{"13","14","15","16"}};
	
	string EmpCheck[5][5] = { {" "," "," "," "} ,{" "," "," "," "},{" "," "," "," "},{" "," "," "," "} };
	// we made these string array therefore the string converter to convert them to 
	

	

	//players names Input
	string n1; 
	string n2;
	cout << "Enter Name of Player 1 : ";
	getline(cin, n1);
	cout << endl;
	cout << "Enter Name of Player 2 : ";
	getline(cin, n2);//getting inputs
	cout << endl;
	cout << n1 << " will play first \n"; // show names of players
	cout << n2 << " will play second \n";
	cout << endl;
	
	
	// Value assigning : in empty array just numbering the indexSpace
	int initVAL = 1;
	for (int j = 0; j <=3; j++)
	{
		for (int k = 0; k <= 3; k++)
		{
			space[j][k] = stringconverter(initVAL++);
		}

	}
	PrintARRAY(space);

	// Taking inputs and giving turn

	int digit;
	int taken = 1;
	while(taken<=16)
	{
		if (taken % 2==0) {
			// we will give 1st turn to P1 so every even will be of P2 :)
			int turn = 2;
			string player = n2;
			cout << " --> " <<n2 << " turn " << endl;
			cout << "Enter index : ";
			cin >> digit;
			//taking digit for placement
			
			
			if (digit > 16) {
				
				//as above function checks is the provided index empty
				
				cout << " Invalid Input : Please input according to Matrix .";
				cin >> digit;
				

				
				if (Retake(EmpCheck, digit)) {
					cout << " Invalid : already taken enter the available one" << endl;
					cin >> digit;
				}
				
				Put(ONGOING, digit, turn);
				Put(EmpCheck, digit, turn);
				Checker(space, digit,turn);
				WinORElse(ONGOING,player);
				bool x = WinORElse(ONGOING,player);
				PrintARRAY(space);		
				if (WinORElse) {
					break;
				}
			}
			else {
				
				//as above function checks is the provided index empty
				if (Retake(EmpCheck, digit)) {
					cout << " Invalid : already taken enter the available one" << endl;
					cin >> digit;
					

				}
				Put(ONGOING, digit, turn);
				Put(EmpCheck, digit, turn);
				Checker(space, digit, turn);
				WinORElse(ONGOING,player);
				PrintARRAY(space);
				bool x = WinORElse(ONGOING, player);
				if (x) {
					break;
				}
			}


		}
		else {/////////////P1
			//similar steps but for P1
			cout << endl;
			cout<<" --> " << n1 << "  turn " << endl;
			int turn1 = 1;
			string player1 = n1;

			cout << "Enter index : ";

			cin >> digit;
			

			
			
			if (digit > 16) {
				cout << " Invalid Input : Please input according to Matrix .";
				cin >> digit;
				

				
				if (Retake(EmpCheck, digit)) {
					cout << " Invalid : already taken enter the available one" << endl;
					cin >> digit;
				}
				Put(ONGOING, digit, turn1);
				Put(EmpCheck, digit, turn1);
				Checker(space, digit, turn1);
				WinORElse(ONGOING,player1);
				
				PrintARRAY(space);
				bool x = WinORElse(ONGOING, player1);
				if (x) {
					break;
				}

			}
			else {
				
				if (Retake(EmpCheck, digit)) {
					cout << " Invalid : already taken enter the available one" << endl;
					cin >> digit;
					

				}
				Put(ONGOING, digit, turn1);
				Put(EmpCheck, digit, turn1);
				Checker(space, digit, turn1);
				WinORElse(ONGOING,player1);
				PrintARRAY(space);
				bool x = WinORElse(ONGOING, player1);
				if (x) {
					break;
				}

			}
		}
		taken++;
	}
	
	
	

	// sketching the table matrix & adding the input by user

	PrintARRAY(space);

	return 0;
}