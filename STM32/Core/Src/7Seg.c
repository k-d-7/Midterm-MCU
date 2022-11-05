#include "7Seg.h"

uint8_t segNumber[10] = {
		0x40,
		0x79,
		0x24,
		0x30,
		0x19,
		0x12,
		0x02,
		0x78,
		0x00,
		0x10
};

void display7SEG(int num) {
	HAL_GPIO_WritePin(SEG7_a_GPIO_Port, SEG7_a_Pin, (segNumber[num]>>0) & 0x01);
	HAL_GPIO_WritePin(SEG7_b_GPIO_Port, SEG7_b_Pin, (segNumber[num]>>1) & 0x01);
	HAL_GPIO_WritePin(SEG7_c_GPIO_Port, SEG7_c_Pin, (segNumber[num]>>2) & 0x01);
	HAL_GPIO_WritePin(SEG7_d_GPIO_Port, SEG7_d_Pin, (segNumber[num]>>3) & 0x01);
	HAL_GPIO_WritePin(SEG7_e_GPIO_Port, SEG7_e_Pin, (segNumber[num]>>4) & 0x01);
	HAL_GPIO_WritePin(SEG7_f_GPIO_Port, SEG7_f_Pin, (segNumber[num]>>5) & 0x01);
	HAL_GPIO_WritePin(SEG7_g_GPIO_Port, SEG7_g_Pin, (segNumber[num]>>6) & 0x01);
}

