
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include "../rnum/rnum.cpp"
#define ll long long
#define ld long double
#define pll pair<ll,ll>
#define vl vector<ll> 
#define vvl vector<vl> 
#define vpll vector<pll>
#define vvpll vector<vpll>
#define pb push_back
#define loop(n,i) for(ll i = 0; i < n; i++)
#define fa(i,v) for(auto &i:v)
#define HALF frac(1,2)
using namespace std;

void test_assign(){
    rnum a(2);
    rnum b(5);
    a = b;
    if(a != b) cout << "Assign failed";
}

void test_add(){
    rnum a(2);
    rnum b(2);
    frac d(1,2);
    a = pow(a,d);
    b = (b + a);
    b.desc();
    cout << "\n";
    // b = b*a;
    // b.desc();
    // a = a + 1;
    // a = a*2;
    // a.desc();
    // cout << "\n";
    // b.desc();
    // cout << "\n";
    cout << (a == b) << "\n";
}

void (*tests[])() = {
    test_assign,
    test_add,
    //test_sub
};

int main(){
    bool res = true;
    fa(x,tests){
        x();
    }
    if(res) cout << "Passed";
}