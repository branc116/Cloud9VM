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
multiset<int> aa;
int n,x;
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
	cin >> n >> x;
	for (int i=0;i<n;i++){
		int temp;
		cin>> temp;
		aa.insert(temp%x);
	}
	multiset<int>::iterator it=aa.end();
	int poc=x;
	int last=-1;
	int lcmm;
	
	while(x&&it!=aa.begin()){
		it--;
		int cur=*it;
		//cout << aa.count(*it);
		if (last!=cur){
			lcmm=(lcm(cur,poc));
			if(aa.count(*it)>=poc/lcmm){
			
			cout << "YES";
			return 0;
			
		}
		if (cur==0){
			cout << "YES";
			return 0;
		}
		}
		
		
		if(x-*it>=0)x-=*it;
		last=cur;
	}
	if (!x){
		cout << "YES";
		return 0;
	}
	cout << "NO";
	return 0;
}

