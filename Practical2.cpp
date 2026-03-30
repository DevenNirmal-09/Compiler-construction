#include<bits/stdc++.h>
using namespace std;

vector<string> splitStringBySpace(const string& str) {
    stringstream ss(str);
    string word;
    vector<string> words;
    while (ss >> word) words.push_back(word);
    return words;
}

// Returns true if character c belongs to the symbol group name
bool matchSymbol(char c, const string& sym) {
    if (sym == "letter") return isalpha(c);
    if (sym == "digit")  return isdigit(c);
    if (sym.length() == 1) return c == sym[0];  // single char symbol like 'a','b','0'
    return false;
}

int main() {

    int n, m, st, t;
    cout << "Number of input symbols : "; cin >> n;
    cout << "Input symbols : ";
    string input[n];                        
    for (int i = 0; i < n; i++) cin >> input[i];

    cout << "Enter number of states : "; cin >> m;
    cout << "Initial state : "; cin >> st;
    st--;

    cout << "Number of accepting states : "; cin >> t;
    int acc[t];
    cout << "Accepting states : ";
    for (int i = 0; i < t; i++) { cin >> acc[i]; acc[i]--; }

    cout << "Transition table :\n";
    int table[m][n];
    unordered_map<string, int> mp;      
    for (int i = 0; i < n; i++) mp[input[i]] = i;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < n * m; i++) {
        string entry;
        getline(cin, entry);
        vector<string> tokens = splitStringBySpace(entry);
        int from      = stoi(tokens[0]) - 1;
        string symbol = tokens[2];            // "letter", "digit", or single char
        int to        = stoi(tokens[4]) - 1;
        table[from][mp[symbol]] = to;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Input string : ";
    string s;
    getline(cin, s);

    for (char c : s) {
        for (int i = 0; i < n; i++) {
            if (matchSymbol(c, input[i])) {  
                st = table[st][i];
                break;
            }
        }
    }

    for (int i : acc) {
        if (i == st) { cout << "Valid string.\n"; return 0; }
    }
    cout << "Invalid string.\n";
}
