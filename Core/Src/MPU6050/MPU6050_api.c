/*
 * Author: 		Victo Carmona Ortiz / @BiomechatronicsRookie (github)
 * Date: 		14/11/2024 (DD-MM-YYYY)
 *
 * Description: high level i2c data read functions to work with MPU6050
 */


#include "MPU6050_registermap.h"
#include "MPU6050_platform.h"
#include <stdio.h>
#include <stdint.h>

void IMU_Init(MPU6050_t* dev){
	// First read the byte on power management
	uint8_t tmp = 0;
	uint8_t connected = 0;
	uint8_t status = 0;
	// Let's read WHO_A_I to see if IMU works
	status |= RdByte(dev, WHO_AM_I, &connected);

	// If properly read
	if (~status){

		tmp = tmp | 0x80;
		// Reset device
		status |= WrtByte(dev, PWR_MGMT_1, &tmp);	// Set high the reset device pin
		HAL_Delay(100);
		tmp = tmp & ~tmp;
		status |= WrtByte(dev, PWR_MGMT_1, &tmp);	// Set low the reset device pin

		// To be sure for now, read it
		status |= RdByte(dev, PWR_MGMT_1, &tmp);

		tmp = 0x07;
		status |= WrtByte(dev, SIGNAL_PATH_RESET, &tmp);
		HAL_Delay(100);
		tmp = 0x00;
		status |= WrtByte(dev, SIGNAL_PATH_RESET, &tmp);
		// Enable Data Ready Interrupt
		tmp = 0x01;
		status |= WrtByte(dev, INT_ENABLE, &tmp);
		tmp = 0x20;
		// Configure Data REady Interrupt
		status |= WrtByte(dev, INT_PIN_CFG, &tmp);

	};
};

int ReadAccX(MPU6050_t* dev,  int16_t* buff){
	int16_t tmp;
	int status = RdWord(dev, ACCEL_XOUT_L, &tmp);
	*buff = tmp;
	return status;
};

int ReadAccY(MPU6050_t* dev,  int16_t* buff){
	int16_t tmp;
	int status = RdWord(dev, ACCEL_YOUT_L, &tmp);
	*buff = tmp;
	return status;
};

int ReadAccZ(MPU6050_t* dev,  int16_t* buff){
	int16_t tmp;
	int status = RdWord(dev, ACCEL_ZOUT_L, &tmp);
	*buff = tmp;
	return status;
};

int ReadGyrX(MPU6050_t* dev,  int16_t* buff){
	int16_t tmp;
	int status = RdWord(dev, GYRO_XOUT_L, &tmp);
	*buff = tmp;
	return status;
};

int ReadGyrY(MPU6050_t* dev,  int16_t* buff){
	int16_t tmp;
	int status = RdWord(dev, GYRO_YOUT_L, &tmp);
	*buff = tmp;
	return status;
};

int ReadGyrZ(MPU6050_t* dev, int16_t* buff){
	int16_t tmp;
	int status = RdWord(dev, GYRO_ZOUT_L, &tmp);
	*buff = tmp;
	return status;
};

int ReadAll(MPU6050_t* dev, int16_t *buff, size_t buffSize){
	int status = 0;
	if (buffSize == 6){
		HAL_Delay(1);
		status |= ReadAccX(dev, &buff[0]);
		HAL_Delay(1);
		status |= ReadAccY(dev, &buff[1]);
		HAL_Delay(1);
		status |= ReadAccZ(dev, &buff[2]);
		HAL_Delay(1);
		status |= ReadGyrX(dev, &buff[3]);
		HAL_Delay(1);
		status |= ReadGyrY(dev, &buff[4]);
		HAL_Delay(1);
		status |= ReadGyrZ(dev, &buff[5]);

	} else {
		status = 255;
	};
	return status;
};

void ClearInterrupt(MPU6050_t* dev){
	uint8_t tmp;
	RdByte(dev, INT_STATUS, &tmp);
};






