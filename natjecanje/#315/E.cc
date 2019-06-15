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


string vals,s,rj;

int leth,rn;
int tipe[30],rule[10000000];

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

char next(int taipe,char od){
	for (char i=od;(i-'a')<vals.size();i++){
		if (taipe==tipe[i-'a'])return i;
	}
	return 0;
}

void reset(int odd,int doo){
	for (int i=odd;i<doo;i++){
		s[i]='a';
	}
}

int prov(int od){
	int nuls=0;
	for (int i=od;i>=0;i--){
		cout << i << "  " << s[i] << endl;
		if (0<rule[i]){
			cout << s[i]-'a' << "  " << rule[i] << "  " << tipe[s[i]-'a'] << endl;
			if (rule[i]!=tipe[s[i]-'a']){
				char temp=next(rule[i],s[i]);
				cout << temp << endl;
				if (temp){s[i]=temp;reset(i+1,leth);i=leth-1;nuls=0;}
				else nuls++;
				
			}
		}
	//	cin >> od;
	}
	if(nuls>0)return -1;
	return 1;
	
}


int main()
{
	init();
	cin >> vals;
	for (int i=0;i<vals.size();i++){
		if (vals[i]=='V')tipe[i]=1;
		else tipe[i]=2;
	}
	cin >> leth >> rn;
	for (int i=0;i<rn*2;i++){
		int tempi;
		char tempc;
		cin >> tempi >> tempc;
		if (tempc=='V')rule[tempi-1]=1;
		else rule[tempi-1]=2;
	}
	cin >>s;
	int poz=leth-1;
	int od=leth-1;
	int dalje=prov(od);
	
	if (dalje ==-1){
		cout << -1;
		return 0;
	}
	cout << s;
	return 0;
}

