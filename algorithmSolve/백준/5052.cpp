#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// Ʈ���̸� �̿��� Ǯ�̴�. Ʈ���̴� �����̸� ���ڿ� ������ �������� Ǯ� ���� ���������ߴ�.
// �׷��� �������̶� �׷��� ������ �߸��Ѱ��� �޸𸮵� �ӵ��� ������ Ʈ���̸� ���� �ʾ�������
// �ξ� ������. �׷����� �ұ��ϰ� �߿��� �����̸� �߿��� ������� �ϳ� ���Ǿ��⿡ 
// ������ ��ġ�� ����ߴ�.

// �ڼ��� ������ �ּ����� �����.

string board[10000];
int T, N;
bool isfind;

// Ʈ���� ����. �ڼ��� ������ �������� ã�ƺ���.
struct dial
{
    // ���� �ܰ迡�� ����Ǿ��°�.
    bool isend;
    dial* child[10];

    dial() : isend(false)
    {
        memset(child, 0, sizeof(child));
    }
    ~dial()
    {
        for (int i = 0; i < 10; ++i)
            if (child[i] != nullptr)
                delete child[i];
    }

    // Ʈ���̿� ���ڿ��� �����ϴ� �Լ�.
    void insert(const char* key)
    {
        // �� �κ��� ���� �߿��ѵ� ���� const char * key ������ � ���ڿ��� �� �� �ּҰ��� ������.
        // ���� *key�� �� ���ڿ��� �� �ձ��ڸ� ����Ų��.
        // ���� �������̱⿡ key���� �ٸ� �ݽ��ÿ��� ��ȭ�ص� ���� ��ȭ�ɰ� ������
        // �����δ� �Ű������� �Ѿ�� �������� �ּҰ��� ����Ǳ⿡ ���� ó���ȴ�.
        // �������ڸ� ������ ����.

        // const char * key�� ������
        // 1. key�� �������̸� ���� �պκ��� �ּҰ��̴�.
        // 2. *key�� 1���� ������ ���� ���� �ձ����̴�.
        // 3. const char * �� �Ű����� �� ���ڿ����� �����Ͱ��� �����ϱ� ������
        // �ٸ��������� ��ȭ�� ���õȴ�.

        if (*key == 0) // �ּҰ��̶�� nullptr�� ���ϴ°� ������ �ּҰ��� �ƴϱ⿡ nullptr�� ���ϴ� ���� 0���� ���Ѵ�.
        {
            isend = true;
        }
        else
        {
            int idx = *key - '0';
            if (child[idx] == nullptr)
                child[idx] = new dial();

            // key�� ������ �ڷ� 1ĭ �и�ä �Ű������� �Ѿ��. ex) abcd >>>> bcd��.
            child[idx]->insert(key + 1);
        }
    }

    void find(const char* key)
    {
        if (*key == 0)
            return;

        if (isend)
        {
            isfind = true;
            return;
        }

        int idx = *key - '0';
        child[idx]->find(key + 1);
    }
};

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        dial tree;
        isfind = false;
        cin >> N;
        for (int i = 0; i < N; ++i)
            cin >> board[i];

        // ���⼭ Ʈ���̸� �����Ѵ�.(�����͸� �����Ѵ�.)
        for (int i = 0; i < N; ++i)
            tree.insert(board[i].c_str());
        // for������ �ٽ� board�� ���ҵ��� ��ȸ�ϸ� ���� �� ���� �ʾҴµ� ����ǥ�ð� �����Ѵٸ�
        // �ٷ� ���ͼ� ���� �������� ����ص� �ǰ� �ܼ� bool ������ �̹� ���� �������� üũ��
        // �ص� �ȴ�.
        for (int i = 0; i < N; ++i)
        {
            tree.find(board[i].c_str());
            if (isfind)
                break;
        }
        if (isfind)
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
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