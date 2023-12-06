#include <iostream>

using namespace std;

// 풀이.
// 언뜻 봤을땐 백트래킹 같은 걸로 복잡하게 풀어야 할것 같으나 실상은 그렇지 않다.
// 현재 위치 +- D에서의 D의 최대값을 구해야 하는데 이는 다른 말로 D만큼 이동했을때
// 모든 동생들과 만날수 있다는 것이며 이것은 현재 위치에서 동생들까지의 위치들에 대한
// 공약수임을 나타낸다. 또한 가장 큰 D를 구해야 하므로 결과적으로 동생들과의 거리들중
// 최대 공약수를 구하면 된다.

// 자세한 설명은 주석으로 남긴다.

int board[100001];
int N, S;

// 두 수 lhs와 rhs의 최대공약수를 구하는 함수.
int GDC(int lhs, int rhs)
{
    if (rhs == 0)
        return lhs;
    return GDC(rhs, lhs % rhs);
}

void MakeAnswer()
{
    // 첫번째 동생과의 거리로 시작한다.
    int answer = abs(S - board[0]);
    // 모든 동생들과의 거리들중 최대 공약수를 구한다.
    for (int i = 1; i < N; ++i)
        answer = GDC(answer, abs(S - board[i]));

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> S;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}