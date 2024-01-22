#include <iostream>
#include <string>

using namespace std;

// 풀이.
// 최대 1000자리에 해당하는 긴 덧셈을 구현하는 문제다.
// 당연히 long long의 범위값을 아득히 벗어나기 때문에 string으로 덧셈을 구현하였다.
// 다른 풀이를 보니 vector 하나로 긴 수를 표현하여 푸는 것이 더 빨랐다.
// string은 매번 int -> string, string -> int로의 변환이 있어서 그런것 같다.

// 자세한 설명은 주석으로 남긴다.

string board[4];
int N;

string PlusStr(string lhs, string rhs)
{
    // lhs가 더 이전의 수이기 때문에 무조건 길이가 짧거나 같다.
    // 그렇기에 lhs의 길이를 rhs와 맞춰준다.
    while (lhs.size() != rhs.size())
    {
        lhs = "0" + lhs;
    }
    int plus = 0;
    string str = "";
    // 맨 뒷자리부터 순회를 하며 각 자리수를 더한다.
    for (int i = lhs.size() - 1; i >= 0; --i)
    {
        int cur = (lhs[i] - '0') + (rhs[i] - '0') + plus;
        plus = cur >= 10 ? 1 : 0;
        cur %= 10;
        str = to_string(cur) + str;
    }
    str = plus == 1 ? "1" + str : str;
    return str;
}

int main()
{
    cin >> N;
    board[1] = board[2] = "1";
    for (int i = 3; i <= N; ++i)
        board[i % 3] = PlusStr(board[(i - 2) % 3], board[(i - 1) % 3]);
    cout << board[N % 3] << '\n';
    return 0;
}