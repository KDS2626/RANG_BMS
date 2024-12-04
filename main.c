/*
* BOOK MANAGEMENT SYSTEM Ver 0.1
* 작성자 : 신예랑
* 내  용: 도서 관리 시스템 ver 0.1(C스타일 코딩, UI o)
*/

#include "Book.h"
#include<stdio.h>

int main()
{
	int choice;
	BOOK user[SIZE];

	while (1)
	{
		Show_Menu();
		printf("  ┌────────────────────────┐\n");
		printf("  │   옵션을 선택 하세요   │\n");
		printf("  └────────────────────────┘\n");
		printf(" >> 선택 : ");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case SEARCH:
			Search(user);
			break;
		case RENT:
			Rent(user);
			break;
		case RETURN:
			Return(user);
			break;
		case ADD:
			Add(user);
			break;
		case REPAIR:
			Repair(user);
			break;
		case DROP:
			Drop(user);
			break;
		case WATCH_BOOKLIST:
			Watch_BookList(user);
			break;
		case EXIT:
			Save(user);
			break;
		case CALL:
			Call_save(user);
			break;
		default:
			return 0;
		}

		if (choice == EXIT)
			return -1;
	}
	return 0;
}
