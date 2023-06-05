#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 풀이.
// 완전 이진 탐색중 중위순회에 관한 문제였다.
// 재귀를 사용하여 왼쪽 >> 자기자신 >> 오른쪽으로 순회 및 값을 저장하여
// 출력해주면 된다.

// 자세한 설명은 주석으로 남긴다.

// 각 깊이마다 값을 기록하는 벡터.
vector<vector<int>> answer;
vector<int> board;
int K;

// 중위 순회를 구현하는 함수. 상술하였듯
// 왼쪽 >> 자기 자신 >> 오른쪽 순으로 순회하며 그 값을 answer에 기록한다.
void Inorder(int dep, const vector<int>& cur)
{
    // 현재 가장 말단노드에 도착했다면 그 값을 기록하고 빠진다.
    if (cur.size() == 1)
    {
        answer[dep].push_back(cur[0]);
        return;
    }

    int piv = cur.size() / 2;
    Inorder(dep + 1, vector<int>(cur.begin(), cur.begin() + piv));
    answer[dep].push_back(cur[piv]);
    Inorder(dep + 1, vector<int>(cur.begin() + piv + 1, cur.end()));
}

void MakeAnswer()
{
    // 중위 순회.
    Inorder(0, board);
    for (int i = 0; i < answer.size(); ++i)
    {
        for (int j = 0; j < answer[i].size(); ++j)
            cout << answer[i][j] << ' ';
        cout << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> K;
    answer.resize(K, vector<int>());
    int iter = pow(2, K) - 1;
    for (int i = 0; i < iter; ++i)
    {
        int num;
        cin >> num;
        board.push_back(num);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}