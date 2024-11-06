class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids)
    {
        stack<int>st;
        stack<int>r;
        for(int &a: asteroids)
        {
            while(!st.empty()&&a<0&&st.top()>0)
            {
                int sum=st.top()+a;
                if(sum<0)st.pop();
                else if(sum>0)a=0;
                else {st.pop();a=0;}
            }
            if(a!=0)
            {
                st.push(a);
            }
        }
        int s = st.size();
        vector<int>res(s);
        int i = s-1;
        while(!st.empty()) 
        {
            res[i]= st.top();
            st.pop();
            i--;
        }
    return res;}
};
//using vector
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids)
    {
        vector<int>st;
        for(int &a: asteroids)
        {
            while(!st.empty()&&a<0&&st.back()>0)
            {
                int sum=st.back()+a;
                if(sum<0)st.pop_back();
                else if(sum>0)a=0;
                else {st.pop_back();a=0;}
            }
            if(a!=0)
            {
                st.push_back(a);
            }
        }
        int s = st.size();
        vector<int>res(s);
        int i = s-1;
        while(!st.empty()) 
        {
            res[i]= st.back();
            st.pop_back();
            i--;
        }
    return res;}
};
