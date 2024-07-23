#include <iostream>

using namespace std;

// 풀이.
// 문제를 주절주절 어렵게 설명해 놓았지만 결과적으로는 최소 스패닝 트리를 구해야 한다.
// 모든 컴퓨터를 연결하는 최소 스패닝 트리의 길이를 구해서 모든 랜선에서 제외해주면 된다.
// 그런데 문제가 여러가지 꼬아놨는데 주어지는 랜선들중 가장 짧게 연결된 선들을 구해야한다.
// 하지만 단순히 짧은걸 찾는게 아닌 0이 아닌 수들중 가장 짧은 수를 구해야 한다. 최대한 연결된
// 것들중 최소 스패닝 트리를 구해야하기 때문이다. 최소 스패닝 트리의 변화성 깊은 문제인데 잘 풀어서 다행이다.

// 자세한 설명은 주석으로 남긴다.

int board[50][50] = { 0, };
int N, answer = 0;

// 프림 알고리즘을 통해 최소 스패닝 트리를 구하는 문제.
void Prim()
{
    // 2차원 이상의 배열에서는 이니셜라이즈를 통해서 한번에 초기화가 되었는데 1차원에서는 안된다.
    int dist[50] = { 0, };
    for (int i = 1; i < N; ++i)
        dist[i] = 987654321;
    bool visit[50] = { false, };
    for (int iter = 0; iter < N; ++iter)
    {
        // 프림 알고리즘의 전형적인 틀. next가 -1로 초기화되어 존재하는건 무조건 하나 이상의 정점을
        // 찾아야 하기 때문이다.
        int next = -1;
        for (int i = 0; i < N; ++i)
        {
            // 상술한대로 프림에서 조금 변형되었다. dist[i]가 987654321이라는 것은 현재 연결된 정점이 없다는 것이므로
            // 그 정점으로 도달해서는 안된다. 
            if (!visit[i] && dist[i] != 987654321 && (next == -1 || dist[next] > dist[i]))
                next = i;
        }

        // 다음 정점을 찾지 못했다는 것은 전부 이어지지 않았다는 소리이기에 -1을 출력하고 탈출한다.
        if (next == -1)
        {
            cout << -1 << '\n';
            return;
        }

        // 총 랜선 길이에서 현재 길이만큼을 제외하고 정점의 방문여부를 갱신한다.
        answer -= dist[next];
        visit[next] = true;
        for (int i = 0; i < N; ++i)
        {
            // 현재 정점에서 연결된 모든 정점들중 dist값을 갱신한다.
            if (!visit[i] && board[next][i] != 0)
                dist[i] = min(dist[i], board[next][i]);
        }
    }
    cout << answer << '\n';
}

void MakeAnswer()
{
    Prim();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str; // 소문자면 96을 뺀다. 대문자면 38을 뺀다.
        for (int j = 0; j < N; ++j)
        {
            // 주어진 알파벳을 정수로 변환한다. 각각 대문자, 소문자, 0일때의 경우가 존재한다.
            int cur;
            if ('a' <= str[j] && str[j] <= 'z')
                cur = str[j] - 96;
            else if ('A' <= str[j] && str[j] <= 'Z')
                cur = str[j] - 38;
            else
                cur = 0;
            // 상술한대로 0과 0이 아닌값이 존재한다면 0이 아닌값을 우위에 두어야한다.
            // 최대한 각 컴퓨터들 사이의 연결고리를 찾아야 최소 스패닝 트리를 찾기에도 유리하기 때문이다.
            // 따라서 기존 거리가 0이라면 무조건 갱신해주고, 그렇지 않을 경우 현재 값이 0이 아니면서
            // 기존값보다 작다면 갱신해준다.
            if (board[i][j] == 0 || (cur != 0 && board[i][j] > cur))
            {
                board[i][j] = cur;
                board[j][i] = cur;
            }
            // 랜선의 총길이를 추가해준다.
            answer += cur;
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}