/********************************** (C) COPYRIGHT *******************************
 * File Name          : KEYBOARD.h
 * Author             : ChnMasterOG
 * Version            : V1.1
 * Date               : 2021/12/23
 * Description        : 机械键盘驱动头文件
 *******************************************************************************/

#ifndef __KEYBOARD_H
    #define __KEYBOARD_H

    #include "CH58x_common.h"

    #define Row_GPIO_(x)    GPIOB_ ## x
    #define Colum_GPIO_(x)  GPIOA_ ## x

    #define ROW_SIZE        6    // 键盘行数 - 其它键盘布局需修改此处
    #define COL_SIZE        14   // 键盘列数 - 其它键盘布局需修改此处

    #define MAX_PRESS_COUNT 15   // 8个特殊键+6个一般键+1个Fn键
    #define MAX_CHANGETIMES 24   // 按下Capslock改变键盘布局检测次数
    #define CAPSLOCK_HOLDING_TIMES  4 // Capslock按下持续时间

    //special
    #define KEY_None    0x00
    #define KEY_Fn      0xFF

    //A~Z
    #define KEY_A   0x04
    #define KEY_B   0x05
    #define KEY_C   0x06
    #define KEY_D   0x07
    #define KEY_E   0x08
    #define KEY_F   0x09
    #define KEY_G   0x0A
    #define KEY_H   0x0B
    #define KEY_I   0x0C
    #define KEY_J   0x0D
    #define KEY_K   0x0E
    #define KEY_L   0x0F
    #define KEY_M   0x10
    #define KEY_N   0x11
    #define KEY_O   0x12
    #define KEY_P   0x13
    #define KEY_Q   0x14
    #define KEY_R   0x15
    #define KEY_S   0x16
    #define KEY_T   0x17
    #define KEY_U   0x18
    #define KEY_V   0x19
    #define KEY_W   0x1A
    #define KEY_X   0x1B
    #define KEY_Y   0x1C
    #define KEY_Z   0x1D

    //0~9
    #define KEY_1   0x1E    //!
    #define KEY_2   0x1F    //@
    #define KEY_3   0x20    //#
    #define KEY_4   0x21    //$
    #define KEY_5   0x22    //%
    #define KEY_6   0x23    //^
    #define KEY_7   0x24    //&
    #define KEY_8   0x25    //*
    #define KEY_9   0x26    //(
    #define KEY_0   0x27    //)

    //others
    #define KEY_ENTER       0x28
    #define KEY_ESCAPE      0x29
    #define KEY_BACKSPACE   0x2A
    #define KEY_TAB         0x2B
    #define KEY_SPACEBAR    0x2C
    #define KEY_Subtraction 0x2D    //- or _
    #define KEY_Equal       0x2E    //= or +
    #define KEY_LSbrackets  0x2F    //[ or {
    #define KEY_RSbrackets  0x30    //] or }
    #define KEY_Backslash   0x31
    #define KEY_NonUS_WS    0x32    //\ or |
    #define KEY_Semicolon   0x33    //; or :
    #define KEY_Quotation   0x34    //' or "
    #define KEY_GraveAccent 0x35    //` or ~
    #define KEY_Comma       0x36    //, or <
    #define KEY_FullStop    0x37    //. or >
    #define KEY_Slash       0x38    /// or ?
    #define KEY_CapsLock    0x39
    #define KEY_F1          0x3A
    #define KEY_F2          0x3B
    #define KEY_F3          0x3C
    #define KEY_F4          0x3D
    #define KEY_F5          0x3E
    #define KEY_F6          0x3F
    #define KEY_F7          0x40
    #define KEY_F8          0x41
    #define KEY_F9          0x42
    #define KEY_F10         0x43
    #define KEY_F11         0x44
    #define KEY_F12         0x45

    #define KEY_PrintScreen 0x46
    #define KEY_ScrollLock  0x47
    #define KEY_Pause       0x48
    #define KEY_Insert      0x49
    #define KEY_Home        0x4A
    #define KEY_PageUp      0x4B
    #define KEY_Delete      0x4C
    #define KEY_End         0x4D
    #define KEY_PageDown    0x4E
    #define KEY_RightArrow  0x4F    //→
    #define KEY_LeftArrow   0x50    //←
    #define KEY_DownArrow   0x51    //↓
    #define KEY_UpArrow     0x52    //↑

    //特殊
    #define KEY_Undo        0x7A
    #define KEY_Cut         0x7B
    #define KEY_Copy        0x7C
    #define KEY_Paste       0x7D

    //功能键
    #define KEY_LeftCTRL    0xE0
    #define KEY_LeftShift   0xE1
    #define KEY_LeftAlt     0xE2
    #define KEY_LeftGUI     0xE3
    #define KEY_RightCTRL   0xE4
    #define KEY_RightShift  0xE5
    #define KEY_RightAlt    0xE6
    #define KEY_RightGUI    0xE7

    //矮轴
    #define KEY_MouseL      0xF0
    #define KEY_MouseR      0xF1
    #define KEY_MouseM      0xF2

    //Fn功能
    #define Fn_Mode_None                  0x00
    #define Fn_Mode_Reset                 0x01
    #define Fn_Mode_ChangeKey             0x02
    #define Fn_Mode_JumpBoot              0xB0
    #define Fn_Mode_SoftReset             0xB1
    #define Fn_Mode_VolumeUp              0xC0
    #define Fn_Mode_VolumeDown            0xC1
    #define Fn_Mode_DisEnableBLE          0xD0
    #define Fn_Mode_DisEnableTP           0xD1
    #define Fn_Mode_PriorityUSBorBLE      0xE0
    #define Fn_Mode_SelectDevice1         0xE1
    #define Fn_Mode_SelectDevice2         0xE2
    #define Fn_Mode_SelectDevice3         0xE3
    #define Fn_Mode_SelectDevice4         0xE4
    #define Fn_Mode_SelectDevice5         0xE5
    #define Fn_Mode_SelectDevice6         0xE6  // Mode SaveAddr-SelectDevice6需连续
    #define Fn_Mode_LED_Style1            0xF0
    #define Fn_Mode_LED_Style2            0xF1
    #define Fn_Mode_LED_Style3            0xF2
    #define Fn_Mode_LED_Style4            0xF3
    #define Fn_Mode_LED_Style5            0xF4
    #define Fn_Mode_PaintedEgg            0xFE
    #define Fn_Mode_GiveUp                0xFF

    typedef union {
        struct {
            unsigned char LeftCTRL : 1;
            unsigned char LeftShift : 1;
            unsigned char LeftAlt : 1;
            unsigned char LeftGUI : 1;
            unsigned char RightCTRL : 1;
            unsigned char RightShift : 1;
            unsigned char RightAlt : 1;
            unsigned char RightGUI : 1;
            unsigned char Reserved : 8;
            unsigned char Key1 : 8;
            unsigned char Key2 : 8;
            unsigned char Key3 : 8;
            unsigned char Key4 : 8;
            unsigned char Key5 : 8;
            unsigned char Key6 : 8;
            };
        uint8_t data[8];
    }Keyboardstate;

    extern uint8_t KEYBOARD_data_ready, KEYBOARD_mouse_ready, LED_Change_flag;
    extern Keyboardstate* const Keyboarddat;
    extern BOOL PaintedEggMode;

    UINT8 FLASH_Write_KeyArray( void );
    UINT8 KEYBOARD_Custom_Function( void );
    void KEYBOARD_Init( void );
    void KEYBOARD_Detection( void );
    uint8_t KEYBOARD_EnterPasskey( uint32_t* key );

#endif
