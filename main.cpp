/*
#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

long long solve(long long m, long long n) {
    long long pm=m,res=1;
    while(n!=0)
    {
        if(n&1==1)
        {
            res=res*pm;
            res%=100003;
        }
        pm=pm*pm;
        pm%=100003;
        n>>=1;
    }
    return res%100003;
}
int main(){
	long long M,N;
	cin>>M;
	cin>>N;
	if(M<=0 || N<=0) //ilegal
	{
        cout<<0;
        return 0;
    }
    if(N==1) //only one room
    {
        cout<<0;
        return 0;
    }
	long long situaCnts=(solve(M,N)+100003-(M*solve(M-1,N-1))%100003)%100003;
	cout<<situaCnts;
	return 0;
}
*/
/*
#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;


void add(queue<int> &seq,int x,int mod,int t) {
    int tmp=(x+t)%mod;
    seq.push(tmp);
}
int query(queue<int> &seq,int x) {
    stack<int> tmpStack;
    queue<int> tmpSeq=seq;
    if(tmpSeq.empty()) return 0;
    while(!tmpSeq.empty()) // push the queue into stack
    {
        tmpStack.push(tmpSeq.front());
        tmpSeq.pop();
    }
    int maxNum=tmpStack.top(); //top of the stack
    while(x--) //get the largest number of the last x numbers
    {
        maxNum=maxNum>=tmpStack.top()? maxNum:tmpStack.top();
        tmpStack.pop();
    }
    return maxNum;
}
int main() {
    int m,mod;
	cin>>m>>mod; //M,mod
    queue<int> numSeq;
    int t=0;
	while(m--) {
        char ch; //insert I   query Q
		int x;   //insert N   query L
		cin>>ch;
		cin>>x;
		if (ch == 'I') //insert
			add(numSeq,x,mod,t);
		else if(ch == 'Q') //query
		{
			t=query(numSeq,x);  //t
			cout<<t<<endl; //cout,endl;
        }
	}
	return 0;
}
*/
/*
#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void add(vector<int> &seq,int x,int mod,int t) {
    int tmp=(x+t)%mod;
    seq.push_back(tmp);
}
int query(vector<int> &seq,int x) {
    int length=seq.size();
    if(length==0) return 0;
    int maxNum=seq[length-1];
    for(int i=length-1;i>=length-x;i--)
    {
        maxNum=maxNum>=seq[i]?maxNum:seq[i];
    }
    return maxNum;
}
int main() {
    int m,mod;
	cin>>m>>mod; //M,mod
    vector<int> numSeq;
    int t=0;
	while(m--) {
        char ch; //insert I   query Q
		int x;   //insert N   query L
		cin>>ch;
		cin>>x;
		if (ch == 'I') //insert
			add(numSeq,x,mod,t);
		else if(ch == 'Q') //query
		{
			t=query(numSeq,x);  //t
			cout<<t<<endl; //cout,endl;
        }
	}
	return 0;
}
*/
#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void add(vector<int> &seq,int x,int mod,int t) {
    int tmp=(x+t)%mod;
    seq.push_back(tmp);
}
int query(int* a,vector<int> &seq,int x) {
    int length=seq.size();
    if(length==0) return 0;
    int maxNum=seq[length-1];
    for(int i=length-1;i>=length-x;i--)
    {
        maxNum=maxNum>=seq[i]?maxNum:seq[i];
    }
    return maxNum;
}
int main() {
    int m,mod;
	cin>>m>>mod; //M,mod
    vector<int> numSeq;
    int t=0;
    int  maxvec[200000];
	while(m--) {
        char ch; //insert I   query Q
		int x;   //insert N   query L
		cin>>ch;
		cin>>x;

		if (ch == 'I') //insert
		{
			add(numSeq,x,mod,t);
			int length=numSeq.size();
            int maxarr[length];
            int maxNum=numSeq[length-1];
            for(int i=length-1;i>=0;i--)
            {
                maxNum=maxNum>=numSeq[i]?maxNum:numSeq[i];
                maxarr[length-1-i]=maxNum;
            }
		}
		else if(ch == 'Q') //query
		{
			t=query(maxarr,numSeq,x);  //t
			cout<<t<<endl; //cout,endl;
        }
	}
	return 0;
}









