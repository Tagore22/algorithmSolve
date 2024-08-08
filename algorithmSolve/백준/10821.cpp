#include <iostream>

using namespace std;

// 풀이.
// 주어지는 문자열에 공백이 존재하지 않았으므로 getline()은 필요가 없었다.
// 따라서 하나의 문자열을 입력받았으면 되었고, 맨 처음과 마지막이 숫자로 확정되었으니
// 문자열에 존재하는 콤마의 수를 확인하여 + 1을 출력하면 된다.

int main()
{
    string str;
    cin >> str;
    int answer = 0;
    for (auto& c : str)
        if (c == ',')
            ++answer;
    cout << answer + 1 << '\n';
    return 0;
}