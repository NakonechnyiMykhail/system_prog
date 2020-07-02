// hw6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>


int GetInteger(std::string category) {
	/*
	Funtion:    print category and check inputting varieble for correct data
	Get:        integer varieble from user
	Return:     int
	*/
	int number{ 0 };
	while (true)
	{
		std::cout << "\nEnter your " << category << ": ";
		std::cin >> number;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			continue;
		}
		// our data shoul be Non-zero
		if (number <= 0) { continue; }

		// board boundary
		if (number < 1 || number > 8) { 
			std::cout << "You get out of board boundary! Try again! (1-8)\n"; 
			continue; 
		}

		break;
	}
	return number;
}

int GetBoardCoordinate(std::string category) {

	char ch = { 0 };

	while (true)
	{
		std::cout << "\nEnter your " << category << ": ";
		std::cin >> ch;

		if (ch == 'a' || ch == 'A' ||
			ch == 'b' || ch == 'B' ||
			ch == 'c' || ch == 'C' ||
			ch == 'd' || ch == 'D' ||
			ch == 'e' || ch == 'E' ||
			ch == 'f' || ch == 'F' ||
			ch == 'g' || ch == 'G' ||
			ch == 'h' || ch == 'H') {
			
			//return ch;
			switch (ch) {
				case 'a':
				case 'A':
					return 1;
				case 'b':
				case 'B':
					return 2;
				case 'c':
				case 'C':
					return 3;
				case 'd':
				case 'D':
					return 4;
				case 'e':
				case 'E':
					return 5;
				case 'f':
				case 'F':
					return 6;
				case 'g':
				case 'G':
					return 7;
				case 'h':
				case 'H':
					return 8;
			}
		}
		else { 
			std::cout << "You get out of board boundary! Try again! (a-h)\n";
			continue; 
		}
	}
}

std::map<int, int> PossibleMoves(int x1, int y1)
{
	std::map<int, int> moves;
	return moves;
}

bool CheckMove(int **board, int boardLenght, int figure, int x1, int y1, int x2, int y2) {
	bool check = false;
	std::map<int, int> possibleMoves;
	switch (figure)
	{
	case 1:// King
		break;
	case 2:// Queen
		break;
	case 3:// Rooks
		break;
	case 4://Bishops
		break;
	case 5:// Knights
	{
		std::cout << "Knight moves from : " << x1 << "-" << y1 << " to: " << x2 << "-" << y2 << std::endl;
		
		if (((x1 - x2) == 1 && ((y1 - y2) == 2 || (y2 - y1) == 2)) ||
			((x2 - x1) == 1 && ((y1 - y2) == 2 || (y2 - y1) == 2)) ||
			((x1 - x2) == 2 && ((y1 - y2) == 1 || (y2 - y1) == 1)) ||
			((x2 - x1) == 2 && ((y1 - y2) == 1 || (y2 - y1) == 1))) {
			check = true;
			return check;
		}
		//
		/*for (size_t i = 1; i <= boardLenght; i++)
		{
			for (size_t j = 1; j <= boardLenght; j++)
			{
				if (isSpaceFree(board[i][i])) {
					possibleMoves[i] = j;
				}
			}
		}*/
	}
	case 6:
		break;

	default:
		break;
	}

	return false;
}

void MakeMove(bool check) {
	std::cout << "Move is \"" << std::boolalpha << check << "\"\n";
}

int main()
{
	const int chessLength = 8;
	//int chessBoard[chessLength][chessLength] = { {} };
    //{   {0,0,0,0,0,0,0,0},
    //    {0,0,0,0,0,0,0,0},
    //    {0,0,0,0,0,0,0,0},
    //    {0,0,0,0,0,0,0,0},
    //    {0,0,0,0,0,0,0,0},
    //    {0,0,0,0,0,0,0,0},
    //    {0,0,0,0,0,0,0,0},
    //    {0,0,0,0,0,0,0,0},
    //}; //a,b,c,d,e,f,g,h 

	 int **chessBoard = new int*[chessLength];
	 for (size_t i = 0; i < chessLength; ++i) {
		 chessBoard[i] = new int[chessLength];
	 }

	std::map<std::string, int> figures;
	figures["King"]		= 1;
	figures["Queen"]	= 2;
	figures["Rooks"]	= 3;
	figures["Bishops"]	= 4;
	figures["Knights"]	= 5;
	figures["Pawns"]	= 6;


	while (true)
	{
		int x1 = { 0 }, x2 = { 0 }, y1 = { 0 }, y2 = { 0 };
		x1 = GetBoardCoordinate("'x1' coordinate");
		y1 = GetInteger("'y1' coordinate");

		x2 = GetBoardCoordinate("'x2' coordinate");
		y2 = GetInteger("'y2' coordinate");
		MakeMove(CheckMove(chessBoard, chessLength, figures["Knights"], x1, y1, x2, y2));
		std::cout << "Try move again? (0-no/1-yes):";
		int again = GetInteger("choice");
		if (again != 1) { break; }
	}

    return 0;
}


