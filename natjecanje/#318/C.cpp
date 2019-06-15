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
int n;
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
vector<long long int> p;
bool notprm[10000000];
vector<int> primes;
void init(){
	ios::sync_with_stdio(false);
	cout << fixed;
	primes.push_back(2);
	
	for (int i=2;i<32000;i++){
		if (!notprm[i]){
			primes.push_back(i);
			for (int j=i+i;j<32000;j+=i){
				notprm[j]=true;
			}
		}
	}
}
int fuckoff23(int a){
	//cout << 0.5<<endl;
	while(!(a%2)||!(a%3)){
		//cout << a ;
		int duh;
		//cin >> duh;
		if (!(a%2))a/=2;
		if (!(a%3))a/=3;
	}
	//cout << 0.75<<endl;
	return a;
}
vector<int> factorize(int a){
	a=fuckoff23(a);
	vector<int> temp;
	int curn=2;
	//cout << 1 << endl;
	while (a>1&&primes.size()>curn){
		int curprim=primes[curn];
		while (!(a%curprim)){
			//cout << curprim << "  ";
			temp.push_back(curprim);
			a/=curprim;
		}
		curn++;	
	}
	if (a>1)temp.push_back(a);
	return temp;
	
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
	//cout << 0 << endl;
	cin >> n;
	int first;
	cin >> first;
	vector<int> prmz=factorize(first);
	//cout << 2 << endl;
	for (int i=1;i<n;i++){
		
		int temp;
		cin >> temp;
		temp=fuckoff23(temp);
		for (int j=0;j<prmz.size();j++){
			
			if ((temp%prmz[j])){
				cout << "No";
				return 0;
			}
			temp/=prmz[j];
		}
		if (temp>1){
			cout << "No";
			return 0;
		}
	}
	
	
	cout << "Yes";
	return 0;
}

