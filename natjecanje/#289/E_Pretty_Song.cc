#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <stack>
#include <string>
#include <iostream>


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
string s,valws="AEIOUY";

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
bool prov(char c){
    for (int i=0;i<valws.size();i++){
        if (c==valws[i])return true;
    }
    
    return false;
}
int main()
{
	init();
    cin >> s;
    for (int i=0;i<50000;i++){
        s+='A';
    }
    double sum;
    int size=s.size();
    if (size>1000) cout << size << endl;
    int lastv=0;
    for (int j=0;j<size;j++){
        int v=lastv;
        
        double temp;
        //cout << "j" << j << endl;
        v+=prov(s[j]);
        lastv=v;
        temp=(double)v/((double)(j+1));
        //cout << temp << "   "<< v << endl;
        for (int i=1;i<(size-j);i++){
            if (prov(s[i-1]))v--;
            if (prov(s[i+j]))v++;
            temp+=(double)v/((double)j+1);
        }
        sum+=temp;
       // cout << temp << endl;
        
        
    }
    cout << sum;
	return 0;
}

