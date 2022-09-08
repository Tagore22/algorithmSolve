#include <iostream>
#include <vector>

using namespace std;

//ó�� �÷��׸� ������ �� ��ä��� ��츦 ����ġ���ؼ� �����ɷȴ�. T^T ex) 3,5  1,1,1,1,2 ���� ��� 1�� �÷��׿��� �ž����Ƿ�
//���߿� 2�� ���ö����� �ٸ� �÷��׸� ���� �ʾƵ� �ȴ�.

vector<int> board;
vector<bool> check;
int N, K;

//�־��� �ε������� �� ������ �ε������� ��ȸ�ϸ� ���� �����ִ� �÷��� �� �����ϴ� ���� ������ ���Ҹ� ã�´�.
//����, �ƿ� �������� �ʴ´ٸ� �� �÷����� �ϳ��� ã�´�.

int FindPlug(int idx)
{
    vector<bool> now(check);
    int last_num = -1;
    for (int i = idx; i < K; ++i)
        if (now[board[i] - 1])
        {
            now[board[i] - 1] = false;
            last_num = board[i] - 1;
        }
    for (int i = 0; i < K; ++i)
        if (now[i])
            last_num = i;
    return last_num;
}

void MakeAnswer()
{
    int check_num = 0;
    for (int i = 0; i < N; ++i)
        if (!check[board[i] - 1])
        {
            ++check_num;
            check[board[i] - 1] = true;
        }
    int answer = 0;
    for (int i = N; i < K; ++i)
    {
        if (!check[board[i] - 1])
        {
            if (check_num < N)
            {
                ++check_num;
                check[board[i] - 1] = true;
            }
            else
            {
                int next = FindPlug(i + 1);
                check[next] = false;
                check[board[i] - 1] = true;
                ++answer;
            }
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    check.resize(K, false);
    for (int i = 0; i < K; ++i)
    {
        int a;
        cin >> a;
        board.push_back(a);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}