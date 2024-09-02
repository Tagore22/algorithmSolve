#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// 풀이.
// 후술하겠으나 배운게 많은 문제다. 우선 문제 크게 어렵지 않았다. 전형적인 정렬 및 그리디 문제로,
// 현재 강의가 기존 강의실중 사용할수 있는 즉, 강의실의 종료 시간이 현재 강의의 시작시간보다 작다면
// 그 강의실을 사용하면 되고, 그런 강의실이 없다면 새로운 강의실을 사용하는 문제다. 그렇기 위해서는
// 강의들을 시간순으로 정렬해야 한다. 여기까진 쉬운데 그 다음이 문제였다. 처음에는 어차피 최대 강의실은
// N개이니 N번을 순회하며 강의실을 찾았으나 이것은 각 강의마다 N개의 강의실을 순회해야 하기에
// 최대 N * N으로 10억을 훌쩍 뛰어넘었다. 따라서 매번 정렬을 사용하기로 했는데 sort는 NlogN의 시간복잡도를
// 지닌다. 따라서 더욱더 느렸다. 우선순위큐는 logN의 시간복잡도를 지니기에 이 문제에 적합했다. 찾아보기 전에는
// 왜 우선순위큐는 되고, sort()는 안되는지 한참 헤맸는데 상술한 이유가 있었다. 이것을 잊지 말자. 매번 정렬을
// 해야할때는 순회에 sort()를 끼워넣지 말고 우선순위큐를 사용하자. 각각 NlogN과 logN의 시간복잡도를 지니기 때문이다.

// 자세한 설명은 주석으로 남긴다.

pair<int, int> board[100000];
// 우선순위큐. 우선순위큐 혼자만 정렬순위가 반대다.
priority_queue<int, vector<int>, greater<int>> que;
int N;

void MakeAnswer()
{
    // 각 강의들을 시간순서에 따라 정렬한다.
    sort(board, board + N);
    // 가장 빠른 강의는 무조건 사용가능하다.
    que.push(board[0].second);
    for (int i = 1; i < N; ++i)
    {
        // 맨 앞 즉, 가장 빨리 끝나는 강의가 현재 강의의 시작시간보다 작다면
        // 이 강의실을 사용하면 되므로 기존의 종료 시간을 제거한다.
        if (que.top() <= board[i].first)
            que.pop();
        // 현재 강의의 종료시간을 추가한다. 만약 위 if문이 성립된다면 
        // 기존의 강의실을 사용하는 것으로 적용할수 있고, 그렇지 않다면 새로운
        // 강의실을 사용하는것과 같다.
        que.push(board[i].second);
    }
    // 사용했던 모든 강의실의 수는 que안의 원소수와 같다.
    cout << que.size() << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    int a;
    for (int i = 0; i < N; ++i)
        cin >> a >> board[i].first >> board[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}