/**
 * @file intr.h
 * @author 20eo0125 松原広樹
 * @brief タイマー割り込みしか書いてないです。
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <3069.h>

// // ITU0 割り込みハンドラ
// static void (*imia0_handler)(void);
// static void (*imib0_handler)(void);
// static void (*ovi0_handler)(void);
// // ITU1 割り込みハンドラ
// static void (*imia1_handler)(void);
// static void (*imib1_handler)(void);
// static void (*ovi1_handler)(void);
// // ITU2 割り込みハンドラ
// static void (*imia2_handler)(void);
// static void (*imib2_handler)(void);
// static void (*ovi2_handler)(void);
// // TMR0 割り込みハンドラ
// static void (*cmia0_handler)(void);
// static void (*cmib0_handler)(void);
// static void (*tovi0_handler)(void);
// // TMR1 割り込みハンドラ
// static void (*cmia1_handler)(void);
// static void (*cmib1_handler)(void);
// static void (*tovi1_handler)(void);
// // TMR2 割り込みハンドラ
// static void (*cmia2_handler)(void);
// static void (*cmib2_handler)(void);
// static void (*tovi2_handler)(void);
// // TMR3 割り込みハンドラ
// static void (*cmia3_handler)(void);
// static void (*cmib3_handler)(void);
// static void (*tovi3_handler)(void);

void set_imia0_handler(void (*handler)(void));
void set_imib0_handler(void (*handler)(void));
void set_ovi0_handler(void (*handler)(void));

void set_imia1_handler(void (*handler)(void));
void set_imib1_handler(void (*handler)(void));
void set_ovi1_handler(void (*handler)(void));

void set_imia2_handler(void (*handler)(void));
void set_imib2_handler(void (*handler)(void));
void set_ovi2_handler(void (*handler)(void));

void set_cmia0_handler(void (*handler)(void));
void set_cmib0_handler(void (*handler)(void));
void set_tovi0_handler(void (*handler)(void));

void set_cmia1_handler(void (*handler)(void));
void set_cmib1_handler(void (*handler)(void));
void set_tovi1_handler(void (*handler)(void));

void set_cmia2_handler(void (*handler)(void));
void set_cmib2_handler(void (*handler)(void));
void set_tovi2_handler(void (*handler)(void));

void set_cmia3_handler(void (*handler)(void));
void set_cmib3_handler(void (*handler)(void));
void set_tovi3_handler(void (*handler)(void));

// // IMFA0による割り込みの関数登録
// static inline void set_imia0_handler(void (*handler)(void)) {
//   imia0_handler = handler;
// }
// // IMFB0による割り込みの関数登録
// static inline void set_imib0_handler(void (*handler)(void)) {
//   imib0_handler = handler;
// }
// // OVF0による割り込みの関数登録
// static inline void set_ovi0_handler(void (*handler)(void)) {
//   ovi0_handler = handler;
// }

// // IMFA1による割り込みの関数登録
// static inline void set_imia1_handler(void (*handler)(void)) {
//   imia1_handler = handler;
// }
// // IMFB1による割り込みの関数登録
// static inline void set_imib1_handler(void (*handler)(void)) {
//   imib1_handler = handler;
// }
// // OVF1による割り込みの関数登録
// static inline void set_ovi1_handler(void (*handler)(void)) {
//   ovi1_handler = handler;
// }

// // IMFA2による割り込みの関数登録
// static inline void set_imia2_handler(void (*handler)(void)) {
//   imia2_handler = handler;
// }
// // IMFB2による割り込みの関数登録
// static inline void set_imib2_handler(void (*handler)(void)) {
//   imib2_handler = handler;
// }
// // OVF2による割り込みの関数登録
// static inline void set_ovi2_handler(void (*handler)(void)) {
//   ovi2_handler = handler;
// }

// // CMFA0による割り込みの関数登録
// static inline void set_cmia0_handler(void (*handler)(void)) {
//   cmia0_handler = handler;
// }
// // CMFB0による割り込みの関数登録
// static inline void set_cmib0_handler(void (*handler)(void)) {
//   cmib0_handler = handler;
// }
// // OVF0による割り込みの関数登録
// static inline void set_tovi0_handler(void (*handler)(void)) {
//   tovi0_handler = handler;
// }

// // CMFA1による割り込みの関数登録
// static inline void set_cmia1_handler(void (*handler)(void)) {
//   cmia1_handler = handler;
// }
// // CMFB1による割り込みの関数登録
// static inline void set_cmib1_handler(void (*handler)(void)) {
//   cmib1_handler = handler;
// }
// // OVF1による割り込みの関数登録
// static inline void set_tovi1_handler(void (*handler)(void)) {
//   tovi1_handler = handler;
// }

// // CMFA2による割り込みの関数登録
// static inline void set_cmia2_handler(void (*handler)(void)) {
//   cmia2_handler = handler;
// }
// // CMFB2による割り込みの関数登録
// static inline void set_cmib2_handler(void (*handler)(void)) {
//   cmib2_handler = handler;
// }
// // OVF2による割り込みの関数登録
// static inline void set_tovi2_handler(void (*handler)(void)) {
//   tovi2_handler = handler;
// }

// // CMFA3による割り込みの関数登録
// static inline void set_cmia3_handler(void (*handler)(void)) {
//   cmia3_handler = handler;
// }
// // CMFB3による割り込みの関数登録
// static inline void set_cmib3_handler(void (*handler)(void)) {
//   cmib3_handler = handler;
// }
// // OVF3による割り込みの関数登録
// static inline void set_tovi3_handler(void (*handler)(void)) {
//   tovi3_handler = handler;
// }

/*--------------------------------------------------------------*/
/* 割り込み関数プロトタイプ宣言                                 */
/*--------------------------------------------------------------*/
// NMI割り込み
void int_nmi(void) asm("_int_adi") __attribute__((interrupt_handler));

// IRQ0～5外部割り込み
void int_irq0(void) asm("_int_irq0") __attribute__((interrupt_handler));
void int_irq1(void) asm("_int_irq1") __attribute__((interrupt_handler));
void int_irq2(void) asm("_int_irq2") __attribute__((interrupt_handler));
void int_irq3(void) asm("_int_irq3") __attribute__((interrupt_handler));
void int_irq4(void) asm("_int_irq4") __attribute__((interrupt_handler));
void int_irq5(void) asm("_int_irq5") __attribute__((interrupt_handler));
// ウォッチドッグタイマ (インターバルタイマ)
void int_wovi(void) asm("_int_wovi") __attribute__((interrupt_handler));
// リフレッシュコントローラ (コンペアマッチ)
void int_cmi(void) asm("_int_cmi") __attribute__((interrupt_handler));

// A/D (A/D完了)
void int_adi(void) asm("_int_adi") __attribute__((interrupt_handler));

// ITU0 (コンペアマッチ/インプットキャプチャA0)
void int_imia0(void) asm("_int_imia0") __attribute__((interrupt_handler));
// ITU0 (コンペアマッチ/インプットキャプチャB0)
void int_imib0(void) asm("_int_imib0") __attribute__((interrupt_handler));
// ITU0 (オーバフロー0)
void int_ovi0(void) asm("_int_ovi0") __attribute__((interrupt_handler));

// ITU1 (コンペアマッチ/インプットキャプチャA1)
void int_imia1(void) asm("_int_imia1") __attribute__((interrupt_handler));
// ITU1 (コンペアマッチ/インプットキャプチャB1)
void int_imib1(void) asm("_int_imib1") __attribute__((interrupt_handler));
// ITU1 (オーバフロー1)
void int_ovi1(void) asm("_int_ovi1") __attribute__((interrupt_handler));

// ITU2 (コンペアマッチ/インプットキャプチャA2)
void int_imia2(void) asm("_int_imia2") __attribute__((interrupt_handler));
// ITU2 (コンペアマッチ/インプットキャプチャB2)
void int_imib2(void) asm("_int_imib2") __attribute__((interrupt_handler));
// ITU2 (オーバフロー2)
void int_ovi2(void) asm("_int_ovi2") __attribute__((interrupt_handler));

// TMR0 (コンペアマッチA0)
void int_cmia0(void) asm("_int_cmia0") __attribute__((interrupt_handler));
// TMR0 (コンペアマッチB0)
void int_cmib0(void) asm("_int_cmib0") __attribute__((interrupt_handler));
// TMR1 (コンペアマッチA1/B1)
void int_cmiab1(void) asm("_int_cmiab1") __attribute__((interrupt_handler));
// TMR0,1 (オーバフロー0/1)
void int_tovi01(void) asm("_int_tovi01") __attribute__((interrupt_handler));

// TMR2 (コンペアマッチA2)
void int_cmia2(void) asm("_int_cmia2") __attribute__((interrupt_handler));
// TMR2 (コンペアマッチB2)
void int_cmib2(void) asm("_int_cmib2") __attribute__((interrupt_handler));
// TMR3 (コンペアマッチA3/B3)
void int_cmiab3(void) asm("_int_cmiab3") __attribute__((interrupt_handler));
// TMR2,3 (オーバフロー2/3)
void int_tovi23(void) asm("_int_tovi23") __attribute__((interrupt_handler));

// DMAC0 (DMAC0/DMAC0A転送完了)
void int_dend0a(void) asm("_int_dend0a") __attribute__((interrupt_handler));
// DMAC0 (DMAC0B転送完了)
void int_dend0b(void) asm("_int_dend0b") __attribute__((interrupt_handler));
// DMAC1 (DMAC1/DMAC1A転送完了)
void int_dend1a(void) asm("_int_dend1a") __attribute__((interrupt_handler));
// DMAC1 (DMAC1B転送完了)
void int_dend1b(void) asm("_int_dend1b") __attribute__((interrupt_handler));

// SCI0 (受信エラー0)
void int_eri0(void) asm("_int_eri0") __attribute__((interrupt_handler));
// SCI0 (受信データフル0)
void int_rxi0(void) asm("_int_rxi0") __attribute__((interrupt_handler));
// SCI0 (送信データエンプティ0)
void int_txi0(void) asm("_int_txi0") __attribute__((interrupt_handler));
// SCI0 (送信終了0)
void int_tei0(void) asm("_int_tei0") __attribute__((interrupt_handler));

// SCI1 (受信エラー1)
void int_eri1(void) asm("_int_eri1") __attribute__((interrupt_handler));
// SCI1 (受信データフル1)
void int_rxi1(void) asm("_int_rxi1") __attribute__((interrupt_handler));
// SCI1 (送信データエンプティ1)
void int_txi1(void) asm("_int_txi1") __attribute__((interrupt_handler));
// SCI1 (送信終了1)
void int_tei1(void) asm("_int_tei1") __attribute__((interrupt_handler));

// SCI2 (受信エラー2)
void int_eri2(void) asm("_int_eri2") __attribute__((interrupt_handler));
// SCI2 (受信データフル2)
void int_rxi2(void) asm("_int_rxi2") __attribute__((interrupt_handler));
// SCI2 (送信データエンプティ2)
void int_txi2(void) asm("_int_txi2") __attribute__((interrupt_handler));
// SCI2 (送信終了2)
void int_tei2(void) asm("_int_tei2") __attribute__((interrupt_handler));

#ifdef __cplusplus
}
#endif
