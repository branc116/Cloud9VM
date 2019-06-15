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
#include <fstream>

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

int n[5000002];
int izrac(int a);
void init(){
	ios::sync_with_stdio(false);
	cout << fixed;
	n[1]=0;
	n[2]=1;
	
	
/*	
	for (int i=3;i<2300;i++){
	    n[i]=izrac(i);
	}
*/
}
int izrac(int a){
	int doo=sqrt((double)a);
	int sum=0;
//	cout << " a " << a << "  "; 
	int delj=2;
//	cout << endl;
	while (a>1&&delj<=doo){
		
		if (!(a%delj)){a/=delj;sum++;}else delj++;
		if (n[a])return sum+n[a];
		
	}
//	cout << sum << endl;;
	if (sum)return sum+1;return 1;
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
int t;

int main()
{
	init();
	cin >> t;
	
	for (;t;--t){
	    int a,b;
	    cin >> a >> b;
	    //cout << "tu" << endl;
	    int sum=0;
	    for (int i=(b+1);i<=a;i++){
	       // cout << i << endl;
	        if (n[i])sum+=n[i];else{ 
	        	n[i]=izrac(i);sum+=n[i];
	        	//cout << i << "  "  << n[i] << endl;
	        }
	    }
	    cout << sum  << endl;
	}
	return 0;
}

