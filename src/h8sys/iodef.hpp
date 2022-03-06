#pragma once

#include "utils/types.hpp"

namespace eommpsys {

namespace H8Reg {

union un_p1dr {                   /* union P1DR   */
  _BYTE BYTE;                     /*  Byte Access */
  union {                         /*  Bit  Access */
    bitAccess_t<_BYTE, 0> B0;     /*  Bit 0       */
    bitAccess_t<_BYTE, 1> B1;     /*  Bit 1       */
    bitAccess_t<_BYTE, 2> B2;     /*  Bit 2       */
    bitAccess_t<_BYTE, 3> B3;     /*  Bit 3       */
    bitAccess_t<_BYTE, 4> B4;     /*  Bit 4       */
    bitAccess_t<_BYTE, 5> B5;     /*  Bit 5       */
    bitAccess_t<_BYTE, 6> B6;     /*  Bit 6       */
    bitAccess_t<_BYTE, 7> B7;     /*  Bit 7       */
  } BIT;                          /*              */
};                                /*              */
union un_p2pcr {                  /* union P2PCR  */
  _BYTE BYTE;                     /*  Byte Access */
  union {                         /*  Bit  Access */
    bitAccess_t<_BYTE, 0> B0;     /*  Bit 0       */
    bitAccess_t<_BYTE, 1> B1;     /*  Bit 1       */
    bitAccess_t<_BYTE, 2> B2;     /*  Bit 2       */
    bitAccess_t<_BYTE, 3> B3;     /*  Bit 3       */
    bitAccess_t<_BYTE, 4> B4;     /*  Bit 4       */
    bitAccess_t<_BYTE, 5> B5;     /*  Bit 5       */
    bitAccess_t<_BYTE, 6> B6;     /*  Bit 6       */
    bitAccess_t<_BYTE, 7> B7;     /*  Bit 7       */
  } BIT;                          /*              */
};                                /*              */
union un_p2dr {                   /* union P2DR   */
  _BYTE BYTE;                     /*  Byte Access */
  union {                         /*  Bit  Access */
    bitAccess_t<_BYTE, 0> B0;     /*  Bit 0       */
    bitAccess_t<_BYTE, 1> B1;     /*  Bit 1       */
    bitAccess_t<_BYTE, 2> B2;     /*  Bit 2       */
    bitAccess_t<_BYTE, 3> B3;     /*  Bit 3       */
    bitAccess_t<_BYTE, 4> B4;     /*  Bit 4       */
    bitAccess_t<_BYTE, 5> B5;     /*  Bit 5       */
    bitAccess_t<_BYTE, 6> B6;     /*  Bit 6       */
    bitAccess_t<_BYTE, 7> B7;     /*  Bit 7       */
  } BIT;                          /*              */
};                                /*              */
union un_p3dr {                   /* union P3DR   */
  _BYTE BYTE;                     /*  Byte Access */
  union {                         /*  Bit  Access */
    bitAccess_t<_BYTE, 0> B0;     /*  Bit 0       */
    bitAccess_t<_BYTE, 1> B1;     /*  Bit 1       */
    bitAccess_t<_BYTE, 2> B2;     /*  Bit 2       */
    bitAccess_t<_BYTE, 3> B3;     /*  Bit 3       */
    bitAccess_t<_BYTE, 4> B4;     /*  Bit 4       */
    bitAccess_t<_BYTE, 5> B5;     /*  Bit 5       */
    bitAccess_t<_BYTE, 6> B6;     /*  Bit 6       */
    bitAccess_t<_BYTE, 7> B7;     /*  Bit 7       */
  } BIT;                          /*              */
};                                /*              */
union un_p4pcr {                  /* union P4PCR  */
  _BYTE BYTE;                     /*  Byte Access */
  union {                         /*  Bit  Access */
    bitAccess_t<_BYTE, 0> B0;     /*  Bit 0       */
    bitAccess_t<_BYTE, 1> B1;     /*  Bit 1       */
    bitAccess_t<_BYTE, 2> B2;     /*  Bit 2       */
    bitAccess_t<_BYTE, 3> B3;     /*  Bit 3       */
    bitAccess_t<_BYTE, 4> B4;     /*  Bit 4       */
    bitAccess_t<_BYTE, 5> B5;     /*  Bit 5       */
    bitAccess_t<_BYTE, 6> B6;     /*  Bit 6       */
    bitAccess_t<_BYTE, 7> B7;     /*  Bit 7       */
  } BIT;                          /*              */
};                                /*              */
union un_p4dr {                   /* union P4DR   */
  _BYTE BYTE;                     /*  Byte Access */
  union {                         /*  Bit  Access */
    bitAccess_t<_BYTE, 0> B0;     /*  Bit 0       */
    bitAccess_t<_BYTE, 1> B1;     /*  Bit 1       */
    bitAccess_t<_BYTE, 2> B2;     /*  Bit 2       */
    bitAccess_t<_BYTE, 3> B3;     /*  Bit 3       */
    bitAccess_t<_BYTE, 4> B4;     /*  Bit 4       */
    bitAccess_t<_BYTE, 5> B5;     /*  Bit 5       */
    bitAccess_t<_BYTE, 6> B6;     /*  Bit 6       */
    bitAccess_t<_BYTE, 7> B7;     /*  Bit 7       */
  } BIT;                          /*              */
};                                /*              */
union un_p5pcr {                  /* union P5PCR  */
  _BYTE BYTE;                     /*  Byte Access */
  union {                         /*  Bit  Access */
    bitAccess_t<_BYTE, 0> B0;     /*  Bit 0       */
    bitAccess_t<_BYTE, 1> B1;     /*  Bit 1       */
    bitAccess_t<_BYTE, 2> B2;     /*  Bit 2       */
    bitAccess_t<_BYTE, 3> B3;     /*  Bit 3       */
  } BIT;                          /*              */
};                                /*              */
union un_p5dr {                   /* union P5DR   */
  _BYTE BYTE;                     /*  Byte Access */
  union {                         /*  Bit  Access */
    bitAccess_t<_BYTE, 0> B0;     /*  Bit 0       */
    bitAccess_t<_BYTE, 1> B1;     /*  Bit 1       */
    bitAccess_t<_BYTE, 2> B2;     /*  Bit 2       */
    bitAccess_t<_BYTE, 3> B3;     /*  Bit 3       */
  } BIT;                          /*              */
};                                /*              */
union un_p6dr {                   /* union P6DR   */
  _BYTE BYTE;                     /*  Byte Access */
  union {                         /*  Bit  Access */
    bitAccess_t<_BYTE, 0> B0;     /*  Bit 0       */
    bitAccess_t<_BYTE, 1> B1;     /*  Bit 1       */
    bitAccess_t<_BYTE, 2> B2;     /*  Bit 2       */
    bitAccess_t<_BYTE, 3> B3;     /*  Bit 3       */
    bitAccess_t<_BYTE, 4> B4;     /*  Bit 4       */
    bitAccess_t<_BYTE, 5> B5;     /*  Bit 5       */
    bitAccess_t<_BYTE, 6> B6;     /*  Bit 6       */
    bitAccess_t<_BYTE, 7> B7;     /*  Bit 7       */
  } BIT;                          /*              */
};                                /*              */
union un_p7dr {                   /* union P7DR   */
  _BYTE BYTE;                     /*  Byte Access */
  union {                         /*  Bit  Access */
    bitAccess_t<_BYTE, 0> B0;     /*  Bit 0       */
    bitAccess_t<_BYTE, 1> B1;     /*  Bit 1       */
    bitAccess_t<_BYTE, 2> B2;     /*  Bit 2       */
    bitAccess_t<_BYTE, 3> B3;     /*  Bit 3       */
    bitAccess_t<_BYTE, 4> B4;     /*  Bit 4       */
    bitAccess_t<_BYTE, 5> B5;     /*  Bit 5       */
    bitAccess_t<_BYTE, 6> B6;     /*  Bit 6       */
    bitAccess_t<_BYTE, 7> B7;     /*  Bit 7       */
  } BIT;                          /*              */
};                                /*              */
union un_p8dr {                   /* union P8DR   */
  _BYTE BYTE;                     /*  Byte Access */
  union {                         /*  Bit  Access */
    bitAccess_t<_BYTE, 0> B0;     /*  Bit 0       */
    bitAccess_t<_BYTE, 1> B1;     /*  Bit 1       */
    bitAccess_t<_BYTE, 2> B2;     /*  Bit 2       */
    bitAccess_t<_BYTE, 3> B3;     /*  Bit 3       */
    bitAccess_t<_BYTE, 4> B4;     /*  Bit 4       */
  } BIT;                          /*              */
};                                /*              */
union un_p9dr {                   /* union P9DR   */
  _BYTE BYTE;                     /*  Byte Access */
  union {                         /*  Bit  Access */
    bitAccess_t<_BYTE, 0> B0;     /*  Bit 0       */
    bitAccess_t<_BYTE, 1> B1;     /*  Bit 1       */
    bitAccess_t<_BYTE, 2> B2;     /*  Bit 2       */
    bitAccess_t<_BYTE, 3> B3;     /*  Bit 3       */
    bitAccess_t<_BYTE, 4> B4;     /*  Bit 4       */
    bitAccess_t<_BYTE, 5> B5;     /*  Bit 5       */
  } BIT;                          /*              */
};                                /*              */
union un_padr {                   /* union PADR   */
  _BYTE BYTE;                     /*  Byte Access */
  union {                         /*  Bit  Access */
    bitAccess_t<_BYTE, 0> B0;     /*  Bit 0       */
    bitAccess_t<_BYTE, 1> B1;     /*  Bit 1       */
    bitAccess_t<_BYTE, 2> B2;     /*  Bit 2       */
    bitAccess_t<_BYTE, 3> B3;     /*  Bit 3       */
    bitAccess_t<_BYTE, 4> B4;     /*  Bit 4       */
    bitAccess_t<_BYTE, 5> B5;     /*  Bit 5       */
    bitAccess_t<_BYTE, 6> B6;     /*  Bit 6       */
    bitAccess_t<_BYTE, 7> B7;     /*  Bit 7       */
  } BIT;                          /*              */
};                                /*              */
union un_pbdr {                   /* union PBDR   */
  _BYTE BYTE;                     /*  Byte Access */
  union {                         /*  Bit  Access */
    bitAccess_t<_BYTE, 0> B0;     /*  Bit 0       */
    bitAccess_t<_BYTE, 1> B1;     /*  Bit 1       */
    bitAccess_t<_BYTE, 2> B2;     /*  Bit 2       */
    bitAccess_t<_BYTE, 3> B3;     /*  Bit 3       */
    bitAccess_t<_BYTE, 4> B4;     /*  Bit 4       */
    bitAccess_t<_BYTE, 5> B5;     /*  Bit 5       */
    bitAccess_t<_BYTE, 6> B6;     /*  Bit 6       */
    bitAccess_t<_BYTE, 7> B7;     /*  Bit 7       */
  } BIT;                          /*              */
};                                /*              */
union un_mdcr {                   /* union MDCR   */
  _BYTE BYTE;                     /*  Byte Access */
  union {                         /*  Bit  Access */
    bitAccess_t<_BYTE, 0, 2> MDS; /*    MDS       */
  } BIT;                          /*              */
};
union un_syscr {                    /* union SYSCR  */
  _BYTE BYTE;                       /*  Byte Access */
  union {                           /*  Bit  Access */
    bitAccess_t<_BYTE, 0> RAME;     /*    RAME      */
    bitAccess_t<_BYTE, 1> SSOE;     /*    SSOE      */
    bitAccess_t<_BYTE, 2> NMIEG;    /*    NMIEG     */
    bitAccess_t<_BYTE, 3> UE;       /*    UE        */
    bitAccess_t<_BYTE, 4, 6> STS;   /*    STS       */
    bitAccess_t<_BYTE, 7> SSBY;     /*    SSBY      */
  } BIT;                            /*              */
};                                  /*              */
union un_divcr {                    /* union DIVCR  */
  _BYTE BYTE;                       /*  Byte Access */
  union {                           /*  Bit  Access */
    bitAccess_t<_BYTE, 0, 1> DIV;   /*    DIV       */
  } BIT;                            /*              */
};                                  /*              */
union un_mstcr {                    /* union MSTCR  */
  _WORD WORD;                       /*  Word Access */
  union {                           /*  Byte Access */
    bitAccess_t<_WORD, 0, 7> H;     /*    High      */
    bitAccess_t<_WORD, 8, 15> L;    /*    Low       */
  } BYTE;                           /*              */
  union {                           /*  Bit  Access */
    bitAccess_t<_WORD, 0, 2> MSTPH; /*    MSTPH     */
    bitAccess_t<_WORD, 7> PSTOP;    /*    PSTOP     */
    bitAccess_t<_WORD, 8> MSTPL0;   /*    MSTPL0    */
    bitAccess_t<_WORD, 10> MSTPL2;  /*    MSTPL2    */
    bitAccess_t<_WORD, 11> MSTPL3;  /*    MSTPL3    */
    bitAccess_t<_WORD, 12> MSTPL4;  /*    MSTPL4    */
    bitAccess_t<_WORD, 13> MSTPL5;  /*    MSTPL5    */
    bitAccess_t<_WORD, 15> MSTPL7;  /*    MSTPL7    */
  } BIT;                            /*              */
};
struct st_bsc {                      /* struct BSC   */
  char wk1;                          /*              */
  union {                            /* BRCR         */
    _BYTE BYTE;                      /*  Byte Access */
    union {                          /*  Bit  Access */
      bitAccess_t<_BYTE, 7> A23E;    /*    A23E      */
      bitAccess_t<_BYTE, 6> A22E;    /*    A22E      */
      bitAccess_t<_BYTE, 5> A21E;    /*    A21E      */
      bitAccess_t<_BYTE, 4> A20E;    /*    A20E      */
      bitAccess_t<_BYTE, 0> BRLE;    /*    BRLE      */
    } BIT;                           /*              */
  } BRCR;                            /*              */
  char wk2[11];                      /*              */
  union {                            /* CSCR         */
    _BYTE BYTE;                      /*  Byte Access */
    union {                          /*  Bit  Access */
      bitAccess_t<_BYTE, 7> CS7E;    /*    CS7E      */
      bitAccess_t<_BYTE, 6> CS6E;    /*    CS6E      */
      bitAccess_t<_BYTE, 5> CS5E;    /*    CS5E      */
      bitAccess_t<_BYTE, 4> CS4E;    /*    CS4E      */
    } BIT;                           /*              */
  } CSCR;                            /*              */
  union {                            /* ABWCR        */
    _BYTE BYTE;                      /*  Byte Access */
    union {                          /*  Bit  Access */
      bitAccess_t<_BYTE, 7> ABW7;    /*    ABW7      */
      bitAccess_t<_BYTE, 6> ABW6;    /*    ABW6      */
      bitAccess_t<_BYTE, 5> ABW5;    /*    ABW5      */
      bitAccess_t<_BYTE, 4> ABW4;    /*    ABW4      */
      bitAccess_t<_BYTE, 3> ABW3;    /*    ABW3      */
      bitAccess_t<_BYTE, 2> ABW2;    /*    ABW2      */
      bitAccess_t<_BYTE, 1> ABW1;    /*    ABW1      */
      bitAccess_t<_BYTE, 0> ABW0;    /*    ABW0      */
    } BIT;                           /*              */
  } ABWCR;                           /*              */
  union {                            /* ASTCR        */
    _BYTE BYTE;                      /*  Byte Access */
    union {                          /*  Bit  Access */
      bitAccess_t<_BYTE, 7> AST7;    /*    AST7      */
      bitAccess_t<_BYTE, 6> AST6;    /*    AST6      */
      bitAccess_t<_BYTE, 5> AST5;    /*    AST5      */
      bitAccess_t<_BYTE, 4> AST4;    /*    AST4      */
      bitAccess_t<_BYTE, 3> AST3;    /*    AST3      */
      bitAccess_t<_BYTE, 2> AST2;    /*    AST2      */
      bitAccess_t<_BYTE, 1> AST1;    /*    AST1      */
      bitAccess_t<_BYTE, 0> AST0;    /*    AST0      */
    } BIT;                           /*              */
  } ASTCR;                           /*              */
  union {                            /* WCR          */
    _WORD WORD;                      /*  Word Access */
    union {                          /*  Byte Access */
      bitAccess_t<_WORD, 8, 15> L;   /*    WCRL      */
      bitAccess_t<_WORD, 0, 7> H;    /*    WCRH      */
    } BYTE;                          /*              */
    union {                          /*  Bit  Access */
      bitAccess_t<_WORD, 14, 15> W7; /*    W7        */
      bitAccess_t<_WORD, 12, 13> W6; /*    W6        */
      bitAccess_t<_WORD, 10, 11> W5; /*    W5        */
      bitAccess_t<_WORD, 8, 9> W4;   /*    W4        */
      bitAccess_t<_WORD, 6, 7> W3;   /*    W3        */
      bitAccess_t<_WORD, 4, 5> W2;   /*    W2        */
      bitAccess_t<_WORD, 2, 3> W1;   /*    W1        */
      bitAccess_t<_WORD, 0, 1> W0;   /*    W0        */
    } BIT;                           /*              */
  } WCR;                             /*              */
  union {                            /* BCR          */
    _BYTE BYTE;                      /*  Byte Access */
    union {                          /*  Bit  Access */
      bitAccess_t<_BYTE, 7> ICIS1;   /*    ICIS1     */
      bitAccess_t<_BYTE, 6> ICIS0;   /*    ICIS0     */
      bitAccess_t<_BYTE, 5> BROME;   /*    BROME     */
      bitAccess_t<_BYTE, 4> BRSTS1;  /*    BRSTS1    */
      bitAccess_t<_BYTE, 3> BRSTS0;  /*    BRSTS0    */
      bitAccess_t<_BYTE, 2> EMC;     /*    BRSTS0    */
      bitAccess_t<_BYTE, 1> RDEA;    /*    RDEA      */
      bitAccess_t<_BYTE, 0> WAITE;   /*    WAITE     */
    } BIT;                           /*              */
  } BCR;                             /*              */
  char wk3;                          /*              */
  union {                            /* DRCRA        */
    _BYTE BYTE;                      /*  Byte Access */
    union {                          /*  Bit  Access */
      bitAccess_t<_BYTE, 5, 7> DRAS; /*    DRAS      */
      bitAccess_t<_BYTE, 3> BE;      /*    BE        */
      bitAccess_t<_BYTE, 2> RDM;     /*    RDM       */
      bitAccess_t<_BYTE, 1> SRFMD;   /*    SRFMD     */
      bitAccess_t<_BYTE, 0> RFSHE;   /*    RFSHE     */
    } BIT;                           /*              */
  } DRCRA;                           /*              */
  union {                            /* DRCRB        */
    _BYTE BYTE;                      /*  Byte Access */
    union {                          /*  Bit  Access */
      bitAccess_t<_BYTE, 6, 7> MXC;  /*    MXC       */
      bitAccess_t<_BYTE, 5> CSEL;    /*    CSEL      */
      bitAccess_t<_BYTE, 4> RCYCE;   /*    RCYCE     */
      bitAccess_t<_BYTE, 2> _TPC;    /*    TPC       */
      bitAccess_t<_BYTE, 1> RCW;     /*    RCW       */
      bitAccess_t<_BYTE, 0> RLW;     /*    RLW       */
    } BIT;                           /*              */
  } DRCRB;                           /*              */
  union {                            /* RTMCSR       */
    _BYTE BYTE;                      /*  Byte Access */
    union {                          /*  Bit  Access */
      bitAccess_t<_BYTE, 7> CMF;     /*    CMF       */
      bitAccess_t<_BYTE, 6> CMIE;    /*    CMIE      */
      bitAccess_t<_BYTE, 3, 5> CKS;  /*    CKS       */
    } BIT;                           /*              */
  } RTMCSR;                          /*              */
  _BYTE RTCNT;                       /* RTCNT        */
  _BYTE RTCOR;                       /* RTCOR        */
};                                   /*              */
struct st_intc {                     /* struct INTC  */
  union {                            /* ISCR         */
    _BYTE BYTE;                      /*  Byte Access */
    union {                          /*  Bit  Access */
      bitAccess_t<_BYTE, 5> IRQ5SC;  /*    IRQ5SC    */
      bitAccess_t<_BYTE, 4> IRQ4SC;  /*    IRQ4SC    */
      bitAccess_t<_BYTE, 3> IRQ3SC;  /*    IRQ3SC    */
      bitAccess_t<_BYTE, 2> IRQ2SC;  /*    IRQ2SC    */
      bitAccess_t<_BYTE, 1> IRQ1SC;  /*    IRQ1SC    */
      bitAccess_t<_BYTE, 0> IRQ0SC;  /*    IRQ0SC    */
    } BIT;                           /*              */
  } ISCR;                            /*              */
  union {                            /* IER          */
    _BYTE BYTE;                      /*  Byte Access */
    union {                          /*  Bit  Access */
      bitAccess_t<_BYTE, 5> IRQ5E;   /*    IRQ5E     */
      bitAccess_t<_BYTE, 4> IRQ4E;   /*    IRQ4E     */
      bitAccess_t<_BYTE, 3> IRQ3E;   /*    IRQ3E     */
      bitAccess_t<_BYTE, 2> IRQ2E;   /*    IRQ2E     */
      bitAccess_t<_BYTE, 1> IRQ1E;   /*    IRQ1E     */
      bitAccess_t<_BYTE, 0> IRQ0E;   /*    IRQ0E     */
    } BIT;                           /*              */
  } IER;                             /*              */
  union {                            /* ISR          */
    _BYTE BYTE;                      /*  Byte Access */
    union {                          /*  Bit  Access */
      _BYTE : 2;                     /*              */
      bitAccess_t<_BYTE, 5> IRQ5F;   /*    IRQ5F     */
      bitAccess_t<_BYTE, 4> IRQ4F;   /*    IRQ4F     */
      bitAccess_t<_BYTE, 3> IRQ3F;   /*    IRQ3F     */
      bitAccess_t<_BYTE, 2> IRQ2F;   /*    IRQ2F     */
      bitAccess_t<_BYTE, 1> IRQ1F;   /*    IRQ1F     */
      bitAccess_t<_BYTE, 0> IRQ0F;   /*    IRQ0F     */
    } BIT;                           /*              */
  } ISR;                             /*              */
  char wk;                           /*              */
  union {                            /* IPRA         */
    _BYTE BYTE;                      /*  Byte Access */
    union {                          /*  Bit  Access */
      bitAccess_t<_BYTE, 7> _IRQ0;   /*    IRQ0      */
      bitAccess_t<_BYTE, 6> _IRQ1;   /*    IRQ1      */
      bitAccess_t<_BYTE, 5> _IRQ23;  /*    IRQ2,IRQ3 */
      bitAccess_t<_BYTE, 4> _IRQ45;  /*    IRQ4,IRQ5 */
      bitAccess_t<_BYTE, 3> _WDT;    /* WDT,DRAM,A/D */
      bitAccess_t<_BYTE, 2> _ITU0;   /*    ITU0      */
      bitAccess_t<_BYTE, 1> _ITU1;   /*    ITU1      */
      bitAccess_t<_BYTE, 0> _ITU2;   /*    ITU2      */
    } BIT;                           /*              */
  } IPRA;                            /*              */
  union {                            /* IPRB         */
    _BYTE BYTE;                      /*  Byte Access */
    union {                          /*  Bit  Access */
      bitAccess_t<_BYTE, 7> _TMR01;  /*    TMR0,1    */
      bitAccess_t<_BYTE, 6> _TMR23;  /*    TMR2,3    */
      bitAccess_t<_BYTE, 5> _DMAC;   /*    DMAC      */
      bitAccess_t<_BYTE, 3> _SCI0;   /*    SCI0      */
      bitAccess_t<_BYTE, 2> _SCI1;   /*    SCI1      */
      bitAccess_t<_BYTE, 1> _SCI2;   /*    SCI2      */
    } BIT;                           /*              */
  } IPRB;                            /*              */
};                                   /*              */
#if __CPU__ == 2                     /* Normal Mode  */
struct st_sam {                      /* struct DMAC  */
  char wk[2];                        /*              */
  void* MAR;                         /* MAR          */
  _WORD ETCR;                        /* ETCR         */
  _BYTE IOAR;                        /* IOAR         */
  union {                            /* DTCR         */
    _BYTE BYTE;                      /*  Byte Access */
    union {                          /*  Bit  Access */
      bitAccess_t<_BYTE, 7> DTE;     /*    DTE       */
      bitAccess_t<_BYTE, 6> DTSZ;    /*    DTSZ      */
      bitAccess_t<_BYTE, 5> DTID;    /*    DTID      */
      bitAccess_t<_BYTE, 4> RPE;     /*    RPE       */
      bitAccess_t<_BYTE, 3> DTIE;    /*    DTIE      */
      bitAccess_t<_BYTE, 0, 2> DTS;  /*    DTS       */
    } BIT;                           /*              */
  } DTCR;                            /*              */
};                                   /*              */
struct st_fam {                      /* struct DMAC  */
  char wk1[2];                       /*              */
  void* MARA;                        /* MARA         */
  _WORD ETCRA;                       /* ETCRA        */
  char wk2;                          /*              */
  union {                            /* DTCRA        */
    _BYTE BYTE;                      /*  Byte Access */
    union {                          /*  Bit  Access */
      bitAccess_t<_BYTE, 7> DTE;     /*    DTE       */
      bitAccess_t<_BYTE, 6> DTSZ;    /*    DTSZ      */
      bitAccess_t<_BYTE, 5> SAID;    /*    SAID      */
      bitAccess_t<_BYTE, 4> SAIDE;   /*    SAIDE     */
      bitAccess_t<_BYTE, 3> DTIE;    /*    DTIE      */
      bitAccess_t<_BYTE, 0, 2> DTS;  /*    DTS       */
    } BIT;                           /*              */
  } DTCRA;                           /*              */
  char wk3[2];                       /*              */
  void* MARB;                        /* MARB         */
  _WORD ETCRB;                       /* ETCRB        */
  char wk4;                          /*              */
  union {                            /* DTCRB        */
    _BYTE BYTE;                      /*  Byte Access */
    union {                          /*  Bit  Access */
      bitAccess_t<_BYTE, 7> DTME;    /*    DTME      */
      bitAccess_t<_BYTE, 5> DAID;    /*    DAID      */
      bitAccess_t<_BYTE, 4> DAIDE;   /*    DAIDE     */
      bitAccess_t<_BYTE, 3> TMS;     /*    TMS       */
      bitAccess_t<_BYTE, 0, 2> DTS;  /*    DTS       */
    } BIT;                           /*              */
  } DTCRB;                           /*              */
};                                   /*              */
#else                                /* Advanced Mode*/
struct st_sam {                     /* struct DMAC  */
  void* MAR;                        /* MAR          */
  _WORD ETCR;                       /* ETCR         */
  _BYTE IOAR;                       /* IOAR         */
  union {                           /* DTCR         */
    _BYTE BYTE;                     /*  Byte Access */
    union {                         /*  Bit  Access */
      bitAccess_t<_BYTE, 7> DTE;    /*    DTE       */
      bitAccess_t<_BYTE, 6> DTSZ;   /*    DTSZ      */
      bitAccess_t<_BYTE, 5> DTID;   /*    DTID      */
      bitAccess_t<_BYTE, 4> RPE;    /*    RPE       */
      bitAccess_t<_BYTE, 3> DTIE;   /*    DTIE      */
      bitAccess_t<_BYTE, 0, 2> DTS; /*    DTS       */
    } BIT;                          /*              */
  } DTCR;                           /*              */
};                                  /*              */
struct st_fam {                     /* struct DMAC  */
  void* MARA;                       /* MARA         */
  _WORD ETCRA;                      /* ETCRA        */
  char wk1;                         /*              */
  union {                           /* DTCRA        */
    _BYTE BYTE;                     /*  Byte Access */
    union {                         /*  Bit  Access */
      bitAccess_t<_BYTE, 7> DTE;    /*    DTE       */
      bitAccess_t<_BYTE, 6> DTSZ;   /*    DTSZ      */
      bitAccess_t<_BYTE, 5> SAID;   /*    SAID      */
      bitAccess_t<_BYTE, 4> SAIDE;  /*    SAIDE     */
      bitAccess_t<_BYTE, 3> DTIE;   /*    DTIE      */
      bitAccess_t<_BYTE, 0, 2> DTS; /*    DTS       */
    } BIT;                          /*              */
  } DTCRA;                          /*              */
  void* MARB;                       /* MARB         */
  _WORD ETCRB;                      /* ETCRB        */
  char wk2;                         /*              */
  union {                           /* DTCRB        */
    _BYTE BYTE;                     /*  Byte Access */
    union {                         /*  Bit  Access */
      bitAccess_t<_BYTE, 7> DTME;   /*    DTME      */
      bitAccess_t<_BYTE, 5> DAID;   /*    DAID      */
      bitAccess_t<_BYTE, 4> DAIDE;  /*    DAIDE     */
      bitAccess_t<_BYTE, 3> TMS;    /*    TMS       */
      bitAccess_t<_BYTE, 0, 2> DTS; /*    DTS       */
    } BIT;                          /*              */
  } DTCRB;                          /*              */
};                                  /*              */
#endif                               /*              */

struct st_flash {                     /* struct FLASH */
  char wk;                            /*              */
  union {                             /* RAMCR        */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 3> RAMS;     /*    RAMS      */
      bitAccess_t<_BYTE, 0, 2> RAM;   /*    RAM       */
    } BIT;                            /*              */
  } RAMCR;                            /*              */
  char wk1[56];                       /*              */
  union {                             /* FCCS         */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 7> FWE;      /*    FWE       */
      bitAccess_t<_BYTE, 4> FLER;     /*    FLER      */
      bitAccess_t<_BYTE, 0> SCO;      /*    SCO       */
    } BIT;                            /*              */
  } FCCS;                             /*              */
  union {                             /* FPCS         */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 0> PPVS;     /*    PPVS      */
    } BIT;                            /*              */
  } FPCS;                             /*              */
  union {                             /* FECS         */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 0> EPVB;     /*    EPVB      */
    } BIT;                            /*              */
  } FECS;                             /*              */
  char wk2;                           /*              */
  _BYTE FKEY;                         /* FKEY         */
  _BYTE FMATS;                        /* FMATS        */
  char wk3;                           /*              */
  union {                             /* FVACR        */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 7> FVCHGE;   /*    FVCHGE    */
      bitAccess_t<_BYTE, 0, 3> FVSEL; /*    FVSEL     */
    } BIT;                            /*              */
  } FVACR;                            /*              */
  _BYTE FVADRR;                       /* FVADRR       */
  _BYTE FVADRE;                       /* FVADRE       */
  _BYTE FVADRH;                       /* FVADRH       */
  _BYTE FVADRL;                       /* FVADRL       */
};                                    /*              */
struct st_itu {                       /* struct ITU   */
  union {                             /* TSTR         */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 2> STR2;     /*    STR2      */
      bitAccess_t<_BYTE, 1> STR1;     /*    STR1      */
      bitAccess_t<_BYTE, 0> STR0;     /*    STR0      */
    } BIT;                            /*              */
  } TSTR;                             /*              */
  union {                             /* TSNC         */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 2> SYNC2;    /*    SYNC2     */
      bitAccess_t<_BYTE, 1> SYNC1;    /*    SYNC1     */
      bitAccess_t<_BYTE, 0> SYNC0;    /*    SYNC0     */
    } BIT;                            /*              */
  } TSNC;                             /*              */
  union {                             /* TMDR         */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 6> MDF;      /*    MDF       */
      bitAccess_t<_BYTE, 5> FDIR;     /*    FDIR      */
      bitAccess_t<_BYTE, 2> PWM2;     /*    PWM2      */
      bitAccess_t<_BYTE, 1> PWM1;     /*    PWM1      */
      bitAccess_t<_BYTE, 0> PWM0;     /*    PWM0      */
    } BIT;                            /*              */
  } TMDR;                             /*              */
  union {                             /* TOLR         */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 5> TOB2;     /*    TOB2      */
      bitAccess_t<_BYTE, 4> TOA2;     /*    TOA2      */
      bitAccess_t<_BYTE, 3> TOB1;     /*    TOB1      */
      bitAccess_t<_BYTE, 2> TOA1;     /*    TOA1      */
      bitAccess_t<_BYTE, 1> TOB0;     /*    TOB0      */
      bitAccess_t<_BYTE, 0> TOA0;     /*    TOA0      */
    } BIT;                            /*              */
  } TOLR;                             /*              */
  union {                             /* TISRA        */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 6> IMIEA2;   /*    IMIEA2    */
      bitAccess_t<_BYTE, 5> IMIEA1;   /*    IMIEA2    */
      bitAccess_t<_BYTE, 4> IMIEA0;   /*    IMIEA2    */
      bitAccess_t<_BYTE, 2> IMFA2;    /*    IMFA2     */
      bitAccess_t<_BYTE, 1> IMFA1;    /*    IMFA1     */
      bitAccess_t<_BYTE, 0> IMFA0;    /*    IMFA0     */
    } BIT;                            /*              */
  } TISRA;                            /*              */
  union {                             /* TISRB        */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 6> IMIEB2;   /*    IMIEB2    */
      bitAccess_t<_BYTE, 5> IMIEB1;   /*    IMIEB2    */
      bitAccess_t<_BYTE, 4> IMIEB0;   /*    IMIEB2    */
      bitAccess_t<_BYTE, 2> IMFB2;    /*    IMFB2     */
      bitAccess_t<_BYTE, 1> IMFB1;    /*    IMFB1     */
      bitAccess_t<_BYTE, 0> IMFB0;    /*    IMFB0     */
    } BIT;                            /*              */
  } TISRB;                            /*              */
  union {                             /* TISRC        */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 6> OVIE2;    /*    OVIE2     */
      bitAccess_t<_BYTE, 5> OVIE1;    /*    OVIE2     */
      bitAccess_t<_BYTE, 4> OVIE0;    /*    OVIE2     */
      bitAccess_t<_BYTE, 2> OVF2;     /*    OVF2      */
      bitAccess_t<_BYTE, 1> OVF1;     /*    OVF1      */
      bitAccess_t<_BYTE, 0> OVF0;     /*    OVF0      */
    } BIT;                            /*              */
  } TISRC;                            /*              */
};                                    /*              */
struct st_itu0 {                      /* struct ITU0  */
  union {                             /* TCR          */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 5, 6> CCLR;  /*    CCLR      */
      bitAccess_t<_BYTE, 3, 4> CKEG;  /*    CKEG      */
      bitAccess_t<_BYTE, 0, 2> TPSC;  /*    TPSC      */
    } BIT;                            /*              */
  } TCR;                              /*              */
  union {                             /* TIOR         */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 4, 6> IOB;   /*    IOB       */
      bitAccess_t<_BYTE, 0, 2> IOA;   /*    IOA       */
    } BIT;                            /*              */
  } TIOR;                             /*              */
  _WORD TCNT;                         /* TCNT         */
  _WORD GRA;                          /* GRA          */
  _WORD GRB;                          /* GRB          */
};                                    /*              */
union un_wdt {                        /* union WDT    */
  struct {                            /* Read  Access */
    union {                           /* TCSR         */
      _BYTE BYTE;                     /*  Byte Access */
      union {                         /*  Bit  Access */
        bitAccess_t<_BYTE, 7> OVF;    /*    OVF       */
        bitAccess_t<_BYTE, 6> WTIT;   /*    WT/IT     */
        bitAccess_t<_BYTE, 5> TME;    /*    TME       */
        bitAccess_t<_BYTE, 0, 2> CKS; /*    CKS       */
      } BIT;                          /*              */
    } TCSR;                           /*              */
    _BYTE TCNT;                       /* TCNT         */
    char wk;                          /*              */
    union {                           /* RSTCSR       */
      _BYTE BYTE;                     /*  Byte Access */
      union {                         /*              */
        bitAccess_t<_BYTE, 7> WRST;   /*    WSRT      */
      } BIT;                          /*              */
    } RSTCSR;                         /*              */
  } READ;                             /*              */
  struct {                            /* Write Access */
    _WORD TCSR;                       /* TCSR/TCNT    */
    _WORD RSTCSR;                     /* RSTCSR       */
  } WRITE;                            /*              */
};                                    /*              */
struct st_tmr01 {                     /* struct TMR01 */
  union {                             /* TCR0         */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 7> CMIEB;    /*    CMIEB     */
      bitAccess_t<_BYTE, 6> CMIEA;    /*    CMIEA     */
      bitAccess_t<_BYTE, 5> OVIE;     /*    OVIE      */
      bitAccess_t<_BYTE, 3, 4> CCLR;  /*    CCLR      */
      bitAccess_t<_BYTE, 0, 2> CKS;   /*    CKS       */
    } BIT;                            /*              */
  } TCR0;                             /*              */
  union {                             /* TCR1         */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 7> CMIEB;    /*    CMIEB     */
      bitAccess_t<_BYTE, 6> CMIEA;    /*    CMIEA     */
      bitAccess_t<_BYTE, 5> OVIE;     /*    OVIE      */
      bitAccess_t<_BYTE, 3, 4> CCLR;  /*    CCLR      */
      bitAccess_t<_BYTE, 0, 2> CKS;   /*    CKS       */
    } BIT;                            /*              */
  } TCR1;                             /*              */
  union {                             /* TCSR0        */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 7> CMFB;     /*    CMFB      */
      bitAccess_t<_BYTE, 6> CMFA;     /*    CMFA      */
      bitAccess_t<_BYTE, 5> OVF;      /*    OVF       */
      bitAccess_t<_BYTE, 4> ADTE;     /*    ADTE      */
      bitAccess_t<_BYTE, 0, 3> OS;    /*    OS        */
    } BIT;                            /*              */
  } TCSR0;                            /*              */
  union {                             /* TCSR1        */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 7> CMFB;     /*    CMFB      */
      bitAccess_t<_BYTE, 6> CMFA;     /*    CMFA      */
      bitAccess_t<_BYTE, 5> OVF;      /*    OVF       */
      bitAccess_t<_BYTE, 4> ICE;      /*    ICE       */
      bitAccess_t<_BYTE, 0, 3> OS;    /*    OS        */
    } BIT;                            /*              */
  } TCSR1;                            /*              */
  _WORD TCORA;                        /* TCORA        */
  _WORD TCORB;                        /* TCORB        */
  _WORD TCNT;                         /* TCNT         */
};                                    /*              */
struct st_tmr23 {                     /* struct TMR23 */
  union {                             /* TCR2         */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 7> CMIEB;    /*    CMIEB     */
      bitAccess_t<_BYTE, 6> CMIEA;    /*    CMIEA     */
      bitAccess_t<_BYTE, 5> OVIE;     /*    OVIE      */
      bitAccess_t<_BYTE, 3, 4> CCLR;  /*    CCLR      */
      bitAccess_t<_BYTE, 0, 2> CKS;   /*    CKS       */
    } BIT;                            /*              */
  } TCR2;                             /*              */
  union {                             /* TCR3         */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 7> CMIEB;    /*    CMIEB     */
      bitAccess_t<_BYTE, 6> CMIEA;    /*    CMIEA     */
      bitAccess_t<_BYTE, 5> OVIE;     /*    OVIE      */
      bitAccess_t<_BYTE, 3, 4> CCLR;  /*    CCLR      */
      bitAccess_t<_BYTE, 0, 2> CKS;   /*    CKS       */
    } BIT;                            /*              */
  } TCR3;                             /*              */
  union {                             /* TCSR2        */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 7> CMFB;     /*    CMFB      */
      bitAccess_t<_BYTE, 6> CMFA;     /*    CMFA      */
      bitAccess_t<_BYTE, 5> OVF;      /*    OVF       */
      bitAccess_t<_BYTE, 0, 3> OS;    /*    OS        */
    } BIT;                            /*              */
  } TCSR2;                            /*              */
  union {                             /* TCSR3        */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 7> CMFB;     /*    CMFB      */
      bitAccess_t<_BYTE, 6> CMFA;     /*    CMFA      */
      bitAccess_t<_BYTE, 5> OVF;      /*    OVF       */
      bitAccess_t<_BYTE, 4> ICE;      /*    ICE       */
      bitAccess_t<_BYTE, 0, 3> OS;    /*    OS        */
    } BIT;                            /*              */
  } TCSR3;                            /*              */
  _WORD TCORA;                        /* TCORA        */
  _WORD TCORB;                        /* TCORB        */
  _WORD TCNT;                         /* TCNT         */
};                                    /*              */
struct st_tmr0 {                      /* struct TMR0  */
  union {                             /* TCR          */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 7> CMIEB;    /*    CMIEB     */
      bitAccess_t<_BYTE, 6> CMIEA;    /*    CMIEA     */
      bitAccess_t<_BYTE, 5> OVIE;     /*    OVIE      */
      bitAccess_t<_BYTE, 3, 4> CCLR;  /*    CCLR      */
      bitAccess_t<_BYTE, 0, 2> CKS;   /*    CKS       */
    } BIT;                            /*              */
  } TCR;                              /*              */
  char wk1;                           /*              */
  union {                             /* TCSR         */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 7> CMFB;     /*    CMFB      */
      bitAccess_t<_BYTE, 6> CMFA;     /*    CMFA      */
      bitAccess_t<_BYTE, 5> OVF;      /*    OVF       */
      bitAccess_t<_BYTE, 4> ADTE;     /*    ADTE      */
      bitAccess_t<_BYTE, 2, 3> OIS;   /*    OIS       */
      bitAccess_t<_BYTE, 0, 1> OS;    /*    OS        */
    } BIT;                            /*              */
  } TCSR;                             /*              */
  char wk2;                           /*              */
  _BYTE TCORA;                        /* TCORA        */
  char wk3;                           /*              */
  _BYTE TCORB;                        /* TCORB        */
  char wk4;                           /*              */
  _BYTE TCNT;                         /* TCNT         */
};                                    /*              */
struct st_tmr1 {                      /* struct TMR1  */
  union {                             /* TCR          */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 7> CMIEB;    /*    CMIEB     */
      bitAccess_t<_BYTE, 6> CMIEA;    /*    CMIEA     */
      bitAccess_t<_BYTE, 5> OVIE;     /*    OVIE      */
      bitAccess_t<_BYTE, 3, 4> CCLR;  /*    CCLR      */
      bitAccess_t<_BYTE, 0, 2> CKS;   /*    CKS       */
    } BIT;                            /*              */
  } TCR;                              /*              */
  char wk1;                           /*              */
  union {                             /* TCSR         */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 7> CMFB;     /*    CMFB      */
      bitAccess_t<_BYTE, 6> CMFA;     /*    CMFA      */
      bitAccess_t<_BYTE, 5> OVF;      /*    OVF       */
      bitAccess_t<_BYTE, 4> ICE;      /*    ICE       */
      bitAccess_t<_BYTE, 2, 3> OIS;   /*    OIS       */
      bitAccess_t<_BYTE, 0, 1> OS;    /*    OS        */
    } BIT;                            /*              */
  } TCSR;                             /*              */
  char wk2;                           /*              */
  _BYTE TCORA;                        /* TCORA        */
  char wk3;                           /*              */
  _BYTE TCORB;                        /* TCORB        */
  char wk4;                           /*              */
  _BYTE TCNT;                         /* TCNT         */
};                                    /*              */
struct st_tmr2 {                      /* struct TMR2  */
  union {                             /* TCR          */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 7> CMIEB;    /*    CMIEB     */
      bitAccess_t<_BYTE, 6> CMIEA;    /*    CMIEA     */
      bitAccess_t<_BYTE, 5> OVIE;     /*    OVIE      */
      bitAccess_t<_BYTE, 3, 4> CCLR;  /*    CCLR      */
      bitAccess_t<_BYTE, 0, 2> CKS;   /*    CKS       */
    } BIT;                            /*              */
  } TCR;                              /*              */
  char wk1;                           /*              */
  union {                             /* TCSR         */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 7> CMFB;     /*    CMFB      */
      bitAccess_t<_BYTE, 6> CMFA;     /*    CMFA      */
      bitAccess_t<_BYTE, 5> OVF;      /*    OVF       */
      bitAccess_t<_BYTE, 2, 3> OIS;   /*    OIS       */
      bitAccess_t<_BYTE, 0, 1> OS;    /*    OS        */
    } BIT;                            /*              */
  } TCSR;                             /*              */
  char wk2;                           /*              */
  _BYTE TCORA;                        /* TCORA        */
  char wk3;                           /*              */
  _BYTE TCORB;                        /* TCORB        */
  char wk4;                           /*              */
  _BYTE TCNT;                         /* TCNT         */
};                                    /*              */
union un_dastcr {                     /* DASTCR       */
  _BYTE BYTE;                         /*  Byte Access */
  union {                             /*  Bit  Access */
    bitAccess_t<_BYTE, 0> DASTE;      /*    DASTE     */
  } BIT;                              /*              */
};                                    /*              */
struct st_da {                        /* struct D/A   */
  _BYTE DADR0;                        /* DADR0        */
  _BYTE DADR1;                        /* DADR1        */
  union {                             /* DACR         */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 7> DAOE1;    /*    DAOE1     */
      bitAccess_t<_BYTE, 6> DAOE0;    /*    DAOE0     */
      bitAccess_t<_BYTE, 5> DAE;      /*    DAE       */
    } BIT;                            /*              */
  } DACR;                             /*              */
};                                    /*              */
struct st_tpc {                       /* struct TPC   */
  union {                             /* TPMR         */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 3> G3NOV;    /*    G3NOV     */
      bitAccess_t<_BYTE, 2> G2NOV;    /*    G2NOV     */
      bitAccess_t<_BYTE, 1> G1NOV;    /*    G1NOV     */
      bitAccess_t<_BYTE, 0> G0NOV;    /*    G0NOV     */
    } BIT;                            /*              */
  } TPMR;                             /*              */
  union {                             /* TPCR         */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 6, 7> G3CMS; /*    G3CMS     */
      bitAccess_t<_BYTE, 4, 5> G2CMS; /*    G2CMS     */
      bitAccess_t<_BYTE, 2, 3> G1CMS; /*    G1CMS     */
      bitAccess_t<_BYTE, 0, 1> G0CMS; /*    G0CMS     */
    } BIT;                            /*              */
  } TPCR;                             /*              */
  union {                             /* NDERB        */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 7> B15;      /*    NDER15    */
      bitAccess_t<_BYTE, 6> B14;      /*    NDER14    */
      bitAccess_t<_BYTE, 5> B13;      /*    NDER13    */
      bitAccess_t<_BYTE, 4> B12;      /*    NDER12    */
      bitAccess_t<_BYTE, 3> B11;      /*    NDER11    */
      bitAccess_t<_BYTE, 2> B10;      /*    NDER10    */
      bitAccess_t<_BYTE, 1> B9;       /*    NDER9     */
      bitAccess_t<_BYTE, 0> B8;       /*    NDER8     */
    } BIT;                            /*              */
  } NDERB;                            /*              */
  union {                             /* NDERA        */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 7> B7;       /*    NDER7     */
      bitAccess_t<_BYTE, 6> B6;       /*    NDER6     */
      bitAccess_t<_BYTE, 5> B5;       /*    NDER5     */
      bitAccess_t<_BYTE, 4> B4;       /*    NDER4     */
      bitAccess_t<_BYTE, 3> B3;       /*    NDER3     */
      bitAccess_t<_BYTE, 2> B2;       /*    NDER2     */
      bitAccess_t<_BYTE, 1> B1;       /*    NDER1     */
      bitAccess_t<_BYTE, 0> B0;       /*    NDER0     */
    } BIT;                            /*              */
  } NDERA;                            /*              */
  union {                             /* NDRB (H'A4)  */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 7> B15;      /*    NDR15     */
      bitAccess_t<_BYTE, 6> B14;      /*    NDR14     */
      bitAccess_t<_BYTE, 5> B13;      /*    NDR13     */
      bitAccess_t<_BYTE, 4> B12;      /*    NDR12     */
      bitAccess_t<_BYTE, 3> B11;      /*    NDR11     */
      bitAccess_t<_BYTE, 2> B10;      /*    NDR10     */
      bitAccess_t<_BYTE, 1> B9;       /*    NDR9      */
      bitAccess_t<_BYTE, 0> B8;       /*    NDR8      */
    } BIT;                            /*              */
  } NDRB1;                            /*              */
  union {                             /* NDRA (H'A5)  */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 7> B7;       /*    NDR7      */
      bitAccess_t<_BYTE, 6> B6;       /*    NDR6      */
      bitAccess_t<_BYTE, 5> B5;       /*    NDR5      */
      bitAccess_t<_BYTE, 4> B4;       /*    NDR4      */
      bitAccess_t<_BYTE, 3> B3;       /*    NDR3      */
      bitAccess_t<_BYTE, 2> B2;       /*    NDR2      */
      bitAccess_t<_BYTE, 1> B1;       /*    NDR1      */
      bitAccess_t<_BYTE, 0> B0;       /*    NDR0      */
    } BIT;                            /*              */
  } NDRA1;                            /*              */
  union {                             /* NDRB (H'A6)  */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 3> B11;      /*    NDR11     */
      bitAccess_t<_BYTE, 2> B10;      /*    NDR10     */
      bitAccess_t<_BYTE, 1> B9;       /*    NDR9      */
      bitAccess_t<_BYTE, 0> B8;       /*    NDR8      */
    } BIT;                            /*              */
  } NDRB2;                            /*              */
  union {                             /* NDRA (H'A7)  */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 3> B3;       /*    NDR3      */
      bitAccess_t<_BYTE, 2> B2;       /*    NDR2      */
      bitAccess_t<_BYTE, 1> B1;       /*    NDR1      */
      bitAccess_t<_BYTE, 0> B0;       /*    NDR0      */
    } BIT;                            /*              */
  } NDRA2;                            /*              */
};                                    /*              */
struct st_sci {                       /* struct SCI   */
  union {                             /* SMR          */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 7> CA;       /*    C/A       */
      bitAccess_t<_BYTE, 6> CHR;      /*    CHR       */
      bitAccess_t<_BYTE, 5> PE;       /*    PE        */
      bitAccess_t<_BYTE, 4> OE;       /*    O/E       */
      bitAccess_t<_BYTE, 3> STOP;     /*    STOP      */
      bitAccess_t<_BYTE, 2> MP;       /*    MP        */
      bitAccess_t<_BYTE, 0, 1> CKS;   /*    CKS       */
    } BIT;                            /*              */
  } SMR;                              /*              */
  _BYTE BRR;                          /* BRR          */
  union {                             /* SCR          */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 7> TIE;      /*    TIE       */
      bitAccess_t<_BYTE, 6> RIE;      /*    RIE       */
      bitAccess_t<_BYTE, 5> TE;       /*    TE        */
      bitAccess_t<_BYTE, 4> RE;       /*    RE        */
      bitAccess_t<_BYTE, 3> MPIE;     /*    MPIE      */
      bitAccess_t<_BYTE, 2> TEIE;     /*    TEIE      */
      bitAccess_t<_BYTE, 0, 1> CKE;   /*    CKE       */
    } BIT;                            /*              */
  } SCR;                              /*              */
  _BYTE TDR;                          /* TDR          */
  union {                             /* SSR          */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 7> TDRE;     /*    TDRE      */
      bitAccess_t<_BYTE, 6> RDRF;     /*    RDRF      */
      bitAccess_t<_BYTE, 5> ORER;     /*    ORER      */
      bitAccess_t<_BYTE, 4> FER;      /*    FER       */
      bitAccess_t<_BYTE, 3> PER;      /*    PER       */
      bitAccess_t<_BYTE, 2> TEND;     /*    TEND      */
      bitAccess_t<_BYTE, 1> MPB;      /*    MPB       */
      bitAccess_t<_BYTE, 0> MPBT;     /*    MPBT      */
    } BIT;                            /*              */
  } SSR;                              /*              */
  _BYTE RDR;                          /* RDR          */
  union {                             /* SCMR         */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 3> SDIR;     /*    SDIR      */
      bitAccess_t<_BYTE, 2> SINV;     /*    SINV      */
      bitAccess_t<_BYTE, 0> SMIF;     /*    SMIF      */
    } BIT;                            /*              */
  } SCMR;                             /*              */
};                                    /*              */
struct st_smci {                      /* struct SMCI  */
  union {                             /* SMR          */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 7> GM;       /*    GM        */
      bitAccess_t<_BYTE, 6> CHR;      /*    CHR       */
      bitAccess_t<_BYTE, 5> PE;       /*    PE        */
      bitAccess_t<_BYTE, 4> OE;       /*    O/E       */
      bitAccess_t<_BYTE, 3> STOP;     /*    STOP      */
      bitAccess_t<_BYTE, 2> MP;       /*    MP        */
      bitAccess_t<_BYTE, 0, 1> CKS;   /*    CKS       */
    } BIT;                            /*              */
  } SMR;                              /*              */
  _BYTE BRR;                          /* BRR          */
  union {                             /* SCR          */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 7> TIE;      /*    TIE       */
      bitAccess_t<_BYTE, 6> RIE;      /*    RIE       */
      bitAccess_t<_BYTE, 5> TE;       /*    TE        */
      bitAccess_t<_BYTE, 4> RE;       /*    RE        */
      bitAccess_t<_BYTE, 3> MPIE;     /*    MPIE      */
      bitAccess_t<_BYTE, 2> TEIE;     /*    TEIE      */
      bitAccess_t<_BYTE, 0, 1> CKE;   /*    CKE       */
    } BIT;                            /*              */
  } SCR;                              /*              */
  _BYTE TDR;                          /* TDR          */
  union {                             /* SSR          */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 7> TDRE;     /*    TDRE      */
      bitAccess_t<_BYTE, 6> RDRF;     /*    RDRF      */
      bitAccess_t<_BYTE, 5> ORER;     /*    ORER      */
      bitAccess_t<_BYTE, 4> ERS;      /*    ERS       */
      bitAccess_t<_BYTE, 3> PER;      /*    PER       */
      bitAccess_t<_BYTE, 2> TEND;     /*    TEND      */
      bitAccess_t<_BYTE, 1> MPB;      /*    MPB       */
      bitAccess_t<_BYTE, 0> MPBT;     /*    MPBT      */
    } BIT;                            /*              */
  } SSR;                              /*              */
  _BYTE RDR;                          /* RDR          */
  union {                             /* SCMR         */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 3> SDIR;     /*    SDIR      */
      bitAccess_t<_BYTE, 2> SINV;     /*    SINV      */
      bitAccess_t<_BYTE, 0> SMIF;     /*    SMIF      */
    } BIT;                            /*              */
  } SCMR;                             /*              */
};                                    /*              */
struct st_ad {                        /* struct A/D   */
  _WORD ADDRA;                        /* ADDRA        */
  _WORD ADDRB;                        /* ADDRB        */
  _WORD ADDRC;                        /* ADDRC        */
  _WORD ADDRD;                        /* ADDRD        */
  union {                             /* ADCSR        */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 7> ADF;      /*    ADF       */
      bitAccess_t<_BYTE, 6> ADIE;     /*    ADIE      */
      bitAccess_t<_BYTE, 5> ADST;     /*    ADST      */
      bitAccess_t<_BYTE, 4> SCAN;     /*    SCAN      */
      bitAccess_t<_BYTE, 3> CKS;      /*    CKS       */
      bitAccess_t<_BYTE, 0, 2> CH;    /*    CH        */
    } BIT;                            /*              */
  } ADCSR;                            /*              */
  union {                             /* ADCR         */
    _BYTE BYTE;                       /*  Byte Access */
    union {                           /*  Bit  Access */
      bitAccess_t<_BYTE, 7> TRGE;     /*    TRGE      */
    } BIT;                            /*              */
  } ADCR;                             /*              */
};                                    /*              */

constexpr uint32_t addr_p1ddr = 0xFEE000;
constexpr uint32_t addr_p2ddr = 0xFEE001;
constexpr uint32_t addr_p3ddr = 0xFEE002;
constexpr uint32_t addr_p4ddr = 0xFEE003;
constexpr uint32_t addr_p5ddr = 0xFEE004;
constexpr uint32_t addr_p6ddr = 0xFEE005;
constexpr uint32_t addr_p8ddr = 0xFEE007;
constexpr uint32_t addr_p9ddr = 0xFEE008;
constexpr uint32_t addr_paddr = 0xFEE009;
constexpr uint32_t addr_pbddr = 0xFEE00A;
constexpr uint32_t addr_p2pcr = 0xFEE03C;
constexpr uint32_t addr_p4pcr = 0xFEE03E;
constexpr uint32_t addr_p5pcr = 0xFEE03F;
constexpr uint32_t addr_p1dr = 0xFFFFD0;
constexpr uint32_t addr_p2dr = 0xFFFFD1;
constexpr uint32_t addr_p3dr = 0xFFFFD2;
constexpr uint32_t addr_p4dr = 0xFFFFD3;
constexpr uint32_t addr_p5dr = 0xFFFFD4;
constexpr uint32_t addr_p6dr = 0xFFFFD5;
constexpr uint32_t addr_p7dr = 0xFFFFD6;
constexpr uint32_t addr_p8dr = 0xFFFFD7;
constexpr uint32_t addr_p9dr = 0xFFFFD8;
constexpr uint32_t addr_padr = 0xFFFFD9;
constexpr uint32_t addr_pbdr = 0xFFFFDA;
constexpr uint32_t addr_mdcr = 0xFEE011;
constexpr uint32_t addr_syscr = 0xFEE012;
constexpr uint32_t addr_divcr = 0xFEE01B;
constexpr uint32_t addr_mstcr = 0xFEE01C;
constexpr uint32_t addr_intc = 0xFEE014;
constexpr uint32_t addr_mar0ar = 0xFFFF20;
constexpr uint32_t addr_mar0br = 0xFFFF28;
constexpr uint32_t addr_mar1ar = 0xFFFF30;
constexpr uint32_t addr_mar1br = 0xFFFF38;
constexpr uint32_t addr_flash = 0xFEE076;
constexpr uint32_t addr_tstr = 0xFFFF60;
constexpr uint32_t addr_16tcr0 = 0xFFFF68;
constexpr uint32_t addr_16tcr1 = 0xFFFF70;
constexpr uint32_t addr_16tcr2 = 0xFFFF78;
constexpr uint32_t addr_tcsr = 0xFFFF8C;
constexpr uint32_t addr_8tcr0 = 0xFFFF80;
constexpr uint32_t addr_8tcr1 = 0xFFFF81;
constexpr uint32_t addr_8tcr2 = 0xFFFF90;
constexpr uint32_t addr_8tcr3 = 0xFFFF91;
constexpr uint32_t addr_dastcr = 0xFEE01A;
constexpr uint32_t addr_dadr0 = 0xFFFF9C;
constexpr uint32_t addr_tpmr = 0xFFFFA0;
constexpr uint32_t addr_smr0 = 0xFFFFB0;
constexpr uint32_t addr_smr1 = 0xFFFFB8;
constexpr uint32_t addr_smr2 = 0xFFFFC0;
constexpr uint32_t addr_addrah = 0xFFFFE0;

inline uint8_t& P1DDR = *reinterpret_cast<uint8_t*>(addr_p1ddr);   /* P1DDR */
inline uint8_t& P2DDR = *reinterpret_cast<uint8_t*>(addr_p2ddr);   /* P2DDR */
inline uint8_t& P3DDR = *reinterpret_cast<uint8_t*>(addr_p3ddr);   /* P3DDR */
inline uint8_t& P4DDR = *reinterpret_cast<uint8_t*>(addr_p4ddr);   /* P4DDR */
inline uint8_t& P5DDR = *reinterpret_cast<uint8_t*>(addr_p5ddr);   /* P5DDR */
inline uint8_t& P6DDR = *reinterpret_cast<uint8_t*>(addr_p6ddr);   /* P6DDR */
inline uint8_t& P8DDR = *reinterpret_cast<uint8_t*>(addr_p8ddr);   /* P8DDR */
inline uint8_t& P9DDR = *reinterpret_cast<uint8_t*>(addr_p9ddr);   /* P9DDR */
inline uint8_t& PADDR = *reinterpret_cast<uint8_t*>(addr_paddr);   /* PADDR */
inline uint8_t& PBDDR = *reinterpret_cast<uint8_t*>(addr_pbddr);   /* PBDDR */
inline un_p2pcr& P2PCR = *reinterpret_cast<un_p2pcr*>(addr_p2pcr); /* P2PCR */
inline un_p4pcr& P4PCR = *reinterpret_cast<un_p4pcr*>(addr_p4pcr); /* P4PCR */
inline un_p5pcr& P5PCR = *reinterpret_cast<un_p5pcr*>(addr_p5pcr); /* P5PCR */
inline un_p1dr& P1DR = *reinterpret_cast<un_p1dr*>(addr_p1dr);     /* P1DR */
inline un_p2dr& P2DR = *reinterpret_cast<un_p2dr*>(addr_p2dr);     /* P2DR */
inline un_p3dr& P3DR = *reinterpret_cast<un_p3dr*>(addr_p3dr);     /* P3DR */
inline un_p4dr& P4DR = *reinterpret_cast<un_p4dr*>(addr_p4dr);     /* P4DR */
inline un_p5dr& P5DR = *reinterpret_cast<un_p5dr*>(addr_p5dr);     /* P5DR */
inline un_p6dr& P6DR = *reinterpret_cast<un_p6dr*>(addr_p6dr);     /* P6DR */
inline un_p7dr& P7DR = *reinterpret_cast<un_p7dr*>(addr_p7dr);     /* P7DR */
inline un_p8dr& P8DR = *reinterpret_cast<un_p8dr*>(addr_p8dr);     /* P8DR */
inline un_p9dr& P9DR = *reinterpret_cast<un_p9dr*>(addr_p8dr);     /* P9DR */
inline un_padr& PADR = *reinterpret_cast<un_padr*>(addr_padr);     /* PADR */
inline un_pbdr& PBDR = *reinterpret_cast<un_pbdr*>(addr_pbdr);     /* PBDR */
inline un_mdcr& MDCR = *reinterpret_cast<un_mdcr*>(addr_mdcr);     /* MDCR */
inline un_syscr& SYSCR = *reinterpret_cast<un_syscr*>(addr_syscr); /* SYSCR */
inline un_divcr& DIVCR = *reinterpret_cast<un_divcr*>(addr_divcr); /* DIVCR */
inline un_mstcr& MSTCR = *reinterpret_cast<un_mstcr*>(addr_mstcr); /* MSTCR */
inline st_bsc& BSC = *reinterpret_cast<st_bsc*>(addr_syscr);       /* BSC */
inline st_intc& INTC = *reinterpret_cast<st_intc*>(addr_intc);     /* INTC */
inline st_sam& DMAC0A = *reinterpret_cast<st_sam*>(addr_mar0ar);   /* DMAC 0A */
inline st_sam& DMAC0B = *reinterpret_cast<st_sam*>(addr_mar0br);   /* DMAC 0B */
inline st_sam& DMAC1A = *reinterpret_cast<st_sam*>(addr_mar1ar);   /* DMAC 1A */
inline st_sam& DMAC1B = *reinterpret_cast<st_sam*>(addr_mar1br);   /* DMAC 1B */
inline st_fam& DMAC0 = *reinterpret_cast<st_fam*>(addr_mar0ar);    /* DMAC 0 */
inline st_fam& DMAC1 = *reinterpret_cast<st_fam*>(addr_mar1ar);    /* DMAC 1 */
inline st_flash& FLASH = *reinterpret_cast<st_flash*>(addr_flash); /* FLASH */
inline st_itu& ITU = *reinterpret_cast<st_itu*>(addr_tstr);        /* ITU */
inline st_itu0& ITU0 = *reinterpret_cast<st_itu0*>(addr_16tcr0);   /* ITU0 */
inline st_itu0& ITU1 = *reinterpret_cast<st_itu0*>(addr_16tcr1);   /* ITU1 */
inline st_itu0& ITU2 = *reinterpret_cast<st_itu0*>(addr_16tcr2);   /* ITU2 */
inline un_wdt& WDT = *reinterpret_cast<un_wdt*>(addr_tcsr);        /* WDT */
inline st_tmr01& TMR01 = *reinterpret_cast<st_tmr01*>(addr_8tcr0); /* TMR01 */
inline st_tmr23& TMR23 = *reinterpret_cast<st_tmr23*>(addr_8tcr2); /* TMR23 */
inline st_tmr0& TMR0 = *reinterpret_cast<st_tmr0*>(addr_8tcr0);    /* TMR0 */
inline st_tmr1& TMR1 = *reinterpret_cast<st_tmr1*>(addr_8tcr1);    /* TMR1 */
inline st_tmr2& TMR2 = *reinterpret_cast<st_tmr2*>(addr_8tcr2);    /* TMR2 */
inline st_tmr1& TMR3 = *reinterpret_cast<st_tmr1*>(addr_8tcr3);    /* TMR3 */
inline un_dastcr& DASTCR =
    *reinterpret_cast<un_dastcr*>(addr_dastcr);                 /* DASTCR */
inline st_da& DA = *reinterpret_cast<st_da*>(addr_dadr0);       /* D/A */
inline st_tpc& TPC = *reinterpret_cast<st_tpc*>(addr_tpmr);     /* TPC */
inline st_sci& SCI0 = *reinterpret_cast<st_sci*>(addr_smr0);    /* SCI0 */
inline st_sci& SCI1 = *reinterpret_cast<st_sci*>(addr_smr1);    /* SCI1 */
inline st_sci& SCI2 = *reinterpret_cast<st_sci*>(addr_smr2);    /* SCI2 */
inline st_smci& SMCI0 = *reinterpret_cast<st_smci*>(addr_smr0); /* SMCI0 */
inline st_smci& SMCI1 = *reinterpret_cast<st_smci*>(addr_smr1); /* SMCI1 */
inline st_smci& SMCI2 = *reinterpret_cast<st_smci*>(addr_smr2); /* SMCI2 */
inline st_ad& AD = *reinterpret_cast<st_ad*>(addr_addrah);      /* A/D */

}  // namespace H8Reg
}  // namespace eommpsys
