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
	long long x, y;
};
struct rectangle{
	point point1, point2;
};
struct circle{
	double r;
	point center;
};
int n;
set <point> p;
inline bool operator<(point a,point b){
    if (a.x<b.x)return true;
    else if (a.x>b.x)return false;
    else if (a.y<b.x)return true;
    return false;
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
    cin >> n;
    for (int i=0;i<n;i++){
        string s;
        cin >> s;
        int size=s.size();
        bool bill=false;
        bool sad=false;
        
        bool way=false;
        int doo;
        for (int j=0;j<size;j++){
            if (s[j]>='0'&&s[j]<='9'){
                if (!sad){
                if (!bill){
                    bill=true;
                    doo=j;
                }
                else{
                    way=true;
                    break;
                
                
                }
                sad=true;
                }
            }else sad=false;
         if (!way){
             int x=0;
             for (int j=doo-1;j>=0;j--){
                 x+=((s[j]-'A')*(pow(26,doo-j)));
            }
            int y=stoi (s,nullptr,10);
             
         } 
        }
    }
	
	return 0;
}

