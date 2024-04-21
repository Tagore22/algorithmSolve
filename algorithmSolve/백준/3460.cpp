#include <iostream>

using namespace std;

// 풀이.
// 주어진 수 num을 2로 나누며 이진수로 만드는 도중 1이 등장시 몇번째 수인지를 출력하면 된다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, num;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        cin >> num;
        int idx = 0;
        while (num > 0)
        {
            if (num % 2 == 1)
                cout << idx << ' ';
            num /= 2;
            ++idx;
        }
        cout << '\n';
    }
    return 0;
}