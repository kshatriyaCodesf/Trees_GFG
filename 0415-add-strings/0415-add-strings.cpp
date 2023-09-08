class Solution {
public:
    string s="";
    int rev = 0 ;
    string helper(string n1 , string n2 , int l1 ,  int l2)
    {
        if(l1 < 0 && l2 < 0 )
        {
           if(rev)return to_string(rev)+s;
           else return s;
           
        }
        if(l1<0)
        {
            int num =n2[l2]-'0'+rev;
            s = to_string(num%10)+s;
            rev = num/10;
            return helper(n1 , n2 ,l1,l2-1);
        }
        else if(l2<0)
        {
            int num = n1[l1]-'0'+rev;
            s = to_string(num%10)+s;
            rev = num/10;
            return helper(n1 , n2 ,l1-1,l2);
        }
        else
        {
            int num = n1[l1]-'0'+n2[l2]-'0'+rev;
            s = to_string(num%10)+s;
            rev = num/10;
            return helper(n1 , n2 ,l1-1,l2-1);
        }
        
        
        
        
        
    }
    string addStrings(string num1, string num2) {
       
        
            return helper(num1 , num2 , num1.size()-1 , num2.size()-1);

    }
};