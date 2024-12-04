/*
 * Author: 		Victo Carmona Ortiz / @BiomechatronicsRookie (github)
 * Date: 		12/10/2024 (DD-MM-YYYY)
 *
 * Description: low level i2c data read functions to work with MPU6050
 */


#include "MPU6050_errorcodes.h"
#include "MPU6050_platform.h"
#include <stdio.h>
#include <stdint.h>

/* Read a byte from a specific memory address using i2c */
uint8_t RdByte(MPU6050_t* dev, uint8_t memAdd, uint8_t* buff){
	uint8_t status;
	status = HAL_I2C_Mem_Read(dev->i2c_hanlde, dev->dev_address, memAdd, 1, buff , 1, 500);
	return status;
	};

uint8_t WrtByte(MPU6050_t* dev, uint8_t memAdd, uint8_t* buff){
	uint8_t status;
	status = HAL_I2C_Mem_Write(dev->i2c_hanlde, dev->dev_address, memAdd, 1, buff , 1, 500);
	return status;
	};

/* Read a 2ord (2 bytes) from a specific memory address and it's previous address using i2c*/
uint8_t RdWord(MPU6050_t* dev, uint8_t memAdd_L, int16_t* buff){
	// Declare status
	uint8_t status = 0;
	uint8_t i;

	for (i=0; i < 2; i++){
		uint8_t tmp = 0;							// Use a temporal variable to store the
		status |= RdByte(dev, memAdd_L-i ,&tmp);	// Read a byte from the address shifter by positions up
		*buff |= (tmp & 0x00FF) << i*8 ;		    // Assign it to the buffer
	}
	return status;
};
