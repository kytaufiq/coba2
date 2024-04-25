#include <iostream>
#include <cstring>
using namespace std;

void toUpperCase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

bool cariKata(const char* word) {
    char matrix[24][24] = {
        "AAFLKHPFSSUFICICLESGNNH",
        "SFVREOMRWLRTTSXOQQNAOAO",
        "QEIAIFXAEIRFVFYSXIMINJI",
        "WSTRLGOCAPBIAFIWIWTUACM",
        "FEYAEAISTPCRLUJKOAKCERS",
        "RVDAKPNDEEHDEMSNCKKFOAH",
        "MRNEDSLCRRIWNRSAAFITMMI",
        "YAAECIEAHYMOTAVHRSSTISB",
        "RJSEWELCCENNIETOHWSGLSE",
        "ATANYYMOIEESNESIOIRELTR",
        "UTENEWEBHMYBETNNRAIEBEN",
        "RCLKUTEAEQJLSGSHTGDSKOA",
        "BHOICATNRRSDDECEHOOLGIT",
        "ENSLUARIRSETALOCOHCTOHE",
        "FZFUDQJYMADOYIWYGLOVESU",
        "TEKALFWONSNAEBMIEJTZNTG",
        "ESWPOSJXEUTUYOZUWAKEZHM",
        "KZUHBPEZEERFLMSNOWBALLH",
        "NSNOWBOARDYTVWYCLEVOHSA",
        "ACOCRQLGZIYCHODRAZZILBI",
        "LBVKKWANZAAQINWOLPWONSL",
        "BFREEZINGRAINSLILGTMELT",
        "HQPYLWHFMNFFUFPSWXNUMMV"
    };

    int wordLen = strlen(word);

    // Check horizontally
    for (int i = 0; i < 24; i++) {
        for (int j = 0; j <= 24; j++) {
            bool found = true;
            for (int k = 0; k < wordLen; k++) {
                if (matrix[i][j + k] != word[k]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return true;
            }
        }
    }

    // Check vertically
    for (int i = 0; i <= 24; i++) {
        for (int j = 0; j < 24; j++) {
            bool found = true;
            for (int k = 0; k < wordLen; k++) {
                if (matrix[i + k][j] != word[k]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return true;
            }
        }
    }

    // Check diagonally (up-left)
    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 24; j++) {
            bool found = true;
            for (int k = 0; k < wordLen; k++) {
                if (matrix[i - k][j - k] != word[k]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return true;
            }
        }
    }

    // Check diagonally (up-right)
    for (int i = 0; i < 24; i++) {
        for (int j = 0; j <= 24; j++) {
            bool found = true;
            for (int k = 0; k < wordLen; k++) {
                if (matrix[i - k][j + k] != word[k]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return true;
            }
        }
    }

    // Check diagonally (down-right)
    for (int i = 0; i <= 24; i++) {
        for (int j = 0; j <= 24; j++) {
            bool found = true;
            for (int k = 0; k < wordLen; k++) {
                if (matrix[i + k][j + k] != word[k]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return true;
            }
        }
    }

    // Check diagonally (down-left)
    for (int i = 0; i <= 24; i++) {
        for (int j = 0; j < 24; j++) {
            bool found = true;
            for (int k = 0; k < wordLen; k++) {
                if (matrix[i + k][j - k] != word[k]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int num;
    cin >> num;
    cin.ignore(); // Clear input buffer

    char words[num][25]; // Array to store words

    for (int i = 0; i < num; i++) {
        cin.getline(words[i], 25);
        toUpperCase(words[i]); // Convert input word to uppercase
      
    }

    for (int i = 0; i < num; i++) {
        if (cariKata(words[i])) {
            cout << "Ada" << endl;
        } else {
            cout << "Tidak Ada" << endl;
        }
    }

    return 0;
}