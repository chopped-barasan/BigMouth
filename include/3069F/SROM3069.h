
 #define  sprintf  ((int (*)(char *,const char *,...))0x000209e8)
 #define  sscanf  ((int (*)(char *,const char *,...))0x00020a3e)

 #define  initADC  ((void (*)(void))0x00020476)
 #define  ADconv  ((int(*)(void))0x000204a6)
 
 #define  initDAC  ((void (*)(void))0x000204cc)
 #define  DAconv0  ((void (*)(unsigned))0x000204ea)
 #define  DAconv1  ((void (*)(unsigned))0x000204f8)

 #define  initLCD  ((void (*)(void))0x00020612)
 #define  cls_lcd  ((void (*)(void))0x000205f8)
 #define  lcdprintf  ((void (*)(char *))0x000205d4)
 #define  cur_pos  ((void(*)(char,char))0x0002069e)

 #define  initITU0  ((void (*)(char, char))0x00020000)
 #define  initITU1  ((void (*)(char, char))0x0002004c)
 #define  initITU2  ((void (*)(char, char))0x00020098)

 #define  initPWM0  ((void (*)(unsigned int, unsigned int))0x000200e4)
 #define  initPWM1  ((void (*)(unsigned int, unsigned int))0x00020134)
 #define  initPWM2  ((void (*)(unsigned int, unsigned int))0x00020184)

 #define  initTIOCA0capt  ((void(*)(void))0x000201d4)
 #define  initTIOCB0capt  ((void(*)(void))0x00020220)
 #define  initTIOCA1capt  ((void(*)(void))0x0002026c)
 #define  initTIOCB1capt  ((void(*)(void))0x000202b8)
 #define  initTIOCA2capt  ((void(*)(void))0x00020300)
 #define  initTIOCB2capt  ((void(*)(void))0x0002034c)

 #define  time_wait0  ((void(*)(int))0x00020398)
 #define  time_wait1  ((void(*)(int))0x000203e2)
 #define  time_wait2  ((void(*)(int))0x0002042c)

 #define  initSCI0  ((void (*)(unsigned int, int))0x00020700)
 #define  initSCI1  ((void (*)(unsigned int, int))0x0002075a)
 #define  initSCI2  ((void (*)(unsigned int, int))0x000207b4)
 #define  sendData0  ((void (*)(char))0x0002080e)
 #define  sendData1  ((void (*)(char))0x00020826)
 #define  sendData2  ((void (*)(char))0x0002083e)
 #define  sendDatas0  ((void (*)(char *))0x00020856)
 #define  sendDatas1  ((void (*)(char *))0x00020878)
 #define  sendDatas2  ((void (*)(char *))0x0002089a)
 #define  recvData0  ((int (*)(char))0x000208bc)
 #define  recvData1  ((int (*)(char))0x00020902)
 #define  recvData2  ((int (*)(char))0x00020948)
