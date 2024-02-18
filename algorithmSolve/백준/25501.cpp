#include <iostream>

using namespace std;

// 풀이.
// 재귀를 굳이 재귀로 구현하지 않고 for문으로 대신 구현할수 있다. 다만 문자열의 길이가 3일 경우
// 가운데 1번째 인덱스는 굳이 비교할 필요가 없으나 이 문제에서는 비교해야한다고 나와있기에
// 문자열의 길이 / 2까지 순회를 해야함에 있어 주의해야 한다.

string str;
int T;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> str;
        int idx = str.size();
        int num = idx / 2;
        idx -= 1;
        int answer = 1, ans = 0;
        for (int i = 0; i <= num; ++i)
        {
            ++ans;
            if (str[i] != str[idx - i])
            {
                answer = 0;
                break;
            }
        }
        cout << answer << ' ' << ans << '\n';
    }
    return 0;
}