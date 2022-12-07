#include <bits/stdc++.h>
using namespace std;

int main()
{
	stack <char> piles[10];
	stack <char> temp;
	piles[1].push('H');
	piles[1].push('T');
	piles[1].push('Z');
	piles[1].push('D');
	piles[2].push('Q');
	piles[2].push('R');
	piles[2].push('W');
	piles[2].push('T');
	piles[2].push('G');
	piles[2].push('C');
	piles[2].push('S');
	piles[3].push('P');
	piles[3].push('B');
	piles[3].push('F');
	piles[3].push('Q');
	piles[3].push('N');
	piles[3].push('R');
	piles[3].push('C');
	piles[3].push('H');
	piles[4].push('L');
	piles[4].push('C');
	piles[4].push('N');
	piles[4].push('F');
	piles[4].push('H');
	piles[4].push('Z');
	piles[5].push('G');
	piles[5].push('L');
	piles[5].push('F');
	piles[5].push('Q');
	piles[5].push('S');
	piles[6].push('V');
	piles[6].push('P');
	piles[6].push('W');
	piles[6].push('Z');
	piles[6].push('B');
	piles[6].push('R');
	piles[6].push('C');
	piles[6].push('S');
	piles[7].push('Z');
	piles[7].push('F');
	piles[7].push('J');
	piles[8].push('D');
	piles[8].push('L');
	piles[8].push('V');
	piles[8].push('Z');
	piles[8].push('R');
	piles[8].push('H');
	piles[8].push('Q');
	piles[9].push('B');
	piles[9].push('H');
	piles[9].push('G');
	piles[9].push('N');
	piles[9].push('F');
	piles[9].push('Z');
	piles[9].push('L');
	piles[9].push('D');
	while(1)
	{
		string t;
		int from, to, q;
		cin>>t;
		if(t=="stop")
			break;
		cin>>q>>t>>from>>t>>to;
		for(int i=0; i<q; i++)
		{
			char c =piles[from].top();
			piles[from].pop();
			temp.push(c);
		}
		while(!temp.empty())
		{
			char c = temp.top();
			piles[to].push(c);
			temp.pop();
		}
	}
	for(int i=1; i<10; i++)
	{
		cout<<piles[i].top();
	}
}
