#include <iostream>

using namespace std;

//풀이
//가로와 세로로 string배열을 순회하되, '.'가 연속으로 2번이상 나오는 경우를 모두 센다.
//주의할점은 '.'가 연속으로 2번을 나오던 3번을 나오던 2번 이상이라면 모두 한가지 방법으로 세야 하기 때문에
//따로 변수를 두어서 확인해야한다는 것이다.
//ex) ..x.. 은 2가지 방법이며, ....x은 한가지 방법이다.

string board[100];
int N;

void MakeAnswer()
{
    pair<int, int> answer = make_pair(0, 0);
    int o;
    for (int i = 0; i < N; ++i)
    {
        o = 0;
        for (int j = 0; j < N; ++j)
        {
            if (board[i][j] == '.')
            {
                ++o; // '.'가 연속으로 몇번 나오는지를 센다.
                if (o == 2) //'.'가 연속으로 2번이상 나왔다면 그것 모두 한가지 방법으로 센다.
                    ++answer.first;
            }
            else
            {
                o = 0; //연속으로 나온 '.'의 수를 초기화한다.
            }
        }
    }

    for (int j = 0; j < N; ++j)
    {
        o = 0;
        for (int i = 0; i < N; ++i)
        {
            if (board[i][j] == '.')
            {
                ++o;
                if (o == 2)
                    ++answer.second;
            }
            else
            {
                o = 0;
            }
        }
    }

    cout << answer.first << ' ' << answer.second << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}