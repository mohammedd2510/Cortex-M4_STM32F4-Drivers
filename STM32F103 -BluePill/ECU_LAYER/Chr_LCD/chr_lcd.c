/*
 * chr_lcd.c
 *
 *  Created on: Nov 2, 2023
 *      Author: mohop
 */
#include "chr_lcd.h"

static Std_ReturnType lcd_send_4bits(const chr_lcd_4bit_t *lcd, uint8_t _data_command );
static Std_ReturnType lcd_4bit_send_enable_signal(const chr_lcd_4bit_t *lcd);
static Std_ReturnType lcd_8bit_send_enable_signal(const chr_lcd_8bit_t *lcd);
static Std_ReturnType lcd_8bit_set_cursor(const chr_lcd_8bit_t *lcd , uint8_t row , uint8_t column);
static Std_ReturnType lcd_4bit_set_cursor(const chr_lcd_4bit_t *lcd , uint8_t row , uint8_t column);
/**
 *
 * @param lcd
 * @return
 */
#include "stm32f1xx.h"


Std_ReturnType lcd_4bit_initialize (const chr_lcd_4bit_t *lcd){
    Std_ReturnType ret=E_OK;
    if(lcd==NULL)
    {
        ret=E_NOT_OK;
    }
    else
    {
        ret=lcd_4bit_send_command(lcd,_LCD_8BIT_MODE_2times);
        delay_us(150);
        ret=lcd_4bit_send_command(lcd,_LCD_8BIT_MODE_THEN_4BIT_MODE);
    	ret=lcd_4bit_send_command(lcd,_LCD_4BIT_MODE_2_LINE);
    	ret=lcd_4bit_send_command(lcd,_LCD_4BIT_MODE_2_LINE);
    	HAL_Delay(1);
    	ret=lcd_4bit_send_command(lcd,_LCD_CLEAR);
    	HAL_Delay(1);
    	ret=lcd_4bit_send_command(lcd,_LCD_ENTRY_MODE_INC_SHIFT_OFF);
    	ret=lcd_4bit_send_command(lcd,_LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
        }
    return ret;
}
/**
 *
 * @param lcd
 * @param command
 * @return
 */
Std_ReturnType lcd_4bit_send_command (const chr_lcd_4bit_t *lcd, uint8_t command){
    Std_ReturnType ret=E_OK;
    if(lcd==NULL){
        ret=E_NOT_OK;
    }
    else{
        HAL_GPIO_WritePin(lcd->lcd_rs_port, lcd->lcd_rs_pin, GPIO_PIN_RESET);
        ret=lcd_send_4bits(lcd, command >> 4);
        ret=lcd_4bit_send_enable_signal(lcd);
        ret=lcd_send_4bits(lcd, command);
        ret=lcd_4bit_send_enable_signal(lcd);
        }
    return ret;
}
/**
 *
 * @param lcd
 * @param data
 * @return
 */
Std_ReturnType lcd_4bit_send_char_data (const chr_lcd_4bit_t *lcd, uint8_t data){
    Std_ReturnType ret=E_OK;
    if(lcd==NULL){
        ret=E_NOT_OK;
    }
    else{
    	HAL_GPIO_WritePin(lcd->lcd_rs_port, lcd->lcd_rs_pin, GPIO_PIN_SET);
        ret=lcd_send_4bits(lcd, data >> 4);
        ret=lcd_4bit_send_enable_signal(lcd);
        ret=lcd_send_4bits(lcd, data);
        ret=lcd_4bit_send_enable_signal(lcd);
        }
    return ret;
}
/**
 *
 * @param lcd
 * @param row
 * @param column
 * @param data
 * @return
 */
Std_ReturnType lcd_4bit_send_char_data_pos (const chr_lcd_4bit_t *lcd ,uint8_t row ,uint8_t column , uint8_t data){
    Std_ReturnType ret=E_OK;
    if(lcd==NULL){
        ret=E_NOT_OK;
    }
    else{
        lcd_4bit_set_cursor(lcd,row,column);
        lcd_4bit_send_char_data(lcd,data);
        }
    return ret;
}
/**
 *
 * @param lcd
 * @param str
 * @return
 */
Std_ReturnType lcd_4bit_send_string (const chr_lcd_4bit_t *lcd, uint8_t *str){
    Std_ReturnType ret=E_OK;
    if(lcd==NULL){
        ret=E_NOT_OK;
    }
    else{
        while(*str){
            ret=lcd_4bit_send_char_data(lcd,*str++);
        }
        }
    return ret;
}
/**
 *
 * @param lcd
 * @param row
 * @param column
 * @param str
 * @return
 */
Std_ReturnType lcd_4bit_send_string_pos (const chr_lcd_4bit_t *lcd ,uint8_t row ,uint8_t column , uint8_t *str){
    Std_ReturnType ret=E_OK;
    if(lcd==NULL){
        ret=E_NOT_OK;
    }
    else{
       lcd_4bit_set_cursor(lcd,row,column);
        while(*str){
            ret=lcd_4bit_send_char_data(lcd,*str++);
        }
        }
    return ret;
}
/**
 *
 * @param lcd
 * @param row
 * @param column
 * @param _chr
 * @param mem_pos
 * @return
 */
Std_ReturnType lcd_4bit_send_custom_char(const chr_lcd_4bit_t *lcd ,uint8_t row ,uint8_t column ,
                                         const uint8_t _chr[],uint8_t mem_pos){
     Std_ReturnType ret=E_OK;
    uint8_t lcd_counter=ZERO_INIT;
    if(lcd==NULL){
        ret=E_NOT_OK;
    }
    else{
        ret=lcd_4bit_send_command(lcd,(_LCD_CGRAM_START+(8*mem_pos)));
        for(lcd_counter=ZERO_INIT;lcd_counter<8;lcd_counter++){
           ret= lcd_4bit_send_char_data(lcd,_chr[lcd_counter]);
        }
        ret=lcd_4bit_send_char_data_pos(lcd,row,column,mem_pos);
        }
    return ret;

}

/**
 *
 * @param lcd
 * @return
 */
Std_ReturnType lcd_8bit_initialize (const chr_lcd_8bit_t *lcd){
    Std_ReturnType ret=E_OK;
    if(lcd==NULL){
        ret=E_NOT_OK;
    }
    else{
        HAL_Delay(20);
        ret=lcd_8bit_send_command(lcd,_LCD_8BIT_MODE_2_LINE);
        HAL_Delay(5);
        ret=lcd_8bit_send_command(lcd,_LCD_8BIT_MODE_2_LINE);
        delay_us(150);
        ret=lcd_8bit_send_command(lcd,_LCD_8BIT_MODE_2_LINE);
        ret=lcd_8bit_send_command(lcd,_LCD_8BIT_MODE_2_LINE);
        ret=lcd_8bit_send_command(lcd,_LCD_CLEAR);
        ret=lcd_8bit_send_command(lcd,_LCD_ENTRY_MODE_INC_SHIFT_OFF);
        ret=lcd_8bit_send_command(lcd,_LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);


        }
    return ret;
}
/**
 *
 * @param lcd
 * @param command
 * @return
 */
Std_ReturnType lcd_8bit_send_command (const chr_lcd_8bit_t *lcd, uint8_t command){
    Std_ReturnType ret=E_OK;
     uint8_t l_pins_counter=ZERO_INIT;
    if(lcd==NULL){
        ret=E_NOT_OK;
    }
    else{
    	HAL_GPIO_WritePin(lcd->lcd_rs_port, lcd->lcd_rs_pin, GPIO_PIN_RESET);
        for(l_pins_counter=ZERO_INIT;l_pins_counter<8;l_pins_counter++){
        	HAL_GPIO_WritePin(lcd->lcd_data_port[l_pins_counter], lcd->lcd_data_pin[l_pins_counter], ( command >> l_pins_counter ) & (uint8_t)0x01);
        }
        lcd_8bit_send_enable_signal(lcd);

        }
    return ret;
}
/**
 *
 * @param lcd
 * @param data
 * @return
 */
Std_ReturnType lcd_8bit_send_char_data (const chr_lcd_8bit_t *lcd, uint8_t data){
     Std_ReturnType ret=E_OK;
     uint8_t l_pins_counter=ZERO_INIT;
    if(lcd==NULL){
        ret=E_NOT_OK;
    }
    else{
    	HAL_GPIO_WritePin(lcd->lcd_rs_port, lcd->lcd_rs_pin, GPIO_PIN_SET);
        for(l_pins_counter=ZERO_INIT;l_pins_counter<8;l_pins_counter++){
        	HAL_GPIO_WritePin(lcd->lcd_data_port[l_pins_counter], lcd->lcd_data_pin[l_pins_counter], ( data >> l_pins_counter ) & (uint8_t)0x01);
        }
        lcd_8bit_send_enable_signal(lcd);
        }
    return ret;
}
/**
 *
 * @param lcd
 * @param row
 * @param column
 * @param data
 * @return
 */
Std_ReturnType lcd_8bit_send_char_data_pos (const chr_lcd_8bit_t *lcd ,uint8_t row ,uint8_t column , uint8_t data){
    Std_ReturnType ret=E_OK;
    if(lcd==NULL){
        ret=E_NOT_OK;
    }
    else{
        lcd_8bit_set_cursor(lcd,row,column);
        lcd_8bit_send_char_data(lcd,data);
        }
    return ret;
}
/**
 *
 * @param lcd
 * @param str
 * @return
 */
Std_ReturnType lcd_8bit_send_string (const chr_lcd_8bit_t *lcd, uint8_t *str){
    Std_ReturnType ret=E_OK;
    if(lcd==NULL){
        ret=E_NOT_OK;
    }
    else{
        while(*str){
            ret=lcd_8bit_send_char_data(lcd,*str++);
        }
        }
    return ret;
}
/**
 *
 * @param lcd
 * @param row
 * @param column
 * @param str
 * @return
 */
Std_ReturnType lcd_8bit_send_string_pos (const chr_lcd_8bit_t *lcd ,uint8_t row ,uint8_t column , uint8_t *str){
    Std_ReturnType ret=E_OK;
    if(lcd==NULL){
        ret=E_NOT_OK;
    }
    else{
        lcd_8bit_set_cursor(lcd,row,column);
        while(*str){
            ret=lcd_8bit_send_char_data(lcd,*str++);
        }
        }
    return ret;
}
/**
 *
 * @param lcd
 * @param row
 * @param column
 * @param _chr
 * @param mem_pos
 * @return
 */
Std_ReturnType lcd_8bit_send_custom_char(const chr_lcd_8bit_t *lcd ,uint8_t row ,uint8_t column ,
                                         const uint8_t _chr[],uint8_t mem_pos){
    Std_ReturnType ret=E_OK;
    uint8_t lcd_counter=ZERO_INIT;
    if(lcd==NULL){
        ret=E_NOT_OK;
    }
    else{
        ret=lcd_8bit_send_command(lcd,(_LCD_CGRAM_START+(8*mem_pos)));
        for(lcd_counter=ZERO_INIT;lcd_counter<8;lcd_counter++){
           ret= lcd_8bit_send_char_data(lcd,_chr[lcd_counter]);
        }
        ret=lcd_8bit_send_char_data_pos(lcd,row,column,mem_pos);
        }
    return ret;

}
/**
 *
 * @param value
 * @param str
 */
Std_ReturnType convert_uint8_t_to_string(uint8_t value , uint8_t *str){
   Std_ReturnType ret=E_OK;
   uint8_t Temp_str[4]={0};
   uint8_t cnt =0;
    if(str==NULL){
        ret=E_NOT_OK;
    }
    else{
        memset(str,' ',4);
        sprintf(Temp_str,"%i",value);
        while (Temp_str[cnt] != '\0'){
            str[cnt] = Temp_str [cnt];
            cnt++;
        }
        str[3] = '\0';
        }
    return ret;
}
/**
 *
 * @param value
 * @param str
 */
Std_ReturnType convert_uint16_t_to_string(uint16_t value , uint8_t *str){
    Std_ReturnType ret=E_OK;
   uint8_t Temp_str[6]={0};
   uint8_t cnt =0;
    if(str==NULL){
        ret=E_NOT_OK;
    }
    else{
        memset(str,' ',6);
        sprintf(Temp_str,"%i",value);
        while (Temp_str[cnt] != '\0'){
            str[cnt] = Temp_str [cnt];
            cnt++;
        }
        str[5] = '\0';
        }
    return ret;
}
/**
 *
 * @param value
 * @param str
 */
Std_ReturnType convert_uint32_t_to_string(uint32_t value , uint8_t *str){
   Std_ReturnType ret=E_OK;
   uint8_t Temp_str[11]={0};
   uint8_t cnt =0;
    if(str==NULL){
        ret=E_NOT_OK;
    }
    else{
        memset(str,' ',11);
        sprintf(Temp_str,"%i",value);
        while (Temp_str[cnt] != '\0'){
            str[cnt] = Temp_str [cnt];
            cnt++;
        }
        str[10] = '\0';
        }
    return ret;
}
/**
 *
 * @param lcd
 * @param _data_command
 * @return
 */
static Std_ReturnType lcd_send_4bits(const chr_lcd_4bit_t *lcd, uint8_t _data_command ){
    Std_ReturnType ret=E_OK;
    if(lcd==NULL){
        ret=E_NOT_OK;
    }
    else{
    	HAL_GPIO_WritePin(lcd->lcd_data_port[0], lcd->lcd_data_pin[0], ( _data_command >> 0 ) & (uint8_t)0x01);
    	HAL_GPIO_WritePin(lcd->lcd_data_port[1], lcd->lcd_data_pin[1], ( _data_command >> 1 ) & (uint8_t)0x01);
    	HAL_GPIO_WritePin(lcd->lcd_data_port[2], lcd->lcd_data_pin[2], ( _data_command >> 2 ) & (uint8_t)0x01);
    	HAL_GPIO_WritePin(lcd->lcd_data_port[3], lcd->lcd_data_pin[3], ( _data_command >> 3 ) & (uint8_t)0x01);
        }
    return ret;
}
static Std_ReturnType lcd_4bit_send_enable_signal(const chr_lcd_4bit_t *lcd){
    Std_ReturnType ret=E_OK;
    if(lcd==NULL){
        ret=E_NOT_OK;
    }
    else{
    	HAL_GPIO_WritePin(lcd->lcd_en_port, lcd->lcd_en_pin, GPIO_PIN_SET);
        delay_us(5);
        HAL_GPIO_WritePin(lcd->lcd_en_port, lcd->lcd_en_pin, GPIO_PIN_RESET);
        delay_us(5);
        }
    return ret;
}
static Std_ReturnType lcd_8bit_send_enable_signal(const chr_lcd_8bit_t *lcd){
    Std_ReturnType ret=E_OK;
    if(lcd==NULL){
        ret=E_NOT_OK;
    }
    else{
    	HAL_GPIO_WritePin(lcd->lcd_en_port, lcd->lcd_en_pin, GPIO_PIN_SET);
        delay_us(5);
        HAL_GPIO_WritePin(lcd->lcd_en_port, lcd->lcd_en_pin, GPIO_PIN_RESET);
        }
    return ret;
}
static Std_ReturnType lcd_8bit_set_cursor(const chr_lcd_8bit_t *lcd , uint8_t row , uint8_t column){
    Std_ReturnType ret=E_OK;
    if(lcd==NULL){
        ret=E_NOT_OK;
    }
    else{
        column--;
        switch (row){
            case ROW1 : ret=lcd_8bit_send_command(lcd,0x80+column);break;
            case ROW2 : ret=lcd_8bit_send_command(lcd,0xC0+column);break;
            case ROW3 : ret=lcd_8bit_send_command(lcd,0x94+column);break;
            case ROW4 : ret=lcd_8bit_send_command(lcd,0xD4+column);break;
            default:    ret=E_NOT_OK;break;
        }
        }
    return ret;
}
static Std_ReturnType lcd_4bit_set_cursor(const chr_lcd_4bit_t *lcd , uint8_t row , uint8_t column){
    Std_ReturnType ret=E_OK;
    if(lcd==NULL){
        ret=E_NOT_OK;
    }
    else{
        column--;
        switch (row){
            case ROW1 : ret=lcd_4bit_send_command(lcd,0x80+column);break;
            case ROW2 : ret=lcd_4bit_send_command(lcd,0xC0+column);break;
            case ROW3 : ret=lcd_4bit_send_command(lcd,0x94+column);break;
            case ROW4 : ret=lcd_4bit_send_command(lcd,0xD4+column);break;
            default:    ret=E_NOT_OK;break;
        }
        }
    return ret;
}