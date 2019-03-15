/*  BEGIN_FILE_HDR
************************************************************************************************
*
************************************************************************************************
*   File Name       : GPIO.c
************************************************************************************************
*   Project/Product : All
*   Title           : GPIO module Source File
*   Author          : hf
************************************************************************************************
*   Description     : Parallel Input/Output Control module Source File
*
************************************************************************************************
*   Limitations     : 
*
************************************************************************************************
*
************************************************************************************************
*   Revision History:
* 
*   Version     Date          Initials      CR#          Descriptions
*   ---------   ----------    ------------  ----------   ---------------
*   1.0         20190315    HF        N/A          Original
*   
*
************************************************************************************************
* END_FILE_HDR*/
#ifndef GPIO_C
#define GPIO_C
#endif


#include "GPIO.h"
#include "COMMON.h"


/*const variable declaration*/

//Data  Register
 static const uchar *cGPIO_RegData[GPIO_PORT_NUM] =       
{
    #if (GPIO_PIN_NUM_100 == GPIO_PIN_NUM)
     &PORTA,&PORTB,&PORTC,&PORTD,
    #endif
    &PORTE, &PTT, &PTS, &PTM,
    &PTP, &PTJ, &PT0AD, &PT1AD 
};


//Data Directioin Register
static const UINT8 *cGPIO_RegDataDir[GPIO_PORT_NUM] =        
{
    #if (GPIO_PIN_NUM_100 == GPIO_PIN_NUM)
      &DDRA,&DDRB,&DDRC,&DDRD,
    #endif
    &DDRE, &DDRT, &DDRS, &DDRM,
    &DDRP, &DDRJ, &DDR0AD, &DDR1AD
};
//Input Register                      
static const UINT8 *cGPIO_RegInput[7] =
{
    &PTIT,&PTIS,&PTIM,
    &PTIP,&PTIJ,&PTI0AD,&PTI1AD
};
 // Pull Device Enable Register
 static const UINT8 *cGPIO_RegPullDrvEn[8] =     
{
    
    &PUCR, &PERT, &PERS, &PERM,
    &PERP, &PERJ, &PER0AD, &PER1AD 
};


 //Polarity Select Register (PPST)
static const UINT8 *cGPIO_RegPolarSelect[7] =
{
    &PPST,&PPSS,&PPSM,
    &PPSP,&PPSJ,&PPS0AD,&PPS1AD

};
//Wired -OR Mode Register
static const UINT8 *cGPIO_RegWiredORMode[2] =
{
    &WOMS,&WOMM
};
//Interrupt Enable Register
static const UINT8 *cGPIO_RegIntEn[4] =
{
    &PIEP,&PIEJ,&PIE0AD,&PIE1AD
};
//Interrupt Flag Register
static const UINT8 *cGPIO_RegIntFlag[4] =
{
    &PIFP,&PIFJ,&PIF0AD,&PIF1AD
};

 /********* function declaration ********************************************/


 static void GPIO_PinPullDrvEn(UINT8 portNum,UINT8 pinNum);
 static void GPIO_PinPullDrvDis(UINT8 portNum,UINT8 pinNum);
 static void GPIO_PinPullUp(UINT8 portNum, UINT8 pinNum);
static void GPIO_PinPullDown(UINT8 portNum, UINT8 pinNum);
static UINT8 GPIO_BitCheck(UINT8 chkByte);
 

 /* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : GPIO_PinDirOut
*
* Description   : Set pin as output pin. 
*
* Inputs        : UINT8 portNum      :Port number 
*                 UINT8 pinNum       :Pin number  
*
* Outputs       : None
* 
* Limitations   : 1.Only used in the MC9S12G Family chip
*                 2.Only for GPIO_PORT_E,GPIO_PORT_T,GPIO_PORT_S,GPIO_PORT_M,
*                   GPIO_PORT_P,GPIO_PORT_J,GPIO_PORT_AD0, GPIO_PORT_AD1
*                 
************************************************************************************************
END_FUNCTION_HDR */
void GPIO_PinDirOut(UINT8 portNum,UINT8 pinNum)
{
    GPIO_Set_8U(GPIO_REG_ETC(cGPIO_RegDataDir[portNum]),pinNum);
}


/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : GPIO_PinDirIn
*
* Description   : Set pin as input pin. 
*
* Inputs        : UINT8 portNum      :Port number 
*                 UINT8 pinNum       :Pin number
*
* Outputs       : None
* 
* Limitations   : 1.Only used in the MC9S12G Family chip
*                 2.Only for GPIO_PORT_E,GPIO_PORT_T,GPIO_PORT_S,GPIO_PORT_M,
*                   GPIO_PORT_P,GPIO_PORT_J,GPIO_PORT_AD0, GPIO_PORT_AD1
*                 
************************************************************************************************
END_FUNCTION_HDR */
void GPIO_PinDirIn(UINT8 portNum, UINT8 pinNum)
{
   GPIO_Clr_8U(GPIO_REG_ETC(cGPIO_RegDataDir[portNum]), pinNum);
    
}
/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : GPIO_PinWrite
*
* Description   : Write pin to designed logic level. 
*
* Inputs        : UINT8 portNum      :Port number 
*                 UINT8 pinNum       :Pin number
*                 UINT8 PinLevel     :Pin logic level 
*                                       value can be :SET_PIN_HIGH(0x01U) SET_PIN_LOW (0x00U)
*
* Outputs       : None
* 
* Limitations   : 1.Only used in the MC9S12G Family chip
*                 2.Only for GPIO_PORT_E,GPIO_PORT_T,GPIO_PORT_S,GPIO_PORT_M,
*                   GPIO_PORT_P,GPIO_PORT_J,GPIO_PORT_AD0, GPIO_PORT_AD1
*                 
************************************************************************************************
END_FUNCTION_HDR */
void GPIO_PinWrite(UINT8 portNum, UINT8 pinNum, UINT8 pinVal) 
{ 
   GPIO_Write_8U((GPIO_REG_ETC(cGPIO_RegData[portNum])), pinNum, pinVal);
}
/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : GPIO_PinDataRead
*
* Description   : Reading logic level of associated pin from data register. 
*
* Inputs        : UINT8 portNum      :Port number 
*                 UINT8 pinNum       :Pin number
*
* Outputs       : Logic level of the pin in data register.
* 
* Limitations   : 1.Only used in the MC9S12G Family chip
*                 2.Only for GPIO_PORT_E,GPIO_PORT_T,GPIO_PORT_S,GPIO_PORT_M,
*                   GPIO_PORT_P,GPIO_PORT_J,GPIO_PORT_AD0, GPIO_PORT_AD1
*                 
************************************************************************************************
END_FUNCTION_HDR */   
                                                                    
UINT8 GPIO_PinDataRead(UINT8 portNum, UINT8 pinNum) 
{
   return GPIO_Read_8U(GPIO_REG_ETC(cGPIO_RegData[portNum]), pinNum);
}  
/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : GPIO_PinInputRead
*
* Description   : Reading logic level of associated pin from input register. 
*
* Inputs        : UINT8 portNum      :Port number 
*                 UINT8 pinNum       :Pin number
*
* Outputs       : Logic level of associated pin in input register
* 
* Limitations   : 1.Only used in the MC9S12G Family chip
*                 2.Only for GPIO_PORT_T,GPIO_PORT_S,GPIO_PORT_M,
*                   GPIO_PORT_P,GPIO_PORT_J,GPIO_PORT_AD0, GPIO_PORT_AD1
*                 
************************************************************************************************
END_FUNCTION_HDR */
UINT8 GPIO_PinInputRead(UINT8 portNum, UINT8 pinNum)
{
    UINT8 ret;
    if(portNum>=GPIO_PORT_T)
    {
       ret = GPIO_Read_8U(GPIO_REG_ETC(cGPIO_RegInput[portNum-GPIO_PORT_T]), pinNum);
    }
    
    return ret;
}
/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : GPIO_PortDirSet
*
* Description   : Configuring the pins in associated port as input or output. 
*
* Inputs        : UINT8 portNum      :Port number 
*                 UINT8 dirVal       :Direction register value
*
* Outputs       : None
* 
* Limitations   : 1.Only used in the MC9S12G Family chip
*                 2.Only for GPIO_PORT_E,GPIO_PORT_T,GPIO_PORT_S,GPIO_PORT_M,
*                   GPIO_PORT_P,GPIO_PORT_J,GPIO_PORT_AD0, GPIO_PORT_AD1
*                 
************************************************************************************************
END_FUNCTION_HDR */
void GPIO_PortDirSet(UINT8 portNum, UINT8 dirVal)
{
    GPIO_BYTE(cGPIO_RegDataDir[portNum]) = dirVal;
}

/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : GPIO_PortWrite
*
* Description   : Write pins of the port to designed logic level. 
*
* Inputs        : UINT8 portNum      :Port number 
*                 UINT8 dataVal      :Data register value
*
* Outputs       : None
* 
* Limitations   : 1.Only used in the MC9S12G Family chip
*                 2.Only for GPIO_PORT_E,GPIO_PORT_T,GPIO_PORT_S,GPIO_PORT_M,
*                   GPIO_PORT_P,GPIO_PORT_J,GPIO_PORT_AD0, GPIO_PORT_AD1
*                 
************************************************************************************************
END_FUNCTION_HDR */
void GPIO_PortWrite(UINT8 portNum, UINT8 dataVal) 
{
   GPIO_BYTE(cGPIO_RegData[portNum]) = dataVal;
}
/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : GPIO_PortDataRead
*
* Description   : Reading logic level of associated port from data register.
*
* Inputs        : UINT8 portNum      :Port number 
*
* Outputs       : Logic level of the port. 
* 
* Limitations   : 1.Only used in the MC9S12G Family chip
*                 2.Only for GPIO_PORT_E,GPIO_PORT_T,GPIO_PORT_S,GPIO_PORT_M,
*                   GPIO_PORT_P,GPIO_PORT_J,GPIO_PORT_AD0, GPIO_PORT_AD1
*                 
************************************************************************************************
END_FUNCTION_HDR */
UINT8 GPIO_PortDataRead(UINT8 portNum) 
{
    return GPIO_BYTE(cGPIO_RegData[portNum]);
}
/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : GPIO_PortInputRead
*
* Description   : Reading logic level of associated port from input register. 
*
* Inputs        : UINT8 portNum      :Port number 
*
* Outputs       : Logic level of associated port in input register
* 
* Limitations   : 1.Only used in the MC9S12G Family chip
*                 2.Only for GPIO_PORT_T,GPIO_PORT_S,GPIO_PORT_M,
*                   GPIO_PORT_P,GPIO_PORT_J,GPIO_PORT_AD0,GPIO_PORT_AD1
*                 
************************************************************************************************
END_FUNCTION_HDR */
UINT8 GPIO_PortInputRead(UINT8 portNum)
{
    UINT8 ret;
    if(portNum>=GPIO_PORT_T)
    {
       ret = GPIO_BYTE(cGPIO_RegInput[portNum-GPIO_PORT_T]);
    }
    return ret;
}


/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : GPIO_PinPullDrvEn
*
* Description   : Enable pull dirve.
*
* Inputs        : UINT8 portNum      :Port number 
*                 UINT8 pinNum       :Pin number
*
* Outputs       : None
* 
* Limitations   : 1.Only used in the MC9S12G Family chip
*                 2.PORT_E,only support port pull down enable,
*                   PORT_E,not support separate pin pull down enable
*                   PORT_E,not support port or separate pin pull up enable
*                 3.Port setting support:GPIO_PORT_T,GPIO_PORT_S,GPIO_PORT_M,
*                   GPIO_PORT_P,GPIO_PORT_J,GPIO_PORT_AD0,GPIO_PORT_AD1
*                 
************************************************************************************************
END_FUNCTION_HDR */
static void GPIO_PinPullDrvEn(UINT8 portNum, UINT8 pinNum)
{
    #if (GPIO_PIN_NUM_100 == GPIO_PIN_NUM)
      if(portNum<GPIO_PORT_T)
      {
        GPIO_Set_8U(GPIO_REG_ETC(cGPIO_RegPullDrvEn[0]), portNum); 
      }
    #else
      if(portNum<GPIO_PORT_T)
      {
         if(portNum == GPIO_PORT_E)
         {
            GPIO_Set_8U(GPIO_REG_ETC(cGPIO_RegPullDrvEn[0]), 4);  
         }
      }
    #endif
      else
      {
          GPIO_Set_8U(GPIO_REG_ETC(cGPIO_RegPullDrvEn[portNum+1- GPIO_PORT_T]), pinNum); 
      }

}


/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : GPIO_PinPullDrvDis
*
* Description   : Disable pull dirve.
*
* Inputs        : UINT8 portNum      :Port number 
*                 UINT8 pinNum       :Pin number
*
* Outputs       : None
* 
* Limitations   : 1.Only used in the MC9S12G Family chip
*                 2.PORT_E,only support port pull down enable,
*                   PORT_E,not support separate pin pull down enable
*                   PORT_E,not support port or separate pin pull up enable
*                 3.Pin setting support:GPIO_PORT_T,GPIO_PORT_S,GPIO_PORT_M,
*                   GPIO_PORT_P,GPIO_PORT_J,GPIO_PORT_AD0,GPIO_PORT_AD1
*                  
************************************************************************************************
END_FUNCTION_HDR */
static void GPIO_PinPullDrvDis(UINT8 portNum, UINT8 pinNum)
{
    #if (GPIO_PIN_NUM_100 == GPIO_PIN_NUM)
      if(portNum<GPIO_PORT_T)
      {
        GPIO_Clr_8U(GPIO_REG_ETC(cGPIO_RegPullDrvEn[0]), portNum); 
      }
    #else
      if(portNum<GPIO_PORT_T)
      {
         if(portNum == GPIO_PORT_E)
         {
            GPIO_Clr_8U(GPIO_REG_ETC(cGPIO_RegPullDrvEn[0]), 4);  
         }
      }
    #endif
    else 
    {
        GPIO_Clr_8U(GPIO_REG_ETC(cGPIO_RegPullDrvEn[portNum+1- GPIO_PORT_T]), pinNum);
    }

}


/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : GPIO_PinPullUp
*
* Description   : Enable pull-up dirve.
*
* Inputs        : UINT8 portNum      :Port number 
*                 UINT8 pinNum       :Pin number
*
* Outputs       : None
* 
* Limitations   : 1.Only used in the MC9S12G Family chip
*                 2.PORT_E,only support port pull down enable,
*                   PORT_E,not support separate pin pull down enable
*                   PORT_E,not support port or separate pin pull up enable
*                 3.Pin setting support:GPIO_PORT_T,GPIO_PORT_S,GPIO_PORT_M,
*                   GPIO_PORT_P,GPIO_PORT_J,GPIO_PORT_AD0,GPIO_PORT_AD1
*                 
************************************************************************************************
END_FUNCTION_HDR */
static void GPIO_PinPullUp(UINT8 portNum, UINT8 pinNum)
{ 
    if(portNum>=GPIO_PORT_T)
    {
        GPIO_Clr_8U(GPIO_REG_ETC(cGPIO_RegPolarSelect[portNum - GPIO_PORT_T]), pinNum);
    }

}

/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : GPIO_PinPullDown
*
* Description   : Enable pull-down dirve.
*
* Inputs        : UINT8 portNum      :Port number 
*                 UINT8 pinNum       :Pin number
*
* Outputs       : None
* 
* Limitations   : 1.Only used in the MC9S12G Family chip
*                 2.PORT_E,only support port pull down enable,
*                   PORT_E,not support separate pin pull down enable
*                   PORT_E,not support port or separate pin pull up enable
*                 3.Pin setting support:GPIO_PORT_T,GPIO_PORT_S,GPIO_PORT_M,
*                   GPIO_PORT_P,GPIO_PORT_J,GPIO_PORT_AD0,GPIO_PORT_AD1
*                 
************************************************************************************************
END_FUNCTION_HDR */
static void GPIO_PinPullDown(UINT8 portNum, UINT8 pinNum)
{
    if((portNum >= GPIO_PORT_T)&&(portNum<=GPIO_PORT_AD1))
    {
        GPIO_Set_8U(GPIO_REG_ETC(cGPIO_RegPolarSelect[portNum - GPIO_PORT_T]), pinNum);
    }
}

/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : GPIO_PinPullDrvSet
*
* Description   : Setting pull dirve mode.
*
* Inputs        : UINT8 portNum      :Port number 
*                 UINT8 pinNum       :Pin number
*                 UINT8 pullMode     :Pull drive mode, optional choice:
*                                       GPIO_PULL_DIS
*                                       GPIO_PULL_MODE_UP
*                                       GPIO_PULL_MODE_DOWN
*
* Outputs       : None
* 
* Limitations   : 1.Only used in the MC9S12G Family chip
*                 2.PORT_E,only support port pull down enable,
*                   PORT_E,not support separate pin pull down enable
*                   PORT_E,not support port or separate pin pull up enable
*                 3.Pin setting support:GPIO_PORT_T,GPIO_PORT_S,GPIO_PORT_M,
*                   GPIO_PORT_P,GPIO_PORT_J,GPIO_PORT_AD0,GPIO_PORT_AD1
*                 
************************************************************************************************
END_FUNCTION_HDR */
void GPIO_PinPullDrvSet(UINT8 portNum, UINT8 pinNum, UINT8 pullMode)
{
    if(pullMode == GPIO_PULL_DIS)
    {
        GPIO_PinPullDrvDis(portNum, pinNum);
    }
    else if(pullMode == GPIO_PULL_MODE_UP)
    {
        GPIO_PinPullDrvEn(portNum, pinNum);
        GPIO_PinPullUp(portNum, pinNum);
    }
    else if(pullMode == GPIO_PULL_MODE_DOWN)
    {
        GPIO_PinPullDrvEn(portNum, pinNum);
        GPIO_PinPullDown(portNum, pinNum);
    }
    else
    {
        /* do nothing */
    }
}


/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : GPIO_PinWiredORModeSet
*
* Description   : Wired-OR Mode.
*
* Inputs        : UINT8 portNum      :Port number 
*                 UINT8 pinNum       :Pin number
*                 UINT8 womVal       :Wired-OR Mode register value,optional choice:
*                                       SET_PIN_PUSH_PULL(0):Output buffers operate as push-pull outputs.
*                                       SET_PIN_OPEN_DRAIN(1):Output buffers operate as open-drain outputs
*
* Outputs       : None
* 
* Limitations   : 1.Only used in the MC9S12G Family chip
*                 2.Port setting support:GPIO_PORT_S,GPIO_PORT_M
*                 
************************************************************************************************
END_FUNCTION_HDR */
void GPIO_PinWiredORModeSet(UINT8 portNum,UINT8 pinNum,UINT8 womVal)
{
    if((portNum >= GPIO_PORT_S) && (portNum <= GPIO_PORT_M))
    {
        if(SET_PIN_OPEN_DRAIN == womVal)
        {
          GPIO_Set_8U(GPIO_REG_ETC(cGPIO_RegWiredORMode[portNum - GPIO_PORT_S]), pinNum);
        }
        else if(SET_PIN_PUSH_PULL == womVal)
        {
          GPIO_Clr_8U(GPIO_REG_ETC(cGPIO_RegWiredORMode[portNum - GPIO_PORT_S]), pinNum);
        }
        else
        {
          /* do nothing */
        }
         
    }

}


  
 /* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : GPIO_PinIntSet
*
* Description   : Setting interrupt mode.
*
* Inputs        : UINT8 portNum      :Port number 
*                 UINT8 pinNum       :Pin number
*                 UINT8 intMode:     Interrupt mode, optional choice:
*                                      GPIO_INT_DIS
*                                      GPIO_INT_MODE_FALLING
*                                      GPIO_INT_MODE_RAISING
*
* Outputs       : None
* 
* Limitations   : 1.Only used in the MC9S12G Family chip
*                 2.Port setting support:GPIO_PORT_P,GPIO_PORT_J,GPIO_PORT_AD0,GPIO_PORT_AD1
*                 
************************************************************************************************
END_FUNCTION_HDR */
void GPIO_PinIntSet(UINT8 portNum, UINT8 pinNum, UINT8 intMode)
{
    if((portNum >= GPIO_PORT_P) && (portNum <= GPIO_PORT_AD1))
    {
        if(intMode == GPIO_INT_DIS)
        {
            GPIO_Clr_8U(GPIO_REG_ETC(cGPIO_RegIntEn[portNum - GPIO_PORT_P]), pinNum);
        }
        else 
        {
            switch(portNum)
            {
              case GPIO_PORT_P:
              {
                 #if (INTERRUPT == PORTP_PROCESSING)
                   GPIO_Set_8U(GPIO_REG_ETC(cGPIO_RegIntEn[portNum - GPIO_PORT_P]), pinNum); 
                 #endif
              }
              break;
              case GPIO_PORT_J:
              {
                 #if (INTERRUPT == PORTJ_PROCESSING)
                   GPIO_Set_8U(GPIO_REG_ETC(cGPIO_RegIntEn[portNum - GPIO_PORT_P]), pinNum); 
                 #endif
              }
              break;
              case GPIO_PORT_AD0:
              {
                 #if (INTERRUPT == PORTAD_PROCESSING)
                   GPIO_Set_8U(GPIO_REG_ETC(cGPIO_RegIntEn[portNum - GPIO_PORT_P]), pinNum); 
                 #endif
              }
              break;
              case GPIO_PORT_AD1:
              {
                 #if (INTERRUPT == PORTAD_PROCESSING)
                   GPIO_Set_8U(GPIO_REG_ETC(cGPIO_RegIntEn[portNum - GPIO_PORT_P]), pinNum); 
                 #endif
              }
              break;
              default:
                
              break;
              
            }
          
            
            if(intMode == GPIO_INT_MODE_FALLING)
            {
                GPIO_Clr_8U(GPIO_REG_ETC(cGPIO_RegPolarSelect[portNum - GPIO_PORT_T]), pinNum); 
            }
            else
            {
                GPIO_Set_8U(GPIO_REG_ETC(cGPIO_RegPolarSelect[portNum - GPIO_PORT_T]), pinNum); 
            }
        }  
    }
    else
    {
        /* do nothing */
    }
}

/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : GPIO_BitCheck
*
* Description   : Checking which bit is '1'.
*
* Inputs        : UINT8 chkByte      :Be checked data 
*
* Outputs       : Number of the first bit '1', 0~7
* 
* Limitations   : 1.If "chkByte" have more than one '1' bit, this function will return the number of the bit which is nearly the LSB.
*                 
************************************************************************************************
END_FUNCTION_HDR */
static UINT8 GPIO_BitCheck(UINT8 chkByte)
{
    UINT8 i = 0;
    while(((chkByte & 0x01) == 0) && (i < 8)) 
    {
        i++;
        chkByte = chkByte >> 1;
    }
    return i;   
}



extern void GPIO_PortPInt_Hook(UINT8 pinNum);
  
/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : PORTP_MainFunction
*
* Description   : This function performs the polling of Port P's interrupt 
*
* Inputs        : None
*
* Outputs       : None
* 
* Limitations   : 1.Only used in the MC9S12G Family chip
*                 
************************************************************************************************
END_FUNCTION_HDR */  
#if (POLLING == PORTP_PROCESSING) 
void PORTP_MainFunction(void)
{
   while(0!=(PIFP&GPIO_PORT_P_MASK))
   {
     volatile UINT8  PIM_P_PinNum = 0;   
     PIM_P_PinNum = GPIO_BitCheck(GPIO_BYTE(cGPIO_RegIntFlag[0]));
     GPIO_Set_8U(GPIO_REG_ETC(cGPIO_RegIntFlag[0]), PIM_P_PinNum);     /* This flag can only be cleared by writing a 1 */
     
     GPIO_PortPInt_Hook(PIM_P_PinNum);
   }

}
#endif
  

#if (INTERRUPT == PORTP_PROCESSING) 
/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : PORTP_ISR
*
* Description   : PORT_P's Interrupt Service Routine 
*
* Inputs        : None
*
* Outputs       : None
* 
* Limitations   : 1.Only used in the MC9S12G Family chip
*                 
************************************************************************************************
END_FUNCTION_HDR */
#pragma CODE_SEG __NEAR_SEG NON_BANKED   
void VECTOR_NUMBER_VPORTP  PORTP_ISR(void)
{
#if 0
   volatile UINT8  PIM_P_PinNum = 0; 
   UINT8 LOCK_LEFT_ST = 1;
   UINT8 LOCK_RIGHT_ST = 1;
   
   LOCK_LEFT_ST = GPIO_Read_8U(LOCK_LEFT_RUN_DIAG_PORT,LOCK_LEFT_RUN_DIAG_PIN);
   LOCK_RIGHT_ST = GPIO_Read_8U(LOCK_RIGHT_RUN_DIAG_PORT,LOCK_RIGHT_RUN_DIAG_PIN);
   
   if(LOCK_LEFT_ST==0)
   {
       LOCK_LEFT_SCG_Flag = 1;
       //LOCK_LEFT_SCG_Flag = 1;
   }
   else
   {
       //
   }
   
   if(LOCK_RIGHT_ST==0)
   {
       LOCK_RIGHT_SCG_Flag = 1;
       //LOCK_RIGHT_SCG_Flag = 1;
   }
   else
   {
       //
   }
     
   PIM_P_PinNum = GPIO_BitCheck(GPIO_BYTE(cGPIO_RegIntFlag[0]));
   GPIO_Set_8U(GPIO_REG_ETC(cGPIO_RegIntFlag[0]), PIM_P_PinNum);     /* This flag can only be cleared by writing a 1 */
   
   //GPIO_PortPInt_Hook(PIM_P_PinNum);
   #endif
}
#pragma CODE_SEG DEFAULT 
 
#endif


extern void GPIO_PortJInt_Hook(UINT8 pinNum);
  
/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : PORTJ_MainFunction
*
* Description   : This function performs the polling of Port J's interrupt 
*
* Inputs        : None
*
* Outputs       : None
* 
* Limitations   : 1.Only used in the MC9S12G Family chip
*                 
************************************************************************************************
END_FUNCTION_HDR */  
#if (POLLING == PORTJ_PROCESSING) 
void PORTJ_MainFunction(void)
{
   while(0!=(PIFJ&GPIO_PORT_J_MASK))
   {
     volatile UINT8  PIM_J_PinNum = 0;   
     PIM_J_PinNum = GPIO_BitCheck(GPIO_BYTE(cGPIO_RegIntFlag[1]));
     GPIO_Set_8U(GPIO_REG_ETC(cGPIO_RegIntFlag[1]), PIM_J_PinNum);     /* This flag can only be cleared by writing a 1 */
     
     GPIO_PortJInt_Hook(PIM_J_PinNum);
   }
 
}
#endif

#if (INTERRUPT == PORTJ_PROCESSING) 
/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : PORTJ_ISR
*
* Description   : PORT_J's Interrupt Service Routine 
*
* Inputs        : None
*
* Outputs       : None
* 
* Limitations   : 1.Only used in the MC9S12G Family chip
*                 
************************************************************************************************
END_FUNCTION_HDR */ 
#pragma CODE_SEG __NEAR_SEG NON_BANKED   
void VECTOR_NUMBER_VPORTJ  PORTJ_ISR(void)
{
#if 0
   
   volatile UINT8  PIM_J_PinNum = 0;   
   PIM_J_PinNum = GPIO_BitCheck(GPIO_BYTE(cGPIO_RegIntFlag[1]));
   GPIO_Set_8U(GPIO_REG_ETC(cGPIO_RegIntFlag[1]), PIM_J_PinNum);     /* This flag can only be cleared by writing a 1 */
   RfDrv_ISR_Nint();
   
   RKEReceiveFlag = 1;
 #endif
}
#pragma CODE_SEG DEFAULT 
#endif

/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : GPIO_PortADInt_Hook
*
* Description   : Hook function of Port AD's interrupt 
*
* Inputs        : None
*
* Outputs       : None
* 
* Limitations   : 1.Only used in the MC9S12G Family chip
*                 
************************************************************************************************
END_FUNCTION_HDR */
extern void GPIO_PortADInt_Hook(UINT8 pinNum);

/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : PORTAD_MainFunction
*
* Description   : This function performs the polling of Port AD(0 and 1)'s interrupt 
*
* Inputs        : None
*
* Outputs       : None
* 
* Limitations   : 1.Only used in the MC9S12G Family chip
*                 
************************************************************************************************
END_FUNCTION_HDR */   
#if (POLLING == PORTAD_PROCESSING) 
void PORTAD_MainFunction(void)
{
   volatile UINT8  PIM_AD_PinNum = 0;
   while((0!=(PIF0AD&GPIO_PORT_AD0_MASK))||(0!=(PIF1AD&GPIO_PORT_AD1_MASK)))
   {
     if(0!=(PIF0AD&GPIO_PORT_AD0_MASK))
     {
       PIM_AD_PinNum = GPIO_BitCheck(GPIO_BYTE(cGPIO_RegIntFlag[2]));
       GPIO_Set_8U(GPIO_REG_ETC(cGPIO_RegIntFlag[2]), PIM_AD_PinNum);     /* This flag can only be cleared by writing a 1 */
       
       GPIO_PortADInt_Hook(PIM_AD_PinNum);
     }
     else if(0!=(PIF1AD&GPIO_PORT_AD1_MASK))
     {
       PIM_AD_PinNum = 8+GPIO_BitCheck(GPIO_BYTE(cGPIO_RegIntFlag[3]));
       GPIO_Set_8U(GPIO_REG_ETC(cGPIO_RegIntFlag[3]), PIM_AD_PinNum);     /* This flag can only be cleared by writing a 1 */
       
       GPIO_PortADInt_Hook(PIM_AD_PinNum+8);
     }
     else
     {
         /* do nothing */
     }
   }

}
#endif

#if (INTERRUPT == PORTAD_PROCESSING) 
  /* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : PORTAD_ISR
*
* Description   : PORT_AD's Interrupt Service Routine 
*
* Inputs        : None
*
* Outputs       : None
* 
* Limitations   : 1.Only used in the MC9S12G Family chip
*                 
************************************************************************************************
END_FUNCTION_HDR */ 
#pragma CODE_SEG __NEAR_SEG NON_BANKED 
void VECTOR_NUMBER_VPORTAD  PORTAD_ISR(void)
{
   volatile UINT8  PIM_AD_PinNum = 0;   
   if(0!=(PIF0AD&GPIO_PORT_AD0_MASK))
   {
     PIM_AD_PinNum = GPIO_BitCheck(GPIO_BYTE(cGPIO_RegIntFlag[2]));
     GPIO_Set_8U(GPIO_REG_ETC(cGPIO_RegIntFlag[2]), PIM_AD_PinNum);     /* This flag can only be cleared by writing a 1 */
     GPIO_PortADInt_Hook(PIM_AD_PinNum);
   }
   else if(0!=(PIF1AD&GPIO_PORT_AD1_MASK))
   {
     PIM_AD_PinNum = 8+GPIO_BitCheck(GPIO_BYTE(cGPIO_RegIntFlag[3]));
     GPIO_Set_8U(GPIO_REG_ETC(cGPIO_RegIntFlag[3]), PIM_AD_PinNum);     /* This flag can only be cleared by writing a 1 */
     GPIO_PortADInt_Hook(PIM_AD_PinNum);
   }
}
#pragma CODE_SEG DEFAULT
#endif


























