#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node *left, *right;
};
bool search(struct node* root, int keys){ 
    while(root!=NULL){
        if(keys>root->key){
            root=root->right;
        }
        else if(keys<root->key){
            root=root->left;
        }
        else{
            return true;
        }
    }
    return false;
}
struct node* newnode(int select){
    struct node* temporary=new node;
    temporary->key=select;
    temporary->left=temporary->right=NULL;
    return temporary;
}
struct node* insert(struct node* node, int key){
    if(node==NULL){
        return newnode(key);
    }
    if(key<node->key){
        node->left=insert(node->left, key);
    }
    else if(key>node->key){
        node->right=insert(node->right, key);
    }
    return node;
}
int main(){
	int num;
    struct node* root=NULL;
    root=insert(root, 40);
    insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);
    insert(root, 60);
    printf("Masukan Angka: ");
    scanf("%d", &num);
    if(search(root, num)){
        printf("Data Ditemukan!\n");
    }
    else{
        printf("Data Tidak Ditemukan!\n");
    }
    return 0;
}
