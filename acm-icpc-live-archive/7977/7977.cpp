#include <bits/stdc++.h>
using namespace std;

int mod(int a, int b) {
    return (b + (a % b)) % b;
}

int ctoi(char a) {
    return (int)a - 'A';
}

int main() {
    string cypher, secret, cp;
    while(cin >> cypher >> secret) {
        char arr[cypher.size()];

        for(int i=0; i<cypher.size(); i++) {
            if(i < secret.size())
                arr[i] = mod(ctoi(cypher[i]) - ctoi(secret[i]), 26) + 'A';
            else
                arr[i] = mod(ctoi(cypher[i]) - ctoi(arr[i - secret.size()]), 26) + 'A';
        }
        
        for(int i=0; i<cypher.size(); i++)
            cout << arr[i];
        cout << '\n';
    }
    return 0;
}
