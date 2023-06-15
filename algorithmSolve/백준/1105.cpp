#include <iostream>

using namespace std;

// Ǯ��.
// �־����� ���� 1 ~ 20������ �ܼ��� 1�� �����ϸ� Ǫ�� ������δ� �Ұ����ߴ�.
// �׷��� ������ �̿��� �׸��� �������ٵ� �� ������ �� �������� �ʾҴ�.
// �ᱹ �ݷʵ��� ã�ƺ��� Ǯ����.

// �ڼ��� ������ �ּ����� �����.

int L_array[10], R_array[10];
int L, R, L_num, R_num;

void MakeArray()
{
    L_num = -1;
    while (L >= 1)
    {
        ++L_num;
        L_array[L_num] = L % 10;
        L /= 10;
    }

    R_num = -1;
    while (R >= 1)
    {
        ++R_num;
        R_array[R_num] = R % 10;
        R /= 10;
    }
}

void MakeAnswer()
{
    // 1. L�� R�� ���ٸ� 8�� ������ ����Ѵ�.
    // 2. ���� �ٸ��ٸ� 
    // 2-1. ���� �ڸ����� ���ٸ� ������ �ڸ����� ��ȸ�Ѵ�.
    // 2-1-1. �� �ڸ����� �����鼭 �� ���� 8�̶�� ���� 1 �����Ѵ�.
    // 2-1-2. �� �ڸ����� ������ 8�� �ƴ϶�� �����ϰ� �Ѿ��. << �̺κ��� �������� ���߾���.
    // 2-1-3. �� �ڸ����� �ٸ��ٸ� �ݺ����� Ż���Ѵ�.
    // 2-2. ���� �ڸ����� �ٸ��ٸ� 0.
    int answer = 0;
    if (L == R)
    {
        while (L >= 1)
        {
            if (L % 10 == 8)
                ++answer;
            L /= 10;
        }
        cout << answer << '\n';
    }
    else
    {
        MakeArray();
        if (L_num == R_num)
        {
            for (int i = L_num; i >= 0; --i)
            {
                if (L_array[i] == R_array[i])
                {
                    if (L_array[i] == 8)
                        ++answer;
                }
                else
                {
                    break;
                }
            }

            cout << answer << '\n';
        }
        else
        {
            cout << 0 << '\n';
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> L >> R;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}