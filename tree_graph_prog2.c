// Conversion of BST PreOrder/PostOrder/InOrder.

#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode
{
        int data;
        struct treeNode *left;
        struct treeNode *right;

}treeNode;

treeNode* FindMin(treeNode *node)
{
        if(node==NULL)
        {
                /* There is no element in the tree */
                return NULL;
        }
        if(node->left) /* Go to the left sub tree to find the min element */
                return FindMin(node->left);
        else 
                return node;
}
treeNode* FindMax(treeNode *node)
{
        if(node==NULL)
    {
                /* There is no element in the tree */
        return NULL;
    }
    if(node->right) /* Go to the left sub tree to find the min element */
        FindMax(node->right);
    else 
        return node;    
}

treeNode * Insert(treeNode *node,int data)
{
        if(node==NULL)
        {
                treeNode *temp;
                temp = (treeNode *)malloc(sizeof(treeNode));
                temp -> data = data;
                temp -> left = temp -> right = NULL;
                return temp;
        }

        if(data >(node->data))
        {
                node->right = Insert(node->right,data);
        }
        else if(data < (node->data))
        {
                node->left = Insert(node->left,data);
        }
        /* Else there is nothing to do as the data is already in the tree. */
        printf("\nInsertion Successful....\n");
        return node;
}

treeNode * Delete(treeNode *node, int data)
{
        treeNode *temp;
        if(node==NULL)
        {
                printf("Element Not Found");
        }
        else if(data < node->data)
        {
                node->left = Delete(node->left, data);
        }
        else if(data > node->data)
        {
                node->right = Delete(node->right, data);
        }
        else
        {
                /* Now We can delete this node and replace with either minimum element 
                   in the right sub tree or maximum element in the left subtree */
                if(node->right && node->left)
                {
                        /* Here we will replace with minimum element in the right sub tree */
                        temp = FindMin(node->right);
                        node -> data = temp->data; 
                        /* As we replaced it with some other node, we have to delete that node */
                        node -> right = Delete(node->right,temp->data);
                }
                else
                {
                        /* If there is only one or zero children then we can directly 
                           remove it from the tree and connect its parent to its child */
                        temp = node;
                        if(node->left == NULL)
                                node = node->right;
                        else if(node->right == NULL)
                                node = node->left;
                        free(temp); /* temp is longer required */ 
                }
        }
        return node;

}

treeNode * Find(treeNode *node, int data)
{
        if(node==NULL)
        {
                /* Element is not found */
                return NULL;
        }
        if(data > node->data)
        {
                /* Search in the right sub tree. */
                return Find(node->right,data);
        }
        else if(data < node->data)
        {
                /* Search in the left sub tree. */
                return Find(node->left,data);
        }
        else
        {
                /* Element Found */
                return node;
        }
}

void PrintInorder(treeNode *node)
{
        if(node==NULL)
        {
                return;
        }
        PrintInorder(node->left);
        printf("%d ",node->data);
        PrintInorder(node->right);
}

void PrintPreorder(treeNode *node)
{
        if(node==NULL)
        {
                return;
        }
        printf("%d ",node->data);
        PrintPreorder(node->left);
        PrintPreorder(node->right);
}

void PrintPostorder(treeNode *node)
{
        if(node==NULL)
        {
                return;
        }
        PrintPostorder(node->left);
        PrintPostorder(node->right);
        printf("%d ",node->data);
}

int main()
{
        treeNode *root = NULL;
    treeNode * temp;
    int choice,val;
    while(1)
    {
                printf("\nTree Menu");
                printf("\n1. Insert Node");
                printf("\n2. Delete Node");
                printf("\n3. Pre Order Traversal");
                printf("\n4. Post Order Traversal");
                printf("\n5. In Order Traversal");
                printf("\n6. All Traversal");
                printf("\n7. Search an Element");
                printf("\n8. Find Minimum Element");
                printf("\n9. Find Maximum Element");
                printf("\n0. Exit");
                printf("\n\nEnter Your Choice (0-9) : ");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                printf("\nInserting Node in Binary Search Tree\n");
                                printf("Enter value to insert in new node : ");
                                scanf("%d",&val);
                                root=Insert(root,val);
                                break;
                        case 2:
                                printf("\nDeleting a Node in Binary Search Tree\n");
                                printf("Enter value of node to Delete : ");
                                scanf("%d",&val);
                                root=Delete(root,val);
                                break;
                        case 3:
                                PrintPreorder(root);
                                break;
                        case 4:
                                PrintPostorder(root);
                                break;
                        case 5:
                                PrintInorder(root);
                                break;
                        case 6:
                                printf("\nPre Order Traversal:");
                                PrintPreorder(root);
                                printf("\nIn Order Traversal:");
                                PrintInorder(root);
                                printf("\nPost Order Traversal:");
                                PrintPostorder(root);
                                break;
                        case 7:
                                printf("\nSearch a Node");
                                printf("\nEnter value to search : ");
                                scanf("%d",&val);
                                temp = Find(root,val);
                                if(temp==NULL)
                                {
                                        printf("Element %d not found\n",val);
                                }
                                else
                                {
                                        printf("Element %d Found \n",val);
                                }
                                break;
                        case 8:
                                temp = FindMin(root);
                                printf("Minimum element is %d\n",temp->data);
                                break;
                        case 9:
                                temp = FindMax(root);
                                printf("Maximum element is %d\n",temp->data);
                                break;
                        case 0:
                                printf("\nThanks for using Tree Program...\n");
                                exit(1);
                                break;
                        default:
                                printf("\nInvalid Choice. Please Try Again....\n");
                                break;
                }
        }
}

