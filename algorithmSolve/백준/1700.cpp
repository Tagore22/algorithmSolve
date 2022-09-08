#include <iostream>
#include <vector>

using namespace std;

//처음 플러그를 꼽을때 꽉 못채우는 경우를 생각치못해서 오래걸렸다. T^T ex) 3,5  1,1,1,1,2 같은 경우 1번 플러그에만 꼽았으므로
//나중에 2가 나올때에는 다른 플러그를 뽑지 않아도 된다.

vector<int> board;
vector<bool> check;
int N, K;

//주어진 인덱스부터 맨 마지막 인덱스까지 순회하며 현재 꼽혀있는 플러그 중 등장하는 가장 마지막 원소를 찾는다.
//또한, 아예 등장하지 않는다면 그 플러그중 하나를 찾는다.

int FindPlug(int idx)
{
    vector<bool> now(check);
    int last_num = -1;
    for (int i = idx; i < K; ++i)
        if (now[board[i] - 1])
        {
            now[board[i] - 1] = false;
            last_num = board[i] - 1;
        }
    for (int i = 0; i < K; ++i)
        if (now[i])
            last_num = i;
    return last_num;
}

void MakeAnswer()
{
    int check_num = 0;
    for (int i = 0; i < N; ++i)
        if (!check[board[i] - 1])
        {
            ++check_num;
            check[board[i] - 1] = true;
        }
    int answer = 0;
    for (int i = N; i < K; ++i)
    {
        if (!check[board[i] - 1])
        {
            if (check_num < N)
            {
                ++check_num;
                check[board[i] - 1] = true;
            }
            else
            {
                int next = FindPlug(i + 1);
                check[next] = false;
                check[board[i] - 1] = true;
                ++answer;
            }
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    check.resize(K, false);
    for (int i = 0; i < K; ++i)
    {
        int a;
        cin >> a;
        board.push_back(a);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}