#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <time.h>
#include <string.h>

void center(char* str);

struct point {
    float x;
    float y;
    char name;
};

typedef struct point Point;

void put_point(Point z) {
    printf("Точка %c (%.1f, %.1f)", z.name, z.x, z.y);
}

float dist(Point z, Point w) {
    return sqrt(pow(w.x - z.x, 2) + pow(w.y - z.y, 2));
}

Point middle(Point z, Point w) {
    Point m;
    m.x = (z.x + w.x) / 2;
    m.y = (z.y + w.y) / 2;
    m.name = 'M';
    return m;
}

int quarter(Point z) {
    if (z.x > 0 && z.y > 0)
        return 1;
    else if (z.x < 0 && z.y > 0)
        return 2;
    else if (z.x < 0 && z.y < 0)
        return 3;
    else if (z.x > 0 && z.y < 0)
        return 4;
    else
        return 0;
}

int task1() {
    setlocale(LC_ALL, "RUS");
    Point a, b, m;
    printf("Введите координаты точки A (x y): ");
    scanf("%f %f", &a.x, &a.y);
    a.name = 'A';
    printf("Введите координаты точки B (x y): ");
    scanf("%f %f", &b.x, &b.y);
    b.name = 'B';
    printf("\n");
    put_point(a);
    printf("\n");
    put_point(b);
    printf("\nРасстояние между точками: %.2f\n", dist(a, b));
    m = middle(a, b);
    printf("Середина отрезка: ");
    put_point(m);
    printf("\n");
    if (quarter(a) == 0)
        printf("Точка A лежит на оси координат или в начале координат.\n");
    else
        printf("Точка A находится в %d-й координатной четверти.\n", quarter(a));
    if (quarter(b) == 0)
        printf("Точка B лежит на оси координат или в начале координат.\n");
    else
        printf("Точка B находится в %d-й координатной четверти.\n", quarter(b));
    system("pause");
    return 0;
}









int task2() {
    setlocale(LC_ALL, "RUS");

    time_t t = time(NULL);
    struct tm* mytime = localtime(&t);
    struct tm now = *mytime;

    char str[200];
    char line[81];

    char* days[] = {
        "воскресенье", "понедельник", "вторник",
        "среда", "четверг", "пятница", "суббота"
    };

    char* months[] = {
        "января", "февраля", "марта", "апреля",
        "мая", "июня", "июля", "августа",
        "сентября", "октября", "ноября", "декабря"
    };

    char* roman[] = {
        "I", "II", "III", "IV", "V", "VI",
        "VII", "VIII", "IX", "X", "XI", "XII"
    };

    char* seasons[] = { "зимы", "весны", "лета", "осени" };

    int year = now.tm_year + 1900;
    int month = now.tm_mon;
    int day = now.tm_mday;
    int hour = now.tm_hour;
    int min = now.tm_min;
    int sec = now.tm_sec;

    int daysInMonth[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        daysInMonth[1] = 29;

    
    for (int i = 0; i < 10; i++)
        printf("********************************************************************************\n");

    
    sprintf(str, "Текущее время: %02d:%02d:%02d", hour, min, sec);
    center(str);

    
    sprintf(str, "День недели: %s", days[now.tm_wday]);
    center(str);

    
    sprintf(str, "Дата: %02d.%02d.%d", day, month + 1, year);
    center(str);

    
    sprintf(str, "Сегодня %d %s", day, months[month]);
    center(str);

    
    sprintf(str, "Сегодня %d-й день %d года", now.tm_yday + 1, year);
    center(str);

    
    int daysToSunday = (7 - now.tm_wday) % 7;
    int hoursToSunday = daysToSunday * 24 - hour;

    if (hoursToSunday < 0)
        hoursToSunday = 0;

    sprintf(str, "До воскресенья %d дней и %d часов",
        daysToSunday, hoursToSunday);
    center(str);

    
    int elapsed = hour * 60 + min - (8 * 60 + 30);

    if (elapsed < 0)
        elapsed = 0;

    sprintf(str, "С первой пары прошло %d часов %d минут",
        elapsed / 60, elapsed % 60);
    center(str);

    
    int monthsLeft = 11 - month;
    int daysLeft = daysInMonth[month] - day;

    sprintf(str, "До Нового года осталось %d месяцев и %d дней",
        monthsLeft, daysLeft);
    center(str);

    
    int currentTime = hour * 60 + min;
    int pairEnd = 0;

    if (currentTime >= 8 * 60 + 30 && currentTime < 10 * 60 + 5)
        pairEnd = 10 * 60 + 5;
    else if (currentTime >= 10 * 60 + 15 && currentTime < 11 * 60 + 50)
        pairEnd = 11 * 60 + 50;
    else if (currentTime >= 12 * 60 && currentTime < 13 * 60 + 35)
        pairEnd = 13 * 60 + 35;
    else if (currentTime >= 14 * 60 + 20 && currentTime < 15 * 60 + 55)
        pairEnd = 15 * 60 + 55;
    else if (currentTime >= 16 * 60 + 5 && currentTime < 17 * 60 + 40)
        pairEnd = 17 * 60 + 40;
    else if (currentTime >= 17 * 60 + 50 && currentTime < 19 * 60 + 25)
        pairEnd = 19 * 60 + 25;

    if (pairEnd != 0) {
        int remaining = (pairEnd - currentTime) * 60 - sec;
        sprintf(str, "До конца пары %d минут и %d секунд",
            remaining / 60, remaining % 60);
    }
    else {
        sprintf(str, "Сейчас занятий нет");
    }

    center(str);

    
    sprintf(str, "До конца месяца %d дней, до конца года %d месяцев",
        daysInMonth[month] - day, 11 - month);
    center(str);

    
    sprintf(str, "Месяц: %s, год: %d", roman[month], year);
    center(str);

    
    int season;

    if (month == 11 || month <= 1)
        season = 0;
    else if (month >= 2 && month <= 4)
        season = 1;
    else if (month >= 5 && month <= 7)
        season = 2;
    else
        season = 3;

    char* seasonNames[] = { "зима", "весна", "лето", "осень" };

    sprintf(str, "Время года: %s, год: %02d",
        seasonNames[season], year % 100);
    center(str);

    
    int seasonDay;

    if (season == 0) {
        if (month == 11)
            seasonDay = day;
        else if (month == 0)
            seasonDay = 31 + day;
        else
            seasonDay = 62 + day;
    }
    else if (season == 1) {
        seasonDay = day;
        for (int i = 2; i < month; i++)
            seasonDay += daysInMonth[i];
    }
    else if (season == 2) {
        seasonDay = day;
        for (int i = 5; i < month; i++)
            seasonDay += daysInMonth[i];
    }
    else {
        seasonDay = day;
        for (int i = 8; i < month; i++)
            seasonDay += daysInMonth[i];
    }

    sprintf(str, "Идет %d-й день %s", seasonDay, seasons[season]);
    center(str);

    
    for (int i = 0; i < 10; i++)
        printf("********************************************************************************\n");

    system("pause");
    return 0;
}

void center(char* str) {
    char line[81];

    int len = strlen(str);
    int left = (80 - len) / 2;
    int right = 80 - len - left;

    memset(line, '*', left);
    memcpy(line + left, str, len);
    memset(line + left + len, '*', right);
    line[80] = '\0';

    printf("%s\n", line);
}



int main()
{
    task2();
}
