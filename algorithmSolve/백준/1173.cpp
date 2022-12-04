#include <iostream>

using namespace std;

//Ǯ��
//�ʱ� �ƹڿ��� �����Ͽ� ��� �����ϴ� �ƹڰ��� ���� �ִ� �ƹں��� �۴ٸ� ��� �Ͽ� �ƹ��� �ø���, �ִ� �ƹں��� ũ�ٸ� �޽��� �ؼ� �ƹ��� ���ҽ�Ų��. �ٸ�, �ּ�
//�ƹں��� �۾����� �ȵǱ⿡ max�Լ��� �ִ밪�� ���ؾ��Ѵ�. ����, �ֽô��� ��� �Ұ����� ��찡 �ִµ�, �ּ� �ƹڰ� �ִ� �ƹ��� ���̰� ��� �����ϴ� �ƹں��� ����
//����̴�. �̷� ���� -1�� ����Ѵ�. 

int N, m, M, T, R;

void MakeAnswer()
{
    if (M - m < T) //�ֽô��� ��� �Ұ��� �Ұ��. �� �ʱ� �ƹڰ� �ִ� �ƹ��� ���̰� ��ҽ� �����ϴ� �ƹں��� ���� ���.
    {
        cout << -1 << '\n';
        return;
    }

    int answer = 0, cur = m, ex = 0;
    while (ex < N)
    {
        if (cur + T > M) //�޽��� �ؾ��ϴ� ���.
        {
            cur = max(cur - R, m);
        }
        else //��� �ص� �Ǵ� ���.
        {
            cur += T;
            ++ex;
        }
        ++answer;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> m >> M >> T >> R;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}