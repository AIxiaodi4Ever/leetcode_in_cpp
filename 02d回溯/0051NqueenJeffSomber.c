#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*#ifdef WIN32

#define MAX_BOARDSIZE 21
typedef unsigned __int64 SOLUTIONTYPE;*/

//#else

#define MAX_BOARDSIZE 32
typedef unsigned long SOLUTIONTYPE;

//#endif

#define MIN_BOARDSIZE 2

SOLUTIONTYPE g_numsolutions = 0;

void printtable(int boardsize, int *aQueenBitRes, SOLUTIONTYPE numSolution)
{
    int i, j, k, row;
    for (k = 0; k < 2; ++k)
    {
        /*#ifdef WIM32
        printf("*** Solution #: %d ***\n", 2 * numSolution + k - 1);
        #else*/
        printf("*** Solution #: %lu ***\n", 2 * numSolution + k - 1);
        //#endif
        for ( i = 0; i < boardsize; ++i)
        {
            unsigned int bitf;
            bitf = aQueenBitRes[i];
            row = bitf ^ (bitf & (bitf - 1));
            for (j = 0; j < boardsize; ++j)
            {
                if (0 == k && ((row >> j) & 1))
                {
                    printf("Q");
                }
                else if (1 == k && (row & (1 << (boardsize - j - 1))))
                {
                    printf("Q");
                }
                else
                {
                    printf(".");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
}

void Nqueen(int board_size)
{
    /* 结果 */
    int aQueenBitRes[MAX_BOARDSIZE];
    int aQueenBitCol[MAX_BOARDSIZE];
    int aQueenBitPosDiag[MAX_BOARDSIZE];
    int aQueenBitNegDiag[MAX_BOARDSIZE];

    // 维护一个栈从而将递归改成迭代
    // 仍然不知道为什么MAX_BOARDSIZE + 2
    int aStack[MAX_BOARDSIZE + 2];
    register int *pnStack;

    register int numrows = 0;

    register unsigned int lsb;

    register unsigned int bitfield;
    int i;
    
    int odd = board_size & 1;
    printf("odd:%d\n", odd);

    int board_minus = board_size - 1;

    int mask = (1 << board_size) - 1;

    aStack[0] = -1;

    for (i = 0; i < (1 + odd); ++i)
    {
        bitfield = 0;
        if (0 == i)
        {
            int half = board_size >> 1;
            bitfield = (1 << half) - 1;
            printf("half :%d,\t bitfield: %d. \n", half, bitfield);

            pnStack = aStack + 1;

            /*lsb = (-(signed)bitfield) & bitfield;
            printf("lsb: %d\n", lsb);*/

            aQueenBitRes[0] = 0;
            aQueenBitCol[0] = aQueenBitNegDiag[0] = aQueenBitPosDiag[0] = 0;
        }
        else
        {
            bitfield = 1 << (board_size >> 1);
            numrows = 1;

            aQueenBitCol[0] = aQueenBitNegDiag[0] = aQueenBitPosDiag[0] = 0;
            aQueenBitCol[1] = bitfield;

            aQueenBitNegDiag[1] = (bitfield >> 1);
            aQueenBitPosDiag[1] = (bitfield << 1);
            pnStack = aStack + 1;

            // 因为这个else处理奇数的中间列，所以中间列放过棋子以后没有其他可放位置，所以入栈时置为0
            *pnStack = 0;
            ++pnStack;
            bitfield = (bitfield - 1) >> 1;
        }

        for (;;)
        {
            //printf("numrows: %d\n", numrows);
            lsb = (-(signed)bitfield) & bitfield;
            //printf("lsb: %d\n", lsb);
            //printf("pnstack: %d\n", *pnStack);
            if (0 == bitfield)
            {
                --pnStack;
                bitfield = *pnStack;
                if (pnStack == aStack)
                    break;
                --numrows;
                continue;
            }

            // 通过和~lsb做与运算将bitfield的最后一位1置为0，也可以通过和bitfield-1做与运算实现
            bitfield &= (~lsb);
            //bitfield &= (bitfield - 1);

            aQueenBitRes[numrows] = lsb;
            if (numrows < board_minus)
            {
                int n = numrows;
                ++numrows;
                aQueenBitCol[numrows] = aQueenBitCol[n] | lsb;
                aQueenBitNegDiag[numrows] = (aQueenBitNegDiag[n] | lsb) >> 1;
                aQueenBitPosDiag[numrows] = (aQueenBitPosDiag[n] | lsb) << 1;
                *pnStack = bitfield;
                ++pnStack;

                bitfield = mask & ~(aQueenBitCol[numrows] | aQueenBitNegDiag[numrows] | aQueenBitPosDiag[numrows]);
                continue;
            }
            else
            {
                printtable(board_size, aQueenBitRes, g_numsolutions + 1);
                ++g_numsolutions;
                --pnStack;
                bitfield = *pnStack;
                --numrows;
                continue;
            }
        }
    }
    g_numsolutions *= 2;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("error arguments!");
        exit(1);
    }
    int boardsize;
    boardsize = atoi(argv[1]);
    printf("%d\n", boardsize);
    Nqueen(boardsize);
    printf("solution(s): %lu", g_numsolutions);
    return 0;
}