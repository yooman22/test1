#include "Simple.h"

typedef struct _sllist_node {
	struct _sllist_node *front, *back;
	int id;
	char msg[80];
}NODE;
NODE *head, *tail;

int request(NODE *node) {
	if (head == NULL) {
		head = node;
	}
	else {
		tail->front = node;
//		node->front = tail;
	}
	tail = node;
	return 0;
}
int viewNode(NODE *node) {
	printf("pointer : %p %p \n", node->front, node->back);
	printf("id : %d \n", node->id);
	printf("message : %s \n", node->msg);
	return 0;
}
int viewList() {
	NODE *temp;
	NODE *sub;
	temp = head;
	while (temp) {
		printf("id : %d : %s\n", temp->id, temp->msg);
		sub = temp->back;
		while (sub) {
			printf("\tid : %d : %s\n", sub->id, sub->msg);
			sub = sub->back;
		}
		temp = temp->front;
	}
	return 0;
}
int getNode() {
	NODE *node;
	char buf[80] = { 0 };
	printf("ID Message \n");
	fgets(buf, sizeof(buf), stdin);
	node = (NODE*)calloc(1, sizeof(NODE));
	sscanf(buf, "%d %s", &node->id, node->msg);
	request(node);
	return 0;
}
int getNodeSubtask(NODE *head) {
	NODE *node;
	char buf[80] = { 0 };
	printf("ID Message \n");
	fgets(buf, sizeof(buf), stdin);
	node = (NODE*)calloc(1, sizeof(NODE));
	sscanf(buf, "%d %s", &node->id, node->msg);

	// head 에서 마지막 찾는다...
	{
		NODE *temp;
		temp = head;
		while (temp->back) {
			temp = temp->back;
		}
		temp->back = node;
//		node->back = tail;
	}
	return 0;
}
NODE *getNodeById(NODE *node, int id) {
	if ( node == NULL ) {
		return NULL;
	}
	if ( node->id == id ) {
		return node;
	}
	return getNodeById(node->front, id);
}
int main() {
	int menu, id;
	NODE *node;
	while (1) {
		printf("---------------\n");
		viewList();
		printf("---------------\n[1]request[2]view[3]sub[0]exit:");
		scanf("%d", &menu); rewind(stdin);
		if (menu == 0)break;
		if (menu == 1) {
			printf("새 요청을 입력\n");
			getNode();
		}
		if (menu == 2) {
			printf("view node info \n");
			printf("node id : ");
			scanf("%d", &id); rewind(stdin);
			node = getNodeById(head,id);
			if (node) {
				viewNode(node);
			}
			else {
				printf("NullPointException\n");
			}
		}
		if (menu == 3) {
			printf("add subtask node \n");
			printf("node id : ");
			scanf("%d", &id); rewind(stdin);
			node = getNodeById(head, id);
			if (node) {
				getNodeSubtask(node);
			}
			else {
				printf("NullPointException\n");
			}

		}

	}

	return 0;
}
