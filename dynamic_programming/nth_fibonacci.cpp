/*
    Find nth Fibonacci
*/

#include<iostream>

using namespace std;

typedef long long ll;


ll nthFib( ll arr[], int n){

    if( arr[n] == 0){
        arr[n] = nthFib( arr, n-1) + nthFib( arr, n-2);
        return arr[n];
    }

    else {
        return arr[n];
    }
}

int main(){

    int N = 6;

    ll arr[N + 1] = {0};

    arr[1] = 1;
    arr[2] = 1;
    cout << nthFib(arr, N);

}
