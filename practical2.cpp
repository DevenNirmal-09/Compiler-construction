#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    cout << "Enter number of symbols: ";
    int stymbols;
    cin >> stymbols;
    cout << "Input symbols: ";
    vector<char> sym(stymbols);
    for(int i = 0; i < stymbols; i++)
    {
        cin >> sym[i];
    }
    cout << "Entre NUmber of states: ";
    int states;
    cin >> states;
    
        cout << "Enter the initial test: \n";
        int initial_state;
        cin >> initial_state;
        
    cout << "Number of the accepting states: ";
    int acc_states;
    cin >> acc_states;
    
    vector<int> acc_st(acc_states);
    cout << "Enter the accepting states: "; 
    for(int i = 0; i < acc_states; i++)
    {
        cin >> acc_st[i];
    }

    cout << "Transition Table: \n";
    vector<vector<int>> trans_table(states + 1, vector<int>(stymbols));
    for(int i = 1; i <= states; i++)
    {
        for(int j = 0; j < stymbols; j++)
        {
            cin >> trans_table[i][j];
        }
    }
    
    // cout << "DFA successfully created!\n";
    
    cout << "Enter input string: ";
    string input;
    cin >> input;
    
    int current_state = initial_state;
    bool valid_input = true;
    for(char ch : input)
    {
        auto it = find(sym.begin(), sym.end(), ch);
        if(it == sym.end())
        {
            cout << "Invalid symbol in input string.\n";
            valid_input = false;
            break;
        }
        int symbol_index = distance(sym.begin(), it);
        current_state = trans_table[current_state][symbol_index];
    }
    
    if(valid_input)
    {
        if(find(acc_st.begin(), acc_st.end(), current_state) != acc_st.end())
        {
            cout << "Valid string\n";
        }
        else
        {
            cout << "Invalid string\n";
        }
    }
    return 0;
}