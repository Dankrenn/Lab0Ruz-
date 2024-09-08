#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_LEN 100  // ������������ ����� �������� ������
#define WIDTH 70  // ������ ������� ��� ��������������


// ������� ��� ��������������� ������ ������
void printCentered(const char* text) {
    int len = strlen(text);
    int padding = (WIDTH - len) / 2;

    printf("*");
    for (int i = 0; i < padding; i++) {
        printf(" ");
    }
    printf("%s", text);  // ����� ������
    for (int i = 0; i < WIDTH - len - padding; i++) {
        printf(" ");
    }
    printf("*\n");
}

// ������� ��� ������ ������, ������������ �� ������ ����
void printLeftAligned(const char* text) {
    printf("* %s", text);
    for (int i = strlen(text) + 2; i <= WIDTH; i++) {
        printf(" ");
    }
    printf("*\n");
}

// ������� ������� 1
void name() 
{
    const char* base_theme = "������������ ������:";
    const char* base_group = "������:";
    const char* base_study = "�������:";

    // ���������������� ������
    char user_theme[MAX_LEN];
    char user_group[MAX_LEN];
    char user_study[MAX_LEN];

    // ���� ������ �������������
    printf("������� ���� ������������ ������: ");
    fgets(user_theme, MAX_LEN, stdin);

    printf("������� ����� ������: ");
    fgets(user_group, MAX_LEN, stdin);

    printf("������� ��� ��������: ");
    fgets(user_study, MAX_LEN, stdin);

    // ������� ������ ����� ������ '\n'
    user_theme[strcspn(user_theme, "\n")] = 0;
    user_group[strcspn(user_group, "\n")] = 0;
    user_study[strcspn(user_study, "\n")] = 0;

    // �������� ������
    char final_theme[MAX_LEN + 50];
    char final_personal_data[MAX_LEN + 100];

    // ����������� �������� ������� �������� � ��������� ������� ������
    sprintf_s(final_theme, sizeof(final_theme), "%s %s", base_theme, user_theme);
    sprintf_s(final_personal_data, sizeof(final_personal_data), "%s %s, %s %s", base_group, user_group, base_study, user_study);

    // ����� ����������
    for (int i = 0; i < WIDTH + 2; i++) {
        printf("*");
    }
    printf("\n");

    printCentered(final_theme);
    printLeftAligned(final_personal_data);

    for (int i = 0; i < WIDTH + 2; i++) {
        printf("*");
    }
    printf("\n");

}

//������� ��������� ����� 
void printDigit(int digit, int row)
{
    switch (digit) {
    case 0:
        if (row == 0 || row == 3) printf(" _ ");
        else if (row == 1 || row == 2) printf("| |");
        break;
    case 1:
        if (row == 0) printf("   ");
        else if (row == 1 || row == 2) printf(" | ");
        else if (row == 3) printf("   ");
        break;
    case 2:
        if (row == 0) printf(" _ ");
        else if (row == 1) printf(" _|");
        else if (row == 2) printf("|_ ");
        else if (row == 3) printf("   ");
        break;
    case 3:
        if (row == 0) printf(" _ ");
        else if (row == 1) printf(" _|");
        else if (row == 2) printf(" _|");
        else if (row == 3) printf("   ");
        break;
    case 4:
        if (row == 0) printf("   ");
        else if (row == 1) printf("|_|");
        else if (row == 2) printf("  |");
        else if (row == 3) printf("   ");
        break;
    case 5:
        if (row == 0) printf(" _ ");
        else if (row == 1) printf("|_ ");
        else if (row == 2) printf(" _|");
        else if (row == 3) printf("   ");
        break;
    case 6:
        if (row == 0) printf(" _ ");
        else if (row == 1) printf("|_ ");
        else if (row == 2) printf("|_|");
        else if (row == 3) printf("   ");
        break;
    case 7:
        if (row == 0) printf(" _ ");
        else if (row == 1) printf("  |");
        else if (row == 2) printf("  |");
        else if (row == 3) printf("   ");
        break;
    case 8:
        if (row == 0) printf(" _ ");
        else if (row == 1) printf("|_|");
        else if (row == 2) printf("|_|");
        else if (row == 3) printf("   ");
        break;
    case 9:
        if (row == 0) printf(" _ ");
        else if (row == 1) printf("|_|");
        else if (row == 2) printf(" _|");
        else if (row == 3) printf("   ");
        break;
    }
}

//������� ��������� ���� ���������
void printIndex(int day, int month, int year) {
    // ��������� ����, ����� � ��� �� ������� � �������
    int day_digits[] = { day / 10, day % 10 };
    int month_digits[] = { month / 10, month % 10 };
    int year_digits[] = { (year / 10) % 10, year % 10 };

    // ������ ������ ��� ������ �����
    for (int row = 0; row < 3; row++) {
        // ����
        printDigit(day_digits[0], row);
        printDigit(day_digits[1], row);
        printf("  ");

        // �����
        printDigit(month_digits[0], row);
        printDigit(month_digits[1], row);
        printf("  ");

        // ���
        printDigit(year_digits[0], row);
        printDigit(year_digits[1], row);

        printf("\n");
    }
}

//������� ������� 2
void date() 
{
    int day;
    int month;
    int year;

    // ���� ������
    printf("������� ���� (1-31): ");
    scanf_s("%d", &day);

    printf("������� ����� (1-12): ");
    scanf_s("%d", &month);

    printf("������� ���: ");
    scanf_s("%d", &year);

    // �������� ������������ �����
    if (day < 1 || day > 31 || month < 1 || month > 12) {
        printf("������������ ����. ��������� ������������ ����� ��� � ������.\n");
        return;
    }
    printIndex(day, month, year);
}

void car() 
{
    printf("       ______\n");
    printf("      /|_||_\\`.__\n");
    printf("     (   _    _ _\\\n");
    printf("      `-(_)--(_)-'\n");
    printf("     (o)      (o)\n");
}

int main()
{
    setlocale(LC_ALL, "RUS");
    /*
        1. �������� ���������, ������� ������� ���� ������������ ������, � ���������� �� �� ����������� (������, �������).

        2. ���������� �������������� ���� ������ �� ������ �������, � ���������� �� ����������� � ����� � ����.

        3. �������� ����� ������ �� �������� -* ��� � ��� >.

    */
     name();

     getchar();

     /*
         ������� 3
         ��������� ���������, ������� ������� �����, ����� � ��������� ��� �����
         ���� �������� �� �������� ��������� ������� �� �������� � �������
         �������� \, |, _,/.
     */
    date();
    getchar();

     /*
     *   ���������� �������
     */
    car();
    getchar();
    return 0;
    

}




