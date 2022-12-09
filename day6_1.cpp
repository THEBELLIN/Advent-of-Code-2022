#include <bits/stdc++.h>
using namespace std;

int main()
{
	deque<char> buffer;
	char r;
	int ans=5;
	for(int i=0; i<4; i++)
	{
		cin>>r;
		buffer.push_back(r);
	}
	while(1)
	{
		cin>>r;
		bool duplicate = false;
		for(int i=0; i<buffer.size() && !duplicate; i++)
		{
			for(int j=i+1; j<buffer.size(); j++)
			{
				if(buffer[i]==buffer[j])
				{
					duplicate = true;
					break;
				}
			}
		}
		if(duplicate)
		{
			buffer.push_back(r);
			buffer.pop_front();
			ans++;
		}
		else
			break;
	}
	cout<<ans;
}