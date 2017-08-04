#include<stdio.h>
void movdquTest();

int main(int argc, char* argv[]) {
	movdquTest();
	return 0;
}

void movdquTest() {
	short ShortArrayA[8] = { 1,2,3,4,5,6,7,8 };
	short ShortArrayB[8] = { 0 };

	__asm {
		pushad
		pxor xmm0, xmm0
		movdqu xmm0, ShortArrayA
		movdqu ShortArrayB, xmm0
		popad
		emms
	}

	printf("ShortArrayB : %d, %d, %d, %d, %d, %d, %d, %d\n",
		ShortArrayB[0], ShortArrayB[1], ShortArrayB[2], ShortArrayB[3],
		ShortArrayB[4], ShortArrayB[5], ShortArrayB[6], ShortArrayB[7]);
}