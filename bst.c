#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

void inorder(struct node *root);
void add_node();
struct node *search(int key, struct node *root);
void printtree(struct node *root, int n);
struct node *delete_node(struct node *root, int x);
struct node *successor(struct node *node);

struct node *root = NULL;

void main()
{
    int is_running = 1, ch;
    while (is_running)
    {
        printf("\n1.Add\n2.Display Tree\n3. Inorder traversal\n4.Delete Node\nPress 0 to exit...\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 0:
            is_running = 0;
            break;
        case 1:
            add_node();
            break;
        case 2:
            printtree(root, 0);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            int element;
            printf("Enter element: ");
            scanf("%d", &element);
            root = delete_node(root, element);
            break;
        default:
            printf("\nWrong Choice\n");
            break;
        }
    }
}

void add_node()
{
    struct node *newnode;
    int num;
    newnode = malloc(sizeof(struct node));
    newnode->left = NULL;
    newnode->right = NULL;
    printf("Enter the data to be added: ");
    scanf("%d", &num);
    newnode->data = num;
    if (root == NULL)
    {

        root = newnode;
    }
    else
    {
        struct node *current;
        current = root;

        while (current != NULL)
        {
            if (num == current->data)
            {
                printf("Element already exists.");
                break;
            }
            else if (num > current->data)
            {
                if (current->right == NULL)
                {
                    current->right = newnode;
                    break;
                }
                current = current->right;
            }
            else
            {
                if (current->left == NULL)
                {
                    current->left = newnode;
                    break;
                }
                current = current->left;
            }
        }
        printf("Node inserted.");
    }
}

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void printtree(struct node *root, int n)
{
    if (root == NULL)
    {
        return;
    }
    n++;
    printtree(root->right, n);
    if (n == 1)
    {
        printf("Root -> ");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            printf("\t");
        }
    }
    printf("%d\n", root->data);
    printtree(root->left, n);
}

struct node* delete_node(struct node *root, int x)
{
    if (root == NULL)
    {
        return root;
    }

    if (x > root->data)
    {
        root->right = delete_node(root->right, x);
    }
    else if (x < root->data)
    {
        root->left = delete_node(root->left, x);
    }
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            struct node *succ = successor(root);
            root->data = succ->data;
            root->right = delete_node(root->right, succ->data);
        }
    }
    return root;
}

struct node *successor(struct node *node)
{
    node = node->right;

    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

struct node *search(int key, struct node *root)
{
    if (root == NULL || root->data == key)
    {
        return root;
    }

    if (key > root->data)
    {
        return search(key, root->right);
    }
    else
    {
        return search(key, root->left);
    }
}
