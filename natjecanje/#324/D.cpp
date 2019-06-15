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
vector <int> prms;
bool notprime[100000];

void init(){
	ios::sync_with_stdio(false);
	cout << fixed;
	
	for (int i=2;i<100000;i++){
		if (!notprime[i]){
			prms.push_back(i);
			
			for (int j=i+i;j<100000;j+=i){
				notprime[j]=1;
			}
		}
	}
}
int n;
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

bool p(int n){
	int doo=(int)sqrt(n);
	int cur=0;
	while (prms[cur]<=doo){
		if (n%prms[cur]==0)return false;
		cur++;
	}
	return true;
}

int main()
{
	init();
	int  n;
	cin >> n;
	
	cout << prms.size() << endl;
	for (int i=0;i<100000;i++){
		vector <int> rj;
		n=i;
		int now=n/2;
	while (n){
		
		while (!p(now)){
			if (now%2==1){
				now-=1;
			}else{
				now--;
			}
		}
		
		rj.push_back(now);
		n-=now;
	
		now = n;
	}
	//cout << "n= " << i << endl;
	//cout << rj.size() << endl ;
	//for (int i=0;i<rj.size();i++){
	//	cout << rj[i] << ' ';
	//}
	//cout << endl;
	if (rj.size()>3){
		cout << i << endl;
		return 0;
	}
	}
	cout << "ok";
	return 0;
}

