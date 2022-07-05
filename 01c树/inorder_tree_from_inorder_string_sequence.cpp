#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define MP make_pair
using namespace std;

const int maxn=1e7+10;

int ans[maxn];

struct node {
    string val;
    node *lef;
    node *rig;
};

//解析字符串
node *dfs(string k,int l,int r) {
    if(l>r) return nullptr;
    if(l==r) {
        node *tmp=new node;
        tmp->val=k.substr(l,1);
        tmp->lef=nullptr;
        tmp->rig=nullptr;
        return tmp;
    }
    int nexl=0,nexr=0,mid=0;
    int deep=0;
    for(int i=l;i<r;i++) {
        if(k[i]=='(') {
            deep++;
            if(deep==1) {
                nexl=i;
            }
        } else if(k[i]==')'){
            deep--;
            if(deep==0) {
                nexr=i;
            }
        }
        if(k[i]==','&&deep==1) {
            mid=i;
            break;
        }
    }
    node *now=new node;
    now->val=k.substr(l,nexl-l);
    now->lef=dfs(k,nexl+1,mid-1);
    now->rig=dfs(k,mid+1,r-1);
    return now;
}

void middfs(node *root) {
    if(root==nullptr) return;
    middfs(root->lef);
    cout<<root->val<<" ";
    middfs(root->rig);
}

//10(5(4,3),6(,2))

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    string st;
    cin>>st;
    node *root=new node;
    root=dfs(st,0,st.size()-1);
    middfs(root);
    cout<<endl;
    return 0;
}
