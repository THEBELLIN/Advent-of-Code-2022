#include <bits/stdc++.h>
using namespace std;

int main()
{
	map<string,int> scores=			  {{"A X", 3}, //X lose, Y draw, Z win
									   {"A Y", 4}, //A rock, B paper, C scissors
									   {"A Z", 8},
									   {"B X", 1},
									   {"B Y", 5},
									   {"B Z", 9},
									   {"C X", 2},
									   {"C Y", 6},
									   {"C Z", 7}};
	int totScore=0;
	while(1)
	{
		string s;
		getline(cin, s);
		if(s=="stop")
			break;
		totScore+=scores[s];
	}
	cout<<totScore;
}