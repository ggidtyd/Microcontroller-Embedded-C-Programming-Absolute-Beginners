/*
 * main.c
 *
 *  Created on: Aug 20, 2024
 *      Author: feger
 */

#include <stdio.h>
#include "math.h"

int main(void)
{
	printf("Add : %X\n", math_add(0x0FFF1111, 0x0FFF1111));
	printf("Mul : %I64X\n", math_mul(0x0FFF1111, 0x0FFF1111));
	printf("Div : %f\n", math_div(100, 8));

	return 0;
}
