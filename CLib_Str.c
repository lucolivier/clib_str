//
//  CLib_Str.c
//  CLib_Str
//
//  Created by Luc-Olivier on 13/04/2014.
//
//

#include "CLib_Str.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>





/*
	States
*/

/* clib_strlen */
unsigned long clib_strlen(const char *str) {
	unsigned long i=0;
	while (str[i]!='\0') {
		i++;
	}
	return i;
}

/* clib_strcmp */
int clib_strcmp(const char *ref, const char *cmp) {
	unsigned long i=0;
	while (ref[i]!='\0') {
		if (cmp[i]=='\0') {
			return (int)ref[i];
		} else if (ref[i]!=cmp[i]) {
			return (int)ref[i]-(int)cmp[i];
		} else {
			i++;
		}
	}
	return -(int)cmp[i];
}

/* clib_strchr */
char *clib_strchr(char *str, char chr) {
	long res=clib_strchrpos(str, chr);
	if (res>-1) {
		return &str[res];
	}
	return NULL;
}

/* clib_strchrpos */
long clib_strchrpos(char *str, char chr) {
	unsigned long i=0;
	while (str[i]!='\0') {
		if (str[i]==chr) {
			return i;
		}
		i++;
	}
	return -1;
}

/* clib_strstr */
char *clib_strstr(char *str, char *cmp) {
	long res=clib_strstrpos(str, cmp);
	if (res>-1) {
		return &str[res];
	}
	return NULL;
}

/* clib_strstrpos */
long clib_strstrpos(char *str, char *cmp) {
	unsigned long i=0;
	unsigned long j=0;
	unsigned long start=0;
	while (str[i]!='\0') {
		if (str[i]==cmp[j]) {
			if (start==0) start=i;
		} else {
			start=0;
			j=0;
		}
		if (start!=0) {
			j++;
			if (cmp[j]=='\0') {
				return start;
			}
		}
		i++;
	}
	return -1;
}

/* clib_arraycount */
unsigned long clib_arraycount(void *array[]) {
    unsigned long int counter=0;
    while (array[counter]!=NULL) {
        counter++;
    }
    return counter;
}





/*
    Tools
*/

/* clib_strcpy */
void clib_strcpy(char *dest, const char *src) {
	unsigned long i=0;
	while (src[i]!='\0') {
		dest[i]=src[i];
		i++;
	}
	dest[i]='\0';
}

/* clib_strcpys */
void clib_strcpys(char *dest, const char **srcs) {
	//printf("%s\n", srcs[1]);
	unsigned long i=0, j=0, k=0;
	const char *src;
	while (srcs[j]!=NULL) {
		k=0;
		src=srcs[j];
		while (src[k]!='\0') {
			dest[i]=src[k];
			i++;
			k++;
		}
		j++;
	}
	dest[i]='\0';
}

/* clib_strcat */
void clib_strcat(char *dest, const char *src) {
	
	unsigned long i=clib_strlen(dest);
	unsigned long j=0;
	while (src[j]!='\0') {
		dest[i]=src[j];
		i++; j++;
	}
	dest[i]='\0';
}

/* clib_getstrcat */
char *clib_getstrcat (char *str1, char *str2) {
	//static char str[Clib_StaticStr];
	char *str=malloc((Clib_StaticStr+1)*sizeof(char));
	
    sprintf(str, "%s%s", str1, str2);
    return str;
}

/* clib_strleft */
void clib_strleft(char *dest, char *src, unsigned long pos) {
    long len=clib_strlen(src);
    if (len==0) { clib_strcpy(dest, ""); return; }
    if (pos>=len-1) { clib_strcpy(dest, src); return; }
    long i=0;
    while (i<=pos && src[i]!='\0') {
        dest[i]=src[i];
        i++;
    }
    dest[i]='\0';
    return;
}

/* clib_strright */
void clib_strright(char *dest, char *src, unsigned long pos) {
    long len=clib_strlen(src);
    if (len==0 || pos>len-1) { clib_strcpy(dest, ""); return; }
    if (pos==0) { clib_strcpy(dest,src); return; }
    long i=pos, j=0;
    while (src[i]!='\0') {
        dest[j]=src[i];
        i++; j++;
    }
    dest[j]='\0';
    return;
}

/* clib_strsub */
void clib_strsub(char *dest, char *src, unsigned long start, unsigned long end) {
    long len=clib_strlen(src);
    if (end>len-1) end=len-1;
    if (start>=end) { clib_strcpy(dest, ""); return; }
    long i=start, j=0;
    while (i<=end) {
        dest[j]=src[i];
        i++; j++;
    }
    dest[j]='\0';
    return;
}


/* clib_strtrimleft */
void clib_strtrimleft(char *dest, char *src) {
    int i=0,j=0;
    while (src[j]==' ') j++;
    while (src[j]!='\0') {
        dest[i]=src[j];
        i++; j++;
    }
    dest[i]='\0';
}

/* clib_strtrimright */
void clib_strtrimright(char *dest, char *src) {
    int i=0,j=0;
    int k=(int)clib_strlen(src)-1;
    while (src[k]==' ') k--;
    while (j<=k) {
        dest[i]=src[j];
        i++; j++;
    }
    dest[i]='\0';
}

/* clib_strtrim */
void clib_strtrim(char *dest, char *src) {
    char *buff=malloc( (clib_strlen(src)+1)*sizeof(char) );
    clib_strtrimright(buff, src);
    clib_strtrimleft(dest, buff);
    free(buff);
}

/* clib_strtolong */
long clib_strtolong(char *str) {
    long len=(long)clib_strlen(str);
    if (len==0) return 0;

    long dot=clib_strchrpos(str,'.');
    if (dot==0) return 0;
    len=(dot>0)?dot:len;

    unsigned long sign=(str[0]=='-')?-1:1;

    unsigned long res=0;
    unsigned long p=1;
    
    while (len>=0) {
        if (str[len]>=Clib_Digit0 && str[len]<=Clib_Digit9) {
            res+=(long)clib_priv_power10(p-1)*(str[len]-Clib_DigitBase);
            p++;
        }
        len--;
    }
    return res*sign;
}

/* clib_strtodouble */
double clib_strtodouble(char *str) {
    long len=(long)clib_strlen(str);
    if (len==0) return 0;
    
    double res=0.0;
    long dot=clib_strchrpos(str,'.');
    
    char buffer[50];
    if (dot>0 && dot<len) {
        clib_strleft(buffer, str, dot-1);
        res=(double)clib_strtolong(buffer);
    } else if (dot==-1) {
        res+=(double)clib_strtolong(str);
    }
    if (dot<len-2) {
        clib_strright(buffer, str, dot+1);
        long interm=clib_strtolong(buffer);
        if (interm>0) {
        res+=(double)interm/clib_priv_power10(clib_strlen(buffer));
        }
    }
    return res;
}





/*
    private
*/
long clib_priv_power10(long n) {
    if (n==0) return 1;
    long res=1;
    for (long i=1; i<=n; i++) {
        res*=10;
    }
    return res;
}




