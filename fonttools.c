#include <stdio.h>
#include <stdlib.h>
#include <libeth/fidel.h>
#include <libeth/etstdio.h>
#include <libeth/etstring.h>
#include <libeth/etctype.h>
#include <libeth/sysinfo.h>
#include "include/fban.h"

extern int UniToTraditional[];

#ifdef __STDC__
  bdffont* read_bdf ( FILE* fp );
  void draw_word    ( FCHAR* word, bdffont Ffont[], bdffont Lfont[], MyFlags* fbanFlags, LibEthFlags* lethFlags);
  void draw_word_r  ( FCHAR* word, bdffont Ffont[], bdffont Lfont[], MyFlags* fbanFlags, LibEthFlags* lethFlags);
  char get_fban_char ( FCHAR uniAddr, LibEthFlags* lethFlags );
#endif /* __STDC__ */


/*  READ_BDF  -  reads from file .bdf file and constructs FIDEL bit array */


int lfont_h=0, ffont_h=0;   /* sigh... we need to know who is taller to universalize */
int lstart=0, fstart=0;

bdffont* 
read_bdf (fp) 
  FILE* fp;
{

int width;
int bitmap;
boolean done;
int bbyoff;
register int i,j,k;
int fbxx,fbyy,font_w,font_h;
int start,end;
char str[WSIZE];
bdffont* font;



  start = end = NIL;
  done = false;
  while ( !done ) 
    {
      fscanf ( fp, "%s", str );
      if ( !strcmp ( "CHARS",str ) )
        {
          fscanf ( fp, "%d", &end );
          done = true;
        }
      else if ( !strcmp ( "FONTBOUNDINGBOX", str) )
        fscanf ( fp, "%d%d%d%d", &font_w, &font_h, &fbxx, &fbyy );
    }

  if ( !ffont_h ) 
    {
      ffont_h = font_h;
      fstart = start;
    }
  else       
    {
      lfont_h = font_h;
      lstart = start;
    }

  font = (bdffont *) malloc ( end*sizeof(bdffont) );

  for ( k=0; k < end; k++ ) 
    {
      done = false;
      while ( !done ) 
        {
          fscanf (fp, "%s", str );
          if ( !strcmp ( "ENCODING", str ) ) 
            fscanf ( fp, "%d", &font[k].myAddr );
          else if ( !strcmp ( "DWIDTH", str ) ) 
            fscanf ( fp, "%d", &font[k].dwx0 );
          else if ( !strcmp ( "BBX", str ) )
            done = true;
        }

      fscanf (fp, "%d%d%d%d", &font[k].bbw, &font[k].bbh, &font[k].bbxoff, &bbyoff );
      font[k].my_yoff = (font_h - font[k].bbh) - bbyoff;
      font[k].bits = (char **) malloc(font[k].bbh*sizeof(char *));

      fscanf ( fp, "%s", str );   /* read and ignore BITMAP line */

      fscanf ( fp, "%s", str );
      font[k].my_width = width = strlen(str)/2;
    
      font[k].bits[0] = (char *) malloc(font[k].bbh*width*sizeof(char));
      for ( j = 0; j < font[k].bbh; j++ )
        font[k].bits[j] = font[k].bits[0] + j*width;
   
      for ( j = 0; j < width; j++) 
        {
          sscanf( &str[j*2], "%2x", &bitmap );
          font[k].bits[0][j] = bitmap;
        } 

      for ( i = 1; i < font[k].bbh; i++ ) 
         for ( j = 0; j < width; j++ ) 
           {
             fscanf ( fp, "%2x", &bitmap );
             font[k].bits[i][j] = bitmap;
           }

    }  /* end k loop */


  return ( font );

}


void 
draw_word ( word, Ffont, Lfont, fbanFlags, lethFlags )
  FCHAR* word;
  bdffont Ffont[];
  bdffont Lfont[];
  MyFlags* fbanFlags;
  LibEthFlags* lethFlags;
{

unsigned char trow, vrow, shift, skip;
register unsigned int addr;
register int i,j,k,l,m;
int kBegin, kEnd, lBegin, lEnd;
int jBegin, jEnd; 
enum Scripts script;
boolean done[WSIZE],Done = false;
boolean setShift; 
bdffont* Font;
int ldiff=0, lNext=0, fdiff=0, diff, font_h, yDiff;


  if ( lfont_h > ffont_h ) 
    {
      fdiff = lfont_h - ffont_h;
      font_h = lfont_h;
    }
  else 
    {
      ldiff = ffont_h - lfont_h;
      font_h = ffont_h;
    }

  for ( k = 0; word[k] != '\0'; k++ ) 
    done[k] = false;

  if ( fbanFlags->mirror ) 
    {
      kBegin = fidel_strlen (word) - 1;
      kEnd   = -1;  
    }
  else
    {
      kBegin = 0;  
      kEnd   = fidel_strlen (word);
    }

  if ( fbanFlags->fliph ) 
    {
      lBegin = font_h - 1;
      lEnd   = -1;  
    }
  else
    {
      lBegin = 0;  
      lEnd   = font_h;
    }

  l = lBegin;
  while ( !Done ) 
   {

     for ( k = kBegin; k != kEnd; k = ( (kEnd > kBegin) ? k++ : k-- ) ) 
       {

         addr = word[k];
         if ( addr == NIL )  /* skip instead of print blank space */
           continue;     
         if ( 0 < addr && addr < ANSI )
           {
             script = latin;
             Font   = Lfont;
             diff   = ldiff; 
           }
         else if ( isethiopic(addr) && !isprivate(addr) ) 
           {
             script  = fidel;
             Font    = Ffont;
             diff    = fdiff; 
           }
         else if ( isprivate(addr) )
           {
             script = special;
             Font   = Ffont;
             diff   = fdiff; 
           }
         else
           script = greek;

         addr = 0;                               /* reset address for local font */
         while ( word[k] != Font[addr].myAddr )
           addr++;
         if ( fbanFlags->flipv ) 
           {
             jBegin =  Font[addr].my_width-1;
             jEnd   = -1;  
           }
         else
           {
             jBegin = 0;  
             jEnd   = Font[addr].my_width;
           }

        if ( !done[k] ) 
          {

            lNext  = l;
            yDiff  = Font[addr].my_yoff + diff;
            lNext -= yDiff; 

            setShift = false;
            skip = 0;
            for ( j = jBegin; j != jEnd; j = ( (jEnd > jBegin) ? j++ : j-- ), setShift = false , skip = 0) 
              for ( m = 0; m < 8;  m++ ) 
              if ( j*8+(7-m) < Font[addr].bbw )
                {
                  if ( (lEnd > lBegin && lNext < 0) 
                      || (lBegin > lEnd && l >= Font[addr].bbh + yDiff) ) 
                    fprintf ( stdout, " " );
                  else 
                    { 
                      trow  = Font[addr].bits[lNext][j];
                      shift = (7-m) + skip;
                      if ( jEnd < jBegin )
                        { 
                          vrow = 0;
                          for ( i = 0x01; i <= 0x80; i <<= 1 )      /* mirror copy bits */
                            {
                              if (i != 0x01) 
                                vrow <<= 1;
                              if (trow & i)  
                                vrow  |= 0x01;
                            }
                          if ( (setShift && Font[addr].bbw%8 != 0) || Font[addr].bbw < 8 )   
                            {
                              vrow <<= 8-Font[addr].bbw%8;
                            }
                          trow = vrow;
                        } 
                     
                      trow >>= shift; 
                      trow  &= 0x01; 

                      if ( trow ) 
                        if ( fbanFlags->use_alfa )
                          switch ( script ) 
                            {
                              case latin :
                                fprintf ( stdout,"%c", word[k] );
                                break;

                              case special :
                              case fidel :
                                fprintf ( stdout, "%c", get_fban_char( word[k], lethFlags ) );
                                break;

                              case greek :
                              default :
                                break;
                            } 
                        else if ( fbanFlags->use_geez )
                          switch ( script ) 
                            {
                              case latin :
                                fprintf ( stdout,"%c", word[k] );
                                break;

                              case special :
                              case fidel :
                                fidel_putc ( word[k], lethFlags );
                                break;

                              case greek :
                              default :
                                break;
                            }
                        else
                          fprintf ( stdout, "%s", fbanFlags->sym );
                      else
                        fprintf ( stdout, " " );

                    } /* end else ( l < Font[addr].my_yoff + diff ) */

                } /* end if j */
              else
                {
                  setShift = true;
                  skip++;
                } /* end m loop */

              if ( ( lEnd > lBegin && lNext == Font[addr].bbh - 1 ) 
                   || ( lBegin > lEnd && lNext == 0 ) ) 
                done[k] = true; 

          } /* if ( !done[k] ) */
        else
          for ( j = 0; j < Font[addr].bbw; j++ ) 
            fprintf ( stdout, " " );

        if ( script == latin  )
          fprintf ( stdout, "  " );    /* Latin kerning */
        else
          for ( i = 0; i < (Font[addr].dwx0 - Font[addr].bbw); i++ )  /* Fidel Kerning */
            fprintf ( stdout, " " );


    } /* end for */

    fprintf ( stdout, "\n" );

    Done = true;
    for ( i = 0; word[i] != '\0'; i++ ) 
      Done *= done[i];

    l =  (lEnd > lBegin) ? l++ : l-- ;

  } /* end while ( !Done ) */

}

void 
draw_word_r ( word, Ffont, Lfont, fbanFlags, lethFlags )
  FCHAR* word;
  bdffont Ffont[];
  bdffont Lfont[];
  MyFlags* fbanFlags;
  LibEthFlags* lethFlags;
{

unsigned char trow, vrow, shift, skip;
register unsigned int addr;
register int i,j,k,l,m;
int kBegin, kEnd, lBegin, lEnd;
int jBegin, jEnd; 
bdffont* Font;
enum Scripts script;
int ldiff=0,fdiff=0;
boolean setShift; 


  if ( lfont_h > ffont_h ) 
    fdiff = lfont_h-ffont_h;
  else 
    ldiff = ffont_h-lfont_h;

  if ( fbanFlags->mirror ) 
    {
      kBegin = fidel_strlen (word) - 1;
      kEnd   = -1;  
    }
  else
    {
      kBegin = 0;  
      kEnd   = fidel_strlen (word);
    }


  for ( k = kBegin; k != kEnd; k = ( (kEnd > kBegin) ? k++ : k-- ) ) 
    {

      addr = word[k];
      if ( addr == NIL )  /* skip instead of print blank space */
        continue;     
      if ( 0 < addr && addr < ANSI )
        {
          script = latin;
          Font   = Lfont;
        }
      else if ( isethiopic(addr) && !isprivate(addr) ) 
        {
          script  = fidel;
          Font    = Ffont;
        }
      else if ( isprivate(addr) )
        {
          script = special;
          Font   = Ffont;
        }
      else
        script = greek;

      addr = 0;                               /* reset address for local font */
      while ( word[k] != Font[addr].myAddr )
        addr++;

      if ( fbanFlags->fliph ) 
        {
          lBegin =  Font[addr].bbh-1;
          lEnd   = -1;  
        }
      else
        {
          lBegin = 0;  
          lEnd   = Font[addr].bbh;
        }

      if ( fbanFlags->flipv ) 
        {
          jBegin =  Font[addr].my_width-1;
          jEnd   = -1;  
        }
      else
        {
          jBegin = 0;  
          jEnd   = Font[addr].my_width;
        }

      setShift = false;
      skip = 0;
      for ( j = jBegin; j != jEnd; j = ( (jEnd > jBegin) ? j++ : j-- ), setShift = false , skip = 0) 
        for ( m = 0; m < 8;  m++ ) 
        if ( j*8+(7-m) < Font[addr].bbw )
          {
            for ( l = lBegin; l != lEnd; l = ( (lEnd > lBegin) ? l++ : l-- ) )
              { 
                trow = Font[addr].bits[l][j];
                shift = (7-m) + skip;
                if ( jEnd < jBegin )
                  { 
                    vrow = 0;
                    for ( i = 0x01; i <= 0x80; i <<= 1 )      /* mirror copy bits */
                      {
                        if (i != 0x01) 
                          vrow <<= 1;
                        if (trow & i)  
                          vrow  |= 0x01;
                      }
                    if ( (setShift && Font[addr].bbw%8 != 0) || Font[addr].bbw < 8 )   
                      vrow <<= 8-Font[addr].bbw%8;
                    trow = vrow;
                  } 
                     
                trow >>= shift; 
                trow  &= 0x01; 

                if ( trow ) 
                  if ( fbanFlags->use_alfa )
                    switch ( script ) 
                      {
                        case latin :
                          fprintf ( stdout,"%c", word[k] );
                          break;

                        case special :
                        case fidel :
                          fprintf ( stdout, "%c", get_fban_char( word[k], lethFlags ) );
                          break;

                        case greek :
                        default :
                          break;
                      }
                    else if ( fbanFlags->use_geez )
                      switch ( script ) 
                        {
                          case latin :
                            fprintf ( stdout,"%c", word[k] );
                            break;

                          case special :
                          case fidel :
                            fidel_putc ( word[k], lethFlags );
                            break;

                          case greek :
                          default :
                            break;
                        }
                  else
                    fprintf ( stdout, "%s", fbanFlags->sym );
                else
                  fprintf ( stdout, " " );

              } /* end l loop */

            fprintf ( stdout, "\n" );

          } /* end m loop */
        else
          {
            setShift = true;
            skip++;
          }

        fprintf ( stdout, "\n\n" );

    } /* end k loop */

    fprintf ( stdout, "\n" );

}


char
get_fban_char ( uniAddr, lethFlags )
  FCHAR uniAddr;
  LibEthFlags* lethFlags;
{


char ch;
unsigned char* fidelName;


  fidelName = fidel_sputc ( uniAddr, lethFlags );
  ch =  ( fidelName[0] == '`' || uniAddr == WORDSPACE) ? fidelName[1] : fidelName[0] ;

  free ( fidelName );
  return ( ch );

}
