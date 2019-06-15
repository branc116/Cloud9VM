#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <stack>
#include <string>

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
int n,miny[3],maxy[3],nn[3];
int main()
{
	cin >> n;
	for (int i=0;i<3;i++){
	    cin >> miny[i] >> maxy[i];
	}
	for (int i=0;i<3;i++){
	    n-=miny[i];
	    nn[i]+=miny[i];
	}
	for (int i=0;i<3;i++){
	    if (n){
	        if (n>maxy[i]-miny[i]){
	            nn[i]+=(maxy[i]-miny[i]);
	            n-=(maxy[i]-miny[i]);
	        }else{
	            
	            nn[i]+=(n);
	            n-=(n);
	        }
	    }
	    cout << nn[i] << " ";
	}
	
	return 0;
}

