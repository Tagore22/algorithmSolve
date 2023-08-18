#include <iostream>

using namespace std;

// 풀이.
// 어렵지 않은 문제다. 다만 한가지 주의해야할점이 있는데
// 다른 모든 수들은 각각 한번씩밖에 못쓰지만 6, 9는 뒤집어서 대체용으로 쓸수 있다는 것이다.
// 따라서 수를 입력받은수 처음부터 끝까지 순회하며 등장한 수들의 수를 저장하되, 6과 9는 합쳐서 2로 나눈수로
// 대체하여 가장 큰 값을 출력하면 된다.

// 자세한 설명은 주석으로 남긴다.

string str;
int board[10];

void MakeAnswer()
{
    // 처음부터 끝까지 순회하며 등장한 수를 저장한다.
    for (int i = 0; i < str.size(); ++i)
        ++board[str[i] - '0'];

    int ans = 0;
    // 0 ~ 9중에서 6과 9를 제외한 나머지 수들의 등장횟수중 최대수를 구한다.
    for (int i = 0; i < 9; ++i)
        if (i != 6)
            ans = max(ans, board[i]);

    // 6과 9의 등장횟수를 더해 2로 나누되, 나머지가 존재한다면 증가시킨다. ex) 3같은 경우는 2로 나누었을때 1이지만 
    // 실제로는 2개가 필요하다.
    int sixornine = (board[6] + board[9]) / 2;
    if (sixornine * 2 != board[6] + board[9])
        ++sixornine;

    // 6과 9의 등장횟수와 현재 최대 등장횟수의 최대값을 출력한다.
    ans = max(ans, sixornine);
    cout << ans << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}