#include <iostream>
#include <string>

using namespace std;

// 풀이.
// 두가지 실수 아닌 실수를 했는데 첫째로는 주어지는 수가 한자리일때에는 변환이 일어나지 않는다.
// 최대 100만자리의 수를 입력받기에 string 타입을 이용하였는데 어느 순간이든 int로의 변환이
// 일어나기에 실수했다. 두번째는 ios::sync_with_stdio(false)를 잊었다. 문자열 하나이기 때문에
// 무시했는데 상술했듯 최대 100만자리 입력을 받는다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;
    if (str.size() == 1)
    {
        int cur = str[0] - '0';
        cout << 0 << '\n';
        cout << ((cur % 3 == 0) ? "YES" : "NO") << '\n';
        return 0;
    }
    int answer = 0, cur;
    while (true)
    {
        ++answer;
        int ssize = str.size();
        cur = 0;
        for (int i = 0; i < ssize; ++i)
            cur += str[i] - '0';
        if (cur < 10)
            break;
        str = to_string(cur);
    }
    cout << answer << '\n';
    cout << ((cur % 3 == 0) ? "YES" : "NO") << '\n';
    return 0;
}