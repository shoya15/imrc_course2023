/*
データ(年月日、売り上げ、廃棄、客数)が入力される
0 -> 終了
1 -> 最大売上日、売り上げを出力
2 -> 最小　　　　；
3 -> 売上合計
4, 5, 6 -> 廃棄ver.
7, 8, 9 -> 客ver.
10, 11 -> 売り上げ/客ver.
12 -> 年月日で削除
13 -> データの追加
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Data
{
    int year_month_day;
    int earned_money;
    int throw_away;
    int num_customer;
};

int main()
{
    int data_num = 0;
    int array_index = 0;
    std::vector<Data> all_data;
    Data sum{0, 0, 0, 0};

    while (true)
    {
        int query;
        std::cin >> query;
        if (query == 0)
        {
            break;
        }
        else if (query == 1)
        {
            // std::sort(all_data.begin(), all_data.end());
            std::cout << "year_month_day: " << all_data[-1].year_month_day << std::endl;
            std::cout << "earned_money: " << all_data[-1].earned_money << std::endl;
        }
        else if (query == 2)
        {
            // std::sort(all_data.begin(), all_data.end());
            std::cout << "year_month_day: " << all_data[0].year_month_day << std::endl;
            std::cout << "earned_money: " << all_data[0].earned_money << std::endl;
        }
        else if (query == 3)
        {
            std::cout << "earned_money: " << sum.earned_money << std::endl;
        }
        else if (query == 4)
        {
            // std::sort(all_data.begin(), all_data.end());
            std::cout << "year_month_day: " << all_data[-1].year_month_day << std::endl;
            std::cout << "throw_away: " << all_data[-1].throw_away << std::endl;
        }
        else if (query == 5)
        {
            // std::sort(all_data.begin(), all_data.end());
            std::cout << "year_month_day: " << all_data[0].year_month_day << std::endl;
            std::cout << "throw_away: " << all_data[0].throw_away << std::endl;
        }
        else if (query == 6)
        {
            std::cout << "throw_away: " << sum.throw_away << std::endl;
        }
        else if (query == 7)
        {
            // std::sort(all_data.begin(), all_data.end());
            std::cout << "year_month_day: " << all_data[-1].year_month_day << std::endl;
            std::cout << "num_customer: " << all_data[-1].num_customer << std::endl;
        }
        else if (query == 8)
        {
            // std::sort(all_data.begin(), all_data.end());
            std::cout << "year_month_day: " << all_data[0].year_month_day << std::endl;
            std::cout << "num_customer: " << all_data[0].num_customer << std::endl;
        }
        else if (query == 9)
        {
            std::cout << "num_customer: " << sum.num_customer << std::endl;
        }
        else if (query == 10)
        {
            double max = 0;
            for (int i = 0; i < array_index; i++)
            {
                max = std::max(max, double(all_data[i].earned_money / all_data[i].num_customer));
            }
        }
        else if (query == 11)
        {
            double min = std::pow(10, 18);
            for (int i = 0; i < array_index; i++)
            {
                min = std::min(min, double(all_data[i].earned_money / all_data[i].num_customer));
            }
        }
        else if (query == 12)
        {
            int year_month_day;
            std::cin >> year_month_day;
            for (int i = 0; i < array_index; i++)
            {
                if (year_month_day == all_data[i].year_month_day)
                {
                    all_data[i].year_month_day = -1;
                    sum.earned_money -= all_data[i].earned_money;
                    sum.throw_away -= all_data[i].throw_away;
                    sum.num_customer -= all_data[i].num_customer;
                    data_num--;
                    array_index--;
                    break;
                }
            }
        }
        else
        {
            Data one_data;
            std::cin >> one_data.year_month_day >> one_data.earned_money >> one_data.throw_away >> one_data.num_customer;
            all_data[array_index] = one_data;
            sum.earned_money += one_data.earned_money;
            sum.throw_away += one_data.throw_away;
            sum.num_customer += one_data.num_customer;
            array_index++;
            data_num++;
        }
    }
}