/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    flash_if.h
  * @author  MCD Application Team
  * @brief   This file contains definitions for FLASH Interface functionalities.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __FLASH_IF_H__
#define __FLASH_IF_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "platform.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/**
  * @brief Flash status
  */
typedef enum
{
  FLASH_IF_PARAM_ERROR  = -6, /*!< Error Flash invalid parameter */
  FLASH_IF_LOCK_ERROR   = -5, /*!< Error Flash not locked */
  FLASH_IF_WRITE_ERROR  = -4, /*!< Error Flash write not possible */
  FLASH_IF_READ_ERROR   = -3, /*!< Error Flash read not possible */
  FLASH_IF_ERASE_ERROR  = -2, /*!< Error Flash erase not possible */
  FLASH_IF_ERROR        = -1, /*!< Error Flash generic */
  FLASH_IF_OK           = 0,  /*!< Flash Success */
  FLASH_IF_BUSY         = 1   /*!< Flash not available */
} FLASH_IF_StatusTypedef;

/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
#define FLASH_IF_BUFFER_SIZE       0x00001000U /*!< External FLASH Sector Size, 4 KBytes */

/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* External variables --------------------------------------------------------*/
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
/**
  * @brief This function initializes the internal and external flash interface
  *
  * @param pAllocRamBuffer pointer used to store a FLASH page in RAM when partial replacement is needed
  * @return FLASH_IF_StatusTypedef status
  */
FLASH_IF_StatusTypedef FLASH_IF_Init(void *pAllocRamBuffer);

/**
  * @brief This function de-initializes the internal and external flash interface
  *
  * @return FLASH_IF_StatusTypedef status
  */
FLASH_IF_StatusTypedef FLASH_IF_DeInit(void);

/**
  * @brief This function writes a data buffer in internal or external flash
  *
  * @param pDestination pointer of flash address to write. It has to be 8 bytes aligned.
  * @param pSource pointer on buffer with data to write
  * @param uLength length of data buffer in bytes. It has to be 8 bytes aligned.
  * @return FLASH_IF_StatusTypedef status
  */
FLASH_IF_StatusTypedef FLASH_IF_Write(void *pDestination, const void *pSource, uint32_t uLength);

/**
  * @brief This function reads a amount of data from flash and copy into the output data buffer
  *
  * @param pDestination pointer of target location to copy the flash sector
  * @param pSource pointer of flash address to read
  * @param uLength number of bytes to read
  * @return FLASH_IF_StatusTypedef status
  */
FLASH_IF_StatusTypedef FLASH_IF_Read(void *pDestination, const void *pSource, uint32_t uLength);

/**
  * @brief This function erases a amount of internal or external flash pages depending of the length
  *
  * @param pStart pointer of flash address to erase
  * @param uLength number of bytes to erase
  * @return FLASH_IF_StatusTypedef status
  */
FLASH_IF_StatusTypedef FLASH_IF_Erase(void *pStart, uint32_t uLength);

/* USER CODE BEGIN EFP */

/**
 * @brief This function returns page index in internal or external flash
 *
 * @param uStart flash address to get page index
 * @return Number of pages
 */
uint32_t FLASH_IF_PAGE_Index (uint32_t uStart);

/**
 * @brief Check if address is in external flash
 *
 * @param uStart address in question
 * @return If external flash true
 */
bool FLASH_IF_IsExt (uint32_t uStart);

/**
 * @brief Calculate CRC32 of flash content of internal or external flash
 *
 * @param uStart Flash address to start calculation
 * @param uLength Length of area to calculate CRC32
 * @return CRC32 value
 */
uint32_t FLASH_IF_CRC32 (uint32_t uStart, uint32_t uLength);

/* USER CODE END EFP */

#ifdef __cplusplus
}
#endif

#endif /* __FLASH_IF_H__ */
