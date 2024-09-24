/*
 * type_cast.c
 *
 *  Created on: Aug 20, 2024
 *      Author: feger
 */

#include <stdio.h>

int main(void)
{
	//unsigned char data = 0x01 + 0x0089;
	// unsigned char data = 0x00000001 + 0x00000089
	// Implicit casting (Compiler does this)

	unsigned char data = (unsigned char)(0x01 + 0x0089);
	// Explicit casting (Programmer does this)
	// 데이터 손실을 방지하지는 않는다

	float result = (float)80 / 3;
	// Explicit casting (Programmer does this)

	printf("Data : %X result : %f\n", data, result);
}
