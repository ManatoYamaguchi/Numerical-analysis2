#include<stdio.h>

int main()
{
	int num1 = 0, num2 = 0, count, count2, judg1, judg2;
	char str1[64], str2[64], distr1[128] = {}, distr2[128] = {}, result[64] = {};

	scanf("%s", str1);
	scanf("%s", str2);

	printf("str1 %s\n", str1);
	printf("str2 %s\n", str2);

	for(count = 0; count < 64; count++)
	{
		if(str1[num1] == '\0' && str2[num2] == '\0')		//二つの文字列がNULLならループ終了
		{
			count = 64;
		}


		if(str1[num1] == str2[num2])				//文字が一致
		{
			result[count * 2] = 't';
			distr1[count * 2] = str1[num1];
			distr2[count * 2] = str2[num2];

			num1++;
			num2++;
		}

		else if(str1[num1] != str2[num2])			//文字が不一致
		{
			result[count * 2] = 'f';

			judg1 = judg2 = 1;

			while(1)
			{
				if(str1[num1 + judg1] == str2[num2])	//文字列２の要素は変えずに文字列１の要素をずらして一致する文字を探す
				{
					break;
				}

				else 
				{
					judg1++;
				}
			}

			while(1)
			{
				if(str1[num1] == str2[num2 + judg2])	//文字列１の要素は変えずに文字列２の要素をずらして一致する文字を探す
				{
					break;
				}

				else
				{
					judg2++;
				}
			}

			if(judg1 > judg2)				//文字列１を文字列２に合わせてずらす場合
			{
				distr2[count * 2] = str2[num2];
				distr1[count * 2] = '_';
				num2 = num2 + judg2;	
			}

			else if(judg1 < judg2)
			{
				distr1[count * 2] = str1[num1];		//文字列２を文字列１に合わせてずらす場合
				distr2[count * 2] = '_';
				num1 = num1 + judg1;
			}
		}

		distr1[count * 2 + 1] = ' ';
		distr2[count * 2 + 1] = ' ';
		result[count * 2 + 1] = ' ';
		
	}

	printf("---------------------result--------------------\n");	//結果の表示
	printf(" %s\n", distr1);
	printf(" %s\n", distr2);
	printf(" %s\n", result);


	return 0;
}

