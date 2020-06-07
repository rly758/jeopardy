This is the final project for PIC 10C for Spring 2020 under Professor Salazar. 

This program will allow the user to play Jeopardy with a GUI. 


Game Details: 
The game is played between four teams. There are multiple sets of 5 topical questions. The 5 questions
are worth 100, 200, ... , 500 points, respectively. The question sets will be read from a text file. The main window will keep 
track of each team's score. Each team will alternate in choosing a question determined by the topic and point value of the question.
The main window will not allow the same question to be answered twice, regardless if it was answered correctly or not. 
The game ends when all questions have been exhausted. The winning team is then displayed. 

Learning Objective: 
My main objective for this project is to be able to familiarize myself with Qt and its widgets. The jeopardy game itself was not exceptionally difficult or
complicated to allow me to learn basic functionalities of Qt's widgets. Additionally, I learned that Qt has the ability to deploy programs as applications
that are independent of an IDE. This was particularly interesting to me so I decided to pursue this as well.


Development History:

Week 6: 
Downloaded and installed Qt Creator. There were issues in trying to set up Git and Qt. I followed Qt's official documentation here: https://doc.qt.io/qtcreator/creator-vcs-git.html
This fixed any issues I was having. I also learned various functionalities of using Git directly through Qt. 

Week 7:
I planned out how I was going to approach the jeopardy game. I worked through the logic of how things would happen and when. 
In addition, I wrote out the program in pseudocode for reference for actual coding. This was done in c++ syntax and this would
need to be redone while incorporating the GUI elements from Qt.

Week 8: 
I spent this week learning about the slots of various widgets. I read through the official documention of various widgets, like the label: https://doc.qt.io/qt-5/qlabel.html
I worked on implementing these widgets individually in simple test programs to familiarize myself with them. 

Week 9:
This week I wrote out the jeopardy program in Qt. Although I wrote the pseudocode earlier, there were various logical errors still. One small thing that
I learned was while trying to change the text of QLabel objects during the game. ui->QLabel_var->setText("some string") does not work. 
The parameter must be of type QString, not string and so I followed the answer here: https://stackoverflow.com/questions/1814189/how-to-change-string-into-qstring
and instead used ui->QLabel_var->setText(QString::fromStdString("some string"))
Something else I learned was where input and output files should be placed. They should not be put in the original project folder, but in the project's build folder. 


Week 10:
This week I wanted to be able to send the jeopardy game as an executable that was independent of an IDE. 
Something that was really important that I learned when trying to do this is that there are certain libraries that MUST be included with your executable.
If you do not have these libraries, trying to run the executable returns an error prompt. Following the directions here: https://wiki.qt.io/Deploy_an_Application_on_Windows
I was able to deploy the program as an independent application. 
