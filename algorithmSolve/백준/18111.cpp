#include <iostream>

using namespace std;

//�ܼ��� ���Ʈ���� �����ε�, ���̸� ������ �ؾ� �ּ����� �۾��ð��� ���Ҽ� �ִ��� �˼����⿡ 0~256�� ���� ��ȸ�ϸ� �ּҰ���
//���ؾ��Ѵ�. ������ �Լ������� �ش� ���̰� ���� ��ǥ�� ���̺��� �۴ٸ� ����� �����ϰ�, ���ٸ� �κ��丮�� �ִ� ����� �׾ư���.
//�Ѱ��� �Ǽ������� �ִµ� board�� ��ȸ�ذ��� block�� ���ڶ��� �̹� height�δ� �����⸦ �Ҽ� ���� �Ǵ��Ͽ� �ִ밪�� ��ȯ�Ѱ��̴�.
//������� �ݵ�� 0,0 ~ max,max�� ������ �ؾ��ϴ°��̶�� ���� ���⿡ �� �������� ����� ���ڶ��ٸ� �׶� ������ �ִ밪�� ��ȯ�ؾ�
//�Ѵ�. �̺κ��� ���ļ� ��� ����ߴ�.

const int MAX_NUM = 500;
int board[MAX_NUM][MAX_NUM];
int N, M, B;

int LandSmooth(int height)
{
    int answer = 0;
    int block = B;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            if (board[i][j] > height)
            {
                int minus = board[i][j] - height;
                answer += minus * 2;
                block += minus;
            }
            else if (board[i][j] < height)
            {
                int minus = height - board[i][j];
                //if (block < minus)     �̹� ��ǥ�� ����� ���ڶ� ������ ��ǥ���� ����ü� �ִٸ�, �׷��� �� ����� ���ڶ��� �ʴ´ٸ�
                //  return 987654321;    �ð��� ���Ҽ� �ִ�.
                answer += minus;
                block -= minus;
            }
        }
    return block < 0 ? 987654321 : answer; //����� ���ڶ� ���δ� �̰�����
}

void MakeAnswer()
{
    pair<int, int> answer = make_pair(987654321, 0);
    for (int i = 0; i <= 256; ++i)
    {
        int check = LandSmooth(i);
        answer = answer.first >= check ? make_pair(check, i) : answer;
    }
    cout << answer.first << ' ' << answer.second << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> B;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}