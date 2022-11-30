#include <iostream>

using namespace std;

//풀이
//주어지는 N개의 문자열들을 맨 뒤부터 부분문자열로 나누어 N개의 부분문자열들이 모두 다른 최초의 부분문자열 자리수를 구하면 된다.
//어떠한 자리수부터 맨 뒤까지 부분문자열을 만드는데에 string.substr이라는 좋은 함수가 있기에 이걸 이용하면 나머지는 다른 모든 부분문자열을 비교하는
//2중 for문만 구현하면 된다.

string board[1000];
int N;

void MakeAnswer()
{
    int answer = 1;
    bool isfind;
    for (int i = board[0].size() - 1; i >= 1; --i)
    {
        isfind = true;
        for (int from = 0; from < N - 1; ++from)
        {
            for (int to = from + 1; to < N; ++to)
                if (board[from].substr(i) == board[to].substr(i))
                {
                    isfind = false;
                    break;
                }
            if (!isfind)
                break;
        }

        if (!isfind)
            ++answer;
        else
            break;
    }
    cout << answer << '\n';
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