#include <iostream>
#include <cstring>

using namespace std;

bool l[20];
bool r[20];
int board[10][10];
int N;

//�⺻���� ��Ʈ��ŷ���� ���ڰ� �ִ� 10*10�̱⿡ 2�� 100������ �Ǿ� �ð��ʰ��� ��������.
//�׷��� ����ĭ�϶��� �Ͼ�ĭ�϶��� �����Ͽ� �ι��� ���� ���� ���ؾ��Ѵ�.
//Ư���� y�� x���� �̿��Ͽ� �� �밢���� ����� �����ϴ��� ���ϴ� ����� ������.


int Simulation(int y, int x, bool isblack)
{
    if (y >= N)
        return 0;
    int answer = 0;
    int next_y = x + 2 >= N ? y + 1 : y;
    int next_x = x + 2 >= N ? (x % 2) ^ 1 : x + 2;

    //x-y+N-1�� y+x�� �� ���ʴ밢�� ���ο� �����ʴ밢�� ������ �ش��ϴ� ��ǥ��� ��ġ�ϱ⿡ �ϳ��� ������ ����� ������ �˾Ƴ��� �ִ�.
    if (board[y][x] == 1 && !l[x - y + N - 1] && !r[y + x])
    {
        l[x - y + N - 1] = r[y + x] = true;
        answer = max(answer, Simulation(next_y, next_x, isblack) + 1);
        l[x - y + N - 1] = r[y + x] = false;
    }
    answer = max(answer, Simulation(next_y, next_x, isblack));
    return answer;
}

void MakeAnswer()
{
    int answer = Simulation(0, 0, false);
    answer += Simulation(0, 1, true);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(l, false, sizeof(l));
    memset(r, false, sizeof(r));

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}