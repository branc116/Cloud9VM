#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <stack>
#include <string>

using namespace std;
#define mod 1000000007

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
int kompres(string s){
    char cur=s[0];
    int temp=0;
    for (int i=1;i<s.size();i++){
        if (s[i]==cur)temp++;else cur=s[i];
    }
    return temp;
}
int t;
int main()
{
    cin >> t;
    for (;t;--t){
        string s;
        cin >> s;
        int temp;
        temp=s.size()/2+s.size()%2;
        temp+=kompres(s);
        cout << temp;
    }
	
	return 0;
}

