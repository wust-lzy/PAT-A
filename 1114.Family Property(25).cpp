// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// int father[10000];
// bool vis[10000];
// struct data
// {
//     int id, fid, mid, num, area;
//     int cid[10];
// } data[1005];

// struct family
// {
//     int id, people;
//     double num, area;
//     bool flag = 0;
// } ans[10000];

// int findfather(int v)
// {
//     if (v == father[v])
//     {
//         return v;
//     }
//     else
//     {
//         int f = findfather(father[v]);
//         father[v] = f;
//         return f;
//     }
// }
// void Union(int a, int b)
// {
//     int fa = findfather(a);
//     int fb = findfather(b);
//     if (fa > fb)
//     {
//         father[fa] = fb;
//     }
//     else if (fa < fb)
//     {
//         father[fb] = fa;
//     }
// }
// bool cmp(family a, family b)
// {
//     if (a.area != b.area)
//     {
//         return a.area > b.area;
//     }
//     else
//     {
//         return a.id < b.id;
//     }
// }
// int main()
// {
//     int n, k, cnt = 0;
//     scanf("%d", &n);
//     for (int i = 0; i < 10000; i++)
//     {
//         father[i] = i;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d %d %d %d", &data[i].id, &data[i].fid, &data[i].mid, &k);
//         vis[data[i].id] = 1;
//         if (data[i].fid != -1)
//         {
//             vis[data[i].fid] = 1;
//             Union(data[i].fid, data[i].id);
//         }
//         if (data[i].mid != -1)
//         {
//             vis[data[i].mid] = 1;
//             Union(data[i].mid, data[i].id);
//         }
//         for (int j = 0; j < k; j++)
//         {
//             scanf("%d", &data[i].cid[j]);
//             vis[data[i].cid[j]] = 1;
//             Union(data[i].cid[j], data[i].id);
//         }
//         scanf("%d %d", &data[i].num, &data[i].area);
//     }
//     for (int i = 0; i < n; i++)
//     {
//         int id = findfather(data[i].id);
//         ans[id].id = id;
//         ans[id].num += data[id].num;
//         ans[id].area += data[id].area;
//         ans[id].flag = 1;
//     }
//     for (int i = 0; i < 10000; i++)
//     {
//         if (vis[i])
//         {
//             ans[findfather(i)].people++;
//         }
//         if (ans[i].flag)
//         {
//             cnt++;
//         }
//     }
//     for (int i = 0; i < 10000; i++)
//     {
//         if (ans[i].flag)
//         {
//             ans[i].num = (double)(ans[i].num * 1.0 / ans[i].people);
//             ans[i].area = (double)(ans[i].area * 1.0 / ans[i].people);
//         }
//     }
//     sort(ans, ans + 10000, cmp);
//     printf("%d\n", cnt);
//     for (int i = 0; i < cnt; i++)
//     {
//         printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].people, ans[i].num, ans[i].area);
//     }
//     return 0;
// }
#include <cstdio>
#include <algorithm>
using namespace std;
struct DATA {
    int id, fid, mid, num, area;
    int cid[10];
}data[1005];
struct node {
    int id, people;
    double num, area;
    bool flag = false;
}ans[10000];
int father[10000];
bool visit[10000];
int find(int x) {
    while(x != father[x])
        x = father[x];
    return x;
}
void Union(int a, int b) {
    int faA = find(a);
    int faB = find(b);
    if(faA > faB)
        father[faA] = faB;
    else if(faA < faB)
        father[faB] = faA;
}
int cmp1(node a, node b) {
    if(a.area != b.area)
        return a.area > b.area;
    else
        return a.id < b.id;
}
int main() {
    int n, k, cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < 10000; i++)
        father[i] = i;
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &data[i].id, &data[i].fid, &data[i].mid, &k);
        visit[data[i].id] = true;
        if(data[i].fid != -1) {
            visit[data[i].fid] = true;
            Union(data[i].fid, data[i].id);
        }
        if(data[i].mid != -1) {
            visit[data[i].mid] = true;
            Union(data[i].mid, data[i].id);
        }
        for(int j = 0; j < k; j++) {
            scanf("%d", &data[i].cid[j]);
            visit[data[i].cid[j]] = true;
            Union(data[i].cid[j], data[i].id);
        }
        scanf("%d %d", &data[i].num, &data[i].area);
    }
    for(int i = 0; i < n; i++) {
        int id = find(data[i].id);
        ans[id].id = id;
        ans[id].num += data[i].num;
        ans[id].area += data[i].area;
        ans[id].flag = true;
    }
    for(int i = 0; i < 10000; i++) {
        if(visit[i])
            ans[find(i)].people++;
        if(ans[i].flag)
            cnt++;
    }
    for(int i = 0; i < 10000; i++) {
        if(ans[i].flag) {
            ans[i].num = (double)(ans[i].num * 1.0 / ans[i].people);
            ans[i].area = (double)(ans[i].area * 1.0 / ans[i].people);
        }
    }
    sort(ans, ans + 10000, cmp1);
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++)
        printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].people, ans[i].num, ans[i].area);
    return 0;
}