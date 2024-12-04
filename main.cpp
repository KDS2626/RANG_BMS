/*
* BOOK MANAGEMENT SYSTEM Ver 0.2
* 작성자 : 신예랑
* 내  용: 도서 관리 시스템 ver 0.2(C스타일 코딩 + STL 추가)
*/

#include "BookHandler.h"

enum { SEARCH = 1, RENT, RETURN, ADD, REPAIR, DROP, WATCH_BOOKLIST, EXIT, CALL };

int main()
{
	int choice;
	BookHandler user;

	while (1)
	{
		user.ShowMenuInfo();
		cout << ">> 옵션 선택 : ";
		cin >> choice;

		switch (choice)
		{
		case SEARCH:
			user.Search();
			break;
		case RENT:
			user.Rent();
			break;
		case RETURN:
			user.Return();
			break;
		case ADD:
			user.Add();
			break;
		case REPAIR:
			user.Repair();
			break;
		case DROP:
			user.Drop();
			break;
		case WATCH_BOOKLIST:
			user.ShowBookInfo();
			break;
		case EXIT:
			user.Save();
			break;
		case CALL:
			user.Call_save();
			break;
		default:
			cout << "잘못 입력 하였습니다. 재입력 바랍니다." << endl;
			continue;
		}

		if (choice == EXIT)
			return -1;
	}
	return 0;
}
