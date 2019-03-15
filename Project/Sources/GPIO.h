/*  BEGIN_FILE_HDR
************************************************************************************************
*   NOTICE                              
*   This software is the property of YKXH Technologies. Any information contained in this 
*   doc should not be reproduced, or used, or disclosed without the written authorization from 
*   YKXH Technologies.
************************************************************************************************
*   File Name       : GPIO.h
************************************************************************************************
*   Project/Product : All
*   Title           : GPIO module Head File
*   Author          : YangHe
************************************************************************************************
*   Description     : Parallel Input/Output Control module Head File
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
*   1.0         2011/07/04    YangHe        N/A          Original
*
************************************************************************************************
* END_FILE_HDR*/

#ifndef GPIO_H
#define GPIO_H

#define GPIO_C


#ifdef  GPIO_C
#define GPIO_EXT
#else
#define GPIO_EXT extern
#endif

#include "GPIO_Cfg.h"
#include "mc9s12g128.h"




#define GPIO_Read_8U(PortAddr,Offset)        ((*(PortAddr) >> (Offset)) & 0x01)      /*read I/O*/
#define GPIO_Inv_8U(PortAddr,Offset)         (*(PortAddr) ^= SET_BIT_8U(Offset))     /*Invert I/O*/
#define GPIO_Clr_8U(PortAddr,Offset)         (*(PortAddr) &= CLR_BIT_8U(Offset))     /*I/O clear 0*/
#define GPIO_Set_8U(PortAddr,Offset)         (*(PortAddr) |= SET_BIT_8U(Offset))     /*I/O set 1*/

#define GPIO_Write_8U(PortAddr,Offset,Val)\
{\
    if((Val) == 0)\
    {\
        GPIO_Clr_8U((PortAddr),(Offset));\
    }\
    else\
    {\
        GPIO_Set_8U((PortAddr),(Offset));\
    }\
}

/* fgao add*/
#define GPIO_Read_16U(PortAddr,Offset)       ((*(PortAddr) >> (Offset)) & 0x0001)    /*read I/O*/
#define GPIO_Inv_16U(PortAddr,Offset)        (*(PortAddr) ^= SET_BIT_16U(Offset))    /*Invert I/O*/
#define GPIO_Clr_16U(PortAddr,Offset)        (*(PortAddr) &= CLR_BIT_16U(Offset))    /*I/O clear 0*/
#define GPIO_Set_16U(PortAddr,Offset)        (*(PortAddr) |= SET_BIT_16U(Offset))    /*I/O set 1*/


#define SET_PIN_OPEN_DRAIN         (0x01U)
#define SET_PIN_PUSH_PULL          (0x00U)











 /*Explicit Type Casting*/
 
#define GPIO_REG_ETC               (volatile UINT8 *)
#define GPIO_BYTE(addr)            (*((volatile UINT8*)(addr))) 
#define GPIO_WORD(addr)            (*((volatile UINT16*)(addr)))

#define GPIO_PIN_NUM_100           100
#define GPIO_PIN_NUM_64            64
#define GPIO_PIN_NUM_48            48


#if (GPIO_PIN_NUM_100 == GPIO_PIN_NUM)
  #define GPIO_PORT_A                0
  #define GPIO_PORT_B                1
  #define GPIO_PORT_C                2
  #define GPIO_PORT_D                3
  #define GPIO_PORT_E                4u
  #define GPIO_PORT_T                5                        
  #define GPIO_PORT_S                6u
  #define GPIO_PORT_M                7u
  #define GPIO_PORT_P                8u
  #define GPIO_PORT_J                9u
  #define  GPIO_PORT_AD0              10u
  #define GPIO_PORT_AD1              11u  
#elif(GPIO_PIN_NUM_64 == GPIO_PIN_NUM)
  #define GPIO_PORT_E                0u
  #define GPIO_PORT_T                1u
  #define GPIO_PORT_S                2u
  #define GPIO_PORT_M                3u
  #define GPIO_PORT_P                4u
  #define GPIO_PORT_J                5u
  #define GPIO_PORT_AD0              6u
  #define GPIO_PORT_AD1              7u 
#elif(GPIO_PIN_NUM_48 == GPIO_PIN_NUM)
  #define GPIO_PORT_E                0u
  #define GPIO_PORT_T                1u
  #define GPIO_PORT_S                2u
  #define GPIO_PORT_M                3u
  #define GPIO_PORT_P                4u
  #define GPIO_PORT_J                5u
  #define GPIO_PORT_AD0              6u
  #define GPIO_PORT_AD1              7u
#else
  #error "error number of GPIO pins"
#endif

#if (GPIO_PIN_NUM_100 == GPIO_PIN_NUM)
  #define GPIO_PORT_NUM             12u
#elif(GPIO_PIN_NUM_64 == GPIO_PIN_NUM)
  #define GPIO_PORT_NUM             8u
#elif(GPIO_PIN_NUM_48 == GPIO_PIN_NUM)
  #define GPIO_PORT_NUM             8u
#else
  #error "error number of GPIO pins"
#endif




/* Pull-up or Pull-down selection */
#define GPIO_PULL_DIS              0u
#define GPIO_PULL_MODE_UP          1u
#define GPIO_PULL_MODE_DOWN        2u

/* Interrupt detection mode selection */
#define GPIO_INT_DIS               0u
#define GPIO_INT_MODE_FALLING      1u
#define GPIO_INT_MODE_RAISING      2u



#if (GPIO_PIN_NUM_48 == GPIO_PIN_NUM)
  #define GPIO_PORT_J_MASK           (UINT8)0x0fu
#else  
  #define GPIO_PORT_J_MASK           (UINT8)0xffu
#endif

#if (GPIO_PIN_NUM_48 == GPIO_PIN_NUM)
  #define GPIO_PORT_P_MASK           (UINT8)0x3fu
#else
  #define GPIO_PORT_P_MASK           (UINT8)0xffu
#endif

#if (GPIO_PIN_NUM_48 == GPIO_PIN_NUM)
  #define GPIO_PORT_AD0_MASK         (UINT8)0x0fu
#else
  #define GPIO_PORT_AD0_MASK         (UINT8)0xffu
#endif
  
#define GPIO_PORT_AD1_MASK           (UINT8)0xffu



GPIO_EXT void     GPIO_PinDirOut(UINT8 portNum, UINT8 pinNum);
GPIO_EXT void     GPIO_PinDirIn(UINT8 portNum, UINT8 pinNum);
GPIO_EXT void     GPIO_PinWrite(UINT8 portNum, UINT8 pinNum, UINT8 pinVal); 
GPIO_EXT UINT8    GPIO_PinDataRead(UINT8 portNum, UINT8 pinNum); 
GPIO_EXT UINT8    GPIO_PinInputRead(UINT8 portNum, UINT8 pinNum);

GPIO_EXT void     GPIO_PortDirSet(UINT8 portNum, UINT8 dirVal);
GPIO_EXT void     GPIO_PortWrite(UINT8 portNum, UINT8 dataVal);
GPIO_EXT UINT8  GPIO_PortDataRead(UINT8 portNum); 
GPIO_EXT UINT8  GPIO_PortInputRead(UINT8 portNum);


GPIO_EXT void     GPIO_PinPullDrvSet(UINT8 portNum, UINT8 pinNum, UINT8 pullMode);

GPIO_EXT void     GPIO_PinWiredORModeSet(UINT8 portNum,UINT8 pinNum,UINT8 womVal);

GPIO_EXT void     GPIO_PinIntSet(UINT8 portNum, UINT8 pinNum, UINT8 intMode) ;


#if (POLLING == PORTP_PROCESSING) 
  GPIO_EXT  void PORTP_MainFunction(void);
#endif



#if (POLLING == PORTJ_PROCESSING) 
  GPIO_EXT  void PORTJ_MainFunction(void);
#endif


#if (POLLING == PORTAD_PROCESSING) 
  GPIO_EXT void PORTAD_MainFunction(void);
#endif




#endif