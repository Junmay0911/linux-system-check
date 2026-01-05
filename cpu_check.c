#include <stdio.h>
#include <string.h>

// 카페 키오스크 프로그램 
// id,pw 입력창 (8자 이상 , 영어 대소문자만 구분)
// 메뉴 출력
// 음료수 선택
// 장바구니
// 결재 

void id_pw(void) {
char id[20];
char pw[20];
char *p = pw;
int is_pw = 1;

printf("아이디 입력 : \n");
scanf("%s",id);

printf("비밀번호 입력 : \n");
scanf("%s" , pw);

if (strlen(pw) > 8) {printf("비밀번호확인\n");}

while (*p != '\0' ) {
if (*p >= 'A' && *p <= 'Z') {is_pw = 0; break;}
p++;
}
if (is_pw == 0) {printf("로그인 성공\n")};
else {printf("비밀번호 재확인\n");}
}

void menu_print(void) {
char menu1[] = "아메리카노";
char menu2[] = "카페라떼";
char menu3[] = "카푸치노";
char menu4[] = "바닐라 라떼";
char menu5[] = "아이스티";
}


int main(void) {

while (1) {
id_pw();
break;
}
