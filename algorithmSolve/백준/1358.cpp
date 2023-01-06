#include <iostream>
#include <cmath>

using namespace std;

//Ǯ��
//��ũ�ȿ� �ִ� ����� ���� �ִ� 3���ε� 1. ���� ���ȿ� �����Ұ�� 2. �߾� ���簢���� ������ ��� 3. ���� ���ȿ� �����Ұ���̴�.
//�ٸ� ���� ���簢���� �߰��� �����Ѵ��ص� �ļ��� ���ǹ����� ��� �˻��Ҽ� �ֱ⿡ ������� �ʴ´�.
//�� ���� �߽ɰ� ������, �����κ����� �Ÿ��� �̸� ����س��� if���ǹ����� ������ �Ÿ��� ���������� ���ų�, ���簢���� ���� �ȿ� �����Ѵٸ�
//�� ������ ��ũ�ȿ� �����ϱ⿡ answer�� ���� 1�� �ø���. �׷��� ��� �������� �迭�� ��ȸ�Ͽ� ������ answer���� ����ϸ� �ȴ�.
//�ٸ�, �Ÿ��� ���Ҷ� �����ٰ����� ���� ������ ������ �����Ƿ� �׳� �������� ������ �ʰ�, ���������� �����Ͽ� ���Ѵ�.

pair<int, int> board[50]; //first�� y�� �ƴ� x�ӿ� �����Ұ�.
int W, H, X, Y, P;

bool InLink(int x, int y)
{
    if (X <= x && x <= X + W && Y <= y && y <= Y + H)
        return true;
    else
        return false;
}

void MakeAnswer()
{
    int rad = H / 2;
    int rad_pow = pow(rad, 2);
    pair<int, int> first_circle = make_pair(X, Y + rad);
    pair<int, int> second_circle = make_pair(X + W, Y + rad);

    int answer = 0;
    for (int i = 0; i < P; ++i)
    {
        int first_dist = pow(board[i].first - first_circle.first, 2) + pow(board[i].second - first_circle.second, 2);
        int second_dist = pow(board[i].first - second_circle.first, 2) + pow(board[i].second - second_circle.second, 2);

        if (first_dist <= rad_pow || second_dist <= rad_pow || InLink(board[i].first, board[i].second))
            ++answer;
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> W >> H >> X >> Y >> P;
    for (int i = 0; i < P; ++i)
        cin >> board[i].first >> board[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}