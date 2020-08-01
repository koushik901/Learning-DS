#include<iostream>
using namespace std;
#define endl "\n"

struct binnode{		 		
	int data;
	binnode* left;
	binnode* right;
};
 
binnode* getnode(int val){ 			//getter function    
	binnode *temp=new binnode() ; 
	temp->data=val;
	temp->left=temp->right=NULL;
	return temp;
}
 
binnode* binsert(binnode* root,int val){ //insert function
	if(root==NULL){
		root = getnode(val);
	}
	else if(val <= root->data){
		root->left=binsert(root->left,val);
	}
	else {
		root->right=binsert(root->right,val);
	}
	return root;
}

bool binsearch(binnode* root,int val){  //search function
	if(root == NULL)return false;
	if(root->data==val)return true;
	else if(root->data >= val)return binsearch(root->left,val);
	else return binsearch(root->right,val);
}

binnode* FindMin(binnode* root){
	if(root->left!=NULL)root=root->left;
	return root;
}

binnode* bindelete(binnode* root,int val){
		if(root==NULL)return root;
		else if(val < root->data)root->left=bindelete(root->left,val);
		else if(val > root->data)root->right=bindelete(root->right,val);
		else{
			//Case 1 : When no child
			if(root->left==NULL && root->right==NULL){
				delete root;    //delete from heap memory 
				root=NULL;      // so that its address get erased
			}
			//Case 2: When one child
			else if(root->left==NULL){
				binnode* temp=root;
				root=root->right;
				delete temp;
			}
			else if(root->right==NULL){
				binnode* temp=root;
				root = root ->left;
				delete temp;
			}
			//Case 3:When 2 child
			else {
				binnode* min_in_left=FindMin(root->right);
				root->data=min_in_left->data;
				root->right=bindelete(root->right,min_in_left->data);
			} 
		}
		return root;
}

int main()
{
		binnode* root = NULL;
		root = binsert(root,10);
		root = binsert(root,15);
		root = binsert(root,34);
		root = binsert(root,17);
		
		int x;cin>>x;
		
		if(binsearch(root,x)==true)
			cout<<"found"<<endl;
		else cout<<"not found"<<endl;
		
		root = bindelete(root,15);
		
		if(binsearch(root,15))cout<<"found"<<endl;
		else cout<<"not found"<<endl;
		
		return 0;
}
// Some points to keep in mind 
// instead of new operator, malloc function can also be used
// instead of delete , free can also be used to remove from heap memory
