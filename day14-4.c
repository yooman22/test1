#include "Simple.h"

struct _user {
	int code;
	char name[80];
	char id[80];
	char pw[12];
};
typedef struct _user User;
struct _usertable {
	struct _user *base;	// �����迭
	int size;	// ����(��������ȣ)
};
typedef struct _usertable UTable;

int viewList(UTable table) {// �� ����
	User *base;	// ������...
	int i;
	User temp;
	base = table.base;	// �迭 �ݺ�
	for (i = 0; i <= table.size; i++) {
		temp = base[i];
		printf("[%d] %s \n", i, temp.name);
	}
	return 0;
}
int append(UTable *param, User arg) {
	param->size++;
	param->base = (User*)realloc( 
			param->base, 
			sizeof(User) * (param->size + 1) );
	param->base[param->size] = arg;
	return 0;
}
User getUserByIndex(UTable table, int i) {
	User clear = { 0 };
	if (table.base != NULL) {
		if (table.size >= i) {
			return table.base[i];
		}
	}
	return clear;// ��ȯ�Ұ��� ����...
}
int viewUser(User arg) {
	printf("Code : %d \n", arg.code);
	printf("Name : %s \n", arg.name);
	printf("ID : %s \n", arg.id);
	printf("PW : %s \n", arg.pw);
	return 0;
}
UTable searchBy(UTable table, User key) {
	UTable result = { NULL,-1 };
	result.base;
	result.size;
	return result;
}
int main() {
	UTable main_table = { NULL, -1 };
	UTable result;
	User temp;
	char buf[80];
	int i;

	while (1) {
		viewList(main_table);
		printf("[1]����[2]�߰�[0]����\nMenu: ");
		scanf("%d", &i);	rewind(stdin);
		if( i == 1 ){
			printf("ȸ������ ����:��ȣ�� ���� ");
			scanf("%d", &i);	rewind(stdin);
			temp = getUserByIndex(main_table, i);
			viewUser(temp);
		}
		else if(i == 2){
			printf("ȸ������ �Է�\n");
			printf("Name : ");
			fgets(buf, sizeof(buf), stdin);
			strcpy(temp.name, buf);
			printf("Id : ");
			fgets(buf, sizeof(buf), stdin);
			strcpy(temp.id, buf);
			printf("Pw : ");
			fgets(buf, sizeof(buf), stdin);
			strcpy(temp.pw, buf);

			append(&main_table, temp);// &temp
		}
	}
	return 0;
}