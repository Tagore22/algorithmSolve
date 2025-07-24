#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// 어느 정도 난이도가 있는 문제였다. 주의해야 할점은 뿅망치를 휘두르지 않아도 되는
// 경우를 for문에 같이 포함하기 위해 휘두르는 타이밍을 잘 선택해야했다.

// 자세한 설명은 주석으로 남긴다.

// 매번 정렬이 되어야하며 원소에 접근하기 용이한 우선순위 큐를 사용한다.
priority_queue<int> board;
int N, H, T;

void Solve()
{
    for (int iter = 0; iter <= T; ++iter)
    {
        // 사실상 바로 아래 첫번째 if문까지가 iter번 휘두른 순간이고
        // 그 이후로는 iter + 1번 휘두른 순간과 동일하다.
        int cur = board.top();
        board.pop();
        if (cur < H)
        {
            cout << "YES" << '\n';
            cout << iter << '\n';
            return;
        }
        // 상술하였듯 이 부분은 iter + 1번 휘두른 것과 일치하므로
        // iter가 T번째 일때에는 반값이 아닌 원본을 집어넣는다.
        if (iter != T)
            board.push(max(cur / 2, 1));
        else
            board.push(cur);
    }
    cout << "NO" << '\n';
    cout << board.top() << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> H >> T;
    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        board.push(num);
    }
}

int main()
{
    Input();
    Solve();
    return 0;
}