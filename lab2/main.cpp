#include "ipp.h"
#include "ippcore.h"
#include "ippvm.h"
#include <stdio.h>

/* Next two defines are created to simplify code reading and understanding */
#define EXIT_MAIN exitLine:                                 
#define check_sts(st) if((st) != ippStsNoErr) goto exitLine; 

IppStatus ippsCbrt_32f_A21_sample(void);
IppStatus ippsPow_32f_A21_sample(void);
IppStatus ippsLog10_32f_A21_sample(void);
IppStatus abs(void);
IppStatus ippsSin_32f_A21_sample(const Ipp32f *x, int len);

int main(int argc, char* argv[])
{
   const IppLibraryVersion *lib;

   /* Init IPP library */
   ippInit();
   /* Get IPP library version info */
   lib = ippGetLibVersion();
   printf("%s %s\n", lib->Name, lib->Version);
   ippsCbrt_32f_A21_sample();
   ippsPow_32f_A21_sample();
   ippsLog10_32f_A21_sample();
   abs();
   const Ipp32f x[] = {5666.372, 6052.125, 397.656, -3960.997};
   ippsSin_32f_A21_sample(x, 4);
   return 0;
}

IppStatus ippsCbrt_32f_A21_sample(void)
{
    const Ipp32f x[4] = {6456.801, 4932.096, -6517.838, 7178.869};
    Ipp32f y[4];
	IppStatus st = ippsCbrt_32f_A21( x, y, 4 );
	printf(" ippsCbrt_32f_A21:\n");
	printf(" x = %.3f %.3f %.3f %.3f \n", x[0], x[1], x[2], x[3]);
	printf(" y = %.3f %.3f %.3f %.3f \n", y[0], y[1], y[2], y[3]);
	return st;
}

IppStatus ippsPow_32f_A21_sample(void)
{
    const Ipp32f x1[4] = {2, 3, 0.776, 4};
    const Ipp32f x2[4] = {2, 2, 0.411, 0.692};
    Ipp32f y[4];
	IppStatus st = ippsPow_32f_A21( x1, x2, y, 4 );
	printf(" ippsPow_32f_A21:\n");
	printf(" x1 = %.3f %.3f %.3f %.3f \n", x1[0], x1[1], x1[2], x1[3]);
	printf(" x2 = %.3f %.3f %.3f %.3f \n", x2[0], x2[1], x2[2], x2[3]);
	printf(" y  = %.3f %.3f %.3f %.3f \n", y[0],  y[1],  y[2],  y[3]);
	return st;
}
IppStatus ippsLog10_32f_A21_sample(void)
{
    const Ipp32f x[4] = {100, 10, 1.746, 6.664};
    Ipp32f y[4];
	IppStatus st = ippsLog10_32f_A21( x, y, 4 );
	printf(" ippsLog10_32f_A21:\n");
	printf(" x = %.3f %.3f %.3f %.3f \n", x[0], x[1], x[2], x[3]);
	printf(" y = %.3f %.3f %.3f %.3f \n", y[0], y[1], y[2], y[3]);
	return st;
}
IppStatus abs(void)
{
    int len = 32;
    int i;
    Ipp64f *pSrcDst = ippsMalloc_64f(len * sizeof(Ipp64f));
    IppStatus status;

    printf("\n\nSource vector\n");
    for ( i= 0; i < len; i++)
    {
        pSrcDst[i] = 10 - i;
        printf("%.0f; ", pSrcDst[i]);
    }

    check_sts(status = ippsAbs_64f_I(pSrcDst, len));

    printf("\n\nResult\n");
    for (i = 0; i < len; i++) printf("%.0f; ", pSrcDst[i]);
    printf("\n\n");

EXIT_MAIN
    ippsFree(pSrcDst);
    printf("Exit status %d (%s)\n", (int)status, ippGetStatusString(status));
    return status;
}

IppStatus ippsSin_32f_A21_sample(const Ipp32f *x, int len)
{
    Ipp32f y[len];
	IppStatus st = ippsSin_32f_A21( x, y, 4 );
	printf(" ippsSin_64f_A21:\n");
	printf(" x = %.3f %.3f %.3f %.3f \n", x[0], x[1], x[2], x[3]);
	printf(" y = %.3f %.3f %.3f %.3f \n", y[0], y[1], y[2], y[3]);
	return st;
}