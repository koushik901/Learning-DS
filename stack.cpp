#include<iostream>
using namespace std;
#define endl "\n"
struct node{
		int val;
		node* next;
	};
class LL{
private:
	node* head=NULL;
public:
	void push(int data){
		node* temp = new node();
		temp->val=data;
		temp->next=NULL;
		if(head==NULL)head=temp;
		else{
			temp->next=head;
			head=temp;
		}
	}
	void print(){
		node* temp=head;
		while(temp!=NULL){
			cout<<temp->val<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
	void pop(){
		if(head==NULL){
			cout<<"No more elements in stack"<<endl;
			return;
		}
		node* temp=head;
		head=head->next;
		delete(temp);
	}
	node* top(){
		return head;
	}
	bool empty(){
		if(head==NULL)return true;
		return false;
	}
};

int main(){
	LL check;
	check.push(15);
	check.push(21);
	check.push(23);
	node* uper=check.top();
	cout<<uper->val<<endl;
	check.print();
	check.pop();
	check.print();
	check.pop();
	check.print();
	check.pop();
	check.print();
	check.pop();
	if(check.empty())cout<<"stack is empty"<<endl;
	return 0;
}	
