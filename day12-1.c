/* File I/O 
	����� ��� : �ؽ�Ʈ ���, ���̳ʸ� ���(������ ���� : format : Ȯ���� )
	���� ���� �뵵 : mode 
	"r"	�б�: ù �κ� : NULL		: �б⸸
	"w"	����: ù �κ� : �� ����	: �� ����
	"a"	�߰�: �� �κ� : �� ����	: ���� ����
	"r+" : �аų� ���� (��ȯ�ϱ�_fseek);

	"rt"	1byte ������ ���� ���� �б� ����
	"rb"	������ ũ�� ������ ���� ���� �б� ����
		�Ź� ũ�⸦ ����Ѵ�....

	�߿�!!!!
		���� ������ Ŀ��(cursor) ��ġ�� ����Ѵ�...
		SEEK_SET	0	���� ù ��ġ
		SEEK_CUR	1	���� ��ġ
		SEEK_END	2	�� ��ġ
*/
#include "Simple.h"
#include <windows.h>
// ���� �����ͺ���
FILE *fp = NULL;
struct _data_format {
	int idx;
	char title[80];
	int type;
};

int main() {
	struct _data_format	data = { 1,"Hong",20 };
	char fname[80] = { "db.dat" };

	fp = fopen(fname, "wb+");
	if (fp == NULL) {
		printf("Error return");
		return 1;
	}
	fwrite(&data, sizeof(struct _data_format), 1, fp);
	Sleep(10);
	fseek(fp,0,SEEK_SET);
	memset(&data, 0, sizeof(data));
	fread(&data, sizeof(struct _data_format), 1, fp);
	printf("%d : %s : %d \n", data.idx, data.title, data.type);
	fclose(fp);
	// ��ȯ
	return 0;
}

int main_binary_1() {
	// ����� �Լ� : 2�� read write
	//	�������ּ�, ũ��, ��, ����
	char fname[80] = { "db.dat" };
	char buf[80] = { 0 };
	buf[0] = 'A';
	buf[10] = 'D';
	buf[20] = 'S';
	buf[30] = 'A';
	fp = fopen(fname, "wb");
	// ������ 1�� ũ��, �� ��
	fwrite(buf, sizeof(char), 80, fp);
	fwrite(buf, sizeof(buf), 1, fp);
	fclose(fp);

	return 0;
}

int main_convert_html() {
	char srcfname[80] = { "a.c" };
	char destfname[80] = { "copy.html" };
	FILE *src, *dest;
	char ch;

	src = fopen(srcfname, "rt");
	dest = fopen(destfname, "wt");
	fputs("<!doctype html>", dest);
	// 1byte �� �����Ѵ�
	fputs("<body>", dest);
	while ((ch = fgetc(src)) != EOF) {
		if (ch == '\n') {
			fputs("<br/>",dest);
		}
		fputc(ch, dest);
	}
	fputs("</body>", dest);

	fclose(src);
	fclose(dest);
	return 0;
}

// ������ ���� : ���� ������ �о ����..
int main_copy() {
	char srcfname[80] = { "a.c" };
	char destfname[80] = { "copy.txt" };
	FILE *src, *dest;
	char ch;

	src = fopen(srcfname, "rt");
	dest = fopen(destfname, "wt");
	// 1byte �� �����Ѵ�
	while ((ch = fgetc(src)) != EOF) {
		fputc(ch, dest);
	}
	fclose(src);
	fclose(dest);
	return 0;
}

int main_file_2() {
	// ���� ���� ����� ( ���ڿ� )
	char fname[80] = { "text.txt" };

	{// ���� ���
		fp = fopen(fname, "wt");
		putc('A', fp);
		fputc('B', fp);
		fprintf(fp, "%c", 'C');
		fputc('\n', fp);	// ���� ���� �� \r\n
		fclose(fp);
	}
	{// ���� �Է�:�б�
		char ch;
		fp = fopen(fname, "rt");
		if (fp == NULL) {
			// ���. �ִµ� ���ٺҰ�(�б�,����,����)
		}
		// ���� ������ -1 ���´�... EOF
		// ���� ���ϳ����� ��� �о���̱�
		while ( (ch = fgetc(fp)) != EOF) {
			printf("%c", ch);
		}
		//ch = fgetc(fp);	printf("%d,", ch);

		fclose(fp);

	}
	{// ���ڿ� ���:����
		char buf[80] = { "Hello C World" };
		fp = fopen(fname, "wt");
		fputs(buf, fp);
		fprintf(fp, buf);
		fprintf(fp, "%s\n", buf);
		fclose(fp);
	}
	{// ���ڿ� �Է�:�б�
		// �� ���� �Է� : ù����~���๮��
		char readBuffer[80] = { 0 };
		char *r;
		fp = fopen(fname, "rt");
		// ������ ������ ������� �Է�ó��
		memset(readBuffer, 0, sizeof(readBuffer));
		r = fgets(readBuffer, 78, fp);
		if (r == NULL) { return 0; }
		printf("%s : %d\n", readBuffer, r);

		memset(readBuffer, 0, sizeof(readBuffer));
		r = fgets(readBuffer, 78, fp);
		printf("%s : %d\n", readBuffer, r);

		memset(readBuffer, 0, sizeof(readBuffer));
		r = fgets(readBuffer, 78, fp);
		printf("%s : %d\n", readBuffer, r);

		fclose(fp);
	}

	return 0;
}

int main_file_1() {
	int fsize;
	// ���ϸ�(����,���) ����
	char filename[] = {"test.txt"};
//	const char *fname = "C:\\ProgramFiles\\text.dat";

	// ���ٸ�� ���� ( �б�, ����, �߰� ): �ؽ�Ʈ ���, ���̳ʸ� ���
	// ���Ͽ���(���ϸ�, ���ٸ��)
	fp = fopen(filename, "rt");
	if (fp == NULL) {
		printf("%s �� ã�� �� ����\n", filename);
		// ������Ʈ ���� ����....
	}
	else {
		// ���������(text , binary )
		fseek(fp, 0, SEEK_END); // Ŀ���� ������ ������ �Űܶ�...
		fsize = ftell(fp);		// ����~����Ŀ����ġ ����Ʈ ��ȯ
		printf("size : %d \n", fsize);
		fseek(fp, 0, SEEK_SET);
//		rewind(fp);	// ������ġ�� �ű��...

		// ���ϴݱ�
		fclose(fp);
	}

	return 0;
}
