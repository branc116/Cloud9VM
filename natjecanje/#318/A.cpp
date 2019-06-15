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
#include <map>

using namespace std;
#define mod 1000000007
#define eps (1.0E-9)
int n;
multiset<int> p;

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

int main()
{
	init();
	cin >> n;
	int temp;
	
	int first;
	cin >> first;
	int rj=0;
	for (int i=1;i<n;i++){
		cin >> temp;
		if (temp>=first){
			p.insert(temp);
		}
	}
	while (p.size()&&*(--p.end())>=first){
		int num=*(--p.end());
		p.erase(--p.end());
		num--;
		first++;
		rj++;
		if (first<=num){
			p.insert(num);
		}
	}
	
	
	cout << rj;
	return 0;
}

