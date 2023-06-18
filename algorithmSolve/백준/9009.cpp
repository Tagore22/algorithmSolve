#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Ǯ��.
// �Ǻ���ġ�� �̿��ؾ� �Ұ� ������ �����δ� +�� ����Ž������ �˾ƾ��Ѵ�.
// ū Ʋ�� �������ڸ�

// 1. ��ó���� �Ǻ���ġ �迭�� �̸� ������ ���´�. �ٸ�, �ִ� 10������� ���� �ʿ��ϴ�.
// 2. �ּ� ������ �Ǻ���ġ ���� �˱����ؼ��� �־��� �� num�� ���� �����鼭 ���� �Ǻ���ġ ������ ���ҽ��ѳ����� �Ѵ�.

// �̰��� �������ָ� �ȴ�.
// �ڼ��� ������ �ּ����� �����.

vector<int> fibo, vec;
int T;
const int MAX_NUM = 1000000000;

// ��ó���� �Ǻ���ġ �迭�� �����س��� �Լ�.
void CalFibo()
{
    fibo.push_back(0);
    fibo.push_back(1);

    int num;
    for (int i = 2; ; ++i)
    {
        num = fibo[i - 2] + fibo[i - 1];
        // 1���� ����Ͽ��� �־����� ���� �ִ� 10���̱⿡ 10���� �ʰ��ϴ� ���� �ʿ����� �ʴ�.
        if (num > MAX_NUM)
            break;
        fibo.push_back(num);
    }
}

void FindNum(int num)
{
    vec.clear();

    while (num > 0)
    {
        // ����� num�� ���� ����� �Ǻ���ġ ���� ���Ϳ� ������ num�� ���ҽ�Ų��.
        // �̰��� num�� 0�� �ɶ����� �ݺ��Ѵ�.
        int idx = upper_bound(fibo.begin(), fibo.end(), num) - fibo.begin();
        num -= fibo[idx - 1];
        vec.push_back(fibo[idx - 1]);
    }
}

void MakeAnswer()
{
    CalFibo();
    int num;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> num;
        FindNum(num);
        // ���Ϳ� ����� ������ ������������ ����Ѵ�.
        for (int i = vec.size() - 1; i >= 0; --i)
            cout << vec[i] << ' ';
        cout << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}