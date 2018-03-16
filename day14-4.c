#include "Simple.h"

struct _user {
	int code;
	char name[80];
	char id[80];
	char pw[12];
};
typedef struct _user User;
struct _usertable {
	struct _user *base;	// 동적배열
	int size;	// 길이(마지막번호)
};
typedef struct _usertable UTable;

int viewList(UTable table) {// 값 복사
	User *base;	// 꺼낸다...
	int i;
	User temp;
	base = table.base;	// 배열 반복
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
	return clear;// 반환할것이 없다...
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
		printf("[1]보기[2]추가[0]종료\nMenu: ");
		scanf("%d", &i);	rewind(stdin);
		if( i == 1 ){
			printf("회원정보 보기:번호를 선택 ");
			scanf("%d", &i);	rewind(stdin);
			temp = getUserByIndex(main_table, i);
			viewUser(temp);
		}
		else if(i == 2){
			printf("회원정보 입력\n");
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