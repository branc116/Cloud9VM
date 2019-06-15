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
	int m,ff;
	
};
struct rectangle{
	point point1, point2;
};
struct circle{
	double r;
	point center;
};

long long int n, dif,max_ff=0;

multiset<point> p;
vector<point> sorted_p;

void init(){
	ios::sync_with_stdio(false);
	cout << fixed;
}

inline bool operator <(point point1, point point2){
	return point1.m<point2.m;
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
	cin >> n >> dif;
	for (int i=0;i<n;i++){
		point temp;
		cin >> temp.m >> temp.ff;
		p.insert(temp);
	}
	for (set<point>::iterator it=p.begin();it!=p.end();++it){
		//cout << (*it).m << "\n\n";
		sorted_p.push_back(*it);
	}
	int od=0,doo=0;
	long long int cur_ff=0;
	for (int i=0;i<n;i++){
		
		while (sorted_p[i].m-sorted_p[od].m>=dif&&od<i){
			cur_ff-=sorted_p[od].ff;
			od++;
			
		}
		while (doo<n&&sorted_p[doo].m-sorted_p[i].m<dif){
			cur_ff+=sorted_p[doo].ff;
			doo++;
		}
		max_ff=max(max_ff,cur_ff);
	}
	cout << max_ff;
	return 0;
}

