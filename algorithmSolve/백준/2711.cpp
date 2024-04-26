#include <iostream>

using namespace std;

// 풀이.
// 주어지는 오타의 위치를 제외한 나머지 문자들을 출력한다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, num;
    cin >> T;
    string str;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> num >> str;
        for (int i = 0; i < str.size(); ++i)
        {
            if (i == num - 1)
                continue;
            cout << str[i];
        }
        cout << '\n';
    }
    return 0;
}