//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends


class Solution{
    public:
    int preindex = 0 ; 
    Node*helper(int in[] , int pre[] , int si , int ei)
    {
        if(si>ei)return NULL;
        Node*newroot = new Node(pre[preindex++]);
        int index;
        for(int i = si ; i <=ei ; i++)
        {
            if(in[i]==newroot->data)
            {
                index = i ;
                break;
            }
        }
        newroot->left = helper(in , pre , si , index-1);
        newroot->right = helper(in , pre , index+1 , ei);
        
        return newroot;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        Node*temp  = helper(in , pre , 0 , n-1);
        return temp ;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends