#include <iostream>

using namespace std;

// Ǯ��.
// �־��� ���ڿ��� ���ϰ� ��ġ�ϴ��� Ȯ���ϴ� ������.
// *�� ���ڰ� �ɼ���, ��� ���ڿ��� �ɼ��� �ִ�. ���� ������ ���� ���ڰ� *�϶� ������ ���� ����� ���� �����Ѵ�.

// *�϶�

// 1. *�� ��ĭ���� �����ϰ� ������ �������� �Ѿ.
// 2. *�� str�� �������� ���� �Ѿ.
// 3. *�� str�� ���� ���ڸ� ����ϰ� str�� �Ѿ.

// ���� ������ ���� ���ڰ� *���� Ȯ���ϰ� �׷��ٸ� ���� ����� ����, �׷��� �ʴٸ�
// �ܼ� ���� ������ ���ڿ� str�� ���ڸ� ���ϸ� ������ ���ڱ��� ��ȸ�ϸ� �ȴ�.
// ��� ��ȸ�� �� �ѹ��̶� true�� �ȴٸ� �ùٸ� �����̴�.

// �ڼ��� ������ �ּ����� �����.

string pat, str;
int N;

// �� ���ڿ��� ��� ��츦 ��ȸ�ϴ� �Լ�.
bool ComposePatten(int pat_idx, int str_idx)
{
    // �� ���ڿ��� ��� ������ ��ȸ�ߴٸ� �ùٸ� �����̴�.
    if (pat_idx >= pat.size() && str_idx >= str.size())
        return true;
    // �� ���ڿ��� �ϳ��� ������ ��ȸ�ߴٸ� �ùٸ� ������ �ƴϴ�.
    if (pat_idx >= pat.size() || str_idx >= str.size())
        return false;

    bool ans = false;
    // ���� ������ ���ڰ� *�϶� ����� 3���� ����� ���� ��� ��ȸ�Ѵ�.
    if (pat[pat_idx] == '*')
    {
        // 1. *�� ���ڷ� ����� ���ϸ� ���� ���ڷ� �Ѿ��.
        ans |= ComposePatten(pat_idx + 1, str_idx);
        // 2. *�� ���� ���ڱ����� ����ϰ� �Ѵ� ���� ���ڷ� �Ѿ��.
        ans |= ComposePatten(pat_idx + 1, str_idx + 1);
        // 3. *�� ���� ���ڵ� ����ϰ� str�� ���� ���ڷ� �Ѿ��.
        ans |= ComposePatten(pat_idx, str_idx + 1);
    }
    // ���� ���ڰ� *�� �ƴҶ�
    else
    {
        // �ܼ��� �� ���ڰ� ���������� �������� �Ѿ�� �ִ�.
        if (pat[pat_idx] == str[str_idx])
            ans |= ComposePatten(pat_idx + 1, str_idx + 1);
    }
    return ans;
}

void MakeAnswer()
{
    for (int iter = 0; iter < N; ++iter)
    {
        cin >> str;
        cout << (ComposePatten(0, 0) ? "DA" : "NE") << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> pat;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}