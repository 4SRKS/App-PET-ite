#include <QApplication>
#include <QPushButton>
#include <QtGui>

int main (int argc, char* argv[]) {
    QApplication app(argc, argv);
    QTextStream cout(stdout);

    // Declarations of variables
    int answer = 0;

    do {
        // local variables to the loop:
        int weight = 0;

        weight = QInputDialog::getInt(0, "Appetite UI",
            "Enter the weight to be dispensed:", 1);
        cout << "User entered: " << weight << endl;

        int time = 0;

        time = QInputDialog::getInt(0, "Appetite UI",
        "Enter the time for next dispense in hours:", 1);
        cout << "User entered: " << time << endl;


//        QMessageBox msgBox;
//        msgBox.setText("You have entered weight as %1 and time as %2").arg(weight).arg(time);
//        msgBox.exec();
        QString response = QString("You have entered weight as %1 and time as %2.\n Have you entered the right values").arg(weight).arg(time);

        answer = QMessageBox::question(0, "Play again?", response,
            QMessageBox::Yes | QMessageBox::No);
    } while (answer == QMessageBox::No);
    return EXIT_SUCCESS;
}

