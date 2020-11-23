<p align="center">МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ<br>
Федеральное государственное автономное образовательное учреждение высшего образования<br>
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"<br>
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ<br>
Кафедра компьютерной инженерии и моделирования</p>
<br>
<h3 align="center">Отчёт по лабораторной работе № 1<br> по дисциплине "Программирование"</h3>
<br><br>
<p>студента 1 курса группы ПИ-б-о-203(1)<br>
Павленко Степана Владимировича<br>
направления подготовки 09.03.04 "Программная инженерия"</p>
<br><br>
<table>
<tr><td>Научный руководитель<br> старший преподаватель кафедры<br> компьютерной инженерии и моделирования</td>
<td>(оценка)</td>
<td>Чабанов В.В.</td>
</tr>
</table>
<br><br>
<p align="center">Симферополь, 2020</p>
<hr>

<!-- ![](./image/pic1.png) -->
## Цель:

1. Закрепить навыки разработки многофайловыx приложений;
2. Изучить способы работы с API web-сервиса;
3. Изучить процесс сериализации/десериализации данных в/из json;
4. Получить базовое представление о сетевом взаимодействии приложений;

## Постановка задачи
Разработать сервис предоставляющий данные о погоде в городе Симферополе на момент запроса. В качестве источника данных о погоде использовать: http://openweathermap.org/. В состав сервиса входит: серверное приложение на языке С++ и клиентское приложение на языке Python.
Серверное приложение (далее Сервер) предназначенное для обслуживания клиентских приложений и минимизации количества запросов к сервису openweathermap.org. Сервер должен обеспечивать возможность получения данных в формате JSON и виде html виджета (для вставки виджета на страницу будет использоваться iframe).
Клиентское приложение должно иметь графический интерфейс отображающий сведения о погоде и возможность обновления данных по требованию пользователя.

## Выполнение работы
<!--
    API key полученный на сервисе openweathermap.org;
    Запрос составленный в пункте I.7;
    Запрос составленный в пункте II;
    Полный исходный код серверного приложения;
    Полный исходный код клиентского приложения;
    Скриншот графического интерфейса клиентского приложения. Только окно программы, лишнее обрезать;
    Скриншот браузера с загруженными виджетом.
-->
Для начала был зарегистрирован аккаунт openwheatermap.org. API ключ по-умолчанию созданный сервисом: 4b4b143c5f50ea5d5810563a8346acc0.

Затем были произведены несколько тестовых запросов, чтобы убедиться, что они не имеют ошибок и вывод правилен.

Запрос, созданный к серверу погоды включает в себя широту и долготу места, для которого необходимо получить погоду, исключить все типы прогноза кроме почасового, ключ API, метрические единицы изменения (цельсий) и описание на русском языке: 
api.openweathermap.org/data/2.5/forecast?id=693805&appid=bf97b147726cfd116b9077cfa82459b5&units=metric&lang=ru

Запрос для сервера погоды включает в себя город, время которого необходимо получить:

http://worldtimeapi.org/api/timezone/Europe/Simferopol

Исходный код сервера:
#include <iostream>
#include <iomanip>
#include "include/cpp_httplib/httplib.h"
#include <string>
#include <fstream>
#include <ctime>
#include "include/nlohmann/json.hpp"
#include "include/Loginer.hpp"

using namespace httplib;
using json = nlohmann::json;
using namespace std;

// В этой функции формируем ответ сервера на запрос
void gen_response(const Request& req, Response& res2) {
    // Создаём клиент и привязываем к домену. Туда пойдут наши запросы
    Client cli("http://worldtimeapi.org");
    // Отправляем get-запрос и ждём ответ, который сохраняется в переменной res
    auto res = cli.Get("/api/timezone/Europe/Simferopol");
    // res преобразуется в true, если запрос-ответ прошли без ошибок
    if (res) {
        // Проверяем статус ответа, т.к. может быть 404 и другие
        if (res->status == 200) {
            // В res->body лежит string с ответом сервера
            cout << res->body << endl;
        }
        else {
            cout << "Status code: " << res->status << endl;
        }
    }
    else {
        auto err = res.error();
        cout << "Error code: " << err << endl;
    }
    // Создаём клиент и привязываем к домену. Туда пойдут наши запросы
    Client clin("http://api.openweathermap.org");
    // Отправляем get-запрос и ждём ответ, который сохраняется в переменной wea
    auto wea = clin.Get("/data/2.5/onecall?lat=44.952116&lon=34.102411&exclude=minutly,hourly,alerts,daily&appid=4b4b143c5f50ea5d5810563a8346acc0&lang=eng&units=metric");
    // wea преобразуется в true, если запрос-ответ прошли без ошибок
    if (wea) {
        // Проверяем статус ответа, т.к. может быть 404 и другие
        if (wea->status == 200) {
            // В wea->body лежит string с ответом сервера
            cout << wea->body << endl;
        }
        else {
            cout << "Status code: " << wea->status << endl;
        }
    }
    else {
        auto err2 = wea.error();
        cout << "Error code: " << err2 << endl;
    }

    json j = json::parse(res->body);
    // Достаём значение времени
    string time = j["datetime"];
    cout << "Время " << time << endl;


    json j2 = json::parse(wea->body);
    // Достаём значения погодных условий
    int temperatura = j2["current"]["temp"];
    string pogoda = j2["current"]["weather"][0]["description"].get<string>();

    json j3 = temperatura;
    json j4 = pogoda;
    res2.set_content(j3, "text/json; charset=UTF-8");
    res2.set_content(j4, "text/json; charset=UTF-8");

    string strina;
    ifstream file2("fole.html"); // Файловая переменная
    if (file2.is_open())
    {
        getline(file2, strina, '\0');
        file2.close();
    }
    else
    {
        res2.set_content("Error! Could not open `template.html` file.", "text/plain;charset=utf-8");
        return;
    }

    size_t found = strina.find("hourly[i]");
    strina.replace(1,2, strina);
;
    
}
void gen_response_raw(const Request& req, Response& res2) {
   

    Client cli("http://worldtimeapi.org");
    auto res = cli.Get("/api/timezone/Europe/Simferopol");
    if (res) {
        if (res->status == 200) {
            cout << res->body << endl;
        }
        else {
            cout << "Status code: " << res->status << endl;
        }
    }
    else {
        auto err = res.error();
        cout << "Error code: " << err << endl;
    }
    Client clin("http://api.openweathermap.org");
    auto wea = clin.Get("/data/2.5/onecall?lat=44.952116&lon=34.102411&exclude=minutly,hourly,alerts,daily&appid=4b4b143c5f50ea5d5810563a8346acc0&lang=eng&units=metric");
    if (wea) {
        if (wea->status == 200) {
            cout << wea->body << endl;
        }
        else {
            cout << "Status code: " << wea->status << endl;
        }
    }
    else {
        auto err2 = wea.error();
        cout << "Error code: " << err2 << endl;
    }

    json j = json::parse(res->body);
    string time = j["datetime"];
    cout << "Время " << time << endl;


    json j2 = json::parse(wea->body);
    int temperatura = j2["current"]["temp"];
    string pogoda = j2["current"]["weather"][0]["description"].get<string>();
    res2.set_content(j2.dump(), "text/json; charset=UTF-8");

}

int main() {
    Server svr;                    // Создаём сервер (пока-что не запущен)     
    svr.Get("/", gen_response);    // Вызвать функцию gen_response если кто-то обратиться к корню "сайта"     
    std::cout << "Start server... OK\n";     
    svr.listen("localhost", 3000);   
}         
```