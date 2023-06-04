#include <iostream>
#include <map>

using namespace std;

// 풀이.
// 조금은 막무가내로 푼 풀이. 백트래킹으로 만들수 있는 모든 수를 만든후
// map에 그 수가 만들어질수 있는 수임을 체크한다.
// 마지막으로 1부터 시작하되, 1씩 증가하면서 현재 수가 만들어질수 있는지를 확인한후
// 만들어질수 없는 수라면 출력한다.

// map을 썼기에 속도도 엄청 느리고 메모리도 엄청 잡아먹는다.

map<int, int> check;
int board[20];
int N;

void BackTrack(int idx, int sum)
{
    if (sum != 0)
        check.insert(make_pair(sum, 1));

    for (int i = idx + 1; i < N; ++i)
        BackTrack(i, sum + board[i]);
}

void MakeAnswer()
{
    BackTrack(-1, 0);
    int answer = 1;
    while (true)
    {
        if (check[answer] == 0)
        {
            cout << answer << '\n';
            return;
        }
        ++answer;
    }
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