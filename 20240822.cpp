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
		{800, 4, "삼다수"}, {1000, 2, "모카커피"}, {1200, 4, "포카리스웨트"}, {1500, 3, "펩시제로"}, {1500, 5, "코카콜라"}
	};

	printf("<<음료자판기!>>\n");
	printf("\n얼마를 넣으시겠습니까? : ");
	scanf("%d", &money);
	printf("\n");

	while (true) {
		for (int i = 0; i < N; i++) {
			printf("%d.[%6s] %4d원 (%d개남음)\n", (i + 1), beverages[i].name, beverages[i].price, beverages[i].stock);
		}

		int choice;
		printf("\n음료를 선택해주세요 : ");
		scanf("%d", &choice);
		if (money >= beverages[choice - 1].price) {
			printf("%s이(가) 나왔습니다.\n", beverages[choice - 1].name);
			money -= beverages[choice - 1].price;
			beverages[choice - 1].stock--;
		}
		else
			printf("음료를 구매할 수 없습니다.\n");

		printf("거스름돈을 반환하시겠습니까?(Y or N) : ");
		scanf(" %c", &change);

		if (change == 'Y') {
			printf("거스름돈 %d원이 나왔습니다.\n", money);
			break;
		}
		printf("\n");
	}

	return 0;
}