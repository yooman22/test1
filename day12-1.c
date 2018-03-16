/* File I/O 
	입출력 방법 : 텍스트 기반, 바이너리 기반(데이터 형식 : format : 확장자 )
	파일 접근 용도 : mode 
	"r"	읽기: 첫 부분 : NULL		: 읽기만
	"w"	쓰기: 첫 부분 : 새 파일	: 새 파일
	"a"	추가: 끝 부분 : 새 파일	: 기존 파일
	"r+" : 읽거나 쓰기 (전환하기_fseek);

	"rt"	1byte 단위로 여러 개를 읽기 쓰기
	"rb"	지정된 크기 단위로 여러 개를 읽기 쓰기
		매번 크기를 계산한다....

	중요!!!!
		파일 내에는 커서(cursor) 위치를 고려한다...
		SEEK_SET	0	시작 첫 위치
		SEEK_CUR	1	현재 위치
		SEEK_END	2	끝 위치
*/
#include "Simple.h"
#include <windows.h>
// 파일 포인터변수
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
	// 전환
	return 0;
}

int main_binary_1() {
	// 입출력 함수 : 2개 read write
	//	데이터주소, 크기, 개, 파일
	char fname[80] = { "db.dat" };
	char buf[80] = { 0 };
	buf[0] = 'A';
	buf[10] = 'D';
	buf[20] = 'S';
	buf[30] = 'A';
	fp = fopen(fname, "wb");
	// 데이터 1개 크기, 몇 개
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
	// 1byte 씩 복사한다
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

// 파일을 복사 : 문자 단위로 읽어서 쓴다..
int main_copy() {
	char srcfname[80] = { "a.c" };
	char destfname[80] = { "copy.txt" };
	FILE *src, *dest;
	char ch;

	src = fopen(srcfname, "rt");
	dest = fopen(destfname, "wt");
	// 1byte 씩 복사한다
	while ((ch = fgetc(src)) != EOF) {
		fputc(ch, dest);
	}
	fclose(src);
	fclose(dest);
	return 0;
}

int main_file_2() {
	// 문자 단위 입출력 ( 문자열 )
	char fname[80] = { "text.txt" };

	{// 문자 출력
		fp = fopen(fname, "wt");
		putc('A', fp);
		fputc('B', fp);
		fprintf(fp, "%c", 'C');
		fputc('\n', fp);	// 파일 저장 시 \r\n
		fclose(fp);
	}
	{// 문자 입력:읽기
		char ch;
		fp = fopen(fname, "rt");
		if (fp == NULL) {
			// 없어서. 있는데 접근불가(읽기,쓰기,실행)
		}
		// 파일 끝나면 -1 나온다... EOF
		// 문자 파일끝까지 모두 읽어들이기
		while ( (ch = fgetc(fp)) != EOF) {
			printf("%c", ch);
		}
		//ch = fgetc(fp);	printf("%d,", ch);

		fclose(fp);

	}
	{// 문자열 출력:쓰기
		char buf[80] = { "Hello C World" };
		fp = fopen(fname, "wt");
		fputs(buf, fp);
		fprintf(fp, buf);
		fprintf(fp, "%s\n", buf);
		fclose(fp);
	}
	{// 문자열 입력:읽기
		// 행 단위 입력 : 첫글자~개행문자
		char readBuffer[80] = { 0 };
		char *r;
		fp = fopen(fname, "rt");
		// 저장할 공간을 비워놓고 입력처리
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
	// 파일명(절대,상대) 지정
	char filename[] = {"test.txt"};
//	const char *fname = "C:\\ProgramFiles\\text.dat";

	// 접근모드 지정 ( 읽기, 쓰기, 추가 ): 텍스트 기반, 바이너리 기반
	// 파일열기(파일명, 접근모드)
	fp = fopen(filename, "rt");
	if (fp == NULL) {
		printf("%s 을 찾을 수 없음\n", filename);
		// 프로젝트 폴더 기준....
	}
	else {
		// 파일입출력(text , binary )
		fseek(fp, 0, SEEK_END); // 커서를 파일의 끝으로 옮겨라...
		fsize = ftell(fp);		// 시작~현재커서위치 바이트 반환
		printf("size : %d \n", fsize);
		fseek(fp, 0, SEEK_SET);
//		rewind(fp);	// 시작위치로 옮긴댜...

		// 파일닫기
		fclose(fp);
	}

	return 0;
}
