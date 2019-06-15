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

vector<list<int>> p;

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
void ispis(list<int> a){
	for (list<int>::iterator it=a.begin();it!=a.end();++it){
		cout << *it << "  ";
	}
	cout << endl;
}
int main()
{
	init();
	cin >> n;
	list<int> lt;
	p.push_back(lt);
	for (int i=0;i<n;i++){
		int temp;
		cin >> temp;
		
		p[0].push_back(temp);
	}
	
	int rj=0;
	do{
		rj++;
		list<int> next;
		p.push_back(next);
		if (p[rj-1].size()>2){
			
			for(list<int>::iterator it=++p[rj-1].begin();it!=(--p[rj-1].end());++it){
				list<int>::iterator itp=--it,its=++it;
				its++;
				int br=min(min(*itp,*its),(*it)-1);
				//cout << *itp << "  " << *it << "  " << *its << "  " << *(--p[rj-1].end()) << "  " << br << endl;
				if (br<0)br=0;
				if (br||(*its>0&&*itp>0&&itp!=p[rj-1].begin()&&its!=--p[rj-1].end())){
					
					p[rj].push_back(br);
				}
				int bup;
				//cin >> bup;
				
			}
		}
		//ispis(next);
		//cout << endl;
		
		
		//ispis(p[rj]);
	}while (p[rj].size()>1||(p[rj].size()==1&&*p[rj].begin()>0));
	cout << rj;
	return 0;
}

