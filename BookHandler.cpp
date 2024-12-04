/*
* BOOK MANAGEMENT SYSTEM Ver 0.2
* 작성자 : 신예랑
* 내  용: 도서 관리 시스템 ver 0.2(C스타일 코딩 + STL 추가)
*/

#include "BookHandler.h"

void BookHandler::SelectMenu() const
{
	cout << "!입력오류. 재입력 바람." << endl;
	ShowMenuInfo();
}

void BookHandler::ShowMenuInfo() const
{
	int select;

	cout << "[ 메뉴보기(1), 종료(0) ]" << endl;
	cout << " → ";
	cin >> select;

	switch (select)
	{
	case 0:
		cout << "!프로그램이 종료되었습니다." << endl;
		exit(1);
	case 1:
		cout << "1. 도서 검색" << endl;
		cout << "2. 도서 대여" << endl;
		cout << "3. 도서 반납" << endl;
		cout << "4. 도서 추가" << endl;
		cout << "5. 도서 정보수정" << endl;
		cout << "6. 도서 삭제" << endl;
		cout << "7. 모든 도서 목록보기" << endl;
		cout << "8. 프로그램 종료" << endl;
		cout << "9. 불러오기" << endl;
		return;
	default:
		SelectMenu();
	}
}

// 1. 도서 검색(제목 또는 저자로 검색)
void BookHandler::Search()
{
	int s_cnt = 1;
	string search, name_check;
	int type_check;

	cout << ">> 책 제목으로 검색하려면 BN, 저자 이름으로 검색하려면 WN, 장르로 검색 하려면 TN을 입력하세요(나가기 : exit) : ";
	cin >> search;

	if (search == "exit\n" || search == "exit") return;

	if (search == "BN")
	{
		cout << ">> 책 제목을 입력하세요 : ";
		cin >> name_check;

		for (auto& entry : book_map)
		{
			if (entry.second.BookName == name_check)
			{
				cout << "[" << s_cnt << "]" << endl;
				cout << "ㆍ책 제목 : " << entry.second.BookName << endl;
				cout << "ㆍ저자 이름 : " << entry.second.WriterName << endl;
				cout << "ㆍI S B N : " << entry.first << endl;
				if (entry.second.BookStatus)
				{
					cout << "ㆍ대여 상태 : 대여 중" << endl;
				}
				else
				{
					cout << "ㆍ대여 상태 : 대여 가능" << endl;
				}
				cout << "ㆍ장르 : ";
				switch (entry.second.type)
				{
				case 1:
					cout << "소설(1)" << endl;
					break;
				case 2:
					cout << "에세이(2)" << endl;
					break;
				case 3:
					cout << "IT & 모바일(3)" << endl;
					break;
				case 4:
					cout << "유아(4)" << endl;
					break;
				case 5:
					cout << "자기계발(5)" << endl;
					break;
				case 6:
					cout << "인문(6)" << endl;
					break;
				case 7:
					cout << "역사(7)" << endl;
					break;
				}
				cout << "ㆍ등록된 날짜 : " << entry.second.add_date << endl;

				s_cnt++;
			}
		}

		return;
	}
	if (search == "WN")
	{
		cout << ">> 저자 이름을 입력하세요 : ";
		cin >> name_check;

		for (auto& entry : book_map)
		{
			if (entry.second.WriterName == name_check)
			{
				cout << "[" << s_cnt << "]" << endl;
				cout << "ㆍ책 제목 : " << entry.second.BookName << endl;
				cout << "ㆍ저자 이름 : " << entry.second.WriterName << endl;
				cout << "ㆍI S B N : " << entry.first << endl;
				if (entry.second.BookStatus)
				{
					cout << "ㆍ대여 상태 : 대여 중" << endl;
				}
				else
				{
					cout << "ㆍ대여 상태 : 대여 가능" << endl;
				}
				cout << "ㆍ장르 : ";
				switch (entry.second.type)
				{
				case 1:
					cout << "소설(1)" << endl;
					break;
				case 2:
					cout << "에세이(2)" << endl;
					break;
				case 3:
					cout << "IT & 모바일(3)" << endl;
					break;
				case 4:
					cout << "유아(4)" << endl;
					break;
				case 5:
					cout << "자기계발(5)" << endl;
					break;
				case 6:
					cout << "인문(6)" << endl;
					break;
				case 7:
					cout << "역사(7)" << endl;
					break;
				}
				cout << "ㆍ등록된 날짜 : " << entry.second.add_date << endl;
				s_cnt++;
			}
		}

		return;
	}
	if (search == "TN")
	{
		cout << "소설(1)" << endl;
		cout << "에세이(2)" << endl;
		cout << "IT & 모바일(3)" << endl;
		cout << "유아(4)" << endl;
		cout << "자기계발(5)" << endl;
		cout << "인문(6)" << endl;
		cout << "역사(7)" << endl;
		cout << ">> 장르코드를 입력하세요 : ";
		cin >> type_check;

		for (auto& entry : book_map)
		{
			if (entry.second.type == type_check)
			{
				cout << "[" << s_cnt << "]" << endl;
				cout << "ㆍ책 제목 : " << entry.second.BookName << endl;
				cout << "ㆍ저자 이름 : " << entry.second.WriterName << endl;
				cout << "ㆍI S B N : " << entry.first << endl;
				if (entry.second.BookStatus)
				{
					cout << "ㆍ대여 상태 : 대여 중" << endl;
				}
				else
				{
					cout << "ㆍ대여 상태 : 대여 가능" << endl;
				}
				cout << "ㆍ장르 : ";
				switch (entry.second.type)
				{
				case 1:
					cout << "소설(1)" << endl;
					break;
				case 2:
					cout << "에세이(2)" << endl;
					break;
				case 3:
					cout << "IT & 모바일(3)" << endl;
					break;
				case 4:
					cout << "유아(4)" << endl;
					break;
				case 5:
					cout << "자기계발(5)" << endl;
					break;
				case 6:
					cout << "인문(6)" << endl;
					break;
				case 7:
					cout << "역사(7)" << endl;
					break;
				}
				cout << "ㆍ등록된 날짜 : " << entry.second.add_date << endl;
				s_cnt++;
			}
		}

		return;
	}
	else
	{
		cout << "!입력오류. 재입력 바람." << endl;
		Search();
		return;
	}
	cout << "!유효하지않는 도서 및 저자. 재입력 바람." << endl;
	Search();
	return;
}

// 2. 도서 대여
void BookHandler::Rent()
{
	string book_check, person_check;

	cout << ">> 대여 할 도서의 '책 제목' 을 입력하세요(나가기 : exit) : ";
	cin >> book_check;

	if (book_check == "exit\n" || book_check == "exit") return;

	cout << ">> 대여 할 도서의 '저자 이름' 을 입력하세요 :";
	cin >> person_check;

	for (auto& entry : book_map)
	{
		if (entry.second.BookName == book_check && entry.second.WriterName == person_check)
		{
			if (entry.second.BookStatus == 0)
			{
				entry.second.BookStatus = 1;
				cout << "대여완료" << endl;
				return;
			}
			else
			{
				cout << "!대여 중이므로 대여 불가. 재입력 바람." << endl;
				Rent();
				return;
			}
		}
	}

	cout << "!유효하지않는 도서 및 저자.재입력 바람." << endl;
	Rent();
	return;
}

// 3. 도서 반납
void BookHandler::Return()
{
	string book_check, person_check;

	cout << ">> 반납 할 도서의 '책 제목' 을 입력하세요(나가기 : exit) : ";
	cin >> book_check;

	if (book_check == "exit\n" || book_check == "exit") return;

	cout << ">> 반납 할 도서의 '저자 이름' 을 입력하세요 :";
	cin >> person_check;

	for (auto& entry : book_map)
	{
		if (entry.second.BookName == book_check && entry.second.WriterName == person_check)
		{
			if (entry.second.BookStatus == 1)
			{
				entry.second.BookStatus = 0;
				cout << "반납완료" << endl;
				return;
			}
			else
			{
				cout << "!재고있음으로 반납 불필요. 재입력 바람." << endl;
				Return();
				return;
			}
		}
	}

	cout << "!유효하지않는 도서 및 저자. 재입력 바람." << endl;
	Return();
	return;
}

// 4. 재고에 새로운 도서 추가
void BookHandler::Add()
{
	Book book;
	string Isbn;
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);

	cout << ">> 추가 할 도서의 '책 제목' 을 입력하세요(나가기 : exit) : ";
	cin >> book.BookName;
	if (book.BookName == "exit\n" || book.BookName == "exit") return;
	cout << ">> 추가 할 도서의 '저자 이름' 을 입력하세요 : ";
	cin >> book.WriterName;
	cout << ">> 추가 할 도서의 'ISBN(고유번호)' 를 입력하세요 : ";
	cin >> Isbn;
	if (Isbn.size() != 13)
	{
		cout << "!ISBN은 13자리 입력필수. 재입력 바람. (입력한 자릿수 : " << Isbn.size() << "자리)" << endl << endl;
		Add();
		return;
	}
	cout << ">> 추가 할 도서의 장르코드를 선택 하세요" << endl;
	cout << ">>>> 소설(1)" << endl;
	cout << ">>>> 에세이(2)" << endl;
	cout << ">>>> IT & 모바일(3)" << endl;
	cout << ">>>> 유아(4)" << endl;
	cout << ">>>> 자기계발(5)" << endl;
	cout << ">>>> 인문(6)" << endl;
	cout << ">>>> 역사(7)" << endl;
	cout << " : ";
	cin >> book.type;
	if (book.type > 7 || book.type < 1)
	{
		cout << "!장르코드를 잘못 입력 하였습니다. 재입력 바람. (입력한 코드 : " << book.type << ")" << endl;
		Add();
		return;
	}
	book.BookStatus = 0;

	book.add_date = to_string(ltm.tm_year + 1900) + "-" + to_string(1 + ltm.tm_mon) + "-" + to_string(ltm.tm_mday);

	Isbn.insert(3, "-");
	Isbn.insert(5, "-");
	Isbn.insert(8, "-");
	Isbn.insert(15, "-");

	for (const auto& entry : book_map)
	{
		if (entry.second.BookName == book.BookName && entry.second.WriterName == book.WriterName)
		{
			cout << "!이미 등록 된 도서. 재입력 바람." << endl;
			Add();
			return;
		}
		if (entry.first == Isbn)
		{
			cout << "!이미 등록 된 ISBN. 재입력 바람." << endl;
			Add();
			return;
		}
	}

	auto result = book_map.insert({ Isbn, book });

	if (!result.second)
	{
		cout << "!insert 실패" << endl;
		Add();
		return;
	}

	cout << "추가완료." << endl;
	return;
}

// 5. 도서 정보 수정(예: 잘못된 정보 수정)
void BookHandler::Repair()
{
	string repair;
	string book_name;
	string write_name;
	string modify_name;

	cout << ">> 책 제목을 수정하려면 BN, 저자 이름을 수정하려면 WN 을 입력하세요(나가기 : exit) : ";
	cin >> repair;
	if (repair == "exit\n" || repair == "exit") return;

	if (repair == "BN")
	{
		cout << ">> 책 제목을 입력하세요 : ";
		cin >> book_name;

		cout << ">> 저자 이름을 입력하세요 : ";
		cin >> write_name;

		for (auto& entry : book_map)
		{
			if (entry.second.BookName == book_name && entry.second.WriterName == write_name)
			{
				cout << ">> 수정 할 '도서 제목' 을 입력하세요 : ";
				cin >> modify_name;
			}
			else
			{
				cout << "!유효하지않는 도서 및 저자. 재입력 바람." << endl;
				Repair();
				return;
			}

			if (entry.second.WriterName == write_name)
			{
				if (entry.second.BookName == modify_name)
				{
					cout << "!이미 존재하는 도서이므로 수정이 불가. 재입력 바람." << endl;
					Repair();
					return;
				}
				else
				{
					entry.second.BookName = modify_name;
					cout << "수정완료." << endl;
					return;
				}
			}
		}
	}
	else if (repair == "WN")
	{
		cout << ">> 책 제목을 입력하세요 : ";
		cin >> book_name;

		cout << ">> 저자 이름을 입력하세요 : ";
		cin >> write_name;

		for (auto& entry : book_map)
		{
			if (entry.second.BookName == book_name && entry.second.WriterName == write_name)
			{
				cout << ">> 수정 할 '저자 이름' 을 입력하세요 : ";
				cin >> modify_name;
			}
			else
			{
				cout << "!유효하지않는 도서 및 저자. 재입력 바람." << endl;
				Repair();
				return;
			}
			if (entry.second.BookName == book_name)
			{
				if (entry.second.WriterName == modify_name)
				{
					cout << "!이미 존재하는 도서이므로 수정이 불가. 재입력 바람." << endl;
					Repair();
					return;
				}
				else
				{
					entry.second.WriterName = modify_name;
					cout << "수정완료." << endl;
					return;
				}
			}
		}
	}
	else
	{
		cout << "!입력오류. 재입력 바람." << endl;
		Repair();
		return;
	}

}

// 6. 도서 삭제
void BookHandler::Drop()
{
	string BN_check, WN_check;

	cout << ">> 삭제 할 도서의 '책 제목' 을 입력하세요(나가기 : exit) : ";
	cin >> BN_check;
	if (BN_check == "exit\n" || BN_check == "exit") return;

	cout << ">> 삭제 할 도서의 '저자 이름' 을 입력하세요 : ";
	cin >> WN_check;

	for (auto& entry : book_map)
	{
		if (entry.second.BookName == BN_check && entry.second.WriterName == WN_check)
		{
			if (!book_map.erase(entry.first))
			{
				cout << "!삭제 실패" << endl;
				return;
			}
			else
			{
				cout << "삭제완료." << endl;
				return;
			}
		}
		else
		{
			cout << "!유효하지않는 도서 및 저자. 재입력 바람." << endl;
			Drop();
			return;
		}
	}
}

// 7. 모든 도서 정보 출력
void BookHandler::ShowBookInfo() const
{
	int cnt = 1;
	for (const auto& entry : book_map)
	{
		cout << "[" << cnt << "]" << endl;
		cout << "ㆍ책 제목 : " << entry.second.BookName << endl;
		cout << "ㆍ저자 이름 : " << entry.second.WriterName << endl;
		cout << "ㆍI S B N : " << entry.first << endl;
		if (entry.second.BookStatus)
		{
			cout << "ㆍ대여 상태 : 대여 중" << endl;
		}
		else
		{
			cout << "ㆍ대여 상태 : 대여 가능" << endl;
		}
		cout << "ㆍ장르 : ";
		switch (entry.second.type)
		{
		case 1:
			cout << "소설(1)" << endl;
			break;
		case 2:
			cout << "에세이(2)" << endl;
			break;
		case 3:
			cout << "IT & 모바일(3)" << endl;
			break;
		case 4:
			cout << "유아(4)" << endl;
			break;
		case 5:
			cout << "자기계발(5)" << endl;
			break;
		case 6:
			cout << "인문(6)" << endl;
			break;
		case 7:
			cout << "역사(7)" << endl;
			break;
		}
		cout << "ㆍ등록된 날짜 : " << entry.second.add_date << endl;
		cnt++;
	}
}


// 8. 저장하기
void BookHandler::Save()
{
	char save;

	string bookname = "ㆍ책 제목 : ";
	string writername = "ㆍ저자 이름 : ";
	string isbn = "ㆍI S B N : ";
	string type = "ㆍ책 장르(코드) : ";
	string date = "ㆍ등록 된 날짜 : ";
	string bookstatus = "ㆍ대여 상태 : ";
	string nn = "\n";

	cout << ">> 저장 하시겠습니까 ? (Y / N) : ";
	cin >> save;

	if (save == 'Y')
	{

		ofstream File;
		File.open("C:\\BookSearch\\book.txt");


		for (const auto& entry : book_map)
		{
			File << entry.second.BookName << endl;
			File << entry.second.WriterName << endl;
			File << entry.first << endl;
			File << entry.second.type << endl;
			File << entry.second.add_date << endl;
			File << entry.second.BookStatus << endl;
		}
		File.close();
		cout << "저장완료." << endl;
		return;
	}
	else if (save == 'N')
	{
		return;
	}
	cout << "!입력오류. 재입력 바람." << endl;
	Save();
	return;
}

// 9. 파일에서 도서정보 불러오기
void BookHandler::Call_save()
{
	string Isbn, line;
	ifstream file("C:\\BookSearch\\book.txt");

	if (!file.is_open()) {
		cerr << "Error opening file!" << endl;
		return;
	}

	while (getline(file, line))
	{
		if (line.empty()) continue;

		Book book;
		book.BookName = line;

		if (!getline(file, line)) break;
		book.WriterName = line;

		if (!getline(file, line)) break;
		Isbn = line;

		if (!getline(file, line)) break;
		book.type = stoi(line);

		if (!getline(file, line)) break;
		book.add_date = line;

		if (!getline(file, line)) break;
		book.BookStatus = stoi(line);

		auto result = book_map.insert({ Isbn, book });

		if (!result.second)
		{
			cout << "!insert 실패" << endl;
			Call_save();
			return;
		}
	}

	file.close();

	cout << "불러오기 완료." << endl;
	return;
}
