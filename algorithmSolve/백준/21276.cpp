#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Ǯ��.
// ���������� ���鼭 -��- ������ Ǯ���� ������ ������ ������ ��2���� �ϳ���ŭ�� Ǯ��� ����߰�
// �����ߴ�. 2�ð� �����̳� �ɷ����� ���͹����δ� �׷��� ������ �ʾҴ�. ���������� �����ؾ��ϴ� ��������.
// �������� Ǭ�� ������ �����Ǽ� ����� ����� �ȳ����� �������� Ʋ�� ������ ����.
// �ļյ��� ���� ������Ű�鼭 ���� ������ �Ǵ� ��ġ���� ���� �ļյ��� ã�ƾ��ߴ�. �־����� �ļհ� ������ ���谡
// �ٷ� �̾����� �θ��ڽ� ���谡 �ƴ� �ļհ� ���� ���迴�� �����̴�. ������ �������ٰ� ���� ������ �������� �ʾ�
// �ؿ� �ּ����� �����ؾ߰ڴ�.

// �ڼ��� ������ �ּ����� �����.

map<string, int> con; // string >> int���� ��ȯ.
map<int, string> recon; // int >> string������ ��ȯ.
vector<int> board[1000]; // �ļյ��� �����ϴ� vector�迭.
int num[1000]; // ���� ���°�� ���� �ִ����� ����. ���� ������ ����.
int N, M;

// 1. ���󿡼� �ļ��� ���Խ�Ų��. �̶� �ļ��� ������ 1�� ������Ų��.
// 2. �������� �����Ѵ�. ������ �ļյ��� ���� ��� -1 ��Ű�� �̶� 0�� �� �ļյ��� ���� �ļ��� �ȴ�.
// �� ���� �� �ļյ��� ���� �������� ���Խ�Ų��.

void MakeAnswer()
{
    // ���� ���� ������ �����ֱ� ���̱� ������ ��� 0���� �ʱ�ȭ �ȴ�. ������ 2�� ���� ��� �� ���� 2�� �Ǿ�
    // ���� 2���� ��� �ļ��� ���ϱ� ������ �����ϼ� ����.
    for (int i = 0; i < N; ++i)
        num[i] = 0;
    string first, second;
    // ��� ������ �Է¹޾� ���󿡼� �ļ��� �����ϰ�
    // �ļ��� ��� �����ִ��� �����Ѵ�.
    for (int i = 0; i < M; ++i)
    {
        cin >> first >> second;
        int f_num = con[first];
        int s_num = con[second];
        ++num[f_num];
        board[s_num].push_back(f_num);
    }
    // �Ŀ� ��� �ļյ��� ���������� �����ؼ� ����ؾ� �Ѵ�. �̶� ������ ������
    // ���߿� que�� ��ȸ�Ҷ��� ���������� ��ȸ�ϱ� ������ ���Ѵ�.
    for (int i = 0; i < N; ++i)
        sort(board[i].begin(), board[i].end());

    queue<int> que;
    vector<int> thefirst;
    // ������ ���ϴ� �κ�. �ֽô��� �������� �ʴ� �̵��� �����̱� �����̴�.
    for (int i = 0; i < N; ++i)
        if (num[i] == 0)
        {
            que.push(i);
            thefirst.push_back(i);
        }

    // �������� ���� �� �̸��� ����Ѵ�.
    cout << thefirst.size() << '\n';
    for (auto& a : thefirst)
        cout << recon[a] << ' ';
    cout << '\n';

    vector<int> answer[1000];
    while (!que.empty())
    {
        int cur = que.front();
        que.pop();

        // ���� ������ �ļյ��� ��ȸ�ϸ� �� �����ִ� ���� 1�� ���ش�. �̶� ���̻� ���� ���� �ʴٸ�
        // ���� ������ �ɼ� ������ �� ������ ���� �ļ��� �ȴ�. ���� que�� ���Խ����ְ� �� ������
        // vector �迭�� �����Ѵ�.
        for (auto& a : board[cur])
        {
            --num[a];
            if (num[a] == 0)
            {
                answer[cur].push_back(a);
                que.push(a);
            }
        }
    }

    // �ε��������� �� �ļյ��� ���� �̸��� ����Ѵ�.
    for (int i = 0; i < N; ++i)
    {
        cout << recon[i] << ' ' << answer[i].size() << ' ';
        for (auto& a : answer[i])
            cout << recon[a] << ' ';
        cout << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    vector<string> name;
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        name.push_back(str);
    }
    sort(name.begin(), name.end());
    for (int i = 0; i < N; ++i)
    {
        con[name[i]] = i;
        recon[i] = name[i];
    }
    cin >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}