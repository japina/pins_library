#include "pins.h"

int8_t pinMode(uint8_t pinName, uint8_t dir) {
    if (pinName < 15) {
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);	
    }
    if ((pinName > 14) && (pinName < 31)) {
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);
    }
    if (pinName == 31) {
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);	
    }
    if ((pinName < 0) || (pinName > 31)) {
	return -1;
    }
    GPIO_InitTypeDef GPIO_InitDef;

    switch (pinName) {
    case 0://A
    case 16://B	
	GPIO_InitDef.GPIO_Pin = GPIO_Pin_0;
	break;
    case 1:
    case 17:
	GPIO_InitDef.GPIO_Pin = GPIO_Pin_1;
	break;
    case 2:
    case 18:
	GPIO_InitDef.GPIO_Pin = GPIO_Pin_2;
	break;
    case 3:
    case 19:
	GPIO_InitDef.GPIO_Pin = GPIO_Pin_3;
	break;
    case 4:
    case 20:
	GPIO_InitDef.GPIO_Pin = GPIO_Pin_4;
	break;
    case 5:
    case 21:
	GPIO_InitDef.GPIO_Pin = GPIO_Pin_5;
	break;
    case 6:
    case 22:
	GPIO_InitDef.GPIO_Pin = GPIO_Pin_6;
	break;
    case 7:
    case 23:
	GPIO_InitDef.GPIO_Pin = GPIO_Pin_7;
	break;
    case 8:
    case 24:
	GPIO_InitDef.GPIO_Pin = GPIO_Pin_8;
	break;
    case 9:
    case 25:
	GPIO_InitDef.GPIO_Pin = GPIO_Pin_9;
	break;
    case 10:
    case 26:
	GPIO_InitDef.GPIO_Pin = GPIO_Pin_10;
	break;
    case 11:
    case 27:
	GPIO_InitDef.GPIO_Pin = GPIO_Pin_11;
	break;
    case 12:
    case 28:
	GPIO_InitDef.GPIO_Pin = GPIO_Pin_12;
	break;
    case 13:
    case 29: 
    case 32: //C
	GPIO_InitDef.GPIO_Pin = GPIO_Pin_13;
	break;
    case 14:
    case 30:
	GPIO_InitDef.GPIO_Pin = GPIO_Pin_14;
	break;
    case 15:
    case 31:
	GPIO_InitDef.GPIO_Pin = GPIO_Pin_15;
	break;
    default:
	return -1;
    }
    GPIO_InitDef.GPIO_OType = GPIO_OType_PP;
    if (dir==IN){
	GPIO_InitDef.GPIO_Mode = GPIO_Mode_IN;	
    } else {
	GPIO_InitDef.GPIO_Mode = GPIO_Mode_OUT;	
    }
    GPIO_InitDef.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitDef.GPIO_Speed = GPIO_Speed_10MHz;
    //Initialize pins
    if (pinName < 15) {
	GPIO_Init(GPIOA, &GPIO_InitDef);    
    }
    if ((pinName > 14) && (pinName < 32)) {
	GPIO_Init(GPIOB, &GPIO_InitDef);
    }
    if (pinName == 32) {
	GPIO_Init(GPIOC, &GPIO_InitDef);
    }    
    return 0;
}
int8_t digitalWrite(uint8_t pinName, uint8_t value) {
    if (value == HIGH) {
	switch(pinName){
	case 0:
	    GPIO_SetBits(GPIOA, GPIO_Pin_0);
	    break;
	case 1:
	    GPIO_SetBits(GPIOA, GPIO_Pin_1);
	    break;
	case 2:
	    GPIO_SetBits(GPIOA, GPIO_Pin_2);
	    break;
	case 3:
	    GPIO_SetBits(GPIOA, GPIO_Pin_3);
	    break;
	case 4:
	    GPIO_SetBits(GPIOA, GPIO_Pin_4);
	    break;
	case 5:
	    GPIO_SetBits(GPIOA, GPIO_Pin_5);
	    break;
	case 6:
	    GPIO_SetBits(GPIOA, GPIO_Pin_6);
	    break;
	case 7:
	    GPIO_SetBits(GPIOA, GPIO_Pin_7);
	    break;
	case 8:
	    GPIO_SetBits(GPIOA, GPIO_Pin_8);
	    break;
	case 9:
	    GPIO_SetBits(GPIOA, GPIO_Pin_9);
	    break;
	case 10:
	    GPIO_SetBits(GPIOA, GPIO_Pin_10);
	    break;
	case 11:
	    GPIO_SetBits(GPIOA, GPIO_Pin_11);
	    break;
	case 12:
	    GPIO_SetBits(GPIOA, GPIO_Pin_12);
	    break;
	case 13:
	    GPIO_SetBits(GPIOA, GPIO_Pin_13);
	    break;
	case 14:
	    GPIO_SetBits(GPIOA, GPIO_Pin_14);
	    break;
	case 15:
	    GPIO_SetBits(GPIOA, GPIO_Pin_15);
	    break;
	case 16:
	    GPIO_SetBits(GPIOB, GPIO_Pin_0);
	    break;
	case 17:
	    GPIO_SetBits(GPIOB, GPIO_Pin_1);
	    break;
	case 18:
	    GPIO_SetBits(GPIOB, GPIO_Pin_2);
	    break;
	case 19:
	    GPIO_SetBits(GPIOB, GPIO_Pin_3);
	    break;
	case 20:
	    GPIO_SetBits(GPIOB, GPIO_Pin_4);
	    break;
	case 21:
	    GPIO_SetBits(GPIOB, GPIO_Pin_5);
	    break;
	case 22:
	    GPIO_SetBits(GPIOB, GPIO_Pin_6);
	    break;
	case 23:
	    GPIO_SetBits(GPIOB, GPIO_Pin_7);
	    break;
	case 24:
	    GPIO_SetBits(GPIOB, GPIO_Pin_8);
	    break;
	case 25:
	    GPIO_SetBits(GPIOB, GPIO_Pin_9);
	    break;
	case 26:
	    GPIO_SetBits(GPIOB, GPIO_Pin_10);
	    break;
	case 27:
	    GPIO_SetBits(GPIOB, GPIO_Pin_11);
	    break;
	case 28:
	    GPIO_SetBits(GPIOB, GPIO_Pin_12);
	    break;
	case 29:
	    GPIO_SetBits(GPIOB, GPIO_Pin_13);
	    break;
	case 30:
	    GPIO_SetBits(GPIOB, GPIO_Pin_14);
	    break;
	case 31:
	    GPIO_SetBits(GPIOB, GPIO_Pin_15);
	    break;
	case 32:
	    GPIO_SetBits(GPIOC, GPIO_Pin_13);
	    break;
	default:
	    return -1;
	}

    } else {
	switch (pinName){
	case 0:
	    GPIO_ResetBits(GPIOA, GPIO_Pin_0);
	    break;
	case 1:
	    GPIO_ResetBits(GPIOA, GPIO_Pin_1);
	    break;
	case 2:
	    GPIO_ResetBits(GPIOA, GPIO_Pin_2);
	    break;
	case 3:
	    GPIO_ResetBits(GPIOA, GPIO_Pin_3);
	    break;
	case 4:
	    GPIO_ResetBits(GPIOA, GPIO_Pin_4);
	    break;
	case 5:
	    GPIO_ResetBits(GPIOA, GPIO_Pin_5);
	    break;
	case 6:
	    GPIO_ResetBits(GPIOA, GPIO_Pin_6);
	    break;
	case 7:
	    GPIO_ResetBits(GPIOA, GPIO_Pin_7);
	    break;
	case 8:
	    GPIO_ResetBits(GPIOA, GPIO_Pin_8);
	    break;
	case 9:
	    GPIO_ResetBits(GPIOA, GPIO_Pin_9);
	    break;
	case 10:
	    GPIO_ResetBits(GPIOA, GPIO_Pin_10);
	    break;
	case 11:
	    GPIO_ResetBits(GPIOA, GPIO_Pin_11);
	    break;
	case 12:
	    GPIO_ResetBits(GPIOA, GPIO_Pin_12);
	    break;
	case 13:
	    GPIO_ResetBits(GPIOA, GPIO_Pin_13);
	    break;
	case 14:
	    GPIO_ResetBits(GPIOA, GPIO_Pin_14);
	    break;
	case 15:
	    GPIO_ResetBits(GPIOA, GPIO_Pin_15);
	    break;
	case 16:
	    GPIO_ResetBits(GPIOB, GPIO_Pin_0);
	    break;
	case 17:
	    GPIO_ResetBits(GPIOB, GPIO_Pin_1);
	    break;
	case 18:
	    GPIO_ResetBits(GPIOB, GPIO_Pin_2);
	    break;
	case 19:
	    GPIO_ResetBits(GPIOB, GPIO_Pin_3);
	    break;
	case 20:
	    GPIO_ResetBits(GPIOB, GPIO_Pin_4);
	    break;
	case 21:
	    GPIO_ResetBits(GPIOB, GPIO_Pin_5);
	    break;
	case 22:
	    GPIO_ResetBits(GPIOB, GPIO_Pin_6);
	    break;
	case 23:
	    GPIO_ResetBits(GPIOB, GPIO_Pin_7);
	    break;
	case 24:
	    GPIO_ResetBits(GPIOB, GPIO_Pin_8);
	    break;
	case 25:
	    GPIO_ResetBits(GPIOB, GPIO_Pin_9);
	    break;
	case 26:
	    GPIO_ResetBits(GPIOB, GPIO_Pin_10);
	    break;
	case 27:
	    GPIO_ResetBits(GPIOB, GPIO_Pin_11);
	    break;
	case 28:
	    GPIO_ResetBits(GPIOB, GPIO_Pin_12);
	    break;
	case 29:
	    GPIO_ResetBits(GPIOB, GPIO_Pin_13);
	    break;
	case 30:
	    GPIO_ResetBits(GPIOB, GPIO_Pin_14);
	    break;
	case 31:
	    GPIO_ResetBits(GPIOB, GPIO_Pin_15);
	    break;
	case 32:
	    GPIO_ResetBits(GPIOC, GPIO_Pin_13);
	    break;
	default:
	    return -1;
	    
	}
    }
    return 0;
}

int8_t digitalRead(uint8_t pinName){
    int8_t ret_value = -1;
    switch(pinName){
    case 0:
	ret_value = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0);
	break;
    case 1:
	ret_value = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1);
	break;
    case 2:
	ret_value = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2);
	break;
    case 3:
	ret_value = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_3);
	break;
    case 4:
	ret_value = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_4);
	break;
    case 5:
	ret_value = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_5);
	break;
    case 6:
	ret_value = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_6);
	break;
    case 7:
	ret_value = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_7);
	break;
    case 8:
	ret_value = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8);
	break;
    case 9:
	ret_value = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_9);
	break;
    case 10:
	ret_value = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_10);
	break;
    case 11:
	ret_value = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_11);
	break;
    case 12:
	ret_value = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_12);
	break;
    case 13:
	ret_value = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_13);
	break;
    case 14:
	ret_value = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_14);
	break;
    case 15:
	ret_value = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_15);
	break;
    case 16:
	ret_value = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0);
	break;
    case 17:
	ret_value = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1);
	break;
    case 18:
	ret_value = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_2);
	break;
    case 19:
	ret_value = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_3);
	break;
    case 20:
	ret_value = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4);
	break;
    case 21:
	ret_value = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5);
	break;
    case 22:
	ret_value = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6);
	break;
    case 23:
	ret_value = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7);
	break;
    case 24:
	ret_value = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8);
	break;
    case 25:
	ret_value = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_9);
	break;
    case 26:
	ret_value = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10);
	break;
    case 27:
	ret_value = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11);
	break;
    case 28:
	ret_value = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12);
	break;
    case 29:
	ret_value = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13);
	break;
    case 30:
	ret_value = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14);
	break;
    case 31:
	ret_value = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15);
	break;
    case 32:
	ret_value = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13);
    }
    return ret_value;
}
