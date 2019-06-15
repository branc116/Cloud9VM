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
#define inf 1000000000
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
bool p[4010][4010];
int recogniz[4010];
int n,m;


int dfs(int i,int depth){
	//cout << i << "  "  << depth << endl;
	int sljed=depth-1;
	if (n-i<depth)return inf;
	if (depth==0){
		//cout << recogniz[i]-1 << endl;
		if (recogniz[i]-1>0){
			return recogniz[i]-1;
		}
		return 0;
	}
	int tempmin=inf;
	
	
	for (int j=i;j<n;j++){
		cout << "     " << p[i][j] << endl;
		if (p[i][j]==true)tempmin=min(tempmin,dfs(j,sljed)+recogniz[j]-1);
	}
	cout << tempmin << endl;
	if (tempmin>0){
		return tempmin;
	}
	return 0;
}

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
	cin >> n >> m;
	for (int i=0;i<m;i++){
		int temp1,temp2;
		cin >> temp1 >> temp2;
		p[temp1-1][temp2-1]=true;
		//p[temp2-1][temp1-1]=true;
		recogniz[temp1-1]++;
		//recogniz[temp2-1]++;
	}
	int miny=inf;
	for (int i=0;i<n-3;i++){
		miny=min(dfs(i,3),miny);
	}
	cout << miny;
	return 0;
}

