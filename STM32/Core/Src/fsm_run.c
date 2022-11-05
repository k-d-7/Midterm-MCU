#include "fsm_run.h"

void fsm_simple_buttons_run() {
	switch (mode) {
		case INIT:
			mode = DISPLAY;
			break;
		case DISPLAY:
			display7SEG(value);
			if (isResetPressed() == 1) {
				setTimer2(1000);
				mode = RESET_STATE;
			}
			if (isDecPressed() == 1) {
				setTimer2(1000);
				mode = DEC_STATE;
			}
			if (isIncPressed() == 1) {
				setTimer2(1000);
				mode = INC_STATE;
			}
//			if (timer2_flag == 1) {
//				mode = COUNTDOWN_STATE;
//			}
			break;

		case RESET_STATE:
			value = 0;
			mode = DISPLAY;
			break;
		case INC_STATE:
			value++;
			if (value > 9) {
				value = 0;
			}
			mode = DISPLAY;
			break;
		case DEC_STATE:
			value--;
			if (value < 0) {
				value = 9;
			}
			mode = DISPLAY;
			break;
		case COUNTDOWN_STATE:
//			value--;
//			setTimer2(100);
//			if (value < 0) {
//				value = 0;
//				timer2_flag = 0;
//			}
//			mode = DISPLAY;
			break;
		default:
			break;
	}
}


