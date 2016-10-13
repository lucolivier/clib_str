//
//  CLib_Str.h
//  CLib_Str
//
//  Created by Luc-Olivier on 13/04/2014.
//
//

#ifndef CCLib_Str_CLib_Str_h
#define CLib_Str_CLib_Str_h
#endif

#define Clib_StaticStr      1024
#define Clib_Digit0         '0'
#define Clib_Digit9         '9'
#define Clib_DigitBase      48


#define arrayLength(array,fst) sizeof(array)/sizeof(fst)

#define rc() printf("\n")
#define lf() printf("\n")
#define ps(l,s) printf("%s: %s\n",l,s)
#define pc(l,c) printf("%s: %c\n",l,c)
#define pd(l,i) printf("%s: %d\n",l,i)
#define pl(l,ii) printf("%s: %ld\n",l,ii)
#define pf(l,f) printf("%s: %f\n",l,f)

#define pstr(s) printf("%s\n",s)



/*
    States
*/

// clib_strlen: return length of string
unsigned long clib_strlen(const char *str);

// clib_strcmp: compare 2 strings
//              return 0 if =,
//              diff with last if equal length
//              diff with next if not equal length
int clib_strcmp(const char *ref, const char *cmp);

// clib_strchr: return pointer to char in string
//              or NULL if not found
char *clib_strchr(char *str, char chr);

// clib_strchrpos: return pos of char in string
//                 or -1 if not found
long clib_strchrpos(char *str, char chr);

// clib_strstr: return pointer of string in string
//              or NULL if not found
char *clib_strstr(char *str, char *cmp);

// clib_strstrpos: return pos of string in string
//                 or -1 if not found
long clib_strstrpos(char *str, char *cmp);

// clib_arraycount: return length of array based
// on last member equal to NULL
unsigned long clib_arraycount(void *array[]);




    
/*
    Tools
*/

// clib_strcpy: copy string into string
void clib_strcpy(char *dest, const char *src);

// clib_strcpys: copy array of strings into string
void clib_strcpys(char *dest, const char **srcs);

// clib_strcat: copy string at end of string
void clib_strcat(char *dest, const char *src);

// clib_strcat: return a string resulting of strings
//              concatenation
char *clib_getstrcat(char *str1, char *str2);


// clib_strleft: copy string from start to a given pos
void clib_strleft(char *dest, char *src, unsigned long pos);

// clib_strleft: copy string from a given pos to end
void clib_strright(char *dest, char *src, unsigned long pos);

// clib_strsub: copy string from a given pos to a given pos
void clib_strsub(char *dest, char *src, unsigned long start, unsigned long end);

// clib_strtrimleft: copy string without front blanks
//                   to string
void clib_strtrimleft(char *dest, char *src);

// clib_strtrimright: copy string without end blanks
//                    to string
void clib_strtrimright(char *dest, char *src);

// clib_strtrim: copy string without front and end
//               blank to string
void clib_strtrim(char *dest, char *src);


//
long clib_strtolong(char *str);
double clib_strtodouble(char *str);





/*
 private
 */
long clib_priv_power10(long n);




