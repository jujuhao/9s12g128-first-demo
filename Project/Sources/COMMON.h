 /*  BEGIN_FILE_HDR
************************************************************************************************
************************************************************************************************
*   File Name       : HRSTDDEF.h
************************************************************************************************
*   Project/Product : Common Driver
*   Title           : Standard Define 
*   Author          : hf
************************************************************************************************
*   Description     : This is common module for body netword
*
************************************************************************************************
*   Limitations     : NONE
*
************************************************************************************************
*
************************************************************************************************
*   Revision History:
* 
*   Version       Date         Initials     CR#           Descriptions
*   ---------   -----------  ------------  ----------  ---------------
*   1.0           20190315       hf          N/A           Original
************************************************************************************************
*   END_FILE_HDR*/

#ifndef COMMON_H
#define COMMON_H

#include <hidef.h>
#include "derivative.h"
#include "Vector.h"

 /* data type defintion */
typedef unsigned char   UINT8;                /* UnSigned  8 bit quantity    */ 
typedef signed   char   INT8;                /* Signed  8 bit quantity    */ 
typedef unsigned short  UINT16;               /* Unsigned  16 bit quantity */
typedef signed   short  INT16;               /* Signed  16 bit quantity  */
typedef unsigned long   UINT32;               /* Unsigned  32 bit quantity */ 
typedef signed   long   INT32;               /* Signed  8 bit quantity */
typedef float           FLOAT;                /* Float   */
typedef UINT8         BOOL;                 /* Boolean   */ 

typedef unsigned  int   UINT16I;
typedef signed    int   UINT16S;

 UINT8 SET_BIT_8U(UINT8 x)
{
    return ( UINT8 ) (  ((UINT8)1u<<x) );
}

UINT8 CLR_BIT_8U(UINT8 x)
{
    return ( UINT8 ) (  (~((UINT8)1u<<x)) );
}

#define SET_BIT0        0x01U
#define SET_BIT1        0x02U
#define SET_BIT2        0x04U
#define SET_BIT3        0x08U
#define SET_BIT4        0x10U
#define SET_BIT5        0x20U
#define SET_BIT6        0x40U
#define SET_BIT7        0x80U

#define CLR_BIT0        0xFEU
#define CLR_BIT1        0xFDU
#define CLR_BIT2        0xFBU
#define CLR_BIT3        0xF7U
#define CLR_BIT4        0xEFU
#define CLR_BIT5        0xDFU
#define CLR_BIT6        0xBFU
#define CLR_BIT7        0x7FU

#define SET_BITX        (0x01U)
#define CLR_BITX        (0x00U)

/* Macro Define */
/*used to configure in or configure out a certain function*/
#define FUN_EN          1
#define FUN_DIS         0

/*use online configure or offline configure*/
#define CFG_ONLINE      1
#define CFG_OFFLINE     0

/* Haradware Define */
#define SET_DDR_OUT         (0x01U)
#define SET_DDR_IN          (0x00U)

#define SET_PORT_HIGH	      (0x01U)
#define SET_PORT_LOW	      (0x00U)

#define PIN_SET_HIG         (1U)
#define PIN_SET_LOW         (0U)
/*INACTIVE & ACTIVE definition*/
#define INACTIVE        0
#define ACTIVE          1

/* Diagnose   */
#define SAMP_VAL_RESET                  (0x00U)
#define CNT_DIAG_RESET_LVL              (0x00U)
#define CNT_DIAG_END_LVL                (0x01U)
#define CNT_DIAG_START_LVL              (0x01U)
#define CNT_NOR_RESET_LVL               (0x00U)
#define CNT_DIAG_RUN_RESET_LVL          (0x00U)
#define CNT_DIAG_RUN_END_LVL            (0x01U)

#define ERR_DIAG_ST_MEDIACY             (0x80U)
#define ERR_DIAG_ST_END                 (0x00U)

#define EXIT_ABNOR_WAIT_CNT_LVL	         (100U)

/* add by haijiang.zhang for S12G128 interrupt begin 20120709 */
#ifndef INTERRUPT
#define INTERRUPT                       1u
#endif

#ifndef POLLING
#define POLLING                         0u
#endif
/* add by haijiang.zhang for S12G128 interrupt end   20120709 */


#endif
