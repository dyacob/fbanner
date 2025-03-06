# Fidel Banner

## NOTE
*This is a archived work last updated in 1996, it is not expected to
 build out-of-the-box. It will eventually be revived.*



                 fffff   BBBBBB              nn     RRRRRR    
                ff  fff  BB   BB             nn     RR   RR   
                f    ff  BB    BB            nn     RR    RR  
               ff        BB    BB   aaaaa    nnnn   RR    RR  
               ff        BB   BB   aa  aaa     nnn  RR    RR  
               fffff     BBBBBB         aa     nn   RR   RR   
               ff  ffff  BB   BB     aaaaa     nn   RRRRRR    
               ff fff f  BB    BB   aa  aa     nn   RR  RR    
                ff ff    BB    BB  aa   aa    nn    RR   RR   
                   ff    BB    BB  aa   aa    nn    RR   RR   
                   ff    BB   BB   aa  aaa    nn    RR    RR  
                   ff    BBBBBB     aaaa aa   nn    RR    RR 

                                Fidel Banner 0.17
                               by  Admas  Concepts

Intro
-----

"fbanner" is provided for the Fidel script Unix user community to have the
same utility for Fidel that "banner" provides for Latin script.  fbanner uses
phonetic input following the SERA convention for Fidel.  fbanner works by
converting BDF format fonts into large editible text.  This principal allows
for ease of use, and extension to, other font choices.


What's New in Version 0.17 ?
----------------------------
   o -g switch added to draw characters with Ge'ez letters.
   o revisions to work with libeth 0.33.
     It is *required* that you have pre-installed libeth v0.33 or later with
     this release of fbanner.  Get LibEth from http://libeth.netpedia.net
   o cleaned up as per -Wall warnings.

What's New in Version 0.16 ?
----------------------------
   o Bug fixes from v0.15.
   o libeth's Unicode processing is compliant with June amendments to
     UTC-95-055A.

What's New in Version 0.15 ?
----------------------------

Advanced text and character manipulation!! 

  o Mirror image printing with -m
  o Rotated printing with -r, -rr, -rrr and +r +rr +rrr
    r = 90 degrees 
  o Flip each letter on its horizontal axis with -fh
  o Flip each letter on its vertical axis with -fv

Fidel banner now uses the "libeth" 0.1 beta motor.  Unfortunately this
will increase the size of the executable.  If size truly prevents anyone
from down loading and compiling fbanner, a minimal package w/o libeth can
be provided.  Flex support is added for libeth, and Fbanner has run 
successfully on top of Linux 1.2.13 and later.

What's New in Version 0.14 ?
----------------------------

The Fbanner now relies on a SERA engine written in Lex -which may present new
portability problems!  The Ethiopic font now houses some 411 Fidel letters,
numbers, punctuations, and glyphs.  Fbanner now comes with a man page (fbanner.1)
that you may install into your man path.


Installation
------------

If you have down loaded the file fbanner-0.XY.tar.Z by ftp (set in binary transfer
mode); enter the 2 command lines as follows ("XY" is some number like "16"):

    tar -zxvf fbanner-0.XY.tar.gz

(
  Or in 2 Steps :
    gunzip fbanner-0.XY.tar.gz
    tar -xvf fbanner-0.XY.tar
)

You will find a new subdirectory with the name "fbanner-0.XY" that contains the 
fbanner source files.  If you have obtained your copy of fbanner through encoded 
email, you will need to save the email message as a new file name and enter at the
window command line :

    uudecode filename

you will then discover a new file has been created with the name 
"fbanner-0.XY.tar.Z" .  At this point follow the 2 commands given for the ftp
instructions above.


BEFORE COMPILING
----------------
 
We recommend you to make a directory in your account for holding font
files.  You may make this directory anywhere in your account, lets call it
"FONTDIR" for now.  

        % mkdir FONTDIR
        % cp fonts/*.bdf FONTDIR

        % [ edit line 4 of fban.h and replace ./fonts with
            FONTDIR -do NOT delete the " " marks! ]

IF YOU DO NOT HAVE gcc

You should then have "cc" and "lex".  You may edit the Makefile in
lines 2 and 5 for cc and lex.


DEFAULT LANGUAGE

You may change the default language rules by editing commenting out and
uncommenting the choices on lines 12-14 of the fban.h file.  Tigrigna
rules are the default if no change is made.


TO COMPILE:  

        % make       - makes everything.
        % make clean - removes unnecessary files.


TO RUN:  

        % fbanner  < Hit RETURN or ENTER Key > 
                     -gives a full list of options
           
Options Are:

       -a        Print characters with alphabets.
       -fh       Flip characters around horizontal axis.
       -fv       Flip characters around vertical axis.
       -l LL(L)  Use rules for language specified with ISO symbols 
                 LL or LLL:  am(h), g(e)z, la(t), ti(g)

       -m        Print words in mirror image.
       -r(rr)    Rotate words -90 degrees for each "r"
       +r(rr)    Rotate words +90 degrees for each "r"
       -s        Print spaces " " with Ethiopic : 
       -x X(X)   Print characters using symbol "X" or "XX"
       -v        Echo version number and exit.


   Example:

        % fbanner -a "f\Ba\ne\R"  [ creates logo at top ]
        % fbanner -a "s2elam yonas!" "admas"  <RETURN/ENTER>
        % fbanner -r "s2elam yonas!" <RETURN/ENTER>
        % fbanner -fh -x @ "s2elam yonas!" <RETURN/ENTER>



Installing Man Pages
---------------------

The files etc/fbanner.1 and etc/sera.1 are provided man
page instructions for Unix systems.  If you can not install the
man pages into a system man directory.  You may create your own
man directory by:

    % cd fbanner-0.XY
    % mkdir man
    % mkdir man/man1
    % cp etc/*.1 man/man1
    % setenv MANPATH $MANPATH":"$PWD/man
    % man fbanner
    % man sera

It is more practical to set your new MANPATH in your .cshrc file
where the $PWD/man directory in the above is replaced the complete
path name for your man directory.


For More Info On SERA 
---------------------

    https://www.academia.edu/87262938/The_SERA_Users_Guide
    http://abyssiniagateway.net/fidel/sera-faq.html

and

    ftp://ftp.geez.org/fidel/sera-docs/
