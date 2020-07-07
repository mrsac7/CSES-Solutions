/*
Problem Name: Chessboard and Queens
Problem Link: https://cses.fi/problemset/task/1624
Author: Sachin Srivastava (mrsac7)
*/

#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (int i=a;i<b;i++)
char chess[8][8];
int c=0;
bool ld[15], rd[15], row[7];
void rec(int j){
	if (j==8) {c++; return;}
	rep(i,0,8){
		if (chess[i][j]=='.' && ld[i-j+7]==0 && rd[i+j]==0 && row[i]==0){
			ld[i-j+7]=1, rd[i+j]=1, row[i]=1;
			rec(j+1);
			ld[i-j+7]=0, rd[i+j]=0, row[i]=0;
		}
	}
}
int main(){
	rep(i,0,8)rep(j,0,8)cin>>chess[i][j];
	rec(0);
	cout<<c;
}