#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int find_square(int n) {
    int square = 1;

    while(square*square < n)
        square++;
    return square;
}

void append(string& text, int square) {
    for(int i=0; i<square; i++)
        text.append("*");
}

char** create_matrix(int n) {
    char **m;
    m = new char*[n];
    for(int i=0; i<n; i++)
        m[i] = new char[n];
    return m;
}

void fill_matrix(char **matrix, string message) {
    int size = sqrt(message.size());
    int z = 0;
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++, z++)
            matrix[i][j] = message[z];
    }
}

main() {
    int ncases, size, square;
    char **matrix;
    string message;

    cin >> ncases;
    for(int i=0; i<ncases; i++) {
        cin >> message;
        size = message.size();
        square = find_square(size);
        append(message, square);//Apending asterisk
        matrix = create_matrix(square);
        fill_matrix(matrix, message);

        for(int j=0; j<square; j++) {
            for(int i=square-1; i>=0; i--) {
                if(matrix[i][j] != '*')
                    cout << matrix[i][j];
            }
        }
        cout << '\n';
    }
}
