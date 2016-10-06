#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

int n;
int pre[1001];
int in[1001];
vector<int> post;

void move(int pre_l, int pre_r, int in_l, int in_r)
{
    if (pre_l > pre_r) return;
    int root = pre[pre_l];
    //printf("%d %d, %d %d\n", pre_l, pre_r, in_l, in_r);
    for (int i = in_l; i <= in_r; i++)
        if (root == in[i]) {
            int left_size  = i - in_l;
            move(pre_l + 1, pre_l + left_size, in_l, i - 1);
            move(pre_l + left_size + 1, pre_r, i + 1, in_r);
            break;
        }
    post.push_back(root);
}

int main()
{
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &pre[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &in[i]);
        post.clear();

        move(0, n - 1, 0, n - 1);
        for (auto v : post)
            printf("%d ", v);
        printf("\n");
    }

    return 0;
}
