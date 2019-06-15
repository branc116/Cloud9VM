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

bool notprime[1000001];
vector<int> prime;
vector<int> factorz;

void init(){
	ios::sync_with_stdio(false);
	cout << fixed;
	
	for (int i=2;i<1000001;i++){
		if (!notprime[i]){
			prime.push_back(i);
			for (int j=i;j<1000001;j+=i){
				notprime[j]=true;
			}
		}
	}
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
	long long int n,started,nsqrt;
	
	cin >> n;
	nsqrt=sqrt(n)+1;
	int cur_prm=0;
	started=n;
	while(prime[cur_prm]<nsqrt&&n>1){
		while (n%prime[cur_prm]==0){
			//cout << prime[cur_prm] << "  " ;
			factorz.push_back(prime[cur_prm]);
			n/=prime[cur_prm];
		}
		cur_prm++;
	}
	if (n>1){
		factorz.push_back(n);
	}
	if (started==1)factorz.push_back(1);
	//cout << n << "  " << prime.size() << "  " << factorz.size();
	int last;
	for (int i=0;i<(factorz.size()-1);i++){
		int last=factorz[i],neew=factorz[i+1];
		if (last==neew)started/=last;
		
	}
	cout << started;
	return 0;
}

