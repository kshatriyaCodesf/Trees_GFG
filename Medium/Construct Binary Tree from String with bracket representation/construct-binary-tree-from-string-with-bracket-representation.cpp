//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends

class Solution{
public:
    map<int,int>mp;
    void mapping(string str)
    {
        stack<int>st;
        for(int i = 0 ; i < str.length();i++)
        {
            if(str[i]=='(')
            {
                st.push(i);
            }
            else if(str[i]==')')
            {
                mp[st.top()]=i;
                st.pop();
            }
        }
    }
    bool isDigit(char ch)
    {
        return (ch<='9' and ch>='0');
    }
    Node*rec(string str, int si , int ei)
    {
        if(si>ei)return NULL;
        int num = 0;
        while(si<str.length() and isDigit(str[si]))
        {
            int x = str[si]-'0';
            num = num*10+x;
            si++;
        }
        // si--;
        Node*root = new Node(num);
        int y = -1;
        if(si<=ei and str[si]=='(')
        {
            y = mp[si];
        }
        
            if(y!=-1)
            {
                root->left = rec(str , si+1 , y-1);
                root->right = rec(str , y+2 , ei-1);
            }
            return root;

    }

    Node *treeFromString(string str)
    {
        mapping(str);
        return rec(str , 0 , str.length()-1);
    }
};


//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends