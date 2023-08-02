#include <iostream>

using namespace std;

// 풀이.
// 처음부터 100에 가까운 수를 만들어가는 문제.
// 기존값보다 100에서 멀어진다면 무시한다.

int main()
{
    int sum = 0;
    int num;
    for (int i = 0; i < 10; ++i)
    {
        cin >> num;
        if (abs(100 - (sum + num)) <= abs(100 - sum))
            sum += num;
    }
    cout << sum << '\n';
    return 0;
}