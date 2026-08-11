class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString = "";
        for(auto s : strs) {
            encodedString += to_string(s.length()) + "#" + s;
        }
        return encodedString;
    }

    vector<string> decode(string s) {
        vector<string> res;
        string tempS = "";
        int n = s.length();
        int count = 0;
        int tempLen = 0;
        int i = 0;

        while(i<n) {
            if(s[i]>='0' && s[i]<='9') {
                tempLen = tempLen*10 + s[i]-'0';
                i++;
            }
            else {
                while(count<tempLen+1) {
                    tempS += s[i];
                    i++;
                    count++;
                }
                res.push_back(tempS.substr(1));
                count = 0;
                tempLen = 0;
                tempS = "";
            }
        }
        return res;
    }
};
