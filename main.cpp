#include <iostream>
#include <string>
#include <cmath>
#include <tuple>
#include <cstdlib>
#include <ctime>


int score_of_done_tasks = 0;


/**
 Функция оптимизирует ввод чисел пользователем
 
 @param prompt промпт для вывода в консоль (подсказка для пользователя)
 @return возращает число с плавующей точкой (которе ввёл пользователь)
  */
float inputFloat(std::string prompt) {
    float inputted_num = 0.0;
    std::cout << prompt;
    std::cin >> inputted_num;
    return inputted_num;
}


/**
 Функция оптимизирует ввод строк пользователем
 
 @param prompt промпт для вывода в консоль (подсказка для пользователя)
 @return возращает строчку (которую ввёл пользователь)
  */
std::string inputString(std::string prompt) {
    std::string inputted_str = "";
    std::cout << prompt;
    std::cin >> inputted_str;
    return inputted_str;
}


/**
 Функция разделения номеров заданий для main()
 Также она может прервать процесс, если пользователь устал
 */
void goNext() {
    score_of_done_tasks += 1;
    std::string user_decision;
    
    std::cout << "\nTask №" << score_of_done_tasks << " is done, let's start №" << score_of_done_tasks+1 << "?" << std::endl;
    std::cout << "press ENTER to continue or 'stop' to break process: ";
    std::getline(std::cin, user_decision);
    std::getline(std::cin, user_decision);
    
    if (user_decision == "stop") {
        std::cout << "Really? Ok, let's finish, I don't want to see you for now...\n";
        exit(0);
    }
    
    std::cout << "\n\n";
}


/**
 Подсчёт площади трапеции по формуле:
 ((base_1 + base_2) / 2) x high
  
 @param b1 первое основание
 @param b2 второе основание
 @param h высота
 @return площадь вашей трапеции
  */
float getTrapezoidSquare(float b1, float b2, float h) {
    return ((b1 + b2) / 2) * h;
}


struct Circle{  // Структура круга
    float radius;  // Радиус
    float diametr;  // Диаметр
    float lengh;  // Длина окружности
    float area;  // Площадь круга
};

/**
 Создаёт круг
 
 @param radius радиус окружности
 @return круг с членами: радиус, диаметр, длина, площадь
 */
Circle initCircle(float radius) {
    float diam = radius*2;
    float sqr = (3.14/2) * (diam * diam);
    float len = 2 * 3.14 * radius;
    
    Circle result = {radius, diam, len, sqr};
    
    return result;
}


/**
 Вычисляет площадь прямоугольного треугольника
 
 @param a первый катет тругольника
 @param b второй катет трегольника
 @return площадь трегольника
 */
float getSquareOfRightTriangle(float a, float b) {
    return (a * b) / 2;
}


/**
 Вычисляет гипотенузу прямоугольного треугольника
 
 @param a первый катет тругольника
 @param b второй катет трегольника
 @return длинуа гипотенузы
 */
float getHypotenuseOfRightTriangle(float a, float b) {
    return sqrt((a * a) + (b * b));
}


/**
 Сумирует члены (цифры)  десятичного четырёхзначного число
 
 @param num число которое нужно просумировать
 */
int getSumOfFourNum(float num) {
    int four = num / 1000;
    int three = int((num / 100)) % 10;
    int two = int((num / 10)) % 10;
    int one = int(num) % 10;
    
    return four + three + two + one;
}


/**
 Переводит декартову систему в полярную
 
 @param c_x 'x' в декартовой ситстеме
 @param c_y 'y' в декартовой ситстеме
 @return пара, где 1 значение - 'x' в полярной системе, 2 - 'y' в полярной системе
 */
std::tuple<float, float> decart2polar(float c_x, float c_y) {
    return {sqrt(c_x * c_x + c_y * c_y), atan2(c_y, c_x)};
}


/**
 Переводит полярную систему в декартову
 
 @param p_x 'x' в полярной системе
 @param p_y 'y' в полярной системе
 @return пара, где 1 значение - 'x' в декартовой системе, 2 - 'y' в декартовой системе
 */
std::tuple<float, float> polar2decart(float p_x, float p_y) {
    return {(p_x * cos(p_y)), (p_x * sin(p_y))};
}



/**
 Вычисляет корни квадратного уравнения
 
 @param a число a (стоит перд 'x')
 @param b число b (стоит перед 'x^2')
 @param c число стоящее в конце уравнения
 @return корни уравнения (если возращает 0.0 и 0.0 - чего быть не может - значит дискриминант меньше нуля)
 */
std::tuple<float, float> getAnswerToSqrTask(float a, float b, float c) {
    float d = (b * b) - (4 * a * c);
    if (d < 0) {
        return {0.0, 0.0};
    }
    
    float sqrt_d = sqrt(d);
    if (sqrt_d == 0) {
        float x = (-1 * b) / (2 * a);
        return {x, x};
    } else {
        float x1 = ((-1 * b) + sqrt_d) / (2 * a);
        float x2 = ((-1 * b) - sqrt_d) / (2 * a);
        return {x1, x2};
    }
}


struct Triangle{  // структура тругольника (стороны + медианы)
    float a;  // сторона A
    float b;  // сторона B
    float c;  // сторона C
    float m2a;  // медиана к стороне A
    float m2b;  // медиана к стороне B
    float m2c;  // медиана к стороне C
};


/**
 'приватный метод' - не используется в main()
 вычисляет медиану в трегольнике
 
 @param a сторона, к кторой опущена медиана
 @param b другая сторона
 @param c другая сторона
 @return медиана, опущенная к стороне 'a'
 */
float __getMediana__(float a, float b, float c) {
    float under_sqrt = (2 * (b * b)) + (2 * (c * c)) - (a * a);
    return sqrt(under_sqrt)/2;
}
/**
 Создаёт трегольник (стороны + медианы) по трём полученным сторонам
 
 @param a сторона трегольника
 @param b сторона трегольника
 @param c сторона трегольника
 @return структура трегольника
 */
Triangle initTriangle(float a, float b, float c) {
    Triangle result;
    result.a = a;
    result.b = b;
    result.c = c;
    result.m2a = __getMediana__(a, b, c);
    result.m2b = __getMediana__(b, a, c);
    result.m2c = __getMediana__(c, b, a);
    return result;
}


/**
 Конвертирует количество секунд, которые прошли после начала суток в часы + минуты
 
 @param sec число секунд после 00:00
 @return время из секунд по формату ЧЧ:ММ
 */
std::string convertSec2TimeThatSpendedAfterZero(int sec) {
    int hours = sec / 3600;
    int minutes = (sec % 3600) / 60;
    std::string result = "";
    
    if (std::to_string(hours).length() == 1) {
        result += "0";
    }
    result += std::to_string(hours) + ":";
    
    if (std::to_string(minutes).length() == 1) {
        result += "0";
    }
    result += std::to_string(minutes);
    
    return result;
}


/**
 Определяет является ли треугольник равнобедренным
 
 @param triangle структура тругольника
 @return true или false
 */
bool isTriangleIsosceles(Triangle triangle) {
    return triangle.a == triangle.b && triangle.b == triangle.c;
}


/**
 Отнимает из числа процент
 
 @param num число, из которого нужно отнять процент
 @param percents процент (от 0 до 100), который нужно отнять от числа
 @return итогове число из которого вычли процент
 */
float numMinusPercents(float num, int percents) {
    float num2minus = (num / 100) * percents;
    return num - num2minus;
}


/**
 Вычисляет 'идеальный' вес человека
 
 @param hight рост человека
 @return 'идеальный' вес человека по формуле: рост - 100
 */
float getIdealWeight(float hight) {
    return hight - 100;
}


/**
 Возращает рандомную цифру  (честно - не очень понимаю как это работает, взял реализацию с интернета)
 
 @return цифра, псевдослучайная
 */
int getRundumNum() {
    std::srand(std::time(nullptr));
    int random_result = 11;
    while (random_result > 10) {
        random_result = 1 + std::rand() / ((RAND_MAX + 1u) / 6);
    }
    return random_result;
}


/**
 Считает стоимость переговоров
 
 @param len длина переговоров (в часах)
 @param day день недели для переговоров (0, 7)
 @param price_per_hour цена за час переговоров
 @return усмноженная длина переговоров на цену за час (если выходные, то скидка 20%)
 */
float getPriceOfSpeking(float len, int day, int price_per_hour) {
    float result = len * price_per_hour;
    if (day == 6 || day == 7) {
        result = numMinusPercents(result, 20);
    }
    return result;
}


/**
 Преобразует число в параметры месяца
 
 @param num число, по которому я ищу месяц
 @return пару, стостоящую из порядкового номера, названия месяца, времени года
 */
std::tuple<int, std::string, std::string> getMonthsParams(int num) {
    std::tuple<int, std::string, std::string> month[12] = {
        {12, "January", "Winter"}, {1, "January", "Winter"}, {2, "February", "Winter"},
        {3, "March", "Spring"}, {4, "April", "Spring"}, {5, "May", "Spring"},
        {6, "June", "Summer"}, {7, "July", "Summer"}, {8, "August", "Summer"},
        {9, "September", "Autumn"}, {10, "October", "Autumn"}, {11, "November", "Autumn"}
    };
    
    for (std::tuple values : month){
        if (std::get<0>(values) == num) {
            return values;
        }
    }
    
    return {num, "None", "None"};
}


/**
 Узнаёт, являеется ли шестизначеное число счастливым
 
 @param num шестизначное число
 @return true или false (зависит от сумма первых трёх числе равна вторым)
 */
bool isSixNumLucky(int num) {
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < 6; i++) {
        if (i < 3) {
            sum1 += num % 10;
            num /= 10;
        } else {
            sum2 += num % 10;
            num /= 10;
        }
    }
    
    return sum1 == sum2;
}


/**
 Возращает верное написание слова 'копейка' с числом
 
 @param num число от 1 до 99
 @return формат копейки
 */
std::string getRightKopeikaWord(int num) {
    if (num == 11 || num == 12 || num == 13 || num == 14) {
        return "копеек";
    }
    if (num % 10 >= 2 && num % 10 <= 4) {
        return "копейки";
    }
    if (num % 10 >= 5 && num % 10 <= 9) {
        return "копеек";
    }
    return "копейка";
}


/**
 Проверяет явялется ли четырёхзначное число полиндромом
 
 @param num число для проверки
 @return true или false (завист от того, можно ли прочитать его справа на лево и с лева на право одинаково)
 */
bool isFourNumPolindrom(int num) {
    std::string str_num = std::to_string(num);
    
    for (int i = 0; i < str_num.length() / 2; i++) {
        if (str_num[i] != str_num[str_num.length() - 1 - i]) {
            return false;
        }
    }
    
    return true;
}

/**
 Возращает сумму цифр из которых состоит трёхзначное число
 
 @param num трёхзначное число для работы
 @return пару из произведения и суммы цифр
 */
std::tuple<int, int> getParamsOfThreeCountNum(int num) {
    int piece1 = num / 100;
    int piece2 = (num / 10) % 10;
    int piece3 = num % 10;
    return {(piece1 * piece2 * piece3), (piece1 + piece2 + piece3)};
}


int main(int argc, const char * argv[]) {
    std::cout << "Please, write norm numbers, because program dosn't have checks for human...\n\n";
    
    /* Task1 */
    float base1_for_trapezoid = inputFloat("Put first base for trapezoid: ");
    float base2_for_trapezoid = inputFloat("Put second base for trapezoid: ");
    float high_for_trapezoid = inputFloat("Put high for trapezoid: ");
    std::cout << "\nI think, that " << getTrapezoidSquare(base1_for_trapezoid, base2_for_trapezoid, high_for_trapezoid) << " is square of your trapezoid\n";
    
    goNext();
    
    /* Task2 */
    Circle user_circle = initCircle(inputFloat("Put radius and I`l init circle: "));
    std::cout << "Your circle params:\nsquare = " << user_circle.area << "\nlengh = " << user_circle.lengh << std::endl;
    
    goNext();
    
    float katet1_right_triangle = inputFloat("Put first katet for triangle that has 90' angle: ");
    float katet2_right_triangle = inputFloat("Put second katet for triangle that has 90' angle: ");
    std::cout << "So, square of this triagle = " << getSquareOfRightTriangle(katet1_right_triangle, katet2_right_triangle);
    std::cout << " and hypotenuse is " << getHypotenuseOfRightTriangle(katet1_right_triangle, katet2_right_triangle) << std::endl;
    
    goNext();
    
    /* Task4 */
    float num_4digit_for_sum = inputFloat("Put four-diget number and I'l return sum: ");
    std::cout << "So easy for me and sum is " << getSumOfFourNum(num_4digit_for_sum) << std::endl;
    
    goNext();
    
    /* Task5 */
    float decart_x = inputFloat("Write 'x' value in decart system: ");
    float decart_y = inputFloat("Write 'y' value in decart system: ");
    std::tuple<float, float> pair_of_polar_coord = decart2polar(decart_x, decart_y);
    std::cout << "Inputted coords in polar system: (" << std::get<0>(pair_of_polar_coord) << ", " << std::get<1>(pair_of_polar_coord) << ")\n";
    
    goNext();
    
    /* Task6 */
    float polar_x = inputFloat("Write 'x' value in polar system: ");
    float polar_y = inputFloat("Write 'y' value in polar system: ");
    std::tuple<float, float> pair_of_decard_coord = polar2decart(polar_x, polar_y);
    std::cout << "Inputted coords in decard system: (" << std::get<0>(pair_of_decard_coord) << ", " << std::get<1>(pair_of_decard_coord) << ")\n";
    
    goNext();
    
    /* Task7 */
    std::string str_q_task = "";
    
    float before_x2_q_task = inputFloat("Put value that stay before 'x^2' in quadratic equation (YOUR_VALUE * x^2 +- ... * x^2 +- ...): ");
    if (int(before_x2_q_task) == before_x2_q_task) {
        str_q_task += std::to_string(int(before_x2_q_task)) + "x^2 ";
    } else {
        str_q_task += std::to_string(before_x2_q_task) + "x^2 ";
    }
    
    float before_x_q_task = inputFloat("\nPut value that stay before 'x' in quadratic equation (" + str_q_task + "YOUR_VALUE * x +- ...): ");
    if (int(before_x_q_task) == before_x_q_task) {
        if (before_x_q_task < 0) {
            str_q_task += "- " + std::to_string(int(before_x_q_task * -1)) + "x ";
        } else {
            str_q_task += "+ " + std::to_string(int(before_x_q_task)) + "x ";
        }
    } else {
        if (before_x_q_task < 0) {
            str_q_task += "- " + std::to_string(before_x_q_task * -1) + "x ";
        } else {
            str_q_task += "+ " + std::to_string(before_x_q_task) + "x ";
        }
    }
    
    float c_value_q_task = inputFloat("\nPut 'c' value that stay in the end in quadratic equation (" + str_q_task + "YOUR_VALUE): ");
    if (int(c_value_q_task) == c_value_q_task) {
        if (c_value_q_task < 0) {
            str_q_task += "- " + std::to_string(int(c_value_q_task * -1));
        } else {
            str_q_task += "+ " + std::to_string(int(c_value_q_task));
        }
    } else {
        if (c_value_q_task < 0) {
            str_q_task += "- " + std::to_string(c_value_q_task * -1);
        } else {
            str_q_task += "+ " + std::to_string(c_value_q_task);
        }
    }
    
    std::cout << "\nRoots of a quadratic equation '" << str_q_task << "':\n";
    
    std::tuple<float, float> roots_q_task= getAnswerToSqrTask(before_x2_q_task, before_x_q_task, c_value_q_task);
    
    if (std::get<0>(roots_q_task) == std::get<1>(roots_q_task)) {
        if (std::get<0>(roots_q_task) == 0) {
            std::cout << "Sorry, but here no roots, 'd' less that zero...\n";
        } else {
            std::cout << "Here only one root -> x = " << std::get<0>(roots_q_task) << std::endl;
        }
    } else {
        std::cout << "X1 = " << std::get<0>(roots_q_task) << " & X2 = " << std::get<1>(roots_q_task) << std::endl;
    }
    
    goNext();
    
    /* Task8 */
    float a_in_triangle_for_medians = inputFloat("Write 'a' side in triangle: ");
    float b_in_triangle_for_medians = inputFloat("Write 'b' side in triangle: ");
    float c_in_triangle_for_medians = inputFloat("Write 'c' side in triangle: ");
    Triangle user_triangle_for_medians = initTriangle(a_in_triangle_for_medians, b_in_triangle_for_medians, c_in_triangle_for_medians);
    std::cout << "\nIf we try to make new triangle with sides that equal medians in your triangle, we will get something like this:\n";
    Triangle new_triangle_from_medians = initTriangle(user_triangle_for_medians.m2a, user_triangle_for_medians.m2b, user_triangle_for_medians.m2c);
    std::cout << "Side A: " << new_triangle_from_medians.a << " & Median to this side: " << new_triangle_from_medians.m2a << std::endl;
    std::cout << "Side B: " << new_triangle_from_medians.b << " & Median to this side: " << new_triangle_from_medians.m2b << std::endl;
    std::cout << "Side C: " << new_triangle_from_medians.c << " & Median to this side: " << new_triangle_from_medians.m2c << std::endl;
    
    goNext();
    
    /* Task9 */
    std::string converted_time_from_sec = convertSec2TimeThatSpendedAfterZero(int(inputFloat("Put number of secs that spent after start of day: ")));
    std::cout << "Oh, I tried to convert it and get this: " << converted_time_from_sec << std::endl;
    
    goNext();
    
    /* Task10 */
    float side1_of_triangle_for_isoscales = inputFloat("Input triangle's first side: ");
    float side2_of_triangle_for_isoscales = inputFloat("Input triangle's second side: ");
    float side3_of_triangle_for_isoscales = inputFloat("Input triangle's third side: ");
    Triangle triangle_for_isoscales = initTriangle(side1_of_triangle_for_isoscales, side2_of_triangle_for_isoscales, side3_of_triangle_for_isoscales);
    if (isTriangleIsosceles(triangle_for_isoscales)) {
        std::cout << "\nYour triangle (with all sides = " << triangle_for_isoscales.a << ") is isoscales!" << std::endl;
    } else {
        std::cout << "\nTo be honest, your triangle isn't isoscales" << std::endl;
    }
    
    goNext();
    
    /* Task11 */
    float sum_of_buying = inputFloat("Please, say me your private info about sum that you spend for bying something: ");
    if (sum_of_buying > 1000) {
        std::cout << "With sale 10%, this sum are " << numMinusPercents(sum_of_buying, 10) << std::endl;
    } else {
        std::cout << "This sum is less than 1k, so sale is not here(\n";
    }
    
    goNext();
    
    /* Task12 */
    float user_weight = inputFloat("Write someone's weigth: ");
    float user_hight = inputFloat("Write someone's hight: ");
    float ideal_user_weight = getIdealWeight(user_hight);
    if (user_weight == ideal_user_weight) {
        std::cout << "It is magic, but someone have his ideal wieght!\n";
    } else {
        if (user_weight > ideal_user_weight) {
            std::cout << "Program thinks that someone should reduce weigth to " << ideal_user_weight << std::endl;
        } else {
            std::cout << "Program thinks that someone should eat more and make weigth bigger to " << ideal_user_weight << std::endl;
        }
    }
    
    goNext();
    
    /* Task13 */
    int random_num = getRundumNum();
    int user_opinion_of_rand_num = int(inputFloat("I have generated some num (0, 9), try to guess: "));
    if (user_opinion_of_rand_num == random_num) {
        std::cout << "Wow, it's right!\n";
    } else {
        std::cout << "Wow, it isn't right, becouse I generated " << random_num << " ;(\n";
    }
    
    goNext();
    
    /* Task14 */
    float len_of_speking = inputFloat("Put lengh of speking (in hours): ");
    int weak_day_of_speaking = int(inputFloat("Put num of day, when speking (0, 7): "));
    int price_per_hour_for_speking = 1000;
    std::cout << "Price for tolking (per hour = " << price_per_hour_for_speking << ") is " << getPriceOfSpeking(len_of_speking, weak_day_of_speaking, price_per_hour_for_speking) << ". So, think about it...\n";
    
    goNext();
    
    /* Task15 */
    std::tuple<int, std::string, std::string> users_month_params = getMonthsParams(int(inputFloat("Put number of month (1, 12): ")));
    std::cout << "I found, that month " << std::get<1>(users_month_params) << " is in " << std::get<2>(users_month_params) << std::endl;
    
    goNext();
    
    /* Task16 */
    int six_num_to_try_luck = int(inputFloat("Put six-count number and I'l say is num lycky: "));
    if (isSixNumLucky(six_num_to_try_luck)) {
        std::cout << "Yes, it is!\n";
    } else {
        std::cout << "No, it isn't...\n";
    }
    
    goNext();
    
    /* Task17 */
    int num_of_kopeek = int(inputFloat("Put score of kopeika: "));
    std::cout << "I think, that " << num_of_kopeek << " sounds with " << getRightKopeikaWord(num_of_kopeek) << std::endl;
    
    goNext();
    
    /* Task18 */
    if (isFourNumPolindrom(int(inputFloat("Put four-count number: ")))) {
        std::cout << "It is polindrom\n";
    } else {
        std::cout << "It isn't polindrom\n";
    }
    
    goNext();
    
    /* Task19 */
    int three_num_to_19_task = int(inputFloat("Put 3-count number: "));
    std::tuple<int, int> params_of_inputted_three_count_num = getParamsOfThreeCountNum(three_num_to_19_task);
    
    /* Task19.1 */
    if (std::get<0>(params_of_inputted_three_count_num) > inputFloat("Put param 'b' to look with 3-count num's product: ")) {
        std::cout << "Product is bigger\n";
    } else {
        std::cout << "Param 'b' is bigger\n";
    }
    
    /* Task19.1 */
    if (std::get<1>(params_of_inputted_three_count_num) % 7 == 0) {
        std::cout << "The sum of the digits is a multiple of 7\n";
    } else {
        std::cout << "The sum of the digits is not a multiple of 7\n";
    }
    
    goNext();
    
    /* Task20 */
    float a_for_rectangle_task = inputFloat("Put line 'a' in rectangle: ");
    float b_for_rectangle_task = inputFloat("Put line 'b' in rectangle: ");
    float c_for_rectangle_task = inputFloat("Put line 'c' in rectangle: ");
    float d_for_rectangle_task = inputFloat("Put line 'd' in rectangle: ");
    if ((a_for_rectangle_task <= c_for_rectangle_task && b_for_rectangle_task <= d_for_rectangle_task) || (a_for_rectangle_task <= d_for_rectangle_task && b_for_rectangle_task <= c_for_rectangle_task)) {
        std::cout << "Rectangle can be placed in another rectangle\n";
    } else {
        std::cout << "Rectangle cannot be placed in another rectangle\n";
    }
    
    /* DONE */
    
    std::cout << "\n\nThats all, thank you, all the best!\n\n";

    
    return 0;
}
