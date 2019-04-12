//dominator
#include <bits/stdc++.h>
using namespace std;
int C,T;
int i,j,n,t;

vector <int> v[100];
bool visit[100];
void dfs(int x){
    if (visit[x]) return;
    visit[x] = true;
    for (auto i : v[x])
        dfs(i);
}

void lineBreak(){
    printf("+");
    for (int i = 0; i < n*2-1; i++) printf("-");
    printf("+\n");
}

int main(){
    cin >> T;
    for (C = 1; C <= T; C++){
        cin >> n;
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                cin >> t;
                if (t) v[i].push_back(j);
            }
        }

        bool dominate[100][100];
        memset(dominate,false,sizeof(dominate));

        dominate[0][0] = true;
        for (i = 1; i < n; i++){
            dominate[0][i] = dominate[i][i] = true;
            memset(visit,false,sizeof(visit));
            visit[i] = true;
            dfs(0);
            for (j = 0; j < n; j++)
                if (!visit[j]) dominate[i][j] = true;
        }
        memset(visit,false,sizeof(visit));
        dfs(0);
        printf("Case %d:\n",C);
        lineBreak();
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                printf(dominate[i][j] && visit[j] ? "|Y" : "|N");
            }
            printf("|\n");
            lineBreak();
        }
        for (i = 0; i < 100; i++) v[i].clear();
    }
}
