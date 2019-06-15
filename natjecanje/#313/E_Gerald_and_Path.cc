#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <stack>
#include <string>
#include <list>

using namespace std;
#define mod 1000000007

struct point{
	int ood, doo;
};
struct rectangle{
	point point1, point2;
};
struct circle{
	double r;
	point center;
};
int n;
list <point> polja;
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
int izrac(int ood,int pover){
    point temp1,temp2;
    temp1.doo=ood-1;
    temp2.ood=ood;
    temp2.doo=ood+pover-1;
    temp1.ood=ood-pover;
    cout << "ovede" << endl;
    if (temp1.ood<0){
        temp1.ood=0;
    }
   if ( !polja.empty()){ 
       list<point>::iterator it=--polja.end();
       do{
           point temp=*it;
           if (temp1.ood<temp.doo){
               if (temp1.doo<=temp.doo){
                   temp1.ood=-1;temp1.doo=-1;
               }else {
                   temp1.ood=temp.doo+1;
               }
              
               
           }
           if (temp2.ood<temp.doo){
               if (temp2.doo<=temp.doo){
                   temp2.ood=-1;temp2.doo=-1;
               }else {
                   temp2.ood=temp.doo+1;
               }
              
               
           }
           --it;
       }while(it!=polja.begin());
   }
    if (temp1.ood==-1&&temp2.ood==-1){
       if (temp1.doo-temp1.ood>=temp2.doo-temp1.ood){
           polja.push_back(temp1);
           return temp1.doo-temp2.doo
       }else {
           polja.push_back(temp2);
       }
           
    }else {
       if (temp2.ood!=-1){
           polja.push_back(temp2);
       }else polja.push_back(temp1);
     }
   
}


int main()
{
    cin >> n;
    long long sum=0;
    for (;n;--n){
        int pover, ood;
        cin >> ood >> pover;
        sum+=izrac(ood,pover);
        
        point temp =*(--polja.end());
       
        cout << sum << "  " << n << endl;
    }
    cout << sum << endl;
	return 0;
}

