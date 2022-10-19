struct RetrieveValue
{   
    template <typename T>
    typename T::second_type operator()(T keyValuePair) const
    {   
        return keyValuePair.second;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        
        for(string& str : strs){
            vector<int> count(26, 0);
            for(char c : str){
                count[c-'a']++;
            }
            
            string scount = "";
            for(int& e : count){
                scount += (to_string(e)+"#");
            }
            
            groups[scount].push_back(str);
        }
        
        vector<vector<string>> ans;
        
        transform(groups.begin(), groups.end(), back_inserter(ans), RetrieveValue());
        
        return ans;
    }
};
