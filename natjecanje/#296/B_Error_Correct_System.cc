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
int n;
string s,t;
vector<int> error;

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
	cin >> s >> t;
	int rj=0;
    for (int i=0;i<n;i++){
        if (s[i]!=t[i]){
            error.push_back(i);
            rj++;
        }
    }	
    int pamtii=-1,pamtij=-1;
    for (int i=0;i<error.size();i++){
        for(int j=i+1;j<error.size();j++){
            int k=error[i],h=error[j];
            if (s[k]==t[h]||s[h]==t[k]){
                if (s[k]==t[h]&&s[h]==t[k]){
                    cout << rj-2 << endl << k+1 << ' ' << h+1;
                    return 0;
                }
                pamtii=k+1;
                pamtij=h+1;
            }
            if (error.size()>1000)j+=7;
        }
        if (error.size()>1000)+=7;
    }
    if (pamtii!=-1)rj--;
    cout << rj << endl << pamtii << ' ' << pamtij;
	return 0;
}

