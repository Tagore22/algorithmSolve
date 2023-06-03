#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이.
// 정렬 문제다. 여러가지 풀이가 있겠다만, 나는 백트래킹 문제로 풀었다.
// 한개씩 벡터에 원소값을 담되, 원소의 개수가 7개일때 그 합이 100이라면 출력을 하고
// 백트래킹 순회를 멈추었다. 다른 풀이가 있나 구글링을 좀 해보았는데 하나같이 풀이 뿐만 아니라
// 코드자체가 똑같은 것이 판을 쳤다. 조금 씁쓸했다.

// 자세한 설명은 주석으로 남긴다.

int board[9];
vector<int> answer;
bool isfind = false;

// 현재 벡터에 담긴 원소들의 합이 100인지 확인하는 함수.
bool Check()
{
    int ans = 0;
    for (int i = 0; i < answer.size(); ++i)
        ans += answer[i];

    return ans == 100;
}

// 백트래킹 함수. 하나씩 벡터에 담아보면서 원소의 개수가 7개인지, 그 합이 100인지 확인후
// 맞다면 출력후 순회를 멈춘다.
void BackTrack(int num)
{
    if (isfind)
        return;

    if (answer.size() == 7 && Check())
    {
        sort(answer.begin(), answer.end());
        for (int i = 0; i < answer.size(); ++i)
            cout << answer[i] << '\n';
        cout << '\n';
        isfind = true;
        return;
    }

    for (int i = num + 1; i < 9; ++i)
    {
        answer.push_back(board[i]);
        BackTrack(i);
        answer.pop_back();
    }
}

void MakeAnswer()
{
    BackTrack(-1);
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 9; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}