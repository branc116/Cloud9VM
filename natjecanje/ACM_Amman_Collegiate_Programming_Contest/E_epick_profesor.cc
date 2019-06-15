#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <stack>

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
int t,n;


int main()
{
	cin >> t;
	for (int i=0;i<t;i++){
		cin >> n;
		int maxy=0;
		int temp;
		set<int> s;
		if (i)cout << endl;
		for (int i=0;i<n;i++){
			cin >> temp;
			s.insert(temp);
		}
		maxy=*(--s.end());
		int add=100-maxy;
		int stud=0;
		
		for (set<int>::iterator it=s.begin();it!=s.end();++it){
			
			
			if (*it+add>=50)stud++;
		}
		cout << stud ;
	}
	
	return 0;
}

