/******************************************************************************

  Copyright (C), 2001-2011, DCN Co., Ltd.

 ******************************************************************************
  File Name     : common_api.c
  Version       : Initial Draft
  Author        : ligui.zhang
  Created       : 2019/5/9
  Last Modified :
  Description   : stm32f10x-template
  Function List :
  History       :
  1.Date        : 2019/5/9
    Author      : ligui.zhang
    Modification: Created file

******************************************************************************/

/*----------------------------------------------*
 * external variables                           *
 *----------------------------------------------*/

/*----------------------------------------------*
 * external routine prototypes                  *
 *----------------------------------------------*/

/*----------------------------------------------*
 * internal routine prototypes                  *
 *----------------------------------------------*/

/*----------------------------------------------*
 * project-wide global variables                *
 *----------------------------------------------*/

/*----------------------------------------------*
 * module-wide global variables                 *
 *----------------------------------------------*/

/*----------------------------------------------*
 * constants                                    *
 *----------------------------------------------*/

/*----------------------------------------------*
 * macros                                       *
 *----------------------------------------------*/

/*----------------------------------------------*
 * routines' implementations                    *
 *----------------------------------------------*/
#include <stdio.h>
#include "common_api.h"
#include "stm32f10x_usart.h"

//重定义fputc函数
int fputc(int ch, FILE *f)
{
    USART_ClearFlag(DEBUG_UART, USART_FLAG_TC);
    USART_SendData(DEBUG_UART, ch);

    while (USART_GetFlagStatus(DEBUG_UART, USART_FLAG_TXE) == RESET);
    return ch;
}



