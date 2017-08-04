#include <stdio.h>

void movTest();
void addTest();
void subTest();
void mulTest();
void divTest();
void shiftTest();
void cmpjuTest();
void doWhileTest();
void evenAdd();
/*
int main(int argc, char* argv[]) {
	evenAdd();
	return 0;
}
*/
void movTest() {
	int a = 1;
	int nValue = 0;
	__asm
	{
		mov eax, 1
		mov nValue, eax
	}
	printf("nValue : %d\n", nValue);
}

void addTest() {
	int a = 1;
	int b = 2;
	int c = 0;
	__asm
	{
		pushad
		mov eax, a;
		mov ebx, b;
		add eax, ebx;
		mov c, eax;
		popad
	}

	printf("result C : %d\n", c);
}

void subTest() {
	int a = 5;
	int b = 7;
	int c = 0;
	__asm
	{
		pushad
		mov ebx, a;
		sub ebx, b;
		mov c, ebx;
		popad
	}
	printf("result C : %d\n", c);
}

void mulTest() {
	int a = 5;
	int b = 0;

	__asm {
		pushad
		mov eax, 15
		mov ebx, a
		mul ebx
		mov b, eax
		popad
	}
	printf("result B : %d\n", b);
}

void divTest() {
	int a = 0;
	int b = 0;

	__asm{
		pushad
		mov eax, 10
		cdq
		mov ebx, 4
		div ebx
		mov a, eax
		mov b, edx
		popad
	}
	printf("result a : %d\nresult b : %d\n", a, b);
}

void shiftTest() {
	int a = 8;

	__asm {
		pushad
		mov eax, a
		shl eax, 1
		mov a, eax
		popad
	}
	printf("%d", a);
	
	__asm {
		pushad
		mov eax, a
		shr eax, 2
		mov a, eax
		popad
	}
	printf("%d", a);
}

void cmpjuTest() {
	int result = 0;
	__asm {
		pushad
		mov eax, 0
		LP:
		inc eax
		cmp eax, 1000
		jne LP
		mov result, eax
		popad
	}
	printf("reuslt : %d\n", result);
}

void doWhileTest() {
	int result = 0;
	__asm {
		pushad
		mov eax, 100
LP:
		dec eax
		jnz LP
		mov result, eax
		popad
	}
	printf("reuslt : %d\n", result);
}

void evenAdd() {
	int result = 0;
	int a = 0;
	__asm {
		pushad
		
		LP:
		inc a
		mov eax, a
		cdq
		mov ebx, 2

		div ebx
		mov eax, a

		cmp edx, 0
		jne LP2

		add result, eax

		LP2:
		cmp eax, 100
		jle LP

		popad
	}
	printf("%d\n", result);
}