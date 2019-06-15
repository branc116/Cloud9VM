#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <stack>
#include <string>

using namespace std;
#define mod 1000000007
#define eps (1.0E-9)

struct point{
	double x, y;
};
struct rectangle{
	point point1, point2;
};
struct circle{
	double r;
	point center;
};

void init(){
	ios::sync_with_stdio(false);
	cout << fixed;
}
int gcd(int a, int b){
	int c;
	while (a != 0) {
		c = a; a = b%a;  b = c;
	}
	return b;
}
int lcm(int a, int b){
	int temp = gcd(a, b);

	return temp ? (a / temp * b) : 0;
}
long long fast_pow(int a, int n){
	long long result = 1;
	long long power = n;
	long long value = a;
	while (power>0)
	{
		if (power & 1)
		{
			result = result*value;
			result = result % mod;
		}
		value = value*value;
		value = value % mod;
		power /= 2;
		//power >>= 1;
	}
	return result;
}
bool cmp(string a,string b){
    if (a.size()<b.size()){
        return false;
    }else if (a.size()>b.size()){
        return true;
    }
    for (int i=0;i<a.size();i++){
        if (a[i]<b[i])return false;
        else if (a[i]>b[i])return true;
    }
    return true;
}
int n;
int main()
{
    init();
    string last="0";
    cin >> n;
    for (;n;n--){
        int temp1,old,nn=0,oldn;
        string temp2="";
        cin >> temp1;
        old=temp1;
        
        
        temp2="";
        temp1=old;
        oldn=nn;
       // cout << oldn;
        while (temp1){
            //cout << nn<<endl;
            if (temp1>9){
                    
                temp2='9'+temp2;
                nn++;
                temp1-=9;
            }else {
                
                temp2=(char)(temp1+'0')+temp2;
                temp1=0;
                nn++;
                
            }
        }
        while (cmp(last,temp2)){
                   temp2='1'+temp2;
                   temp2[1]--;
        }
            
        cout << temp2 << endl;
        last=temp2;
        
    }
	
	return 0;
}

