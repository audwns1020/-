#include <stdio.h>

struct BEVERAGE
{
	int price;
	int stock;
	char name[20];
};

int main()
{
	const int N = 5;
	int money = 0;
	char change;
	BEVERAGE beverages[N] = {
		{800, 4, "��ټ�"}, {1000, 2, "��īĿ��"}, {1200, 4, "��ī������Ʈ"}, {1500, 3, "�������"}, {1500, 5, "��ī�ݶ�"}
	};

	printf("<<�������Ǳ�!>>\n");
	printf("\n�󸶸� �����ðڽ��ϱ�? : ");
	scanf("%d", &money);
	printf("\n");

	while (true) {
		for (int i = 0; i < N; i++) {
			printf("%d.[%6s] %4d�� (%d������)\n", (i + 1), beverages[i].name, beverages[i].price, beverages[i].stock);
		}

		int choice;
		printf("\n���Ḧ �������ּ��� : ");
		scanf("%d", &choice);
		if (money >= beverages[choice - 1].price) {
			printf("%s��(��) ���Խ��ϴ�.\n", beverages[choice - 1].name);
			money -= beverages[choice - 1].price;
			beverages[choice - 1].stock--;
		}
		else
			printf("���Ḧ ������ �� �����ϴ�.\n");

		printf("�Ž������� ��ȯ�Ͻðڽ��ϱ�?(Y or N) : ");
		scanf(" %c", &change);

		if (change == 'Y') {
			printf("�Ž����� %d���� ���Խ��ϴ�.\n", money);
			break;
		}
		printf("\n");
	}

	return 0;
}