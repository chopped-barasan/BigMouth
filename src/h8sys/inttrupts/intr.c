/**
 * @file intr.c
 * @author 20eo0125 松原広樹
 * @brief タイマー割り込みしか書いてないです。
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "intr.h"

// ITU0 割り込みハンドラ
static void (*imia0_handler)(void) = 0;
static void (*imib0_handler)(void) = 0;
static void (*ovi0_handler)(void) = 0;
// ITU1 割り込みハンドラ
static void (*imia1_handler)(void) = 0;
static void (*imib1_handler)(void) = 0;
static void (*ovi1_handler)(void) = 0;
// ITU2 割り込みハンドラ
static void (*imia2_handler)(void) = 0;
static void (*imib2_handler)(void) = 0;
static void (*ovi2_handler)(void) = 0;
// TMR0 割り込みハンドラ
static void (*cmia0_handler)(void) = 0;
static void (*cmib0_handler)(void) = 0;
static void (*tovi0_handler)(void) = 0;
// TMR1 割り込みハンドラ
static void (*cmia1_handler)(void) = 0;
static void (*cmib1_handler)(void) = 0;
static void (*tovi1_handler)(void) = 0;
// TMR2 割り込みハンドラ
static void (*cmia2_handler)(void) = 0;
static void (*cmib2_handler)(void) = 0;
static void (*tovi2_handler)(void) = 0;
// TMR3 割り込みハンドラ
static void (*cmia3_handler)(void) = 0;
static void (*cmib3_handler)(void) = 0;
static void (*tovi3_handler)(void) = 0;

// IMFA0による割り込みの関数登録
inline void set_imia0_handler(void (*handler)(void)) {
  imia0_handler = handler;
}
// IMFB0による割り込みの関数登録
inline void set_imib0_handler(void (*handler)(void)) {
  imib0_handler = handler;
}
// OVF0による割り込みの関数登録
inline void set_ovi0_handler(void (*handler)(void)) {
  ovi0_handler = handler;
}

// IMFA1による割り込みの関数登録
inline void set_imia1_handler(void (*handler)(void)) {
  imia1_handler = handler;
}
// IMFB1による割り込みの関数登録
inline void set_imib1_handler(void (*handler)(void)) {
  imib1_handler = handler;
}
// OVF1による割り込みの関数登録
inline void set_ovi1_handler(void (*handler)(void)) {
  ovi1_handler = handler;
}

// IMFA2による割り込みの関数登録
inline void set_imia2_handler(void (*handler)(void)) {
  imia2_handler = handler;
}
// IMFB2による割り込みの関数登録
inline void set_imib2_handler(void (*handler)(void)) {
  imib2_handler = handler;
}
// OVF2による割り込みの関数登録
inline void set_ovi2_handler(void (*handler)(void)) {
  ovi2_handler = handler;
}

// CMFA0による割り込みの関数登録
inline void set_cmia0_handler(void (*handler)(void)) {
  cmia0_handler = handler;
}
// CMFB0による割り込みの関数登録
inline void set_cmib0_handler(void (*handler)(void)) {
  cmib0_handler = handler;
}
// OVF0による割り込みの関数登録
inline void set_tovi0_handler(void (*handler)(void)) {
  tovi0_handler = handler;
}

// CMFA1による割り込みの関数登録
inline void set_cmia1_handler(void (*handler)(void)) {
  cmia1_handler = handler;
}
// CMFB1による割り込みの関数登録
inline void set_cmib1_handler(void (*handler)(void)) {
  cmib1_handler = handler;
}
// OVF1による割り込みの関数登録
inline void set_tovi1_handler(void (*handler)(void)) {
  tovi1_handler = handler;
}

// CMFA2による割り込みの関数登録
inline void set_cmia2_handler(void (*handler)(void)) {
  cmia2_handler = handler;
}
// CMFB2による割り込みの関数登録
inline void set_cmib2_handler(void (*handler)(void)) {
  cmib2_handler = handler;
}
// OVF2による割り込みの関数登録
inline void set_tovi2_handler(void (*handler)(void)) {
  tovi2_handler = handler;
}

// CMFA3による割り込みの関数登録
inline void set_cmia3_handler(void (*handler)(void)) {
  cmia3_handler = handler;
}
// CMFB3による割り込みの関数登録
inline void set_cmib3_handler(void (*handler)(void)) {
  cmib3_handler = handler;
}
// OVF3による割り込みの関数登録
inline void set_tovi3_handler(void (*handler)(void)) {
  tovi3_handler = handler;
}

// ITU0 (コンペアマッチ/インプットキャプチャA0)
void int_imia0(void) {
  DI;
  imia0_handler();
  *(volatile unsigned char*)(0xFFFF64) &= ~(0b00000001);
  EI;
}
// ITU0 (コンペアマッチ/インプットキャプチャB0)
void int_imib0(void) {
  DI;
  imib0_handler();
  *(volatile unsigned char*)(0xFFFF65) &= ~(0b00000001);
  EI;
}
// ITU0 (オーバフロー0)
void int_ovi0(void) {
  DI;
  ovi0_handler();
  *(volatile unsigned char*)(0xFFFF66) &= ~(0b00000001);
  EI;
}
// ITU1 (コンペアマッチ/インプットキャプチャA1)
void int_imia1(void) {
  DI;
  imia1_handler();
  *(volatile unsigned char*)(0xFFFF64) &= ~(0b00000010);
  EI;
}
// ITU1 (コンペアマッチ/インプットキャプチャB1)
void int_imib1(void) {
  DI;
  imib1_handler();
  *(volatile unsigned char*)(0xFFFF65) &= ~(0b00000010);
  EI;
}
// ITU1 (オーバフロー1)
void int_ovi1(void) {
  DI;
  ovi1_handler();
  *(volatile unsigned char*)(0xFFFF66) &= ~(0b00000010);
  EI;
}
// ITU2 (コンペアマッチ/インプットキャプチャA2)
void int_imia2(void) {
  DI;
  imia2_handler();
  *(volatile unsigned char*)(0xFFFF64) &= ~(0b00000100);
  EI;
}
// ITU2 (コンペアマッチ/インプットキャプチャB2)
void int_imib2(void) {
  DI;
  imib2_handler();
  *(volatile unsigned char*)(0xFFFF65) &= ~(0b00000100);
  EI;
}
// ITU2 (オーバフロー2)
void int_ovi2(void) {
  DI;
  ovi2_handler();
  *(volatile unsigned char*)(0xFFFF66) &= ~(0b00000100);
  EI;
}
// TMR0 (コンペアマッチA0)
void int_cmia0(void) {
  DI;
  cmia0_handler();
  *(volatile unsigned char*)(0xFFFF82) &= ~(0b01000000);
  EI;
}
// TMR0 (コンペアマッチB0)
void int_cmib0(void) {
  DI;
  cmib0_handler();
  *(volatile unsigned char*)(0xFFFF82) &= ~(0b10000000);
  EI;
}
// TMR1 (コンペアマッチA1/B1)
void int_cmiab1(void) {
  DI;
  unsigned char temp = *(volatile unsigned char*)(0xFFFF83) & 0b11000000;
  if (temp == 0b01000000) {
    // CMFA1による割り込み
    cmia1_handler();
  } else if (temp == 0b10000000) {
    // CMFB1による割り込み
    cmib1_handler();
  } else {
    cmia1_handler();
    cmib1_handler();
  }
  *(volatile unsigned char*)(0xFFFF83) &= ~(0b11000000);
  EI;
}
// TMR0,1 (オーバフロー0/1)
void int_tovi01(void) {
  DI;
  if ((*(volatile unsigned char*)(0xFFFF82) & 0b00100000) == 0b00100000) {
    // OVF0による割り込み
    tovi0_handler();
  } else if ((*(volatile unsigned char*)(0xFFFF83) & 0b00100000) ==
             0b00100000) {
    // OVF1による割り込み
    tovi1_handler();
  } else {
    // nothing to do
  }
  *(volatile unsigned char*)(0xFFFF82) &= ~(0b00100000);
  *(volatile unsigned char*)(0xFFFF83) &= ~(0b00100000);
  EI;
}

// TMR2 (コンペアマッチA2)
void int_cmia2(void) {
  DI;
  cmia2_handler();
  *(volatile unsigned char*)(0xFFFF92) &= ~(0b01000000);
  EI;
}
// TMR2 (コンペアマッチB2)
void int_cmib2(void) {
  DI;
  cmib2_handler();
  *(volatile unsigned char*)(0xFFFF92) &= ~(0b10000000);
  EI;
}
// TMR3 (コンペアマッチA3/B3)
void int_cmiab3(void) {
  DI;
  unsigned char temp = *(volatile unsigned char*)(0xFFFF93) & 0b11000000;
  if (temp == 0b01000000) {
    // CMFA3による割り込み
    cmia3_handler();
  } else if (temp == 0b10000000) {
    // CMFB3による割り込み
    cmib3_handler();
  } else {
    cmia3_handler();
    cmib3_handler();
  }
  *(volatile unsigned char*)(0xFFFF93) &= ~(0b11000000);
  EI;
}
// TMR2,3 (オーバフロー2/3)
void int_tovi23(void) {
  DI;
  if ((*(volatile unsigned char*)(0xFFFF92) & 0b00100000) == 0b00100000) {
    // OVF2による割り込み
    tovi2_handler();
  } else if ((*(volatile unsigned char*)(0xFFFF93) & 0b00100000) ==
             0b00100000) {
    // OVF3による割り込み
    tovi3_handler();
  } else {
    // nothing to do
  }
  *(volatile unsigned char*)(0xFFFF92) &= ~(0b00100000);
  *(volatile unsigned char*)(0xFFFF93) &= ~(0b00100000);
  EI;
}
