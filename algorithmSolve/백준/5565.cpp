#include <iostream>

using namespace std;

// 풀이.
// (주어진 총값 - 1 ~ 9번째 책의 합)을 구하면 나머지 10번째 책의 가격을 알수있다. 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int sum, cur = 0;
    cin >> sum;
    for (int i = 0; i < 9; ++i)
    {
        int num;
        cin >> num;
        cur += num;
    }
    cout << sum - cur << '\n';
    return 0;
}