#include <iostream>
#include <vector>

using namespace std;

void printMagicSquare(vector<vector<int>>& square) {
    int n = square.size();
    int magicSum = (n * n + 1) * n / 2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << square[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Magic sum: " << magicSum << endl;
}

void generateMagicSquare(int n) {
    if (n % 2 == 0 || n < 3) {
        cout << "Invalid order. Must be odd and >= 3." << endl;
        return;
    }

    vector<vector<int>> square(n, vector<int>(n));

    int i = 0, j = n / 2;
    for (int k = 1; k <= n * n; k++) {
        square[i][j] = k;
        if (i == 0) {
            if (j == n - 1) {
                i++;
            } else {
                i = n - 1;
                j++;
            }
        } else if (j == n - 1) {
            i--;
            j = 0;
        } else if (square[i - 1][j + 1] == 0) {
            i--;
            j++;
        } else {
            i++;
        }
    }

    printMagicSquare(square);
}

int main() {
    int n;
    cout << "Enter the order of the magic square: ";
    cin >> n;

    generateMagicSquare(n);

    return 0;
}