/*
 * FSM
 *
 *  Created on: Oct 23, 2022
 *      Author: bixua
 */

#ifndef FSM_H_
#define FSM_H_
#include <msp430.h>

/* Type of State
* @ValidateInactive: reset the servo motors
* @ValidateActive: send PMWs to servo motors
*/
typedef enum {
    ValidateActive, ValidateInactive
} FSMState;

/* Type of String Status
* @Positive: send clock-wise PMW
* @Negative: send counter clock PMW
*/

//typedef struct {
//    bool data[6];
//} StringStatus;

typedef struct {
    FSMState CurrentState;                   // Current state of the FSM
    char * BtPort;                      // Input port associated with switch
    unsigned char BtBit;                      // Input port associated with switch
    unsigned char * next_data;       // String Status for pluck
    unsigned char * cur_data;
    unsigned char * servo_statue;
} StringDefine;

void InitializeString(StringDefine *String,char *BtPort,unsigned char BtBit,
                       char data[]);

//StringStatus ReadStringStatus(StringStatus *string); // read whether the string is positive or negative

unsigned char* readBtInput(char * BtPort, unsigned char BtBit);


FSMState NextStateFunction(StringDefine *String,unsigned char * input);
void OutputFunction(StringDefine *String,unsigned char * input);  //send out PWM signals


#endif /* FSM_H_ */

