//int to roman traslator 

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<int> ints={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    vector<string> roman={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    string s;
    int p=0;
    for(int i=0;i<roman.size();i++)
    {
    while(num>=ints[i]){
        num-=ints[i];
        s.append(roman[i],p);
        p+=roman[i].size();
    }
}
    return s;


    }
};
