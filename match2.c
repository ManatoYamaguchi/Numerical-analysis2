#include<stdio.h>

int main()
{
	int eCnt1, eCnt2, count1, count2, cCnt, judg1, judg2;
	char str1[64], str2[64], candStr1[64] = {}, candStr2[64] = {}, cand[64][64] = {}, match[64] = {};

	cCnt = 0;

	printf("一つ目の文字列を入力してください\n");
	scanf("%s", str1);

	printf("二つ目の文字列を入力してください\n");
	scanf("%s", str2);

	//１回目

	eCnt1 = eCnt2 = 0;

	for(count1 = 0; count1 < 64; count1++)
	{
		if(str1[eCnt1] == str2[eCnt2])
		{
			match[count1] = 'o';
			candStr1[count1] = str1[eCnt1];
			candStr2[count1] = str2[eCnt2];
		}

		else if(str1[eCnt1] != str2[eCnt2])
		{
			match[count1] = 'x';
			candStr1[count1] = str1[eCnt1];
			candStr2[count1] = str2[eCnt2];
		}

		eCnt1++;
		eCnt2++;

		if(str1[eCnt1] == '\0' && str2[eCnt2] == '\0')
		{
			count1 = 64;
		}
	}

	//candへの代入

	for(count1 = 0; count1 < 64; count1++)
	{
		cand[cCnt][count1] = candStr1[count1];
		cand[cCnt + 1][count1] = candStr2[count1];
		cand[cCnt + 2][count1] = match[count1];

		candStr1[count1] = '\0';
		candStr2[count1] = '\0';
		match[count1] = '\0';
	}

	cCnt = cCnt + 3;

	//２回目
	
	eCnt1 = eCnt2 = 0;
	
	for(count1 = 0; count1 < 64; count1++)
	{
		if(str1[eCnt1] == str2[eCnt2])
		{
			match[count1] = 'o';
			candStr1[count1] = str1[eCnt1];
			candStr2[count1] = str2[eCnt2];

			eCnt1++;
			eCnt2++;
		}

		else if(str1[eCnt1] != str2[eCnt2])
		{
			match[count1] = 'x';

			judg1 = judg2 = 1;

			while(1)
			{
				if(str1[eCnt1 + judg1] == str2[eCnt2])
				{
					break;
				}

				else if(str1[eCnt1 + judg1] == '\0')
				{
					judg1 = 64;
					break;
				}

				else
				{
					judg1++;
				}
			}

			while(1)
			{
				if(str1[eCnt1] == str2[eCnt2 + judg2])
				{
					break;
				}

				else if(str2[eCnt2 + judg2] == '\0')
				{
					judg2 = 64;
					break;
				}

				else
				{
					judg2++;
				}
			}

			if(judg1 < judg2)
			{
				candStr1[count1] = str1[eCnt1];
				candStr2[count1] = '_';

				if(judg1 > 1)
				{
					for(count2 = 1; count2 < judg1; count2++)
					{
						count1++;

						candStr1[count1] = str1[eCnt1 + count2];
						candStr2[count1] = '_';
						match[count1] = 'x';
					}
				}

				eCnt1 = eCnt1 + judg1;
			}

			else if(judg1 > judg2)
			{
				candStr1[count1] = '_';
				candStr2[count1] = str2[eCnt2];

				if(judg2 > 1)
				{
					for(count2 = 1; count2 < judg2; count2++)
					{
						count1++;

						candStr1[count1] = '_';
						candStr2[count1] = str2[eCnt2 + count2];
						match[count1] = 'x';
					}
				}

				eCnt2 = eCnt2 + judg2;
			}

			else if(judg1 == judg2)
			{
				candStr1[count1] = str1[eCnt1];
				candStr2[count1] = str2[eCnt2];

				eCnt1++;
				eCnt2++;
			}
		}

		if(str1[eCnt1] == '\0' && str2[eCnt2] == '\0')
		{
			count1 = 64;
		}
	}

	//candへの代入

	for(count1 = 0; count1 < 64; count1++)
	{
		cand[cCnt][count1] = candStr1[count1];
		cand[cCnt + 1][count1] = candStr2[count1];
		cand[cCnt + 2][count1] = match[count1];

		candStr1[count1] = '\0';
		candStr2[count1] = '\0';
		match[count1] = '\0';
	}

	cCnt = cCnt + 3;

	//resultの選別
	
	int oCnt, oMax, xCnt, xMin, candNum;

	candNum = 0;
	oMax = 0;
	xMin = 64;

	for(count1 = 0; count1 < 64; count1++)
	{
		oCnt = 0;
		xCnt = 0;

		for(count2 = 0; count2 < 64; count2++)
		{
			if(cand[count1 * 3 + 2][count2] == 'o')
			{
				oCnt++;
			}

			else if(cand[count1 * 3 + 2][count2] == 'x')
			{
				xCnt++;
			}

			if(cand[count1 * 3 + 2][count2] == '\0')
			{
				count2 = 64;
			}
		}

		if(oCnt > oMax)
		{
			oMax = oCnt;
			candNum = count1 * 3;
		}

		else if(oCnt == oMax)
		{
			if(xCnt < xMin)
			{
				xMin = xCnt;
				candNum = count1 * 3;
			}
		}

		if(cand[count1 * 3 + 3][0] == '\0')
		{
			count1 = 64;
		}
	}

	/*printf("-------------test-------------\n");

	for(count1 = 0; count1 < 64; count1++)
	{
		printf("%s\n", cand[count1]);

		if(cand[count1 + 1][0] == '\0')
		{
			count1 = 64;
		}
	}

	printf("%d\n", candNum);*/

	printf("------------result------------\n");

	char disStr1[128] = {}, disStr2[128] = {}, result[128] = {};

	for(count1 = 0; count1 < 64; count1++)
	{
		disStr1[count1 * 2] = cand[candNum][count1];
		disStr2[count1 * 2] = cand[candNum + 1][count1];
		result[count1 * 2] = cand[candNum + 2][count1];

		disStr1[count1 * 2 + 1] = ' ';
		disStr2[count1 * 2 + 1] = ' ';
		result[count1 * 2 + 1] = ' ';
	}

	printf("%s\n", disStr1);
	printf("%s\n", disStr2);
	printf("%s\n",result);

	return 0;
}
