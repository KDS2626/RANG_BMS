/* book.c */

#include "Book.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 메뉴선택 시 오류
void Select_Menu()
{
	printf("  ┌────────────────────────────────────────────────────────────┐\n");
	printf("  │   해당 옵션은 유효하지 않는 옵션입니다. 재입력 바랍니다.   │\n");
	printf("  └────────────────────────────────────────────────────────────┘\n");

	Show_Menu();
}

// 0. 메뉴보기
void Show_Menu()
{
	int select;

	printf("\n───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");
	printf("  ┌───────────────────────────────────────┐\n");
	printf("  │    메뉴 보기 : 1        종료 : 0      │\n");
	printf("  └───────────────────────────────────────┘\n");
	printf("───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");
	printf(" → ");
	scanf_s("%d", &select);

	switch (select)
	{
	case 0:
		printf("!프로그램이 종료되었습니다.\n");
		exit(1);
	case 1:
		printf("          ┌────────┐\n");
		printf("┌─────────│ M E N U│──────────┐\n");
		printf("│         └────────┘          │\n");
		printf("│        1. 도서 검색         │\n");
		printf("│                             │\n");
		printf("│        2. 도서 대여         │\n");
		printf("│                             │\n");
		printf("│        3. 도서 반납         │\n");
		printf("│                             │\n");
		printf("│        4. 도서 추가         │\n");
		printf("│                             │\n");
		printf("│      5. 도서 정보 수정      │\n");
		printf("│                             │\n");
		printf("│        6. 도서 삭제         │\n");
		printf("│                             │\n");
		printf("│   7. 모든 도서 목록 보기    │\n");
		printf("│                             │\n");
		printf("│       8. 프로그램 종료      │\n");
		printf("│                             │\n");
		printf("│         9. 불러오기         │\n");
		printf("│                             │\n");
		printf("└─────────────────────────────┘\n");
		return;
	default:
		Select_Menu();
	}
}

// 1. 도서 검색(제목 또는 저자로 검색)
void Search(BOOK* user)
{
	int i, s_cnt = 1;
	char search[SIZE] = { 0 };
	char name_check[SIZE] = { 0 };

	printf("\n───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");
	printf("  ┌──────────────────────────────────┐\n");
	printf("  │   '도서 검색'을 선택 하였습니다. │\n");
	printf("  └──────────────────────────────────┘\n");
	printf("───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");

	printf(">> 책 제목으로 검색하려면 BN, 저자 이름으로 검색하려면 WN 을 입력하세요(나가기 : exit) : ");
	scanf_s("%s", search, (unsigned int)sizeof(search));
	if (!strcmp(search, "exit\n") || !strcmp(search, "exit")) return;

	if (!strcmp(search, "BN"))
	{
		printf("\n───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");
		printf("  ┌──────────────────────────────────────┐\n");
		printf("  │   '책 제목 검색'을 선택 하였습니다. │\n");
		printf("  └──────────────────────────────────────┘\n");
		printf("───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");

		printf("\n>> 책 제목을 입력하세요 : ");
		scanf_s("%s", name_check, (unsigned int)sizeof(name_check));

		for (i = 0; i < cnt; i++)
		{
			if (!strcmp(name_check, user[i].book_name))
			{
				printf("\n\n          ┌─────────────────┐\n");
				printf("┌─────────│  검 색 결 과  %d │──────────┐\n", s_cnt);
				printf("│         └─────────────────┘          │\n");
				printf("│                                      │\n");
				printf("│ ㆍ 책 제목 :   %s           │\n", user[i].book_name);
				printf("│                                      │\n");
				printf("│ ㆍ 저자 이름 :   %s              │\n", user[i].person_name);
				printf("│                                      │\n");
				printf("│ ㆍ I S B N : %s             │\n", user[i].ISBN);
				printf("│                                      │\n");
				printf("│ ㆍ 대여 상태 :   %s            │\n", user[i].book_status);
				printf("│                                      │\n");
				printf("└──────────────────────────────────────┘\n\n");
				printf("───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");
				s_cnt++;
			}
		}
		return;
	}
	if (!strcmp(search, "WN"))
	{
		printf("\n───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");
		printf("  ┌───────────────────────────────────────┐\n");
		printf("  │   '저자 이름 검색'을 선택 하였습니다. │\n");
		printf("  └───────────────────────────────────────┘\n");
		printf("───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");

		printf("\n>> 저자 이름을 입력하세요 : ");
		scanf_s("%s", name_check, (unsigned int)sizeof(name_check));

		for (i = 0; i < cnt; i++)
		{
			if (!strcmp(name_check, user[i].person_name))
			{
				printf("\n\n          ┌─────────────────┐\n");
				printf("┌─────────│  검 색 결 과  %d │──────────┐\n", s_cnt);
				printf("│         └─────────────────┘          │\n");
				printf("│                                      │\n");
				printf("│ ㆍ 책 제목 :   %s           │\n", user[i].book_name);
				printf("│                                      │\n");
				printf("│ ㆍ 저자 이름 :   %s              │\n", user[i].person_name);
				printf("│                                      │\n");
				printf("│ ㆍ I S B N : %s             │\n", user[i].ISBN);
				printf("│                                      │\n");
				printf("│ ㆍ 대여 상태 :   %s            │\n", user[i].book_status);
				printf("│                                      │\n");
				printf("└──────────────────────────────────────┘\n\n");
				printf("───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");
				s_cnt++;
			}
		}
		return;
	}
	else
	{
		printf("  ┌───────────────────────────────────────────────────────┐\n");
		printf("  │   잘못 입력 하였습니다. 재입력 바랍니다.   │\n");
		printf("  └───────────────────────────────────────────────────────┘\n");
		Search(user);
		return;
	}
	printf("  ┌────────────────────────────────────────────────────────────┐\n");
	printf("  │   해당 도서 및 저자는 유효하지 않습니다. 재입력 바랍니다.   │\n");
	printf("  └────────────────────────────────────────────────────────────┘\n");
	Search(user);
	return;
}

// 2. 도서 대여
void Rent(BOOK* user)
{
	int i;
	char book_check[SIZE] = { 0 };
	char person_check[SIZE] = { 0 };

	printf("\n───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");
	printf("  ┌──────────────────────────────────┐\n");
	printf("  │   '도서 대여'를 선택 하였습니다. │\n");
	printf("  └──────────────────────────────────┘\n");
	printf("───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");

	printf(">> 대여 할 도서의 '책 제목' 을 입력하세요(나가기 : exit) : ");
	scanf_s("%s", book_check, (unsigned int)sizeof(book_check));

	if (!strcmp(book_check, "exit\n") || !strcmp(book_check, "exit")) return;

	printf(">> 대여 할 도서의 '저자 이름' 을 입력하세요 :");
	scanf_s("%s", person_check, (unsigned int)sizeof(person_check));

	for (i = 0; i < cnt; i++)
	{
		if (!strcmp(user[i].book_name, book_check) && !strcmp(user[i].person_name, person_check))
		{
			if (!strcmp(user[i].book_status, "재고있음"))
			{
				strcpy_s(user[i].book_status, SIZE, "대여 중");

				printf("\n\n          ┌──────────────┐\n");
				printf("┌─────────│  대 여 완 료 │──────────┐\n");
				printf("│         └──────────────┘          │\n");
				printf("│                                      │\n");
				printf("│ ㆍ 책 제목 :   %s           │\n", user[i].book_name);
				printf("│                                      │\n");
				printf("│ ㆍ 저자 이름 :   %s              │\n", user[i].person_name);
				printf("│                                      │\n");
				printf("│ ㆍ I S B N : %s             │\n", user[i].ISBN);
				printf("│                                      │\n");
				printf("│ ㆍ 대여 상태 :   %s            │\n", user[i].book_status);
				printf("│                                      │\n");
				printf("└──────────────────────────────────────┘\n\n");
				printf("───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");
				return;
			}
			else
			{
				printf("  ┌─────────────────────────────────────────────────────────────────────────────────────┐\n");
				printf("  │         해당 도서는 현재 '대여 중'이므로 대여가 불가능합니다. 재입력 바랍니다.      │\n");
				printf("  └─────────────────────────────────────────────────────────────────────────────────────┘\n");
				Rent(user);
				return;
			}
		}
	}
	printf("  ┌────────────────────────────────────────────────────────────┐\n");
	printf("  │   해당 도서는 유효하지 않는 도서입니다. 재입력 바랍니다.   │\n");
	printf("  └────────────────────────────────────────────────────────────┘\n");
	Rent(user);
	return;
}

// 3. 도서 반납
void Return(BOOK* user)
{
	int i;
	char book_check[SIZE] = { 0 };
	char person_check[SIZE] = { 0 };

	printf("\n───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");
	printf("  ┌──────────────────────────────────┐\n");
	printf("  │   '도서 반납'을 선택 하였습니다. │\n");
	printf("  └──────────────────────────────────┘\n");
	printf("───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");

	printf(">> 반납 할 도서의 '책 제목' 을 입력하세요(나가기 : exit) : ");
	scanf_s("%s", book_check, (unsigned int)sizeof(book_check));

	if (!strcmp(book_check, "exit\n") || !strcmp(book_check, "exit")) return;

	printf(">> 반납 할 도서의 '저자 이름' 을 입력하세요 :");
	scanf_s("%s", person_check, (unsigned int)sizeof(person_check));

	for (i = 0; i < cnt; i++)
	{
		if (!strcmp(user[i].book_name, book_check) && !strcmp(user[i].person_name, person_check))
		{
			if (!strcmp(user[i].book_status, "대여 중"))
			{
				strcpy_s(user[i].book_status, SIZE, "재고있음");

				printf("\n\n          ┌──────────────┐\n");
				printf("┌─────────│  반 납 완 료 │──────────┐\n");
				printf("│         └──────────────┘          │\n");
				printf("│                                      │\n");
				printf("│ ㆍ 책 제목 :   %s           │\n", user[i].book_name);
				printf("│                                      │\n");
				printf("│ ㆍ 저자 이름 :   %s              │\n", user[i].person_name);
				printf("│                                      │\n");
				printf("│ ㆍ I S B N : %s             │\n", user[i].ISBN);
				printf("│                                      │\n");
				printf("│ ㆍ 대여 상태 :   %s            │\n", user[i].book_status);
				printf("│                                      │\n");
				printf("└──────────────────────────────────────┘\n\n");
				printf("───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");
				return;
			}
			else
			{
				printf("  ┌─────────────────────────────────────────────────────────────────────────────────────────────┐\n");
				printf("  │         해당 도서는 현재 '재고 있음'으로 반납이 불필요한 도서 입니다. 재입력 바랍니다.         │\n");
				printf("  └─────────────────────────────────────────────────────────────────────────────────────────────┘\n");
				Return(user);
				return;
			}
		}
	}
	printf("  ┌────────────────────────────────────────────────────────────┐\n");
	printf("  │   해당 도서는 유효하지 않는 도서입니다. 재입력 바랍니다.   │\n");
	printf("  └────────────────────────────────────────────────────────────┘\n");
	Return(user);
	return;
}

// 4. 재고에 새로운 도서 추가
void Add(BOOK* user)
{
	char book_name_check[SIZE] = { 0 };
	char write_name_check[SIZE] = { 0 };
	char ISBN_check[SIZE] = { 0 };
	char result[SIZE] = { 0 };
	int i;

	printf("\n───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");
	printf("  ┌──────────────────────────────────┐\n");
	printf("  │   '도서 추가'를 선택 하였습니다. │\n");
	printf("  └──────────────────────────────────┘\n");
	printf("───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");

	printf(">> 추가 할 도서의 '책 제목' 을 입력하세요(나가기 : exit) : ");
	scanf_s("%s", &book_name_check, (unsigned int)sizeof(book_name_check));
	if (strcmp(book_name_check, "exit\n") == 0 || strcmp(book_name_check, "exit") == 0) return;
	printf("\n>> 추가 할 도서의 '저자 이름' 을 입력하세요 : ");
	scanf_s("%s", &write_name_check, (unsigned int)sizeof(write_name_check));
	printf("\n>> 추가 할 도서의 'ISBN(고유번호)' 를 입력하세요 : ");
	scanf_s("%s", &ISBN_check, (unsigned int)sizeof(ISBN_check));

	if (strlen(ISBN_check) != 13)
	{
		printf("  ┌───────────────────────────────────────────────────────────────────┐\n");
		printf("  │   ISBN은 13자리 입력필수 입니다. 재입력 바랍니다. (입력한 자릿수 : %d자리  │\n", (int)strlen(ISBN_check));
		printf("  └───────────────────────────────────────────────────────────────────┘\n");
		Add(user);
		return;
	}

	for (i = 0; i < cnt; i++)
		if (!strcmp(book_name_check, user[i].book_name) && !strcmp(write_name_check, user[i].person_name))
		{
			printf("  ┌───────────────────────────────────────────────────────┐\n");
			printf("  │   이미 등록 된 도서입니다. 재입력 바랍니다.   │\n");
			printf("  └───────────────────────────────────────────────────────┘\n");
			Add(user);
			return;
		}

	result[0] = ISBN_check[0];
	result[1] = ISBN_check[1];
	result[2] = ISBN_check[2];
	result[3] = '-';
	result[4] = ISBN_check[3];
	result[5] = '-';
	result[6] = ISBN_check[4];
	result[7] = ISBN_check[5];
	result[8] = '-';
	result[9] = ISBN_check[6];
	result[10] = ISBN_check[7];
	result[11] = ISBN_check[8];
	result[12] = ISBN_check[9];
	result[13] = ISBN_check[10];
	result[14] = ISBN_check[11];
	result[15] = '-';
	result[16] = ISBN_check[12];
	result[17] = '\0';

	for (i = 0; i < cnt; i++)
		if (!strcmp(result, user[i].ISBN))
		{
			printf("  ┌───────────────────────────────────────────────────────┐\n");
			printf("  │   이미 등록 된 ISBN 입니다. 재입력 바랍니다.   │\n");
			printf("  └───────────────────────────────────────────────────────┘\n");
			Add(user);
			return;
		}

	strcpy_s(user[cnt].book_name, SIZE, book_name_check);
	strcpy_s(user[cnt].person_name, SIZE, write_name_check);
	strcpy_s(user[cnt].ISBN, SIZE, result);
	strcpy_s(user[cnt].book_status, SIZE, "재고있음");

	printf("\n\n          ┌──────────────┐\n");
	printf("┌─────────│  추 가 완 료 │──────────┐\n");
	printf("│         └──────────────┘          │\n");
	printf("│                                      │\n");
	printf("│ ㆍ 책 제목 :   %s           │\n", user[cnt].book_name);
	printf("│                                      │\n");
	printf("│ ㆍ 저자 이름 :   %s              │\n", user[cnt].person_name);
	printf("│                                      │\n");
	printf("│ ㆍ I S B N : %s             │\n", user[cnt].ISBN);
	printf("│                                      │\n");
	printf("│ ㆍ 대여 상태 :   %s            │\n", user[cnt].book_status);
	printf("│                                      │\n");
	printf("└──────────────────────────────────────┘\n\n");
	printf("───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");
	cnt++;
	return;
}

// 5. 도서 정보 수정(예: 잘못된 정보 수정)
void Repair(BOOK* user)
{
	int i;
	char repair[SIZE] = { 0 };
	char book_name[SIZE] = { 0 };
	char write_name[SIZE] = { 0 };
	char repair_BNWN[SIZE] = { 0 };

	printf("\n───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");
	printf("  ┌───────────────────────────────────────┐\n");
	printf("  │   '도서 정보 수정'을 선택 하였습니다. │\n");
	printf("  └───────────────────────────────────────┘\n");
	printf("───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");

	printf(">> 책 제목을 수정하려면 BN, 저자 이름을 수정하려면 WN 을 입력하세요(나가기 : exit) : ");
	scanf_s("%s", repair, (unsigned int)sizeof(repair));
	if (!strcmp(repair, "exit\n") || !strcmp(repair, "exit")) return;

	if (!strcmp(repair, "BN"))
	{

		printf("\n───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");
		printf("  ┌──────────────────────────────────────┐\n");
		printf("  │   '책 제목 수정'을 선택 하였습니다. │\n");
		printf("  └──────────────────────────────────────┘\n");
		printf("───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");

		printf("\n>> 책 제목을 입력하세요 : ");
		scanf_s("%s", book_name, (unsigned int)sizeof(book_name));

		printf("\n>> 저자 이름을 입력하세요 : ");
		scanf_s("%s", write_name, (unsigned int)sizeof(write_name));

		for (i = 0; i < cnt; i++)
		{
			if (!strcmp(book_name, user[i].book_name) && !strcmp(write_name, user[i].person_name))
			{
				printf("\n\n>> 수정 할 '도서 제목' 을 입력하세요 : ");
				scanf_s("%s", repair_BNWN, (unsigned int)sizeof(repair_BNWN));
				strcpy_s(user[i].book_name, SIZE, repair_BNWN);

				printf("\n\n          ┌──────────────┐\n");
				printf("┌─────────│  수 정 완 료 │──────────┐\n");
				printf("│         └──────────────┘          │\n");
				printf("│                                      │\n");
				printf("│ ㆍ 책 제목 :   %s           │\n", user[i].book_name);
				printf("│                                      │\n");
				printf("│ ㆍ 저자 이름 :   %s              │\n", user[i].person_name);
				printf("│                                      │\n");
				printf("│ ㆍ I S B N : %s             │\n", user[i].ISBN);
				printf("│                                      │\n");
				printf("│ ㆍ 대여 상태 :   %s            │\n", user[i].book_status);
				printf("│                                      │\n");
				printf("└──────────────────────────────────────┘\n\n");
				printf("───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");
				return;
			}
		}
	}
	else if (!strcmp(repair, "WN"))
	{
		printf("\n───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");
		printf("  ┌───────────────────────────────────────┐\n");
		printf("  │   '저자 이름 수정'을 선택 하였습니다. │\n");
		printf("  └───────────────────────────────────────┘\n");
		printf("───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");

		printf("\n>> 책 제목을 입력하세요 : ");
		scanf_s("%s", book_name, (unsigned int)sizeof(book_name));

		printf("\n>> 저자 이름을 입력하세요 : ");
		scanf_s("%s", write_name, (unsigned int)sizeof(write_name));

		for (i = 0; i < cnt; i++)
		{
			if (!strcmp(book_name, user[i].book_name) && !strcmp(write_name, user[i].person_name))
			{
				printf("\n\n>> 수정 할 '저자 이름' 을 입력하세요 : ");
				scanf_s("%s", repair_BNWN, (unsigned int)sizeof(repair_BNWN));
				strcpy_s(user[i].person_name, SIZE, repair_BNWN);

				printf("\n\n          ┌──────────────┐\n");
				printf("┌─────────│  수 정 완 료 │──────────┐\n");
				printf("│         └──────────────┘          │\n");
				printf("│                                      │\n");
				printf("│ ㆍ 책 제목 :   %s           │\n", user[i].book_name);
				printf("│                                      │\n");
				printf("│ ㆍ 저자 이름 :   %s              │\n", user[i].person_name);
				printf("│                                      │\n");
				printf("│ ㆍ I S B N : %s             │\n", user[i].ISBN);
				printf("│                                      │\n");
				printf("│ ㆍ 대여 상태 :   %s            │\n", user[i].book_status);
				printf("│                                      │\n");
				printf("└──────────────────────────────────────┘\n\n");
				printf("───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");
				return;
			}
		}
	}
	else
	{
		printf("  ┌───────────────────────────────────────────────────────┐\n");
		printf("  │   잘못 입력 하였습니다. 재입력 바랍니다.   │\n");
		printf("  └───────────────────────────────────────────────────────┘\n");
		Repair(user);
		return;
	}
	printf("  ┌────────────────────────────────────────────────────────────┐\n");
	printf("  │   해당 도서는 유효하지 않는 도서입니다. 재입력 바랍니다.   │\n");
	printf("  └────────────────────────────────────────────────────────────┘\n");
	Repair(user);
	return;
}

// 6. 도서 삭제
void Drop(BOOK* user)
{
	int i, j;
	char BN_check[SIZE] = { 0 };
	char WN_check[SIZE] = { 0 };

	printf("\n───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");
	printf("  ┌──────────────────────────────────┐\n");
	printf("  │   '도서 삭제'를 선택 하였습니다. │\n");
	printf("  └──────────────────────────────────┘\n");
	printf("───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");

	printf(">> 삭제 할 도서의 '책 제목' 을 입력하세요(나가기 : exit) : ");
	scanf_s("%s", BN_check, (unsigned int)sizeof(BN_check));
	if (!strcmp(BN_check, "exit\n") || !strcmp(BN_check, "exit")) return;

	printf(">> 삭제 할 도서의 '저자 이름' 을 입력하세요 : ");
	scanf_s("%s", WN_check, (unsigned int)sizeof(WN_check));

	for (i = 0; i < cnt; i++)
	{
		if (!strcmp(BN_check, user[i].book_name) && !strcmp(WN_check, user[i].person_name))
		{
			// 다음요소에 값이 있다면 
			if (!strcmp(user[i + 1].book_status, "대여 중") || !strcmp(user[i + 1].book_status, "재고있음"))
			{
				for (j = i; j < cnt - 1; j++)
				{
					user[j] = user[j + 1];
				}
			}
			cnt--;
			printf("\n───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");
			printf("  ┌────────────────────────────────┐\n");
			printf("  │       삭제 완료되었습니다.     │\n");
			printf("  └────────────────────────────────┘\n");
			printf("───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n\n");
			return;
		}
	}
	printf("  ┌────────────────────────────────────────────────────────────┐\n");
	printf("  │   해당 도서는 유효하지 않는 도서입니다. 재입력 바랍니다.   │\n");
	printf("  └────────────────────────────────────────────────────────────┘\n");
	Drop(user);
	return;
}

// 7. 모든 도서 목록 보기
void Watch_BookList(BOOK* user)
{
	int i;

	printf("\n───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");
	printf("  ┌──────────────────────────────────────────────────────┐\n");
	printf("  │         '모든 도서 목록 보기'를 선택 하였습니다.      │\n");
	printf("  └──────────────────────────────────────────────────────┘\n");
	printf("───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");

	for (i = 0; i < cnt; i++)
	{
		printf("[%d]\n", i + 1);
		printf("책 제목 : %s\n", user[i].book_name);
		printf("저자 : %s\n", user[i].person_name);
		printf("ISBN : %s\n", user[i].ISBN);
		printf("대여 상태 : %s\n\n", user[i].book_status);
	}
	return;
}

// 8. 저장하기
void Save(BOOK* user)
{
	int i;
	char save[SIZE] = { 0 };

	printf("\n>> 저장 하시겠습니까?(Y/N) : ");
	scanf_s("%s", save, (unsigned int)sizeof(save));

	if (!strcmp(save, "Y"))
	{
		FILE* fp;
		errno_t err1 = fopen_s(&fp, "C:\\BookSearch\\book.txt", "w");
		if (err1)
		{
			printf("fopen error!");
			exit(1);
		}

		for (i = 0; i < cnt; i++)
		{
			fputc('[', fp);
			fprintf(fp, "%d", i + 1);
			fputc(']', fp);
			fputc('\n', fp);
			fputs("ㆍ책 제목 : ", fp);
			fputs(user[i].book_name, fp);
			fputc('\n', fp);
			fputs("ㆍ저자 이름 : ", fp);
			fputs(user[i].person_name, fp);
			fputc('\n', fp);
			fputs("ㆍISBN : ", fp);
			fputs(user[i].ISBN, fp);
			fputc('\n', fp);
			fputs("ㆍ대여 상태 : ", fp);
			fputs(user[i].book_status, fp);
			fputc('\n', fp);
		}
		printf("  ┌──────────────────────────────────────────┐\n");
		printf("  │   저장 완료. 프로그램이 종료 되었습니다. │\n");
		printf("  └──────────────────────────────────────────┘\n");
		return;
	}
	else if (!strcmp(save, "N"))
	{
		printf("  ┌───────────────────────────────┐\n");
		printf("  │   프로그램이 종료 되었습니다. │\n");
		printf("  └───────────────────────────────┘\n");
		return;
	}
	printf("  ┌───────────────────────────────────────────────────────┐\n");
	printf("  │   잘못 입력 하였습니다. 재입력 바랍니다.   │\n");
	printf("  └───────────────────────────────────────────────────────┘\n");
	Save(user);
	return;
}

// 9. 파일에서 도서정보 불러오기
void Call_save(BOOK* user)
{
	printf("\n───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");
	printf("  ┌──────────────────────────────────────────────────────┐\n");
	printf("  │         '도서정보 불러오기'를 선택 하였습니다.       │\n");
	printf("  └──────────────────────────────────────────────────────┘\n");
	printf("───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");

	FILE* fp;
	errno_t err1 = fopen_s(&fp, "C:\\BookSearch\\book.txt", "r");
	if (err1)
	{
		printf("fopen error!");
		exit(1);
	}
	while (cnt < SIZE)
	{
		char ch[SIZE];
		fgets(ch, SIZE, fp);
		if (feof(fp)) break;

		fgets(ch, SIZE, fp);
		sscanf_s(ch, "ㆍ책 제목 : %[^\n]", user[cnt].book_name, (unsigned int)sizeof(user[cnt].book_name));

		fgets(ch, SIZE, fp);
		sscanf_s(ch, "ㆍ저자 이름 : %[^\n]", user[cnt].person_name, (unsigned int)sizeof(user[cnt].person_name));

		fgets(ch, SIZE, fp);
		sscanf_s(ch, "ㆍISBN : %[^\n]", user[cnt].ISBN, (unsigned int)sizeof(user[cnt].ISBN));

		fgets(ch, SIZE, fp);
		sscanf_s(ch, "ㆍ대여 상태 : %[^\n]", user[cnt].book_status, (unsigned int)sizeof(user[cnt].book_status));

		cnt++;
	}
	fclose(fp);

	printf("  ┌───────────────────────────────────────┐\n");
	printf("  │   도서정보 불러오기 완료 되었습니다.  │\n");
	printf("  └───────────────────────────────────────┘\n");

	for (int i = 0; i < cnt; i++)
	{
		printf("[%d]\n", i + 1);
		printf("책 제목 : %s\n", user[i].book_name);
		printf("저자 : %s\n", user[i].person_name);
		printf("ISBN : %s", user[i].ISBN);
		printf("\n대여 상태 : %s\n\n", user[i].book_status);
	}
	return;
}
