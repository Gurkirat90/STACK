class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        string result ="";
        string token="";
        stringstream s(path);
        while(getline(s,token,'/'))
        {
            if (token==""||token==".")continue;
            else if(token!="..") st.push(token);
            else if(!st.empty())st.pop();
        }
        if (st.empty()) return"/";
        while(!st.empty())
        {
            result ="/"+st.top()+result;
            st.pop();
        }
        return  result;
    }
};
//using vectors
class Solution {
public:
    string simplifyPath(string path) {
        vector<string>st;
        string result ="";
        string token="";
        stringstream s(path);
        while(getline(s,token,'/'))
        {
            if (token==""||token==".")continue;
            else if(token!="..") st.push_back(token);
            else if(!st.empty())st.pop_back();
        }
        if (st.empty()) return"/";
        for(auto &token:st)
        {
            result =result+"/"+token;
        }
        return  result;
        
    }
};
