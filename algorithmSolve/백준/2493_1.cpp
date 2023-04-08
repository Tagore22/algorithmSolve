#include <iostream>
#include <stack>

using namespace std;

// 2493번의 다른 풀이.
// 뒤에서부터가 아닌 앞에서부터 계산하였기에 기존에 배열이 필요없어져
// 잡아먹는 용량이 확줄어들었다. 원리는 스택이 텅 비거나, 자기 자신보다
// 큰 원소가 나타날때까지 스택에 저장된 원소들을 모두 삭제한다.
// 스택이 텅 비었다면 수신받을수 있는 탑이 없기에 0을 출력하고
// 존재한다면 바로 그것이 수신받는 탑이다.

int N;

void MakeAnswer()
{
    stack<pair<int, int>> sta; // 높이, 번호.    
    int cur;
    for (int i = 0; i < N; ++i)
    {
        cin >> cur;
        while (!sta.empty() && sta.top().first < cur)
            sta.pop();
        if (sta.empty())
            cout << 0 << ' ';
        else
            cout << sta.top().second + 1 << ' ';
        sta.push(make_pair(cur, i));
    }
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}