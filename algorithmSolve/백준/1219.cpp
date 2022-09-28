#include <iostream>
#include <vector>


//������ �˰��̿��� Ǯ���� TimeTrip�� �ſ� ������ �����̴�. �ִܰŸ��� ���ϵ�, �������� ��������Ŭ�� �����ϰų�, Ȥ��
//���������� �ƿ� ���������� ���ϴ°��� �����ؾ��Ѵ�. 51%���� Ʋ���� ���� Ʋ�ȳ� ������ �ôµ� �� �������� �ִܰŸ��� 
//Ÿ���� �߸��Ǿ�����(BF�Լ��� board). BF�Լ����� �ð����⵵�� V�� ���밪 * E�� ���밪�̱⿡ ��� �������� ����� ��쿡�� �� ���������� 
// �ִܰŸ��� �����Ҷ����� ��� ������ �ִܰŸ��� ���ŵȴ�. ��, �Ź� 100���� �پ��� 50 * 50 * 1,000,000�� �Ǿ� -25���� �Ǿ� int���� 
// �پ�ѱ⿡ long long���� �ؾ��Ѵ�.

using namespace std; //������� �ƴϴ�

vector<vector<pair<int, int>>> path;
vector<vector<bool>> Cango;
vector<int> money;
int N, from, to, M;
const long long MAXNUM = 1LL << 62;

void CalCango()
{
    for (int i = 0; i < N; ++i)
        Cango[i][i] = true;
    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                Cango[i][j] = Cango[i][j] || (Cango[i][k] && Cango[k][j]);
}

void BF()
{
    vector<long long> board(N, MAXNUM);
    board[from] = -money[from];
    for (int iter = 0; iter < N - 1; ++iter) // == 2 * (1+2) == 2 * 1 + 2 * 2 >>> �ڿ� 1,2�� �� ������ ������. �� ������ 3��. ������ 2��
        for (int here = 0; here < N; ++here)
            for (int i = 0; i < path[here].size(); ++i) //��� ������ ����Ǿ��ִ� ��쿣 �ż��� board[i]���� �ִ� 100����ŭ ������.
            {
                int there = path[here][i].first;
                int cost = path[here][i].second - money[there];

                board[there] = min(board[there], board[here] + cost);
            }
    for (int here = 0; here < N; ++here)
        for (int i = 0; i < path[here].size(); ++i)
        {
            int there = path[here][i].first;
            int cost = path[here][i].second - money[there];

            if (board[there] > board[here] + cost && (Cango[from][here] && Cango[here][to])) //���� ����Ŭ�� �����Ұ��.
            {
                cout << "Gee" << '\n';
                return;
            }
        }
    cout << -board[to] << '\n';
}

void MakeAnswer()
{
    CalCango();
    if (!Cango[from][to])
    {
        cout << "gg" << '\n';
        return;
    }
    BF();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> from >> to >> M;
    path.resize(N, vector<pair<int, int>>());
    Cango.resize(N, vector<bool>(N, false));
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        path[a].push_back(make_pair(b, c));
        Cango[a][b] = true;
    }
    for (int i = 0; i < N; ++i)
    {
        int a;
        cin >> a;
        money.push_back(a);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}