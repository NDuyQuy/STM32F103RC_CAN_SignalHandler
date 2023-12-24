/*
 * CAN_SignalHandler.h
 *
 *  Created on: 17 Dec 2023
 *      Author: NguyenDuyQuy
 */

#ifndef SRC_CAN_SIGNALHANDLER_H_
#define SRC_CAN_SIGNALHANDLER_H_
#include "main.h"
typedef struct{
	uint8_t sigIdx;
	uint8_t size;
	uint8_t startbit;
	uint8_t msg_idx;
} Signal_Descriptor;

void ReadCanSignal8(uint8_t signalIdx, uint16_t *Val);

void StoreSignal(int8_t idx, uint8_t data[]);

int8_t MessageIdx(uint32_t rx_Id);

uint32_t getSignal_MessageId(uint8_t signalArr_idx);

void getSignalMessageData(uint8_t signalArr_idx, uint8_t data[], uint16_t signal_read);

#endif /* SRC_CAN_SIGNALHANDLER_H_ */
