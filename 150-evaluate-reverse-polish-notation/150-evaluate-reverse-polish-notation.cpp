class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for( string &x : tokens ) {
            if( (x[0]<='9' && x[0]>='0') || (x[1]<='9' && x[1]>='0') ) {
                st.push( stoi(x) );
            }
            else {
                int t;
                int a = st.top(); 
                st.pop();
                int b = st.top(); 
                st.pop();
                if( x[0]=='+' ) {
                    t = b + a;
                }
                else if( x[0]=='-' ) {
                    t = b - a;
                }
                else if( x[0]=='*' ) {
                    t = b*a ;
                }
                else {
                    t = b/a;
                }
                st.push(t);
            }
        }
        return st.top();
    }
};