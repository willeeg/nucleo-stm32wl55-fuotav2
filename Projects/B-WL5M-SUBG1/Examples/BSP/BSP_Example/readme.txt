/**
  @page BSP  Description of the BSP example
  
  @verbatim
  ******************************************************************************
  * @file    BSP/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the BSP example.
  ******************************************************************************
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  @endverbatim

@par Example Description

How to use the different BSP drivers of external devices mounted on : B-WL5M-SUBG1 board.

At the beginning of the main program the HAL_Init() function is called to reset 
all the peripherals, initialize the Flash interface and the systick.
Then the SystemClock_Config() function is used to configure the system clock
(SYSCLK) to run at 64 MHz.

This example shows how to use the different functionalities of components
available on the board by switching between all tests using User Button1 push-button.

 ** Push the User B1 push-button to start first Test.

### LED ###
This example shows how to use turn on/off and toggle the LEDs.

### FLASH ###
This example shows how to Read/Write to the SPI external flash.

### TEMPERATURE ###
This example shows how to use the sensors to get tempearture values. Both, 
STTS22H and LPS22HB sensors are used. 

### GYROSCOPE ###
This example shows how to use the ISM330DHCX sensor to get gyroscope values.

### ACCELERO ###
This example shows how to use the ISM330DHCX sensor to get accelerometer values.

### RADIO ###
This example provides of how to use RADIO in Rx or Tx (HP/LP) modes


@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application need to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Keywords

BSP, Led, Flash, Memory, SPI, Humidity, Button, Temperature, Sensor,
Accelerometer, STTS22H, ISM330DHCX.

@par Directory contents 

  - BSP/Src/main.c                        Main program
  - BSP/Src/system_stm32wlxx.c            STM32WLxx system clock configuration file
  - BSP/Src/stm32wbxx_it.c                Interrupt handlers
  - BSP/Src/flash.c                       Tests of Read/Write to external flash
  - BSP/Src/led.c                         Tests of Turn on/off or toggle the LEDs
  - BSP/Src/sensors.c                     Tests of stts22h, iis2mdc, ism330dhcx and lps22hh sensors
  - BSP/Src/radio.c                       Tests of Radio
  - BSP/Inc/main.h                        Main program header file  
  - BSP/Inc/stm32wlxx_hal_conf.h          HAL Configuration file
  - BSP/Inc/stm32wlxx_it.h                Interrupt handlers header file
  - BSP/Inc/stm32wl5m_subg_conf.h         B-WL5M-SUBG board configuration file

@par Hardware and Software environment  

  - This example runs on STM32WL5Mxx devices.

  - This example has been tested with STMicroelectronics B-WL5M-SUBG1 boards.


@par How to use it ? 

In order to make the program work, you must do the following :    
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
