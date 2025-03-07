/*
**  fbanner 0.16
**
**  This release of Fidel Banner uses a beta release of the libeth package
**  currently under going evaluation.  The SERA scanner is now written in
**  AT&T Lex and may present portability problems on some systems.  Flex
**  support is included in the present release of libeth.  Reporting
**  compilation problems to Fbanner maintainers will assist the libeth
**  project.
** 
**  This is free software; you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation; either version 1, or (at your option)
**  any later version.  See the included "COPYING" file.
** 
**  Admas Concepts 1995
** 
*/

#define SERA_UTIL "fbanner"
#define SERA_UTIL_MAJOR_VERSION 0.1
#define SERA_UTIL_MINOR_VERSION 6

#include <stdio.h>
#include <fban.h>

extern void draw_word(), draw_word_r(); 
extern bdffont* read_bdf();
extern LS LnS[];


#ifdef __STDC__
int flag_reset ( int argc, char **argv, MyFlags** fbanFlags, SERAFlags** seraFlags );
#endif

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
SERAFlags* seraFlags = NULL;
MyFlags* fbanFlags = NULL;
bdffont *ffont, *lfont;



/*-------Read In Font Files First-----------------------*/

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

/*-------Font Read, Now Reset Flags-------------*/


  start = flag_reset ( argc, argv, &fbanFlags, &seraFlags );


/*-------Flags Set, Now It's Banner Time!-------*/

  for ( i = start; i < argc; i++ ) 
    {

      sget_fstring ( &out_string, argv[i], seraFlags );

      if ( fbanFlags->rotate )
        draw_word_r ( out_string, ffont, lfont, fbanFlags, seraFlags );
      else
        draw_word ( out_string, ffont, lfont, fbanFlags, seraFlags );

    }

/*-------Lets Be A Good Citizen-----------------*/

  free (seraFlags);
  free (fbanFlags);
  exit (0);

}





/*-------------------------------------------------------------------------//
//                                                                         //
//  Simple routine to read input options and reset the default flags.      //
//  The flags for this version are -l if a file starts in Latin and        //
//  -s to use Ge'ez word separators in Fidel text zones.                   //
//                                                                         //
//-------------------------------------------------------------------------*/


int 
flag_reset ( argc, argv, fbanFlags, seraFlags )
  int argc;
  char **argv;
  MyFlags** fbanFlags;
  SERAFlags** seraFlags;
{

register int i, j;
LS* default_lang =& LnS[DEFLANG]; 
char* Lnames2[NUMLANGS] = LNAMES2;
char* Lnames3[NUMLANGS] = LNAMES3;

/*---------------- Don't Waste Time Initializing -We Gone!--------------------*/

  if ( argc == 1 ) 
    goto DEFAULT; 

/*---------------- Define and Initialize Flag Values -------------------------*/

  *seraFlags                  =  (SERAFlags *) malloc ( sizeof(SERAFlags) );
  (*seraFlags)->top           =  default_lang;
  (*seraFlags)->minor         =  (*seraFlags)->top;
  (*seraFlags)->major         =& LnS[lat];
  (*seraFlags)->lastchar      =  '\0';
  (*seraFlags)->dos           =  0;
  (*seraFlags)->colon         =  false;
  (*seraFlags)->qmark         =  false;
  (*seraFlags)->gspace        =  false;
  (*seraFlags)->verbatim      =  false;
  (*seraFlags)->lastpunct     =  false;
  (*seraFlags)->other_state   =  false;
  (*seraFlags)->in            =  sera;
  (*seraFlags)->out           =  jun;

  *fbanFlags             = (MyFlags *) malloc ( sizeof(MyFlags) );
  (*fbanFlags)->use_alfa = false;
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
                          break;
              case 'F' :  if ( toupper(argv[i][2]) == 'V') /* Flip Characters Vertical */
                            (*fbanFlags)->flipv =! (*fbanFlags)->flipv;
                          else                             /* Flip Characters Horizontal */
                            (*fbanFlags)->fliph =! (*fbanFlags)->fliph;
                          break;
              case 'L' :  j=-1;
                          while ( ++j < NUMLANGS && (strcmp(argv[i+1],Lnames2[j]) && strcmp(argv[i+1],Lnames3[j])) );
                          if (j < NUMLANGS )
                            (*seraFlags)->minor  =& LnS[j];
                          if (j == latin)
                            (*seraFlags)->major   =  default_lang;
                          i++;
                          if (j == NUMLANGS)
                            {
                              fprintf(stderr,"Language %s Not Supported\n",argv[i]);
                              exit(1);
                            }
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
              case 'S' :  (*seraFlags)->gspace = true;    /* use Eth Word Sep. for " " */
                          break;
              case 'V' :  fprintf (stdout, "This is %s Version %0.1f%i\n", SERA_UTIL, SERA_UTIL_MAJOR_VERSION, SERA_UTIL_MINOR_VERSION);
                          fprintf (stdout, "  Export Date:  Wed Oct  2 10:32:00 EET 1996\n");
                          exit (1);
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
                          fprintf (stderr, "\n\tTo contact the maintainers:\n");
                          fprintf (stderr, "\t   fisseha@cig.mot.com / yacob@padis.gn.apc.org\n\n");
                          exit(0);
                          break;
             
            }
        }  
      else 
       {
         (*seraFlags)->top = (*seraFlags)->minor;
         return (i);   
       } 
    }


}
