
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include "../term/term.cpp"
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

#define HALF frac(1,2)

void test_assign(){
    term a = pow(frac(24),HALF);
    term b = pow(frac(20),HALF);
    a = b;
    if(a != b) cout << "Assign Failed\n";
}

void test_pow(){
    term c = 125;
    c = pow(c,HALF);
    term a = 5;
    a = pow(a,frac(3)*HALF);
    if(a != c) cout << "Power failed\n";
}

void test_mul1(){
    term a = 5;
    term b = pow(a,HALF);
    term c = 125;
    c = pow(c,HALF);
    term res = a*b;
    if(c != (a*b)) cout << "Mul1 failed\n";
}

void test_mul2(){
    term a = 10;
    term b = pow(frac(8),HALF);
    term c = pow(frac(800),HALF);
    if(c != (a*b)) cout << "Mul2 failed\n";
}

void (*tests[])() = {
    test_assign,
    test_pow,
    test_mul1,
    test_mul2,
    //test_sub
};

int main(){
    bool res = true;
    fa(x,tests){
        x();
    }
    if(res) cout << "Passed";
}