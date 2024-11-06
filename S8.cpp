class Solution {
    vector<int> getNSL(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (st.empty())
                result[i] = -1;
            else {
                while (!st.empty() && arr[st.top()] >= arr[i]) {
                    st.pop();
                }
                result[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        return result;
    }

    vector<int> getNSR(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {  // Correct the loop index
            if (st.empty())
                result[i] = n;  // When no element smaller than arr[i] to the right
            else {
                while (!st.empty() && arr[st.top()] > arr[i]) {
                    st.pop();
                }
                result[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }
        return result;
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> NSL = getNSL(arr, n);
        vector<int> NSR = getNSR(arr, n);
        long long sum = 0;
        int m = 1e9 + 7;  // Modulo value

        for (int i = 0; i < n; i++) {
            long long ls = i - NSL[i];  // Number of elements on the left
            long long rs = NSR[i] - i; // Number of elements on the right
            long long totalSum = arr[i] * ls * rs;
            sum = (sum + totalSum) % m; 
        }
        
        return (int)sum;  // Return the sum as an integer
    }
};
