#include <iostream>

using namespace std;

// 풀이.
// 자주 등장하는 구간 쿼리 문제다.
// 이번에는 조금 특별한점이 최소값이나 최대값이 아닌 양수인지 음수인지 0인지에 대해 알아야한다.
// 다만 어려울것 없이 노드가 더이상 내려갈곳 없어 노드값이 바뀔때 양수라면 1, 음수라면 -1, 0이라면 0으로
// 값을 초기화해주면 이 이후 단순 곱하기 연산으로 각 구간별 곱셈값을 알아낼수 있기 때문에 어렵지 않다.

// 자세한 설명은 주석으로 남긴다.

int board[100001], arr[400004];
int N, K;

// 초기화 함수.
int Init(int left, int right, int node)
{
    // 노드의 맨 마지막에 다다랐을때 현재 값이 양수인지 음수인지 0인지에 따라 
    // 초기화값을 바꿔준다.
    if (left == right)
    {
        if (board[left] > 0)
            return arr[node] = 1;
        else if (board[left] == 0)
            return arr[node] = 0;
        else
            return arr[node] = -1;
    }
    int mid = (left + right) / 2;
    return arr[node] = Init(left, mid, node * 2) * Init(mid + 1, right, node * 2 + 1);
}

// 쿼리 함수.
int Query(int left, int right, int node, int node_left, int node_right)
{
    if (left > node_right || node_left > right)
        return 1;
    if (left <= node_left && node_right <= right)
        return arr[node];
    int mid = (node_left + node_right) / 2;
    int lhs = Query(left, right, node * 2, node_left, mid);
    int rhs = Query(left, right, node * 2 + 1, mid + 1, node_right);
    return lhs * rhs;
}

// 값을 변경하는 함수.
int Update(int idx, int value, int node, int left, int right)
{
    if (idx < left || idx > right)
        return arr[node];
    if (left == right)
    {
        if (value > 0)
            return arr[node] = 1;
        else if (value == 0)
            return arr[node] = 0;
        else
            return arr[node] = -1;
    }
    int mid = (left + right) / 2;
    int lhs = Update(idx, value, node * 2, left, mid);
    int rhs = Update(idx, value, node * 2 + 1, mid + 1, right);
    return arr[node] = lhs * rhs;
}

void MakeAnswer()
{
    while (cin >> N >> K)
    {
        string answer = "";
        for (int i = 1; i <= N; ++i)
            cin >> board[i];
        Init(1, N, 1);
        char order;
        int i, j;
        for (int iter = 0; iter < K; ++iter)
        {
            cin >> order >> i >> j;
            if (order == 'C')
            {
                Update(i, j, 1, 1, N);
            }
            else
            {
                int num = Query(i, j, 1, 1, N);
                if (num > 0)
                    answer += "+";
                else if (num == 0)
                    answer += "0";
                else
                    answer += "-";
            }
        }
        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}