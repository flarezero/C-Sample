#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

void sample1()
{
	wchar_t str[256] = {};//���C�h����(���{��)�ɑΉ�����char�^�̐錾
	int res;//wscanf_s ���s���ʗp�ϐ�

	setlocale(LC_CTYPE, "");//������֘A�������V�X�e������ɐݒ�

	printf("�L�[�{�[�h���當������͂��Ă�������\n");//���͎w���\���@\n(���s�̓��ꕶ��)
	res = wscanf_s(L"%s",str,(unsigned)_countof(str));//���C�h����(���{��)�̓��͑҂��@L"%s"(�����ݒ�) str(���͕�����i�[�ϐ�) (unsigned)_countof(str) (�i�[�ϐ��̃T�C�Y�擾)�@

	wprintf(L"���͂��ꂽ������:%s�ł�\n\n", str);//���͌�̃��C�h����(���{��)�\���@L"���͂��ꂽ������:%s�ł�\n\n"(�\�������ݒ�) str(�\��������ϐ�)


}

void sample2()
{
	double a=0, b=0;
	int mode = 0,sres=0;
	double calRes = 0;

	printf("�v�Z���@��I�����Ă�������\n1:���Z 2:���Z 3:��Z 4:���Z\n");
	
	sres = scanf_s("%d", &mode);

	printf("���l1����͂��Ă�������\n");

	sres = scanf_s("%lf", &a);

	printf("���l2����͂��Ă�������\n");

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
				printf("���l2��0�ׁ̈A���Z�o���܂���\n");
				return;
			}
			break;			
		default:
			printf("���͂��s���ł�1����4�̔��p�����œ��͂��Ă�������\n");
			return;
	}

	printf("�v�Z���ʂ�%lf�ł�\n", calRes);
}


int main()
{
	void (*func[2])();//�֐��|�C���^�̔z��錾

	func[0] = sample1;//�֐��|�C���^�ɃT���v���֐�1����
	func[1] = sample2;//�֐��|�C���^�ɃT���v���֐�2����

	for (int i = 0; i < 2; i++)//for���Ŋ֐��|�C���^�̎��s���J��Ԃ�
		(*func[i])();//i�̐��l�Ŋ֐��|�C���^�̃C���f�b�N�X��I�����֐������s
	
	/*/////////////////////////////////////////////////////////////////////////
	while�ɒu���������ꍇ
	
	int i = 0;

	while(i<2)
	{
		(*func[i])();
		i++;
	}
	////////////////////////////////////////////////////////////////////////*/
	return 0;
}

