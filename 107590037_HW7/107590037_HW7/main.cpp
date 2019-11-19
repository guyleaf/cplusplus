/*
	Author: ��u�G 107590037 ��ģ�w

	�{���\��: ����q�v��������

	�@�~�s��: HW7
*/
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "Rating.h"

using namespace std;


/*
	�禡�\��: ���J�q�v�������

	�Ѽ�: ratingsFile => �ɮ׸�� movies => �q�v�M��, order => �M�涶��

	�^�ǭ�: �L
*/
void LoadRatingsFile(fstream& ratingsFile, map<string, Rating>& movies, vector<string>& order)
{
    //�q�v�ƶq
    int numberOfMovies;
    //�q�v�W��
    string movieName;
    //�q�v����
    double ratings;
    //Ū���q�v���׼ƶq
    ratingsFile >> numberOfMovies;
    //��������
    ratingsFile.ignore(1);

    //�C�@loop�N��@���q�v���
    for (int i = 0; i < numberOfMovies; i++)
    {
        //Ū���q�v�W��
        getline(ratingsFile, movieName);
        //Ū���q�v����
        ratingsFile >> ratings;
        //��������
        ratingsFile.ignore(1);

        //�p�G�|���إߦܹq�v�M��A�h���J�@��
        if (movies.find(movieName) == movies.end())
        {
            //���J�q�v�M��ëإ߹q�v���Ƹ��
            movies.insert(pair<string, Rating>(movieName, Rating(1, ratings)));
            //�[�J�ܹq�v���ǲM��
            order.push_back(movieName);
        }
        else
            //�[�J���Ʀܹq�v���
            movies[movieName] += Rating(1, ratings);
    }
}

/*
	�禡�\��: �}�ҹq�v����ɮ�

	�Ѽ�: movies => �q�v�M��, order => �M�涶��

	�^�ǭ�: �L
*/
void OpenRatingsFile(map<string, Rating>& movies, vector<string>& order)
{
    //�ɮצW��
    string fileName = "Data.txt";
    //�ɮצ�y
    fstream ratingsFile;
    //Ū���ɮ�
    ratingsFile.open(fileName, ios::in);

    //�ˬd�O�_����ɮ�
    if (!ratingsFile)
    {
        cout << "�䤣�즹�ɮסA���ˬd�ɮ׸��|" << endl;
        return;
    }

    //���J�q�v�������
    LoadRatingsFile(ratingsFile, movies, order);
}
/*
	�禡�\��: ��X�q�v����

	�Ѽ�: movies => �q�v�M��, order => �M�涶��

	�^�ǭ�: �L
*/
void OutputMovieRating(map<string, Rating>& movies, vector<string>& order)
{
    int reviews;
    double ratings;

    //�̹q�v���ǿ�X
    for (vector<string>::iterator movieName = order.begin(); movieName != order.end(); movieName++)
    {
        reviews = movies[*movieName].GetReviews();
        ratings = movies[*movieName].GetRatings();
        cout << *movieName << ": " << reviews << " ";

        if (reviews > 1)
            cout << "reviews";
        else
            cout << "review";

        cout << ", average of "
             << setprecision(2) << ratings / reviews << " / 5" << endl;
    }
}

int main()
{
    //�q�v�M��
    map<string, Rating> movies;
    //�q�v���ǲM��
    vector<string> order;
    //�}�Ҩø��J�q�v�������
    OpenRatingsFile(movies, order);
    //��X�q�v����
    OutputMovieRating(movies, order);
    system("PAUSE");
    return 0;
}