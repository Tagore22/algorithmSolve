#include <iostream>

using namespace std;

// Ǯ��.
// �������� �����ֵ� �ſ� ���ŷο� ��������. �� ���ڿ��� �־����� � ���ڿ��� �� �ܾ �߰��ϰų� �����ϰų�
// �ٲپ ������ �� ���ڿ��� ���� ����, ���� ������ ���ڼ��� �����Ҽ� �ִ����� ���� ������.
// �������� ����ġ�⸦ �̿��ؼ� �ִ��� ���귮�� �ٿ��� �ϴµ� ������ ����.

// 1. �ֽô��� �� ���ڿ��� ���̰� 2�̻� ���̳��ٸ� �Ұ����ϴ�.
// 2. �� ���ڿ��� ��� ���ĺ� A�� ���� ���� 2�̻� ���̳��ٸ� �Ұ����ϴ�. 

// �� 2���� ����ġ�⸦ �̿��ؼ� ��� ����� ���� ��ȸ�ؾ� �Ѵ�. ���� �� ���ڿ��� ���� ���̿� ���� �� ����������.

// �ڼ��� ������ �ּ����� �����.

int checkstr1[26];
string str1, str2;
int N, size1, size2, num = 0;

// �� ���ڿ��� ���Ͽ� ����� �������� Ȯ���ϴ� �Լ�.
bool CompareStr()
{
    int checkstr2[26];
    for (int i = 0; i < 26; ++i)
        checkstr2[i] = 0;
    // ���� ���ڿ��� �����ϴ� ���ĺ��� �� ���� �����Ѵ�.
    for (int i = 0; i < size2; ++i)
        ++checkstr2[str2[i] - 'A'];
    int diff, ans = 0;
    // ��� ���ĺ��� ��ȸ�ϸ� �� ���ڿ��� ���� �ش� ���ĺ��� ���� ���Ѵ�.
    // ���� ��� ���ĺ����� 2�̻� ���̰� ���ٸ� ��ȯ�Ͽ��� ����� ������ ���� �ʱ⿡
    // false�� ����ϰ� Ż���Ѵ�.
    for (int i = 0; i < 26; ++i)
    {
        diff = abs(checkstr1[i] - checkstr2[i]);
        if (diff >= 2)
            return false;
        ans += diff;
    }
    // �� ���ڿ��� ���̰� ���ٸ� ���̰� 0�̰ų� 2�϶�(��� ���� �ٸ� ���ĺ� �Ѱ����� ������ ������ ex) DOG, DOH)
    // ����� ������ ����� �ִ�.
    if (size1 == size2)
        return ans == 0 || ans == 2 ? true : false;
    // �� ���ڿ��� ���̰� 1�� ���̳��� ���̴� 1���� �۰ų� ���ƾ߸� ����� ������ ����� �ִ�.
    else
        return ans <= 1 ? true : false;
}

void MakeAnswer()
{
    size1 = str1.size();
    // ù��° ���ڿ��� �����ϴ� ���ĺ��� �� ���� �����Ѵ�.
    for (int i = 0; i < size1; ++i)
        ++checkstr1[str1[i] - 'A'];
    int answer = 0;
    // N - 1���� ���ڿ��� �Է¹޾� ���غ���.
    for (int iter = 1; iter < N; ++iter)
    {
        cin >> str2;
        size2 = str2.size();
        if (abs(size1 - size2) >= 2)
            continue;
        answer = CompareStr() ? answer + 1 : answer;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> str1;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}