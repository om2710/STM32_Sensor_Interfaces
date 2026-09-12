#include "main.h"

extern ADC_HandleTypeDef hadc1;

uint32_t Sensor_Read_ADC(void)
{
    uint32_t value = 0;

    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
    value = HAL_ADC_GetValue(&hadc1);
    HAL_ADC_Stop(&hadc1);

    return value;
}

GPIO_PinState Sensor_Read_Digital(GPIO_TypeDef *port, uint16_t pin)
{
    return HAL_GPIO_ReadPin(port, pin);
}

void Sensor_Set_Alert(GPIO_TypeDef *port, uint16_t pin, GPIO_PinState state)
{
    HAL_GPIO_WritePin(port, pin, state);
}
