#include "button.h"

int keyRegButton1_1 = NORMAL_STATE;
int keyRegButton1_2 = NORMAL_STATE;
int keyRegButton1_3 = NORMAL_STATE;
int keyRegButton1_4 = NORMAL_STATE;

int keyRegButton2_1 = NORMAL_STATE;
int keyRegButton2_2 = NORMAL_STATE;
int keyRegButton2_3 = NORMAL_STATE;
int keyRegButton2_4 = NORMAL_STATE;

int keyRegButton3_1 = NORMAL_STATE;
int keyRegButton3_2 = NORMAL_STATE;
int keyRegButton3_3 = NORMAL_STATE;
int keyRegButton3_4 = NORMAL_STATE;



int reset_flag = 0;
int inc_flag = 0;
int dec_flag = 0;

int timeOutButton1 = 300;
int timeOutButton2 = 300;
int timeOutButton3 = 300;

int isResetPressed() {
	if (reset_flag == 1) {
		reset_flag = 0;
		return 1;
	}
	return 0;
}

int isIncPressed() {
	if (inc_flag == 1) {
		inc_flag = 0;
		return 1;
	}
	return 0;
}

int isDecPressed() {
	if (dec_flag == 1) {
		dec_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess1() {
	reset_flag = 1;
}

void subKeyProcess2() {
	inc_flag = 1;
}

void subKeyProcess3() {
	dec_flag = 1;
}

void getKeyReset() {
	keyRegButton1_1 = keyRegButton1_2;
	keyRegButton1_2 = keyRegButton1_3;
	keyRegButton1_3 = HAL_GPIO_ReadPin(RESET_GPIO_Port, RESET_Pin);
	if ((keyRegButton1_1 == keyRegButton1_2) && (keyRegButton1_2 == keyRegButton1_3)) {
		if (keyRegButton1_3 != keyRegButton1_4) {
			keyRegButton1_4 = keyRegButton1_3;
			if (keyRegButton1_4 == PRESSED_STATE) {
				timeOutButton1 = 300;
				subKeyProcess1();
			}
		} else {
			timeOutButton1--;
			if (timeOutButton1 <= 0) {
				keyRegButton1_4 = NORMAL_STATE;
			}
		}
	}
}

void getKeyInc() {
	keyRegButton2_1 = keyRegButton2_2;
	keyRegButton2_2 = keyRegButton2_3;
	keyRegButton2_3 = HAL_GPIO_ReadPin(INC_GPIO_Port, INC_Pin);
	if ((keyRegButton2_1 == keyRegButton2_2) && (keyRegButton2_2 == keyRegButton2_3)) {
		if (keyRegButton2_3 != keyRegButton2_4) {
			keyRegButton2_4 = keyRegButton2_3;
			if (keyRegButton2_4 == PRESSED_STATE) {
				timeOutButton2 = 300;
				subKeyProcess2();
			}
		} else {
			timeOutButton2--;
			if (timeOutButton2 <= 0) {
				keyRegButton2_4 = NORMAL_STATE;
			}
		}
	}
}

void getKeyDec() {
	keyRegButton3_1 = keyRegButton3_2;
	keyRegButton3_2 = keyRegButton3_3;
	keyRegButton3_3 = HAL_GPIO_ReadPin(DEC_GPIO_Port, DEC_Pin);
	if ((keyRegButton3_1 == keyRegButton3_2) && (keyRegButton3_2 == keyRegButton3_3)) {
		if (keyRegButton3_3 != keyRegButton3_4) {
			keyRegButton3_4 = keyRegButton3_3;
			if (keyRegButton3_4 == PRESSED_STATE) {
				timeOutButton3 = 300;
				subKeyProcess3();
			}
		} else {
			timeOutButton3--;
			if (timeOutButton3 <= 0) {
				keyRegButton3_4 = NORMAL_STATE;
			}
		}
	}
}
