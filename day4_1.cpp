#include <bits/stdc++.h>
using namespace std;

int main()
{
	int ans=0;
	int l1, l2, h1, h2;
	while(1)
	{
		char t;
		cin>>l1>>t>>h1>>t>>l2>>t>>h2;
		if(l1<l2)
		{
			if(h2<=h1)
				ans++;
		}
		if(l2<l1)
		{
			if(h1<=h2)
				ans++;
		}
		if(l1==l2)
            ans++;
		cout<<ans<<endl;
	}
}
