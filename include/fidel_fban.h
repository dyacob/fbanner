/*  fbanner Phonetic Mappings Here 
**
**  this follows the work done for sera2latex and avoids 
**  doing more efficient (for memory issues) new work.
**  adjustments are made for 7 bit output 
*/

#ifndef FIDEL_FBAN_H
#define FIDEL_FBAN_H 

#define FBANFIDEL 478


char e[]=""           ,               /* Define Vowel  elemants */
     u[]=""           ,  
     i[]=""           ,  
     a[]=""           ,  
     E[]=""           ,  
     I[]=""           ,  
     o[]=""           ,  
     Y[]=""           ,               /* Keep Y empty!!         */
    We[]=""           , 
    Wu[]=""           , 
    Wi[]=""           , 
    Wa[]=""           , 
    WE[]=""           , 
     W[]=""           , 
    WW[]="W"          , 
    Ya[]=""           , 

    ee[]="e"          ,               /* Define Vowel elemants for vowels*/
    uu[]="u"          ,  
    ii[]="i"          ,  
    aa[]="a"          ,  
    EE[]="E"          ,  
    II[]="I"          ,  
    oo[]="o"          ,  
     A[]="A"          ;              /* for africa symbol */


char h[] = "h"        ,              /* Define Consonants */
     l[] = "l"        ,  
     H[] = "H"        ,  
     m[] = "m"        ,  
    s2[] = "s"        , 
     r[] = "r"        ,  
     s[] = "s"        ,  
     x[] = "x"        ,  
     q[] = "q"        ,  
    q2[] = "q"        ,  
     Q[] = "Q"        ,  
     b[] = "b"        ,  
     v[] = "v"        ,  
     t[] = "t"        ,  
     c[] = "c"        ,  
    h2[] = "h"        ,  
     n[] = "n"        ,  
     N[] = "n"        ,  
     k[] = "k"        ,  
    k2[] = "k"        ,  
     K[] = "K"        ,  
     X[] = "X"        ,  
     w[] = "w"        ,  
    a2[] = ""         ,  
     z[] = "z"        ,  
     Z[] = "Z"        ,  
     y[] = "y"        ,  
     d[] = "d"        ,  
     D[] = "D"        ,  
     j[] = "j"        ,  
     g[] = "g"        ,  
     G[] = "G"        ,  
     T[] = "T"        ,  
     C[] = "C"        ,  
     P[] = "P"        ,  
     S[] = "S"        ,  
    S2[] = "D"        ,  
     f[] = "f"        ,  
     p[] = "p"        ;


char space[] = " "    ,  
    espace[] = ":"    ,  
     comma[] = ","    ,  
    scolon[] = ";"    ,  
    pcolon[] = ":"    ,  
     colon[] = ":"    ,  
    period[] = ":"    ,  
    eqmark[] = "?"    ,  
     parag[] = "*"    ,  
      slaq[] = "|"    ,  
       dot[] = "."    ,  
    lquote[] = "<"    ,  
    rquote[] = ">"    ,  
     qmark[] = "?"    ,  
       one[] = "1"    ,  
       two[] = "2"    ,  
     three[] = "3"    ,  
      four[] = "4"    ,  
      five[] = "5"    ,  
       six[] = "6"    ,  
     seven[] = "7"    ,  
     eight[] = "8"    ,  
      nine[] = "9"    ,  
       ten[] = "1"    ,  
      twen[] = "2"    ,  
      thir[] = "3"    ,  
     fourt[] = "4"    ,  
       fif[] = "5"    ,  
      sixt[] = "6"    ,  
    sevent[] = "7"    ,  
    eighty[] = "8"    ,  
     ninet[] = "9"    ,  
      hund[] = "1"    ,  
    tthous[] = "1"    ;

typedef struct {
          char* c;
          char* v;
       } phonset; 

phonset amharic[FBANFIDEL]=        /* Amharic Rules */
  {
    {h,a}, {h,u}, {h,i}, {h,a}, {h,E}, {h,Y}, {h,o},  {Y,Y},  /*   0 -   7 */
    {l,e}, {l,u}, {l,i}, {l,a}, {l,E}, {l,Y}, {l,o}, {l,Wa},  /*   8 -  15 */
    {h,a}, {h,u}, {h,i}, {h,a}, {h,E}, {h,Y}, {h,o}, {h,Wa},  /*  16 -  23 */
    {m,e}, {m,u}, {m,i}, {m,a}, {m,E}, {m,Y}, {m,o}, {m,We},  /*  24 -  31 */
    {Y,Y}, {m,Wi},{m,Wa},{m,WE},{m,W}, {Y,Y}, {Y,Y},  {Y,Y},  /*  32 -  39 */
    {s,e}, {s,u}, {s,i}, {s,a}, {s,E}, {s,Y}, {s,o}, {s,Wa},  /*  40 -  47 */
    {r,e}, {r,u}, {r,i}, {r,a}, {r,E}, {r,Y}, {r,o}, {r,Wa},  /*  48 -  44 */
    {s,e}, {s,u}, {s,i}, {s,a}, {s,E}, {s,Y}, {s,o}, {s,Wa},  /*  56 -  52 */
    {x,e}, {x,u}, {x,i}, {x,a}, {x,E}, {x,Y}, {x,o}, {x,Wa},  /*  64 -  60 */
    {q,e}, {q,u}, {q,i}, {q,a}, {q,E}, {q,Y}, {q,o}, {q,We},  /*  72 -  80 */
    {Y,Y}, {q,Wi},{q,Wa},{q,WE},{q,W}, {Y,Y}, {Y,Y},  {Y,Y},  /*  80 -  87 */
    {q2,e},{q2,u},{q2,i},{q2,a},{q2,E},{q2,Y},{q2,o}, {Y,Y},  /*  88 -  95 */
    {Q,e}, {Q,u}, {Q,i}, {Q,a}, {Q,E}, {Q,Y}, {Q,o}, {Q,We},  /*  96 - 103 */
    {Q,Wi},{Q,Wa},{Q,WE},{Q,W}, {Y,Y}, {Y,Y}, {Y,Y},  {Y,Y},  /* 104 - 111 */
    {b,e}, {b,u}, {b,i}, {b,a}, {b,E}, {b,Y}, {b,o}, {b,We},  /* 112 - 119 */
    {Y,Y}, {b,Wi},{b,Wa},{b,WE},{b,W}, {Y,Y}, {Y,Y},  {Y,Y},  /* 120 - 127 */
    {v,e}, {v,u}, {v,i}, {v,a}, {v,E}, {v,Y}, {v,o}, {v,Wa},  /* 128 - 135 */
    {t,e}, {t,u}, {t,i}, {t,a}, {t,E}, {t,Y}, {t,o}, {t,Wa},  /* 136 - 143 */
    {c,e}, {c,u}, {c,i}, {c,a}, {c,E}, {c,Y}, {c,o}, {c,Wa},  /* 144 - 151 */
    {h,a}, {h,u}, {h,i}, {h,a}, {h,E}, {h,Y}, {h,o}, {h,We},  /* 152 - 159 */
    {Y,Y}, {h,Wi},{h,Wa},{h,WE},{h,W}, {Y,Y}, {Y,Y},  {Y,Y},  /* 160 - 167 */
    {n,e}, {n,u}, {n,i}, {n,a}, {n,E}, {n,Y}, {n,o}, {n,Wa},  /* 168 - 175 */
    {N,e}, {N,u}, {N,i}, {N,a}, {N,E}, {N,Y}, {N,o}, {N,Wa},  /* 176 - 152 */
    {Y,aa},{Y,uu},{Y,ii},{Y,aa},{Y,EE},{Y,II},{Y,oo},{Y,ee},  /* 184 - 191 */
    {k,e}, {k,u}, {k,i}, {k,a}, {k,E}, {k,Y}, {k,o}, {k,We},  /* 192 - 164 */
    {Y,Y}, {k,Wi},{k,Wa},{k,WE},{k,W}, {Y,Y}, {Y,Y},  {Y,Y},  /* 200 - 171 */
    {k2,e},{k2,u},{k2,i},{k2,a},{k2,E},{k2,Y},{k2,o}, {Y,Y},  /* 208 - 215 */
    {h,e}, {h,u}, {h,i}, {h,a}, {h,E}, {h,Y}, {h,o}, {h,We},  /* 216 - 223 */
    {Y,Y}, {h,Wi},{h,Wa},{h,WE},{h,W}, {Y,Y}, {Y,Y},  {Y,Y},  /* 224 - 231 */
    {X,e}, {X,u}, {X,i}, {X,a}, {X,E}, {X,Y}, {X,o},  {Y,Y},  /* 232 - 239 */
    {w,e}, {w,u}, {w,i}, {w,a}, {w,E}, {w,Y}, {w,o},{WW,We},  /* 240 - 247 */
    {WW,Wu},{WW,Wi},{WW,Wa},{WW,WE},{WW,W}, {Y,Y}, {Y,Y},  {Y,Y},  /* 248 - 255 */
    {Y,aa},{Y,uu},{Y,ii},{Y,aa},{Y,EE},{Y,II},{Y,oo}, {Y,Y},  /* 256 - 263 */
    {z,e}, {z,u}, {z,i}, {z,a}, {z,E}, {z,Y}, {z,o}, {z,Wa},  /* 264 - 271 */
    {Z,e}, {Z,u}, {Z,i}, {Z,a}, {Z,E}, {Z,Y}, {Z,o}, {Z,Wa},  /* 272 - 279 */
    {y,e}, {y,u}, {y,i}, {y,a}, {y,E}, {y,Y}, {y,o}, {y,Wa},  /* 280 - 287 */
    {d,e}, {d,u}, {d,i}, {d,a}, {d,E}, {d,Y}, {d,o}, {d,Wa},  /* 288 - 295 */
    {D,e}, {D,u}, {D,i}, {D,a}, {D,E}, {D,Y}, {D,o}, {D,Wa},  /* 296 - 303 */
    {j,e}, {j,u}, {j,i}, {j,a}, {j,E}, {j,Y}, {j,o}, {j,Wa},  /* 304 - 311 */
    {g,e}, {g,u}, {g,i}, {g,a}, {g,E}, {g,Y}, {g,o}, {g,We},  /* 312 - 319 */
    {Y,Y}, {g,Wi},{g,Wa},{g,WE},{g,W}, {Y,Y}, {Y,Y},  {Y,Y},  /* 320 - 327 */
    {g,e}, {g,u}, {g,i}, {g,a}, {g,E}, {g,Y}, {g,o},  {Y,Y},  /* 328 - 335 */
    {G,e}, {G,u}, {G,i}, {G,a}, {G,E}, {G,Y}, {G,o}, {G,We},  /* 336 - 343 */
    {Y,Y}, {G,Wi},{G,Wa},{G,WE},{G,W}, {Y,Y}, {Y,Y},  {Y,Y},  /* 344 - 349 */
    {T,e}, {T,u}, {T,i}, {T,a}, {T,E}, {T,Y}, {T,o}, {T,Wa},  /* 350 - 357 */
    {C,e}, {C,u}, {C,i}, {C,a}, {C,E}, {C,Y}, {C,o}, {C,Wa},  /* 358 - 363 */
    {P,e}, {P,u}, {P,i}, {P,a}, {P,E}, {P,Y}, {P,o}, {P,Wa},  /* 364 - 371 */
    {S,e}, {S,u}, {S,i}, {S,a}, {S,E}, {S,Y}, {S,o}, {S,Wa},  /* 372 - 479 */
    {S,e}, {S,u}, {S,i}, {S,a}, {S,E}, {S,Y}, {S,o}, {Y, Y},  /* 380 - 387 */
    {f,e}, {f,u}, {f,i}, {f,a}, {f,E}, {f,Y}, {f,o}, {f,We},  /* 388 - 495 */
    {Y,Y}, {f,Wi},{f,Wa},{f,WE},{f,W}, {Y,Y}, {Y,Y},  {Y,Y},  /* 396 - 403 */
    {p,e}, {p,u}, {p,i}, {p,a}, {p,E}, {p,Y}, {p,o}, {p,We},  /* 404 - 411 */
    {Y,Y}, {p,Wi},{p,Wa},{p,WE},{p,W}, {Y,Y}, {Y,Y},  {Y,Y},  /* 412 - 419 */
    {m,Ya},{r,Ya},{f,Ya},{Y,Y}, {Y,Y}, {Y,Y}, {Y,Y},          /* 420 - 427 */
    {Y,Y}, {Y,Y}, {Y,Y}, {Y,Y}, {Y,Y}, {Y,Y}, {Y,Y},          /* 428 - 435 */

    {one,Y},{two,Y},{three,Y},{four,Y},{five,Y},{six,Y},{seven,Y},{eight,Y},{nine,Y},{ten,Y},
    {twen,Y},{thir,Y},{fourt,Y},{fif,Y},{sixt,Y},{sevent,Y},{eighty,Y},{ninet,Y},{hund,Y},{tthous,Y}, 
    {space,Y},{espace,Y},{comma,Y},{scolon,Y},{pcolon,Y},{colon,Y},{period,Y},
    {eqmark,Y},{parag,Y}, {Y,Y},{Y,Y},{slaq,Y},{dot,Y},{lquote,Y},{rquote,Y},{qmark,Y},
    {ee,Y}, {EE,Y}, {aa,Y}, {A,Y}
  };


phonset tigrigna[FBANFIDEL]=        /* Tigrigna Rules */
  {
    {h,e}, {h,u}, {h,i}, {h,a}, {h,E}, {h,Y}, {h,o},  {Y,Y},  /*   0 -   7 */
    {l,e}, {l,u}, {l,i}, {l,a}, {l,E}, {l,Y}, {l,o}, {l,Wa},  /*   8 -  15 */
    {H,e}, {H,u}, {H,i}, {H,a}, {H,E}, {H,Y}, {H,o}, {H,Wa},  /*  16 -  23 */
    {m,e}, {m,u}, {m,i}, {m,a}, {m,E}, {m,Y}, {m,o}, {m,We},  /*  24 -  31 */
    {Y,Y}, {m,Wi},{m,Wa},{m,WE},{m,W}, {Y,Y}, {Y,Y},  {Y,Y},  /*  32 -  39 */
    {s,e}, {s,u}, {s,i}, {s,a}, {s,E}, {s,Y}, {s,o}, {s,Wa},  /*  40 -  47 */
    {r,e}, {r,u}, {r,i}, {r,a}, {r,E}, {r,Y}, {r,o}, {r,Wa},  /*  48 -  44 */
    {s,e}, {s,u}, {s,i}, {s,a}, {s,E}, {s,Y}, {s,o}, {s,Wa},  /*  56 -  52 */
    {x,e}, {x,u}, {x,i}, {x,a}, {x,E}, {x,Y}, {x,o}, {x,Wa},  /*  64 -  60 */
    {q,e}, {q,u}, {q,i}, {q,a}, {q,E}, {q,Y}, {q,o}, {q,We},  /*  72 -  80 */
    {Y,Y}, {q,Wi},{q,Wa},{q,WE},{q,W}, {Y,Y}, {Y,Y},  {Y,Y},  /*  80 -  87 */
    {q2,e},{q2,u},{q2,i},{q2,a},{q2,E},{q2,Y},{q2,o}, {Y,Y},  /*  88 -  95 */
    {Q,e}, {Q,u}, {Q,i}, {Q,a}, {Q,E}, {Q,Y}, {Q,o}, {Q,We},  /*  96 - 103 */
    {Q,Wi},{Q,Wa},{Q,WE},{Q,W}, {Y,Y}, {Y,Y}, {Y,Y},  {Y,Y},  /* 104 - 111 */
    {b,e}, {b,u}, {b,i}, {b,a}, {b,E}, {b,Y}, {b,o}, {b,We},  /* 112 - 119 */
    {Y,Y}, {b,Wi},{b,Wa},{b,WE},{b,W}, {Y,Y}, {Y,Y},  {Y,Y},  /* 120 - 127 */
    {v,e}, {v,u}, {v,i}, {v,a}, {v,E}, {v,Y}, {v,o}, {v,Wa},  /* 128 - 135 */
    {t,e}, {t,u}, {t,i}, {t,a}, {t,E}, {t,Y}, {t,o}, {t,Wa},  /* 136 - 143 */
    {c,e}, {c,u}, {c,i}, {c,a}, {c,E}, {c,Y}, {c,o}, {c,Wa},  /* 144 - 151 */
    {h,e}, {h,u}, {h,i}, {h,a}, {h,E}, {h,Y}, {h,o}, {h,We},  /* 152 - 159 */
    {Y,Y}, {h,Wi},{h,Wa},{h,WE},{h,W}, {Y,Y}, {Y,Y},  {Y,Y},  /* 160 - 167 */
    {n,e}, {n,u}, {n,i}, {n,a}, {n,E}, {n,Y}, {n,o}, {n,Wa},  /* 168 - 175 */
    {N,e}, {N,u}, {N,i}, {N,a}, {N,E}, {N,Y}, {N,o}, {N,Wa},  /* 176 - 152 */
    {Y,aa},{Y,uu},{Y,ii},{Y,aa},{Y,EE},{Y,II},{Y,oo},{Y,ee},  /* 184 - 191 */
    {k,e}, {k,u}, {k,i}, {k,a}, {k,E}, {k,Y}, {k,o}, {k,We},  /* 192 - 164 */
    {Y,Y}, {k,Wi},{k,Wa},{k,WE},{k,W}, {Y,Y}, {Y,Y},  {Y,Y},  /* 200 - 171 */
    {k2,e},{k2,u},{k2,i},{k2,a},{k2,E},{k2,Y},{k2,o}, {Y,Y},  /* 208 - 215 */
    {K,e}, {K,u}, {K,i}, {K,a}, {K,E}, {K,Y}, {K,o}, {K,We},  /* 216 - 223 */
    {Y,Y}, {K,Wi},{K,Wa},{K,WE},{K,W}, {Y,Y}, {Y,Y},  {Y,Y},  /* 224 - 231 */
    {X,e}, {X,u}, {X,i}, {X,a}, {X,E}, {X,Y}, {X,o},  {Y,Y},  /* 232 - 239 */
    {w,e}, {w,u}, {w,i}, {w,a}, {w,E}, {w,Y}, {w,o},{WW,We},  /* 240 - 247 */
    {WW,Wu},{WW,Wi},{WW,Wa},{WW,WE},{WW,W}, {Y,Y}, {Y,Y},  {Y,Y},  /* 248 - 255 */
    {a2,ee},{a2,uu},{a2,ii},{a2,aa},{a2,EE},{a2,II},{a2,oo},{Y,Y}, /* 256 - 263 */
    {z,e}, {z,u}, {z,i}, {z,a}, {z,E}, {z,Y}, {z,o}, {z,Wa},  /* 264 - 271 */
    {Z,e}, {Z,u}, {Z,i}, {Z,a}, {Z,E}, {Z,Y}, {Z,o}, {Z,Wa},  /* 272 - 279 */
    {y,e}, {y,u}, {y,i}, {y,a}, {y,E}, {y,Y}, {y,o}, {y,Wa},  /* 280 - 287 */
    {d,e}, {d,u}, {d,i}, {d,a}, {d,E}, {d,Y}, {d,o}, {d,Wa},  /* 288 - 295 */
    {D,e}, {D,u}, {D,i}, {D,a}, {D,E}, {D,Y}, {D,o}, {D,Wa},  /* 296 - 303 */
    {j,e}, {j,u}, {j,i}, {j,a}, {j,E}, {j,Y}, {j,o}, {j,Wa},  /* 304 - 311 */
    {g,e}, {g,u}, {g,i}, {g,a}, {g,E}, {g,Y}, {g,o}, {g,We},  /* 312 - 319 */
    {Y,Y}, {g,Wi},{g,Wa},{g,WE},{g,W}, {Y,Y}, {Y,Y},  {Y,Y},  /* 320 - 327 */
    {g,e}, {g,u}, {g,i}, {g,a}, {g,E}, {g,Y}, {g,o},  {Y,Y},  /* 328 - 335 */
    {G,e}, {G,u}, {G,i}, {G,a}, {G,E}, {G,Y}, {G,o}, {G,We},  /* 336 - 343 */
    {Y,Y}, {G,Wi},{G,Wa},{G,WE},{G,W}, {Y,Y}, {Y,Y},  {Y,Y},  /* 344 - 351 */
    {T,e}, {T,u}, {T,i}, {T,a}, {T,E}, {T,Y}, {T,o}, {T,Wa},  /* 352 - 359 */
    {C,e}, {C,u}, {C,i}, {C,a}, {C,E}, {C,Y}, {C,o}, {C,Wa},  /* 360 - 367 */
    {P,e}, {P,u}, {P,i}, {P,a}, {P,E}, {P,Y}, {P,o}, {P,Wa},  /* 368 - 375 */
    {S,e}, {S,u}, {S,i}, {S,a}, {S,E}, {S,Y}, {S,o}, {S,Wa},  /* 376 - 483 */
    {S,e}, {S,u}, {S,i}, {S,a}, {S,E}, {S,Y}, {S,o}, {Y, Y},  /* 384 - 391 */
    {f,e}, {f,u}, {f,i}, {f,a}, {f,E}, {f,Y}, {f,o}, {f,We},  /* 392 - 399 */
    {Y,Y}, {f,Wi},{f,Wa},{f,WE},{f,W}, {Y,Y}, {Y,Y},  {Y,Y},  /* 400 - 407 */
    {p,e}, {p,u}, {p,i}, {p,a}, {p,E}, {p,Y}, {p,o}, {p,We},  /* 408 - 415 */
    {Y,Y}, {p,Wi},{p,Wa},{p,WE},{p,W}, {Y,Y}, {Y,Y},  {Y,Y},  /* 416 - 423 */
    {m,Ya},{r,Ya},{f,Ya},{Y,Y}, {Y,Y}, {Y,Y}, {Y,Y},          /* 424 - 430 */
    {Y,Y}, {Y,Y}, {Y,Y}, {Y,Y}, {Y,Y}, {Y,Y}, {Y,Y},          /* 431 - 437 */

    {one,Y},{two,Y},{three,Y},{four,Y},{five,Y},{six,Y},{seven,Y},{eight,Y},{nine,Y},{ten,Y},
    {twen,Y},{thir,Y},{fourt,Y},{fif,Y},{sixt,Y},{sevent,Y},{eighty,Y},{ninet,Y},{hund,Y},{tthous,Y}, 
    {space,Y},{espace,Y},{comma,Y},{scolon,Y},{pcolon,Y},{colon,Y},{period,Y},
    {eqmark,Y},{parag,Y}, {Y,Y},{Y,Y},{slaq,Y},{dot,Y},{lquote,Y},{rquote,Y},{qmark,Y},
    {ee,Y}, {EE,Y}, {aa,Y}, {A,Y}
  };


phonset ge_ez[FBANFIDEL]=        /* Ge'ez Rules */
  {
    {h,e}, {h,u}, {h,i}, {h,a}, {h,E}, {h,Y}, {h,o},  {Y,Y},  /*   0 -   7 */
    {l,e}, {l,u}, {l,i}, {l,a}, {l,E}, {l,Y}, {l,o}, {l,Wa},  /*   8 -  15 */
    {H,e}, {H,u}, {H,i}, {H,a}, {H,E}, {H,Y}, {H,o}, {H,Wa},  /*  16 -  23 */
    {m,e}, {m,u}, {m,i}, {m,a}, {m,E}, {m,Y}, {m,o}, {m,We},  /*  24 -  31 */
    {Y,Y}, {m,Wi},{m,Wa},{m,WE},{m,W}, {Y,Y}, {Y,Y},  {Y,Y},  /*  32 -  39 */
    {s2,e},{s2,u},{s2,i},{s2,a},{s2,E},{s2,Y},{s2,o},{s2,Wa}, /*  40 -  47 */
    {r,e}, {r,u}, {r,i}, {r,a}, {r,E}, {r,Y}, {r,o}, {r,Wa},  /*  48 -  44 */
    {s,e}, {s,u}, {s,i}, {s,a}, {s,E}, {s,Y}, {s,o}, {s,Wa},  /*  56 -  52 */
    {x,e}, {x,u}, {x,i}, {x,a}, {x,E}, {x,Y}, {x,o}, {x,Wa},  /*  64 -  60 */
    {q,e}, {q,u}, {q,i}, {q,a}, {q,E}, {q,Y}, {q,o}, {q,We},  /*  72 -  80 */
    {Y,Y}, {q,Wi},{q,Wa},{q,WE},{q,W}, {Y,Y}, {Y,Y},  {Y,Y},  /*  80 -  87 */
    {q2,e},{q2,u},{q2,i},{q2,a},{q2,E},{q2,Y},{q2,o}, {Y,Y},  /*  88 -  95 */
    {Q,e}, {Q,u}, {Q,i}, {Q,a}, {Q,E}, {Q,Y}, {Q,o}, {Q,We},  /*  96 - 103 */
    {Q,Wi},{Q,Wa},{Q,WE},{Q,W}, {Y,Y}, {Y,Y}, {Y,Y},  {Y,Y},  /* 104 - 111 */
    {b,e}, {b,u}, {b,i}, {b,a}, {b,E}, {b,Y}, {b,o}, {b,We},  /* 112 - 119 */
    {Y,Y}, {b,Wi},{b,Wa},{b,WE},{b,W}, {Y,Y}, {Y,Y},  {Y,Y},  /* 120 - 127 */
    {v,e}, {v,u}, {v,i}, {v,a}, {v,E}, {v,Y}, {v,o}, {v,Wa},  /* 128 - 135 */
    {t,e}, {t,u}, {t,i}, {t,a}, {t,E}, {t,Y}, {t,o}, {t,Wa},  /* 136 - 143 */
    {c,e}, {c,u}, {c,i}, {c,a}, {c,E}, {c,Y}, {c,o}, {c,Wa},  /* 144 - 151 */
    {h2,e},{h2,u},{h2,i},{h2,a},{h2,E},{h2,Y},{h2,o},{h2,We}, /* 152 - 159 */
    {Y,Y},{h2,Wi},{h2,Wa},{h2,WE},{h2,W},{Y,Y},{Y,Y},  {Y,Y}, /* 160 - 167 */
    {n,e}, {n,u}, {n,i}, {n,a}, {n,E}, {n,Y}, {n,o}, {n,Wa},  /* 168 - 175 */
    {N,e}, {N,u}, {N,i}, {N,a}, {N,E}, {N,Y}, {N,o}, {N,Wa},  /* 176 - 152 */
    {Y,aa},{Y,uu},{Y,ii},{Y,aa},{Y,EE},{Y,II},{Y,oo},{Y,ee},  /* 184 - 191 */
    {k,e}, {k,u}, {k,i}, {k,a}, {k,E}, {k,Y}, {k,o}, {k,We},  /* 192 - 164 */
    {Y,Y}, {k,Wi},{k,Wa},{k,WE},{k,W}, {Y,Y}, {Y,Y},  {Y,Y},  /* 200 - 171 */
    {k2,e},{k2,u},{k2,i},{k2,a},{k2,E},{k2,Y},{k2,o}, {Y,Y},  /* 208 - 215 */
    {K,e}, {K,u}, {K,i}, {K,a}, {K,E}, {K,Y}, {K,o}, {K,We},  /* 216 - 223 */
    {Y,Y}, {K,Wi},{K,Wa},{K,WE},{K,W}, {Y,Y}, {Y,Y},  {Y,Y},  /* 224 - 231 */
    {X,e}, {X,u}, {X,i}, {X,a}, {X,E}, {X,Y}, {X,o},  {Y,Y},  /* 232 - 239 */
    {w,e}, {w,u}, {w,i}, {w,a}, {w,E}, {w,Y}, {w,o},{WW,We},  /* 240 - 247 */
    {WW,Wu},{WW,Wi},{WW,Wa},{WW,WE},{WW,W}, {Y,Y}, {Y,Y},  {Y,Y},  /* 248 - 255 */
    {a2,ee},{a2,uu},{a2,ii},{a2,aa},{a2,EE},{a2,II},{a2,oo},{Y,Y},  /* 256 - 263 */
    {z,e}, {z,u}, {z,i}, {z,a}, {z,E}, {z,Y}, {z,o}, {z,Wa},  /* 264 - 271 */
    {Z,e}, {Z,u}, {Z,i}, {Z,a}, {Z,E}, {Z,Y}, {Z,o}, {Z,Wa},  /* 272 - 279 */
    {y,e}, {y,u}, {y,i}, {y,a}, {y,E}, {y,Y}, {y,o}, {y,Wa},  /* 280 - 287 */
    {d,e}, {d,u}, {d,i}, {d,a}, {d,E}, {d,Y}, {d,o}, {d,Wa},  /* 288 - 295 */
    {D,e}, {D,u}, {D,i}, {D,a}, {D,E}, {D,Y}, {D,o}, {D,Wa},  /* 296 - 303 */
    {j,e}, {j,u}, {j,i}, {j,a}, {j,E}, {j,Y}, {j,o}, {j,Wa},  /* 304 - 311 */
    {g,e}, {g,u}, {g,i}, {g,a}, {g,E}, {g,Y}, {g,o}, {g,We},  /* 312 - 319 */
    {Y,Y}, {g,Wi},{g,Wa},{g,WE},{g,W}, {Y,Y}, {Y,Y},  {Y,Y},  /* 320 - 327 */
    {g,e}, {g,u}, {g,i}, {g,a}, {g,E}, {g,Y}, {g,o},  {Y,Y},  /* 328 - 335 */
    {G,e}, {G,u}, {G,i}, {G,a}, {G,E}, {G,Y}, {G,o}, {G,We},  /* 336 - 343 */
    {Y,Y}, {G,Wi},{G,Wa},{G,WE},{G,W}, {Y,Y}, {Y,Y},  {Y,Y},  /* 344 - 349 */
    {T,e}, {T,u}, {T,i}, {T,a}, {T,E}, {T,Y}, {T,o}, {T,Wa},  /* 350 - 357 */
    {C,e}, {C,u}, {C,i}, {C,a}, {C,E}, {C,Y}, {C,o}, {C,Wa},  /* 358 - 363 */
    {P,e}, {P,u}, {P,i}, {P,a}, {P,E}, {P,Y}, {P,o}, {P,Wa},  /* 364 - 371 */
    {S,e}, {S,u}, {S,i}, {S,a}, {S,E}, {S,Y}, {S,o}, {S,Wa},  /* 372 - 479 */
    {S2,e},{S2,u},{S2,i},{S2,a},{S2,E},{S2,Y},{S2,o},{Y, Y},  /* 380 - 387 */
    {f,e}, {f,u}, {f,i}, {f,a}, {f,E}, {f,Y}, {f,o}, {f,We},  /* 388 - 495 */
    {Y,Y}, {f,Wi},{f,Wa},{f,WE},{f,W}, {Y,Y}, {Y,Y},  {Y,Y},  /* 396 - 403 */
    {p,e}, {p,u}, {p,i}, {p,a}, {p,E}, {p,Y}, {p,o}, {p,We},  /* 404 - 411 */
    {Y,Y}, {p,Wi},{p,Wa},{p,WE},{p,W}, {Y,Y}, {Y,Y},  {Y,Y},  /* 412 - 419 */
    {m,Ya},{r,Ya},{f,Ya},{Y,Y}, {Y,Y}, {Y,Y}, {Y,Y},          /* 420 - 427 */
    {Y,Y}, {Y,Y}, {Y,Y}, {Y,Y}, {Y,Y}, {Y,Y}, {Y,Y},          /* 428 - 435 */

    {one,Y},{two,Y},{three,Y},{four,Y},{five,Y},{six,Y},{seven,Y},{eight,Y},{nine,Y},{ten,Y},
    {twen,Y},{thir,Y},{fourt,Y},{fif,Y},{sixt,Y},{sevent,Y},{eighty,Y},{ninet,Y},{hund,Y},{tthous,Y}, 
    {space,Y},{espace,Y},{comma,Y},{scolon,Y},{pcolon,Y},{colon,Y},{period,Y},
    {eqmark,Y},{parag,Y}, {Y,Y},{Y,Y},{slaq,Y},{dot,Y},{lquote,Y},{rquote,Y},{qmark,Y},
    {ee,Y}, {EE,Y}, {aa,Y}, {A,Y}
  };
phonset*  fscript[] = {amharic,ge_ez,tigrigna};

#endif  /* FIDEL_FBAN_H */
