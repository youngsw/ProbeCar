/**
  ******************************************************************************
  * File Name          : USART.c
  * Description        : This file provides code for the configuration
  *                      of the USART instances.
  ******************************************************************************
  * This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * Copyright (c) 2018 STMicroelectronics International N.V. 
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "usart.h"

#include "gpio.h"

/* USER CODE BEGIN 0 */
#include "string.h"
#include "control.h"
/* USER CODE END 0 */

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;

/* USART1 init function */

void MX_USART1_UART_Init(void)
{

  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}
/* USART2 init function */

void MX_USART2_UART_Init(void)
{

  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}
/* USART3 init function */

void MX_USART3_UART_Init(void)
{

  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct;
  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspInit 0 */

  /* USER CODE END USART1_MspInit 0 */
    /* USART1 clock enable */
    __HAL_RCC_USART1_CLK_ENABLE();
  
    /**USART1 GPIO Configuration    
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX 
    */
    GPIO_InitStruct.Pin = GPIO_PIN_9;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* USER CODE BEGIN USART1_MspInit 1 */

  /* USER CODE END USART1_MspInit 1 */
  }
  else if(uartHandle->Instance==USART2)
  {
  /* USER CODE BEGIN USART2_MspInit 0 */

  /* USER CODE END USART2_MspInit 0 */
    /* USART2 clock enable */
    __HAL_RCC_USART2_CLK_ENABLE();
  
    /**USART2 GPIO Configuration    
    PA2     ------> USART2_TX
    PA3     ------> USART2_RX 
    */
    GPIO_InitStruct.Pin = GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* USART2 interrupt Init */
    HAL_NVIC_SetPriority(USART2_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART2_IRQn);
  /* USER CODE BEGIN USART2_MspInit 1 */

  /* USER CODE END USART2_MspInit 1 */
  }
  else if(uartHandle->Instance==USART3)
  {
  /* USER CODE BEGIN USART3_MspInit 0 */

  /* USER CODE END USART3_MspInit 0 */
    /* USART3 clock enable */
    __HAL_RCC_USART3_CLK_ENABLE();
  
    /**USART3 GPIO Configuration    
    PB10     ------> USART3_TX
    PB11     ------> USART3_RX 
    */
    GPIO_InitStruct.Pin = GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* USART3 interrupt Init */
    HAL_NVIC_SetPriority(USART3_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART3_IRQn);
  /* USER CODE BEGIN USART3_MspInit 1 */

  /* USER CODE END USART3_MspInit 1 */
  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspDeInit 0 */

  /* USER CODE END USART1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART1_CLK_DISABLE();
  
    /**USART1 GPIO Configuration    
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX 
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_9|GPIO_PIN_10);

  /* USER CODE BEGIN USART1_MspDeInit 1 */

  /* USER CODE END USART1_MspDeInit 1 */
  }
  else if(uartHandle->Instance==USART2)
  {
  /* USER CODE BEGIN USART2_MspDeInit 0 */

  /* USER CODE END USART2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART2_CLK_DISABLE();
  
    /**USART2 GPIO Configuration    
    PA2     ------> USART2_TX
    PA3     ------> USART2_RX 
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_2|GPIO_PIN_3);

    /* USART2 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART2_IRQn);
  /* USER CODE BEGIN USART2_MspDeInit 1 */

  /* USER CODE END USART2_MspDeInit 1 */
  }
  else if(uartHandle->Instance==USART3)
  {
  /* USER CODE BEGIN USART3_MspDeInit 0 */

  /* USER CODE END USART3_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART3_CLK_DISABLE();
  
    /**USART3 GPIO Configuration    
    PB10     ------> USART3_TX
    PB11     ------> USART3_RX 
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_10|GPIO_PIN_11);

    /* USART3 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART3_IRQn);
  /* USER CODE BEGIN USART3_MspDeInit 1 */

  /* USER CODE END USART3_MspDeInit 1 */
  }
} 

/* USER CODE BEGIN 1 */
extern uint8_t aRxBuffer_1;			                  //接收中断缓冲
extern uint8_t Uart1_RxBuff[256];		              //接收缓冲
extern uint8_t Uart1_Rx_Cnt;		                  //接收缓冲计数
extern uint8_t aRxBuffer_2;			                  //接收中断缓冲
extern uint8_t Uart2_RxBuff[256];		              //接收缓冲
extern uint8_t Uart2_Rx_Cnt;		                  //接收缓冲计数
extern uint8_t aRxBuffer_3;			                  //接收中断缓冲
extern uint8_t Uart3_RxBuff[256];		              //接收缓冲
extern uint8_t Uart3_Rx_Cnt;		                  //接收缓冲计数
extern uint16_t Height;
extern uint16_t HeightArray[12];
extern uint8_t carStatus;
extern uint8_t sendListFlag;
extern uint32_t sendListPage;
extern uint8_t timeFlag;
uint16_t strength,check;
uint8_t i;
uint8_t uart3Receive[9];
uint8_t HeigthContor =0;
const uint8_t HEADER=0x59;

uint8_t	cAlmStr[] = "数据溢出(大于256)\r\n";
uint8_t x,y;

/**
  * @brief  Rx Transfer completed callbacks.
  * @param  huart pointer to a UART_HandleTypeDef structure that contains
  *                the configuration information for the specified UART module.
  * @retval None
  */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
//  UNUSED(huart3);
  UNUSED(huart2);
  /* NOTE: This function Should not be modified, when the callback is needed,
           the HAL_UART_TxCpltCallback could be implemented in the user file
   */
  if(huart->Instance == USART2)
  {              
    if(Uart2_Rx_Cnt >= 255)                       //溢出判断
    { 
      Uart2_Rx_Cnt = 0;
      memset(Uart2_RxBuff,0x00,sizeof(Uart2_RxBuff));
      HAL_UART_Transmit(&huart2, (uint8_t *)&cAlmStr, sizeof(cAlmStr),0xFFFF);	
    } 
    else
    {   
      Uart2_RxBuff[Uart2_Rx_Cnt++] = aRxBuffer_2;   //接收数据转存
      //printf("\r\n我是串口二\n");
      if(Uart2_RxBuff[Uart2_Rx_Cnt-1]==0x66)                 //判断控制命令起始位（拟定起始位0x66）
      {
        carStatus = 1;    //前进
        timeFlag = 1;     //计时
        printf("\r\n我是串口二66\n");
      }
      if(Uart2_RxBuff[Uart2_Rx_Cnt-1]==0x67)                 //判断控制命令起始位（拟定起始位0x66）
      {
        carStatus = 2;    //后退
        timeFlag = 1;     //计时
        printf("\r\n我是串口二67\n");
      }        
      if(Uart2_RxBuff[Uart2_Rx_Cnt-1]==0x68)                 //判断控制命令起始位（拟定起始位0x66）
      {
        carStatus = 3;    //刹车
        timeFlag = 0;     //关闭计时
        printf("\r\n我是串口二68\n");
      }
      if(Uart2_RxBuff[Uart2_Rx_Cnt-1]==0x70)                 //判断控制命令起始位（拟定起始位0x66）
      {
        sendListFlag = 1;    //查询列表
        sendListPage = 0;
      } 
      if(Uart2_RxBuff[Uart2_Rx_Cnt-1]==0x71)                 //判断控制命令起始位（拟定起始位0x66）
      {
        sendListFlag = 1;    //查询列表上一页
        if(sendListPage>0)
          sendListPage --;
      } 
      if(Uart2_RxBuff[Uart2_Rx_Cnt-1]==0x72)                 //判断控制命令起始位（拟定起始位0x66）
      {
        sendListFlag = 1;    //查询列表下一页
        if(sendListPage<99999)
          sendListPage ++;
      }       
    }
    //HAL_UART_Transmit(&huart2, (uint8_t *)&Uart2_RxBuff, Uart2_Rx_Cnt,0xFFFF); //将收到的信息发送出去
    Uart2_Rx_Cnt = 0;
    memset(Uart2_RxBuff,0x00,sizeof(Uart2_RxBuff)); //清空数组
  }
  HAL_UART_Receive_IT(&huart2, (uint8_t *)&aRxBuffer_2, 1);   //开启串口接收中断  
 

/*----------------------------------------------Beautiful Line--------------------------------------------------------*/
  if(huart->Instance == USART3)
  {
    if(Uart3_Rx_Cnt >= 255)                                     //溢出判断
    { 
      Uart3_Rx_Cnt = 0;
      memset(Uart3_RxBuff,0x00,sizeof(Uart3_RxBuff));
      HAL_UART_Transmit(&huart3, (uint8_t *)&cAlmStr, sizeof(cAlmStr),0xFFFF);	
    }
    else
    {
      
      //Uart3_RxBuff[Uart3_Rx_Cnt++] = aRxBuffer_3;             //接收数据转存
      if(aRxBuffer_3==HEADER)
      {
        uart3Receive[0] = 0x59;
        i = 1;      
      }
      uart3Receive[i] =  aRxBuffer_3;
      i++;  
        check = uart3Receive[0]+uart3Receive[1]+uart3Receive[2]+uart3Receive[3]+\
                uart3Receive[4]+uart3Receive[5]+uart3Receive[6]+uart3Receive[7];
        if(uart3Receive[8]==(check&0xff))                       //按照协议对收到的数据进行校验
        {
          Height=uart3Receive[2]+uart3Receive[3]*256;           //计算距离值 
          strength=uart3Receive[4]+uart3Receive[5]*256;         //计算信号强度值 
//          printf("\r\nHeight=%d\n",Height);      
//          printf("\r\nstrength=: %d\n",strength);               //输出信号强度值 
          i = 0;
          memset(uart3Receive,0x00,sizeof(uart3Receive));       //清空数组
          HeightArray[HeigthContor] =  Height; 
          HeigthContor++;
          if(HeigthContor>5)
          {
            HeigthContor=0;
            ifInsideOrOutside();
          }
        }    
    }
    HAL_UART_Receive_IT(&huart3, (uint8_t *)&aRxBuffer_3, 1);   //开启串口接收中断
  }
}
/* USER CODE END 1 */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
