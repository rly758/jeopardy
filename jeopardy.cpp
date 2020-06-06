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


void readTopics(ifstream& fin, string topics[], int numTopics){
    string topicName;

    for(int t = 0; t < numTopics; t++){
        getline(fin, topicName);
        topics[t] = topicName;
    }
}

void readLine(ifstream& fin, string board[][NUM_TOPICS], int numQuestions){
    for(int topicNum = 0;topicNum < NUM_TOPICS;topicNum++){ //for each topic
        for(int questionNum = 0;questionNum < numQuestions;questionNum++){ //for each question
            getline(fin,question); //read a question from a line in the input file

            board[topicNum][questionNum] = question; //store the question in board
        }
    }

    /*

     T1Q1 T1Q2 T1Q3 T1Q4 T1Q5
     T2Q1 ...
     T3Q1 ...
     T4Q1 ...
     T5Q1 ...

     */
}

void openInputFile(ifstream& fin, string fileName){
    fin.open(fileName); //open the input file

    if(fin.fail()){ //if there was an error opening the input file
        cout << "Error opening the input file." << endl; //print error message
        exit(1); //terminate the program
    }
}

void closeInputFile(ifstream& fin){
    fin.close(); //close the input file
}

int getPointsValue(int col){
    switch(col){ //each question is worth more and more points depending on its column index in board
        case 0: return 100; //col 0 questions are 100 points
        case 1: return 200;
        case 2: return 300;
        case 3: return 400;
        case 4: return 500; //col 5 questions are 500 points
        default: return 0;
    }
}

int getTeamNumber(int turnCount){
    //returns the team number of the team whose turn it is by using the counter turnCount and the number of teams playing
    return 1 + turnCount % NUM_TEAMS;
}

void addPoints(int teamNumber, int pointsValue){
    switch(teamNumber){ //determine which team using teamNumber
        //add pointsValue to their cumulative score
        case 1: pointsTeam1 += pointsValue; break;
        case 2: pointsTeam2 += pointsValue; break;
        case 3: pointsTeam3 += pointsValue; break;
        case 4: pointsTeam4 += pointsValue; break;
        default: break;
    }
}

void Jeopardy::on_T1Q1_clicked()
{
    //set row and col to the row and column indexes of a question's location in board
    row = 0;
    col = 0;

    //change questionText to the question in board
    ui->questionText->setText(QString::fromStdString(board[row][col]));

    //disable the question's button
    ui->T1Q1->setEnabled(false);

    //reenable the correct and incorrect buttons since this is a new question
    ui->correctBtn->setEnabled(true);
    ui->incorrectBtn->setEnabled(true);
    ui->answerBtn->setEnabled(true);
}

//Lines 120-360: see lines 107-118 for comments
void Jeopardy::on_T1Q2_clicked()
{
    row = 0;
    col = 1;

    ui->questionText->setText(QString::fromStdString(board[row][col]));

    ui->T1Q2->setEnabled(false);

    ui->correctBtn->setEnabled(true);
    ui->incorrectBtn->setEnabled(true);
    ui->answerBtn->setEnabled(true);
}

void Jeopardy::on_T1Q3_clicked()
{
    row = 0;
    col = 2;

    ui->questionText->setText(QString::fromStdString(board[row][col]));

    ui->T1Q3->setEnabled(false);

    ui->correctBtn->setEnabled(true);
    ui->incorrectBtn->setEnabled(true);
    ui->answerBtn->setEnabled(true);
}

void Jeopardy::on_T1Q4_clicked()
{
    row = 0;
    col = 3;

    ui->questionText->setText(QString::fromStdString(board[row][col]));

    ui->T1Q4->setEnabled(false);

    ui->correctBtn->setEnabled(true);
    ui->incorrectBtn->setEnabled(true);
    ui->answerBtn->setEnabled(true);
}

void Jeopardy::on_T1Q5_clicked()
{
    row = 0;
    col = 4;

    ui->questionText->setText(QString::fromStdString(board[row][col]));

    ui->T1Q5->setEnabled(false);

    ui->correctBtn->setEnabled(true);
    ui->incorrectBtn->setEnabled(true);
    ui->answerBtn->setEnabled(true);
}

void Jeopardy::on_T2Q1_clicked()
{
    row = 1;
    col = 0;

    ui->questionText->setText(QString::fromStdString(board[row][col]));

    ui->T2Q1->setEnabled(false);

    ui->correctBtn->setEnabled(true);
    ui->incorrectBtn->setEnabled(true);
    ui->answerBtn->setEnabled(true);
}

void Jeopardy::on_T2Q2_clicked()
{
    row = 1;
    col = 1;

    ui->questionText->setText(QString::fromStdString(board[row][col]));

    ui->T2Q2->setEnabled(false);

    ui->correctBtn->setEnabled(true);
    ui->incorrectBtn->setEnabled(true);
    ui->answerBtn->setEnabled(true);
}

void Jeopardy::on_T2Q3_clicked()
{
    row = 1;
    col = 2;

    ui->questionText->setText(QString::fromStdString(board[row][col]));

    ui->T2Q3->setEnabled(false);

    ui->correctBtn->setEnabled(true);
    ui->incorrectBtn->setEnabled(true);
    ui->answerBtn->setEnabled(true);
}

void Jeopardy::on_T2Q4_clicked()
{
    row = 1;
    col = 3;

    ui->questionText->setText(QString::fromStdString(board[row][col]));

    ui->T2Q4->setEnabled(false);

    ui->correctBtn->setEnabled(true);
    ui->incorrectBtn->setEnabled(true);
    ui->answerBtn->setEnabled(true);
}

void Jeopardy::on_T2Q5_clicked()
{
    row = 1;
    col = 4;

    ui->questionText->setText(QString::fromStdString(board[row][col]));

    ui->T2Q5->setEnabled(false);

    ui->correctBtn->setEnabled(true);
    ui->incorrectBtn->setEnabled(true);
    ui->answerBtn->setEnabled(true);
}

void Jeopardy::on_T3Q1_clicked()
{
    row = 2;
    col = 0;

    ui->questionText->setText(QString::fromStdString(board[row][col]));

    ui->T3Q1->setEnabled(false);

    ui->correctBtn->setEnabled(true);
    ui->incorrectBtn->setEnabled(true);
    ui->answerBtn->setEnabled(true);
}

void Jeopardy::on_T3Q2_clicked()
{
    row = 2;
    col = 1;

    ui->questionText->setText(QString::fromStdString(board[row][col]));

    ui->T3Q2->setEnabled(false);

    ui->correctBtn->setEnabled(true);
    ui->incorrectBtn->setEnabled(true);
    ui->answerBtn->setEnabled(true);
}

void Jeopardy::on_T3Q3_clicked()
{
    row = 2;
    col = 2;

    ui->questionText->setText(QString::fromStdString(board[row][col]));

    ui->T3Q3->setEnabled(false);

    ui->correctBtn->setEnabled(true);
    ui->incorrectBtn->setEnabled(true);
    ui->answerBtn->setEnabled(true);
}

void Jeopardy::on_T3Q4_clicked()
{
    row = 2;
    col = 3;

    ui->questionText->setText(QString::fromStdString(board[row][col]));

    ui->T3Q4->setEnabled(false);

    ui->correctBtn->setEnabled(true);
    ui->incorrectBtn->setEnabled(true);
    ui->answerBtn->setEnabled(true);
}

void Jeopardy::on_T3Q5_clicked()
{
    row = 2;
    col = 4;

    ui->questionText->setText(QString::fromStdString(board[row][col]));

    ui->T3Q5->setEnabled(false);

    ui->correctBtn->setEnabled(true);
    ui->incorrectBtn->setEnabled(true);
    ui->answerBtn->setEnabled(true);
}

void Jeopardy::on_T4Q1_clicked()
{
    row = 3;
    col = 0;

    ui->questionText->setText(QString::fromStdString(board[row][col]));

    ui->T4Q1->setEnabled(false);

    ui->correctBtn->setEnabled(true);
    ui->incorrectBtn->setEnabled(true);
    ui->answerBtn->setEnabled(true);
}

void Jeopardy::on_T4Q2_clicked()
{
    row = 3;
    col = 1;

    ui->questionText->setText(QString::fromStdString(board[row][col]));

    ui->T4Q2->setEnabled(false);

    ui->correctBtn->setEnabled(true);
    ui->incorrectBtn->setEnabled(true);
    ui->answerBtn->setEnabled(true);
}

void Jeopardy::on_T4Q3_clicked()
{
    row = 3;
    col = 2;

    ui->questionText->setText(QString::fromStdString(board[row][col]));

    ui->T4Q3->setEnabled(false);

    ui->correctBtn->setEnabled(true);
    ui->incorrectBtn->setEnabled(true);
    ui->answerBtn->setEnabled(true);
}

void Jeopardy::on_T4Q4_clicked()
{
    row = 3;
    col = 3;

    ui->questionText->setText(QString::fromStdString(board[row][col]));

    ui->T4Q4->setEnabled(false);

    ui->correctBtn->setEnabled(true);
    ui->incorrectBtn->setEnabled(true);
    ui->answerBtn->setEnabled(true);
}

void Jeopardy::on_T4Q5_clicked()
{
    row = 3;
    col = 4;

    ui->questionText->setText(QString::fromStdString(board[row][col]));

    ui->T4Q5->setEnabled(false);

    ui->correctBtn->setEnabled(true);
    ui->incorrectBtn->setEnabled(true);
    ui->answerBtn->setEnabled(true);
}

void Jeopardy::on_T5Q1_clicked()
{
    row = 4;
    col = 0;

    ui->questionText->setText(QString::fromStdString(board[row][col]));

    ui->T5Q1->setEnabled(false);

    ui->correctBtn->setEnabled(true);
    ui->incorrectBtn->setEnabled(true);
    ui->answerBtn->setEnabled(true);
}

void Jeopardy::on_T5Q2_clicked()
{
    row = 4;
    col = 1;

    ui->questionText->setText(QString::fromStdString(board[row][col]));

    ui->T5Q2->setEnabled(false);

    ui->correctBtn->setEnabled(true);
    ui->incorrectBtn->setEnabled(true);
    ui->answerBtn->setEnabled(true);
}

void Jeopardy::on_T5Q3_clicked()
{
    row = 4;
    col = 2;

    ui->questionText->setText(QString::fromStdString(board[row][col]));

    ui->T5Q3->setEnabled(false);

    ui->correctBtn->setEnabled(true);
    ui->incorrectBtn->setEnabled(true);
    ui->answerBtn->setEnabled(true);
}

void Jeopardy::on_T5Q4_clicked()
{
    row = 4;
    col = 3;

    ui->questionText->setText(QString::fromStdString(board[row][col]));

    ui->T5Q4->setEnabled(false);

    ui->correctBtn->setEnabled(true);
    ui->incorrectBtn->setEnabled(true);
    ui->answerBtn->setEnabled(true);
}

void Jeopardy::on_T5Q5_clicked()
{
    row = 4;
    col = 4;

    ui->questionText->setText(QString::fromStdString(board[row][col]));

    ui->T5Q5->setEnabled(false);

    ui->correctBtn->setEnabled(true);
    ui->incorrectBtn->setEnabled(true);
    ui->answerBtn->setEnabled(true);
}

void Jeopardy::on_correctBtn_clicked()
{
    string strPoints; //string to hold the string equivalent of the integer number of points

    pointsValue = getPointsValue(col); //determine a question's points value based on its column
    teamNumber = getTeamNumber(turnCount); //determine the team whose turn it is based on turnCount

    addPoints(teamNumber, pointsValue); //add pointsValue to the cumulative points of team teamNumber

    //update the score of whichever team answered correctly
    switch(teamNumber){
        case 1:
            strPoints = to_string(pointsTeam1); //convert integer score to string

            ui->pointsTeam1->setText(QString::fromStdString(strPoints)); //update text score

            break;
        case 2:
            strPoints = to_string(pointsTeam2);

            ui->pointsTeam2->setText(QString::fromStdString(strPoints));

            break;
        case 3:
            strPoints = to_string(pointsTeam3);

            ui->pointsTeam3->setText(QString::fromStdString(strPoints));

            break;
        case 4:
            strPoints = to_string(pointsTeam4);

            ui->pointsTeam4->setText(QString::fromStdString(strPoints));

            break;
        default: break;
    }

    turnCount++; //increment turnCount to move to the next team

    //update text showing which team's turn it is
    switch(getTeamNumber(turnCount)){
        case 1: ui->currentTeamLabel->setText("For Team1: "); break;
        case 2: ui->currentTeamLabel->setText("For Team2: "); break;
        case 3: ui->currentTeamLabel->setText("For Team3: "); break;
        case 4: ui->currentTeamLabel->setText("For Team4: "); break;
        default: break;
    }

    //reset the text holding the question to prompt the next team to choose a new question
    ui->questionText->setText("Choose a new question!");

    //disable correct and incorrect buttons until a new question is chosen
    ui->correctBtn->setEnabled(false);
    ui->incorrectBtn->setEnabled(false);
    ui->answerBtn->setEnabled(false);

    //incorrectCount = 0; //reset the counter
}

void Jeopardy::on_incorrectBtn_clicked()
{
    turnCount++; //increment turnCount to move to the next team

    //update text showing which team's turn it is
    switch(getTeamNumber(turnCount)){
        case 1: ui->currentTeamLabel->setText("For Team1: "); break;
        case 2: ui->currentTeamLabel->setText("For Team2: ");  break;
        case 3: ui->currentTeamLabel->setText("For Team3: ");  break;
        case 4: ui->currentTeamLabel->setText("For Team4: ");  break;
        default: break;
    }

    //change the questionText to prompt the next team to choose a new question
    ui->questionText->setText("Choose a new question!");

    //disable correct and incorrect buttons until a new question is chosen
    ui->correctBtn->setEnabled(false);
    ui->incorrectBtn->setEnabled(false);
    ui->answerBtn->setEnabled(false);


    /*

    //keep track of the number of times a question has been answered incorrectly
    if(incorrectCount < NUM_TEAMS - 1){ //if not every team has answered incorrectly
        incorrectCount++; //increment counter
    }
    else{//every team has gotten the question wrong
        //change the questionText to prompt the next team to choose a new question
        ui->questionText->setText("Choose a new question!");

        //disable correct and incorrect buttons until a new question is chosen
        ui->correctBtn->setEnabled(false);
        ui->incorrectBtn->setEnabled(false);

        incorrectCount = 0; //reset the counter
    }

    */
}

void Jeopardy::on_manualComboBox_currentIndexChanged(int index)
{
    //receives the index of the selection made from the combo box
    turnCount = index - 1;

    //update text showing which team's turn it is
    switch(getTeamNumber(turnCount)){
        case 1: ui->currentTeamLabel->setText("For Team1: "); break;
        case 2: ui->currentTeamLabel->setText("For Team2: ");  break;
        case 3: ui->currentTeamLabel->setText("For Team3: ");  break;
        case 4: ui->currentTeamLabel->setText("For Team4: ");  break;
        default: break;
    }
}

void Jeopardy::on_answerBtn_clicked()
    {
        ui->questionText->setText(QString::fromStdString(answers[row][col]));
    }
