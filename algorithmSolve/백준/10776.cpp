#include <iostream>
#include <vector>
#include <queue>

using namespace std; //����� �׷�����.

//�������� ���ͽ�Ʈ�� ����� �׷��� �����̴�. �⺻ ���ͽ�Ʈ�󿡼� ũ�� ����� �ʾ�����, �¸��� ü���̶�� ������ �������� ��ġ���ʹ�.
//���� �ٽ� �����غ��� ���ͽ�Ʈ�� ���� ��� �����ϰ� �Ǵ� ���� �����ΰ� ����.

//Ǯ��
//�⺻Ʋ�� ���ͽ�Ʈ�� Ǯ�̿� ũ�� ���̴� ������, ����Ͽ����� �¸��� ü���� �߿��� ������ �Ǿ���.
//�⺻������ �ּ� �ð����� ���ؾ� �ϱ⿡ dist�� �ּҰ��� �����ذ��� ť�� ��ȸ������ �� �����غ��� �¸��� ü�¶����� ���� �ְ� ����
//����� ���� �����. �׷��⿡ dist�� �ܼ��� �������� �ε����� ������ �ʰ�, �¸��� ü�� ���� ������ �Ǵ� 2���迭�� �Ǿ�� �Ѵ�.
//�������ڸ� �Ȱ��� �ð��� �ɷ� �Ȱ��� ������ �����Ͽ�����, �� ��Ȳ�� ü�� ���� �����ؾ��Ѵٴ� ���̴�.
//������� �� �¸��� ü�º��� ����, dist[there][health - damage]�� ��� ��, �Ȱ��� ������ �Ȱ��� ü������ 
//������ ��캸�� �ð��� �� �ɸ��� �켱���� ť�� �����ϴ� ������ ť�� ��ȸ�Ͽ� dist[to - 1]�� ��� ����(0���� K������)�� �ٽ� ��ȸ�Ͽ�
//�ּҰ��� ����ϵ�, �ƿ� ���������� �������� ���Ͽ� ��� ���� MAX_NUM�϶����� -1�� ����Ѵ�.


vector<vector<pair<int, pair<int, int>>>> board; //������, �ð�, ü��
int K, N, M, from, to;
const int MAX_NUM = 987654321;

void DK()
{
    vector<vector<int>> dist(N, vector<int>(K + 1, MAX_NUM));
    dist[from - 1][K] = 0;
    priority_queue<pair<int, pair<int, int>>> que; //�ð�, ����, ü��
    que.push(make_pair(0, make_pair(from - 1, K)));

    while (!que.empty())
    {
        int cost = -que.top().first;
        int here = que.top().second.first;
        int health = que.top().second.second;
        que.pop();

        if (dist[here][health] < cost)
            continue;

        for (int i = 0; i < board[here].size(); ++i)
        {
            int there = board[here][i].first;
            int time = board[here][i].second.first;
            int damage = board[here][i].second.second;

            if (health > damage && cost + time < dist[there][health - damage])
            {
                dist[there][health - damage] = cost + time;
                que.push(make_pair(-dist[there][health - damage], make_pair(there, health - damage)));
            }
        }
    }

    int answer = MAX_NUM;
    for (int i = 0; i <= K; ++i)
        answer = min(answer, dist[to - 1][i]);

    if (answer != MAX_NUM)
        cout << answer << '\n';
    else
        cout << -1 << '\n';
}

void MakeAnswer()
{
    DK();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> K >> N >> M;
    board.resize(N, vector<pair<int, pair<int, int>>>());
    int a, b, time, damage;
    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b >> time >> damage;
        board[a - 1].push_back(make_pair(b - 1, make_pair(time, damage)));
        board[b - 1].push_back(make_pair(a - 1, make_pair(time, damage)));
    }
    cin >> from >> to;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}