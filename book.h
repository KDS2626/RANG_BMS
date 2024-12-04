/*
* BOOK MANAGEMENT SYSTEM Ver 0.1
* 작성자 : 신예랑
* 내  용: 도서 관리 시스템 ver 0.1(C스타일 코딩, UI o)
*/

#pragma once
#define SIZE 30

enum { SEARCH = 1, RENT, RETURN, ADD, REPAIR, DROP, WATCH_BOOKLIST, EXIT, CALL };
int cnt;

typedef struct
{
	char book_name[SIZE];      // 책 이름
	char person_name[SIZE];   // 저자
	char ISBN[SIZE ];         // 국제표준도서번호
	char book_status[SIZE];   // 대여상태 : 대여 중, 재고있음
}BOOK;

void Select_Menu();
void Show_Menu();
void Search(BOOK*);
void Rent(BOOK*);
void Return(BOOK*);
void Add(BOOK*);
void Repair(BOOK*);
void Drop(BOOK*);
void Watch_BookList(BOOK*);
void Save(BOOK*);
void Call_save(BOOK*);
