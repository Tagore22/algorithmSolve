#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// ��Ʈ��ŷ ������. ���������� �����Ͽ����� K��°�̱⿡, 1, 2, 3������ ���� �ִ��� Ȯ���غ��� �����ϴٸ� ���ȣ���Ѵ�.

// �ڼ��� ������ �ּ����� �����.

vector<int> vec;
int N, K, answer = 0;
bool isfind = false;

void BackTrack(int num)
{
    // K��° ���� �̹� ã�Ҵٸ� �����Ѵ�.
    if (isfind)
        return;

    // ���� answer��° ���� �Ϸ�Ǿ�����.
    if (num == 0)
    {
        ++answer;
        // K��° �Ŀ� �����Ͽ��ٸ� ������� ���Ե� ������ ��� ����ϰ� ���� ã������ �����ϸ� Ż���Ѵ�.
        if (answer == K)
        {
            for (int i = 0; i < vec.size() - 1; ++i)
                cout << vec[i] << '+';
            cout << vec[vec.size() - 1] << '\n';
            isfind = true;
        }
        return;
    }

    // ����Ͽ��� ���������� ���ĵ� ������ ���� ���ϱ� ������ 1, 2, 3�� ������ ����Ѵ�.
    for (int i = 1; i <= 3; ++i)
    {
        if (num >= i)
        {
            vec.push_back(i);
            BackTrack(num - i);
            vec.pop_back();
        }
    }
}

void MakeAnswer()
{
    // ���⼭ ��Ʈ��ŷ.
    BackTrack(N);

    // ���� K��° ���� �������� ���� ���, -1�� ����Ѵ�.
    if (answer < K)
        cout << -1 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}