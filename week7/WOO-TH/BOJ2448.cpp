//
// Created by samsung on 24. 8. 16.
//

#include <iostream>
#include<vector>
using namespace std;

void print_star(int x, int y, int size, vector<vector<char>>& canvas){
    if(size == 3) {     //종료 조건
        canvas[y][x] = '*';
        canvas[y+1][x-1] = canvas[y+1][x+1] = '*';
        for(int i = -2 ; i<=2;++i) {
            canvas[y+2][x+i] = '*';
        }
    }else {
        int new_size = size / 2;
        print_star(x,y,new_size,canvas);
        print_star(x-new_size, y+new_size, new_size,canvas);
        print_star(x + new_size, y + new_size, new_size, canvas);
    }
}
void print_canvas(const vector<vector<char>>& canvas) {
    for (const auto& line : canvas) {// 범위기반 for문
        for (char c : line) {
            cout << c;
        }
        cout << '\n';
    }
}


int main() {
    int num = 0;
    cin >> num;
    vector<vector<char>> canvas(num,vector<char>(2*num-1, ' '));    //벡터의 벡터 -> 2차원 배열
    print_star(num-1,0,num,canvas);
    print_canvas(canvas);

}