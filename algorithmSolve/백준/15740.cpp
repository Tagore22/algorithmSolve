#include <iostream>
#include <string>

using namespace std;

//�ڵ��� ���̸� ���� �˰����� �����ؾ� �� �������� ���� �ϳ� �ָ� �Ծ��� �����̴�. �ܼ��� �� ���� �Է¹޾� ���� ���� ����ϴ� �����ε�,
//�߿��Ѱ� long long�� ������ ����� ū ���� �����̴�. �翬�ϰԵ� string ���� Ǯ��� �ߴµ�, �� ���� ���� ��ȣ���� ũ�⿡ ���� ��������
//����� ���� �������־���ߴ�. ����, �� 0���� �����ϴ� ��쿡�� ó���� ���־��������, 0,0 ���� ���� �ƿ� 0�̾����Ƿ� �� answer����
//answer.size()-1������ 0���� �����Ѵٸ� �����ϵ�, ������ answer[answer.size()-1]�� 0������ ������ ����ؾ��ߴ�.

string A, B;

void MakeAnswer()
{
    bool minusA = A[0] == '-' ? true : false;
    bool minusB = B[0] == '-' ? true : false;
    A = minusA ? A.substr(1, A.size()) : A;
    B = minusB ? B.substr(1, B.size()) : B;

    if (A.size() > B.size())
        while (A.size() != B.size())
            B = '0' + B;

    else
        while (B.size() != A.size())
            A = '0' + A;

    string answer = "";
    if (minusA != minusB) //������ -, ������ +�϶�. ��, �� ���� �����Ҷ�
    {
        if (A > B)
        {
            for (int i = A.size() - 1; i >= 0; --i)
            {
                int nowA = A[i] - '0';
                int nowB = B[i] - '0';
                if (A[i] < B[i])
                {
                    int idx = i - 1;
                    while (A[idx] == '0')
                    {
                        A[idx] = '9';
                        --idx;
                    }
                    --A[idx];
                    nowA += 10;
                }
                answer = to_string(nowA - nowB) + answer;
            }
            if (minusA)
                cout << '-';
        }
        else if (A < B)
        {
            for (int i = A.size() - 1; i >= 0; --i)
            {
                int nowA = A[i] - '0';
                int nowB = B[i] - '0';
                if (A[i] > B[i])
                {
                    int idx = i - 1;
                    while (B[idx] == '0')
                    {
                        B[idx] = '9';
                        --idx;
                    }
                    --B[idx];
                    nowB += 10;
                }
                answer = to_string(nowB - nowA) + answer;
            }
            if (minusB)
                cout << '-';
        }
        else
        {
            answer = "0";
        }
    }
    else // �� ���� ��ȣ�� ������
    {
        int sum = 0;
        for (int i = A.size() - 1; i >= 0; --i)
        {
            sum += (A[i] - '0') + (B[i] - '0');
            answer = to_string(sum % 10) + answer;

            sum = sum >= 10 ? 1 : 0;
        }
        answer = sum == 1 ? '1' + answer : answer; //���� ū �ڸ��������� ������ 10�� �Ѿ ���ο� �ڸ����� �����Ҷ�. �̰� �ؾ�����. �Ф�
        if (minusA)
            cout << '-';
    }

    bool zero = true;
    for (int i = 0; i < answer.size() - 1; ++i) //0���� �����ϴ� ���� �����ؾ� �ϴµ� 0,0�� ��� ��� ���õǾ� �ƹ��͵� ��µ��� �ʴ´�.
    {                                           //������ �ڸ��� �������� 0���� �����ϴ� ��츦 �����ϵ�, ������ �ڸ����� ������ ����Ѵ�.
        if (zero && answer[i] == '0')
            continue;
        zero = false;
        cout << answer[i];
    }
    cout << answer[answer.size() - 1] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> A >> B;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}