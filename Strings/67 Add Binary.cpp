class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i = a.size()-1;  // pointer to the end of string a
        int j = b.size()-1 ; // pointer to the end of string b
        int carry = 0;
        while(i>=0 || j>=0 )
        {
            int sum = carry;
            if(i>=0)sum+=a[i]-'0';
            if(j>=0)sum+=b[j]-'0';
            ans+=to_string(sum%2);
            carry= sum/2;    // find the req carry 
            i--;
            j--;
        }
        if(carry!=0) ans+= to_string(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};