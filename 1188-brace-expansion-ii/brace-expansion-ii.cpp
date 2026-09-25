class Solution {
public:
    int i = 0;

    // Concatenation of two sets
    set<string> product(set<string> &a, set<string> &b) {
        set<string> res;
        for (auto &x : a) {
            for (auto &y : b) {
                res.insert(x + y);
            }
        }
        return res;
    }

    // Parse expression
    set<string> solve(string &s) {

        set<string> ans;
        set<string> curr;
        curr.insert("");

        while (i < s.size() && s[i] != '}') {

            if (s[i] == ',') {
                ans.insert(curr.begin(), curr.end());
                curr.clear();
                curr.insert("");
                i++;
            }

            else if (s[i] == '{') {
                i++;
                set<string> temp = solve(s);
                curr = product(curr, temp);
            }

            else if (islower(s[i])) {
                set<string> temp;
                temp.insert(string(1, s[i]));
                curr = product(curr, temp);
                i++;
            }

            else if (s[i] == '}') {
                break;
            }
        }

        ans.insert(curr.begin(), curr.end());

        if (i < s.size() && s[i] == '}')
            i++;

        return ans;
    }

    vector<string> braceExpansionII(string expression) {
        i = 0;
        set<string> res = solve(expression);
        return vector<string>(res.begin(), res.end());
    }
};