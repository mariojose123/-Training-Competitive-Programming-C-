//Exercice:
//http://www.spoj.com/problems/WORDS1/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> t(26,0);
vector<vector<int> > G(26,vector<int>(26,0));
void ConnectedGraph(int b)//
{
  t[b]=1;
  for(int j=0;j<26;j++){
  		if((G[b][j]||G[j][b])&&!t[j])ConnectedGraph(j);
  }
}
bool door(vector<string> s){
    fill (G.begin(),G.end(),vector<int>(26,0)); 
    fill(t.begin(),t.end(),0);
	if(s.size()==1){
		return 1;
	}
	char firstword='2';//first word of the first string
	//'2' if the first string have different final word and first word
	if(s[0][0]==s[0].back()){
	  firstword=s[0][0];	
	}
	vector<int> v(26,0);
	int flag=1;//check if all nodes are alone
	int stop=1;
	for(int i=0;i<s.size();i++){
	  if(s[i][0]==s[i].back()&&(firstword!='2')&&stop){
	  	if(firstword!=s[i].back()){
         flag=0; 
	  	}
	  }
	  else{
	  	flag=1;
	  	stop=0;
	  }
	  v[s[i][0]-97]=v[s[i].back()-97]=1;
	  G[s[i][0]-97][s[i].back()-97]++;
	}
  if(flag==0){
  	return 0;
  }
	int i;
	for(i=0;!v[i];i++);
	ConnectedGraph(i);
	for(i=0;i<26;i++){
		if(v[i]&&!t[i]){
			return 0;
		}
	}
	int outdegree;
	int indegree;
	int d1=0;//numbers of D1==1;
	int d2=0;//numbers of D2==1;
	int D;//flag node with degree
	for( i=0;i<26;i++){//check the rule to know if the digraph have a euler trail
  	  outdegree=0;
	  indegree=0;
	  for(int z=0;z<26;z++){
		if(G[i][z]){
			outdegree+=G[i][z];
		}
		if(G[z][i]){
			indegree+=G[z][i];
		}
	}
	int D1=outdegree-indegree;
    int	D2=indegree-outdegree;
	if(D1==1){
			d1++;
	}
	else if(D1>1){
		return 0;
	}
	if(D2==1){
			d2++;
	}
	else if(D2>1){
		return 0;
	}
 }
    if(d2<=1&&d1<=1){
        return 1;
    }
    else{
    	return 0;
    }
}
int main(){
	int T;
	int n;
	vector<string> s;
	string s2;
	cin>>T;
	while(T--){
		cin>>n;
		while(n--){
			cin>>s2;
			s.push_back(s2);
		}
		if(door(s)){
			cout<<"Ordering is possible."<<endl;
		}
		else{
			cout<<"The door cannot be opened."<<endl;
		}
		s={};
	}
}
