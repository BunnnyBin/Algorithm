#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char num[10];
	gets(num);

	int count = 0;
	int len = strlen(num);
	int plastic[10] = { 0 };

	//�Էµ� ���� �Ѱ��� �����Ѵ�.
	int part_num;
	for (int x = 0; x < len; x++) {
		part_num = num[x] - '0';

		//��Ʈ�� ���� ���
		if (!plastic[part_num]) {
			//6�� 9�� ���
			if (part_num == 6 && plastic[9] != 0)
				plastic[9] = 0;
			else if(part_num == 9 && plastic[6] != 0)
				plastic[6] = 0;

			else {
				for (int i = 0; i < 10; i++)
					plastic[i]++;

				plastic[part_num]--;
				count++;
			}
		}
		//��Ʈ�� �ִ� ���
		else {
			plastic[part_num]--;
		}
	}

	printf("%d", count);
}