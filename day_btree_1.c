/* Binary Tree */
#include "Simple.h"
typedef struct _binarytree_node {
	struct _binarytree_node *left, *right;
	struct _binarytree_node *parent;
	void* dataptr;	// 실 데이터
	int testvalue;
	int height;		// for AVL
}BTNODE, *PBTNODE;

BTNODE* newNode(int data) {
	BTNODE *ptr;
	ptr = (BTNODE*)calloc(1, sizeof(BTNODE));
	assert(ptr != NULL);
	ptr->testvalue = data;
	return ptr;
}
int insertNode(BTNODE **proot, const BTNODE *node) {
	BTNODE *current = (*proot);
	if ((*proot) == NULL) {
		(*proot) = node;
		return 0;
	}

	while (1) {
		if (current->testvalue == node->testvalue) {
			// 중복을 허용, 않는지 ?
			return 0;
		}
		else if (current->testvalue > node->testvalue) {
			if ( current->left != NULL ) {
				current = current->left;
			}
			else {
				current->left = node;
//				node->parent = current;
				return 1;
			}
		}
		else if (current->testvalue < node->testvalue) {
			if (current->right != NULL) {
				current = current->right;
			}
			else {
				current->right = node;
//				node->parent = current;
				return 1;
			}

		}
	}

	return 0;
}
int randomTree(BTNODE **proot, int numbersOfnode) {
	BTNODE *temp;
	int i;
	for (i = 0; i < numbersOfnode; i++) {
		temp = newNode(rand() % 99 + 1);
		insertNode(proot, temp);
	}
	return 0;
}
int traversePreorder(BTNODE *node) {
	if (node != NULL) {
		printf("%3d ", node->testvalue);
		traversePreorder(node->left);
		traversePreorder(node->right);
	}
	return 0;
}
int traverseInorder(BTNODE *node) {
	if (node != NULL) {
		traverseInorder(node->left);
		printf("%3d ", node->testvalue);
		traverseInorder(node->right);
	}
	return 0;
}
int traversePostorder(BTNODE *node) {
	if (node != NULL) {
		traversePostorder(node->left);
		traversePostorder(node->right);
		printf("%3d ", node->testvalue);
//		free(node);
	}
	return 0;
}
int traverseLevelorder(BTNODE *root) {
	// 각 레벨별 노드 수를 구한다... 그들의 주소 저장
	BTNODE *queue[20] = { NULL };
	BTNODE *dummy[20] = { NULL };
	int i, level, child, n;

	level = 0;
	n = 1;
	queue[0] = root;
	do {
		child = 0;
		printf("level: %d : ", level);
		for (i = 0; i < n; ++i) {
			printf("%3d ", queue[i]->testvalue);
			if (queue[i]->left != NULL) {
				dummy[child++] = queue[i]->left;
			}
			if (queue[i]->right != NULL) {
				dummy[child++] = queue[i]->right;
			}
		}
		printf("\n");
		for (i = 0; i < child; i++) {
			queue[i] = dummy[i];
		}
		level++;
		n = child;
	} while ( child != 0 );
	return 0;
}
BTNODE* searchNode(BTNODE *root, int value) {
	BTNODE *current = root;
	while ( current->testvalue != value ) {
		if (current->testvalue > value) {
			current = current->left;
		}
		else {
			current = current->right;
		}
		if (current == NULL) {
			return NULL;
		}
	}
	return current;
}
int deleteNode(BTNODE **root, int value) {
	BTNODE *parent, *del;
	BTNODE *parent_pt, *pt;
	BTNODE *child;

	// 삭제될 노드의 주소와, 그 부모의 주소를 검색
	parent = NULL;
	pt = (*root);
	while ((pt != NULL) && (pt->testvalue != value)) {
		parent = pt;
		pt = ( value < pt->testvalue) ? pt->left : pt->right;
	}
	del = pt;

	// 삭제 처리
	if (del == NULL) {
		printf("\n삭제될 노드를 찾을 수 없음\n");
		return -1;
	}
	else if( del->left == NULL && del->right == NULL ) {
		// 단말노드인 경우
		if (parent != NULL) {
			if( parent->left == del ) parent->left = NULL;
			else parent->right = NULL;
		}
		else {
			(*root) = NULL;
		}

	}
	else if (del->left == NULL || del->right == NULL) {
		// 하나의 자식
		child = (del->left != NULL) ? del->left : del->right;
		if (parent != NULL) {
			if (parent->left == del) parent->left = child;
			else parent->right = child;
		}
		else {
			(*root) = child;
		}

	}
	else {
		// 2개의 자식
		parent_pt = del;
		pt = del->left;
		while (pt->right != NULL) {
			parent_pt = pt;
			pt = pt->right;
		}
		// 왼쪽 서브에서의 최대값의 주소
		del->testvalue = pt->testvalue;
		if (parent_pt->left == pt)parent_pt->left = pt->left;
		else parent_pt->right = pt->left;
		del = pt;
	}
	free(del);
	return 0;
}
//// AVL ///////////////////
int heightTree(BTNODE *root) {
	int lh, rh;
	if (root != NULL) {
		lh = heightTree(root->left);
		rh = heightTree(root->right);
		return 1 + ( lh > rh ? lh : rh );
	}
	return -1;	// null, leaf node 0
}
int diffHeightSubtree(BTNODE *root) {
	int lh, rh;
	if (root != NULL) {
		lh = heightTree(root->left);
		rh = heightTree(root->right);
		return (lh - rh);
	}
	return 0;
}
BTNODE* rotateRight(BTNODE *parent) {
	// 서브트리의 루트를 전달한다...
	BTNODE *child;
	child = parent->left;
	parent->left = child->right;
	child->right = parent;
	parent = child;
	return parent;
}
BTNODE* rotateLeft(BTNODE *parent) {
	// 서브트리의 루트를 전달한다...
	BTNODE *child;
	child = parent->right;
	parent->right = child->left;
	child->left = parent;
	parent = child;
	return parent;
}
BTNODE* LL(BTNODE *root) {
	root = rotateRight(root);
	return root;
}
BTNODE* RR(BTNODE *root) {
	root = rotateLeft(root);
	return root;
}
BTNODE* LR(BTNODE *root) {
	// root->left->right
	root->left = rotateLeft(root->left);
	root = rotateRight(root);
	return root;
}
BTNODE* RL(BTNODE *root) {
	// root->right->left
	root->right = rotateRight(root->right);
	root = rotateLeft(root);
	return root;
}
// 재정렬에 필요한 함수들 정의 끝

BTNODE *insertAvlNode(BTNODE *root, int value) {
	if (root == NULL) {
		root = newNode(value);
	}
	else {
		if (value > root->testvalue) {
			root->right = insertAvlNode(root->right, value);
			// 밸런싱
			if (diffHeightSubtree(root) == -2) {
				if( value > root->right->testvalue)
					root = RR(root);
				else
					root = RL(root);
			}
		}
		else {
			if (value < root->testvalue) {
				root->left = insertAvlNode(root->left, value);
				if (diffHeightSubtree(root) == 2) {
					if (value < root->left->testvalue) {
						root = LL(root);
					}
					else {
						root = LR(root);
					}
				}
			}
		}
	}
	root->height = heightTree(root);
	return root;
}
BTNODE * deleteAvlNode(BTNODE *root, int delvalue) {
	BTNODE *p;
	if (root != NULL) {
		if (delvalue > root->testvalue) {
			root->right = deleteAvlNode(root->right, delvalue);
			if (diffHeightSubtree(root) == 2) {
				if (diffHeightSubtree(root->left) >= 0) {
					root = LL(root);
				}
				else {
					root = LR(root);
				}
			}
		}
		else if (delvalue < root->testvalue) {
			root->left = deleteAvlNode(root->left, delvalue);
			if (diffHeightSubtree(root) == -2) {
				if (diffHeightSubtree(root->right) <= 0) {
					root = RR(root);
				}
				else {
					root = RL(root);
				}
			}
		}
		else {
			if (root->right != NULL) {
				p = root->left;
				while (p->left != NULL) {
					p = p->left;
				}
				root->testvalue = p->testvalue;
				root->right = deleteAvlNode(root->right, p->testvalue);
				if (diffHeightSubtree(root) == 2) {
					if (diffHeightSubtree(root->left) >= 0) {
						root = LL(root);
					}
					else {
						root = LR(root);
					}
				}
			}
			else {
				return root->left;
			}
		}
	}
	root->height = heightTree(root);
	return root;
}
int main() {
	BTNODE *root = NULL;
	int temp;

	root = insertAvlNode(root, 10);
	root = insertAvlNode(root, 14);
	root = insertAvlNode(root, 30);
	root = insertAvlNode(root, 1);
	traverseLevelorder(root);
	root = deleteAvlNode(root, 1);
	traverseLevelorder(root);
	root = deleteAvlNode(root, 14);
	traverseLevelorder(root);
	root = deleteAvlNode(root, 10);
	traverseLevelorder(root);
	return 0;
}
////////////////////////////
int main_btree() {
	BTNODE *temp;
	BTNODE *root = NULL;
	
	randomTree(&root, 20);
	printf("\nLevel order:");
	traverseLevelorder(root);
	//printf("\nPre order:");
	//traversePreorder(root);
	//printf("\nIn order:");
	//traverseInorder(root);
	//printf("\nPost order:");
	//traversePostorder(root);
	deleteNode(&root, 42);
	deleteNode(&root, 63);
	printf("\nLevel order:");
	traverseLevelorder(root);
	printf("\n");

	temp = searchNode(root, 42);
	if (temp != NULL) {
		printf("%p : %d \n", temp, temp->testvalue);
	}

	return 0;
}
