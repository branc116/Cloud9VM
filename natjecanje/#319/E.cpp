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
	int x, y;
};
struct rectangle{
	point point1, point2;
};
struct circle{
	double r;
	point center;
};
int n;
point a[1000010];

bool bil[1000010];
int udaljenost(point a,point b){
	return(abs(a.x-b.x)+abs(a.y-b.y));
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
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> a[i].x >> a[i].y;
	}
	int id=0;
	long long sum=0;
	vector<int> idz;
	idz.push_back(0);
	for (int i=0;i<n;i++){
		int ids=-1;
		int minn=1000000000;
		bool sve=true;
		bil[id]=true;
		for (int j=0;j<n;j++){
			if (bil[j]==false){
				sve=false;
				int ud=udaljenost(a[j],a[id]);
				if (minn>ud){
					minn=ud;
					ids=j;
				}
			}
		}
		
		
		if (sve){
			
				for (int j=0;j<idz.size();j++){
					cout << idz[j]+1 << " ";
				}
			return 0;
		}
		bil[ids]=true;
		idz.push_back(ids);
		id=ids;
	}
	return 0;
}

