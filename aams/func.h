#ifndef AAMS_FUNC_H
#define AAMS_FUNC_H

#endif //AAMS_FUNC_H


void menu_aams();
bool ConnectMysql( const string & username, const string & password);
bool mysql_login(string username,string password);
void secgetpasseord(std::string& password);
int getwhichmenu(string username);
void menu_aams_display_1();
void menu_aams_display_2();
void menu_aams_display_3();
void menu_root(const string& username);
void menu_student(const string& username);
void menu_teacher(const string& username);
int usermessget();
void getstruct(int num);