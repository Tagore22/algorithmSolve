#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <string>

// 풀이. 
// 오랜만에 골드문제였는데 그동안 녹슬었는지 이 문제가 복잡한건지 
// 꽤나 오래걸렸다. 뭐 굳이 신경쓰지는 말자.
// 결과적으로 모든 물이 C에서 시작해서 갈수 있는 모든 경우의 수를 시도해보며,
// A가 0일때의 C값을 출력하면 된다. 여기까진 어렵지 않았으나
// 중복처리에서 어이없게 시간을 오래 잡아먹었다.
// 처음에는 set<water>형식으로 중복을 처리했었는데 set.find()가 water로 처리할수 없었다.
// int나 string같은 경우는 == 연산이 원래 구현되어있으나, water의 == 연산은 내가 만든 형식이라
// == 연산을 실행할수가 없었기 때문이다. 그래서 결국 to_string()으로 타입을 변환한후 set.find()를 실행하니
// 잘되었다.

// 자세한 설명은 주석으로 남긴다.

struct water
{
    int A;
    int B;
    int C;
};

using namespace std;

vector<int> answer;
int board[3];
queue<water> que;
set<string> check;

// 현재 상태가 아직 존재하지 않았던 상황이라면 que에 추가하고 check에도 추가한다.
void CheckFunc(const water& cur)
{
    // 기존에는 water로 비교하였으나 사용자 형식 타입이기에 비교가 불가능함.
    string str = to_string(cur.A) + to_string(cur.B) + to_string(cur.C);
    if (check.find(str) == check.end())
    {
        check.insert(str);
        que.push(cur);
    }
}

// 모든 순회를 구현하는 함수.
void MakeChoice(water& cur)
{
    int plus;
    // A에서 분배.
    // B로 분배.
    plus = min(board[1] - cur.B, cur.A);
    cur.A -= plus;
    cur.B += plus;
    CheckFunc(cur);
    cur.A += plus;
    cur.B -= plus;

    // C로 분배.
    plus = min(board[2] - cur.C, cur.A);
    cur.A -= plus;
    cur.C += plus;
    CheckFunc(cur);
    cur.A += plus;
    cur.C -= plus;

    // B에서 분배.
    // A로 분배.
    plus = min(board[0] - cur.A, cur.B);
    cur.B -= plus;
    cur.A += plus;
    CheckFunc(cur);
    cur.B += plus;
    cur.A -= plus;

    // C로 분배.
    plus = min(board[2] - cur.C, cur.B);
    cur.B -= plus;
    cur.C += plus;
    CheckFunc(cur);
    cur.B += plus;
    cur.C -= plus;

    // C에서 분배.
    // A로 분배.
    plus = min(board[0] - cur.A, cur.C);
    cur.C -= plus;
    cur.A += plus;
    CheckFunc(cur);
    cur.C += plus;
    cur.A -= plus;

    // B로 분배.
    plus = min(board[1] - cur.B, cur.C);
    cur.C -= plus;
    cur.B += plus;
    CheckFunc(cur);
    cur.C += plus;
    cur.B -= plus;
}

void BFS()
{
    que.push(water{ 0, 0, board[2] });
    // 위와 마찬가지로 기존에는 water형식의 set을 사용하였으나 변경하였다.
    string str = to_string(0) + to_string(0) + to_string(board[2]);
    check.insert(str);

    while (!que.empty())
    {
        water cur = que.front();
        que.pop();

        if (cur.A == 0)
            answer.push_back(cur.C);

        // 여기서 모두 순회해본다.
        MakeChoice(cur);
    }
}

void MakeAnswer()
{
    BFS();
    sort(answer.begin(), answer.end());
    for (int i = 0; i < answer.size(); ++i)
        cout << answer[i] << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 3; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}