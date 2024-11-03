class Solution {
public:
    string removeStars(string s) 
    {
        stack<string>st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='*')
            st.pop();
            else
            st.push(s[i]);
        }
        string result="";
        stack<string>sr;
        while(!st.empty())
        {
            sr.push(st.top());
            st.pop();    
        }
        while(!sr.empty())
        {
            st.push(sr.top());
            result.push_back(st.top());
            sr.pop();
        }
        return result;  
    }
};
