#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <string>

// Ǯ��. 
// �������� ��幮�����µ� �׵��� �콽������ �� ������ �����Ѱ��� 
// �ϳ� �����ɷȴ�. �� ���� �Ű澲���� ����.
// ��������� ��� ���� C���� �����ؼ� ���� �ִ� ��� ����� ���� �õ��غ���,
// A�� 0�϶��� C���� ����ϸ� �ȴ�. ������� ����� �ʾ�����
// �ߺ�ó������ ���̾��� �ð��� ���� ��ƸԾ���.
// ó������ set<water>�������� �ߺ��� ó���߾��µ� set.find()�� water�� ó���Ҽ� ������.
// int�� string���� ���� == ������ ���� �����Ǿ�������, water�� == ������ ���� ���� �����̶�
// == ������ �����Ҽ��� ������ �����̴�. �׷��� �ᱹ to_string()���� Ÿ���� ��ȯ���� set.find()�� �����ϴ�
// �ߵǾ���.

// �ڼ��� ������ �ּ����� �����.

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

// ���� ���°� ���� �������� �ʾҴ� ��Ȳ�̶�� que�� �߰��ϰ� check���� �߰��Ѵ�.
void CheckFunc(const water& cur)
{
    // �������� water�� ���Ͽ����� ����� ���� Ÿ���̱⿡ �񱳰� �Ұ�����.
    string str = to_string(cur.A) + to_string(cur.B) + to_string(cur.C);
    if (check.find(str) == check.end())
    {
        check.insert(str);
        que.push(cur);
    }
}

// ��� ��ȸ�� �����ϴ� �Լ�.
void MakeChoice(water& cur)
{
    int plus;
    // A���� �й�.
    // B�� �й�.
    plus = min(board[1] - cur.B, cur.A);
    cur.A -= plus;
    cur.B += plus;
    CheckFunc(cur);
    cur.A += plus;
    cur.B -= plus;

    // C�� �й�.
    plus = min(board[2] - cur.C, cur.A);
    cur.A -= plus;
    cur.C += plus;
    CheckFunc(cur);
    cur.A += plus;
    cur.C -= plus;

    // B���� �й�.
    // A�� �й�.
    plus = min(board[0] - cur.A, cur.B);
    cur.B -= plus;
    cur.A += plus;
    CheckFunc(cur);
    cur.B += plus;
    cur.A -= plus;

    // C�� �й�.
    plus = min(board[2] - cur.C, cur.B);
    cur.B -= plus;
    cur.C += plus;
    CheckFunc(cur);
    cur.B += plus;
    cur.C -= plus;

    // C���� �й�.
    // A�� �й�.
    plus = min(board[0] - cur.A, cur.C);
    cur.C -= plus;
    cur.A += plus;
    CheckFunc(cur);
    cur.C += plus;
    cur.A -= plus;

    // B�� �й�.
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
    // ���� ���������� �������� water������ set�� ����Ͽ����� �����Ͽ���.
    string str = to_string(0) + to_string(0) + to_string(board[2]);
    check.insert(str);

    while (!que.empty())
    {
        water cur = que.front();
        que.pop();

        if (cur.A == 0)
            answer.push_back(cur.C);

        // ���⼭ ��� ��ȸ�غ���.
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