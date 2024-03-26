#include <iostream>
#include <map>

using namespace std;

// 풀이.
// 주어지는 확장자들과 그 갯수를 저장하여 사전순으로 출력하는 문제이다.
// map을 쓰는게 편하긴 하지만 역시 조금 느리다. 확장자들을 vector에 모두 저장해놓고
// 정렬하여 확장자와 갯수를 출력하는 방법 또한 존재한다.

// 자세한 설명은 주석으로 남긴다.

map<string, int> board;
int N;

void MakeAnswer()
{
    for (int iter = 0; iter < N; ++iter)
    {
        string str;
        cin >> str;
        int from = 0;
        // 확장자가 시작되는 인덱스값을 찾는다.
        for (int i = 0; i < str.size(); ++i)
            if (str[i] == '.')
            {
                from = i;
                break;
            }
        // 확장자의 갯수를 map에서 1 늘려준다.
        ++board[str.substr(from + 1)];
    }
    // map을 순회하며 확장자와 그 갯수를 출력한다.
    for (auto iter = board.begin(); iter != board.end(); ++iter)
        cout << iter->first << ' ' << iter->second << '\n';
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