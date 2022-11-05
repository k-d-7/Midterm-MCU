/*
 * global.h
 *
 *  Created on: Nov 5, 2022
 *      Author: khuon
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"

#define INIT			0
#define DISPLAY			1
#define COUNTDOWN_STATE	2
#define RESET_STATE		3
#define INC_STATE		4
#define DEC_STATE		5

extern int value;
extern int mode;

#endif /* INC_GLOBAL_H_ */
