class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int n=0,r=0,si=1;
        for(int i=0;i<s.length();i++)
        {
            if(isdigit(s[i]))
            {
                n=(n*10)+(s[i]-'0');
            }
            else if(s[i]=='+'){
                r+=n*si;n=0;
                si=1;
            }
            else if(s[i]=='-'){
                r+=n*si;n=0;
                si=-1;
            }
            else if(s[i]=='('){
                st.push(r);
                st.push(si);
                r=0;n=0;
                si=1;
            }
            else if(s[i]==')'){
                r+=n*si;n=0;int sign=st.top();st.pop();int res =st.top();st.pop();
                r*=sign;
                r+=res;  
            }
        }
         return r+=n*si;
    }
};
