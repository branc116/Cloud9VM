//©branimir116™
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <stack>
#include <string>
#include <iomanip>
#include <list>
#include <queue>

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
string s1,s2;
int upitniki,ok;
void rec(int i,int ns,int nt, string s,string t){
   /// cout << i << endl;
    if (i==s1.size()){
        if ( ns==nt)ok++;
        return;
    }
    if (s[i]=='-') ns--;
    if (s[i]=='+') ns++;
    if (t[i]=='?'){
        t[i]='+';
        rec(i+1,ns,nt+1,s,t);
        t[i]='-';
        rec(i+1,ns,nt-1,s,t);
        
    }else {
    if (t[i]=='+') nt++;
    if (t[i]=='-') nt--;
    
    rec(i+1,ns,nt,s,t);
    }
    return;
}
void init(){
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(9);
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

int main()
{
	init();
	cin >> s1 >> s2;
	rec(0,0,0,s1,s2);
	for (int i=0;i<s2.size();i++){
	    if (s2[i]=='?')upitniki++;;
	}
	double mog=pow(2,upitniki);
	double vjero=ok/mog;
	cout << vjero;
	return 0;
}

