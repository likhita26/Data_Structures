
//BINARY SEARCH TREE BY LIKHITA26

#include <stdio.h>
#include <stdlib.h>

struct node{
	int key;
	struct node *left, *right;	//Declaring new node
};
//Function to create new node...
struct node *newN(int val){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->key = val;
	temp->left = temp->right = NULL;
	return temp;
}  
//Function for Pre_Order...
void preOrder(struct node *tree){
	if (tree!=NULL){
		printf(" %d ",tree->key);
		preOrder(tree->left);
		preOrder(tree->right);
		}
	}
//Funtion for In_Order... 
void inOrder(struct node *tree){
	if(tree!=NULL){
		inOrder(tree->left);
		printf(" %d ",tree->key);
		inOrder(tree->right);
	}
}
//Function for Post_Order...
void postOrder(struct node *tree){
	if(tree!=NULL){
		postOrder(tree->right);
		postOrder(tree->left);
		printf(" %d ",tree->key);
	}
}
//Function to print all the traversals...
void printTree(struct node *tree){
	printf("In-Order:");
	inOrder(tree);
	printf("\n");
	printf("Pre-Order:");
	preOrder(tree);
	printf("\n");
	printf("Post-Order:");
	postOrder(tree);
}
int count=0;
//Search Function...
struct node *Search(struct node *tree, int key){
	if(tree->key==key){
		printf("Find(tree,%d)->trueVal,depth: %d\n",key,count);
		count=0;
		return tree;
	}
	if(tree->key<key){
		count++;
		return Search(tree->right,key);
	}
	else{
		count++;
		return Search(tree->left,key);
	}
}
//Insert Function...
struct node *Insert(struct node *tree,int key){
	if(tree==NULL){
		return newN(key);
	}
	if(key<tree->key){
		tree->left=Insert(tree->left,key);
	}
	else if(key>tree->key){
		tree->right=Insert(tree->right,key);
	}
	return tree;
}
//Delete  Function...
struct node *P(struct node *node){
	struct node *present=node;
	while(present&&present->left !=NULL){
		present=present->left;
	}
	return present;
}
struct node *Delete(struct node *tree,int key){
	if(tree==NULL){
		printf("%d is successfully deleted from Binary Search Tree.",key);
		return tree;
	}
	if(key<tree->key){
		tree->left=Delete(tree->left,key);
		return tree;
	}
	else if(key>tree->key){
		tree->right=Delete(tree->right,key);
		return tree;
	}
	else{
		if(tree->left==NULL){
			struct node *temp=tree->right;
			return temp;
		}
		else if(tree->right==NULL){
			struct node *temp=tree->left;
			return temp;
		}
		struct node *temp=P(tree->right);
		tree->key=temp->key;
		tree->right=Delete(tree->right,temp->key);
		printf("%d is successfully deleted from Binary Search Tree.",key);
		return tree;
	}
}
//Function to print the sub-tree...
struct node *printSub(struct node *tree,int key){
	if(tree->key==key){
		printf("\n The sub tree of %d is:\n",key);
		printTree(tree); 
		return 0;
	}
	if(tree->key>key){
		tree=tree->left;
		printSub(tree,key);
		return 0;
	}
	else{
		tree=tree->right;
		printSub(tree,key);
		return 0;
	}
}
//Counting the nodes...
int countNodes(struct node *tree){
	if(tree!=NULL){
		countNodes(tree->left);
		countNodes(tree->left);
		count++;
		countNodes(tree->right);
	}
	return count;
}
//Function to calculate ImBalance...
struct node *CalculateImbalance(struct node *tree,int key){
	if(tree->key==key){
		printf("ImBalance(tree,%d)-> %d (#left child-#right child = ",key,countNodes(tree->left)+countNodes(tree->left)-countNodes(tree->right));
		count=0;
		printf("%d )\n",countNodes(tree->left)+countNodes(tree->left)-countNodes(tree->right));
		count=0;
		return 0;
		}
		if(tree->key>key){
			tree=tree->left;
			return CalculateImbalance(tree,key);
		}
		else{
			tree=tree->right;
			return CalculateImbalance(tree,key);
		}
	}
int splitIndex(int inOrder[],int index, int s){
	for(int i=0;i<index;i++){
		if(inOrder[i]>=s){
			return i-1;
		}
	}
	return index-1;
}
void storeInOrder(struct node *x,int inOrder[],int index){
	if(x==NULL){
		return;
	}
	storeInOrder(x->left,inOrder,index);
	inOrder[index++]=x->key;
	storeInOrder(x->right,inOrder,index);
}
struct node *createTree(int inOrder[],int start, int end){
	if(start>end){
		return NULL;
	}
	int mid=(start+end)/2;
	struct node *T=newN(inOrder[mid]);
	T->left=createTree(inOrder,start,mid-1);
	T->right=createTree(inOrder,mid+1,end);
	return T;
}
//The Main Function...
int main(){
	struct node *tree=NULL;
	tree=Insert(tree,100);
	Insert(tree,50); Insert(tree,25); Insert(tree,10);
	Insert(tree,90);Insert(tree,45),Insert(tree,20);
	Insert(tree,5);Insert(tree,1);
	printTree(tree);
	printf("\n \n");
	Search(tree,50);Search(tree,20);Search(tree,1);
	printf("\n");
	CalculateImbalance(tree,100);CalculateImbalance(tree,50);
	CalculateImbalance(tree,20);CalculateImbalance(tree,1);
	printf("\n");
	Delete(tree,50);
	printf("\n");
	Delete(tree,25);
	printf("\n");
	printSub(tree,100);
	printf("\n");
	printSub(tree,90);
	printf("\n");
	printSub(tree,20);
	printf("\n");
	printSub(tree,1);
	printf("\n");
	return 0;
}

