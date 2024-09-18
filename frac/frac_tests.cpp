
#include <bits/stdc++.h>
#include <iostream>
#include "../frac/frac.cpp"
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
using namespace std;

bool test_add(){
    frac a(4,5);
    frac b(3,4);
    frac c(31,20);
    if(a+b == c) return true;
    else false;
}

bool test_sub(){
    frac a(4,5);
    frac b(3,4);
    frac c(1,20);
    if(a-b == c) return true;
    else false;
}

bool (*tests[])() = {
    test_add,
    test_sub
};

int main(){
    bool res = true;
    fa(x,tests){
        bool r = x();
        if(!r) cout << "Failed\n";
        res = res and r;
    }
    if(res) cout << "Passed";
}