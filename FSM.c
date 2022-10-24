/*
 * string
 *
 *  Created on: Oct 23, 2022
 *      Author: bixua
 */

#include "FSM.h"
//#define FALSE 0
//#define TRUE 1
//
//extern unsigned int g1msTimer;
//
void InitializeString(StringDefine *String,char *BtPort,unsigned char BtBit,
                      char data[])
{
    String->CurrentState = ValidateInactive;
    String->BtPort = BtPort;
    String->BtBit = BtBit;
    String->cur_data = "777777";
    String->next_data = "777777";
}

unsigned char* readBtInput(char * BtPort, unsigned char BtBit){
    unsigned char * input;

    return input;
}
FSMState NextStateFunction(StringDefine *String,unsigned char * input){
    FSMState NextState;
    if (String->CurrentState ==  ValidateInactive){
        NextState = ValidateActive;
    }else if(String->CurrentState ==  ValidateActive){
        NextState = ValidateInactive;
    }
    return NextState;
}

void OutputFunction(StringDefine *String,unsigned char * input){
    switch (String->CurrentState){
        case ValidateInactive: // send PMW -> lift all servo motor
            // SendPMW
            String->cur_data = String->next_data;
            String->next_data = readBtInput(String->BtPort, String->BtBit);
            break;
        case ValidateActive:
            // SendPMW
            break;
    }

}
