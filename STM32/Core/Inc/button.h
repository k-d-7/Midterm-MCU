/*
 * button.h
 *
 *  Created on: Nov 5, 2022
 *      Author: khuon
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE	GPIO_PIN_SET
#define PRESSED_STATE	GPIO_PIN_RESET

extern int reset_flag;
extern int inc_flag;
extern int dec_flag;

int isResetPressed();
int isIncPressed();
int isDecPressed();

void getKeyReset();
void getKeyInc();
void getKeyDec();

#endif /* INC_BUTTON_H_ */
