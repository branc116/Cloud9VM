#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <stack>
#include <string>
#include <iomanip>

using namespace std;
#define mod 1000000007
#define eps (1.0E-6);
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
double n,w;
multiset<int> p;
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
    cin >> n >> w;
    int t=n*2;
    for (int i=0;i<t;i++){
        int temp;
        cin >> temp;
        p.insert(temp);
      
    }

    long double maxy=-1;
    multiset<int>::iterator it=(p.end());
    for (int i=0;i<n;i++){
        --it;
    }
    maxy=(*it);
    if (2*(*p.begin())<maxy)maxy=*p.begin()*2;
    maxy=maxy*n+maxy/2*n;
    if (maxy>w)maxy=w;
    cout <<fixed << maxy;
	return 0;
}

