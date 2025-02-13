#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;
namespace MyNumLib {


	int ReadNumber(string Message) {
		int Number;
		
		
		cout << Message;
		cin >> Number;

		return Number;

	}


	int RandomNumber(int From, int To)
	{
		int readran = rand() % (To - From + 1) + From;




		return (readran);




	}



	void FillMatrixWithRandom(int arr[3][3] , int Row , int Col) {




		for (int i = 0; i < Row; i++) {
			for (int j = 0; j < Col; j++) {
				arr[i][j] = RandomNumber(1, 100);

			}



		}

	}



	void PrintMatrix(int arr[3][3] , int Row , int Col) {



		for (int i = 0; i < Row; i++) {
			for (int j = 0; j < Col; j++) {

				cout << setw(3) << arr[i][j] << "       ";

			}
			cout << endl;


		}


	}








	int ReadPositiveNumber()
	{
		string Message = " Please enter a postive number \n ";
		cout << Message;
		float number;
		cin >> number;

		while (cin.fail()) {

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Number, Enter a valid one:" << endl;
			cin >> number;

		}
		while (number < 0) {



			cout << Message << endl;
			cin >> number;



		}

		return number;
	}

	float ReadNumberInRange(string Message, int From, int To)
	{


		int number;
		do {
			
			cout << Message << endl;
			cin >> number;
		} while (number < From && number > To);

		return number;

	}




	void MinNumberMatrix(int arr[3][3], short Row, short Col) {



		int number = arr[0][0];


		for (int i = 0; i < Row; i++) {
			for (int j = 0; j < Col; j++) {



				if (number > arr[i][j]) {
					number = number = arr[i][j];
				}



			}





		}
		cout << number;



	}

	void MaxNumberMatrix(int arr[3][3], short Row, short Col) {


		int number = arr[0][0];


		for (int i = 0; i < Row; i++) {
			for (int j = 0; j < Col; j++) {



				if (number < arr[i][j]) {
					number = number = arr[i][j];
				}



			}





		}
		cout << number;





	}




	string ReadString() {
		string st;
		cout << " Enter Your String? ";
		getline(cin, st);
		return st;
	}



	string UpperString(string st) {


		for (int i = 0; i < st.length(); i++) {

			st[i] = toupper(st[i]);


		}

		return st;

	}



	string LowerString(string st) {

		for (int i = 0; i < st.length(); i++) {

			st[i] = tolower(st[i]);


		}

		return st;




	}


	char ReadChar() {
		char C;
		cout << " Please Enter a Char?\n";
		cin >> C;
		return C;
	}



	char InvertChar(char C) {


		return isupper(C) ? tolower(C) : toupper(C);

	}


	string InvertAllLetters(string st) {

		for (int i = 0; i <= st.length(); i++) {
			st[i] = InvertChar(st[i]);
		}
		return st;

	}



	short CharCounter(string st, char c) {

		short Counter = 0;

		for (int i = 0; i <= st.length(); i++) {
			if (st[i] == c) {
				Counter++;
			}
		}

		return Counter;

	}


	string CharCounter2x(string st, char c) {

		if (islower(c)) {
			st = LowerString(st);
			return st;

		}
		else if (isupper(c)) {
			st = UpperString(st);
			return st;


		}


	}


	vector <string> SplitString(string st, string delim) {

		vector<string> Split;
		short pos = 0;
		string sWord;
		short counter = 0;
		while ((pos = st.find(delim)) != std::string::npos) {
			sWord = st.substr(0, pos);
			if (sWord != "") {
				Split.push_back(sWord);
			}

			st.erase(0, pos + delim.length());

		}
		if (st != "") {
			Split.push_back(st);
		}

		return Split;

	}






}







