#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// �ڼ��� ���� ������ ���� �����̴�. ���ϰ��� �ϴ� ���� 4�� 7�θ� �����Ǿ��ֱ� ������ 
// �Ź� �ڿ� 4 Ȥ�� 7�� �߰����ָ� �ȴ�. ����, B�� �ִ밪�� 10���̱� ������ ��� ��츦
// ���ϴ� ������ 2�� 9������ŭ�ۿ� ���� �ʱ⿡ �ð��� ����ϴ�.

vector<int> answer;
int A, B;

void BackTrack(long long sum)
{
    if (sum >= B)
        return;

    long long now = (sum * 10) + 4;
    if (A <= now && now <= B)
        answer.push_back(now);
    BackTrack(now);

    now = (sum * 10) + 7;
    if (A <= now && now <= B)
        answer.push_back(now);
    BackTrack(now);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> A >> B;
    BackTrack(0);
    cout << answer.size() << '\n';
    return 0;
}