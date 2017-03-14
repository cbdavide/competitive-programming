#include <iostream>
#define left(i) i << 1
#define right(i) i << 1 | 1
using namespace std;

char operate(char a, char b) {
    if(a == '0' || b == '0')
        return '0';
    else if(a == b && (a == '-' || a == '+'))
        return '+';

    return '-';
}

void build(char *T, int *A, int node, int start, int end) {
    if(start == end) {
        int c = A[start];
        T[node] = c == 0 ? '0' : c > 0 ? '+' : '-';
    } else {
        int mid = (start + end) / 2;
        build(T, A, left(node), start, mid);
        build(T, A, right(node), mid + 1, end);

        T[node] = operate(T[left(node)], T[right(node)]);
    }
}

int query(char *T, int node, int start, int end, int a, int b) {
    if(b < start || end < a)
        return '+';
    if(a <= start && end <= b)
        return T[node];

    int mid = (start + end) / 2;
    int p1 = query(T, left(node), start, mid, a, b);
    int p2 = query(T, right(node), mid + 1, end, a ,b);

    return operate(p1, p2);
}

void update(char *T, int *A, int node, int start, int end, int i, int val) {
    if(start == end) {
        A[i] = val;
        T[node] = val == 0 ? '0' : val > 0 ? '+' : '-';
    } else {
        int mid = (start + end) / 2;
        if(start <= i && i <= mid)
            update(T, A, left(node), start, mid, i, val);
        else
            update(T, A, right(node), mid + 1, end, i, val);

        T[node] = operate(T[left(node)], T[right(node)]);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, *arr, a, b;
    char op, *tree;
    string answ;

    while(cin >> n >> k) {
        answ = "";
        arr = new int[n];
        tree = new char[4 * n];

        for(int i=0; i<n; i++) cin >> arr[i];
        build(tree, arr, 1, 0, n - 1);
        
        while(k--) {
            cin >> op >> a >> b;
            if(op == 'C') {
                update(tree, arr, 1, 0, n - 1, --a, b);
            } else
                answ.push_back(query(tree, 1, 0, n - 1, --a, --b));
        }
        cout << answ << '\n';
    }
    return 0;
}
