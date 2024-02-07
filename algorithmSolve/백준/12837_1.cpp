#include <iostream>

using namespace std;

// 알고리즘 문제풀이를 처음 공부할때에도 펜윅 트리는 '그냥 구간트리를 쓰면 되겠지' 하고는 등한시 했는데
// 이번에 된통 당했다. 펜윅 트리가 더 간결하고 더 빠르기 때문이었다. 다만 비트마스크를 써야해서 
// 기억을 끄집어내야했다. 앞으로는 자주 사용해야겠다.

// 자세한 설명은 주석으로 남긴다.

long long board[1000001];
int N, Q;

// to까지의 모든 합들을 출력하는 함수. 각 원소값들은 1 ~ N까지의 총합들이므로 매개변수를 from, to로 늘려서
// from ~ to까지의 합을 출력할수 없다. 구간합을 직접 대입해보면 알수 있다.
// 1, 2, 3, 4가 존재할때 각 구간합은 1, 3, 6, 10이다. 이중 [3, 4]를 구한다고 할때
// 기존처럼 10 - 3은 7이 되지만, 10 + 6은 16이 되어 정답이 아니기 때문이다.
long long Query(int to)
{
    long long ans = 0;
    while (to > 0)
    {
        ans += board[to];
        // 오른쪽부터 가장 최초의 1을 제거하면 다음 인덱스값을 구할수 있다.
        to &= (to - 1);
    }
    return ans;
}

// to부터 모든 값들을 변화시키는 함수.
void Update(int idx, int value)
{
    while (idx <= N)
    {
        board[idx] += value;
        idx += (idx & -idx);
    }
}

void MakeAnswer()
{
    int a, b, c;
    for (int iter = 0; iter < Q; ++iter)
    {
        cin >> a >> b >> c;
        if (a == 1)
            Update(b, c);
        else
            cout << Query(c) - Query(b - 1) << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> Q;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}