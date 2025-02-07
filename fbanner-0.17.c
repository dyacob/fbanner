/*
**  fbanner 0.17
**
**  This is free software; you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation; either version 1, or (at your option)
**  any later version.  See the included "COPYING" file.
** 
**  Admas Concepts 1995, Ge'ez Frontiers Foundation 1997
** 
*/

#define ADMAS_UTIL "fbanner"
#define ADMAS_UTIL_MAJOR_VERSION 0.1
#define ADMAS_UTIL_MINOR_VERSION 7
#define ADMAS_UTIL_EXPORT_DATE "Wed Dec 11 21:39:02 EET 1996"

#include <stdio.h>
#include <signal.h>
#include <syslog.h>
#include <string.h>
#include <libeth/etstdlib.h>
#include <libeth/etstdio.h>
#include "include/fban.h"

extern void draw_word(), draw_word_r(); 
extern bdffont* read_bdf();
extern LS LnS[];


#ifdef __STDC__
  int flag_reset ( int argc, char **argv, MyFlags** fbanFlags, LibEthFlags** lethFlags );
  static void sig_term ( int signo );
#else
  int flag_reset (),
  static void sig_term ();
#endif /* __STDC__ */

/*-------------------------------------------------------------------------//
//                                                                         //
//  Main reads input switches, does file read-in, and sends one argv at    //
//  at a time to the transliteration subroutines.                          //
//                                                                         //
//-------------------------------------------------------------------------*/

void 
main (argc,argv)
  int argc;
  char **argv;
{

int start;
register int i;
FCHAR* out_string = NULL;
char eth_font_name[WSIZE]; 
char lat_font_name[WSIZE]; 
FILE* inptr;
LibEthFlags* lethFlags = NULL;
MyFlags* fbanFlags = NULL;
bdffont *ffont, *lfont;




/*-------Set Break Out Call Backs---------------------------------------------*/

  if (signal(SIGTERM, sig_term) == SIG_ERR)    /* catch kill commands */
    fprintf (stderr, "can't catch SIGTERM");
  if (signal(SIGINT, sig_term) == SIG_ERR)     /* catch Control-C     */
    fprintf (stderr, "can't catch SIGINT");

/*-------What Does the User Want... ------------------------------------------*/

  start = flag_reset ( argc, argv, &fbanFlags, &lethFlags );


/*-------Flags Set, Now Read in Font------------------------------------------*/

  sprintf ( eth_font_name, "%s/%s", FONTDIR, ETHFONTNAME );

  if ( (inptr = fopen(eth_font_name,"r")) == NULL )
    {
      fprintf ( stderr, "\n*** I cant read from %s ***\n", eth_font_name );
      exit (1);
    }
  ffont = read_bdf ( inptr );
  fclose ( inptr );

  sprintf ( lat_font_name, "%s/%s", FONTDIR, LATFONTNAME );

  if ( (inptr=fopen(lat_font_name,"r")) == NULL )
    {
      fprintf(stderr,"\n*** I cant read from %s ***\n",lat_font_name);
      exit(1);
    }
  lfont = read_bdf ( inptr );
  fclose ( inptr );


/*-------Fonts Read, Now It's Banner Time!------------------------------------*/


  for ( i = start; i < argc; i++ ) 
    {
      out_string = sget_fstring ( argv[i], lethFlags );

      if ( fbanFlags->rotate )
        draw_word_r ( out_string, ffont, lfont, fbanFlags, lethFlags );
      else
        draw_word ( out_string, ffont, lfont, fbanFlags, lethFlags );

      free ( out_string );
    }

/*-------Lets Be A Good Citizen-----------------------------------------------*/

  free (lethFlags);
  free (fbanFlags);
  exit (0);

}





/*----------------------------------------------------------------------------//
//                                                                            //
//  flag_reset is a simple routine that reads input options and resets        //
//  the defautls.                                                             //
//                                                                            //
//----------------------------------------------------------------------------*/


int 
flag_reset ( argc, argv, fbanFlags, lethFlags )
  int argc;
  char** argv;
  MyFlags** fbanFlags;
  LibEthFlags** lethFlags;
{

register int i, j, k;
char* lang2=NULL;
extern char* ISO639_2Names[];   /* data found in etstdlib.c */
extern char* ISO639_3Names[];

/*---------------- Don't Waste Time Initializing -We Gone!--------------------*/

  if ( argc == 1 ) 
    goto DEFAULT; 

/*---------------- Define and Initialize Flag Values -------------------------*/


  *lethFlags  =  SetDefaultLibEthFlags (LETLANGMINOR, MYLANGMAJOR, MYLANGMAJOR);
  (*lethFlags)->minor = (*lethFlags)->top;

  *fbanFlags             = (MyFlags *) malloc ( sizeof(MyFlags) );
  (*fbanFlags)->use_alfa = false;
  (*fbanFlags)->use_geez = false;
  (*fbanFlags)->rotate   = false;
  (*fbanFlags)->mirror   = false;
  (*fbanFlags)->flipv    = false;
  (*fbanFlags)->fliph    = false;
  strcpy ( (*fbanFlags)->sym, MYSYMBOL );

/*-------------End Define and Initialize Flag Values -------------------------*/

  i = 0;
  while ( ++i < argc ) 
    {
      if ( argv[i][0] == '-' || argv[i][0] == '+' ) 
        {
          switch ( toupper(argv[i][1]) ) 
            {

              case 'A' :  (*fbanFlags)->use_alfa = true;
                          (*lethFlags)->csOut = sera;
                          break;
              case 'F' :  if ( toupper(argv[i][2]) == 'V') /* Flip Characters Vertical */
                            (*fbanFlags)->flipv =! (*fbanFlags)->flipv;
                          else                             /* Flip Characters Horizontal */
                            (*fbanFlags)->fliph =! (*fbanFlags)->fliph;
                          break;
              case 'U' :
              case 'G' :  (*fbanFlags)->use_geez = true;
                          break;
              case 'L' :  j=-1;
                          while( ++j < NUMLANGS 
                                  && ( strncmp(argv[i+1], ISO639_2Names[j], 2)
                                    && strncmp(argv[i+1], ISO639_3Names[j], 3) ) );
/*
                          if (j < NUMLANGS )
                            (*lethFlags)->minor  =& LnS[j];
                          if (j == latin)
                            (*lethFlags)->major  =& LnS[MYLANGMAJOR]; 
*/
                          if ( j == NUMLANGS )
                            {
                              fprintf (stderr, "Language %s Not Supported\n",argv[i+1]);
                              exit (1);
                            }
                          k=-1;
                          if ( (lang2 = strstr(argv[i+1],"~")) )  /* Minor Lang is Passed */
                             while( ++k < NUMLANGS 
                                     && ( strncmp((lang2+1), ISO639_2Names[k], 2)
                                       && strncmp((lang2+1), ISO639_3Names[k], 3) ) );
                          if ( k == NUMLANGS )
                            {
                              fprintf (stderr, "Language %s Not Supported\n",argv[i+1]);
                              exit (1);
                            }

                          (*lethFlags)->top = (*lethFlags)->out =& LnS[j];

                          if ( lang2 != NULL )
                            (*lethFlags)->minor =& LnS[k];  
                          else if ( (*lethFlags)->top == (*lethFlags)->minor )
                            (*lethFlags)->minor = (*lethFlags)->major;  

                          (*lethFlags)->major = (*lethFlags)->top;  

                          i++;
                          break; 

              case 'M' :  (*fbanFlags)->mirror = true;    /* Draw Mirrored Text */
                          break;
              case 'R' :  j = 1;
                          while ( argv[i][j+1] == 'r' ) j++;
                          j %= 4;
                          if ( argv[i][0] == '-' ) 
                            {
                             if ( j == 1 )
                               {
                                 (*fbanFlags)->rotate = true;    /* Draw Rotated Text */
                                 (*fbanFlags)->fliph  = true;    /* Flip Characters Horizontal */
                               }
                             else if ( j == 2 )
                               {
                                 (*fbanFlags)->fliph  = true;    /* Flip Characters Horizontal */
                                 (*fbanFlags)->flipv  = true;    /* Flip Characters Horizontal */
                                 (*fbanFlags)->mirror = true;    /* Draw Mirrored Text */
                               }
                             else if ( j == 3 )
                               {
                                 (*fbanFlags)->rotate = true;    /* Draw Rotated Text */
                                 (*fbanFlags)->flipv  = true;    /* Flip Characters Horizontal */
                                 (*fbanFlags)->mirror = true;    /* Draw Mirrored Text */
                               }
                             break;
                            }
                          if ( argv[i][0] == '+' )
                            {
                             if ( j == 1 )
                               {
                                 (*fbanFlags)->rotate = true;    /* Draw Rotated Text */
                                 (*fbanFlags)->mirror = true;    /* Draw Mirrored Text */
                                 (*fbanFlags)->flipv  = true;    /* Flip Characters Horizontal */
                               }
                             else if ( j == 2 )
                               {
                                 (*fbanFlags)->fliph  = true;    /* Flip Characters Horizontal */
                                 (*fbanFlags)->flipv  = true;    /* Flip Characters Horizontal */
                                 (*fbanFlags)->mirror = true;    /* Draw Mirrored Text */
                               }
                             else if ( j == 3 )
                               {
                                 (*fbanFlags)->rotate = true; /* Draw Rotated Text */
                                 (*fbanFlags)->fliph  = true; /* Flip Characters Horizontal */
                               }
                            }
                          break;
              case 'S' :  (*lethFlags)->gspace = true;    /* use Eth Word Sep. for " " */
                          break;
              case 'V' :  fprintf (stdout, "This is %s Version %0.1f%i\n", ADMAS_UTIL, ADMAS_UTIL_MAJOR_VERSION, ADMAS_UTIL_MINOR_VERSION);
                          fprintf (stdout, "  Export Date:  %s\n", ADMAS_UTIL_EXPORT_DATE);
                          exit(1);
                          break;

              case 'X' :  strcpy ( (*fbanFlags)->sym, argv[++i] );
                          break;
DEFAULT:
              default  :
                          fprintf (stderr, "\n\tUseage:  fbanner -option[s] string1 string2 ...\n");
                          fprintf (stderr, "\tTo set character draw symbol:\n");
                          fprintf (stderr, "\t   -x #  [Where `#' is any ascii symbol]\n");
                          fprintf (stderr, "\tTo set alphabetic (phonetical) drawing:\n");
                          fprintf (stderr, "\t   -a\n");
                          fprintf (stderr, "\tTo set Ge'ez drawing:\n");
                          fprintf (stderr, "\t   -g\n");
                          fprintf (stderr, "\tTo substitute Latin spaces with Ge'ez wordspace:\n");
                          fprintf (stderr, "\t   -s\n");
                          fprintf (stderr, "\tTo set starting language:\n");
                          fprintf (stderr, "\t   -l iso639-name \n");
                          fprintf (stderr, "\t      am = amh = Amharic \n");
                          fprintf (stderr, "\t      gz = gez = Ge'ez   \n");
                          fprintf (stderr, "\t      la = lat = Latin   \n");
                          fprintf (stderr, "\t      ti = tir = Tigrigna\n");
                          fprintf (stderr, "\tTo print words in mirror image:\n");
                          fprintf (stderr, "\t   -m\n");
                          fprintf (stderr, "\tTo print words rotated in incements of -90 degress:\n");
                          fprintf (stderr, "\t   -r, -rr, -rrr\n");
                          fprintf (stderr, "\tTo print words rotated in incements of +90 degress:\n");
                          fprintf (stderr, "\t   +r, +rr, +rrr\n");
                          fprintf (stderr, "\tTo flip charcters around horizontal axis:\n");
                          fprintf (stderr, "\t   -fh\n");
                          fprintf (stderr, "\tTo flip charcters around vertical axis:\n");
                          fprintf (stderr, "\t   -fv\n");
                          fprintf (stderr, "\tEcho version number and quit:\n");
                          fprintf (stderr, "\t   -v\n");
                          fprintf (stderr, "\n\tTo contact the maintainer:\n");
                          fprintf (stderr, "\t   FBanner@EthiopiaOnline.Net\n\n");
                          exit(0);
                          break;
             
            }
        }  
      else 
       {
         (*lethFlags)->top = (*lethFlags)->minor;
         return (i);   
       } 
    }

  return (1);

}


/*----------------------------------------------------------------------------//
//                                                                            //
//  sig_term catches the more violent break signals, presumably something     //
//  has gone awry...                                                          //
//                                                                            //
//----------------------------------------------------------------------------*/

static void
sig_term ( int signo )
{

  if ( signo == SIGTERM || signo == SIGINT )
    {
      /* ...personal toying with unix...
       *
	   * openlog ("sera2", LOG_PID, LOG_USER);
	   * syslog (LOG_DEBUG, "failed on %s", filename);
	   * closelog ();
	   */ 
      fprintf (stderr, "\nIndE??  You seem to have found a bug with %s version %0.1f%i\n", ADMAS_UTIL, ADMAS_UTIL_MAJOR_VERSION, ADMAS_UTIL_MINOR_VERSION);
   	  fprintf (stderr, "Please email your input file to the maintainer\n");
	  fprintf (stderr, "Daniel Yacob:-  FBanner@EthiopiaOnline.Net\n");
	  fprintf (stderr, "                                              Thank You!\n\n");
	  exit (0);
    }

}
