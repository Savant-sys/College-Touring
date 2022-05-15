#include "campus_widget.h"
#include "campus.h"

//Note that the constructor initializes a campus associated with the object so that we know which campus the user is messing with.
CampusWidget::CampusWidget(Campus campusPassed, MainWindow *parent)
    :campus{campusPassed}, parent{parent}
{

    //Creating all the UI elements dynamically for each campus column in the list widget.
    layout = new QHBoxLayout(this);
    stateLabel = new QLabel(campus.getState());
    stateLabel->setFixedWidth(100);
    nameLabel = new QLabel(campus.getStartCollege());
    nameLabel->setFixedWidth(270);
    endC = new QComboBox();
//    endC->setFixedWidth(230);
    menuItems = new QComboBox();

    for (int i = 0; i < this->campus.getEndCollege().size(); i++)
    {
        endC->addItem(QString(this->campus.getEndCollege()[i]));
        //qInfo() << campus.getEndCollege()[i] << "\n";
    }
    //Iterating over the menu to add items to the menu ComboBox
    for (int i = 0; i < this->campus.getMenu().size(); i++)
    {
        menuItems->addItem(QString(this->campus.getMenu()[i].name + ": $" + QString::number(this->campus.getMenu()[i].price)));
    }



    //Adding all input widgets to our QHBoxLayout that groups them all together.
    layout->addWidget(stateLabel);
    layout->addWidget(nameLabel);
    layout->addWidget(endC);
    layout->addWidget(menuItems);

}





CampusWidget::~CampusWidget(){
    delete layout;
    delete endC;
    delete stateLabel;
    delete nameLabel;
    delete menuItems;
}
