/*  BEGIN_FILE_HDR
************************************************************************************************
************************************************************************************************
*   File Name       : GPIO_Cfg.h
************************************************************************************************
*   Project/Product : All
*   Title           : GPIO module configuration Head File
*   Author          : hf
************************************************************************************************
*   Description     : Contain the pre-compile-time configuration parameters. 
*
************************************************************************************************
*   Limitations     : Only used in the MC9S12G Family chip
*
************************************************************************************************
*
************************************************************************************************
*   Revision History:
* 
*   Version     Date          Initials      CR#                    Descriptions
*   ---------   ----------    ------------  ----------             ---------------
*   1.0         20190315       hf            N/A                    Original
*
************************************************************************************************
* END_FILE_HDR*/


#ifndef GPIO_CFG_H
#define GPIO_CFG_H

#include "Common.h"

#define GPIO_PIN_NUM          GPIO_PIN_NUM_100

#define PORTJ_PROCESSING      INTERRUPT
/*#define PORTJ_PROCESSING      POLLING*/

#define PORTP_PROCESSING      INTERRUPT
//#define PORTP_PROCESSING      POLLING


/*#define PORTAD_PROCESSING     INTERRUPT*/
#define PORTAD_PROCESSING     POLLING

#endif