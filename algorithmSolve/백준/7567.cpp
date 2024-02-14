#include <iostream>

using namespace std;

// 풀이.
// 결과적으로 같은 모양의 그릇들은 5씩 증가하고 모양이 바뀌어 온전히
// 높이가 드러날때에만 10씩 증가한다.

int main()
{
    string str;
    cin >> str;
    int answer = 10;
    for (int i = 1; i < str.size(); ++i)
        answer = str[i] == str[i - 1] ? answer + 5 : answer + 10;
    cout << answer << '\n';
    return 0;
}