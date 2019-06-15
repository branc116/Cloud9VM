#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <stack>
#include <string>
#include <iostream>


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
int n;
multiset<int> s;
int main()
{
	init();
	cin >> n;
	
	for (int i=0;i<n;i++){
	    int temp;
	    cin >> temp;
	    s.insert(temp);
	}
    
    /*
    for (int i=0;i<4000;i++){
        s.insert(2);
    }*/
	int sum=0;
	for (multiset<int>::iterator it=s.begin();it!=s.end();++it){
	    //cout << *it << "  "; 
	}
//	cout << endl;
	bool posmak=false;
	for (multiset<int>::iterator it=s.begin();it!=s.end();++it){
	    if (posmak){it--;posmak=false;}
	    //cout << *it << endl;
	    int tempic=s.count(*it);
	    if (tempic>1){int temp=*it+tempic-1;s.erase(it++);s.insert(temp);sum+=(tempic-1);posmak=true;}
	    
	}
	cout << sum;
	
	return 0;
}

