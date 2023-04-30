/*
成績(国数英)と学籍番号が入力される
0 -> 終了
1 -> 各科目の合計を出力
2 -> 各科目の平均を出力
3 -> 学籍番号のデータを削除
4 -> 学籍番号で各科目の成績を追加
*/
#include <iostream>

struct Human
{
    int id;
    int japanese_point;
    int mathematics_point;
    int english_point;
};

int main()
{
    int data_num = 0;
    int array_index = 0;
    Human students[100];
    Human sum{0, 0, 0, 0};

    while (1)
    {
        int query;
        std::cin >> query;
        if (query == 0)
            break;
        if (query == 1)
        {
            std::cout << "japanese   : " << sum.japanese_point << std::endl;
            std::cout << "mathematics: " << sum.mathematics_point << std::endl;
            std::cout << "english    : " << sum.english_point << std::endl;
        }
        if (query == 2)
        {
            if (data_num == 0)
            {
                std::cout << "none" << std::endl;
            }
            else
            {
                std::cout << "japanese   : " << sum.japanese_point / data_num << std::endl;
                std::cout << "mathematics: " << sum.mathematics_point / data_num << std::endl;
                std::cout << "english    : " << sum.english_point / data_num << std::endl;
            }
        }
        if (query == 3)
        {
            int id;
            std::cin >> id;
            for (int i = 0; i < array_index; i++)
            {
                if (id == students[i].id)
                {
                    students[i].id = -1;
                    sum.japanese_point -= students[i].japanese_point;
                    sum.mathematics_point -= students[i].mathematics_point;
                    sum.english_point -= students[i].english_point;
                    data_num--;
                    array_index--;
                    break;
                }
            }
        }
        if (query == 4)
        {
            Human student;
            std::cin >> student.id >> student.japanese_point >> student.mathematics_point >> student.english_point;
            students[array_index] = student;
            sum.japanese_point += student.japanese_point;
            sum.mathematics_point += student.mathematics_point;
            sum.english_point += student.english_point;
            array_index++;
            data_num++;
        }
    }
}