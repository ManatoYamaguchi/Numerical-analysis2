#include<stdio.h>

int main()
{
	int num1 = 0, num2 = 0, count, count2, count3, judg1, judg2;
	char str1[64], str2[64], restr1[128] = {}, restr2[128] = {}, result[64] = {};

	scanf("%s", str1);
	scanf("%s", str2);

	printf("str1 %s\n", str1);
	printf("str2 %s\n", str2);

	for(count = 0; count < 64; count++)
	{
		if(str1[num1] == str2[num2])				//文字が一致
		{
			result[count * 2] = 't';
			restr1[count * 2] = str1[num1];
			restr2[count * 2] = str2[num2];

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

				else if(str1[num1 + judg1] == '\0')
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
				if(str1[num1] == str2[num2 + judg2])	//文字列１の要素は変えずに文字列２の要素をずらして一致する文字を探す
				{
					break;
				}

				else if(str2[num2 + judg2] == '\0')
				{
					judg2 = 64;
					break;
				}

				else
				{
					judg2++;
				}
			}

			if(judg1 > judg2)				//文字列１を文字列２に合わせてずらす場合
			{
				restr2[count * 2] = str2[num2];
				restr1[count * 2] = '_';
				num2 = num2 + judg2;
				num1 = num1 + judg2 - 1;
			}

			else if(judg1 < judg2)
			{
				restr1[count * 2] = str1[num1];		//文字列２を文字列１に合わせてずらす場合
				restr2[count * 2] = '_';

				if(judg1 > 1)
				{
					for(count3 = 1; count3 < judg1; count3++)
					{
						restr1[count * 2 + 1] = ' ';
						restr2[count * 2 + 1] = ' ';
						result[count * 2 + 1] = ' ';

						count++;

						restr1[count * 2] = str1[num1 + count3];
						restr2[count * 2] = '_';
						result[count * 2] = 'f';
					}
				}

				num1 = num1 + judg1;
			}

			else if(judg1 == judg2)
			{
				restr1[count * 2] = str1[num1];
				restr2[count * 2] = str2[num2];
				num1++;
				num2++;
			}

		}

		if(str1[num1] == '\0' && str2[num2] == '\0')		//二つの文字列がNULLならループ終了
		{
			count = 64;
		}

		restr1[count * 2 + 1] = ' ';
		restr2[count * 2 + 1] = ' ';
		result[count * 2 + 1] = ' ';

	}

	printf("---------------------result--------------------\n");	//結果の表示
	printf("%s\n", restr1);
	printf("%s\n", restr2);
	printf("%s\n", result);


	return 0;
}

