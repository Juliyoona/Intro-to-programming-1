#include<stdio.h>
#include<stdlib.h>
#define left ptr_to_left_node
#define right ptr_to_right_node
#define num number
typedef struct _NODE
{
    int number;
    struct _NODE *ptr_to_right_node;
    struct _NODE *ptr_to_left_node;
} Node;
int n;

int pre_idx=0;
int idxSearch(int* inorder, int start, int end, int val)
{
    int i;
    for(i=start;i<end;i++)
    {
        if(inorder[i]==val) return i;
    }
}
Node* buildTree(int* Inorder, int* Preorder, int inorder_start, int inorder_end)
{
    if(inorder_start>inorder_end) return NULL;
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->num=Preorder[pre_idx++];//先取Preorder[pre_idx]再把pre_idx++
    int in_idx=idxSearch(Inorder,inorder_start,inorder_end,newNode->num);
    newNode->left=buildTree(Inorder,Preorder,inorder_start,in_idx-1);
    newNode->right=buildTree(Inorder,Preorder,in_idx+1,inorder_end);
    return newNode;
}
void showPostorder(Node* root)
{
    if(root)
    {
        showPostorder(root->left);
        showPostorder(root->right);
        printf("%d ",root->num);
    }
}
void freeTree(Node* root)
{
    pre_idx=0;
    if(root)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
int main(void)
{
    int id = 1;
    while( ~scanf( "%d", &n ) )
    {
        int inorder[100], preorder[100];
        for( int i = 0; i < n; i++ )
            scanf( "%d", &inorder[i] );
        for( int i = 0; i < n; i++ )
            scanf( "%d", &preorder[i] );
        Node *root = buildTree( inorder, preorder, 0, n-1 );
        printf( "testcase%d: ", id++ );
        showPostorder( root );
        printf( "\n" );
        freeTree( root );
    }
    return 0;
}