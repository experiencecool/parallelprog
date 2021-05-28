#include <stdio.h>
#include "ipp.h"
#include "ippcore.h"
#include "ippvm.h"

#include "ippwrap.h"

// #define EXIT_MAIN exitLine:                                 
// #define check_sts(st) if((st) != ippStsNoErr) goto exitLine; 
void swap(Ipp64f *pSrc, Ipp64f *pDst);

IppStatus absI(Ipp64f *pSrcDst, int len)
{
    // int len = 32;
    int i;
    // Ipp64f *pSrcDst = ippsMalloc_64f(len * sizeof(Ipp64f));
    // IppStatus status;

    // printf("\n\nSource vector\n");
    // for ( i= 0; i < len; i++)
    // {
    //     pSrcDst[i] = 10 - i;
    //     printf("%.0f; ", pSrcDst[i]);
    // }

    // check_sts(status = 
    IppStatus st = ippsAbs_64f_I(pSrcDst, len);

    // printf("\n\nResult\n");
    // for (i = 0; i < len; i++) printf("%.3f; ", pSrcDst[i]);
    // printf("\n\n");
    return st;
// EXIT_MAIN
//     // ippsFree(pSrcDst);
//     // printf("Exit status %d (%s)\n", (int)status, ippGetStatusString(status));
//     return status;
}

IppStatus cbrt(Ipp64f *pSrc, Ipp64f *pDst, int len)
{
    // const Ipp64f x[4] = {6456.801, 4932.096, -6517.838, 7178.869};
    // Ipp64f y[4];
	IppStatus st = ippsCbrt_64f_A26( pSrc, pDst, len );
	// printf(" ippsCbrt_32f_A21:\n");
	// printf(" x = %.3f %.3f %.3f %.3f \n", pSrc[0], pSrc[1], pSrc[2], pSrc[3]);
	// printf(" y = %.3f %.3f %.3f %.3f \n", pDst[0], pDst[1], pDst[2], pDst[3]);
	return st;
}

IppStatus pow(Ipp64f *pSrc, Ipp64f *pPow, Ipp64f *pDst, int len)
{
	IppStatus st = ippsPow_64f_A26( pSrc, pPow, pDst, len );
	// printf(" ippsPow_32f_A21:\n");
	// printf(" x1 = %.3f %.3f %.3f %.3f \n", x1[0], x1[1], x1[2], x1[3]);
	// printf(" x2 = %.3f %.3f %.3f %.3f \n", x2[0], x2[1], x2[2], x2[3]);
	// printf(" y  = %.3f %.3f %.3f %.3f \n", y[0],  y[1],  y[2],  y[3]);
	return st;
}
IppStatus log10(Ipp64f *pSrc, Ipp64f *pDst, int len)
{
	IppStatus st = ippsLog10_64f_A26( pSrc, pDst, len );
    // printf(" ippsLog10_32f_A21:\n");
	// printf(" x = %.3f %.3f %.3f %.3f \n", pSrc[0], pSrc[1], pSrc[2], pSrc[3]);
	// printf(" y = %.3f %.3f %.3f %.3f \n", pDst[0],  pDst[1],  pDst[2],  pDst[3]);
	return st;
}

IppStatus sin(Ipp64f *pSrc, Ipp64f *pDst, int len)
{
    // Ipp64f y[len];
	IppStatus st = ippsSin_64f_A26( pSrc, pDst, len );
	// printf(" ippsSin_64f_A21:\n");
	// printf(" x = %.3f %.3f %.3f %.3f \n", pSrc[0], pSrc[1], pSrc[2], pSrc[3]);
	// printf(" y = %.3f %.3f %.3f %.3f \n", pDst[0],  pDst[1],  pDst[2],  pDst[3]);
	return st;
}

IppStatus divC(Ipp64f* pSrcDst, Ipp64f val, int len)
{
    IppStatus st = ippsDivC_64f_I(val, pSrcDst, len);
    return st;
}

IppStatus sum(Ipp64f* pSrc, Ipp64f* pSum, int len)
{
    IppStatus st = ippsSum_64f(pSrc, len, pSum);
    return st;
}


void swap(Ipp64f *pSrc, Ipp64f *pDst) {
    Ipp64f *temp;
    temp = pSrc;
    pSrc = pDst;
    pDst = temp;
    return;
}