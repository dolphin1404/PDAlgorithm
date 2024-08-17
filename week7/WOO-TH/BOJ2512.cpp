//
// Created by samsung on 24. 8. 17.
//
#include<iostream>
#include<vector>
using namespace std;

int adjust_assi(vector<int> arr,int Max_budget) {

}

int main(){
    int N = 0;          //지방의 수
    int MAX =0;         //총 예산의 값
    int sum  = 0;
    int print_max = 0;
    cin >> N;
    vector<int> arr(N,0);       //N선언 하고 초기화
    for(int i =0 ;i <N;++i) {
        cin >> arr[i];        //요청하는 예산의 값
        sum += arr[i];
    }
    cin >> MAX;

    if(sum > MAX) {
        adjust_assi(arr, MAX);
    }
    else {              //배정된 예산들 중 최댓값인 정수 출력
        print_max = arr[0];
        for(int i = 1; i < N;++i) {
            if(print_max < arr[i])
                print_max = arr[i];
        }
        cout << print_max << endl;      //최대 정수 출력
    }

}