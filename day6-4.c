#include "Simple.h"

int main() {
	// 별모양 움직인다...
	int pan[15*15];
	int i, k, v;
	int x, y;
	char ch;
	for (i = 0; i < 225; ++i) {
		pan[i] = 1;
	}
	x = 0;
	y = 1;
	pan[y*15+x] = 2;
	while (1) {
		system("cls");
		for (i = 0; i < 15;++i) {
			for (k = 0; k < 15;++k) {
				v = pan[i*15+k];// 0 ~ 224
				printf("%s", (v == 1) ? "■" : (v == 2) ? "☆" : "  ");
			}
			printf("\n");
		}// 출력
		ch = getch();
		pan[y * 15 + x] = 0;
		switch (ch) {
		case 'w':	--y;	break;
		case 's':	++y;	break;
		case 'a':	--x;	break;
		case 'd':	++x;	break;
//		case 'q': break;
		}
		pan[y * 15 + x] = 2;
		if (ch == 'q') {
			break;
		}
	}
	return 0;
}
