/*
 * RK_Modbus_Sensor.h
 *
 *  Created on: Oct 21, 2024
 *      Author: KU
 */

#ifndef INC_RK_MODBUS_SENSOR_H_
#define INC_RK_MODBUS_SENSOR_H_

#include <nanomodbus.h>
#include <stdio.h>
#include <stdint.h>

/**
 * @brief Reads sensor data from an RK Modbus sensor.
 *
 * This function sets the destination RTU address and reads a specified number of registers
 * starting from address 0x0000. The function expects to read holding registers from the Modbus sensor.
 *
 * @param[in] nmbs Pointer to the Modbus client instance (nmbs_t).
 * @param[in] slave_id ID of the slave device to communicate with.
 * @param[out] reg_out Pointer to an array where the read register values will be stored.
 *
 * @return Returns -1 on failure to read registers; otherwise returns 0 on success.
 */
float read_rk_sensor(nmbs_t* nmbs, uint16_t slave_id, uint16_t* reg_out);

/**
 * @brief Converts two 16-bit register values to a pH value.
 *
 * This function takes two 16-bit register values from a Modbus RTU sensor,
 * combines them to form a 32-bit floating-point value representing the pH.
 *
 * @param[in] raw_data Pointer to an array containing two 16-bit register values.
 * @return The converted pH value as a float.
 */
float Get_RK_pH(uint16_t* raw_data);

/**
 * @brief Converts two 16-bit register values to a temperature value.
 *
 * This function takes two 16-bit register values from a Modbus RTU sensor,
 * combines them to form a 32-bit floating-point value representing the temperature.
 *
 * @param[in] raw_data Pointer to an array containing two 16-bit register values for temperature.
 * @return The converted temperature value as a float.
 */
float Get_RK_temperature(uint16_t* raw_data);

/**
 * @brief Converts two 16-bit register values to a 32-bit floating-point value.
 *
 * This function combines two 16-bit register values (high and low) into a 32-bit
 * integer and then safely converts that to a float using a union.
 *
 * @param[in] high The higher 16 bits of the floating-point value.
 * @param[in] low The lower 16 bits of the floating-point value.
 * @return The combined 32-bit floating-point value.
 */
float convert_raw_to_float(uint16_t high, uint16_t low);

/**
 * @brief Converts a 32-bit hexadecimal value to a floating-point number.
 *
 * This function safely converts a 32-bit unsigned integer (hexadecimal representation)
 * to a float using a union, ensuring compliance with strict aliasing rules.
 *
 * @param[in] hex_value The 32-bit unsigned integer representing the floating-point value.
 * @return The equivalent floating-point value.
 */
float hex_to_float(unsigned int hex_value);

#endif /* INC_RK_MODBUS_SENSOR_H_ */
