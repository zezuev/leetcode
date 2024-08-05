#include <stack>
#include <unordered_map>

using namespace std;


int main() {
    return 0;
}


bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> pairs = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (const char c : s) {
        if (!pairs.contains(c)) {
            st.push(c);
        } else {
            if (st.empty()) return false;
            const char top = st.top();
            st.pop();
            if (pairs[c] != top) return false;
        }
    }
    return st.empty();
}