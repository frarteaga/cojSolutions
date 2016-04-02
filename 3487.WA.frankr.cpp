/*
3487 - Sudoku Solver (112/250)
frankr@coj
compilar con C++11
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> coor;

struct Sudoku{
	int O[9][9]; //Original
	int S[9][9]; //Soved

	bool SQ[3][3][10];//true is present, fase otherwise
	bool Row[9][10]; //true is present, fase otherwise
	bool Col[9][10]; //true is present, fase otherwise

	int totalPut;

	/*
	getSudoku() read from standar input a suduko in format as show below:
* * 1 | * 3 2 | * * 7
6 * 2 | * 8 * | * * 3
7 3 * | 1 9 * | * 5 4
------+-------+------
* * * | 6 * * | * 8 9
* 7 * | 4 * 3 | * 2 *
4 6 * | * * 9 | * * *
------+-------+------
1 9 * | * 5 8 | * 7 2
5 * * | * 6 * | 3 * 8
3 * * | 2 4 * | 1 * *
	*/
	void getSudoku(){
		vector<string> raw_input;
		for (int i = 0 ; i < 11 ; i++){
			string line;
			getline(cin, line);
			raw_input.push_back(line);
		}
		raw_input.erase(raw_input.begin() + 7); //deleting ------+--...
		raw_input.erase(raw_input.begin() + 3);

		//replacing | with ' '
		for (int i = 0 ; i < 9 ; i++)
			for (int j = 3 ; j < raw_input[i].size() ; j++)
				if (raw_input[i][j] == '|')
					raw_input[i][j] = ' ';

		memset(O, 0, sizeof O);
		memset(S, 0, sizeof S);
		for (int i = 0 ; i < 9 ; i++){
			istringstream line(raw_input[i]);
			for (int j = 0 ; j < 9 ; j++){
				string c;
				line >> c;
				if (c[0] != '*')
					O[i][j] = S[i][j] = c[0] - '0';
			}
		}
	} //getSudoku()

	/*
	read a sudoko in format like file:
	/home/frank/.config/gnome-sudoku/puzzles/hard
	*/
	void getSudokoFromSUDOKUGNOMEFormat(){
		for (int i = 0 ; i < 9 ; i++)
			for (int j = 0 ; j < 9 ; j++){
				int x;
				cin >> x;
				O[i][j] = S[i][j] = x;
			}
		double dif;
		cin >> dif;
	}

	void initSets(){
		memset(SQ, false, sizeof SQ);
		memset(Row, false, sizeof Row);
		memset(Col, false, sizeof Col);
		//init single squares:
		totalPut = 0;
		for (int  i = 0 ; i < 3 ; i++)
			for (int j = 0 ; j < 3 ; j++){
				for (int oi = 0 ; oi < 3 ; oi++)
					for (int oj = 0 ; oj < 3 ; oj++){
						int k = O[3 * i + oi][3 * j + oj];
						SQ[i][j][k] = true;
						if (k != 0)
							totalPut++;
					}
			}
		//init rows and cols:
		for (int i = 0 ; i < 9 ; i++)
			for (int j = 0 ; j < 9 ; j++)
				Row[i][O[i][j]] = true;
		for (int j = 0 ; j < 9 ; j++)
			for (int i = 0 ; i < 9 ; i++)
				Col[j][O[i][j]] = true;
	}

	vector<int> lackNumbers(int i, int j){
		vector<int> res;
		for (int k = 1 ; k < 10 ; k++)
			if (!SQ[i][j][k])
				res.push_back(k);
		return res;
	} //lackNumbers()

	vector<coor> getPosibilities(int i, int j, int num){
		vector<coor> res;
		for (int oi = 0 ; oi < 3 ; oi++)
			for (int oj = 0 ; oj < 3 ; oj++){
				int ii = 3 * i + oi;
				int jj = 3 * j + oj;
				if (S[ii][jj] == 0){
					if (!Row[ii][num] && !Col[jj][num])
						res.push_back(coor(ii, jj));
				}
			}
		return res;
	} //getPosibilities()

	void Solve(){
		initSets();

		int pt;
		while (totalPut < 81){
			pt = totalPut;
			for (int i = 0 ; i < 3 ; i++)
				for (int j = 0 ; j < 3 ; j++){
					vector<int> lackNums = lackNumbers(i, j);

					for (auto num : lackNums){
						vector<coor> free = getPosibilities(i, j, num);

						if (free.size() == 1){
							int x = free[0].first;
							int y = free[0].second;
							S[x][y] = num;
							SQ[i][j][num] = true;
							Row[x][num] = true;
							Col[y][num] = true;
							totalPut++;
						}
					}
				}
			if (pt == totalPut)
				break; //error FIXME
		}//while(totalPut < 81)
	}//Solve()

	bool checkIsOk(){
		bool mk[10];
		mk[0] = true;

		for (int  i = 0 ; i < 3 ; i++)
			for (int j = 0 ; j < 3 ; j++){
				memset(mk + 1, 0, 9);
				for (int oi = 0 ; oi < 3 ; oi++)
					for (int oj = 0 ; oj < 3 ; oj++){
						int k = S[3 * i + oi][3 * j + oj];
						if (mk[k])
							return false;
						mk[k] = true;
					}
			}

		for (int i = 0 ; i < 9 ; i++){
			memset(mk + 1, 0, 9);
			for (int j = 0 ; j < 9 ; j++){
				if (mk[S[i][j]])
					return false;
				mk[S[i][j]] = true;
			}
			memset(mk + 1, 0, 9);
			for (int j = 0 ; j < 9 ; j++){
				if (mk[S[j][i]])
					return false;
				mk[S[j][i]] = true;
			}
		}

		return true;
	} //checkIsOk()

	char ch(int x){
		if (x == 0)
			return '*';
		return x + '0';
	}

	void printSolvedSudoku(){
		for (int i = 0 ; i < 9 ; i++){
			if (i == 3 || i == 6)
				cout << "------+-------+------\n";
			cout << ch(S[i][0]);
			for (int j = 1 ; j < 9 ; j++){
				if (j % 3 == 0)
					cout << " |";
				cout << ' ' << ch(S[i][j]);
			}
			cout << endl;
		}
	}
};

int main(){
	/*
	freopen("easy", "r", stdin);

	Sudoku sudoku;

	for (int jd = 0 ; jd < 150 ; jd++){
		sudoku.getSudokoFromSUDOKUGNOMEFormat();

		char sjd[5];
		sprintf(sjd, "%d", jd);
		string ssjd = string(sjd);

		string fn = "sudokus." + ssjd  + ".in";
		freopen(fn.c_str(), "w", stdout);
		sudoku.printSolvedSudoku();
		fclose(stdout);

		fn = "sudokus." + ssjd  + ".out";
		freopen(fn.c_str(), "w", stdout);
		sudoku.Solve();
		sudoku.printSolvedSudoku();
		fclose(stdout);
	}
	*/

    Sudoku sudoku;
	sudoku.getSudoku();
	sudoku.Solve();
	sudoku.printSolvedSudoku();
	//cout << sudoku.checkIsOk();

	return 0;
}
