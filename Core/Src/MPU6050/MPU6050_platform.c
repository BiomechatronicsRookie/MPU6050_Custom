/*
 * Author: 		Victo Carmona Ortiz / @BiomechatronicsRookie (github)
 * Date: 		12/10/2024 (DD-MM-YYYY)
 *
 * Description: i2c data read functions to work with MPU6050
 */


#include "MPU6050_errorcodes.h"
#include "MPU6050_platform.h"
#include <stdio.h>
#include <stdint.h>

/* Read a byte from a specific memory address using i2c */
int RdByte(MPU6050_t* dev, uint16_t memAdd, uint8_t* buff){
	uint8_t status;
	status = HAL_I2C_Mem_Read(dev->i2c_hanlde, dev->dev_address, memAdd, 1, buff , 1, 500);
	return status;
	};
