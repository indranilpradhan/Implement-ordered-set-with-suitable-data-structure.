#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int number;
int countele = 0;

class Node
{
	public:
	int value;
	int rightvalue;
	Node *left = NULL;
	Node *right = NULL;
};

int max(int a, int b)
{
	return a>b?a:b;	
}

int height(Node *ptr)
{
//	cout<<"33"<<endl;
	if(ptr == NULL)
	{
//		cout<<"36"<<endl;
		return 0;
	}
	if(ptr->left == NULL && ptr->right == NULL)
	{
//		cout<<"37"<<endl;
		return 1;
	}
	else
	{
	//	cout<<"46"<<endl;
		return max(1+height(ptr->right),1+height(ptr->left));
	}	
}

Node* inordersuc(Node* ptr)
{
	Node* pt = ptr;
	while(pt->left)
	{
		pt = pt->left;
	}
	return pt;
}

Node* insert(int value,Node *ptr)
{
	if(ptr == NULL)
	{
		ptr = new Node();
		ptr->value = value;
		ptr->right = NULL;
		ptr->left = NULL;
		ptr->rightvalue = 0;
		return ptr;
	}
	
	if(value < ptr->value)
	{
		ptr->left = insert(value, ptr->left);
	}
	
	if(value > ptr->value)
	{
		ptr->rightvalue += 1; 
		ptr->right = insert(value,ptr->right);
	}
//	cout<<"72"<<endl;
	int rheight = height(ptr->right);
//	cout<<"74"<<endl;
	int lheight = height(ptr->left);
	
//	cout<<"lh"<<lheight<<endl;
//	cout<<"rh"<<rheight<<endl;
	
	if(lheight > 1+rheight)
	{
		int llheight = height(ptr->left->left);
		int lrheight = height(ptr->left->right);
//		cout<<"llh"<<llheight<<endl;
//		cout<<"lrh"<<lrheight<<endl;
		if(llheight > lrheight)
		{
			//rightrotate
//			cout<<"ptr rr"<<ptr->value<<endl;
			Node* newptr = new Node();
			newptr = ptr->left;
	//		newptr->rightvalue = ptr->rightvalue + ptr->left->rightvalue;
			ptr->left = newptr->right;
			newptr->right = ptr;
			ptr = newptr;
		}
		else
		{
			//leftrightrotate
			Node* newptr1 = new Node();
			Node* newptr2 = new Node();
			newptr1 = ptr->left->right;
		//	ptr->left->rightvalue = 0;
			ptr->left->right = newptr1->left;
			newptr1->left = ptr->left;
			ptr->left = newptr1;
			newptr2 = ptr->left;
			ptr->left = newptr2->right;
			newptr2->right = ptr;
			ptr = newptr2;
		}
	}
//	cout<<"95"<<endl;
	if(rheight > 1+lheight)
	{
		int rlheight = height(ptr->right->left);
		int rrheight = height(ptr->right->right);
//		cout<<"rlh"<<rlheight<<endl;
//		cout<<"rrh"<<rrheight<<endl;
		if(rrheight > rlheight)
		{
			//leftrotate
			Node* newptr = new Node();
			newptr = ptr->right;
			ptr->right = newptr->left;
			newptr->left=ptr;
			ptr = newptr;
		}
		else
		{
			//rightleftrotate
			Node* newptr1 = new Node();
			Node* newptr2 = new Node();
			newptr1 = ptr->right->left;
			ptr->right->left = newptr1->right;
			newptr1->right = ptr->right;
			ptr->right = newptr1;
			newptr2 = ptr->right;
			ptr->right = newptr2->left;
			newptr2->left = ptr;
			ptr = newptr2;
		}
	}
	return ptr;	
}

Node* deletenode(int value, Node* ptr)
{
	if(ptr == NULL)
	{
		return ptr;
	}
	
	if(value < ptr->value)
	{
		ptr->left = deletenode(value, ptr->left);
	}	
	else if(value > ptr->value)
	{ 
		ptr->right = deletenode(value,ptr->right);
	}
	else
	{
		if(ptr->left == NULL && ptr->right == NULL)
		{
			ptr = NULL;
		}
		else if(ptr->left != NULL && ptr->right == NULL)
		{
			Node* temp = ptr->left;
			*ptr = *temp;
			free(temp);
		}
		else if(ptr->left == NULL && ptr->right != NULL)
		{
			Node* temp = ptr->right;
			*ptr = *temp;
			free(temp);
		}
		else
		{
			Node* temp = inordersuc(ptr->right);
			ptr->value = temp->value;
			ptr->right = deletenode(temp->value,ptr->right);
		}
	}
	
	if(ptr == NULL)
		return ptr;
		
	if(ptr->left == NULL && ptr->right == NULL)
		return ptr;
	
	//	cout<<"72"<<endl;
	int rheight = height(ptr->right);
//	cout<<"74"<<endl;
	int lheight = height(ptr->left);
	
//	cout<<"lh"<<lheight<<endl;
//	cout<<"rh"<<rheight<<endl;
	
	if(lheight > 1+rheight)
	{
		int llheight = height(ptr->left->left);
		int lrheight = height(ptr->left->right);
//		cout<<"llh"<<llheight<<endl;
//		cout<<"lrh"<<lrheight<<endl;
		if(llheight > lrheight)
		{
			//rightrotate
//			cout<<"ptr rr"<<ptr->value<<endl;
			Node* newptr = new Node();
			newptr = ptr->left;
	//		newptr->rightvalue = ptr->rightvalue + ptr->left->rightvalue;
			ptr->left = newptr->right;
			newptr->right = ptr;
			ptr = newptr;
		}
		else
		{
			//leftrightrotate
			Node* newptr1 = new Node();
			Node* newptr2 = new Node();
			newptr1 = ptr->left->right;
		//	ptr->left->rightvalue = 0;
			ptr->left->right = newptr1->left;
			newptr1->left = ptr->left;
			ptr->left = newptr1;
			newptr2 = ptr->left;
			ptr->left = newptr2->right;
			newptr2->right = ptr;
			ptr = newptr2;
		}
	}
//	cout<<"95"<<endl;
	if(rheight > 1+lheight)
	{
		int rlheight = height(ptr->right->left);
		int rrheight = height(ptr->right->right);
//		cout<<"rlh"<<rlheight<<endl;
//		cout<<"rrh"<<rrheight<<endl;
		if(rrheight > rlheight)
		{
			//leftrotate
			Node* newptr = new Node();
			newptr = ptr->right;
			ptr->right = newptr->left;
			newptr->left=ptr;
			ptr = newptr;
		}
		else
		{
			//rightleftrotate
			Node* newptr1 = new Node();
			Node* newptr2 = new Node();
			newptr1 = ptr->right->left;
			ptr->right->left = newptr1->right;
			newptr1->right = ptr->right;
			ptr->right = newptr1;
			newptr2 = ptr->right;
			ptr->right = newptr2->left;
			newptr2->left = ptr;
			ptr = newptr2;
		}
	}
	return ptr;
}

bool ispresent(int key, Node* ptr)
{
	if(ptr == NULL)
		return false;
	if(key < ptr->value)
		return ispresent(key, ptr->left);
	else if(key > ptr->value)
		return ispresent(key, ptr->right);
	else
		return true;
}

int closest(int key, Node* ptr)
{
	if(ptr == NULL)
		return 0;
//	cout<<"key "<<key<<endl;
//	cout<<"value "<<ptr->value<<endl;
	if(key  ==  ptr->value)
		return key;	
	else if(key < ptr->value)
	{
		if(ptr->left == NULL)
			return ptr->value;
		else
			number = closest(key,ptr->left);
	}
	else
	{
		if(ptr->right == NULL)
			return ptr->value;
		else
			number = closest(key,ptr->right);
	}
	
	if(abs(ptr->value - key) <= abs(number - key))
	{
	//	cout<<"309 "<<ptr->value<<endl;
		if(ptr->value > number)
			return number;
		else
			return ptr->value;
	}
	else
	{
	//	cout<<"number "<<number<<endl;
		return number;
	}
}

void kthlargest(int k, Node* ptr)
{
	if(k < 1)
		return;
	if(ptr == NULL)
		return;
//	int num;
	kthlargest(k, ptr->right);
	countele++;
//	cout<<"k "<<k<<endl;
//	cout<<"countele "<<countele<<endl;
//	cout<<"k "<<k<<endl;
	if(countele == k)
	{
		cout<<ptr->value<<endl;
		return;
	}
	kthlargest(k, ptr->left);
}

int rangequery(Node* ptr, int leftpt, int rightpt)
{
	static int countelement = 0;
//	cout<<"left 345 "<<leftpt<<endl;
//	cout<<"right 346 "<<rightpt<<endl;
	if(ptr == NULL)
		return 0;
		
	if(leftpt <= ptr->value && ptr->left != NULL)
		int l = rangequery(ptr->left, leftpt, rightpt);
		
	if(ptr->value >= leftpt && ptr->value <= rightpt)
	{
//		cout<<"ptr value 349 "<<ptr->value<<endl;
//		cout<<"left "<<leftpt<<endl;
//		cout<<"right "<<rightpt<<endl;
		countelement++;
	}
	
	if(rightpt >= ptr->value && ptr->right != NULL)
		int r = rangequery(ptr->right, leftpt, rightpt);
		
	return countelement;
}

void inorder(Node* ptr)
{
	if(ptr != NULL)
	{
		inorder(ptr->left);
		cout<<ptr->value<<" ";
		inorder(ptr->right);
	}
}

int main()
{
	int t;
	cin>>t;
	Node* root = NULL;
	while(t--)
	{	
		cout<<"1. for insert, 2.for delete, 3. for checking, 4. for closest element, 5. for Kth largest, 6. for count in range"<<endl;
		int num;
		cin>>num;
		if(num == 1)
		{
			int ele;
			cin>>ele;
			root = insert(ele,root);
			inorder(root);
			cout<<endl;
		}
		if(num == 2)
		{
			int key;
			cin>>key;
			root = deletenode(key,root);
			inorder(root);
			cout<<endl;
		}
		if(num == 3)
		{
			int key;
			cin>>key;
			if(ispresent(key,root) == 0)
				cout<<"Not present"<<endl;
			else
				cout<<"Present"<<endl;
		}
		if(num == 4)
		{
			int key;
			cin>>key;
			cout<<closest(key,root)<<endl;
		}
		if(num == 5)
		{
			int k;
			cin>>k;
			kthlargest(k,root);
		}
		if(num == 6)
		{
			int left;
			cin>>left;
			int right;
			cin>>right;
			cout<<rangequery(root,left,right)<<endl;
		}
	}
	return 0;
}
