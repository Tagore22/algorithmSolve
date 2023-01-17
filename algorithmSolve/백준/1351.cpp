#include <iostream>
#include <map>

using namespace std;

//Ǯ��
//0���� N���� ���⿡�� N�� �ʹ� �Ǵ�. �׷��� 0���� ��ȸ�ϴ°� �ƴ� N���� �Ųٷ� ��ȸ�ϱ�� �Ͽ���.
//�׷���, N�� �ִ� 1���� ���ϱ⿡ DP�迭�� ����� �͵� ���� �ʾҴµ� �����غ��� �Ź� �ε����� �ּ� 2�� ���������⿡
//���� ��� �迭�� �� ����Ҹ��� ������. �׷��⿡ map���� DP�� �ϸ� �Ǿ���. ��������� Ǯ�̴�
//N���� �����Ͽ� �� P�� Q�� ���������� �ΰ��� ���� ������ ���� Ž���� �س����� �ȴ�.
//���� ��ʴ� ���� �ε������� �̹� ������ �ִ� ���(map�� �ش� ���Ұ��� 0�� �ƴ� ���)���� ���������� �ȴ�.
//0��°���� 1���� �̹� �˰� �ֱ� �����̴�. ���������� ���Ŀ� �����ؾ��ϴµ�, N�� �̹� int���� ��½ �پ�Ѿ���,
//P�� Q�� ���� �ִ� 10���̴�. ����, long long�� int�� ������ �°��� ��Ģ���� ���� long long�� �Ǳ⿡ N�� Q��
//int�� �ص� ����� ����. �ٸ�, board[N]���� int���� ���� ���⿡ map�� �ݵ�� map<long long, long long>�� �Ǿ���Ѵ�.

map<long long, long long> board; //�ε��� �Ӹ� �ƴ϶� �� ��ü�� int���� ����� �ִ�. �ݵ�� <long long, long long>.
long long N, P, Q; 

long long CalAnswer(long long num)
{
    if (board[num] != 0) //board[num]���� ������ �ִ� ���. �ּ� board[0]�� ������ �ֱ⿡ ������ʷ� �����ϴ�.
        return board[num];

    long long first = num / P;
    long long second = num / Q;

    return board[num] = CalAnswer(first) + CalAnswer(second); //board[num] = board[num / P] + board[num / Q].
}

void MakeAnswer()
{
    board.insert(make_pair(0, 1));
    cout << CalAnswer(N) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> P >> Q;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}