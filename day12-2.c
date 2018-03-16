#include "Simple.h"
#pragma pack(push,1)
typedef struct _bmpheader {
	// file header
	unsigned short magic;	// 'BM'
	unsigned int fsize;		// file size
	unsigned short reserved1, reserved2;
	unsigned int offset;	// 54 bytes
	// Info header
	unsigned int hsize;		// of this header(40 bytes)
	int width;				// the bitmap width in pixels(signed integer)
	int height;				// the bitmap height in pixels(signed integer)
	unsigned short planes;	// the number of color planes(must be 1)
	unsigned short bits;	// the number of bits per pixel, which is the color depth of the image.	Typical values are 1, 4, 8, 16, 24 and 32.
	unsigned int compressed;// the compression method being used.See the next table for a list of possible values
	unsigned int image_size;// the image size.
	int h_res;				// the horizontal resolution of the image. (pixel per meter, signed integer)
	int v_res;				// the vertical resolution of the image. (pixel per meter, signed integer)
	unsigned int colors;	// 0 the number of colors in the color palette, or 0 to default to 2n
	unsigned int icolors;	// 0 the number of important colors used, or 0 when every color is important; generally ignored
}BMPHEADER;
typedef struct _rgb_32bit_color {
	unsigned char blue;
	unsigned char green;
	unsigned char red;
	unsigned char alpha;
}RGB32;
typedef struct _rgb_24bit_color {
	unsigned char blue;
	unsigned char green;
	unsigned char red;
}RGB24;
#pragma pack(pop)
BMPHEADER	initedBmpHeader = {0x4D42,0,0,0,54,40,0,0,1,0,0,0,0,0,0,0};

int main() {
	BMPHEADER header;
	FILE *fbmp;
	char fname[80] = { "make.bmp" };
	RGB24 *table = NULL;

	fbmp = fopen(fname, "rb");
	if (fbmp != NULL) {
		fread(&header, sizeof(header), 1, fbmp);
		printf("image size : %d \n", header.image_size);
		table = (RGB24*)malloc(header.image_size);
		fread(table, header.image_size, 1, fbmp);
		fclose(fbmp);

		fbmp = fopen("copy.bmp", "wb");
		fwrite(&header, sizeof(header), 1, fbmp);
		fwrite(table, header.image_size, 1, fbmp);
		fclose(fbmp);
		printf("width : %d \n", header.width);
		printf("height : %d \n", header.height);
		printf("bits : %d \n", header.bits);
		free(table);
	}

	{
		int width;
		int height;
		int i, k;
		table[i*width + k];// [i][k]
	}

	{
		// 행의 수 미정, 열의 수 미정
		RGB24 **table;

		table = (RGB24 **)malloc(sizeof(*table)*header.height);
		table[0 ~height - 1] = malloc(sizeof(RGB24) * header.width);
		table[i][k];
	}


	return 0;
}

int main_write_bmp() {
	BMPHEADER header;
	FILE *fbmp;
	char fname[80] = { "sample.bmp" };
	RGB24 red;
	RGB24 table[400][600] = { 0 };
	int i;
	red.blue = 0;
	red.green = 0;
	red.red = 255;

	for (i = 0; i < 600; ++i) {
		table[200][i] = red;
	}

	header = initedBmpHeader;
	header.bits = 24;
	header.height = 400;
	header.width = 600;
	header.image_size = 400 * 600 * (24 / 8);
	header.fsize = header.image_size + 54;

	fbmp = fopen(fname, "wb");
	fwrite(&header, sizeof(header), 1, fbmp);
	fwrite(table, sizeof(table), 1, fbmp);
	fclose(fbmp);

	return 0;
}