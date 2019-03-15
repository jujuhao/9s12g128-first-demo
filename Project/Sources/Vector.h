/*  BEGIN_FILE_HDR
************************************************************************************************
*   NOTICE                              
*   This software is the property of YKXH Technologies. Any information contained in this 
*   doc should not be reproduced, or used, or disclosed without the written authorization from 
*   YKXH Technologies.
************************************************************************************************
*   File Name       : vector.c
************************************************************************************************
*   Project/Product : All
*   Title           : interrupt vector define File
*   Author          : yaqi.yu
************************************************************************************************
*   Description     : interrupt vector define
*
************************************************************************************************
*   Limitations     : ONLY using the ATD_S12Gxxx moduleNum
*
************************************************************************************************
*
************************************************************************************************
*   Revision History:
* 
*   Version     Date          Initials      CR#          Descriptions
*   ---------   ----------    ------------  ----------   ---------------
*   1.0         2011/07/15    yaqi.yu        N/A          Original
*
************************************************************************************************
* END_FILE_HDR*/
#ifndef VECTOR_H
#define VECTOR_H


/*---------- User config field begin ----------*/
/* when used in bootloader,need to define this,
   when used in application, no need to define this */

#define WITH_BOOTLOADER     /* if only APP, needed delete for BT */

/*---------- User config field end ----------*/ 


/* For interrupt mode selection */ 
#define INT_MODE_NORMAL         0U      /* Normal mode     */
#define INT_MODE_BT             1U      /* Bootloader mode */

#ifdef  WITH_BOOTLOADER
#define LOAD_INT_MODE               INT_MODE_BT
#else
#define LOAD_INT_MODE               INT_MODE_NORMAL
#endif

/**************** interrupt vector numbers ****************/
#if(LOAD_INT_MODE == INT_MODE_NORMAL) 
    #define VECTOR_NUMBER_VSI                interrupt 63U
    #define VECTOR_NUMBER_VPORTAD            interrupt 62U
    #define VECTOR_NUMBER_VATDCOMPARE        interrupt 61U
    #define VECTOR_NUMBER_VRESERVED60        interrupt 60U
    #define VECTOR_NUMBER_VAPI               interrupt 59U
    #define VECTOR_NUMBER_VLVI               interrupt 58U
    #define VECTOR_NUMBER_VTESERVED57        interrupt 57U
    #define VECTOR_NUMBER_VPORTP             interrupt 56U
    #define VECTOR_NUMBER_VRESERVED55        interrupt 55U
    #define VECTOR_NUMBER_VRESERVED54        interrupt 54U
    #define VECTOR_NUMBER_VRESERVED53        interrupt 53U
    #define VECTOR_NUMBER_VRESERVED52        interrupt 52U
    #define VECTOR_NUMBER_VRESERVED51        interrupt 51U
    #define VECTOR_NUMBER_VRESERVED50        interrupt 50U
    #define VECTOR_NUMBER_VRESERVED49        interrupt 49U
    #define VECTOR_NUMBER_VRESERVED48        interrupt 48U
    #define VECTOR_NUMBER_VRESERVED47        interrupt 47U
    #define VECTOR_NUMBER_VRESERVED46        interrupt 46U
    #define VECTOR_NUMBER_VRESERVED45        interrupt 45U
    #define VECTOR_NUMBER_VRESERVED44        interrupt 44U
    #define VECTOR_NUMBER_VRESERVED43        interrupt 43U
    #define VECTOR_NUMBER_VRESERVED42        interrupt 42U
    #define VECTOR_NUMBER_VRESERVED41        interrupt 41U
    #define VECTOR_NUMBER_VRESERVED40        interrupt 40U
    #define VECTOR_NUMBER_VRESERVED39        interrupt 39U
    #define VECTOR_NUMBER_VRESERVED38        interrupt 38U
    #define VECTOR_NUMBER_VRESERVED37        interrupt 37U
    #define VECTOR_NUMBER_VRESERVED36        interrupt 36U
    #define VECTOR_NUMBER_VFLASH             interrupt 35U
    #define VECTOR_NUMBER_VFLASHFD           interrupt 34U
    #define VECTOR_NUMBER_VRESERVED33        interrupt 33U
    #define VECTOR_NUMBER_VRESERVED32        interrupt 32U
    #define VECTOR_NUMBER_VRESERVED31        interrupt 31U
    #define VECTOR_NUMBER_VRESERVED30        interrupt 30U
    #define VECTOR_NUMBER_VRESERVED29        interrupt 29U
    #define VECTOR_NUMBER_VCPMUPLLLCK        interrupt 28U
    #define VECTOR_NUMBER_VCPMUOCSNS         interrupt 27U
    #define VECTOR_NUMBER_VRESERVED26        interrupt 26U
    #define VECTOR_NUMBER_VACMP              interrupt 25U
    #define VECTOR_NUMBER_VPORTJ             interrupt 24U
    #define VECTOR_NUMBER_VRESERVED23        interrupt 23U
    #define VECTOR_NUMBER_VATD               interrupt 22U
    #define VECTOR_NUMBER_VRESERVED21        interrupt 21U
    #define VECTOR_NUMBER_VSCI0              interrupt 20U
    #define VECTOR_NUMBER_VSPI0              interrupt 19U
    #define VECTOR_NUMBER_VRESERVED18        interrupt 18U
    #define VECTOR_NUMBER_VRESERVED17        interrupt 17U
    #define VECTOR_NUMBER_VTIMOVF            interrupt 16U
    #define VECTOR_NUMBER_VRESERVED15        interrupt 15U
    #define VECTOR_NUMBER_VTIMCH6            interrupt 14U
    #define VECTOR_NUMBER_VTIMCH5            interrupt 13U
    #define VECTOR_NUMBER_VTIMCH4            interrupt 12U
    #define VECTOR_NUMBER_VTIMCH3            interrupt 11U
    #define VECTOR_NUMBER_VTIMCH2            interrupt 10U
    #define VECTOR_NUMBER_VTIMCH1            interrupt 9U
    #define VECTOR_NUMBER_VTIMCH0            interrupt 8U
    #define VECTOR_NUMBER_VRTI               interrupt 7U
    #define VECTOR_NUMBER_VIRQ               interrupt 6U
    #define VECTOR_NUMBER_VXIRQ              interrupt 5U
    #define VECTOR_NUMBER_VSWI               interrupt 4U
    #define VECTOR_NUMBER_VTRAP              interrupt 3U
    #define VECTOR_NUMBER_VCOP               interrupt 2U
    #define VECTOR_NUMBER_VCLKMON            interrupt 1U
    #define VECTOR_NUMBER_VRESET             interrupt 0U 
#else
    #define VECTOR_NUMBER_VSI                interrupt 
    #define VECTOR_NUMBER_VPORTAD            interrupt 
    #define VECTOR_NUMBER_VATDCOMPARE        interrupt 
    #define VECTOR_NUMBER_VRESERVED60        interrupt 
    #define VECTOR_NUMBER_VAPI               interrupt 
    #define VECTOR_NUMBER_VLVI               interrupt 
    #define VECTOR_NUMBER_VTESERVED57        interrupt 
    #define VECTOR_NUMBER_VPORTP             interrupt 
    #define VECTOR_NUMBER_VRESERVED55        interrupt 
    #define VECTOR_NUMBER_VRESERVED54        interrupt 
    #define VECTOR_NUMBER_VRESERVED53        interrupt 
    #define VECTOR_NUMBER_VRESERVED52        interrupt 
    #define VECTOR_NUMBER_VRESERVED51        interrupt 
    #define VECTOR_NUMBER_VRESERVED50        interrupt 
    #define VECTOR_NUMBER_VRESERVED49        interrupt 
    #define VECTOR_NUMBER_VRESERVED48        interrupt 
    #define VECTOR_NUMBER_VRESERVED47        interrupt 
    #define VECTOR_NUMBER_VRESERVED46        interrupt 
    #define VECTOR_NUMBER_VRESERVED45        interrupt 
    #define VECTOR_NUMBER_VRESERVED44        interrupt 
    #define VECTOR_NUMBER_VRESERVED43        interrupt 
    #define VECTOR_NUMBER_VRESERVED42        interrupt 
    #define VECTOR_NUMBER_VRESERVED41        interrupt 
    #define VECTOR_NUMBER_VRESERVED40        interrupt 
    #define VECTOR_NUMBER_VRESERVED39        interrupt 
    #define VECTOR_NUMBER_VRESERVED38        interrupt 
    #define VECTOR_NUMBER_VRESERVED37        interrupt 
    #define VECTOR_NUMBER_VRESERVED36        interrupt 
    #define VECTOR_NUMBER_VFLASH             interrupt 
    #define VECTOR_NUMBER_VFLASHFD           interrupt 
    #define VECTOR_NUMBER_VRESERVED33        interrupt 
    #define VECTOR_NUMBER_VRESERVED32        interrupt 
    #define VECTOR_NUMBER_VRESERVED31        interrupt 
    #define VECTOR_NUMBER_VRESERVED30        interrupt 
    #define VECTOR_NUMBER_VRESERVED29        interrupt 
    #define VECTOR_NUMBER_VCPMUPLLLCK        interrupt 
    #define VECTOR_NUMBER_VCPMUOCSNS         interrupt 
    #define VECTOR_NUMBER_VRESERVED26        interrupt 
    #define VECTOR_NUMBER_VACMP              interrupt 
    #define VECTOR_NUMBER_VPORTJ             interrupt 
    #define VECTOR_NUMBER_VRESERVED23        interrupt 
    #define VECTOR_NUMBER_VATD               interrupt 
    #define VECTOR_NUMBER_VRESERVED21        interrupt 
    #define VECTOR_NUMBER_VSCI0              interrupt 
    #define VECTOR_NUMBER_VSPI0              interrupt 
    #define VECTOR_NUMBER_VRESERVED18        interrupt 
    #define VECTOR_NUMBER_VRESERVED17        interrupt 
    #define VECTOR_NUMBER_VTIMOVF            interrupt 
    #define VECTOR_NUMBER_VRESERVED15        interrupt 
    #define VECTOR_NUMBER_VTIMCH6            interrupt 
    #define VECTOR_NUMBER_VTIMCH5            interrupt 
    #define VECTOR_NUMBER_VTIMCH4            interrupt 
    #define VECTOR_NUMBER_VTIMCH3            interrupt 
    #define VECTOR_NUMBER_VTIMCH2            interrupt 
    #define VECTOR_NUMBER_VTIMCH1            interrupt 
    #define VECTOR_NUMBER_VTIMCH0            interrupt 
    #define VECTOR_NUMBER_VRTI               interrupt 
    #define VECTOR_NUMBER_VIRQ               interrupt 
    #define VECTOR_NUMBER_VXIRQ              interrupt 
    #define VECTOR_NUMBER_VSWI               interrupt 
    #define VECTOR_NUMBER_VTRAP              interrupt 
    #define VECTOR_NUMBER_VCOP               interrupt 
    #define VECTOR_NUMBER_VCLKMON            interrupt 
    #define VECTOR_NUMBER_VRESET             interrupt 
#endif

   
#endif /* VECTOR_H */