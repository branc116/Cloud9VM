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
struct drva{
    int x,h;
};
vector<drva> p;
int n;
int izado;
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
	    drva temp;
	    cin >> temp.x >> temp.h ;
	    p.push_back(temp);
	}
	if (n==1){
	    cout << 1;
	    return 0;
	}
	if (n==2){
	    cout << 2;
	    return 0;
	}
	int sum=2;
	izado=p[0].x;
	for (int i=1;i<(n-1);i++){
	    if (p[i].x-p[i].h>izado){
	        izado=p[i].x;
	        sum++;
	       // cout << p[i].x << "  " << p[i].h << "  iza  " << izado << endl;
	    }else if (p[i].x+p[i].h<p[i+1].x){
	        izado=p[i].x+p[i].h;
	        sum++;
	       // cout << p[i].x << "  " << p[i].h << "  ispred  " << izado << endl;
	    }else{
	        izado=p[i].x;
	       // cout << p[i].x << "  " << p[i].h << "  nikam  " << izado << endl;
	    }   
	}
	cout << sum ;
	return 0;
}

