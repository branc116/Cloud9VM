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

short int p[101][101];
vector<int> rj;
int n;

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
        bool prov=true;
        for (int j=0;j<n;j++){
            cin >> p[i][j];
            if (p[i][j]==1 || p[i][j]==3)prov=false;
        }
        if (prov)rj.push_back(i+1);
    }
    cout << rj.size() << endl;
    for (int i=0;i<rj.size();i++){
        cout << rj[i] << " ";
    }
	return 0;
}

