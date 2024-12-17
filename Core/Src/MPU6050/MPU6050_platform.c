/*
 * Author: 		Victo Carmona Ortiz / @BiomechatronicsRookie (github)
 * Date: 		12/10/2024 (DD-MM-YYYY)
 *
 * Description: low level i2c data read functions to work with MPU6050
 */


#include "MPU6050_errorcodes.h"
#include "MPU6050_platform.h"
#include "MPU6050_registermap.h"
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
	for (uint8_t i=0; i < 2; i++){
		uint8_t tmp = 0;							// Use a temporal variable to store the
		status |= RdByte(dev, memAdd_L-i ,&tmp);	// Read a byte from the address shifter by positions up
		*buff |= (tmp & 0x00FF) << i*8 ;		    // Assign it to the buffer
	}
	return status;
};

uint8_t BurstRead(MPU6050_t* dev, uint8_t memAdd_L, int16_t buff[], uint8_t buffSize, uint8_t Delay){
	uint8_t status;
	int16_t tmp = 0;
	uint8_t add;
	for (uint8_t i = 0; i < buffSize; i++){
		tmp = 0;							// Reset buffer contents every time, otherwise OR operation on RdWord messes up info
		add = memAdd_L + (i*2);				// Increment address
		status |= RdWord(dev, add, &tmp);	// Read address value
		buff[i] = tmp;						// Add to the buffer
		HAL_Delay(Delay);					// Delay needed to switch registers in MPU6050
		}
	return status;
};


uint8_t FifoRead(MPU6050_t* dev, int16_t* buff, uint8_t fifoBuffLen){
	uint8_t status;
	int16_t tmp = 0;
	for (uint8_t i = 1; i <= fifoBuffLen; i++){
			status |= RdWord(dev, FIFO_R_W ,&tmp);	// Read a byte from the address shifter by positions up
			*(buff + fifoBuffLen - i) = tmp;		    // Assign it to the buffer
		}
	return status;
};


