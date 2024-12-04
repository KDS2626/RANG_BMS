/*
* BOOK MANAGEMENT SYSTEM Ver 0.2
* 작성자 : 신예랑
* 내  용: 도서 관리 시스템 ver 0.2(C스타일 코딩 + STL 추가)
*/

#pragma once

#include<map>
#include<fstream>
#include<iostream>
#include<string>
#include<ctime>
using namespace std;

typedef struct {
	string BookName;	// 책 이름
	string WriterName;	// 저자
	int BookStatus;	// 대여상태 : 재고있음(0), 대여 중(1)
	string add_date;	// 등록 날짜
	int type;		// 장르
}Book;

class BookHandler
{
private:
	map<string, Book> book_map;		// key : isbn(국제표준도서번호), value : sturct
public:
	void SelectMenu() const;
	void ShowMenuInfo() const;
	void Search();
	void Rent();
	void Return();
	void Add();
	void Repair();
	void Drop();
	void ShowBookInfo() const;
	void Save();
	void Call_save();
};
