/*
 * RK_Modbus_Sensor.c
 *
 *  Created on: Oct 21, 2024
 *      Author: KU
 */
#include <RK_Modbus_Sensor.h>

float read_rk_sensor(nmbs_t* nmbs, uint16_t slave_id, uint16_t* reg_out){
	nmbs_set_destination_rtu_address(nmbs, slave_id); // set destination of rtu address

	// read raw data from slave sensor (address is slave_id)
	nmbs_error err = nmbs_read_holding_registers(nmbs, 0x00, sizeof(reg_out), reg_out);
	if (err != NMBS_ERROR_NONE) return -1;

	return 0;
}

float Get_RK_pH(uint16_t* raw_data){
	float raw = convert_raw_to_float(raw_data[0], raw_data[1]);
	float value = hex_to_float(raw);
	return value;
}

float Get_RK_temperature(uint16_t* raw_data){
	float raw = convert_raw_to_float(raw_data[2], raw_data[3]);
	float value = hex_to_float(raw);
	return value;
}

float convert_raw_to_float(uint16_t high, uint16_t low) {
    uint32_t raw_value = ((uint32_t)high << 16) | low;
    return *(float*)&raw_value;
}

// Typecast the hex value to a float pointer
float hex_to_float(unsigned int hex_value) {
    float float_value = *(float*)&hex_value;
    return float_value;
}

