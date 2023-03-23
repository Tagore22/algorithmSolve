#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Ǯ��.
// ������ �����ϴ� ������ �� �Ｚsw��������. �̹����� ���ÿ���.
// ������� ������ ���������� �����ϰ� ���Ƴ��� �Ӹ��� ���� ������.

// �����ؾ��� ���� ���� 3�����̴�.
// 
// 1. 0 ~ N���� �߿��� �ü��� ��ġ 3���� �����ϴ� ��Ʈ��ŷ �Լ�.
// 2. �ü��� ��ġ�� ������� ������ �����ϴ� �Լ�.
// 3. ������ �������� ������ �̵��ϴ� �Լ�.

// ���� ���� �����Ѱ��� 2���̴�. ������ ���� 2���� �̱� �����̴�.

// 1. �켱������ �Ÿ��� ���� ª�� ���� ������.
// 2. ���� ����� ���� 2�� �̻��̶�� ���� ���ʿ� �ִ� ���� ������.

// �׷��� 2�� ���ǹ����� ���� ����� �����Ѵ�.
// �ڼ��� ������ �ּ��� �޾Ƴ��ڴ�.


// �ʱ� �迭�� �̵� �ĸ� ���� ��ü�� �迭.
vector<vector<int>> board, temp;
int N, M, D, enemy_num = 0, answer = 0;


// �ü��� ���� �����ϴ� �Լ�. 
int Attack(const vector<int>& archer)
{
    // �̹��Ͽ��� �ü��� ���� ����.
    vector<pair<int, int>> dead;
    
    // ���� ����� ��ġ. �ʱⰪ�� �ü��� ��ġ + ���������� ��Ÿ�(D)��ŭ�̴�.
    pair<int, int> cur;

    // ���� �Ÿ��� ���ο� �������� �Ÿ�.
    int cur_dis, new_dis;
    for (int iter = 0; iter < archer.size(); ++iter)
    {
        // ����Ͽ��� �ʱⰪ�� �ü��� ��ġ���� ���������� ��Ÿ�(D)��ŭ �̵��� ���̴�.
        cur = make_pair(N, archer[iter] + D);
        cur_dis = D;
        for (int i = N - 1; i >= 0; --i)
            for (int j = 0; j < M; ++j)

                // ������ �����Ѵٸ� ���ǹ��� �����Ѵ�.
                if (temp[i][j] == 1)
                {
                    // ���ο� �������� �Ÿ� ���.
                    new_dis = abs(N - i) + abs(archer[iter] - j);

                    // ���ο� �Ÿ��� �� �����ų�, ���� �Ÿ��� ������ ���ο� ���� �� ���ʿ� �ִ� ��쿡�� ���� ����� �ٲ��.
                    if (new_dis < cur_dis || ((new_dis == cur_dis) && j < cur.second))
                    {
                        cur = make_pair(i, j);
                        cur_dis = new_dis;
                    }
                }

        // ���� ����� �̹� �����ϰų�, �ƿ� ���� ����� ã�� ���Ѱ� �ƴ϶�� ���� ���Խ�Ų��.
        if (find(dead.begin(), dead.end(), cur) == dead.end() && cur.second != archer[iter] + D)
            dead.push_back(cur);
    }

    for (int i = 0; i < dead.size(); ++i)
        temp[dead[i].first][dead[i].second] = 0;

    // �̹��� ������ ���� ��ȯ.
    return dead.size();
}


// ������ �̵��� �����ϴ� �Լ�. �׳� �Ʒ������� ���� �����ϸ� �ȴ�.
int Move()
{
    int ans = 0;
    for (int i = 0; i < M; ++i)
        if (temp[N - 1][i] == 1)
            ++ans;

    for (int i = N - 1; i >= 1; --i)
        for (int j = 0; j < M; ++j)
            temp[i][j] = temp[i - 1][j];

    for (int i = 0; i < M; ++i)
        temp[0][i] = 0;

    // �������� ����� ������ �� ��ȯ.
    return ans;
}

// �ü��� ���ݰ� ������ �̵��� ��� ȣ���ϴ� �Լ�.
// ������ ��� ����������� ��ӵǱ⿡ ������ ���� �����ذ��� �Ѵ�.
void Play(const vector<int>& archer)
{
    temp = board;
    int cur_enemy = enemy_num;
    int ans = 0, cur;

    while (cur_enemy > 0)
    {
        cur = Attack(archer);
        ans += cur;
        cur_enemy -= cur;
        cur_enemy -= Move();
    }

    answer = max(answer, ans);
}

void BackTrack(int idx, vector<int> archer)
{
    if (archer.size() == 3)
    {
        Play(archer);
        return;
    }

    for (int i = idx + 1; i < M; ++i)
    {
        archer.push_back(i);
        BackTrack(i, archer);
        archer.pop_back();
    }
}

void MakeAnswer()
{
    BackTrack(-1, vector<int>());

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> D;
    board.resize(N, vector<int>(M, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
                ++enemy_num;
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}