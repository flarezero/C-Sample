#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

void sample1()
{
	wchar_t str[256] = {};//ワイド文字(日本語)に対応したchar型の宣言
	int res;//wscanf_s 実行結果用変数

	setlocale(LC_CTYPE, "");//文字列関連処理をシステム言語に設定

	printf("キーボードから文字を入力してください\n");//入力指示表示　\n(改行の特殊文字)
	res = wscanf_s(L"%s",str,(unsigned)_countof(str));//ワイド文字(日本語)の入力待ち　L"%s"(書式設定) str(入力文字列格納変数) (unsigned)_countof(str) (格納変数のサイズ取得)　

	wprintf(L"入力された文字は:%sです\n\n", str);//入力後のワイド文字(日本語)表示　L"入力された文字は:%sです\n\n"(表示書式設定) str(表示文字列変数)


}

void sample2()
{
	double a=0, b=0;
	int mode = 0,sres=0;
	double calRes = 0;

	printf("計算方法を選択してください\n1:加算 2:減算 3:乗算 4:除算\n");
	
	sres = scanf_s("%d", &mode);

	printf("数値1を入力してください\n");

	sres = scanf_s("%lf", &a);

	printf("数値2を入力してください\n");

	sres = scanf_s("%lf", &b);

	switch (mode)
	{
		case 1:
			calRes = a + b;
			break;
		case 2:
			calRes = a - b;
			break;
		case 3:
			calRes = a * b;
			break;
		case 4:
			if (b != 0)
				calRes = a / b;
			else
			{
				printf("数値2が0の為、除算出来ません\n");
				return;
			}
			break;			
		default:
			printf("入力が不正です1から4の半角数字で入力してください\n");
			return;
	}

	printf("計算結果は%lfです\n", calRes);
}


int main()
{
	void (*func[2])();//関数ポインタの配列宣言

	func[0] = sample1;//関数ポインタにサンプル関数1を代入
	func[1] = sample2;//関数ポインタにサンプル関数2を代入

	for (int i = 0; i < 2; i++)//for文で関数ポインタの実行を繰り返し
		(*func[i])();//iの数値で関数ポインタのインデックスを選択し関数を実行
	
	/*/////////////////////////////////////////////////////////////////////////
	whileに置き換えた場合
	
	int i = 0;

	while(i<2)
	{
		(*func[i])();
		i++;
	}
	////////////////////////////////////////////////////////////////////////*/
	return 0;
}

