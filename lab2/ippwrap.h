#ifndef IPPWRAP_H
#define IPPWRAP_H

IppStatus cbrt(Ipp64f *pSrc, Ipp64f *pDst, int len);
IppStatus pow(Ipp64f *pSrc, Ipp64f *pPow, Ipp64f *pDst, int len);
IppStatus log10(Ipp64f *pSrc, Ipp64f *pDst, int len);
IppStatus sin(Ipp64f *pSrc, Ipp64f *pDst, int len);
IppStatus absI(Ipp64f *pSrcDst, int len);
IppStatus divC(Ipp64f* pSrcDst, Ipp64f val, int len);
IppStatus sum(Ipp64f* pSrc, Ipp64f* pSum, int len);

#endif