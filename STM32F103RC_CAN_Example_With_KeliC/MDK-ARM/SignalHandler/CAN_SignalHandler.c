#include "CAN_SignalHandler.h"

uint8_t msg_read[40] = {0};
const uint32_t msg_id[]={(uint32_t)0X3B2,(uint32_t)0X3B0,(uint32_t)0X3BC,(uint32_t)0X3C4,(uint32_t)0X3B3};
/*Body Information 5 MS - ID 0X3B2 */
const  Signal_Descriptor signal_array[]={
		/*Body Information 5 MS - ID 0X3B2 */
		{.sigIdx=1,	.size=1,.startbit=8,.msg_idx=0},
		{.sigIdx=2,	.size=1,.startbit=18,.msg_idx=0},
		{.sigIdx=3,	.size=1,.startbit=19,.msg_idx=0},
		{.sigIdx=4,	.size=1,.startbit=20,.msg_idx=0},
		{.sigIdx=5,	.size=8,.startbit=24,.msg_idx=0},
		{.sigIdx=6,	.size=1,.startbit=34,.msg_idx=0},
		{.sigIdx=7,	.size=3,.startbit=35,.msg_idx=0},
		{.sigIdx=8,	.size=1,.startbit=38,.msg_idx=0},
		{.sigIdx=9,	.size=1,.startbit=39,.msg_idx=0},
		{.sigIdx=10,.size=1,.startbit=40,.msg_idx=0},
		{.sigIdx=11,.size=5,.startbit=43,.msg_idx=0},
		{.sigIdx=12,.size=8,.startbit=48,.msg_idx=0},
		{.sigIdx=12,.size=1,.startbit=62,.msg_idx=0},
		{.sigIdx=14,.size=1,.startbit=63,.msg_idx=0},
		/*Body Information 6 MS - ID 0X3B0 */
		{.sigIdx=15,.size=4,.startbit=0,.msg_idx=1},
		{.sigIdx=16,.size=1,.startbit=4,.msg_idx=1},
		{.sigIdx=17,.size=1,.startbit=5,.msg_idx=1},
		{.sigIdx=18,.size=2,.startbit=6,.msg_idx=1},
		/*Body Information 7 MS - ID 0X3BC */
		{.sigIdx=19,.size=4,.startbit=4,.msg_idx=2},
		{.sigIdx=20,.size=1,.startbit=17,.msg_idx=2},
		{.sigIdx=21,.size=1,.startbit=20,.msg_idx=2},
		{.sigIdx=22,.size=1,.startbit=21,.msg_idx=2},
		{.sigIdx=23,.size=10,.startbit=22,.msg_idx=2},
		{.sigIdx=24,.size=16,.startbit=32,.msg_idx=2},
		{.sigIdx=25,.size=16,.startbit=48,.msg_idx=2},
		/*Body Information 2 MS - ID 0X3C4 */
		{.sigIdx=26,.size=1,.startbit=0, .msg_idx=3},
		{.sigIdx=27,.size=1,.startbit=1, .msg_idx=3},
		{.sigIdx=28,.size=1,.startbit=2, .msg_idx=3},
		{.sigIdx=29,.size=1,.startbit=3, .msg_idx=3},
		{.sigIdx=30,.size=1,.startbit=4, .msg_idx=3},
		{.sigIdx=31,.size=1,.startbit=5, .msg_idx=3},
		{.sigIdx=32,.size=1,.startbit=6, .msg_idx=3},
		{.sigIdx=33,.size=1,.startbit=7, .msg_idx=3},
		{.sigIdx=34,.size=1,.startbit=10,.msg_idx=3},
		{.sigIdx=35,.size=1,.startbit=11,.msg_idx=3},
		{.sigIdx=36,.size=1,.startbit=12,.msg_idx=3},
		{.sigIdx=37,.size=1,.startbit=13,.msg_idx=3},
		{.sigIdx=38,.size=1,.startbit=14,.msg_idx=3},
		{.sigIdx=39,.size=1,.startbit=1, .msg_idx=3},
		{.sigIdx=40,.size=8,.startbit=16,.msg_idx=3},
		{.sigIdx=41,.size=1,.startbit=24,.msg_idx=3},
		{.sigIdx=42,.size=2,.startbit=25,.msg_idx=3},
		{.sigIdx=43,.size=2,.startbit=27,.msg_idx=3},
		{.sigIdx=44,.size=1,.startbit=31,.msg_idx=3},
		{.sigIdx=45,.size=8,.startbit=32,.msg_idx=3},
		{.sigIdx=46,.size=1,.startbit=40,.msg_idx=3},
		{.sigIdx=47,.size=1,.startbit=41,.msg_idx=3},
		{.sigIdx=48,.size=1,.startbit=42,.msg_idx=3},
		{.sigIdx=49,.size=2,.startbit=46,.msg_idx=3},
		{.sigIdx=50,.size=1,.startbit=56,.msg_idx=3},
		{.sigIdx=51,.size=1,.startbit=57,.msg_idx=3},
		{.sigIdx=52,.size=1,.startbit=58,.msg_idx=3},
		{.sigIdx=53,.size=1,.startbit=59,.msg_idx=3},
		{.sigIdx=54,.size=2,.startbit=60,.msg_idx=3},
		{.sigIdx=55,.size=10,.startbit=62,.msg_idx=3},
		/*Body Information 3 MS - ID 0X3B3 */
		{.sigIdx=56,.size=1,.startbit=0,  .msg_idx=4},
		{.sigIdx=57,.size=1,.startbit=1,  .msg_idx=4},
		{.sigIdx=58,.size=2,.startbit=2,  .msg_idx=4},
		{.sigIdx=59,.size=2,.startbit=4,  .msg_idx=4},
		{.sigIdx=60,.size=2,.startbit=6,  .msg_idx=4},
		{.sigIdx=61,.size=1,.startbit=8,  .msg_idx=4},
		{.sigIdx=62,.size=1,.startbit=9,  .msg_idx=4},
		{.sigIdx=63,.size=2,.startbit=10, .msg_idx=4},
		{.sigIdx=64,.size=2,.startbit=12, .msg_idx=4},
		{.sigIdx=65,.size=2,.startbit=14, .msg_idx=4},
		{.sigIdx=66,.size=8,.startbit=16, .msg_idx=4},
		{.sigIdx=67,.size=8,.startbit=24, .msg_idx=4},
		{.sigIdx=68,.size=1,.startbit=40,. msg_idx=4},
		{.sigIdx=69,.size=15,.startbit=41,.msg_idx=4},
		{.sigIdx=70,.size=1,.startbit=48, .msg_idx=4},
		{.sigIdx=71,.size=1,.startbit=49, .msg_idx=4},
		{.sigIdx=73,.size=2,.startbit=54, .msg_idx=4},
		{.sigIdx=74,.size=1,.startbit=58, .msg_idx=4},
		{.sigIdx=75,.size=5,.startbit=59, .msg_idx=4}
};

int8_t MessageIdx(uint32_t rx_Id){
	
	for(int i =0;i<5;i++){
		if(rx_Id == msg_id[i]) return i;
	}
	return -1;
	
}
void ReadCanSignal8(uint8_t signalIdx, uint16_t *Val){
	uint16_t i, start_bit,msgid, size,extractedMessage;
	
	if(signalIdx>75||signalIdx<1){
		return;
	}else{
		i = signalIdx - 1;
		start_bit 	= signal_array[i].startbit;
		msgid 			= signal_array[i].msg_idx;
		size 				= signal_array[i].size;
	}
	/*Index of msg in array*/
	uint8_t arrIdx = 8*msgid + start_bit/8;
	/*Bit position*/
	uint8_t bitPosition = start_bit%8;
	for (uint8_t i = 0; i < size; ++i) {
			extractedMessage |= (msg_read[arrIdx] >> bitPosition) << i;
			bitPosition++;
			if (bitPosition >= 8) {
				bitPosition = 0;
				arrIdx--;// Decrement for Motorola byte order
			}
		}
	extractedMessage &= ((1<<size)-1);
	*Val = extractedMessage;
}

void StoreSignal(int8_t idx, uint8_t data[]){
	if(idx!=-1){
		for (int i = 0; i < 8; i++) {
			msg_read[8*idx+i]=data[i];
		}
	}
}
uint32_t getSignal_MessageId(uint8_t signalArr_idx)
{
	return msg_id[signal_array[signalArr_idx].msg_idx];
}
void getSignalMessageData(uint8_t signalArr_idx, uint8_t* data, uint16_t signal_read)
{
	uint8_t startByte;
	uint8_t startbit = signal_array[signalArr_idx].startbit;
	uint8_t size = signal_array[signalArr_idx].size;
	uint16_t signal_after = signal_read+1;
	startByte = 8*signal_array[signalArr_idx].msg_idx;
	for(int i = 0; i < 8; i++)
	{
		data[i]=msg_read[startByte];
		startByte++;
	}
	uint8_t bytePosition = startbit / 8;
	uint8_t bitPosition = startbit%8;
	
	uint16_t signal_shifted = signal_after << bitPosition;
	
	uint16_t mask = ((1 << size) - 1) << bitPosition;
	
	uint16_t surround_mask = ((1 << 16) - 1) & ~mask;
	
	uint16_t signal_from_arr = (uint16_t) ((data[bytePosition-1]<<8)|data[bytePosition]);
	
	uint16_t final = (signal_from_arr & surround_mask)|signal_shifted;
	
	uint8_t signal_h = (uint8_t)(final&0x00ff);
	
	uint8_t signal_l = (uint8_t)((final&0xff00)>>8);
	
	data[bytePosition] = signal_l;
	
	data[bytePosition-1] = signal_h;
}
