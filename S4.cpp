class Solution {
    private:
    int operation(int a,int b,string t)
    {
        if(t=="+")return a+b;
        if(t=="-")return a-b;
        if(t=="*")return a*b;
        if(t=="/")return a/b;
        return 0;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string &token:tokens)
        {
            if(token == "+"||token == "-"||token == "*"||token == "/")
            {
                int b=st.top();st.pop();
                int a=st.top();st.pop();
                int res=operation(a,b,token);
                st.push(res);
            }
            else
            st.push(stoi(token));//stoi ==. string to integer
        }
      return st.top();  
    }
};
