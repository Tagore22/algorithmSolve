#include <iostream>
#include <map>

using namespace std;

// 풀이.
// 총총이와 만났던 사람들과 그 사람들과 만났던 사람들의 수를 출력하는 문제다.
// 이 풀이에서는 map을 이용해 각 사람들의 상태를 저장하였지만 언제나 그렇듯 연관 컨테이너는 느리다.
// 따라서 이 풀이보다는 여태껏 만났던 사람들을 vector같은 배열에 저장하여 둘다 배열에 존재하지 않는다면 무시하고
// 둘중에 하나만 존재한다면 다른 하나를 저장하는 식으로 해도 될것 같다.

int N;

void MakeAnswer()
{
    map<string, bool> board;
    board["ChongChong"] = true;
    string str1, str2;
    int answer = 1;
    for (int iter = 0; iter < N; ++iter)
    {
        cin >> str1 >> str2;
        if (!board[str1] && board[str2])
        {
            board[str1] = true;
            ++answer;
        }
        else if (!board[str2] && board[str1])
        {
            board[str2] = true;
            ++answer;
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}