#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

// 풀이
// 오일러 회로와 비슷한 DFS문제이다.
// 1번부터 N번까지 순회하며 사이클이 존재하는지를 확인한다. 다만 후술하듯이 이미 확인해본 학생은 if문에서 제외된다.

// 2개의 bool 배열을 사용했는데 visit은 현재 DFS 순회중 방문하였는지의 여부이고, check는 해당 학생의 DFS 순회가 끝났는지에 대한 여부이다.
// 즉, visit은 이번 DFS 순회중 만난 학생들을 갱신하며, check는 순회가 종료된 학생들을 갱신한다.
// 사이클의 여부는 아직 DFS 순회가 종료되지 않은 학생을 이번 순회에서 다시 만났을 경우이다. 예시를 들어보면

// 1번이 2번을, 2번이 3번을, 3번이 4번을, 4번이 2번을 가르킨다고 치자. 1번을 제외한 2 ~ 4번이 사이클을 이루고 있다.
// 1번 학생에서 DFS순회를 시작하여 1 -> 2 -> 3 -> 4번을 순회하고 4번에서 다시 2번을 방문하게 되는데
// 2번이 이미 방문한 학생이다. 하지만 2번의 DFS 순회는 종료되지 않았다. 그렇기에 2 ~ 4번은 사이클을 이루며
// 4번의 다음 ~ 4번까지의 학생들이 사이클을 이룬다(2, 3, 4). 
// 앞서 찾아낸 사이클을 이루는 학생들의 수만큼을 N에서 제외하고, 1 ~ 4번의 학생은 더이상 방문이 불필요함으로
// check를 false로 갱신해준다. 그 이유를 조금더 자세히 설명하자면 당연하겠으나, 1 ~ 4번의 학생들에서 다른 학생들로 가는 길이
// 없기 때문이다. 만약 갈수 있는 길이 있었다면 DFS 순회로 인해 방문하였을 것이다. 그렇기에 1 ~ 4번의 학생들은 DFS순회가 필요없어진다.
// 반대로 어떤 학생 K로부터 1 ~ 4번중 아무 학생에게든 가는길이 있다고 하더라도 1 ~ 4번에서 K로 가는 길이 없었다는 것이기에 사이클은 
// 존재할수가 없기에 무시해도 된다.

int board[100001];
bool check[100001], visit[100001];
int T, N, answer;

void DFS(int start, vector<int>& path)
{
    if (board[path.back()] == start)
    {
        answer -= path.size();
        for (auto n : path)
            visit[n] = true;
        return;
    }

    if (check[path.back()])
        return;

    check[path.back()] = true;
    path.push_back(board[path.back()]);
    DFS(start, path);
}

void MakeAnswer()
{
    for (int i = 0; i < T; ++i)
    {
        cin >> N;
        answer = N;
        memset(visit, false, sizeof(visit));
        for (int j = 1; j <= N; ++j)
            cin >> board[j];
        for (int j = 1; j <= N; ++j)
            if (!visit[j])
            {
                memset(check, false, sizeof(check));
                vector<int> path(1, j);
                DFS(j, path);
            }
        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}