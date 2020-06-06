#include "jeopardy.h"
#include "ui_jeopardy.h"
#include <iostream>
#include <fstream>

using namespace std;

Jeopardy::Jeopardy(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Jeopardy)
{
    ui->setupUi(this);
}

static ifstream fin; //used to read questions from a file
static string question; //stores a question read from a file
const string TOPICS_FILE_NAME = "jeopardyTopics.txt"; //filename for the input file holding the topics
const string QUESTIONS_FILE_NAME = "jeopardyQuestions.txt"; //filename for the input file holding the questions
const string ANSWERS_FILE_NAME = "jeopardyAnswers.txt"; //filename for the input file holding the answers
const int NUM_TOPICS = 5; //number of columns on the board
const int NUM_QUESTIONS = 5; //number of rows on the board
const int NUM_TEAMS = 4; //number of teams playing
static string topics[NUM_TOPICS]; //array of string to store the topic names
static string board[NUM_TOPICS][NUM_QUESTIONS]; //2D array of strings to store the questions
static string answers[NUM_TOPICS][NUM_QUESTIONS]; //2D array of strings to store the answers
static int row, col; //holds the row and column of a question in board respectively
static int turnCount = 0; //counter to keep track of which team's turn it is
static int teamNumber; //holds the team number (1-NUM_TEAMS)
static int pointsValue; //holds the number of points a question is worth
static int pointsTeam1 = 0; //holds the cumulative points for team 1
static int pointsTeam2 = 0; //holds the cumulative points for team 2
static int pointsTeam3 = 0; //holds the cumulative points for team 3
static int pointsTeam4 = 0; //holds the cumulative points for team 4
//static int incorrectCount = 0; //counter to keep track of how many times a question was incorrectly answered

//adding comment for previous commit
void readTopics(ifstream& fin, string topics[], int numTopics);
//reads numTopics lines from the input file and stores each line in topics
void readLine(ifstream& fin, string board[][NUM_TOPICS], int numQuestions);
//reads each line from the input file connected to fin and stores them in board
void openInputFile(ifstream& fin, string fileName);
//connects fin to the input file named fileName
void closeInputFile(ifstream& fin);
//disconnects fin from the input file
int getPointsValue(int col);
//receives the column index of a question in board and returns its points value
int getTeamNumber(int turnCount);
//receives the turnCount and returns the team number of the team whose turn it is

Jeopardy::~Jeopardy()
{
    delete ui;
}

