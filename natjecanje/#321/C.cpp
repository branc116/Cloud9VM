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
struct tree{
	bool cat;
	vector <int> child;
	
};
vector<tree> p;
int n,diff;

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
int dfs(int v,int num_cat){
	if (p[v].cat)num_cat++;else num_cat=0;
	if (num_cat>diff)return 0;
	int rj=0;
	if (p[v].child.size()==0)return 1;
	for (int i=0;i<p[v].child.size();i++){
		rj+=dfs(p[v].child[i],num_cat);
	}
	return rj;
}
int main()
{
	init();
	cin >> n >> diff;
	for (int i=0;i<n;i++){
		tree temp;
		cin >> temp.cat;
		p.push_back(temp);
	}
	for (int i=0;i<(n-1);i++){
		int temp1,temp2;
		cin >> temp1 >> temp2;
		p[temp1-1].child.push_back(temp2-1);
	}
	cout << dfs(0,0);
	return 0;
}

