#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;

int com(int i, int j)
{
    return i < j;
}
int main()
{
    int n, result;
    cin >> n;
    vector<int> num;
    for (int i = 0; i < n; i++)
    {
        int N;
        cin >> N;
        num.push_back(N);
    }
    sort(num.begin(), num.end(), com);
    if (num.size() != 1) //
    {
        result = num[0] * num[num.size() - 1];
    }
    else
    { //약수의 개수가 홀수
        result = num[0] * num[0];
    }
    cout << result;
}