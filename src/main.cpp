#include <iostream>
#include <fstream>
#include <vector>
#include "Subject.h"

#define tendl "\n\n"
#define endl '\n'
#define edge std::cout << "----------------------\n";
#define NAME "NAME"
#define CLASS "CLASS"
#define ID "MASINHVIEN"
#define DATA "D:\\Code\\tools\\QuanLiMonHoc\\data\\data.txt"

std::vector<std::string> infoSub;
std::vector<Subject> Subj;
std::vector<std::string> Choices;

void listInfoSubject ();
void listOptionSubject ();
void listSubj ();
void initList ();
void listChoices ();
void inputInfoSubject ();
void handleOption ();
void inputDataFromTerminal ();
void loadData ();
void writeData();
void clearData();

void solve ();

// Load Data

void loadData ()
{
				std::cout << "Loading data...\n";
				std::ifstream inputFile(DATA);
				if ( inputFile.is_open() )
				{
								Subject tmp;
								int i = 1;
								std::string line;
								while ( std::getline(inputFile, line) )
								{
												if ( i == 1 ) tmp.chngName(line);
												else if ( i == 2 ) tmp.chngCredits(stoi(line));
												else if ( i == 3 ) tmp.chngSemester(stoi(line));
												else if ( i == 4 ) tmp.chngPoint(stod(line));
												else{
													Subject lf;
													tmp.chngPoint4(line);
																Subj.push_back(tmp);
																tmp = lf;
																i = 0;
												}
												++i;
								}
								std::cout << "Done!\n";
								inputFile.close();
				} else std::cerr << "not exit" << endl;
}

void writeData ()
{
				std::ofstream outputFile(DATA);
				if ( outputFile.is_open() )
				{
								for (int i = 0; i < Subj.size(); ++i)
								{
												Subject tmp = Subj[i];
												outputFile << tmp.getName() << endl;
												outputFile << tmp.getCredits() << endl;
												outputFile << tmp.getSemester() << endl;
												outputFile << tmp.getPoint() << endl;
												outputFile << tmp.getPoint4() << endl;
								}
								outputFile.close();
				}
}

void clearData ()
{
				std::ofstream outputFile(DATA);
				std::cout << tendl;
				if ( outputFile.is_open() )
				{
								outputFile << "";
								Subj.clear();
								std::cout << "Da Xoa Het Du Lieu!\n";
				}else std::cerr << "cant open file\n";
				std::cout << tendl;
}

// Load Data


// Begin list Subject

void listSubject ()
{
				for ( int i = 0; i < Subj.size(); ++i )
				{
								std::cout << i + 1 << ": " << Subj[i].getName() << endl;
				}
}

// End list Subject

// Begin List 

void initList ()
{
				infoSub.emplace_back("Ten Mon");
				infoSub.emplace_back("Tin Chi Mon");
				infoSub.emplace_back("Hoc Ki Cua Mon");
				infoSub.emplace_back("Diem So");

				Choices.emplace_back("Nhap Mon Hoc Moi");
				Choices.emplace_back("Chinh Sua Mon Hoc");
				Choices.emplace_back("Hien Thi Tat Ca Mon Hoc");
				Choices.emplace_back("Hien Thi Thong Tin Mon Hoc");
				Choices.emplace_back("Xoa Het Tat Ca Du Lieu Mon Hoc");
				Choices.emplace_back("Exit Va Luu Du Lieu");
}

void listChoices ()
{
				for ( int i = 0; i < Choices.size(); ++i )
				{
								std::cout << i + 1 << ": " << Choices[i] << endl;
				}
				edge
				std::cout << "Nhap Lua Chon Cua Ban: ";
}

void listOptionSubject ()
{
				for ( int i = 0; i < infoSub.size(); ++i )
				{
								std::cout << i << ": " << infoSub[i] << endl;
				}
}
// End List

// Support Funtion

void listInfoStudent ()
{
				std::cout << "-----" << NAME << "-----\n";
				std::cout << "Class: " << CLASS << endl;
				std::cout << "ID: " << ID << endl;
				std::cout << "-\n-\n-\n-\n----------\n";
}

void handleChangeInforSubject ( int ind, int op, const std::string& newValue )
{
				int check = 0;
				for (char i : newValue)
								if ( isalpha (i) )
								{
												check = 1; break;
								}
				if ( check == 1 && op != 0 ) return std::cout << "Du Lieu Khong Hop Le!\n", void();
				if ( check == 0 && op == 0 ) return std::cout << "Du Lieu Khong Hop Le!\n", void();
				switch ( op ){
				case 0:
								Subj[ind].chngName(newValue);
								break;
				case 1:
								Subj[ind].chngCredits(stoi(newValue));
								break;
				case 2:
								Subj[ind].chngSemester(stoi(newValue));
								break;
				case 3:
								Subj[ind].chngPoint(stod(newValue));
								break;
				default:
								std::cout << "Du Lieu Khong Hop Le!\n";
				}
}


void infoSubject ( int ind )
{
				std::cout << "Ten Mon Hoc: " << Subj[ind].getName() << endl;
				std::cout << "Tin Chi Cua Mon Hoc: " << Subj[ind].getCredits() << endl;
				std::cout << "Hoc Ky Mon Hoc: " << Subj[ind].getSemester() << endl;
				std::cout << "Diem So Cua Mon Hoc: " << Subj[ind].getPoint() << endl;
				std::cout << "Diem So Thang Bon Cua Mon Hoc: " << Subj[ind].getPoint4() << endl;
}

// Support Funtion

// Begin Options

void changeInfoSubject ()
{
				int ind;
				listSubject ();
				std::cout << tendl;
				std::cout << "Nhap Mon Hoc Cua Ban: "; std::cin >> ind;
				--ind;
				listOptionSubject ();
				int op;
				std::cout << "Nhap Lua Chon Ma Ban Muon Sua Doi: "; std::cin >> op;
				std::cout << "Nhap Gia Tri Muon Sua Doi: ";
				std::cin.ignore();
				std::string newValue; std::getline(std::cin, newValue);
				handleChangeInforSubject ( ind, op, newValue );
				std::cout << "Thay Doi Du Lieu Thanh Cong!!!\n";
				std::cout << tendl;
				edge
}

void inputInfoSubject ()
{
				std::string name;
				int cre, sem;
				std::cin.ignore();
				std::cout << tendl;
				std::cout << "Nhap ten mon hoc: "; std::getline(std::cin, name);
				Subject tmp(name);
				std::cout << "Nhap so tin chi cua mon hoc: "; std::cin >> cre;
				std::cout << "Nhap hoc ki cua mon hoc(Vui long nhap bang so): "; std::cin >> sem;
				const int ind = Subj.size() - 1;
				tmp.chngCredits(cre); tmp.chngSemester(sem);
				Subj.push_back(tmp);
				std::cout << "Nhap Du Lieu Thanh Cong!!!\n";
				std::cout << tendl;
				edge
}

void listInfoSubjects ()
{
				int ind;
				std::cout << tendl;
				listSubject ();
				std::cout << "Nhap Mon Hoc Ban Muon Xem: "; std::cin >> ind;
				--ind;
				std::cout << "---" << Subj[ind].getName() << "---\n";
				infoSubject(ind);
				std::cout << tendl;
				edge
}

// End Options

// Begin Init Data

void handleOption ( char ind )
{
				if ( ind == 0 ) return inputInfoSubject (), void ();
				if ( ind == 1 ) return changeInfoSubject (), void ();
				if ( ind == 2 )
				{
								std::cout << tendl;
								listSubject ();
								std::cout << "Da Hien Thi Het Mon Hoc!\n";
								std::cout << tendl;
								edge
								return;
				}
				if ( ind == 3 ) return listInfoSubjects (), void ();
				if ( ind == 4 ) return clearData (), void();
}

void inputDataFromTerminal ()
{
				std::string option;
				listChoices();
				while ( std::cin >> option )
				{
								const int c = stoi(option) - 1;
								if ( c == Choices.size() - 1 ){
												return;
								}
								handleOption(c);
								listChoices();
				}
}

// End Init Data


void solve ()
{
				loadData();
				listInfoStudent();
				initList();
				inputDataFromTerminal();
				writeData();
}

int main() {
				solve();
				return 0;
}
