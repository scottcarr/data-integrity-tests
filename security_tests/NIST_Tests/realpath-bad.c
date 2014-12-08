
/*

MIT Copyright Notice

Copyright 2003 M.I.T.

Permission is hereby granted, without written agreement or royalty fee, to use, 
copy, modify, and distribute this software and its documentation for any 
purpose, provided that the above copyright notice and the following three 
paragraphs appear in all copies of this software.

IN NO EVENT SHALL M.I.T. BE LIABLE TO ANY PARTY FOR DIRECT, INDIRECT, SPECIAL, 
INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT OF THE USE OF THIS SOFTWARE 
AND ITS DOCUMENTATION, EVEN IF M.I.T. HAS BEEN ADVISED OF THE POSSIBILITY OF 
SUCH DAMANGE.

M.I.T. SPECIFICALLY DISCLAIMS ANY WARRANTIES INCLUDING, BUT NOT LIMITED TO 
THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, 
AND NON-INFRINGEMENT.

THE SOFTWARE IS PROVIDED ON AN "AS-IS" BASIS AND M.I.T. HAS NO OBLIGATION TO 
PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.

$Author: tleek $
$Date: 2004/01/05 17:27:50 $
$Header: /mnt/leo2/cvs/sabo/hist-040105/wu-ftpd/f3/realpath-bad.c,v 1.1.1.1 2004/01/05 17:27:50 tleek Exp $



*/


/*

WU-FTPD Copyright Notice


  Copyright (c) 1999,2000 WU-FTPD Development Group.  
  All rights reserved.
  
  Portions Copyright (c) 1980, 1985, 1988, 1989, 1990, 1991, 1993, 1994
    The Regents of the University of California.
  Portions Copyright (c) 1993, 1994 Washington University in Saint Louis.
  Portions Copyright (c) 1996, 1998 Berkeley Software Design, Inc.
  Portions Copyright (c) 1989 Massachusetts Institute of Technology.
  Portions Copyright (c) 1998 Sendmail, Inc.
  Portions Copyright (c) 1983, 1995, 1996, 1997 Eric P.  Allman.
  Portions Copyright (c) 1997 by Stan Barber.
  Portions Copyright (c) 1997 by Kent Landfield.
  Portions Copyright (c) 1991, 1992, 1993, 1994, 1995, 1996, 1997
    Free Software Foundation, Inc.  
 
  Use and distribution of this software and its source code are governed 
  by the terms and conditions of the WU-FTPD Software License ("LICENSE").
 
  If you did not receive a copy of the license, it may be obtained online
  at http://www.wu-ftpd.org/license.html.


$Author: tleek $
$Date: 2004/01/05 17:27:50 $
$Header: /mnt/leo2/cvs/sabo/hist-040105/wu-ftpd/f3/realpath-bad.c,v 1.1.1.1 2004/01/05 17:27:50 tleek Exp $



*/


/*

<source>

*/

/*#include "config.h"*/
#include <sys/stat.h>

#include "my-include.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/signal.h>
#include <syslog.h>
#include <stdio.h>

#include "../../nist_safe_functions.h"

#ifndef MAXSYMLINKS		/* Workaround for Linux libc 4.x/5.x */
#define MAXSYMLINKS 5
#endif

/*
#ifndef HAVE_LSTAT
#define lstat stat
#endif
*/

char *fb_realpath(SAFE_CHAR, SAFE_CHAR);    

/*
  * delay_signaling(), enable_signaling - delay signal delivery for a while
  *
  * Author: Wietse Venema
  */


/*typedef struct {
  char* val;
} SAFE_CHAR;
*/


__attribute__((noinline))
void* safe_malloc(size_t n) {
  return malloc(n);
}

__attribute__((noinline))
void safe_getchar(char* addr) {
  int x = getchar();
  *addr = (char) x;
}

__attribute__((noinline))
void safe_putchar(char* adr) {
  putchar(*adr);
}

__attribute__((noinline))
void safe_read_double(double* addr) {
  scanf("%lf", addr);
}

__attribute__((noinline))
void safe_write_double(double* addr) {
  printf("%.9f", *addr);
}

__attribute__((noinline))
void safe_write_long(long* addr) {
  printf("%li", *addr);
}

__attribute__((noinline))
void safe_write_str(char* addr) {
  printf("%s", addr);
}




__attribute__((annotate("sensitive"))) SAFE_CHAR a;

static sigset_t saved_sigmask;
static sigset_t block_sigmask;
static int delaying;
static int init_done;

/* init_mask - compute signal mask only once */

static void init_mask()
{
    int     sig;

    init_done = 1;
    sigemptyset(&block_sigmask);
    for (sig = 1; sig < NSIG; sig++)
	sigaddset(&block_sigmask, sig);
}

char *safe_strrchr(SAFE_CHAR word, char ch){
    register char *result = (char *) 0;

    while (1) {
	if (*(word.val) == ch) {
	    result = word.val;
	}
	if (word.val++ == 0) {
	    break;
	}
    }
    return result;
}


int safe_strncpy(SAFE_CHAR dest, SAFE_CHAR src, int size){
    int x = 0;
    /*while (dest[x] != '\0')
    {
        x++;
    }*/
    int i = 0;
    for (i=0; src.val[i] != '\0' && i < size; i++)
    { 
        dest.val[i] = src.val[i];
    }
    for( ; i < size; i++)
    	dest.val[i] = '\0';
    return 0;
}


int safe_ch_strcpy(SAFE_CHAR dest, const char *ch){
    int x = 0;
    /*while (dest[x] != '\0')
    {
        x++;
    }*/
    //int i = 0;
    //for (i=0; src.val[i] != '\0'; i++)
    //{ 
    //    dest.val[i] = src.val[i];
    //}
    dest.val[0] = *ch;
    dest.val[1] = '\0';
    return 0;
}


int safe_strcpy(SAFE_CHAR dest, SAFE_CHAR src){
    int x = 0;
    /*while (dest[x] != '\0')
    {
        x++;
    }*/
    int i = 0;
    for (i=0; src.val[i] != '\0'; i++)
    { 
        dest.val[i] = src.val[i];
    }
    dest.val[i] = '\0';
    return 0;
}

int safe_char_strcat(SAFE_CHAR dest, char *ch){
    int x = 0;
    int i = 0;
    while (dest.val[x] != '\0')
    {
        x++;
    }
    dest.val[x++] = *ch; 
    dest.val[x] = '\0';
    return 0;
}

int safe_ch_strcat(SAFE_CHAR dest, const char *ch){
    int x = 0;
    int i = 0;
    while (dest.val[x] != '\0')
    {
        x++;
    }
    dest.val[x++] = *ch; 
    dest.val[x] = '\0';
    return 0;
}


int safe_strcat(SAFE_CHAR dest, SAFE_CHAR src){
    int x = 0;
    int i = 0;
    while (dest.val[x] != '\0')
    {
        x++;
    }
    for (i=0; src.val[i] != '\0'; i++)
    { 
        dest.val[x++] = src.val[i];
    }
    dest.val[x] = '\0';
    return 0;
}

int safe_strlen(SAFE_CHAR word){
	int length;
	for (length = 0; word.val != '\0'; word.val++)
	{
		length++;
	}
	return(length);
}

/* enable_signaling - deliver delayed signals and disable signal delay */

int     enable_signaling()
{
    if (delaying != 0) {
	delaying = 0;
	if (sigprocmask(SIG_SETMASK, &saved_sigmask, (sigset_t *) 0)<0) {
	  /*syslog(LOG_ERR, "sigprocmask: %m");*/ /* ISO doesn't support %m */
	    return (-1);
	}
    }
    return (0);
}

/* delay_signaling - save signal mask and block all signals */

int     delay_signaling()
{
    if (init_done == 0)
	init_mask();
    if (delaying == 0) {
	delaying = 1;
	if (sigprocmask(SIG_BLOCK, &block_sigmask, &saved_sigmask)<0) {
	  /* syslog(LOG_ERR, "sigprocmask: %m");*/
	    return (-1);
	}
    }
    return (0);
}
              

char *wu_realpath(SAFE_CHAR path, SAFE_CHAR resolved_path, SAFE_CHAR chroot_path)
{
    //char *ptr;
    //char q[MAXPATHLEN];
    
    SAFE_CHAR ptr;
    SAFE_CHAR q;
    q.val = (char *)safe_malloc(sizeof(char)*MAXPATHLEN);

    fb_realpath(path, q);  /* call to fb_realpath is made */

    printf("safe_strlen(q) = %d\n", safe_strlen(q));
    //printf("q[MAXPATHLEN - 1] = %c\n",q.val[MAXPATHLEN - 1]);     

    if (chroot_path.val == NULL)
//NEED TO LOOK AT THIS TO CHANGE STRCPY
        safe_strcpy(resolved_path, q);
    else {
//NEED TO LOOK AT THIS TO CHANGE STRCPY
        safe_strcpy(resolved_path, chroot_path);
        if (q.val[0] != '/') {
            if (safe_strlen(resolved_path) +safe_strlen(q) < MAXPATHLEN)
                safe_strcat(resolved_path, q);
            else                /* Avoid buffer overruns... */
                return NULL;
        }
        else if (q.val[1] != '\0') {
            for (ptr.val = q.val; ptr.val != '\0'; ptr.val++);
            if (ptr.val == resolved_path.val || *(--ptr.val) != '/') {
                if (safe_strlen(resolved_path) +safe_strlen(q) < MAXPATHLEN)
                    safe_strcat(resolved_path, q);
                else            /* Avoid buffer overruns... */
                    return NULL;
            }
            else {
                if (safe_strlen(resolved_path) +safe_strlen(q) - 1 < MAXPATHLEN)
                    safe_char_strcat(resolved_path, &q.val[1]);
                else            /* Avoid buffer overruns... */
                    return NULL;
            }
        }
    }

    return resolved_path.val;
}
 




/*
 * char *fb_realpath(const char *path, char resolved_path[MAXPATHLEN]);
 *
 * Find the real name of path, by removing all ".", ".." and symlink
 * components.  Returns (resolved) on success, or (NULL) on failure,
 * in which case the path which caused trouble is left in (resolved).
 */
char *fb_realpath(SAFE_CHAR path, SAFE_CHAR resolved)
{
    struct stat sb;
    int fd, rootd, serrno;
    //char *p, *q, wbuf[MAXPATHLEN];
    SAFE_CHAR p, q, wbuf;
    wbuf.val = (char *)safe_malloc(sizeof(char)*MAXPATHLEN);
    /*int symlinks = 0;*/
    int resultcode;

#ifdef HAS_NO_FCHDIR
/* AIX Has no fchdir() so we hope the getcwd() call doesn't overrun the buffer! */
    SAFE_CHAR cwd;
    cwd.val = (char *)safe_malloc(sizeof(char) *(MAXPATHLEN + 1));
    SAFE_CHAR pcwd;
#endif

    /* Save the starting point. */
    errno = 0;
#ifdef HAS_NO_FCHDIR
#ifdef HAVE_GETCWD
    pcwd.val = getcwd(cwd.val, sizeof(cwd.val));
#else
    pcwd.val = getwd(cwd.val);
#endif
#else
    fd = open(".", O_RDONLY);
#endif
    if (EACCES == errno) {
	uid_t userid = geteuid();
	delay_signaling();	/* we can't allow any signals while euid==0: kinch */
	seteuid(0);
#ifdef HAS_NO_FCHDIR
#ifdef HAVE_GETCWD
	pcwd.val = getcwd(cwd.val, sizeof(cwd.val));
#else
	pcwd.val = getwd(cwd.val);
#endif
#else
	fd = open(".", O_RDONLY);
#endif
	seteuid(userid);
	enable_signaling();	/* we can allow signals once again: kinch */
    }
#ifdef HAS_NO_FCHDIR
    if (pcwd == NULL)
#else
    if (fd < 0)
#endif
    {
//NEED TO LOOK AT THIS IN ORDER TO CHANGE STRCPY
	(void) safe_ch_strcpy(resolved, ".");
	return (NULL);
    }

    /*
     * Find the dirname and basename from the path to be resolved.
     * Change directory to the dirname component.
     * lstat the basename part.
     *     if it is a symlink, read in the value and loop.
     *     if it is a directory, then change to that directory.
     * get the current directory name and append the basename.
     */
    
//NEED TO LOOK AT THIS IN ORDER TO CHANGE STRCPY
    (void) safe_strncpy(resolved, path, MAXPATHLEN - 1);
    resolved.val[MAXPATHLEN - 1] = '\0';
  
  loop:
    q.val = safe_strrchr(resolved, '/');     /* given /home/misha/docs.txt, q now pts to the last slash */
  
    printf("q inside LOOP =");
    safe_write_str(q.val);
    printf("\n");
    if (q.val != NULL) {
      p.val = q.val + 1;                   /* p points to docs.txt */

      if (q.val == resolved.val)
	q.val = "/";
      else {
	do {
	  --q.val;
	} while (q.val > resolved.val && q.val == "/");
	q.val[1] = '\0';               /* chop of the last slash */ 
	q.val = resolved.val;              /* q = /home/misha */
      }
      errno = 0;

      printf("trying to chdir(");   
      safe_write_str(q.val);
      printf(")\n");
      resultcode = chdir(q.val);           /* cd to /home/misha */
      if (EACCES == errno) {
	uid_t userid = geteuid();
	delay_signaling();	/* we can't allow any signals while euid==0: kinch */
	seteuid(0);
	errno = 0;
	resultcode = chdir(q.val);
	seteuid(userid);
	enable_signaling();	/* we can allow signals once again: kinch */
      }
      if (resultcode < 0)
	{
	  printf("error occurred while trying to chdir(");
	  safe_write_str(q.val);
	  printf(")\n");
	  goto err1;
	}
    }
    else
      p.val = resolved.val;
    
    /* Deal with the last component. */
    if (p.val != '\0') {
      errno = 0;
      printf("trying to lstat");
      safe_write_str(p.val);
      resultcode = lstat(p.val, &sb);
      printf("Resultcode = %d\n", resultcode);
      printf ("errno=%d\n", errno);

      if (EACCES == errno) {   /* if permission denied */
	uid_t userid = geteuid();
	delay_signaling();	/* we can't allow any signals while euid==0: kinch */
	seteuid(0);      /* need to become root */
	errno = 0;
	resultcode = lstat(p.val, &sb);  /* try lstat again, only now as root */
	seteuid(userid);   /* lower privileges!!  */
	enable_signaling();	/* we can allow signals once again: kinch */
      }
      if (resultcode == 0) {
/* #ifdef HAVE_LSTAT */

	int symlinks =  0;
        int n;
 
	printf ("sb.st_mode=%d\n", sb.st_mode);

	if (S_ISREG(sb.st_mode)) 
	  printf ("isreg\n");
	if (S_ISDIR(sb.st_mode))
	  printf ("isdir\n");
	if (S_ISCHR(sb.st_mode))
	  printf ("ischr\n");
	if (S_ISBLK(sb.st_mode))
	  printf ("isblk\n");
	if (S_ISFIFO(sb.st_mode))
	  printf ("isfifo\n");
	if (S_ISLNK(sb.st_mode)) 
	  printf ("islnk\n");
	if (S_ISSOCK(sb.st_mode))
	  printf ("issock\n");

	if (S_ISLNK(sb.st_mode)) {              /* check if docs is a link */ 
	  if (++symlinks > MAXSYMLINKS) {       /* too many sym links */
	    errno = ELOOP;                    /* too many levels of sym links */
	    goto err1;
	  }
	  errno = 0;
	  {
	    size_t len = safe_strlen(p);
	    SAFE_CHAR tmp;
	    tmp.val = (char *)safe_malloc(len + 1 * sizeof(char));
	    if (tmp.val == 0) {
	      serrno = errno;
	      goto err1;
	    }
//NEED TO LOOK AT THIS TO CHANGE STRCPY
	    safe_strcpy(tmp, p);
	    p.val = tmp.val;
	  }
	  n = readlink(p.val, resolved.val, MAXPATHLEN);
	  if (EACCES == errno) {                /* i.e if read permission was denied */
 	    uid_t userid = geteuid();
	    delay_signaling();	/* we can't allow any signals while euid==0: kinch */
	    seteuid(0);         /*need to become root */ 
	    errno = 0;         
	    n = readlink(p.val, resolved.val, MAXPATHLEN);
	    seteuid(userid);
	    enable_signaling();		/* we can allow signals once again: kinch */
	  }
	  if (n < 0) {
	    free(p.val);
	    goto err1;
	    }
	  free(p.val);
	  resolved.val[n] = '\0';
	  goto loop;
	}
	/*#endif  HAVE_LSTAT */
	if (S_ISDIR(sb.st_mode)) {   /* is docs.txt a directory inside /home/misha? */
	  printf("S_ISDIR..\n");
	  errno = 0;
	  resultcode = chdir(p.val);        
	  printf("chdir(p.val) = resultcode = %d\n", resultcode);
	  if (EACCES == errno) {     
	    uid_t userid = geteuid();
	    delay_signaling();	/* we can't allow any signals while euid==0: kinch */
	    seteuid(0);
	    errno = 0;
	    resultcode = chdir(p.val);  /*mz: cd to dir as root, because we lacked permissions */
	    seteuid(userid);
	    enable_signaling();		/* we can allow signals once again: kinch */
	  }
	  if (resultcode < 0)
	    goto err1;

	  p.val = ""; 
	}
      }
    }
    
    /*
     * Save the last component name and get the full pathname of
     * the current directory.
     */
    
//NEED TO LOOK AT THIS TO CHANGE STRCPY
    (void) safe_strcpy(wbuf, p);  /* wbuf now contains docs.txt */
    printf("wbuf now contains");
    safe_write_str(wbuf.val);
    printf("\n");
    errno = 0;
#ifdef HAVE_GETCWD
    resultcode = getcwd(resolved.val, MAXPATHLEN) == NULL ? 0 : 1; /* cur dir should be /home/misha */
    printf("getcwd: resultcode = %d\n", resultcode);           /* and should be shorter than MAXPATHLEN */
#else
    resultcode = getwd(resolved.val) == NULL ? 0 : 1;       
    if (resolved.val[MAXPATHLEN - 1] != '\0') {       /* not good.. current working dir longer than MAXPATHLEN */
      resultcode = 0;
      errno = ERANGE;
    }
#endif
    if (EACCES == errno) {
      uid_t userid = geteuid();
      delay_signaling();	/* we can't allow any signals while euid==0: kinch */
      seteuid(0);
      errno = 0;
#ifdef HAVE_GETCWD
      resultcode = getcwd(resolved.val, MAXPATHLEN) == NULL ? 0 : 1;
#else
      resultcode = getwd(resolved.val) == NULL ? 0 : 1;
      if (resolved.val[MAXPATHLEN - 1] != '\0') {
	resultcode = 0;
	errno = ERANGE;
      }
#endif
      seteuid(userid);
      enable_signaling();	/* we can allow signals once again: kinch */
    }
    if (resultcode == 0)
      {
	printf("going to err1.. resultcode = %d\n",resultcode);
	goto err1;
      }
    /*
     * Join the twosafe_strings together, ensuring that the right thing
     * happens if the last component is empty, or the dirname is root.
     */
    if (resolved.val[0] == '/' && resolved.val[1] == '\0')
      rootd = 1;                                             /* we're inside root */
    else
      rootd = 0;                                             /* we're not in root */
 
//NEED TO LOOK AT THIS TO CHANGE STRCPY
    printf ("resolved(%d)\n", safe_strlen(resolved));
//NEED TO LOOK AT THIS TO CHANGE STRCPY
    printf ("wbuf(%d)\n", safe_strlen(wbuf));
    printf ("rootd=%d\n", rootd);    
//NEED TO LOOK AT THIS TO CHANGE STRCPY
    printf("safe_strlen(resolved) +safe_strlen(wbuf) + rootd + 1 = %d\n",safe_strlen(resolved) +safe_strlen(wbuf) + rootd + 1);

    if (wbuf.val) {                             /* wbuf is docs.txt and resolved is /home/misha and rootd = 0*/
//NEED TO LOOK AT THIS TO CHANGE STRCPY
      if (safe_strlen(resolved) +safe_strlen(wbuf) + rootd + 1 > MAXPATHLEN) {
	errno = ENAMETOOLONG;                     /* suppose len(/home/misha) + len(docs.txt) + 0 + 1 = MAXPATHLEN */
	printf("resolved path too long!\n");      /* then len(/home/misha/docs.txt) = MAXPATHLEN) and this body is skipped */
	goto err1;                                
      }
      if (rootd == 0)
//NEED TO LOOK AT THIS TO CHANGE STRCPY
	(void) safe_ch_strcat(resolved, "/");    /* resolved becomes /home/misha/ */

//NEED TO LOOK AT THIS TO CHANGE STRCPY
      printf ("resolved=  len=%d \n", safe_strlen(resolved));
      printf ("wbuf=  len=%d \n", safe_strlen(wbuf));
      /* BAD */                            
      (void) safe_strcat(resolved, wbuf);     /* resolved becomes /home/misha/docs.txt + null terminator => MAXPATHLEN + 1 bytes */ 
      printf("after safe_strcat, resolved = , safe_strlen(resolved) = %d\n",safe_strlen(resolved));      
      if ((safe_strlen(resolved)+1) > MAXPATHLEN) 
	printf ("safe_strlen(resolve) > MAXPATHLEN -- buffer overflow maxpathlen: %d and length: %d\n", MAXPATHLEN, (safe_strlen(resolved)+1));

  }                                    
    
    /* Go back to where we came from. */
    errno = 0;
#ifdef HAS_NO_FCHDIR
    resultcode = chdir(cwd.val);
#else
    resultcode = fchdir(fd);
#endif
    if (EACCES == errno) {
      uid_t userid = geteuid();
      delay_signaling();	/* we can't allow any signals while euid==0: kinch */
      seteuid(0);
      errno = 0;
#ifdef HAS_NO_FCHDIR
      resultcode = chdir(cwd.val);
#else
      resultcode = fchdir(fd);
#endif
      seteuid(userid);
      enable_signaling();	/* we can allow signals once again: kinch */
    }
    if (resultcode < 0) {
      serrno = errno;
      goto err2;
    }
    
#ifndef HAS_NO_FCHDIR
    /* It's okay if the close fails, what's an fd more or less? */
    (void) close(fd);
#endif
    return (resolved.val);
    
 err1:serrno = errno;
#ifdef HAS_NO_FCHDIR
    (void) chdir(cwd.val);
#else
    (void) fchdir(fd);
#endif
    if (EACCES == errno) {
      uid_t userid = geteuid();
      delay_signaling();	/* we can't allow any signals while euid==0: kinch */
      seteuid(0);
#ifdef HAS_NO_FCHDIR
      (void) chdir(cwd.val);
#else
      (void) fchdir(fd);
#endif
      seteuid(userid);
      enable_signaling();	/* we can allow signals once again: kinch */
    }
#ifdef HAS_NO_FCHDIR
 err2:errno = serrno;
#else
 err2:(void) close(fd);
    errno = serrno;
#endif
    return (NULL);
}





/*

</source>

*/

