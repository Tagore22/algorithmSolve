#include <iostream>
#include <vector>

using namespace std;

// 16437번의 다른 풀이.
// 주어지는 자료가 늑대인지 양인지, 동물의 수, 연결된 정점 이렇게 셋인데
// 첫번째 자료는 나중에는 필요가 없다. 따라서 이걸 없애고 board의 자료형을 기존 구조체에서
// pair<int, int>로 변경하여 풀어보았다. 속도가 조금더 빠르지 않을까 했지만 별 차이 없었고
// 메모리와 코드수만 줄었다. board의 사용법 이외에는 모든것이 동일하다.

pair<int, int> board[123457];
vector<int> child[123457];
int N;

long long DFS(int idx)
{
    if (child[idx].size() == 0)
        // 더이상 animal로 구분하지 않고 수로 구분한다. 음수라면 늑대, 양수라면 양이다.
        return board[idx].first <= 0 ? 0 : board[idx].first;

    long long ans = 0;
    for (auto& n : child[idx])
        ans += DFS(n);

    ans += board[idx].first;

    return ans >= 0 ? ans : 0;
}

void MakeAnswer()
{
    cout << DFS(1) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    char a;
    int b, c;
    for (int i = 2; i <= N; ++i)
    {
        cin >> a >> b >> c;
        if (a == 'W')
            b *= -1;
        board[i] = make_pair(b, c);
        child[c].push_back(i);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}