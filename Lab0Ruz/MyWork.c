#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_LEN 100  // Максимальная длина введённой строки
#define WIDTH 70  // Ширина консоли для форматирования


// Функция для центрированного вывода текста
void printCentered(const char* text) {
    int len = strlen(text);
    int padding = (WIDTH - len) / 2;

    printf("*");
    for (int i = 0; i < padding; i++) {
        printf(" ");
    }
    printf("%s", text);  // Вывод текста
    for (int i = 0; i < WIDTH - len - padding; i++) {
        printf(" ");
    }
    printf("*\n");
}

// Функция для вывода текста, выровненного по левому краю
void printLeftAligned(const char* text) {
    printf("* %s", text);
    for (int i = strlen(text) + 2; i <= WIDTH; i++) {
        printf(" ");
    }
    printf("*\n");
}

// Функция задание 1
void name() 
{
    const char* base_theme = "Лабораторная работа:";
    const char* base_group = "Группа:";
    const char* base_study = "Студент:";

    // Пользовательские данные
    char user_theme[MAX_LEN];
    char user_group[MAX_LEN];
    char user_study[MAX_LEN];

    // Ввод данных пользователем
    printf("Введите тему лабораторной работы: ");
    fgets(user_theme, MAX_LEN, stdin);

    printf("Введите номер группы: ");
    fgets(user_group, MAX_LEN, stdin);

    printf("Введите имя студента: ");
    fgets(user_study, MAX_LEN, stdin);

    // Убираем символ новой строки '\n'
    user_theme[strcspn(user_theme, "\n")] = 0;
    user_group[strcspn(user_group, "\n")] = 0;
    user_study[strcspn(user_study, "\n")] = 0;

    // Итоговые строки
    char final_theme[MAX_LEN + 50];
    char final_personal_data[MAX_LEN + 100];

    // Присваиваем итоговым строкам значения с указанием размера буфера
    sprintf_s(final_theme, sizeof(final_theme), "%s %s", base_theme, user_theme);
    sprintf_s(final_personal_data, sizeof(final_personal_data), "%s %s, %s %s", base_group, user_group, base_study, user_study);

    // Вывод информации
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

//Функция отрисовки числа 
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

//Функция отрисовки всех элементов
void printIndex(int day, int month, int year) {
    // Разделяем день, месяц и год на десятки и единицы
    int day_digits[] = { day / 10, day % 10 };
    int month_digits[] = { month / 10, month % 10 };
    int year_digits[] = { (year / 10) % 10, year % 10 };

    // Рисуем строки для каждой цифры
    for (int row = 0; row < 3; row++) {
        // День
        printDigit(day_digits[0], row);
        printDigit(day_digits[1], row);
        printf("  ");

        // Месяц
        printDigit(month_digits[0], row);
        printDigit(month_digits[1], row);
        printf("  ");

        // Год
        printDigit(year_digits[0], row);
        printDigit(year_digits[1], row);

        printf("\n");
    }
}

//Функция задание 2
void date() 
{
    int day;
    int month;
    int year;

    // Ввод данных
    printf("Введите день (1-31): ");
    scanf_s("%d", &day);

    printf("Введите месяц (1-12): ");
    scanf_s("%d", &month);

    printf("Введите год: ");
    scanf_s("%d", &year);

    // Проверка корректности ввода
    if (day < 1 || day > 31 || month < 1 || month > 12) {
        printf("Некорректный ввод. Проверьте правильность ввода дня и месяца.\n");
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
        1. Напишите программу, которая выводит тему лабораторной работы, и информацию об ее исполнителе (группа, студент).

        2. Реализуйте форматирование темы работы по центру консоли, а информации об исполнителе – слева к краю.

        3. Окружите текст рамкой из символов -* или – или >.

    */
     name();

     getchar();

     /*
         Задание 3
         Составьте программу, которая выводит число, месяц и последние две цифры
         года рождения по принципу написания индекса на конверте с помощью
         символов \, |, _,/.
     */
    date();
    getchar();

     /*
     *   нарисовать машинку
     */
    car();
    getchar();
    return 0;
    

}




