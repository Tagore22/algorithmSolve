#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 풀이.
// 우선순위 큐를 이용하여 여러번 정렬하며 옮기는 문제인것 같은데 그냥 벡터로 풀었다.
// 우선순위 큐를 이용하면 매번 순회할 필요가 없으니 훨씬더 빠르긴 할것이다.

// 자세한 설명은 주석으로 남긴다.

pair<int, int> board[100000]; // 끝나는 시간, 사용한 횟수.
vector<pair<int, int>> answer;
int N;

void MakeAnswer()
{
    // 가장 빨리 시작하고 가장 빨리 끝나는 순서로 정렬.
    sort(board, board + N);
    answer.push_back(make_pair(board[0].second, 1));
    // 모든 인원들을 순회하며 넣을수 있는 곳에 넣고, 넣을수 없다면 새로운
    // 컴퓨터를 추가한다.
    for (int iter = 1; iter < N; ++iter)
    {
        int idx = answer.size();
        bool IsFind = false;
        for (int i = 0; i < idx; ++i)
        {
            if (answer[i].first <= board[iter].first)
            {
                answer[i] = make_pair(board[iter].second, answer[i].second + 1);
                IsFind = true;
                break;
            }
        }
        if (!IsFind)
            answer.push_back(make_pair(board[iter].second, 1));
    }
    cout << answer.size() << '\n';
    for (auto& now : answer)
        cout << now.second << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i].first >> board[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}