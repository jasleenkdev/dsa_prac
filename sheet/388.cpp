#include <vector>
#include <unordered_map>
#include <iostream>
#include <sstream>   // ✅ FIX 1
#include <algorithm>
using namespace std;

class Solution{
public: 
    int lengthLongestPath(string input){
        unordered_map<int, int> mp;
        mp[0] = 0;

        int maxLen = 0;   // ✅ FIX 2

        stringstream ss(input);
        string line;

        while(getline(ss, line, '\n')){
            int depth = 0;

            // ✅ FIX 3 (safer)
            while (depth < line.size() && line[depth] == '\t') {
                depth++;
}
            string name = line.substr(depth);

            if(name.find('.') != string::npos){
                maxLen = max(maxLen, mp[depth] + name.size());
            } 
            else{
                mp[depth + 1] = mp[depth] + name.size() + 1;
            }
        }

        return maxLen;
    }
};